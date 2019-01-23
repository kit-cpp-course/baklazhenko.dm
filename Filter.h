#pragma once
#include"WavSignal.h"
#include<fftw3.h>
#include<fstream>

class Filter {

public:
	virtual ~Filter() {};

};
/*����� ����������� ������� �������������� ��������� ����������
����������� �� ������ ������ Filter. ��� ���������� ������������ ���������� � ������ ������� �������� �������������� �����*/

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