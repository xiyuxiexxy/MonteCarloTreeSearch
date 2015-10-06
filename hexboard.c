//#include "type.h"
//#include "include.h"



init()
{
/*	
	North.id =-1;
	North.NN=size;		// number of neighbers		
	North.adjlist= malloc(size* sizeof(int));

	

	for(i=0;i++;i<size)
	{
		North.adjlist[i]=i;
	}

*/

	
		
	int i;

	int N= size*size;
	board= malloc(N*sizeof(Node));



	remain=N;
	open= malloc(N*sizeof(int));
	memset(open, 0, N*sizeof(int));

	remaining= (int *) malloc(N*sizeof(int));

/*
	for(i=0;i<N;i++)
		open[i]=0;
	
*/

	Q0.MCQ= malloc(N*sizeof(float));
	memset(Q0.MCQ,0, N*sizeof(float));


	Q0.MCtouch= malloc(N*sizeof(int));
	memset(Q0.MCtouch,0, N*sizeof(int));
	



	Q0.raveQ= malloc(N*sizeof(float));
	memset(Q0.raveQ,0, N*sizeof(float));


	Q0.raveTouch= malloc(N*sizeof(int));
	memset(Q0.raveTouch,0, N*sizeof(int));

	Q0.id=-1;
	//winpro= malloc(N*sizeof(float));

	for(i =0;i<N;i++)
	{
		board[i].id=i;
		int x = board[i].x=i/size;
		int y = board[i].y=i%size;
		
		board[i].adjlist= malloc(6*sizeof(int));

		int ilist=0;

		if(i>=N-size)		// add south 
		{
			board[i].adjlist[ilist] = -2;	
			ilist++;
		}
	
		if(y+1<size)
		{ 
			board[i].adjlist[ilist] = x*size+ y+1;	
			ilist++;
			
		}
	/*	if(y-1>=0)
		{
			ilist = x*size+ y-1;	
			ilist++;
		}

	*/
		if(x+1<size)
		{
			board[i].adjlist[ilist] = (x+1)*size+ y;	
			ilist++;
		}
		
		if(x+1<size&& y-1>=0)
		{
			board[i].adjlist[ilist] = (x+1)*size+ y-1;	
			ilist++;
		}

		// less then cases are ignored for depth first search
	
		board[i].NN= ilist;
	//	//printf("neighbors %d, %d\n",ilist,board[i].adjlist[0]  );

		
		board[i].raveQ= malloc(N*sizeof(float));
		memset(board[i].raveQ,0, N*sizeof(float));


		board[i].raveTouch= malloc(N*sizeof(int));
		memset(board[i].raveTouch,0, N*sizeof(int));

		board[i].MCQ= malloc(N*sizeof(float));
		memset(board[i].MCQ,0, N*sizeof(float));


		board[i].MCtouch= malloc(N*sizeof(int));
		memset(board[i].MCtouch,0, N*sizeof(int));
	
	}

}

int lastopen()
{
	int i=0;
	for(i=0;i<size*size;i++)
	{
		if(open[i]==0)
			return i;
	}


}
setMove(int a,int color)
{
	open[a]=1;	
	remain--;
	board[a].color= color;
}
 openindex(int* remaining)
{
	//int* remaining = malloc(remain*sizeof(int));
	int i=0,j=0;	
	int N= size*size;
	for(i=0;i<N;i++)
	{
		if(open[i]==0)
		{
			remaining[j]=i;
			j++;
		}	
	}	

	printf("length remain %d\n",j);
//	return remaining;
}




play(int* remaining,int remain)
{
	int i;
	for(i=0;i<remain;i++)
	{

  		int id= remaining[i];
		
		if(i%2)
		{	
			board[id].color=1;
		}
		else
			board[id].color=-1;
	} 
}



/*
int main()
{
	init();
	
	printBoard();

	

}
*/
