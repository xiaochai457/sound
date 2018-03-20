#include"sound.h"
#include<stdio.h>
#include<math.h>
//function definition of printID()
void printID(char id[]){
	int i;
	for(i=0; i<4; i++)
		printf("%c",id[i]);

	printf("\n");
}

//function definitition of dispWAVData()
void dispWAVData(char filename[]){
	int i, j;
	FILE *fp;	//file handler to open the file "test.wav"
	double rms[80], sum;	//80 pleces of rma value
	short samples[SAMPLERATE];	// totally 16000 samples in 1 sec
	WAVHeader mh; 	//just used to skip over the header pf wav file
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Error when open the file!\n");
		return;
	}
	fread(&mh, sizeof(mh), 1, fp);
	fread(samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);
	for(i=0; i<80; i++){
		for(j=0, sum=0.0; j<SAMPLERATE/80; ++j){
			sum += samples[j+i*200] * samples[j+i*200];
		}
		rms[i] = sqrt(sum/200);
		printf("rms[%d]: %10.4f\n", i, rms[i]);
	}
}
// function definition of dispWAVHeader()
void dispWAVHeader(char filename[]){
	FILE *fp;
	WAVHeader mh;	//an instance of WAVHeader

	//open the test.wav file for reading
	fp = fopen(filename,"r");
	if(fp == NULL){	//if fopen fails
		printf("Error when open the file!\n");
		return;	//function stops
	}
	fread(&mh, sizeof(mh), 1, fp);
	fclose(fp);	//close the openedile
	printf("chunk ID: ");
	printID(mh.chunkID);
	printf("  chunk size: %d\n", mh.chunkSize);
	printf("Format: ");
	printID(mh.format);
	printf("  subchunk 1 ID: ");
	printID(mh.subchunk1ID);
	printf("  subchunk 1 size: %d\n", mh.subchunk1Size);
	printf("Audio format: %d\n", mh.audioFormat);	//16 for pcm
	printf("Num Channels: %d\n", mh.numChannels);
	printf("  sample Rate: %d\n", mh.sampleRate);
	printf("  byte Rate: %d\n", mh.byteRate);
	printf("  block Align: %d\n", mh.blockAlign);
	printf("  Bits per Sample : %d\n", mh.BitsPerSample);
	printf("  subchunk 2 ID: ");
	printID(mh.subchunk2ID);
	printf("  subchunk 2 size: %d\n", mh.subchunk2Size);
}
