#pragma once
#include<cmath>
#include<iostream>
#include<fftw3.h>
#include<fstream>


class WavSignal
{
	struct WAVHEADER  // Струтура, представляющая из сеья заголовок WAV файла
	{
		// Содержит символы "RIFF" в ASCII кодировке 
		char chunkId[4]; 
		
		unsigned long chunkSize; // Это размер файла - 8   
		
		char format[4]; // Содержит символы "WAVE"

		// Формат "WAVE" состоит из двух подцепочек: "fmt " и "data": 
		// Подцепочка "fmt " описывает формат звуковых данных: 
		
		char subchunk1Id[4]; // Содержит символы "fmt " 

		// 16 для формата PCM. 
		
		unsigned long subchunk1Size; // Это оставшийся размер подцепочки, начиная с этой позиции. 

		// Аудио формат
		// Для PCM = 1 (то есть, Линейное квантование). 
		unsigned short audioFormat;

		// Количество каналов    
		unsigned short numChannels;

		// Частота дискретизации    
		unsigned long sampleRate;

		// sampleRate * numChannels * bitsPerSample/8 
		unsigned long byteRate;

		// Количество байт для одного сэмпла
		unsigned short blockAlign;

		// Так называемая "глубиная" или точность звучания
		unsigned short bitsPerSample;

		// Содержит символы "data" 
		char subchunk2Id[4];

		// Количество байт в области данных. 
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

