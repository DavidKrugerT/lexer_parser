#pragma once

#include <string>
#include <cctype>
#include <algorithm>

struct token
{
	enum Id {
		CHAR,
		ANY,
		ADD,
		STAR,
		END,
		UNKNOWN,
		I,
		O,
		COUNTER
	};
	Id id;
	std::string value;
};

using it = std::string::iterator;

token lexer(it& first, const  it& last)
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
		tk = {token::ADD };
		first++;
		break;
	case '*':
		tk = {token::STAR };
		break;
	case '.':
		tk = {token::ANY };
		break;
	case '{':
		tk = {token::COUNTER };
		first++;
		while (*first != '}')
		{
			tk.value.push_back(*first);
			first++;
		}
		break;
	default:
		tk = { token::CHAR };
		tk.value.push_back(*first);
		break;
	};
	return tk;
}
