//#include <stdio.h>
//#include <stdlib.h>
//#include<stdbool.h>
//
//FILE* fi;
//FILE* fo;
//
//typedef struct HeapStruct{
//	int Capacity;
//	int Size;
//	int *Elements;
//}Heap;
//
////만들고자하는 heap의 용량 capacity를 받아 heap을 만들고 현재 들어있는 숫자 개수를 담을 size는 0으로 초기화해주고 그 heap을 반환하는 함수
//Heap* CreateHeap(int heapsize) {
//	Heap* heap = malloc(sizeof(struct HeapStruct));
//	heap->Capacity = heapsize;
//	heap->Size = 0;
//	heap->Elements = (int*)malloc(sizeof(int)*heap->Capacity);
//	return heap;
//}
////heap 포인터를 받아 해당 heap이 꽉 채워져있다면 true, 아니면 false를 반환하는 함수
//bool isFull(Heap *heap) {
//	if (heap->Capacity == heap->Size)
//		return true;
//	return false;
//}
//
////heap 포인터를 받아 해당 heap이 비어있다면 true, 아니면 false를 반환하는 함수
//bool isEmpty(Heap *heap) {
//	if (heap->Size == 0)
//		return true;
//	return false;
//}
//
////heap 포인터와 찾고자하는 value를 받아 해당 heap에 value가 있으면 true, 없으면 false를 반환하는 함수
//int Find(Heap *heap, int value) {
//	for (int i = 1; i < heap->Size; i++) {
//		if (value == heap->Elements[i])
//			return 1;
//	}
//	return 0;
//}
//
////heap포인터와 heapdp 넣으려는 value를 받아 Maxheap의 조건에 맞게 value값을 해당 heap에 Insert하는 함수
//void Insert(Heap *heap, int value) {
//	if (isFull(heap)) {
//		fprintf(fo, "Insert Error: heap is full\n");
//		return;
//	}
//	if (Find(heap, value)) {
//		fprintf(fo, "[%d] is already in the heap\n", value);
//		return;
//	}
//	int i;
//	heap->Size++;
//	if (heap->Size == 1) {
//		heap->Elements[1] = value;
//	}
//	for (i = heap->Size; heap->Elements[i / 2] < value && i>=2; i /= 2) {
//		heap->Elements[i] = heap->Elements[i / 2];
//	}
//	heap->Elements[i] = value;
//	fprintf(fo,"Insert %d\n", value);
//}
//
////heap포인터를 받아 해당 heap의 root(가장 큰 값)을 Maxheap에 맞게 Delete하는 함수
//int DeleteMax(Heap *heap) {
//	int i, child, max_element, last_element;
//	max_element = heap->Elements[1];
//	last_element = heap->Elements[heap->Size--];
//
//	for (i = 1; i * 2 <= heap->Size;i=child) {
//		child = i * 2;
//		if (child < heap->Size && heap->Elements[child + 1]>heap->Elements[child])//rt child가 있고 rt가child보다 크면 
//			child++;
//		if (last_element < heap->Elements[child])
//			heap->Elements[i] = heap->Elements[child];
//		else
//			break;
//	 }
//	heap->Elements[i] = last_element;
//	return max_element;
//}
//
////heap포인터를 받아 heap 내의 모든 값들을 파일에 출력하는 함수
//void PrintHeap(Heap *heap) {
//	if (isEmpty(heap)) {
//		fprintf(fo, "Print Error: heap is empty\n");
//	}
//	else{
//		for (int i = 1; i <= heap->Size; i++) 
//			fprintf(fo, "%d ", heap->Elements[i]);
//		fprintf(fo, "\n");
//	}
//}
//
//int main() {
//	fi = fopen("input.txt", "r");
//	fo = fopen("output.txt", "wt");
//	char command;
//	int num;
//	fscanf(fi, "%c", &command);
//
//	//heap을 만들기 전에 다른 명령을 수행하려하는 예외 처리
//	while (command != 'n') {
//		fprintf(fo, "Error: heap not created\n");
//		fscanf(fi, "%c", &command);
//	}
//	fscanf(fi, "%d", &num);
//	Heap* heap = CreateHeap(num);
//	fscanf(fi, "%c", &command);
//	//입력이 끝날 때까지
//	while (fscanf(fi, "%c", &command) != EOF) {
//		if (command == 'i') {
//			fscanf(fi, "%d", &num);
//			Insert(heap, num);
//		}
//		else if (command == 'd') {
//			if (!isEmpty(heap)) {
//				fprintf(fo, "Max Element: %d deleted\n", DeleteMax(heap));
//			}
//			else
//				fprintf(fo, "Delete Error: heap is empty\n");
//		}
//		else if (command == 'f') {
//			fscanf(fi, "%d", &num);
//			if (Find(heap, num))
//				fprintf(fo,"%d is in the heap\n",num);
//			else
//				fprintf(fo,"%d is not in the heap\n",num);
//		}
//		else if (command == 'p') {
//			PrintHeap(heap);
//		}
//		//버퍼에 있는 "\n" 처리
//		fscanf(fi, "%c", &command);
//	}
//	return 0;
//}