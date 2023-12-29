#include <stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

#define FROMPARENT 0
#define FROMTHREAD 1

typedef struct ThreadedTree* ThreadedPtr;
typedef int ElementType;

struct ThreadedTree {
	int left_thread; // flag if ptr is thread
	ThreadedPtr left_child;
	ElementType data;
	ThreadedPtr right_child;
	int right_thread; // flag if ptr is thread
}ThreadedTree;

ThreadedPtr CreateTree(){
	ThreadedPtr tree = NULL;
	tree = (ThreadedPtr)malloc(sizeof(ThreadedTree));
	if(tree==NULL){
		fprintf(fout, "Out of Space!\n");
		return NULL;
	}
	tree->data = -1;
	tree->left_thread = 1;
	tree->left_child = tree;
	tree->right_thread = 1;
	tree->right_child = tree;
	return tree;
}

int Insert(ThreadedPtr root, int root_idx, ElementType data, int idx){
	ThreadedPtr tmp = CreateTree();
	
	if(tmp==NULL) return 0;

	tmp->left_child = root;
	tmp->right_child = root;
	tmp->data = data;

	int mov[8];
	int i = 0;

	int toBin = idx;

	while(toBin!=0){ //binary representation for left/right decision
		mov[i] = toBin % 2;
		toBin /= 2;
		i++;
		//printf("flag1\n");
	}

	ThreadedPtr ptr = root;

	for(int k=i-1; k>=1; k--){
		if(mov[k]==0){//left if 0 right if 1
			tmp->right_child = ptr;
			ptr = ptr->left_child;
		}
		else{
			tmp->left_child = ptr;
			ptr = ptr->right_child;
		}
	}

	if(mov[0]==0){
		ptr->left_child = tmp;
		ptr->left_thread = 0;
		tmp->right_child = ptr;
	}
	else{
		ptr->right_child = tmp;
		ptr->right_thread = 0;
		tmp->left_child = ptr;
	}
	return 1;
}

void printInorder(ThreadedPtr root){ //inorder using thread successors
	ThreadedPtr ptr = root->right_child;

	while(ptr->left_thread==0) ptr = ptr->left_child;
	//printf("%d\n", (ptr->right_child)->data);
	fprintf(fout, "inorder traversal : ");
	while(ptr!=root){
		//printf("%d \n", ptr->data);
		fprintf(fout, "%d ", ptr->data);
		if(ptr->right_thread==1) ptr = ptr->right_child;
		else{
			ptr = ptr->right_child;
			while(ptr->left_thread==0) ptr = ptr->left_child;
		}
	}
}

void DeleteTree(ThreadedPtr root){
	ThreadedPtr ptr = root->right_child;
	ThreadedPtr ptr2del;

	while(ptr->left_thread==0) ptr = ptr->left_child;

	while(ptr!=root){
		//printf("flag3");
		ptr2del = ptr;
		if(ptr->right_thread==1) ptr = ptr->right_child;
		else{
			ptr = ptr->right_child;
			while(ptr->left_thread==0) ptr = ptr->left_child;
		}
		free(ptr2del);
	}

	free(root);
}

int main(int argc, char *argv[]){
	fin=fopen(argv[1], "r");
	fout=fopen(argv[2], "w");

	ThreadedPtr root = CreateTree();

	int NUM_NODES;
	fscanf(fin, "%d", &NUM_NODES);

	int root_idx=0, idx=0;

	while(++idx <= NUM_NODES){
		ElementType data;
		fscanf(fin, "%d", &data);
		
		if(Insert(root, root_idx, data, idx) == 0){
			return 0;
		}
	}

	printInorder(root);
	DeleteTree(root);
	
	
	fclose(fin);
	fclose(fout);

	return 0;
}

