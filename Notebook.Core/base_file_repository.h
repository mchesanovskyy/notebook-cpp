#pragma once
#include "stdafx.h"
#include <fstream>

template <class TEntity>
class base_file_repository
	: public virtual abstract_repository<TEntity>
{
	vector<TEntity*>* entities_ = new vector<TEntity*>;
	
public:
	void add(TEntity* entity) override
	{
		auto entities = load_entities();
		entities->push_back(entity);
	}

	void save_changes() override
	{
		const auto file_name = get_file_name();
		ofstream writer(file_name, ios::out);
		if (writer.is_open()) 
		{
			for (TEntity* entity : *entities_)
			{
				auto value = to_string(entity);
				writer << value << endl;
			}
			writer.close();
		}
	}

protected:
	char delimiter = '|';
	virtual string get_file_name() = 0;
	virtual string to_string(TEntity* entity) = 0;
	virtual TEntity* to_entity(vector<string> values) = 0;

	vector<TEntity*>* load_entities(bool force = false)
	{
		if (!force && !entities_->empty())
			return entities_;

		const auto file_name = get_file_name();
		ifstream reader(file_name);
		entities_ = new vector<TEntity*>;
		if (reader.is_open()) 
		{
			string line;
			while (getline(reader, line))
			{
				vector<string> items = split(line, delimiter);
				auto entity = to_entity(items);
				entities_->push_back(entity);
			}
			reader.close();
		}

		return entities_;
	}

};