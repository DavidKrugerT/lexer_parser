#pragma once

#include <string>
#include <cctype>
#include <algorithm>

struct token
{
	enum id {
		LETTER,
		ANY,
		PLUS,
		STAR,
		OR,
		SLASH,
		ENDPROGRAM,
		UNKNOWN
	};
	id id;

};

using it = std::string::iterator;

token lexer(const it& first, const  it& last)
{
	if (first == last)
	{
		return { token::ENDPROGRAM };
	}
	token tk;
	switch (*first)
	{
	case '+':
		tk = { token::PLUS };
		break;
	case '*':
		tk = { token::STAR };
		break;
	case '.':
		tk = { token::ANY };
	default:
		tk = { token::LETTER };
	};
	return tk;
}
