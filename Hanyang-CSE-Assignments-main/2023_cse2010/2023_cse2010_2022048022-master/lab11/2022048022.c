#include<stdio.h>
#include<stdlib.h>

FILE* fin;
FILE* fout;

typedef struct Array Array;

struct Array{
    int size;
    int* values;
};

Array* CreateArray(int size);
void QuickSort(Array* array, int left, int right, int depth);
int Partition(Array* array, int left, int right, int depth);
void PrintArray(Array* array, int left, int right);
void DeleteArray(Array* array);
void swap(int* a, int* b); //unimplemented swap function (could have been used for easy swap)

int main(int argc, char *argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

    int size, i;
    Array* array;

    fscanf(fin, "%d", &size);
    array = CreateArray(size);
    for(i = 0; i < size; i++){
        fscanf(fin, "%d", &array->values[i]);
    }

    QuickSort(array, 0, size - 1, 0);

    fprintf(fout, "\nsorting result :\n");
    PrintArray(array, 0, size - 1);

    DeleteArray(array);


	return 0;
}

Array* CreateArray(int size){
	Array* newArray = (Array*)malloc(sizeof(Array)); //creates a new array (pointer)
	newArray->size = size;
	newArray->values = (int*)malloc(sizeof(int)*size);
	return newArray;
}

void QuickSort(Array* array, int left, int right, int depth){
	if(left < right){
		int q = Partition(array, left, right, depth);
		QuickSort(array, left, q-1, depth+1); //sort left part
		QuickSort(array, q+1, right, depth+1); //sort right part
	}
}

int Partition(Array* array, int left, int right, int depth){
	int x = array->values[right]; // x (value of pivot)
	fprintf(fout, "left : %d, right : %d, pivot : %d\n", left, right, x);
	PrintArray(array, left, right);

	int i = left, j = right; // i is left pointer (j is right pointer)

	while(1){ //while statement (it is manually exited with break)
		if(array->values[i] <= x){
			i++;
		}
		if(array->values[j] >= x){
			j--;
		}
		if(i>j) break; // (the break (i passed j)
		if(array->values[i] > x && array->values[j] < x){
			int tmp = array->values[j];
			array->values[j] = array->values[i];
			array->values[i] = tmp;
			PrintArray(array, left, right);
		}

	}
	int tmp = array->values[i];
	array->values[i] = array->values[right];
	array->values[right] = tmp;
	if(i!=right) PrintArray(array, left, right);
	return i;
}

void PrintArray(Array* array, int left, int right){
	for(int i=0; i<array->size; i++){
		if(i>=left && i<=right){
			fprintf(fout, "%-3d", array->values[i]);
		} //within left and right
		else{
			fprintf(fout, "%-3s", "-");
		} //not within left and right (represent with - )
	}
	fprintf(fout, "\n");
}

void DeleteArray(Array* array){
	free(array->values);
	free(array);
}
