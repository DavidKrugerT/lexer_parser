#pragma once
#include "op.h"

struct Char_op : op {
	double eval() override {
		return 0;
	}
	void print() override {
		std::cout << "Char : " << cha << "\n";
	}
	char cha;
};