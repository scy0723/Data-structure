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
////그래프의 size를 받아 graph를 만들고
////시작점을 제외한 node들을 dist=inf, prev=10으로 초기화
////vertice의 길이도 모두 inf초기화
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
//			g->nodes[i].prev = 10; //수는 한자리수만 들어간다는 조건 주어짐
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
////heap 포인터와 출력용heap에 넣을 vertex를 받고 해당 heap에 node를 넣는 함수
//void Push(Heap* h, int X) {
//	h->Element[h->Size++].vertex = X;
//	return;
//}
//
////heap 포인터를 받고 heap의 맨뒤에 있는 node의 vertex값을 반환하는 함수
//int Pop(Heap* h) {
//	return h->Element[--h->Size].vertex;
//}
//
////heap사이즈를 받고 minheap주고에 맞는 heap을 만드는 함수
////시작점 제외한 node들의 dist는 inf 로 초기화
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
////heap포인터를 받고 정점 vertex와 거리 distance를 받아 heap에 삽입하는 함수
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
////heap포인터를 받고 heap내에서 가장 작은 가중치(dist)를 가진 node를 반환하고 정렬하는 함수
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
////graph포인터를 받고 모든 노드의 최단경로와 dist를 출력하고
////가는 길이 없는 경우도 출력하는 함수
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
//			if (g->nodes[i].prev >= 10) { //길이 없어서 prev가 초기값 10
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
