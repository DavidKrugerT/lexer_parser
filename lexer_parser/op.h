/*
 * File:   op.h
 * Author: martin
 *
 * Created on February 2, 2019, 5:50 PM
 */

#ifndef OP_H
#define OP_H

#include<string>
#include <vector>
#include <iostream>

struct op {
	virtual double eval() = 0;
    virtual void print() = 0;
	std::vector<op*> operands;
};


#endif /* OP_H */

