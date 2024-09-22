#include "pch.h"

#include <iostream>
#include <vector>

struct test
{
	const char* name;
	const int* temp;
};


using namespace std;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	const int* temp;
	int num = 100;
	temp = &num;

	int num2 = 200;
	temp = &num2;

    return 0;
}