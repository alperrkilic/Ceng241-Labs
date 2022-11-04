#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int n1=0;
	int n2=0;
	
	int *array1;
	int *array2;
	
	
	printf("Enter length of first array: ");
	scanf("%d",&n1);
	
	array1=(int*)malloc(n1 * sizeof(int));
	
	printf("Enter numbers: ");
	
	int i=0;
	
	for(i=0;i<n1;i++)
	{
		scanf("%d",&array1[i]);
	}
	
	printf("Enter length of second array: ");
	scanf("%d",&n2);
	
	array2=(int*)malloc(n2 * sizeof(int));
	
	
	printf("Enter numbers: ");
	
	for(i=0;i<n2;i++)
	{
		scanf("%d",&array2[i]);
	}
	
	int *merged_array;
	int n3;
	
	n3=n1+n2;
	
	merged_array=(int*)malloc(n3 * sizeof(int));
	
	for(i=0;i<n1;i++)
	{
		merged_array[i]=array1[i];
	}
	
	//first n1 elements of the array1 is now set to merged array
	
	int t=0;
	
	for(i=n1;i<n3;i++)
	{
		merged_array[i]=array2[t];
		t++;
	}
	
	//second array's elements have been set to merged_array now.
	//after this point I have all elements in the merged_array but they are not in ascending order.
	//I have to sort them.
	
	int temp;
	int j;
	
	for(i=0;i<n3;i++)
	{
		for(j=i;j<n3;j++)
		{
			if(merged_array[j]<merged_array[i])
			{
				temp=merged_array[j];
				merged_array[j]=merged_array[i];
				merged_array[i]=temp;
			}
		}
	}
	
	printf("\nMerged array: ");
	for(i=0;i<n3;i++)
	{
		printf("%d ",merged_array[i]);
	}
	
	free(array1);
	free(array2);
	free(merged_array);
	
	return 0;
	
}