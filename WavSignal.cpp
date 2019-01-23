#include "stdafx.h"
#include "WavSignal.h"



WavSignal::WavSignal(FILE* file)
{
	
	short *s;
	
	fread(&header, sizeof(WAVHEADER), 1, file); //Считываем заголовок
	dataLen= header.subchunk2Size / sizeof(short);

	s = (short*)calloc(dataLen, sizeof(short));
	wavData = (double*)calloc(dataLen, sizeof(double));

	fread(s, sizeof(short), dataLen, file);
	for (int i = 0; i<dataLen; i++) // Заполняем массив данных
	{
		wavData[i] = (double)(s[i]) /32768; // /32768 для нормировки чтобы получить соотношение (Дц -Гц)
	}
	
	fclose(file);
	delete[] s;
}


WavSignal::~WavSignal()
{

	delete[] wavData;
}


void WavSignal::CreateWav() {
	// Создание нового wav файла

	SoundMaker S( "spectest.wav");
	for (int i = 0; i<dataLen; i++)
	{
		S.add_sample(wavData[i], 0);  // Заполняем массив сэмплов
	}

	S.done();

}
