//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//FILE *fi;
//FILE *fo;
//typedef struct BinarySearchTree* Tree;
//struct BinarySearchTree {
//	int value;
//	Tree left;
//	Tree right;
//};
////key�� �ִ� node�� ã�� �װ� root�� �ϴ� Ʈ�� Ž��
////������ null, ������ ��ġ ��ȯ
//Tree TreeFind(Tree root, int key) {
//	if (root == NULL) return NULL;
//	if (key < root->value) return TreeFind(root->left, key);
//	else if (key > root->value) return TreeFind(root->right, key);
//	else return root;
//}
////TreeFind���� null �����ϸ� not in the tree
////�ƴϸ� in the tree ����ϴ� �Լ�
//void findNode(Tree root, int key) {
//	if (TreeFind(root, key) == NULL)
//		fprintf(fo, "%d is not in the tree\n", key);
//	else
//		fprintf(fo, "%d is in the tree.\n", key);
//}
////�μ�Ʈ �Լ�
//Tree Insert(Tree root, int key) {
//	if (root == NULL) { //�ƹ��͵� ���� �ڸ��� ��� ó�� ����� �����Ҵ�
//		root = malloc(sizeof(struct BinarySearchTree));
//		root->value = key;
//		root->left = NULL;
//		root->right = NULL;
//	}
//	else if (key < root->value)
//		root->left = Insert(root->left, key);
//	else if (key > root->value)
//		root->right = Insert(root->right, key);
//	else
//		fprintf(fo, "Insertion Error: %d is already in the tree\n", key);
//	return root;
//}
////input���� subtree�� root�����͸� �޾Ƽ� deleteNode�Լ��� ���� �� ��
////�����Ǵ� node��ġ ��� �� node ã���ִ� �Լ�
//Tree findMin(Tree root) {
//	if (root == NULL)
//		return NULL;
//	else if (root->left == NULL)
//		return root;
//	else
//		return findMin(root->left);
//}
////�ش� root �����͸� root���ϴ� Ʈ�� ������� ������ ��ȯ��
//Tree deleteNode(Tree root, int key) {
//	Tree tmp = malloc(sizeof(Tree));
//	if (root == NULL) fprintf(fo, "Deletion Error: %d is not in the tree.\n", key);
//	else if (key < root->value)
//		root->left = deleteNode(root->left, key);
//	else if (key > root->value)
//		root->right = deleteNode(root->right, key);
//	else if (root->left&&root->right) {
//		tmp = findMin(root->right);
//		root->value = tmp->value;
//		root->right = deleteNode(root->right, root->value);
//	}
//	else {
//		tmp = root;
//		if (root->left == NULL) root = root->right;
//		else if (root->right == NULL) root = root->left;
//		free(tmp);
//		fprintf(fo, "delete %d\n", key);
//	}
//	return root;
//}
////������ȸ Ž�� ������� �����
//void printInorder(Tree root) {
//	if (root) {
//		printInorder(root->left);
//		fprintf(fo, "%d ", root->value);
//		printInorder(root->right);
//	}
//}
//int main() {
//	fi = fopen("input.txt", "r");
//	fo = fopen("output.txt", "w");
//	char command[20];
//	int num;
//	Tree T = malloc(sizeof(Tree));
//	T = NULL;
//	while (fscanf(fi, "%s", command) != EOF) {
//		//insert
//		if (strcmp(command, "i") == 0) {
//			fscanf(fi, "%d", &num);
//			T = Insert(T, num);
//			fprintf(fo, "insert %d\n", num);
//		}
//		//find
//		else if (strcmp(command, "f") == 0) {
//			fscanf(fi, "%d", &num);
//			findNode(T, num);
//		}
//		//delete
//		else if (strcmp(command, "d") == 0) {
//			fscanf(fi, "%d", &num);
//			T = deleteNode(T, num);
//		}
//		//print Inorder
//		else if (strcmp(command, "pi") == 0) {
//			printInorder(T);
//			fprintf(fo, "\n");
//		}
//	}
//	return 0;
//}