//#include<stdio.h>
//#include<stdlib.h>
//
//FILE* fi;
//FILE* fo;
//
//typedef struct AVLNode *Position;
//typedef struct AVLNode *AVLTree;
//typedef int ElementType;
//struct AVLNode {
//	ElementType element;
//	AVLTree left;
//	AVLTree right;
//	int height;
//};
////두 수 중 큰 값을 반환하는 함수
//int Max(int a, int b) {
//	if (a > b) return a;
//	else return b;
//}
////T 포인터를 받고 T의 height 반환(없다면 -1)
//int Height(AVLTree T) {
//	if ( T == NULL) return -1;
//	else return T->height;
//}
////node 포인터를 받고 LeftRotation 진행(LL insert)
//Position SingleRotateWithLeft(Position node) {
//	Position tmp = node->left;
//	node->left = tmp->right;
//	tmp->right = node;
//	node->height = Max(Height(node->left), Height(node->right)) + 1;
//	tmp->height = Max(node->height, Height(node->left)) + 1;
//	return tmp;
//}
////node 포인터를 받고 Right Rotation 진행(RR insert)
//Position SingleRotateWIthRight(Position node) {
//	Position tmp = node->right;
//	node->right = tmp->left;
//	tmp->left = node;
//	node->height = Max(Height(node->left), Height(node->right)) + 1;
//	tmp->height = Max(node->height, Height(tmp->right)) + 1;
//	return tmp;
//}
////node 포인터를 받고 Left-right Double Rotation 진행
//Position DoubleRotateWIthLeft(Position node) {
//	node->left = SingleRotateWIthRight(node->left);
//	return SingleRotateWithLeft(node);
//}
////node 포인터를 받고 Right-left Double Rotation 진행
//Position DoubleRotateWIthRight(Position node) {
//	node->right = SingleRotateWithLeft(node->right);
//	return SingleRotateWIthRight(node);
//}
////X 받고 X가 element인 T생성하여 T포인터 반환
//AVLTree Insert(ElementType X, AVLTree T) {
//	if (T == NULL) {
//		T = malloc(sizeof(struct AVLNode));
//		T->element = X;
//		T->height = 0;
//		T->left = NULL;
//		T->right = NULL;
//	}
//	else if (X < T->element) {
//		T->left = Insert(X, T->left);
//		if (Height(T->left) - Height(T->right) >= 2) {
//			if (X < T->left->element)
//				T = SingleRotateWithLeft(T);
//			else
//				T = DoubleRotateWIthLeft(T);
//		}
//	}
//	else if (X > T->element) {
//		T->right = Insert(X, T->right);
//		if (Height(T->right) - Height(T->left) >= 2) {
//			if (X > T->right->element)
//				T = SingleRotateWIthRight(T);
//			else
//				T = DoubleRotateWIthRight(T);
//		}
//	}
//	T->height = Max(Height(T->left), Height(T->right)) + 1;
//	return T;
//}
////T 포인터를 받고 tree를 중위순회하고 탐색 순서대로 node의 element와 height 출력
//void printInorder(AVLTree T) {
//	if (T) {
//		printInorder(T->left);
//		fprintf(fo, "%d(%d) ", T->element, T->height);
//		printInorder(T->right);
//	}
//}
////free
//void deleteTree(AVLTree T) {
//	if(T->left!=NULL){
//		deleteTree(T->left);
//	}
//	if (T->right != NULL) {
//		deleteTree(T->right);
//	}
//	free(T);
//}
////찾는 X값과 T를 받고 X를 X를 element로 하는 T포인터 반환(없으면 NULL인 T반환)
//Position Find(ElementType X, AVLTree T) {
//	if (T == NULL) return T;
//	else if (X < T->element) return Find(X, T->left);
//	else if (X > T->element) return Find(X, T->right);
//	return T;
//}
//int main() {
//	fi = fopen("input.txt", "r");
//	fo = fopen("output.txt", "wt");
//	AVLTree T = NULL;
//	int X;
//	while (fscanf(fi, "%d", &X) != EOF) {
//		if (Find(X, T) != NULL){
//			fprintf(fo, "%d is already in the tree!\n", X);
//			printInorder(T);
//			fprintf(fo, "\n");
//		}
//		else {
//			T = Insert(X, T);
//			printInorder(T);
//			fprintf(fo, "\n");
//		}
//	}
//	deleteTree(T);
//}
