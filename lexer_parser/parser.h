#pragma once
#include <vector>
#include "token.h"
#include "op.h"
#include "add_op.h"
#include "Word_op.h"
#include "star_op.h"
#include "ingore_op.h"

/*
<MATCH>		:= <STAR> | <IGNORE>
<ADD_OP>	:= <STRING> + <STRING>
<STRING>	:= <A-Z>* | <a-z>*
<PROG>		:= <ADD_OP>
*/

using Iterator = std::vector<token>::const_iterator;

class Parser
{
public:
	Parser();
	~Parser();
	op* parse(const std::vector<token> &tokens);

private:
	Iterator first, last;
	const token* eat_if(token::Id id);
	op* build_string();
	op* build_add(op* lhs);
	op* build_star(op* lhs);
};


