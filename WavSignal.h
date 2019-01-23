#pragma once
#include<cmath>
#include<iostream>
#include<fftw3.h>
#include<fstream>


class WavSignal
{
	struct WAVHEADER  // ��������, �������������� �� ���� ��������� WAV �����
	{
		// �������� ������� "RIFF" � ASCII ��������� 
		char chunkId[4]; 
		
		unsigned long chunkSize; // ��� ������ ����� - 8   
		
		char format[4]; // �������� ������� "WAVE"

		// ������ "WAVE" ������� �� ���� ����������: "fmt " � "data": 
		// ���������� "fmt " ��������� ������ �������� ������: 
		
		char subchunk1Id[4]; // �������� ������� "fmt " 

		// 16 ��� ������� PCM. 
		
		unsigned long subchunk1Size; // ��� ���������� ������ ����������, ������� � ���� �������. 

		// ����� ������
		// ��� PCM = 1 (�� ����, �������� �����������). 
		unsigned short audioFormat;

		// ���������� �������    
		unsigned short numChannels;

		// ������� �������������    
		unsigned long sampleRate;

		// sampleRate * numChannels * bitsPerSample/8 
		unsigned long byteRate;

		// ���������� ���� ��� ������ ������
		unsigned short blockAlign;

		// ��� ���������� "��������" ��� �������� ��������
		unsigned short bitsPerSample;

		// �������� ������� "data" 
		char subchunk2Id[4];

		// ���������� ���� � ������� ������. 
		unsigned long subchunk2Size;
	};

	WAVHEADER header;
	double* wavData;
	 int dataLen;
public:

	WavSignal(FILE* file);
	~WavSignal();

	void CreateWav();

	
	int GetLength() { return dataLen; }
	double* getWavData() { return wavData; }
	unsigned long getSampleRate() { return header.sampleRate; }
};

