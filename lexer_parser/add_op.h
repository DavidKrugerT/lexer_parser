#pragma once
#include "op.h"
struct add_op : op
{
	double eval() override {
		return 0;
	}
	void print() override {
		std::cout << "Add\n";
	}
};
