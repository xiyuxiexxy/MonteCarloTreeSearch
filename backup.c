
int learningIter=5;


int* myaction(int* remaing, int remain)
{
	int* actions =malloc(sizeof(int)*remain/2);
	int i;
	for(i=0;i<remain;i+=2)
	{
		actions[i/2]= remaing[i]; 

	}

}
/*
RAVE(int* raveCount, float * raveQ, int* remaing, int remain)
{
	int i;
	for(i=0;i<remain;i+=2)
	{
		raveCount[remaing[i]]++;

	}
}
*/

// update the score of parent

backup(int* tree, int treelength,int* remaining, int remain, int win)
{
	int i;
	
	for(i=0;i<treelength;i++)
	{

		int id = tree[i];
		
		MCtouch[id]++;
	
		MCQ[id] += (win -MCQ[id])/MCtouch[id];


		int j;


		for(j=0;j<i;j++)
		{

			int parent= tree[j];
			int* raveTouch= board[parent].raveTouch; 
			float* raveQ =  board[parent].raveQ; 

			raveTouch[id]++;
			raveQ[id] += (win - raveQ[id])/raveTouch[id];
	

		}
		




		int* raveTouch= board[id].raveTouch; 
		float* raveQ =  board[id].raveQ; 


		for(j=0; j<remain;j+=2)
		{

			// 
			int a= remaining[j];

			raveTouch[a]++;
			raveQ[a] += (win - raveQ[a])/raveTouch[a];
		}
		


	}


}


Roll()
{

	int *remaining= openindex();
	printArray(remaining, remain);
	shuffle(remaining, remain);	
		
//	printArray(remaining, remain);
	
	play(remaining, remain);


	int *actions= myaction(remaining, remain);	


	int *path= malloc(size*size*sizeof(int));
	memset(path,0,size*size*sizeof(int));
	int plength=0;


//	simulation();
	printf("\n\n");
	printBoard();


	int z=win(1,path, &plength);

	printf("win? %d\n",z);
	printArray(path,plength);

}

	
