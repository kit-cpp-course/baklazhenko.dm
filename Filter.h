#pragma once
#include"WavSignal.h"
#include<fftw3.h>
#include<fstream>

class Filter {

public:
	virtual ~Filter() {};

};
/*Класс реализующий процесс заградительной частотной фильтрации
Наследуются от общего класса Filter. Для фильтрации используется разложение в спектр методом быстрого преобразования Фурье*/

class NotchFilter:public Filter {
protected:
	double* samples;
	double* freq;
	unsigned long length;
	int sampleRate;
public:
	NotchFilter(WavSignal signal);
	~NotchFilter();

	 void Filtration(int lower, int upper);
};