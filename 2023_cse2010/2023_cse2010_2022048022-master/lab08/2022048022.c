#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

typedef struct BNode* BNodePtr;

struct BNode{
    int order;
    int size;           /* number of children */
    BNodePtr *child;    /* children pointers */
    int *key;           /* keys */
    int is_leaf;
}BNode;

BNodePtr CreateTree(int order);

void Insert(BNodePtr *root, int key);
BNodePtr Insert_sub(BNodePtr parent, BNodePtr node, int key, int pos);
BNodePtr split_node(BNodePtr parent, BNodePtr node, int pos);
BNodePtr Createnode(int order);

int Find(BNodePtr root, int key);

void PrintTree(BNodePtr root);

void DeleteTree(BNodePtr root);
void free_node(BNodePtr node);



int main(int argc, char* argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    int order;
    fscanf(fin, "%d", &order);
    BNodePtr root = CreateTree(order);

    char cv;
    int key;
    while(!feof(fin)){
        fscanf(fin, "%c", &cv);
        switch(cv){
            case 'i':
                fscanf(fin, "%d", &key);
                if(Find(root, key))
                    fprintf(fout, "insert error : key %d is already in the tree!\n", key);
                else{
                    Insert(&root, key);
		}
                break;
            case 'f':
                fscanf(fin, "%d", &key);
                if(Find(root, key))
                    fprintf(fout, "key %d found\n", key);
                else{
                    fprintf(fout, "finding error : key %d is not in the tree!\n", key);
		}
		break;
            case 'p':
                if (root->size == 1)
                    fprintf(fout, "print error : tree is empty!");
                else
                    PrintTree(root);
                fprintf(fout, "\n");
                break;
        }
	//
	fflush(fout);
	//
    }
   
    DeleteTree(root);
    fclose(fin);
    fclose(fout);

    return 0;
}

/* 새로운 트리를 생성하는 함수 */
BNodePtr CreateTree(int order){
	BNodePtr newnode = (BNodePtr)malloc(sizeof(BNode));
	newnode->order = order;
	newnode->is_leaf = 1;
	newnode->child = (BNodePtr*)malloc(sizeof(BNodePtr)*(order+1));
	newnode->size = 1;
	newnode->key = (int*)malloc(sizeof(int)*(order));
	return newnode;
}

/* insert key */
void Insert(BNodePtr *root, int key){ // 루트를 함수 내에서 변경시키기 위해 이중 포인터로 선언
    *root = Insert_sub(*root, *root, key, 0); // 리턴값이 있는 재귀함수 활용, 처음에 root 노드는 현재 노드이자 parent이므로 같이 parent, node 똑같이 매개변수 전달
}

BNodePtr Insert_sub(BNodePtr parent, BNodePtr node, int key, int p_pos){
	int tmp = 0;
	while(tmp < node->size-1){
	       if(node->key[tmp] < key)	tmp++;
	       else break;
	}

	if(!node->is_leaf){
		Insert_sub(node, node->child[tmp], key, tmp);
		if(node->size == node->order+1){
			return split_node(parent, node, p_pos);
		}
		else return node;
	}
	else{
		for(int i=node->size-2; i>=tmp; i--){
			node->key[i+1] = node->key[i];
		}
		node->key[tmp] = key;
		node->size+=1;
		if(node->size==node->order+1){
			return split_node(parent, node, p_pos);
		}
		else return node;
	}
}

BNodePtr split_node(BNodePtr parent, BNodePtr node, int pos){
	int mid = (node->order-1)/2;

	BNodePtr s_node;

	s_node = Createnode(node->order);
	s_node->is_leaf = node->is_leaf;
		
	for(int i=mid+1; i<node->order; i++){
		s_node->key[i-mid-1] = node->key[i];
		s_node->child[i-mid-1] = node->child[i];
	}

	s_node->child[node->order-mid-1] = node->child[node->order];
	if(parent!=node){
		for(int i=parent->order; i>pos; i--){
			parent->key[i] = parent->key[i-1];
			parent->child[i+1] = parent->child[i];
		}
	
		parent->child[pos+1] = parent->child[pos];
		parent->key[pos] = node->key[mid];
		node->size = mid+1;
		s_node->size = node->order-mid;
		parent->size++;
		parent->child[pos+1] = s_node;
		return node;
	}
	else{
		BNodePtr newroot = Createnode(node->order);
		newroot->size = 2;
		newroot->is_leaf = 0;
		
		node->size = mid+1;
		s_node->size = node->order-mid;
		newroot->key[0] = node->key[mid];
		newroot->child[0] = node;
		newroot->child[1] = s_node;
		return newroot;
	}
}

/* 노드 하나를 동적할당하는 함수, size, is_leaf는 노드마다 다르므로 초기화하지 않고 공통되는 부분만 초기화 */
BNodePtr Createnode(int order){
	BNodePtr newnode = (BNodePtr)malloc(sizeof(BNode));
  	newnode->order = order;
	newnode->child = (BNodePtr*)malloc(sizeof(BNodePtr)*(order+1));
	newnode->key = (int*)malloc(sizeof(int)*(order));

	return newnode;
}

/* find node that has key */
int Find(BNodePtr root, int key){
	if(root == NULL) return 0;
	for(int i=0; i<root->size-1; i++){
		if(key<root->key[i]){
			return Find(root->child[i], key);
		}
		else if(key == root->key[i]) return 1;
	}	
	return Find(root->child[root->size-1], key);
}

/* print Tree, inorder traversal */
void PrintTree(BNodePtr root){
	if(root == NULL) return;
	for(int i=0; i<root->size-1; i++){
		PrintTree(root->child[i]);
		fprintf(fout, "%d ", root->key[i]);
	}
	PrintTree(root->child[root->size-1]);
}

/* depth first search -> free memory */
void DeleteTree(BNodePtr root){
	if(root == NULL) return;
	if(!root->is_leaf){
		for(int i=0; i<root->size; i++){
			if(root->child[i]) DeleteTree(root->child[i]);
		}
	}
	free_node(root);
}

/* 노드의 메모리를 해제해주는 helper function */
void free_node(BNodePtr node){
    free(node->child);
    free(node->key);
    free(node);
}

