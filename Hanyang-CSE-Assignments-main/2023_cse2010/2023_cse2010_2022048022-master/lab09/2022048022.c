#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fin;
FILE *fout;

typedef struct _Queue {
	int* key;
	int first, rear, qsize, max_queue_size;
}Queue;

typedef struct _Graph {
	int size;
	int* node;
	int** matrix;
}Graph;

Graph* CreateGraph(int* nodes, int n);
void InsertEdge(Graph* G, int a, int b);
void PrintGraph(Graph* G);
void DeleteGraph(Graph* G);
void Topsort(Graph* G);
Queue* MakeNewQueue(int X);
int IsEmpty(Queue* Q);
int Dequeue(Queue* Q);
void Enqueue(Queue* Q, int X);
void DeleteQueue(Queue* Q);
void countInput(int* n, char* str);
void parseInput(int* arr, char* str, int n);
void checkIndegree(Graph* G, int* idg);
void sort_node(int* arr, int n);

int main(int argc, char* agrv[]) {
	fin = fopen(agrv[1], "r");
	fout = fopen(agrv[2], "w");

	char numbers[100], inputs[150];
	fgets(numbers, 100, fin);
	int n = 0;
	countInput(&n, numbers);
	int* nodes = (int*)malloc(sizeof(int)*n);
	parseInput(nodes, numbers, n);

	Graph* G = CreateGraph(nodes, n);

	fgets(inputs, 100, fin);
	int len = strlen(inputs), i, j;
	for (i = 0; i < len; i += 4) {
		int a = inputs[i] - '0', b = inputs[i + 2] - '0';
		InsertEdge(G, a, b);
	}
	//
	//

	PrintGraph(G);
	/* debugging code
	//fprintf(fout, "check");
	//fflush
	*/
	Topsort(G);
	DeleteGraph(G);

	fclose(fin);
	fclose(fout);

	return 0;
}

void countInput(int* n, char* str) {
	int len = strlen(str), i;
	for (i = 0; i < len; i++)
		if (0 <= str[i] - '0' && str[i] - '0' < 10) (*n)++;
}

void parseInput(int* arr, char* str, int n) {
	int len = strlen(str), i;
	int cnt = 0;
	for (i = 0; i < len; i++)
	if (0 <= str[i] - '0' && str[i] - '0' < 10) arr[cnt++] = str[i] - '0';
}

Graph* CreateGraph(int* nodes, int n){
	Graph* newGraph = (Graph*)malloc(sizeof(Graph));
	newGraph->size = n;
	newGraph->node = (int*)malloc(sizeof(int)*n);
	newGraph->matrix = (int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++) newGraph->matrix[i] = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			newGraph->matrix[i][j] = 0;
		}
	}

	for(int i=0; i<n; i++) newGraph->node[i] = nodes[i];

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(newGraph->node[i]>newGraph->node[j]){
				newGraph->node[i] ^= newGraph->node[j];
			        newGraph->node[j] ^= newGraph->node[i];
				newGraph->node[i] ^= newGraph->node[j];
			}
		}
	}	
	return newGraph;
}

void InsertEdge(Graph* G, int a, int b){
	int u, v;
	for(int i=0; i<G->size; i++){
		if(G->node[i]==a) u = i;
		if(G->node[i]==b) v = i;
	}
	G->matrix[u][v] = 1;
}

void PrintGraph(Graph* G){
	fprintf(fout, "   ");
	for(int i=0; i<G->size; i++) fprintf(fout, "%d  ", G->node[i]);
	fprintf(fout, "\n");
	for(int i=0; i<G->size; i++){
		fprintf(fout, "%d  ", G->node[i]);
		for(int j=0; j<G->size; j++){
			fprintf(fout, "%d  ", G->matrix[i][j]);
		}
		fprintf(fout, "\n");
	}
}

void DeleteGraph(Graph* G){
	for(int i=0; i<G->size; i++) free(G->matrix[i]);
	free(G->matrix);
	free(G->node);
	G->size = NULL;
	free(G);
}

void Topsort(Graph* G){
	Queue* Q = MakeNewQueue(G->size);
	int* inD = (int*)malloc(sizeof(int)*G->size); //to store the initial in-degree of each node separately
	int* res = (int*)malloc(sizeof(int)*G->size); //to store the result of topological sort in case the graph is cyclic
	for(int i=0; i<G->size; i++){ //calculating initial indegree
		int inDegree = 0;
		for(int j=0; j<G->size; j++){
			if(G->matrix[j][i]) inDegree++;
		}
		inD[i] = inDegree;
		if(!inDegree) Enqueue(Q, i); //if indegree is 0 push to queue
	}
	for(int i=0; i<G->size; i++){
		int cur = Dequeue(Q);
		res[i] = cur;
		for(int j=0; j<G->size; j++){
			if(G->matrix[cur][j]){
				inD[j]--;
				if(inD[j]==0) Enqueue(Q, j); //if indegree is 0 push to queue
				G->matrix[cur][j] = 0;
			}
		}
	
	}
	fprintf(fout, "\n");
	if(IsEmpty(Q)==0){
		fprintf(fout, "sorting error : cycle!"); //in case of cyclicgraph
	}
	else{
		for(int i=0; i<G->size; i++){
			fprintf(fout, "%d ", G->node[res[i]]); //print result
		}
	}
}

Queue* MakeNewQueue(int X){
	Queue* newQ = (Queue*)malloc(sizeof(Queue));
	newQ->key = (int*)malloc(sizeof(int)*X);
	newQ->max_queue_size = X;
	newQ->first = 0;
	newQ->rear = 0;
	newQ->qsize = 0;
	return newQ;
}

int IsEmpty(Queue* Q){
	if(Q->qsize==0) return 1;
	else return 0;
}

int Dequeue(Queue* Q){
	int toPop = Q->key[Q->first];
	Q->first++;
	Q->qsize--;
	return toPop;
}

void Enqueue(Queue* Q, int X){
	if(Q->qsize == Q->max_queue_size){
		fprintf(fout, "Enqueue error : queue is full!\n");
		return;
	}
	Q->key[Q->rear] = X;
	Q->rear++;
	Q->qsize++;
}

void DeleteQueue(Queue* Q){
	free(Q->key);
	free(Q);
}
