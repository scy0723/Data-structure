//#include<stdio.h>
//#include<stdlib.h>
//#include <string.h>
//#define MAX 1000
//
//FILE*fi;
//FILE*fo;
//
//typedef struct _Queue* Queue;
//struct _Queue {
//	int* key;
//	int first;
//	int rear;
//	int qsize;
//	int max_queue_size;
//};
//
//typedef struct _Graph* Graph;
//struct _Graph {
//	int* node;
//	int size;
//	int** matrix;
//};
////node ������ ����ִ� nodes�迭 �����͸� �޾�
////graph����ü�� �����Ҵ��ϰ� �ʱⰪ�� �����ϴ� �Լ�
//Graph CreateGraph(int* nodes) {
//	Graph G = (Graph)malloc(sizeof(struct _Graph));
//	int size = 0;
//	while (nodes[size] > 0) size++;
//	G->size = --size;
//	//��¿� node, matrix �ʱ�ȭ
//	G->node = nodes;
//	G->matrix = (int**)malloc(sizeof(int*)*size);
//	for (int i = 0; i <= G->size; i++) {
//		G->matrix[i] = malloc(sizeof(int)*size);
//	}
//	for (int i = 0; i <= G->size; i++) {
//		for (int j = 0; j <= G->size; j++) {
//			G->matrix[i][j] = 0;
//		}
//	}
//	return G;
//}
//
////Graph�����Ϳ� �� ���� ���� �޾�
////a-b�� �̷���� ���� ������ graph�� matrix�� �����ϴ� �Լ�
//void InsertEdge(Graph G, int a, int b) {
//	int x = 0, y = 0;
//	for (int i = 0; i <= G->size; i++){
//		if (G->node[i] == a)
//			x = i;
//		if (G->node[i] == b)
//			y = i;
//	}
//	G->matrix[x][y] = 1;
//	return;
//}
//
////Graph�����Ϳ� int�迭 �����͸� �޾� 
////graph�� matrix���� �� ���� ���� indegree���� ����Ͽ� �迭�� �����ϴ� �Լ�
//void CheckIndeg(Graph G, int* indeg) {
//	for (int i = 0; i <= G->size; i++) {
//		int cnt = 0;
//		for (int j = 0; j <= G->size; j++)
//			if (G->matrix[j][i] == 1) 
//				cnt++;
//		indeg[i] = cnt;
//	}
//	return;
//}
//
////topsort�� �ʿ��� Queue�� �����Ҵ�޾� �ʱⰪ�� �����ϰ� Queue�����͸� ��ȯ�ϴ� �Լ� 
//Queue MakeNewQueue(int X) {
//	Queue Q = malloc(sizeof(struct _Queue));
//	Q->first = 0;
//	Q->rear = -1;
//	Q->qsize = 0;
//	Q->max_queue_size = MAX;
//	Q->key = malloc(sizeof(int)*Q->max_queue_size);
//	return Q;
//}
//
////Queue�����Ϳ� ���� ���� �޾� �ش� Queue�� ���� Enqueue�ϴ� �Լ�
//void Enqueue(Queue Q, int X) {
//		Q->key[++Q->rear] = X;
//		Q->qsize++;
//}
//
////Queue�����͸� �޾� Dequeue�� �����ϰ� Dequeue�� ���� ��ȯ�ϴ� �Լ�
//int Dequeue(Queue Q) {
//		Q->qsize--;
//		return Q->key[Q->first++];
//}
//
////Graph�����͸� �޾� graph�� ���������� �����ϰ� ���� ����� ����ϴ� �Լ�
//void TopSort(Graph G) {
//	Queue Q = MakeNewQueue(0);
//	int* indeg = (int*)malloc(sizeof(int) * G->size);
//	CheckIndeg(G, indeg);
//	//INIT
//	for (int i = 0; i <= G->size; i++)
//		if (indeg[i] == 0) 
//			Enqueue(Q, i);
//	//TopSort
//	int x;
//	while (Q->first <= Q->rear) {
//		x = Dequeue(Q);
//		for (int i = 0; i <= G->size; i++)
//			if (G->matrix[x][i] == 1 && --indeg[i] == 0)
//				Enqueue(Q, i);
//		fprintf(fo, "%d ", G->node[x]);
//	}
//	fprintf(fo, "\n");
//	free(Q);
//	return;
//}
//
////Graph�����͸� �޾� �Է¹޾Ҵ� ���� ��� ������ ����ϴ� �Լ�
//void Print(Graph G) {
//	fprintf(fo,"  ");
//	for (int i = 0; i <= G->size; i++)
//		fprintf(fo, "%d ", G->node[i]);
//	fprintf(fo, "\n");
//	for (int i = 0; i <= G->size; i++) {
//		fprintf(fo, "%d ", G->node[i]);
//		for (int j = 0; j <= G->size; j++)
//			fprintf(fo, "%d ", G->matrix[i][j]);
//		fprintf(fo, "\n");
//	}
//	fprintf(fo, "\n");
//	return;
//}
//
//
//int main() {
//	fi = fopen("input.txt", "r");
//	fo = fopen("output.txt", "w");
//
//	int nodes[MAX];
//	int size = -1;
//
//	char* input = malloc(sizeof(char)*MAX);
//
//	//�Է��� ù ���� fgets�� �ް� strtok�� atoi�� �̿��� node���� �迭�� ���
//	fgets(input, MAX, fi);
//	char* tok = strtok(input, " ");
//	while (tok != NULL) {
//		size++;
//		nodes[size] = atoi(tok);
//		tok = strtok(NULL, " ");
//	}
//
//	Graph G = CreateGraph(nodes);
//	while (!feof(fi)) {
//		int a, b;
//		fscanf(fi, "%d-%d", &a, &b);
//		InsertEdge(G, a, b);
//	}
//
//	Print(G);
//	TopSort(G);
//
//	free(G);
//	fclose(fi);
//	fclose(fo);
//}