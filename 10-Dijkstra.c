//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define inf 99999
//
//typedef struct Node {
//	int vertex;
//	int dist; //distance 
//	int prev;
//}Node;
//
//typedef struct Graph {
//	int size;
//	int** vertices;
//	Node* nodes;
//}Graph;
//
//
//typedef struct Heap {
//	int Capacity;
//	int Size;
//	Node* Element;
//}Heap;
//
//
//FILE* fi;
//FILE* fo;
//
////�׷����� size�� �޾� graph�� �����
////�������� ������ node���� dist=inf, prev=10���� �ʱ�ȭ
////vertice�� ���̵� ��� inf�ʱ�ȭ
//Graph* CreateGraph(int Size) {
//	Graph* g = malloc(sizeof(struct Graph));
//	g->size = Size;
//	g->nodes = malloc(sizeof(struct Node)*(Size));
//
//	for (int i = 1; i <= g->size; i++) {
//		g->nodes[i].vertex = i;
//	}
//	for (int i = 1; i <= g->size; i++) {
//		if (i == 1)
//			g->nodes[i].dist = 0;
//		else {
//			g->nodes[i].dist = inf;
//			g->nodes[i].prev = 10; //���� ���ڸ����� ���ٴ� ���� �־���
//		}
//	}
//	g->vertices = malloc(sizeof(int*)*Size);
//	for (int i = 1; i <= g->size; i++) {
//		g->vertices[i] = (int*)malloc(sizeof(int)*Size);
//		for (int j = 1; j <= g->size; j++) {
//			g->vertices[i][j] = inf;
//		}
//	}
//	return g;
//}
//
////heap �����Ϳ� ��¿�heap�� ���� vertex�� �ް� �ش� heap�� node�� �ִ� �Լ�
//void Push(Heap* h, int X) {
//	h->Element[h->Size++].vertex = X;
//	return;
//}
//
////heap �����͸� �ް� heap�� �ǵڿ� �ִ� node�� vertex���� ��ȯ�ϴ� �Լ�
//int Pop(Heap* h) {
//	return h->Element[--h->Size].vertex;
//}
//
////heap����� �ް� minheap�ְ� �´� heap�� ����� �Լ�
////������ ������ node���� dist�� inf �� �ʱ�ȭ
//Heap* createMinHeap(int heapSize) {
//	Heap* h = malloc(sizeof(struct Heap));
//	h->Capacity = heapSize;
//	h->Size = 0;
//	h->Element = (Node*)malloc(sizeof(struct Node)*(heapSize));
//	for (int i = 1; i <= h->Capacity; i++) {
//		h->Element[i].vertex = i;
//		h->Element[i].dist = inf;
//	}
//	h->Element[1].dist = 0;
//	return h;
//}
//
////heap�����͸� �ް� ���� vertex�� �Ÿ� distance�� �޾� heap�� �����ϴ� �Լ�
//void insertToMinHeap(Heap* minHeap, int vertex, int distance) {
//		Node N;
//		N.vertex = vertex;
//		N.dist = distance;
//		int i;
//		minHeap->Size++;
//		for (i = minHeap->Size; minHeap->Element[i / 2].dist > distance; i /= 2) { //i<=2
//			minHeap->Element[i] = minHeap->Element[i / 2];
//		}
//		minHeap->Element[i] = N;
//}
//
////heap�����͸� �ް� heap������ ���� ���� ����ġ(dist)�� ���� node�� ��ȯ�ϰ� �����ϴ� �Լ�
//Node deleteMin(Heap* minHeap) {
//	Node minNode = minHeap->Element[1];
//	Node lastNode = minHeap->Element[(minHeap->Size)--];
//	int i, child;
//	for (i = 1; i * 2 <= minHeap->Size; i = child) {
//		child = i * 2;
//		if (child < minHeap->Size && minHeap->Element[child + 1].dist < minHeap->Element[child].dist)
//			child++;
//		if (lastNode.dist > minHeap->Element[child].dist)
//			minHeap->Element[i] = minHeap->Element[child];
//		else
//			break;
//	}
//	minHeap->Element[i] = lastNode;
//	return minNode;
//}
//
////graph�����͸� �ް� ��� ����� �ִܰ�ο� dist�� ����ϰ�
////���� ���� ���� ��쵵 ����ϴ� �Լ�
//void PrintShortestPath(Graph* g) {
//	Heap* h = createMinHeap(10);
//	insertToMinHeap(h, 1, 0);
//	g->nodes[1].dist = 0;
//	while (h->Size != 0) {
//		Node N = deleteMin(h);
//		int x;
//		for (int i = 1; i <= g->size; i++)
//			if (N.vertex == g->nodes[i].vertex) x = i;
//		for (int i = 1; i <= g->size; i++) {
//
//			if (g->vertices[x][i] != inf && g->nodes[i].dist > N.dist + g->vertices[x][i]) {
//				g->nodes[i].dist = N.dist + g->vertices[x][i];
//				g->nodes[i].prev = x;
//				insertToMinHeap(h, i, g->nodes[i].dist);
//			}
//		}
//	}
//	for (int i = 2; i <= g->size; i++) {
//		Heap* ouputHeap = createMinHeap(g->size);
//		Push(ouputHeap, g->nodes[i].vertex);
//		int tmp = i;
//		while (tmp != 1) {
//			if (g->nodes[i].prev >= 10) { //���� ��� prev�� �ʱⰪ 10
//				fprintf(fo, "Cannot reach to %d", i);
//				break;
//			}
//			tmp = g->nodes[tmp].prev;
//			Push(ouputHeap, g->nodes[tmp].vertex);
//		}
//		if (g->nodes[i].prev >= 10) continue;
//		while (ouputHeap->Size != 1) {
//			fprintf(fo, "%d-> ", Pop(ouputHeap));
//		}
//		fprintf(fo, "%d  (cost: %d) \n", Pop(ouputHeap), g->nodes[i].dist);
//		free(ouputHeap);
//	}
//}
//
//int main() {
//	fi = fopen("input.txt", "r");
//	fo = fopen("output.txt", "wt");
//	Graph *g;
//
//	int size;
//	fscanf(fi, "%d\n", &size);
//	g = CreateGraph(size);
//	char temp = 0;
//	int node1, node2, weight;
//	while (temp != '\n') {
//		fscanf(fi, "%d-%d-%d", &node1, &node2, &weight);
//		g->vertices[node1][node2] = weight;
//		temp = fgetc(fi);
//	}
//	PrintShortestPath(g);
//
//}
