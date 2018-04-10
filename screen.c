#include "screen.h"
#include <stdio.h>
/*function defintion of clearScreen()
	this function uses vt100 escape seguence \ESC[2j to make the whole
	termianl screen empty
	arugment : no
	return : no
*/
void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}

/*function defintion of gotoxy()
	this  function uses vt100 escape sequence \ESC[row;colH to set cursor
	to a specific location on the termial screen
	arugment: row number, 1 is top row
			  col number, 1 is left colum
	return: no
*/
void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

/*function defintiong of setColor()
	this function uses vt100 escape sequence \ESC[1;colorm to set the color
	for part of colum
	arugment: 
*/
void setColor(int color){
	if(color>=BLACK && color<=WHITE){
		printf("%c[1;%dm", ESC, color);
		fflush(stdout);
	}
}

//
void dispBar(int col, double dB){
	int i;
	for(i=0; i<dB/3; i++){
		gotoxy(30-i, col+1);
#ifndef UNICODE		//if unicode is not enable
		printf("%c", '*');
#else
		if(i<50/3) setColor(WHITE);
		else if(i<70/3) setColor(YELLOW);
		else setColor(RED);
		printf("%s", BAR);
#endif
	}	//end of for
}	//end of function
