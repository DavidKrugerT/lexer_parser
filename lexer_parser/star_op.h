#pragma once
#include "op.h"
struct Star_op : op
{
	double eval() override {
		return 0;
	}
	void print() override {
		std::cout << "Star\n";
	}
};