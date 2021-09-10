//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<ctype.h>
//#include<errno.h>
//#define _CRT_SECURE_NO_WARNINGS
//
//#define max_size 10
//#define EMPTY_TOS (-1) //비어있는 stack
//
//typedef struct StackRecord *Stack;
//struct StackRecord {
//	int* key;
//	int top;
//	int max_stack_size;
//};
//
//Stack CreateStack(int max_elements) {
//	Stack s = malloc(sizeof(struct StackRecord));
//	s->key = malloc(sizeof(sizeof(struct StackRecord)*max_elements));
//	s->max_stack_size = max_size;
//	s->top = EMPTY_TOS;
//
//	return s;
//}
//
//int IsFull(Stack S) { return S->top == max_size - 1; }
//
//int IsEmpty(Stack S) { return S->top == EMPTY_TOS;}
//
////차있으면 에러, 넣을 수 있으면 push하고 top은 1 더해주는 함수
//void Push(Stack S, int X, FILE* o) {
//	if (IsFull(S))
//		fprintf(o, "\nFull Stack!!"); //스택이 차있어서 push가 안될 때 
//	else {
//		S->key[++S->top] = X;
//	}
//}
////없으면 에러, 뺼 수 있으면 제일 마지막에 넣은 숫자를 반환하고 top은 1뺴주는 함수
//int Pop(Stack S, FILE* o) {
//
//	if (IsEmpty(S))
//		fprintf(o, "\nEmpty Stack!!"); //스택이 비어있어서 pop이 안될 때
//	else
//		return S->key[S->top--];
//}
//
////push한게 부호인지 숫자인지 판단해서 숫자면 push, 부호면 두 숫자를 pop해서 계산 후push해주는 함수
//int Postfix(Stack S, char input_str, FILE* o) {
//	if (isdigit(input_str)) {     //받은게 숫자면 push
//		int n = input_str - '0';  //아스키코드 48빼주기
//		Push(S,n,o); 
//		return S->key[S->top];
//	}
//	else {				       //받은게 부호면 계산
//		int result;
//		int a, b;
//		a = Pop(S,o); 
//		b = Pop(S,o); 
//		switch (input_str)
//		{
//		case('+'): { Push(S, b + a, o); return b + a; break; }
//		case('-'): { Push(S, b - a, o);  return b - a; break; }
//		case('*'): { Push(S, b * a, o);  return b * a; break; }
//		case('/'): { Push(S, b / a, o);  return b / a; break; }
//		case('%'): { Push(S, b % a, o); return b % a; break; }
//
//		default:
//			fprintf(o,"\nWrong operator!!");  //주어지지 않은 부호를 입력했을 때
//		}
//	}
//}
////free
//void DeleteStack(Stack S) { free(S); }
//
//int main() {
//	FILE * input;
//	FILE * output;
//	//input = fopen(argv[1], "r");
//	//output=fopen(argv[2],"wt");
//	input = fopen("input.txt", "r");    //VS에서 실행
//	output = fopen("output.txt", "wt");
//	
//	int topNum;
//	Stack stack= CreateStack(max_size);;
//	char c[101];
//	fgets(c, 101, input);
//
//	fprintf(output, "Top Numbers : ");
//	for (int i = 0; i < strlen(c) && c[i] != '#'; i++) {
//		topNum = Postfix(stack, c[i],output);
//		fprintf(output,"%d ",stack->key[stack->top]);
//	}
//	fprintf(output, "\nevaluation result : %d", topNum);
//}