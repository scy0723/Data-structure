//#include<stdio.h>
//#include <stdlib.h>
//
//FILE * fi;
//FILE * o;
//
//struct CompleteTree {
//	int Size;
//	int nodeNum;
//	int* Element;
//};
//typedef struct CompleteTree* Tree;
//
////Ʈ���� á���� ���, �ƴ϶�� Element�� �� node value�� �߰��ϰ� nodeNum�� 1 �����ִ� �Լ�
//void Insert(Tree tree, int value) {
//	if (tree->nodeNum+1 > tree->Size)
//	{
//		fprintf(o, "Error! Tree is FULL.\n");
//	}
//	else if (tree->nodeNum <= tree->Size) {
//		tree->Element[tree->nodeNum+1] = value;
//		tree->nodeNum++;
//	}
//}
//
////tree�� ������ȸ�ϰ� Ž�� ������� node�� ���� ������Ͽ� ����ϴ� �Լ�
//void printPreorder(Tree tree, int index) {
//	if (index <= tree->nodeNum) {
//		fprintf(o, "%d ", tree->Element[index]);
//		printPreorder(tree, 2 * index);
//		printPreorder(tree, 2 * index + 1);
//	}
//}
////tree�� ������ȸ�ϰ� Ž�� ������� node�� ���� ������Ͽ� ����ϴ� �Լ�
//void printInorder(Tree tree, int index) {
//	if (index <= tree->nodeNum) {
//		printInorder(tree, 2 * index);
//		fprintf(o, "%d ", tree->Element[index]);
//		printInorder(tree, 2 * index + 1);
//	}
//}
////tree�� ������ȸ�ϰ� Ž�� ������� node�� ���� ������Ͽ� ����ϴ� �Լ�
//void printPostorder(Tree tree, int index) {
//	if (index <= tree->nodeNum) {
//		printPostorder(tree, 2 * index);
//		printPostorder(tree, 2 * index + 1);
//		fprintf(o, "%d ", tree->Element[index]);
//	}
//}
////free
//void Freetree(Tree tree) {
//	free(tree->Element);
//	free(tree);
//}
//
//int main() {
//	//	input = fopen(argv[1], "r");
//	//	output=fopen(argv[2],"wt");
//	fi = fopen("input.txt", "r");    //VS���� ����
//	o = fopen("output.txt", "wt");
//	Tree tr = malloc(sizeof(struct CompleteTree));
//	fscanf(fi, "%d", &tr->Size);
//
//	//Element[1]���� �ޱ�
//	tr->Element = malloc(sizeof(int)*(tr->Size));
//	int number;
//	tr->nodeNum = 0;
//
//	while (fscanf(fi,"%d",&number)!=EOF){
//		Insert(tr, number);
//	}
//
//hello:
//	fprintf(o, "Preorder: ");
//	printPreorder(tr, 1);
//	fprintf(o, "\n");
//
//	fprintf(o, "Inorder: ");
//	printInorder(tr, 1);
//	fprintf(o, "\n");
//
//	fprintf(o, "Postorder: ");
//	printPostorder(tr, 1);
//	fprintf(o, "\n");
//
//	fclose(fi);
//	fclose(o);
//}