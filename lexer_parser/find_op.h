#pragma once
#include "op.h"
struct Find_op : op
{
	double eval() override {
		return 0;
	}
	void print() override {
		std::cout << "Find\n";
	}
};
