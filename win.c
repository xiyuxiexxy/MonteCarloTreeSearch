

int* wincount;

// depth first search --> should be shortest path
int Connectivity (int id1, int id2, int* path, int* plength)
{

	////printf("connect %d, %d\n",id1,id2);
		
	int c=-1;

	if(id1 == id2)
		return 1;

	Node* np= &board[id1];

	int i;

	for(i=0;i< np->NN;i++)
	{
	
		int id= np->adjlist[i];

		////printf("node %d, neighbor%d\n",id1, id);
		if(id == id2)
			return 1;
		else
		{
			if(np->color ==board[id].color )
			{

				
				c =Connectivity(id, id2,path,plength);
				
				if (c==1)
				{
				//	//printf("neighbor %d, color %d\n", id, board[id].color);

			//	path[*plength]=id;
			//	(*plength)++;
			
				//	wincount[id]++;

					
					//ipath++;
					return 1;

				}
				
			}			
		}
	}
	return c;
}



int win(int color,int * path, int* plength)
{
	int i;

	int ipath=*plength;
	int c=0;

	
	for(i=0;i<size;i++)
	{
		if(board[i].color==color)
		{
		//	//printf("neighbor %d, color %d\n", board[i].id, board[i].color);
		
			 c= Connectivity(board[i].id,-2, path,plength);
			 if(c==1)
			 {
		//		path[*plength]=board[i].id;
		//		(*plength)++;

				//printf("%d\n",*plength);

			/*
			//	wincount[i]++;
				for(i=0;i<ipath+1;i++)
					//printf("%d, ",path[i]);*/

			
				return c;
		  	}
		
		}
		
	}


	return c;

}



/*

update()
{
	int i;
	for(i=0;i<size*size;i++)
	{
		winpro[i]= beta*wincount[i]/MAXIter;	
	}

}
*/
