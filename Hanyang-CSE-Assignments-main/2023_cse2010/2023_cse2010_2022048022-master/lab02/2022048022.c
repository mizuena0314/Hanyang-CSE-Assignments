#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node
{
	ElementType element;
	Position next;
};

List MakeEmpty(List L);

int IsEmpty(List L);

int IsLast(Position P, List);

void PrintList(List L);

void Insert(ElementType X, List L, Position P);

void Delete(ElementType X, List L);

Position Find(ElementType X, List L);

Position FindPrevious(ElementType X, List L);

void DeleteList(List L);

FILE *input;
FILE *output;

int main(int argc, char *argv[]){
	char command;
	int key1, key2;
	FILE *input;
	Position header = NULL;
	Position tmp = NULL;
	if(argc == 1){
		input = fopen("input.txt", "r");
		output = fopen("output.txt", "w");
	}
	else{
		input = fopen(argv[1], "r");
		output = fopen(argv[2], "w");
	}
	header = MakeEmpty(header);
	while(1){
		command = fgetc(input);
		if(feof(input)) break;
		switch(command){
			case 'i':
				fscanf(input, "%d %d", &key1, &key2);
				//duplication check
				tmp = Find(key1, header);
				if(tmp!=NULL){
					fprintf(output, "insertion(%d) failed : the key already exists in the list\n", key1);
					break;
				}
				tmp = Find(key2, header);
				if(tmp==NULL){
					fprintf(output, "insertion(%d) failed : can not find the location to be inserted\n", key1);
					break;
				}
				
				Insert(key1, header, tmp);
				break;

			case 'd':
				fscanf(input, "%d", &key1);
				Delete(key1, header);
				break;

			case 'f':
				fscanf(input, "%d", &key1);
				tmp = FindPrevious(key1, header);
				if (IsLast(tmp, header))
					fprintf(output, "finding(%d) failed : element %d is not in the list\n", key1, key1);
				else{
					if(tmp->element > 0)
						fprintf(output, "key of the previous node of %d is %d\n", key1, tmp->element);
					else
						fprintf(output, "key of the previous node of %d is head\n", key1);
				}
				break;
			case 'p':
				PrintList(header);
				break;
			default:
				break;
			}
	}

	DeleteList(header);
	fclose(input);
	fclose(output);
	return 0;
}

List MakeEmpty(List L){
	L = (List)malloc(sizeof(struct Node));
	L->element = -1;
	//initialize list with header key -1 and next node null
	L->next = NULL;
	return L;
}

int IsEmpty(List L){
	if(!L->next){
		return 1;
	}
	//check if header empty
	else return 0;
}

int IsLast(Position P, List L){
	if(!P->next){
		return 1;
	}
	//check if P next is null
	else return 0;
}

void Insert(ElementType X, List L, Position P){
	List newnode = (List)malloc(sizeof(struct Node));
	newnode->element = X;
	newnode->next = P->next;
	P->next = newnode;
	//insert the
}

void PrintList(List L){
	if(IsEmpty(L)){
		fprintf(output, "empty list!\n");
		return;
	}
	while(L){
		if(L->element!=-1) fprintf(output, "key:%d ", L->element);
		L = L->next;
	}
	fprintf(output, "\n");
	//print the
}

void Delete(ElementType X, List L){
	List tmp = L;
	while(L){
		if(L->element == X){
			tmp->next = L->next;
			L->element = NULL;
			L->next = NULL;
			free(L);
			return;
		}
		else{
			tmp = L;
			L = L->next;
		}
	}
	fprintf(output, "deletion(%d) failed : element %d is not in the list\n", X, X);
	//delete the X
}

Position Find(ElementType X, List L){
	while(L){
		if(L->element == X){
			return L;
		}
		else L = L->next;
	}
	return L;
	//iterate over list and find if not found till end 
	//return null
}

Position FindPrevious(ElementType X, List L){
	List tmp = L;
	while(L){
		if(L->element == X){
			return tmp;
		}
		else{
			tmp = L;
			L = L->next;
		}
	}
	return tmp;
}

void DeleteList(List L){
	List tmp = L;
	while(L){
		tmp = tmp->next;
		L->element = NULL;
		L->next = NULL;
		free(L);
		L = tmp;
	}
	//delete the
}
	
