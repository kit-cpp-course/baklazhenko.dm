
#pragma once
#include<iostream>

template<class T> class Signal
{

public:

	Signal::Signal() :length(0), Freq(0)
	{}

	Signal::Signal(size_t* SampleData, size_t length, size_t Freq):length(length),Freq(Freq)
	{
		wavData = (size_t*)calloc(dataLen, sizeof(size_t))
	}

	Signal::~Signal() {}

};