#pragma once
#include "stdafx.h"
#include "notebook_error_code.h"

class notebook_exception : public exception
{
	notebook_error_code code_;
public:
	notebook_exception(notebook_error_code code)
	{
		code_ = code;
	}

	notebook_error_code code() const
	{
		return code_;
	}
};

