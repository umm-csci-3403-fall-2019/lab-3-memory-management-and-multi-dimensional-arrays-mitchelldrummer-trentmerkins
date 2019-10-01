#include "array_merge.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
	int m = num_arrays;
	int sum =0;
	int startindex=0;
	int size=0;
	int count=1;

	for(int i=0; i<m;++i){
	sum+=sizes[i];	
	}

	int* sort = (int*) calloc(sum,sizeof(int));
	
	for(int i=0; i<m;i++){
		for(int j=0; j<sizes[i];j++){
			sort[j+startindex] = values[i][j];
		}
		startindex+=sizes[i];	
	}
	mergesort(sum,sort);
	for(int i=0; i<sum;i++){
		if(sort[i] != sort[i+1]){
		size++;
		}
	}
	int* final = (int*) calloc(size,sizeof(int));
	final[0]=size;

	for(int i=0; i<sum;i++){
                if(sort[i] != sort[i+1]){
                	final[count]=sort[i];
			count++;
                }
        }
	free(sort);

	/*  printf("FinalArray contents [ ");

	for(int i=0; i<size+1;i++){
		printf(" %d ", final[i]);
	}
	printf(" ]");*/

  return final;
}

