#pragma once
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class __declspec(dllexport) MyMath
{
	int a, b;
public:
	MyMath()
	{
		a = 5;
		b = 2;
	}

	MyMath(int x, int y)
	{
		a = x ;
		b = y;
	}

	int add()
	{
		return a + b;
	}

	int add(int x, int y)
	{
		return x + y;
	}

	string details()
	{
		return "MyMath class";
	}
};