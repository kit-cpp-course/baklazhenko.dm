// NotchFiltration.cpp : Defines the entry point for the console application.
//


#include"stdafx.h"
#include<cstdlib>
#include"WavSignal.h"
#include"Filter.h"
#include <iostream>
int main() {

	FILE *file;
	errno_t err;
	err = fopen_s(&file, "input.txt", "r");
	if (err)
	{
		printf_s("Failed open file, error %d", err);
		return 0;
	}
	

	

    return 0;
};

