#pragma once
#include "op.h"

struct Letter_op : op {
	double eval() override {
		return 0;
	}
	void print() override {
		std::cout << "Letter : " << cha << "\n";
	}
	char cha;
};