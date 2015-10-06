
printTree(Node** tree)
{
	int j=0;
	while(tree[j])
	{
		printf("%d->",tree[j]->id);
		j++;
	}
	printf("\n");
	

}
printfloatArray(float* array, int n )
{
	if(!n)
		return;
	int i;
	for(i=0;i<n;i++)
	{
		if(i%10==0)
			printf("\n");
		printf("%.2f, ",array[i] );
	}
	 printf("\n");

}


printArray(int* array, int n)
{	
	if(!n)
		return;
	int i;
	for(i=0;i<n;i++)
	{
		if(i%10==0)
			printf("\n");
		printf("%d, ",array[i] );
	}
	 printf("\n");
}


printNode(Node *p)
{
/*	int n=p->NN;	
	printf("%d, (", p->id );


	printArray(p->adjlist, p->NN);
*/
	printf("%d\t", p->color);
	/*
	int i;
	for(i=0;i<n;i++)
		printf("%d,",p->adjlist[i]);
	printf(")\t");
*/
/*
	for(i=0;i<size*size;i++)
	{
		
		printf("%f,",p->pwin[i]);
	
	}

*/
	//printf("\n");
}




printBoard()
{
	int i,j;


	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printNode(&board[i*size+j]);
			
		}
		printf("-----------------\n");
	}
}

