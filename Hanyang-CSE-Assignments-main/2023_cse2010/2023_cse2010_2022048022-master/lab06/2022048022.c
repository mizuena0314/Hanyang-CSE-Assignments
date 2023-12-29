#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef int ElementType;

typedef struct AVLNode{
	ElementType element;
	AVLTree left, right;
	int height;
}AVLNode;

int max(int a, int b);
int Height(Position node);

AVLTree Insert(ElementType X, AVLTree T);
AVLTree Delete(ElementType X, AVLTree T);
Position SingleRotateWithLeft(Position node);
Position SingleRotateWithRight(Position node);
Position DoubleRotateWithLeft(Position node);
Position DoubleRotateWithRight(Position node);
void PrintInorder(AVLTree T);
void DeleteTree(AVLTree T);

int main(int argc, char *argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	AVLTree Tree = NULL;
	char cv;
	int key;

	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
		switch(cv){
			case 'i':
				fscanf(fin, "%d\n", &key);
				Tree = Insert(key, Tree);
				break;
			case 'd':
				fscanf(fin, "%d\n", &key);
				Tree = Delete(key, Tree);
				break;
		}
		PrintInorder(Tree);
		fprintf(fout, "\n");
		//fflush(fout); <- for debugging
	}

	DeleteTree(Tree);
	fclose(fin);
	fclose(fout);

	return 0;
}

int max(int a, int b){
	return (a>b)?a:b;
} //function to return max of two values

int Height(Position node){
	if(node==NULL) return -1;
	else return node->height;
} //returns height if not null node, if null returns -1


AVLTree Insert(ElementType X, AVLTree T){
	if(T == NULL){ //creates a new node at the position
		AVLTree newnode = (AVLTree)malloc(sizeof(AVLNode));
		newnode->element = X;
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->height = 0;
		return newnode;
	}

	if(X < T->element){ //recursive call of function
		T->left = Insert(X, T->left);
	}
	else if(X > T->element){
		T->right = Insert(X, T->right);
	}
	else{
		fprintf(fout, "insertion error : %d is already in the tree!\n", X);
		return T; //return as is if insertion error
	}

	T->height = max(Height(T->left), Height(T->right)) + 1;

	int diff = Height(T->left) - Height(T->right);

	if(diff > 1){
		if(X < T->left->element){ // LL
			return SingleRotateWithLeft(T);
		}
		else{ // LR
			return DoubleRotateWithLeft(T);
		}
	}
	if(diff < -1){
		if(X > T->right->element){ // RR
			return SingleRotateWithRight(T);
		}
		else{ // RL
			return DoubleRotateWithRight(T);
		}
	}

	return T;
}

AVLTree Delete(ElementType X, AVLTree T){
	if(T == NULL){
		fprintf(fout, "deletion error : %d is not in the tree!\n", X); 
		return T;
	}
	if(X < T->element){
		if(T->left!=NULL) T->left = Delete(X, T->left);
		else{
			fprintf(fout, "deletion error : %d is not in the tree!\n", X);
			return T;
		}
	}
	else if(X > T->element){
		if(T->right!=NULL) T->right = Delete(X, T->right);
		else{
			fprintf(fout, "deletion error : %d is not in the tree!\n", X);
			return T;
		}
	} //return as is in case of deletion error
	else{
		if(T->left!=NULL && T->right!=NULL){ // two child
			Position tmp = T->right;
			while(tmp->left != NULL) tmp = tmp->left;

			T->element = tmp->element;
			T->right = Delete(tmp->element, T->right);
		}
		else if(!(T->left) || !(T->right)){
                        Position tmp = T->left ? T->left : T->right;
                        if(!tmp){ // no  child
                                tmp = T;
                                T = NULL;
                        }
                        else{ // one child
                                if(tmp!=NULL) *T = *tmp;
                        }
                        if(tmp!=NULL) free(tmp);
                }
	}

	if(T==NULL) return T;

	T->height = max(Height(T->left), Height(T->right)) + 1;

	int diff = Height(T->left) - Height(T->right);

	 if(diff > 1){
                if(X < T->left->element){ // LL
                        return SingleRotateWithLeft(T);
                }
                else{ // LR
                        return DoubleRotateWithLeft(T);
                }
        }
        if(diff < -1){
                if(X > T->right->element){ // RR
                        return SingleRotateWithRight(T);
                }
                else{ // RL
                        return DoubleRotateWithRight(T);
                }
        }

        return T;	
}

Position SingleRotateWithLeft(Position node){
	Position L = node->left;
	Position LR = L->right;

	L->right = node;
	node->left = LR;

	node->height = max(Height(node->left), Height(node->right))+1;
	L->height = max(Height(L->left), Height(L->right))+1;

	return L;
}

Position SingleRotateWithRight(Position node){
	Position R = node->right;
	Position RL = R->left;

	R->left = node;
	node->right = RL;

	node->height = max(Height(node->left), Height(node->right)) + 1;
	R->height = max(Height(R->left), Height(R->right)) + 1;

	return R;
}

Position DoubleRotateWithLeft(Position node){
	node->left = SingleRotateWithRight(node->left);
	return SingleRotateWithLeft(node);
}

Position DoubleRotateWithRight(Position node){
	node->right = SingleRotateWithLeft(node->right);
	return SingleRotateWithRight(node);
}

void PrintInorder(AVLTree T){
	if(T==NULL) return;
	PrintInorder(T->left);
	fprintf(fout, "%d(%d) ", T->element, T->height);
	PrintInorder(T->right);
}

void DeleteTree(AVLTree T){
	if(T==NULL) return;
	DeleteTree(T->left);
	DeleteTree(T->right);
	free(T);
}
