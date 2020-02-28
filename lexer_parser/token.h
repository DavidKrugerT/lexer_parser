#pragma once

#include <string>
#include <cctype>
#include <algorithm>

struct token
{
	enum id {
		CHAR,
		WORD,
		ANY,
		PLUS,
		STAR,
		OR,
		END,
		UNKNOWN,
		I,
		O
	};
	id id;

};

using it = std::string::iterator;

token lexer(const it& first, const  it& last)
{
	if (std::string(first, first+2) == "\\I")
	{
		return { token::I };
	}
	if (std::string(first, first + 2) == "\\O")
	{
		return { token::O };
	}
	if (first == last)
	{
		return { token::END};
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
		tk = { token::CHAR };
	};
	return tk;
}
