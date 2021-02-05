#include "parser.h"

Parser::Parser()
{
}

Parser::~Parser()
{
}

op* Parser::parse(const std::vector<token>& tokens)
{
	first = tokens.begin();
	last = tokens.end();
	build_string();
	return nullptr;
}

//private functions
const token* Parser::eat_if(token::Id id)
{
	if (first->id == id)
	{
		return &*first++;
	}
	return nullptr;
}

op* Parser::build_string() {
	
	auto token = eat_if(token::CHAR);
	if (token == nullptr) return nullptr;
	Word_op* word = new Word_op;

	while (token)
	{
		word->str += token->value;
		token = eat_if(token::CHAR);
	}
	return word;
}

op* Parser::build_add(op* lhs)
{

	if (eat_if(token::ADD) == nullptr) return nullptr;
	op* rhs = build_string();
	if (rhs == nullptr) return nullptr;
	Add_op* add = new Add_op;
	add->operands.push_back(lhs);
	add->operands.push_back(rhs);
	return add;
}

op* Parser::build_star(op* lhs) {
	if (eat_if(token::STAR) == nullptr) return nullptr;
	Star_op* star = new Star_op;
	star->operands.push_back(lhs);
	return star;
}








