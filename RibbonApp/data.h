#pragma once
#include <string>
using namespace std;

enum DataType
{
	DT_INVALID,
	DT_INPUT,
	DT_OPERATOR,
};

enum Operator // operation functions
{
	OP_INVALID,
	OP_PLUS,
	OP_MINUS,
	OP_MUL,
	OP_DIV,
};

struct Data
{
	DataType dt;
	CString value;
};
