// constant definitions
#define SAMPLERATE 16000

// struct / union definitions
typedef	struct{
	char chunkID[4];	// "RIFF"
	unsigned int chunkSize;	// 4 bytes
	char format[4];	 	//"wave"
	char subchunk1ID[4];	//"fut"
	unsigned int subchunk1Size;
	unsigned short audioFormat;	//16 for pcm
	unsigned short numChannels;
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short BitsPerSample;
	char subchunk2ID[4];
	unsigned int subchunk2Size;
}WAVHeader;

//function prototypes
void dispWAVHeader(char filename[]);
void dispWAVData(char filename[]);
void printID(char []);
