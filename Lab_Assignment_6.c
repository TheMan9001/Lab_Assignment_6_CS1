#include <stdio.h>

int search(int numbers[], int low, int high, int value){
	int middle;
	if(low <= high){
	//checks if there is at least one index to check between low and high(inclusive)
		middle = (low + high)/2;
		//gets the middle index
		if(numbers[middle] == value){
		//if the value of the middle index equals the desired value return that index ...
			return middle;
		}else{
		/*
		... otherwise check if the value of middle index is higher or lower than the desired 
		value then redefine the low and high indexes and run the function again until the 
		index of the value is found or until all necessary numbers are checked.
		*/
			if(numbers[middle] > value){
				return search(numbers, low, (middle-1), value);
			}else{
				return search(numbers, (middle+1), high, value);
			}
		}
	}
	
	return -1;
}

void printArray(int numbers[], int sz){
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void){
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0){
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++){
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0){
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}else{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
