#include <time.h>
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

