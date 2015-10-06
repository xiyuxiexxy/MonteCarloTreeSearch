
int MC(int* remaining, int remain)
{

	shuffle(remaining, remain);
	
	
	play(remaining, remain);

	int * path;
	int plength;

/*	
	int *path= malloc(size*size*sizeof(int));
	memset(path,0,size*size*sizeof(int));
	int plength=0;
*/

	int z=win(1,path, &plength);

//	printArray(remaining, remain);


	//free(path);
	
	return z;

}


Roll(Node *p, Node** tree)
{
	
	printf("Roll remain %d\n",remain);
//	remaining= (int*)malloc((remain+2)*sizeof(int));

	memset(remaining,0,(remain+2)*sizeof(int));
	printf("after malloc\n");
	
	openindex(remaining);

	
	printArray(remaining,remain);
	

	int i;
	for(i=0;i<MAXIter;i++)
	{
		int z= MC(remaining,remain);
		//printf("win? %d\n",z);
		if(z==1)
			update(p,remaining, remain,z, tree);
		else
			update(p,remaining, remain,0,tree);
	}


//	free(remaining);
	printf("Roll for %d\n",p->id );	
}



setTree(Node** tree, Node* s)
{
	int j=0;
	while(tree[j])
		j++;
	tree[j]=s;
}

int MCMove(Node* p, Node** tree)
{
	Roll(p,tree);
	int a= selectMove(p);
	setMove(a,1);
	setTree(tree, &board[a]);
	return a;
}


int MC_Rave(Node** tree)
{
	
	memset(tree,0,(size*size+1)*sizeof(Node*));
	tree[0]= &Q0;

	remain =size*size;
	memset(open, 0,size*size*sizeof(int));

	printTree(tree);
	int i;
	Node *p=&Q0;
	for(i=0; i<size*size;i++)
	{
		if(i%2==0)
		{
			int a=-3;
			if(remain==1)
				a= lastopen();		
			
			else
				a= MCMove(p,tree );
	
			p= &board[a];
			printf("MC Move %d \n",a);
		}
		else
		{
			int b= dummyMove();
			printf("dummy mov %d \n",b);
		}

		printTree(tree);
	}
	
	printBoard();

	int *path;
	int length;
	int z = win(1,path,&length );

	printf("win?  %d\n",z);

	return z;	
}


