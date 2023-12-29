#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ISFULL 1
#define ISEMPTY 2
#define DIVIDEZERO 3

FILE *fin;
FILE *fout;

typedef struct Stack{
	int *key;
	int top;
	int max_stack_size;
} Stack;

Stack* CreateStack(int max);
void Push(Stack* S, int X);
int Pop(Stack* S);
int Top(Stack* S);

void DeleteStack(Stack* S);
int IsEmpty(Stack* S);
int IsFull(Stack* S);

void main(int argc, char *argv[]){
	fin= fopen(argv[1], "r");
	fout=fopen(argv[2], "w");

	Stack* stack;
	char input_str[101];
	int max=20, i=0, a, b, result, error_flag=0;

	fgets(input_str, 101, fin);
	stack = CreateStack(max);

	fprintf(fout, "top numbers : ");
	while(input_str[i]!='#'){
		if('0'<=input_str[i] && input_str[i]<='9'){
			if(IsFull(stack)==0) Push(stack, input_str[i]-'0');
			else{
				error_flag = ISFULL;
				break;
			}
		}
		else{
			int val1, val2;
			if(IsEmpty(stack)){
				error_flag = ISEMPTY;
				break;
			}
			val1 = Pop(stack);
			if(IsEmpty(stack)){
				error_flag = ISEMPTY;
				break;
			}
			val2 = Pop(stack);
			if(input_str[i]=='+'){
				Push(stack, val2+val1);
			}
			if(input_str[i]=='-'){
				Push(stack, val2-val1);
			}
			if(input_str[i]=='*'){
				Push(stack, val2*val1);
			}
			if(input_str[i]=='/'){
				if(val1==0){
					error_flag = DIVIDEZERO;
					break;
				}
				Push(stack, val2/val1);
			}
			if(input_str[i]=='%'){
				if(val1==0){
					error_flag = DIVIDEZERO;
					break;
				}
				Push(stack, val2%val1);
			}

		}

		int t = Top(stack);
		fprintf(fout, "%d ", t);
		result = t;

		i++;
	}
	if(error_flag == ISFULL){
		fprintf(fout, "\nerror : invalid postfix expression, stack is full!\n");
	}	
	else if(error_flag == ISEMPTY){
		fprintf(fout, "\nerror : invalid postfix expression, stack is empty!\n");
	}	
	else if(error_flag == DIVIDEZERO){
		fprintf(fout, "\nerror : invalid postfix expression, divide by zero!\n");
	}
	else{
		if(stack->top+1 > 1){
			fprintf(fout, "\nerror : invalid postfix expression, %d elements are left!\n", stack->top+1);
		}
		else{
			fprintf(fout, "\nevaulation result : %d\n", result);
		}
	}

	fclose(fin);
	fclose(fout);
	DeleteStack(stack);
}
	

Stack* CreateStack(int max){
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->key = (int*)malloc(sizeof(int)*max);
	s->top = -1;
	s->max_stack_size = max;
	return s;
}

void Push(Stack* S, int X){
	(S->key)[S->top + 1] = X;
	S->top = S->top + 1;
}

int Pop(Stack* S){
	int tmp = (S->key)[S->top];
	(S->key)[S->top] = NULL;
	S->top = S->top - 1;
	return tmp;
}

int Top(Stack* S){
	return (S->key)[S->top];
}

void DeleteStack(Stack* S){
	for(int i=0; i<S->max_stack_size; i++){
		(S->key)[i] = NULL;
	}
	free(S->key);
	free(S);
}

int IsEmpty(Stack* S){
	if(S->top+1==0){
		return 1;
	}
	else return 0;
}

int IsFull(Stack* S){
	if(S->top+1>=S->max_stack_size){
		return 1;
	}
	else return 0;
}
