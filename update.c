	

updateRave(Node* s, int a, int z)
{
	s->raveTouch[a]++;
	s->raveQ[a]  += (z -s->raveQ[a])/s->raveTouch[a];
	
}

updateRave4all(Node* s, Node** tree, int* remaining, int z)
{


	//printf("rave update %d \n",s->id);	
	int j=0;
	while(tree[j]!=s)
	{	
		// update rave for simulation part
		int i;
		for(i=0; i<remain;i+=2)
		{
			int a= remaining[i];

			updateRave(tree[j],a,z);
			
		}

		int t= j+1;
		while(tree[t]!=s)
		{
			int a= tree[t]->id;
			
			updateRave(tree[j],a,z);
			t++;
		}

		updateRave(tree[j],s->id,z);
		j++;

	}
	
	
	//update rave for s
	int i;
	for(i=0; i<remain;i+=2)
	{
		int a= remaining[i];

		updateRave(s,a,z);
			
	}

	//
//	printf("After Rave\n");
//	printfloatArray(s->raveQ,size*size);
//	getchar();
	
//	printf("updateAll\n");
}


updateMC(Node* s, int a,int z)
{
	s->MCtouch[a]++;
	s->MCQ[a]  += (z -s->MCQ[a])/s->MCtouch[a];

}
update(Node* s, int* remaining, int remain,int z, Node** tree)
{

//	printf("update for node %d \n",s->id);

	
	int i=0;
	
	while(tree[i]!=s)
	{
		int a= tree[i+1]->id;
		updateMC(tree[i],a,z);
		i++;
	}
	

	
	int a= remaining[0];
	updateMC(s,a,z);
	
	
//	printf("first action %d, %d\n",a, z);
//	printfloatArray(s->MCQ,size*size);


/*	printBoard();
	int *p;


	int length;
	printf("win %d\n",win(1,p,&length));

	printf("MC after update\n");
	printfloatArray(s->MCQ,size*size);

*/	
//	getchar();

	updateRave4all(s, tree, remaining,z);


	
}


