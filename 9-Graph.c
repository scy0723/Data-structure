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
////node 값들을 담고있는 nodes배열 포인터를 받아
////graph구조체를 동적할당하고 초기값을 설정하는 함수
//Graph CreateGraph(int* nodes) {
//	Graph G = (Graph)malloc(sizeof(struct _Graph));
//	int size = 0;
//	while (nodes[size] > 0) size++;
//	G->size = --size;
//	//출력용 node, matrix 초기화
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
////Graph포인터와 두 정수 값을 받아
////a-b로 이루어진 인접 정보를 graph의 matrix에 저장하는 함수
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
////Graph포인터와 int배열 포인터를 받아 
////graph의 matrix에서 각 정점 별로 indegree값을 계산하여 배열에 저장하는 함수
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
////topsort에 필요한 Queue를 동적할당받아 초기값을 설정하고 Queue포인터를 반환하는 함수 
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
////Queue포인터와 삽입 값을 받아 해당 Queue에 값을 Enqueue하는 함수
//void Enqueue(Queue Q, int X) {
//		Q->key[++Q->rear] = X;
//		Q->qsize++;
//}
//
////Queue포인터를 받아 Dequeue를 수행하고 Dequeue된 값을 반환하는 함수
//int Dequeue(Queue Q) {
//		Q->qsize--;
//		return Q->key[Q->first++];
//}
//
////Graph포인터를 받아 graph의 위상정렬을 수행하고 정렬 결과를 출력하는 함수
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
////Graph포인터를 받아 입력받았던 인접 행렬 정보를 출력하는 함수
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
//	//입력의 첫 줄을 fgets로 받고 strtok와 atoi를 이용해 node들을 배열에 답기
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