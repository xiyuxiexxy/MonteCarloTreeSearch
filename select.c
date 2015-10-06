


int findID(int num)
{
	int i;
	for(i=0;i<size*size;i++)
	{
		
		if(open[i]==1)
			continue;

		if(num==0)
			return i;
		num--;
	}

}


int dummyMove()
{
	srand (time(NULL));
	int num= rand() %remain;	
	int id = findID(num);
	return id;
}
/*
int dummyMove()
{
	int* remaining= openindex();
	int index = rand()%remain;
	
	int a= remaining[index];
	
	
	////printf("dummu move %d",a);
	
	setMove(a,-1);	
	free(remaining);
	return a;
}
*/

int maxIndex(float* MCQ, int n)
{
	int index =0;
	int i;
	for(i=1;i<n;i++)
	{
		if(MCQ[i]>MCQ[index])
			index=i;
	}

	return index;
}


float combinedQ(float treeQ, float subQ)
{
	beta *=0.999999;
	return (1-beta)*treeQ+beta*subQ;
}


/*
float combinedQ(int treeC, float treeQ, int subC, float subQ )
{
//	float beta= (float) subC / (treeC +subC +4*subC*treeC );
//	printf("beta %f\n",beta);
	
	beta=beta*0.9999;
//	printf("beta %f\n",beta);
	return (1-beta)*treeQ+beta*subQ;
	
}

*/


int selectMove(Node *p)
{

	
	
//	float* Qvalue= malloc(size*size*sizeof(float));

	printf("Combined Q: \n");
	int i;

	printf("select for id %d\n",p->id);

	int a=0;
	
	float max=-1;
	
	for(i=0;i<size*size;i++)
	{
//		int  treeC= p->MCtouch[i];

		if(open[i]==1)
			continue;

		float treeQ= p->MCQ[i];
//		int  subC =  p->raveTouch[i];
		float subQ= p->raveQ[i];

		
		float cQ=combinedQ(treeQ, subQ);

		if(cQ>max)
		{
			max=cQ;
			a=i; 
			
		}	
	}

	
//	printfloatArray(Qvalue,size*size);



//	int a= maxIndex(Qvalue, size*size);


	printf("select move %d with combinedQ %f\n", a,max);	
	setMove(a,1);

//	free(Qvalue);
	printf("select move\n");	
	return a;
	

}	

