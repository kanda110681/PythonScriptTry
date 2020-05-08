#pragma once

//#define EXPOSE extern "C"  //__declspec(dllexport)
//#define EXPOSE __declspec(dllexport)  
//EXPOSE int mul(int a, int b);
//EXPOSE int division(int a, int b);

#define EXPOSE extern "C"   __declspec(dllexport) 

EXPOSE int mul(int a, int b)
{
	return a * b;
}

EXPOSE int division(int a, int b)
{
	return a / b;
}
