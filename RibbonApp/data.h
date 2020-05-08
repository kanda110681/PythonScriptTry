#pragma once

enum DataType
{
	DT_INVALID,
	DT_INPUT,
	DT_OPERATOR,
};

enum Operator
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
	int val;
};
