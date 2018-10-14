/********************************
*copyright @Mohamed abouelgoud
*date 28-9-2018
*this programe have an array consists of 40 element 
*i will do some processes to the elements of the array
*maximum, minimum, mean, and median of the array
*and also order elements of array 
**********************************/

/**********************************************
*************************************/
/*int find_maximum(unsigned int num[] ,int len);
int find_minimum(unsigned int num[] ,int len);
int find_mean(unsigned int num[] ,int len);
int find_median(unsigned int num[] ,int len);
int * sort_array(unsigned int num[] ,int len);
void print_array(unsigned int num[] ,int len);
void print_statistics(unsigned int min,unsigned int max,unsigned int mean,unsigned int median);*/
/********************************************
*********************************************/
/*
1,4,5,6,9,10,14,52,8,41, 
						56,91,78,11,25,74,65,16,23,78,
						54,18,19,24,28,27,29,35,36,38,
						41,45,48,49,75,79,82,83,99,98
*/

#include "stats.h"
#include "platform.h"
/* Size of the Data Set */
#define SIZE (40)

/*void main(void){
	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
	                              114, 88,   45,  76, 123,  87,  25,  23,
	                              200, 122, 150, 90,   92,  87, 177, 244,
	                              201,   6,  12,  60,   8,   2,   5,  67,
	                                7,  87, 250, 230,  99,   3, 100,  90};

	printf("Array before sort \n");
	printArray(test, SIZE);
	insertionSort(test, SIZE);
	printf("Array after sort \n");
	printArray(test, SIZE);
	printStats(test, SIZE);

}*/

	/* Add other Implementation File Code Here */
float find_mean(unsigned char *inputArray,unsigned int size){
	float totalSum = 0;
	for(int i = 0; i < size; i++){
		totalSum = totalSum + inputArray[i];
	}
	return totalSum/size;
}

void insertionSort(unsigned char *inputArray,unsigned int size){
	int unsortIndex, index, temp;
	for (unsortIndex = 1; unsortIndex < size; unsortIndex++){
		if(inputArray[unsortIndex] < inputArray[unsortIndex - 1]){
			temp = inputArray[unsortIndex];
			index = unsortIndex;
			do{
				inputArray[index] = inputArray[index - 1];
				index--;
			}
			while(index > 0 && inputArray[index - 1] > temp);
			inputArray[index] = temp;
		}
	}
}

int find_median(unsigned char *inputArray, unsigned int size){
	int midPoint;
	if (size % 2 == 0)
		midPoint = size/2 - 1;
	else
		midPoint = size/2;

	int median = inputArray[midPoint];
	return median;
}

int find_min(unsigned char *inputArray, unsigned int size){
	int min = inputArray[0];
	for (int i=1; i < size; i++){
		if (min > inputArray[i]){
			min = inputArray[i];
		}
	}
	return min;
}

int find_max(unsigned char *inputArray, unsigned int size){
	int max = inputArray[0];
	for (int i=1; i < size; i++){
		if (max < inputArray[i]){
			max = inputArray[i];
		}
	}
	return max;
}


void printArray(unsigned char *inputArray, unsigned int size){
	for (int i=0; i < size; i++){
		printf("%i ", inputArray[i]);
	}
	printf("\n");
}

void print_array(unsigned char *inputArray, unsigned int size){
#ifdef VERBOSE
	
		PRINTF("{");
		for (int i=0; i < size; i++){
			PRINTF("%i ", inputArray[i]);
		}
		PRINTF("}\n\n");
#endif
}

void printStats(unsigned char *inputArray, unsigned int size){
	printf("Below is the statistics of the array \n");
	printf("mean: %f\n", find_mean(inputArray,size));
	printf("median: %i\n", find_median(inputArray,size));
	printf("max: %i\n", find_max(inputArray,size));
	printf("min: %i\n", find_min(inputArray,size));
}

void PRINTF_Stats(unsigned char *inputArray,unsigned int size){
	PRINTF("Below is the statistics of the array \n");
	PRINTF("mean: %f\n", find_mean(inputArray,size));
	PRINTF("median: %i\n", find_median(inputArray,size));
	PRINTF("max: %i\n", find_max(inputArray,size));
	PRINTF("min: %i\n", find_min(inputArray,size));
}