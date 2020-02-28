#pragma once
#include "op.h"
struct I_op : op
{
	double eval() override {
		return 0;
	}
	void print() override {
		std::cout << "SLASH_I\n";
	}
};

struct O_op : op
{
	double eval() override {
		return 0;
	}
	void print() override {
		std::cout << "SLASH_O\n";
	}
};
