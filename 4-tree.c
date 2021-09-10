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
////트리가 찼으면 경고문, 아니라면 Element에 새 node value를 추가하고 nodeNum에 1 더해주는 함수
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
////tree를 전위순회하고 탐색 순서대로 node의 값을 출력파일에 출력하는 함수
//void printPreorder(Tree tree, int index) {
//	if (index <= tree->nodeNum) {
//		fprintf(o, "%d ", tree->Element[index]);
//		printPreorder(tree, 2 * index);
//		printPreorder(tree, 2 * index + 1);
//	}
//}
////tree를 중위순회하고 탐색 순서대로 node의 값을 출력파일에 출력하는 함수
//void printInorder(Tree tree, int index) {
//	if (index <= tree->nodeNum) {
//		printInorder(tree, 2 * index);
//		fprintf(o, "%d ", tree->Element[index]);
//		printInorder(tree, 2 * index + 1);
//	}
//}
////tree를 후위순회하고 탐색 순서대로 node의 값을 출력파일에 출력하는 함수
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
//	fi = fopen("input.txt", "r");    //VS에서 실행
//	o = fopen("output.txt", "wt");
//	Tree tr = malloc(sizeof(struct CompleteTree));
//	fscanf(fi, "%d", &tr->Size);
//
//	//Element[1]부터 받기
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