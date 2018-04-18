#include "comm.h"
#include <stdio.h>	//sprintf()
#include <curl/curl.h>	//libcurl
#include <math.h>

//this function takes in RMS value of 1 scond,each is calculated by 16000/80=200
//samples, but the function will re-calculate 8-pieces of RMS value,each
//corresponding to 2000 samples or 125ms of sound
/*
	function definition of sendToserver()
	This function is simple HTTP post using the esay inerface
	input argument:double r80[]
	outout argument: none
*/
void sendToServer(double rms[]){
	double fast[8],sum;
	int i, j;
	CURL *curl;
	CURLcode res;
	char post[1000];

	for(i=0; i<8; i++){		//outer loop repeats 8 times for 8-pieces of result
		for(j=0, sum=0; j<10; j++){		//inner loop repeats 10 times to accumlate 
			sum += (rms[j+i*10]*rms[j+i*10])*200;
		}
		fast[i] = sqrt(sum/2000);
	}	//end of for[i]
	//prepare post data
	sprintf(post, "data=%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;&.2f",
		fast[0], fast[1], fast[2], fast[3], fast[4], fast[5], fast[6], fast[7]);

	//send data
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl){
		curl_easy_setopt(curl, CURLOPT_URL, URL);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
		res = curl_easy_perform(curl);
		printf("performed\n");
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

		curl_easy_cleanup(curl);
	}	//end of if
	else printf("Curl cannot initiated\n");
	curl_global_cleanup();
}
