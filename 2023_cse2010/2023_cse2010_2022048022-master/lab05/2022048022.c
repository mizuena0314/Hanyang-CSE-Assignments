#include <stdio.h>
#include <stdlib.h>

FILE *fin;
FILE *fout;

typedef struct BST* Tree;
typedef struct BST{
	int value;
	struct BST* left;
	struct BST* right;
}BST;

Tree insertNode(Tree root, int key);
Tree deleteNode(Tree root, int key);
int findNode(Tree root, int key);
void printInorder(Tree root);
void deleteTree(Tree root);

void main(int argc, char* argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	char cv;
	int key;

	Tree root = NULL;

	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
		if(feof(fin))
			break;
		switch(cv){
			case 'i':
				fscanf(fin, "%d", &key);
				if(findNode(root, key))
					fprintf(fout, "insertion error: %d is already in the tree\n", key);
				else{	
					fprintf(fout, "insert %d\n", key);
					root = insertNode(root, key);
				}
				break;
			case 'f':
				fscanf(fin, "%d", &key);
				if(findNode(root, key))
					fprintf(fout, "%d is in the tree\n", key);
				else
					fprintf(fout, "finding error: %d is not in the tree\n", key);
				break;
			case 'd':
				fscanf(fin, "%d", &key);
				if(findNode(root, key)){
					root = deleteNode(root, key);
					fprintf(fout, "delete %d\n", key);
				}
				else{
					fprintf(fout, "deletion error: %d is not in the tree\n", key);
				}
				break;
			case 'p':
				fscanf(fin, "%c", &cv);
				if(cv == 'i'){
					if(root == NULL)
						fprintf(fout, "tree is empty");
					else
						printInorder(root);
					fprintf(fout, "\n");
					break;
				}
		}
		//fflush(fout);
	}
	deleteTree(root);

}

Tree insertNode(Tree root, int key){
	Tree node = (Tree)malloc(sizeof(BST));
	node->value = key;
	node->left = NULL;
	node->right = NULL;
	if(root == NULL){
		root = node;
		return root;
	}
	Tree ptr = root;
	while(1){
		if(key<ptr->value){
			if(ptr->left != NULL){
				ptr = ptr->left;
			}
			else{
				ptr->left = node;
				break;
			}
		}
		else{
			if(ptr->right != NULL){
				ptr = ptr->right;
			}
			else{
				ptr->right = node;
				break;
			}
		}
	}
	//printf("the i\n");
	return root;
}

int findNode(Tree root, int key){
	Tree ptr = root;
	//printf("The Find\n");
	while(ptr != NULL){
		if(ptr->value == key) return 1;
		if(key<ptr->value){
			ptr = ptr->left;
		}
		else ptr = ptr->right;
	}
	return 0;
}

Tree deleteNode(Tree root, int key){
	//printf("the Delete\n");
	Tree ptr = root, bef = NULL;
	int dir = 0;
	while (ptr != NULL){
		if (ptr->value == key) break;
		bef = ptr;
		if (key < ptr->value){
			ptr = ptr->left;
			dir = -1;
		}
		else{
		       ptr = ptr->right;
		       dir = 1;
		}
	}
	//find node to delete

	if(ptr->left == NULL && ptr->right == NULL){
		if(bef != NULL){
			if(dir==1) bef->right = NULL;
			else bef->left = NULL;
		}
		int isRoot = 0;
		if(ptr==root) isRoot=1;
		free(ptr);
		if(isRoot) return NULL;
		else return root;
	}	
	//delete leaf node
	if(ptr == root && ptr!=NULL){
		if(root->right){ //right subtree exists
			Tree ptr2 = root->right, bef2 = NULL;
			while(ptr2->left){
				bef2 = ptr2;
				ptr2 = ptr2->left;
			}
			if(ptr2->right && bef2!=NULL){
				bef2->left = ptr2->right;
				ptr2->right = NULL;
			}else if(bef2!=NULL){
				bef2->left = NULL;
			}
			Tree RL = root->left;
			Tree RR = root->right;
			if(RL != ptr2) ptr2->left = root->left;
			if(RR != ptr2) ptr2->right = root->right;
			free(root);
			root = ptr2;
		}
		else if(root->left){ //right subtree doesn't exist
			Tree RL = root->left;
			free(root);
			root = RL;
		}
		else free(root);
	}//deleting root
	else{
		if(ptr->right){
			Tree ptr2 = ptr->right, bef2 = NULL;
			while(ptr2->left){
				bef2 = ptr2;
				ptr2 = ptr2->left;
			}
			if(ptr2->right && bef2 != NULL){
				bef2->left = ptr2->right;
				ptr2->right = NULL;
			}
			else if(bef2!=NULL) bef2->left = NULL;
			Tree RL = ptr->left;
			Tree RR = ptr->right;
			if(dir==1){
				bef->right = ptr2;
				
				if(RL!=ptr2) ptr2->left = RL;
				if(RR!=ptr2) ptr2->right = RR;
				free(ptr);
			}
			else if(dir==-1){
				bef->left = ptr2;

				if(RL!=ptr2) ptr2->left = RL;
				if(RR != ptr2) ptr2->right = RR;
				free(ptr);
			}
		}
		else{
			Tree RL = ptr->left;
			free(ptr);
			ptr = RL;
			if(dir==1){
				bef->right = ptr;
			}
			else bef->left = ptr;
		}
		
	}//same for when deleting a non root node
	return root;
}

void printInorder(Tree root){ //recursive function to print the inorder traversal of the tree
	if(root==NULL) return;
	printInorder(root->left);
	fprintf(fout, "%d ", root->value);
	printInorder(root->right);
	//printf("the p\n");
}

void deleteTree(Tree root){ //recursive function to delete the tree
	if(root==NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
	//printf("the dT\n");
}
