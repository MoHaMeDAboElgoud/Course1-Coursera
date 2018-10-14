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

#include<stdio.h>
#include"stats.h"

int main()
{
	unsigned int inp[] = {34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

int length = sizeof(inp)/sizeof(int);
print_array(inp,length);
int min = find_minimum(inp,length);
int max = find_maximum(inp,length);
float mean = find_mean(inp,length);
int * p = sort_array(inp,length);

printf("After Sorting ");
print_array(inp,length);

float median = find_median(inp,length);

print_statistics(min,max,mean,median);

}

int find_maximum(unsigned int num[] ,int len)
{
	int maxnum=num[0];
	for(int i = 1;i<len;i++)
	{
		if(maxnum < num[i])
		{
			maxnum = num[i];
		}
	}
	return maxnum;
}

int find_minimum(unsigned int num[] ,int len)
{
	int minnum=num[0];
	for(int i = 1;i<len;i++)
	{
		if(minnum > num[i])
		{
			minnum = num[i];
		}
	}
	return minnum;

}

float find_mean(unsigned int num[] ,int len)
{
	int sum =0;
	for(int i=0;i<len;i++)
	{
		sum+=num[i];
	}
	return ((float)sum/len);

}

float find_median(unsigned int num[] ,int len)
{
	return((float)(num[19]+num[20])/2);

}

int * sort_array(unsigned int num[] ,int len)
{
	for(int i =0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(num[i]<num[j])
			{
				int temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
	}

	return num;

}

void print_array(unsigned int num[] ,int len)
{
	printf("The array is : \n");
	for(int i = 0; i<len;i++)
	{
		printf(" %d ",num[i]);
	}
	printf("\n");

}

void print_statistics(unsigned int min,unsigned int max,float mean,float median)
{
	printf("Minimum number is ---> %d \n",min);
	printf("Maximum number is ---> %d \n",max);
	printf("Mean number is ---> %f \n",mean);
	printf("Median number is ---> %f \n",median);

}
