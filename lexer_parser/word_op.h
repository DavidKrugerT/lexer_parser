#pragma once

struct Word_op :op
{
	double eval() override {
		return 0;
	}
	void print() override {
		std::cout << "Word\n";
	}
};