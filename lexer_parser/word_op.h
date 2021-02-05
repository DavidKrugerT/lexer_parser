#pragma once
#include <string>
struct Word_op :op
{
	std::string str;

	double eval() override {
		return 0;
	}
	void print() override{
		std::cout << "Word: "<< str << "\n";
		
	}
	
};