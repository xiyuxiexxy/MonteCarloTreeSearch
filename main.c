#include "type.h"    // data type
#include "include.h" // functions to use






main()
{
	init();   // init board, in hexboard.c
	
	int count =0;
	int i=0;

	int counts[10];
	for(i=0;i<10;i++)
	{	
		Node** tree =(Node**) malloc((size*size+1)*sizeof(Node*));      // type.h
		count= (MC_Rave(tree)+1);					// simulation2.c
		free(tree);
		counts[i]=count/2;	
		printf("count %d\n",count);
	}
	
	//printf("count %d\n",count);

	printf("\n\n");
	printArray(counts,10);
}
