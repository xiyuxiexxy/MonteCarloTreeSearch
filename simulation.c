


int findID(int num)
{
	int i;
	for(i=0;i<size*size;i++)
	{
		
		if(open[i]==0)
			continue;

		if(num==0)
			return i;
		num--;
	}

}


swap(int*i ,int *j)
{

	int tmp= *i;
		*i=*j;
		*j=tmp;

}

shuffle(int * array, int n)  // knuth shuffle
{

	int i;
	for(i=1; i<n;i++)
	{
		srand (time(NULL));
		int j= rand()%i;

	//	printf("i %d, j %d\n",i,j);
		swap(&array[i], &array[j]);

	}

}

// use shuffle function would be clear 

simulation()
{
	

	int N=size*size;
	int i;

	for(i=0;i<N;i++)
		open[i]=1;
	remain=N;
	for(i=0;i<N;i++)
	{

  	//	srand (time(NULL));
		int num= rand() %remain;	
		int id = findID(num);

	//	printf("num %d, nid %d,remain %d\n",num, id,remain);
		
		open[id]=0;

		remain--;
		
		if(i%2)
		{	
			board[id].color=1;
		}
		else
			board[id].color=-1;
	} 
}

/*
MC()
{

	wincount=malloc(size*size*sizeof(int));
	int iter;
	for (iter=0;iter<MAXIter;iter++)
	{

		simulation();
		win(1);	
	
	}

	int i;
	for(i=0;i<size*size;i++)
		printf("%d \t",wincount[i]);


	update();
	for(i=0;i<size*size;i++)
		printf("%f \t",winpro[i]);


}
*/


