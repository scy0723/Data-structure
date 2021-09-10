//#include<stdio.h>
//#include<stdlib.h>
//
//FILE*fi;
//FILE*fo;
//
//typedef struct ListNode *Position;
//typedef Position List;
//typedef struct HashTbl *HashTable;
//
//struct ListNode {
//	int Element;
//};
//struct HashTbl {
//	int TableSize;
//	List* TheLists;
//};
//
//int Hash(int value, int Size, int i, int solution) {
//	int index = value % Size;
//	int X = index;
//	//Linear
//	if (solution == 1)
//		index += i;
//	//Quadratic
//	else if (solution == 2)
//		index = X + (i * i);
//	return index;
//}
//
//int Find(HashTable H, int value, int solution) {
//	for (int i = 0; i < H->TableSize; i++) {
//		if (H->TheLists[i]->Element == value)
//			return i;
//	}
//	return -1;
//}
//
//void Insert(HashTable H, int value, int solution) {
//	if (Find(H, value, solution) == -1) {
//		int size = H->TableSize;
//		int index = value % size;
//		int i = 1;
//		while (1) {
//			if (H->TheLists[index]->Element != 0) {
//				if (size <= index)
//					index = index % size;
//				if (H->TheLists[index]->Element != 0)
//					index = Hash(value, size, i++, solution);
//			}
//			else {
//				H->TheLists[index]->Element = value;
//				fprintf(fo, "Inserted %d\n", value);
//				break;
//			}
//
//		}
//	}
//	else fprintf(fo, "Already exists.\n");
//}
//void Delete(HashTable H, int value, int solution) {
//	if (Find(H, value, solution) != -1) {
//		H->TheLists[Find(H, value, solution)]->Element = 0;
//		fprintf(fo, "Delete %d\n", value);
//	}
//	else fprintf(fo, "%d not exists.\n", value);
//}
//
//void printTable(HashTable H) {
//	int isEmpty = 1;
//	for (int i = 0; i < H->TableSize; i++)
//		if (H->TheLists[i]->Element != 0) isEmpty = 0;
//	if (!isEmpty) {
//		for (int i = 0; i < H->TableSize; i++) {
//			fprintf(fo, "%d ", H->TheLists[i]->Element);
//		}
//		fprintf(fo, "\n");
//	}
//	else fprintf(fo, "The list is empty.\n");
//}
//
//
//int main() {
//	fi = fopen("input.txt", "r");
//	fo = fopen("output.txt", "wt");
//	char sol[10];
//	int solution = 0, value, size;
//	fscanf(fi, "%s\n", sol);
//	if (sol[0] == 'L') solution = 1;
//	else if (sol[0] == 'Q') solution = 2;
//	HashTable H = malloc(sizeof(struct HashTbl));
//	fscanf(fi, "%d\n", &size);
//	H->TableSize = size;
//	H->TheLists = malloc(sizeof(List)*(H->TableSize));
//	int i;
//	for (i = 0; i < H->TableSize; i++) {
//		H->TheLists[i] = malloc(sizeof(struct ListNode));
//		H->TheLists[i]->Element = 0;
//	}
//	char input;
//	while (fscanf(fi, "%c\n", &input) != EOF) {
//		if (input == 'i') {
//			fscanf(fi, "%d\n", &value);
//			Insert(H, value, solution);
//		}
//		else if (input == 'd') {
//			fscanf(fi, "%d\n", &value);
//			Delete(H, value, solution);
//		}
//		else if (input == 'f') {
//			fscanf(fi, "%d\n", &value);
//			if (Find(H, value, solution) == -1)
//				fprintf(fo, "Not found.\n");
//			else
//				fprintf(fo, "%d", Find(H, value, solution));
//		}
//		else if (input == 'p') {
//			printTable(H);
//		}
//	}
//	free(H);
//}