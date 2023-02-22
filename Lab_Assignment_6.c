#include <stdio.h>

int search(int numbers[], int low, int high, int value){
	int middle;
	if(low <= high){
	//checks to see if there is at least one index to check between low and high (inclusive)
		middle = (low + high)/2;
		if(numbers[middle] == value){
		//if the value of middle index is the desired value return that index
			return middle;
		}else{
		//otherwise reduce the bounds(low and high) and run the function again
			if(numbers[middle] > value){
				return search(numbers, low, (middle-1), value);
			}else{
				return search(numbers, (middle+1), high, value);
			}
		}
	}
	//returns -1 if the function never finds the desired value
	return -1;
}

void printArray(int numbers[], int sz){
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i){
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
