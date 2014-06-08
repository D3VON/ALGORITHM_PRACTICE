// I want to make a C program to do bublesort on an array of numbers (or character?)



#include <stdio.h>

int main(void){
	// Ugh!  In C, arrays are known at compile time.
	int arr[10] = {8,7,4,1,0,5,2,9,6,3};
	
	int i;
 	for(i = 0; i<10; i++){
		printf("%d ", arr[i]);	
	}
	printf("\n");
	
	
	int a;
	for(i = 0; i<10; i++){
		a=i+1;
		for(; a<10; a++){// 'bubble' through entire series of elements
			if(arr[i] > arr[a])	{
				// swap without making temp variable
				arr[i]=arr[a]-arr[i];
				arr[a]=arr[a]-arr[i];
				arr[i]=arr[i]+arr[a];
			}
		}
	}

 	for(i = 0; i<10; i++){
		printf("%d ", arr[i]);	
	}
	printf("\n");
	
	
	return 0;


}