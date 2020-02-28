#include "token.h"
#include "op.h"
#include "add_op.h"
#include "Word_op.h"
#include "char_op.h"
#include "star_op.h"
#include "ingore_op.h"

#include <iostream>
#include <regex>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>


//hej - j ska hamna som en char i * 

/*
<ADD_OP>	:= <STRING> + <STRING>
<STRING>	:= <CHAR>
<CHAR>		:= a-z
<FIND>		:= <MATCH>
<MATCH>		:= <WORD><REPEAT>
<REPEAT		:= <WORD>*
<WORD>		:= <CHAR>+ | <CHAR><>WORD>
*/

std::string stringprogram = "davidddd";
std::string program = "hej+da";
std::string program2 = "loo*";

using it = std::string::iterator;

op* star_parse(it&, it, op*);
op* find_parse(it, it, op*);
//op* add_parse(it, it);
op* build_tree(it, it);

//char_parse only checks the current pointer position returns if that token is a CHAR.
op* char_parse(it &first, it last) {

	token lex = lexer(first, last);
	if (lex.id == token::CHAR) {
		Char_op* char_op = new Char_op();
		char_op->cha = *first;
		return char_op;
	}
	return nullptr;
}

// string_parse will loop through the chars in the string intill it makes a full string. untill first unchar token.
op* word_parse(it &first, it last) {
	token lex;
	Word_op* string_op = new Word_op();
	do {
		op* cha = char_parse(first, last);
		string_op->operands.push_back(cha);
		first++;
		lex = lexer(first, last);
	} while (lex.id == token::CHAR);
	return string_op;
}

op* add_parse(it& first, it last, op* lhs) {
	token lex;
	lex.id = token::id::UNKNOWN;
	lex = lexer(first, last);
	if (lex.id != token::PLUS) {
		return nullptr;
	}
	first++;
	op* rhs = build_tree(first, last);
	if (!rhs) {
		return nullptr;
	}
	add_op* add = new add_op();
	add->operands.push_back(lhs);
	add->operands.push_back(rhs);
	return add;
}

op* star_parse(it &first, it last, op* child) {
	token lex;
	lex = lexer(first, last);
	if (lex.id != token::STAR) {
		return nullptr;
	}
	first++;
	Star_op* star = new Star_op();
	star->operands.push_back(child);
	return star;
}

op* slash_parse(it& first,it last, op* child) {
	token lex;
	lex = lexer(first, last);
	if (lex.id == token::I)
	{
		I_op* I = new I_op();
		I->operands.push_back(child);
		return I;
	}
	O_op* O = new O_op();
	O->operands.push_back(child);
	return O;
}

// skapar en rot med char_parse och en star_parse med den roten.
op* build_tree(it first, it last) {
	op* root = nullptr;
	root = word_parse(first, last); //string �r skapad och har returnats in i root = "loo" i vectorns operands
	if (!root) {
		return nullptr;
	}
	op* unop = nullptr;
	unop = star_parse(first, last, root);
	if (unop) {
		root = unop;
	}
	unop = slash_parse(first, last, root);
	if (unop)
	{
		root = unop;
	}
	op* binop = nullptr;
	binop = add_parse(first, last, root);
	if (binop) {
		root = binop;
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
	

	//string_parse build
	//auto begin = stringprogram.begin();
	//op* word_op = word_parse(begin, stringprogram.end());

	////add_op build
	//op* add_op = add_parse(begin, program.end());
	
	//star_op build tree
	std::string program3 = "loo*\\I";
	auto begin = program3.begin();
	op* op = build_tree(begin, program3.end());
	std::cout << program3;
	//
	//op* Find_op = find_star_parse(program2.begin(), program2.end());

	//std::cout << "find_op:\n\n";
	//display(Find_op);
	//std::cout << "string_op:\n\n";
	//display(word_op);
	//std::cout << "add_op:\n\n";
	//display(add_op);
	std::cout << "\nop:\n\n";
	display(op);

	return 0;
}