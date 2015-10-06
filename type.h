#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// variables for board

int size=7; 	  //7, 11,19
int *remaining;




typedef struct node
{
	int x;
	int y;
	
	int id;
	
	int NN;		// number of neighbers
	int* adjlist;	// adjacent list for adjacent node, 6 is maximal

	int color;      // -1,1 write, black

	//float* pwin;
	

	int* MCtouch;
	float* MCQ;		// MC score	

	int* raveTouch;
	float* raveQ;		// rave Score
	
		
}Node;


Node North;
Node South;
Node Q0;

Node* board;

int* open;
float* winpro;
int remain;

int* path;
//int ipath;

int* wincount;

float beta=1.0;

//int iter=0;

int MAXIter=10;









