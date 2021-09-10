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
////��������ϴ� heap�� �뷮 capacity�� �޾� heap�� ����� ���� ����ִ� ���� ������ ���� size�� 0���� �ʱ�ȭ���ְ� �� heap�� ��ȯ�ϴ� �Լ�
//Heap* CreateHeap(int heapsize) {
//	Heap* heap = malloc(sizeof(struct HeapStruct));
//	heap->Capacity = heapsize;
//	heap->Size = 0;
//	heap->Elements = (int*)malloc(sizeof(int)*heap->Capacity);
//	return heap;
//}
////heap �����͸� �޾� �ش� heap�� �� ä�����ִٸ� true, �ƴϸ� false�� ��ȯ�ϴ� �Լ�
//bool isFull(Heap *heap) {
//	if (heap->Capacity == heap->Size)
//		return true;
//	return false;
//}
//
////heap �����͸� �޾� �ش� heap�� ����ִٸ� true, �ƴϸ� false�� ��ȯ�ϴ� �Լ�
//bool isEmpty(Heap *heap) {
//	if (heap->Size == 0)
//		return true;
//	return false;
//}
//
////heap �����Ϳ� ã�����ϴ� value�� �޾� �ش� heap�� value�� ������ true, ������ false�� ��ȯ�ϴ� �Լ�
//int Find(Heap *heap, int value) {
//	for (int i = 1; i < heap->Size; i++) {
//		if (value == heap->Elements[i])
//			return 1;
//	}
//	return 0;
//}
//
////heap�����Ϳ� heapdp �������� value�� �޾� Maxheap�� ���ǿ� �°� value���� �ش� heap�� Insert�ϴ� �Լ�
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
////heap�����͸� �޾� �ش� heap�� root(���� ū ��)�� Maxheap�� �°� Delete�ϴ� �Լ�
//int DeleteMax(Heap *heap) {
//	int i, child, max_element, last_element;
//	max_element = heap->Elements[1];
//	last_element = heap->Elements[heap->Size--];
//
//	for (i = 1; i * 2 <= heap->Size;i=child) {
//		child = i * 2;
//		if (child < heap->Size && heap->Elements[child + 1]>heap->Elements[child])//rt child�� �ְ� rt��child���� ũ�� 
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
////heap�����͸� �޾� heap ���� ��� ������ ���Ͽ� ����ϴ� �Լ�
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
//	//heap�� ����� ���� �ٸ� ����� �����Ϸ��ϴ� ���� ó��
//	while (command != 'n') {
//		fprintf(fo, "Error: heap not created\n");
//		fscanf(fi, "%c", &command);
//	}
//	fscanf(fi, "%d", &num);
//	Heap* heap = CreateHeap(num);
//	fscanf(fi, "%c", &command);
//	//�Է��� ���� ������
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
//		//���ۿ� �ִ� "\n" ó��
//		fscanf(fi, "%c", &command);
//	}
//	return 0;
//}