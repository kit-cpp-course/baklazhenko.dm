#include"stdafx.h"
#include"Filter.h"

NotchFilter::NotchFilter(WavSignal signal)
{
	freq = new double[signal.GetLength()];
	samples = new double[signal.GetLength()];
	for (int i = 0; i < signal.GetLength(); i++) {
		samples[i] = signal.getWavData()[i];
	}
	length = signal.GetLength();
	sampleRate = signal.getSampleRate();
};

NotchFilter::~NotchFilter() {
	delete[] freq;
	delete[] samples;
};

void NotchFilter::Filtration(int lower, int upper) {
	
	int L =length / 2 + 1;
	fftw_complex* spec = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * L);

	fftw_plan pforward = fftw_plan_dft_r2c_1d(length, samples, spec, FFTW_ESTIMATE); //��������� ������ ������� �������������� ����� ����� �������� ������ �������
	fftw_execute(pforward);

	//FILE *fRes;
	//fopen_s(&fRes, "C:/Users/Asus/Desktop/spec.txt", "w");

	//for (int i = 0; i<dataLen; i++)
	//{
	//	fprintf_s(fRes, "%f, ", wavData[i]);  // �������� �� � ���� ����� �������� ������� �������� � Matlab
	//}
	//fclose(fRes);

	for (int i = 0; i < length; i++)
	{
		freq[i] = sampleRate / 2 * i / (length / 2); // ������ �������
		
		if (freq[i] < upper && freq[i]>lower) {   //���������� ������, ��� ������, �������� ������� ���������� � ��������
			spec[i][0] = 0;
			spec[i][1] = 0;
		}
	}
	
	fftw_plan pbackward = fftw_plan_dft_c2r_1d(length, spec, samples, FFTW_ESTIMATE); //��������� �������� �������������� �����
	fftw_execute(pbackward);
	

	SoundMaker S("Newsignal.wav");  // ��������� ��������������� ������ ������� � ����
	for (int i = 0; i<length; i++)
	{
		S.add_sample(samples[i], 0);  // ��������� ������ �������
	}

	S.done();

	fftw_free(spec); //����������� ������
	fftw_destroy_plan(pforward);
	fftw_destroy_plan(pbackward);
}
