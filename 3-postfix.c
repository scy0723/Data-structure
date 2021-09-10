//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<ctype.h>
//#include<errno.h>
//#define _CRT_SECURE_NO_WARNINGS
//
//#define max_size 10
//#define EMPTY_TOS (-1) //����ִ� stack
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
////�������� ����, ���� �� ������ push�ϰ� top�� 1 �����ִ� �Լ�
//void Push(Stack S, int X, FILE* o) {
//	if (IsFull(S))
//		fprintf(o, "\nFull Stack!!"); //������ ���־ push�� �ȵ� �� 
//	else {
//		S->key[++S->top] = X;
//	}
//}
////������ ����, �E �� ������ ���� �������� ���� ���ڸ� ��ȯ�ϰ� top�� 1���ִ� �Լ�
//int Pop(Stack S, FILE* o) {
//
//	if (IsEmpty(S))
//		fprintf(o, "\nEmpty Stack!!"); //������ ����־ pop�� �ȵ� ��
//	else
//		return S->key[S->top--];
//}
//
////push�Ѱ� ��ȣ���� �������� �Ǵ��ؼ� ���ڸ� push, ��ȣ�� �� ���ڸ� pop�ؼ� ��� ��push���ִ� �Լ�
//int Postfix(Stack S, char input_str, FILE* o) {
//	if (isdigit(input_str)) {     //������ ���ڸ� push
//		int n = input_str - '0';  //�ƽ�Ű�ڵ� 48���ֱ�
//		Push(S,n,o); 
//		return S->key[S->top];
//	}
//	else {				       //������ ��ȣ�� ���
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
//			fprintf(o,"\nWrong operator!!");  //�־����� ���� ��ȣ�� �Է����� ��
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
//	input = fopen("input.txt", "r");    //VS���� ����
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