#pragma once

struct String_op :op
{
	double eval() override {
		return 0;
	}
	void print() override {
		std::cout << "String\n";
	}
};