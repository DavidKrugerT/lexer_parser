#include "token.h"
#include "op.h"
#include "add_op.h"
#include "string_op.h"
#include "letter_op.h"
#include "star_op.h"

#include <iostream>
#include <regex>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>

//hej - j ska hamna som en char i * 

/*

<ADD_OP>	:= <string> + <string>
<STRING>	:= <letter>+
<LETTER>	:= a-z
<STAR>		:= <STRING>*

*/

std::string program = "hej+da";
std::string program2 = "loo*";
using it = std::string::iterator;

op* letter_parse(it &first, it last) {
	token lex = lexer(first, last);
	if (lex.id != token::LETTER) {
		return nullptr;
	}
	Letter_op* letter_op = new Letter_op();
	
	letter_op->cha = *first;

	return letter_op;
}

op* string_parse(it &first, it last) {
	token lex;
	String_op* string_op = new String_op();
	do {
		op* let = letter_parse(first, last);
		string_op->operands.push_back(let);
		first++;
		lex = lexer(first, last);
	} while (lex.id == token::LETTER);

	return string_op;
}

op* add_parse(it first, it last) {
	token lex;
	lex.id = token::id::UNKNOWN;
	op* lhs = string_parse(first, last);
	if (!lhs) {
		return nullptr;
	}
	
	lex = lexer(first, last);
	if (lex.id != token::PLUS) {
		return nullptr;
	}
	first++;
	op* rhs = string_parse(first, last);
	if (!rhs) {
		return nullptr;
	}
	add_op* add = new add_op();
	add->operands.push_back(lhs);
	add->operands.push_back(rhs);
	return add;
}

/*
op* star_parse(it first, it last) {
	token lex;
	lex.id = token::id::UNKNOWN;
	op* recived_string = string_parse(first, last);
	if (!recived_string) {
		return nullptr;
	}
	lex = lexer(first, last);
	if (lex.id != token::STAR) {
		return nullptr;
	}
	Star_op* add = new Star_op();
	add->operands.push_back(recived_string);
	return add;
}
*/

op* star_parse(it first, it last, op* child) {
	token lex;
	lex = lexer(first, last);
	if (lex.id != token::STAR) {
		return nullptr;
	}
	Star_op* star = new Star_op();
	star->operands.push_back(child);
	return star;
}

op* build_tree(it first, it last) {
	op* root = nullptr;
	root = string_parse(first, last);
	if (!root) {
		return nullptr;
	}
	op* unop = nullptr;
	unop = star_parse(first, last, root);
	if (unop) {
		root = unop;
	}
	return root;
}

int indent = 0;

void display(op* root) {
	if (!root) {
		return;
	}

	for (int i = 0; i < indent; i++) {
		std::cout << "  ";
	}
	root->print();
	indent++;

	for (auto child : root->operands) {
		display(child);
	}
	indent--;
}

int main() {
	op* add_op = add_parse(program.begin(), program.end());
	//op* star_op = star_parse(program2.begin(), program2.end());
	op* star_op = build_tree(program2.begin(), program2.end());
	std::cout << "add_op:\n\n";
	display(add_op);
	std::cout << "\nstar_op:\n\n";
	display(star_op);

	return 0;
}