#pragma once
#include "pch.h"
#include "cmd_context.h"

class abstract_cmd
{
public:
	virtual string get_cmd_name() = 0;
	virtual void execute(cmd_context* context) = 0;
};
