#include<stdio.h>
#include<stdlib.h>
#include<time.h>

FILE *fin;
FILE *fout;

typedef struct _DisjointSet {
    int size_maze;
    int *ptr_arr;
}DisjointSets;

void init(DisjointSets *sets, DisjointSets *maze_print, int num);
void Union(DisjointSets *sets, int i, int j);
int find(DisjointSets *sets, int i);
void createMaze(DisjointSets *sets, DisjointSets *maze_print, int num);
void printMaze(DisjointSets *sets, int num);
void freeMaze(DisjointSets *sets, DisjointSets *maze_print);

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main(int argc, char* agrv[]) {
    srand((unsigned int)time(NULL));

    int num, i;
    fin = fopen(agrv[1], "r");
    fout = fopen(agrv[2], "w");

    DisjointSets *sets, *maze_print;
    fscanf(fin, "%d", &num);

    sets = (DisjointSets*)malloc(sizeof(DisjointSets));
    maze_print = (DisjointSets*)malloc(sizeof(DisjointSets));

    init(sets, maze_print, num);
    createMaze(sets, maze_print, num);
    printMaze(maze_print, num);

    freeMaze(sets, maze_print);

    fclose(fin);
    fclose(fout);

    return 0;
}

void init(DisjointSets *sets, DisjointSets *maze_print, int num) {
	int i;

	sets->size_maze = num * num;
	sets->ptr_arr = (int*)malloc(sizeof(int) * (sets->size_maze + 1));
	for (i = 1; i <= sets->size_maze; i++) sets->ptr_arr[i] = i;

	maze_print->size_maze = num * num * 2;
	maze_print->ptr_arr = (int*)malloc(sizeof(int) * (maze_print->size_maze + 1));
	for (i = 1; i <= maze_print->size_maze; i++) maze_print->ptr_arr[i] = 1;
	//maze_print->ptr_arr[(x-1)*2+1 ~ x*2] : two directions(right, down) walls of the number x

	//start and end position have not to have the wall
	maze_print->ptr_arr[maze_print->size_maze - 1] = 0;
}

void Union(DisjointSets *sets, int i, int j){
	int root1 = find(sets, i);
	int root2 = find(sets, j);

	if(root1 != root2) sets->ptr_arr[root1] = root2; //union
}

int find(DisjointSets *sets, int i){
	if(sets->ptr_arr[i] == i) return i;
	else return sets->ptr_arr[i] = find(sets, sets->ptr_arr[i]); //path compression
}

void createMaze(DisjointSets *sets, DisjointSets *maze_print, int num){
	while(find(sets, 1) != find(sets, num*num)){

		int cur = rand() % (num*num) + 1;

		//fprintf(fout, "%d\n", cur);
		//fflush(fout);
		//right
		if(cur%num!=0){
			if(find(sets, cur) != find(sets, cur+1)){
				Union(sets, cur, cur+1);
				maze_print->ptr_arr[2*cur-1] = 0;
			}
		}
		//down
		if(cur+num <= num*num){
			if(find(sets, cur) != find(sets, cur+num)){
				Union(sets, cur, cur+num);
				maze_print->ptr_arr[2*cur] = 0;
			}
		}
	}
}

void printMaze(DisjointSets *sets, int num){
	fprintf(fout, "+");
	for(int i=1; i<=num; i++) fprintf(fout, "---+");
	fprintf(fout, "\n");

	for(int i=1; i<=num; i++){
		//check right
		for(int j=1; j<=num; j++){
			if(j==1 && i!=1) fprintf(fout, "|");
			else if(j==1 && i==1) fprintf(fout, " ");
			int cur = (i-1)*num+j;
			fprintf(fout, "   ");
			if(sets->ptr_arr[2*cur-1]){
				fprintf(fout, "|");
			}
			else fprintf(fout, " ");
		}
		fprintf(fout, "\n");
		//check down
		for(int j=1; j<=num; j++){
			int cur = (i-1)*num+j;
			fprintf(fout, "+");
			if(sets->ptr_arr[2*cur]){
				fprintf(fout, "---");
			}
			else fprintf(fout, "   ");
		}
		fprintf(fout, "+\n");
	}
}

void freeMaze(DisjointSets* sets, DisjointSets *maze_print){
	free(sets->ptr_arr);
	free(maze_print->ptr_arr);
	free(sets);
	free(maze_print);
}
