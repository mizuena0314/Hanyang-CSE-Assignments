#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 1e9

FILE *fin;
FILE *fout;

typedef struct Node {
	int vertex;
	int dist;	//distance
	int prev;
}Node;

typedef struct Graph {
	int size;
	int** vertices;
	Node* nodes;
}Graph;

typedef struct Heap {
	int Capacity;
	int Size;
	Node* Elements;
}Heap;

Graph* createGraph(int size);
void deleteGraph(Graph* g);
void printShortestPath(Graph* g);
Heap* createMinHeap(int heapSize);
void deleteMinHeap(Heap* minHeap);
void insertToMinHeap(Heap* minHeap, int vertex, int distance);
Node deleteMin(Heap* minHeap);


void main(int argc, char *argv[]) {
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	Graph* g;
	int size;
	fscanf(fin, "%d\n", &size);
	g = createGraph(size);

	char tmp = 0;
	while (tmp != '\n' && tmp != EOF) {
		int node1, node2, weight;
		fscanf(fin, "%d-%d-%d", &node1, &node2, &weight);
		g->vertices[node1][node2] = weight;
		tmp = fgetc(fin);
	}

	printShortestPath(g);

	deleteGraph(g);
}

Graph* createGraph(int size){ //make new graph
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->size = size;
	G->nodes = (Node*)malloc(sizeof(Node)*(size+1));
	for(int i=1; i<=size; i++){
		G->nodes[i].vertex = i;
		G->nodes[i].dist = INF;
		G->nodes[i].prev = i; //initialize settings of the graph
	}
	G->vertices = (int**)malloc(sizeof(int*)*(size+1));
	for(int i=0; i<=size; i++){
		G->vertices[i] = (int*)malloc(sizeof(int)*(size+1));
	}

	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++){
			G->vertices[i][j] = INF;
		}
	}
	return G;
}

void deleteGraph(Graph* g){ //delete the graph (or rather free the graph)
	free(g->nodes);
	for(int i=0; i<=g->size; i++) free(g->vertices[i]);
	free(g->vertices);
	free(g);
}

Heap* createMinHeap(int heapSize){ //create min heap
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->Capacity = heapSize;
	h->Size = 0;
	h->Elements = (Node*)malloc(sizeof(Node)*heapSize);
	return h;
}

void deleteMinHeap(Heap* minHeap){
	free(minHeap->Elements);
	free(minHeap);
}

void insertToMinHeap(Heap* minHeap, int vertex, int distance){
	Node value;
	value.vertex = vertex;
	value.dist = distance;
	minHeap->Elements[++(minHeap->Size)]=value;
	int sz = minHeap->Size;
	for(int idx=sz/2; idx>=1; idx--){ //iterate from mid point to top and max heapify	
		int flg1 = idx*2<=minHeap->Size && minHeap->Elements[idx].dist > minHeap->Elements[idx*2].dist;
		int flg2 = idx*2+1<=minHeap->Size && minHeap->Elements[idx].dist > minHeap->Elements[idx*2+1].dist;
		if(flg1 && flg2){
			if(minHeap->Elements[idx*2].dist > minHeap->Elements[idx*2+1].dist){
				Node tmp = minHeap->Elements[idx*2+1];
				minHeap->Elements[idx*2+1] = minHeap->Elements[idx];
				minHeap->Elements[idx] = tmp;
			}
			else{
				Node tmp = minHeap->Elements[idx*2];
				minHeap->Elements[idx*2] = minHeap->Elements[idx];
				minHeap->Elements[idx] = tmp;
			}
		}
		else if(flg1){
			Node tmp = minHeap->Elements[idx*2];
			minHeap->Elements[idx*2] = minHeap->Elements[idx];
			minHeap->Elements[idx] = tmp;
		}
		else if(flg2){
			Node tmp = minHeap->Elements[idx*2+1];
			minHeap->Elements[idx*2+1] = minHeap->Elements[idx];
			minHeap->Elements[idx] = tmp;
		}
	}

}

Node DeleteMin(Heap* minHeap){
	/* delete Max value from the heap */
	Node ret = minHeap->Elements[1];

	minHeap->Elements[1] = minHeap->Elements[minHeap->Size];
	Node tmpblank;
	tmpblank.dist = INF;
	minHeap->Elements[minHeap->Size] = tmpblank;
	int idx = 1;
	minHeap->Size--;

	while(idx<=(minHeap->Size)/2){ //percolate down
		int flg1 = idx*2<=minHeap->Size && minHeap->Elements[idx].dist > minHeap->Elements[idx*2].dist;
		int flg2 = idx*2+1<=minHeap->Size && minHeap->Elements[idx].dist > minHeap->Elements[idx*2+1].dist;
		if(flg1 && flg2){
			if(minHeap->Elements[idx*2].dist > minHeap->Elements[idx*2+1].dist){
				Node tmp = minHeap->Elements[idx*2+1];
				minHeap->Elements[idx*2+1] = minHeap->Elements[idx];
				minHeap->Elements[idx] = tmp;

				idx = idx*2+1;

			}
			else{
				Node tmp = minHeap->Elements[idx*2];
				minHeap->Elements[idx*2] = minHeap->Elements[idx];
				minHeap->Elements[idx] = tmp;

				idx = idx*2;
			}
		}
		else if(flg1){
			Node tmp = minHeap->Elements[idx*2];
			minHeap->Elements[idx*2] = minHeap->Elements[idx];
			minHeap->Elements[idx] = tmp;

			idx = idx*2;
		}
		else if(flg2){
			Node tmp = minHeap->Elements[idx*2+1];
			minHeap->Elements[idx*2+1] = minHeap->Elements[idx];
			minHeap->Elements[idx] = tmp;

			idx = idx*2+1;
		}
		else break;
	}

	return ret;
}



void printShortestPath(Graph* g){
	int d[g->size+1];

	for(int i=1; i<=g->size; i++){
		d[i] = INF;
	}

	Heap* mh = createMinHeap((g->size+1)*(g->size+1));
	d[1] = 0;
	g->nodes[1].dist = 0;

	insertToMinHeap(mh, 1, 0);
	/*
	fprintf(fout, "I have done the insert\n");
	fflush(fout);
	*/
	while(mh->Size!=0){ //while heap is not empty
		/*
		fprintf(fout, "I am doing the dijk\n");
		fflush(fout);
		*/ 
		//do the dijk
		Node cur = DeleteMin(mh);
		int u = cur.vertex;
		int ud = cur.dist;

		if(g->nodes[u].dist < ud) continue;

		for(int v=1; v<=g->size; v++){
			if(g->vertices[u][v]==INF) continue;
			int vdist = ud + g->vertices[u][v];
			if(vdist < g->nodes[v].dist){
				g->nodes[v].prev = u;
				g->nodes[v].dist = vdist;
				insertToMinHeap(mh, v, vdist);
				/*
				fprintf(fout, "I have inserted the v\n");
				fflush(fout);
				*/
			}
		}
	}

	/*
	fprintf(fout, "I have finished the dijk\n");
	fflush(fout);
	*/

	for(int target=2; target<=g->size; target++){
		//
		//fflush(fout);
		//
		int path[g->size+1];
		int pathlen = 0;
		if(g->nodes[target].dist == INF){
			fprintf(fout, "can not reach to node %d\n", target);
			continue;
		} //backtrack to vertex 1 to print path
		Node cur = g->nodes[target];

		while(1){
			path[++pathlen] = cur.vertex;
			if(cur.vertex == 1) break;
			cur = g->nodes[cur.prev];
		}

		for(int i=pathlen; i>=2; i--){
			fprintf(fout, "%d->", path[i]);
		}
		fprintf(fout, "%d (cost : %d)\n", path[1], g->nodes[target].dist);
	}
}
