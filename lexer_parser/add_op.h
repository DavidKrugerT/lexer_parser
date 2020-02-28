#pragma once
#include "op.h"
struct add_op : op
{


	//std::string rhs, lhs;
	//add_op(std::string lhs, std::string rhs) : rhs(rhs), lhs(lhs) {}

	double eval() override {
		return 0;
	}


	void print() override {
		std::cout << "Add\n";
	}
};
