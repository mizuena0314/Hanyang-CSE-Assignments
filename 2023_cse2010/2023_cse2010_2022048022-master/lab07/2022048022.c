#include<stdio.h>
#include<stdlib.h>
#define INF 1e9

FILE *fin;
FILE *fout;

typedef struct HeapStruct{
	int Capacity;
	int Size;
	int *Elements;
}Heap;

Heap* CreateHeap(int heapSize);
void Insert(Heap *heap, int value);
int Find(Heap *heap, int value);
int DeleteMax(Heap* heap);
void PrintHeap(Heap* heap);
int IsFull(Heap *heap);

int main(int argc, char* argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	char cv;
	Heap* maxHeap;
	int heapSize, key, max_element;

	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
		switch(cv){
			case 'n':
				fscanf(fin, "%d", &heapSize);
				maxHeap = CreateHeap(heapSize);
				break;
			case 'i':
				fscanf(fin, "%d", &key);
				if(IsFull(maxHeap)){
					fprintf(fout, "insert error : heap is full\n");
					break;
				}
				if(Find(maxHeap, key)){
					fprintf(fout, "insert error : %d is already in the heap\n", key);
					break;
				}
				Insert(maxHeap, key);
				fprintf(fout, "insert %d\n", key);
				break;
			case 'd':
				max_element = DeleteMax(maxHeap);
				if(max_element != -INF){
					fprintf(fout, "max element : %d deleted\n", max_element);
				}
				else fprintf(fout, "delete error : heap is empty\n");
				break;
			case 'p':
				if(maxHeap->Size==0){
					fprintf(fout, "print error : heap is empty\n");
				break;
				}
				PrintHeap(maxHeap);
				break;
			case 'f':
				fscanf(fin, "%d", &key);
				if(Find(maxHeap, key)) fprintf(fout, "%d is in the heap\n", key);
				else fprintf(fout, "finding error : %d is not in the heap\n", key);
				break;
		}
		//fflush(fout); flush output only for debugging
	}

	return 0;
}

Heap* CreateHeap(int heapSize){
	/* create a new heap */
	Heap* newheap = (Heap*)malloc(sizeof(Heap));
	newheap->Capacity = heapSize;
	newheap->Size = 0;
	newheap->Elements = (int*)malloc(sizeof(int)*(heapSize+1));
	return newheap;
}

void Insert(Heap *heap, int value){
	/* insert a value into the heap */
	heap->Elements[++(heap->Size)]=value;
	int sz = heap->Size;
	for(int idx=sz/2; idx>=1; idx--){ //iterate from mid point to top and max heapify	
		int flg1 = idx*2<=heap->Size && heap->Elements[idx] < heap->Elements[idx*2];
		int flg2 = idx*2+1<=heap->Size && heap->Elements[idx] < heap->Elements[idx*2+1];
		if(flg1 && flg2){
			if(heap->Elements[idx*2] < heap->Elements[idx*2+1]){
				int tmp = heap->Elements[idx*2+1];
				heap->Elements[idx*2+1] = heap->Elements[idx];
				heap->Elements[idx] = tmp;
			}
			else{
				int tmp = heap->Elements[idx*2];
				heap->Elements[idx*2] = heap->Elements[idx];
				heap->Elements[idx] = tmp;
			}
		}
		else if(flg1){
			int tmp = heap->Elements[idx*2];
			heap->Elements[idx*2] = heap->Elements[idx];
			heap->Elements[idx] = tmp;
		}
		else if(flg2){
			int tmp = heap->Elements[idx*2+1];
			heap->Elements[idx*2+1] = heap->Elements[idx];
			heap->Elements[idx] = tmp;
		}
	}
}

int Find(Heap* heap, int value){
	/* find a value in the heap */
	for(int i=1; i<=heap->Size; i++){
		if(heap->Elements[i]==value) return 1;
	}
	return 0;
}

int DeleteMax(Heap* heap){
	/* delete Max value from the heap */
	if(heap->Size == 0) return -INF;

	int ret = heap->Elements[1];

	heap->Elements[1] = heap->Elements[heap->Size];
	heap->Elements[heap->Size] = -INF;
	int idx = 1;
	heap->Size--;

	while(idx<=(heap->Size)/2){ //percolate down
		int flg1 = idx*2<=heap->Size && heap->Elements[idx] < heap->Elements[idx*2];
		int flg2 = idx*2+1<=heap->Size && heap->Elements[idx] < heap->Elements[idx*2+1];
		if(flg1 && flg2){
			if(heap->Elements[idx*2] < heap->Elements[idx*2+1]){
				int tmp = heap->Elements[idx*2+1];
				heap->Elements[idx*2+1] = heap->Elements[idx];
				heap->Elements[idx] = tmp;

				idx = idx*2+1;

			}
			else{
				int tmp = heap->Elements[idx*2];
				heap->Elements[idx*2] = heap->Elements[idx];
				heap->Elements[idx] = tmp;

				idx = idx*2;
			}
		}
		else if(flg1){
			int tmp = heap->Elements[idx*2];
			heap->Elements[idx*2] = heap->Elements[idx];
			heap->Elements[idx] = tmp;

			idx = idx*2;
		}
		else if(flg2){
			int tmp = heap->Elements[idx*2+1];
			heap->Elements[idx*2+1] = heap->Elements[idx];
			heap->Elements[idx] = tmp;

			idx = idx*2+1;
		}
		else break;
	}
	
	return ret;
}

void PrintHeap(Heap* heap){
	/* print the heap */
	for(int i=1; i<=heap->Size; i++) fprintf(fout, "%d ", heap->Elements[i]);
	fprintf(fout, "\n");
}

int IsFull(Heap* heap){ 
	/* check if the heap is full */	
	if(heap->Size == heap->Capacity) return 1;
	else return 0;
}

