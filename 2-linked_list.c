//#include <stdio.h>
//#include <stdlib.h>
//
//FILE *output;
//
//typedef struct Node *PtrToNode;
//typedef PtrToNode List;
//typedef PtrToNode Position;
//typedef int ElementType;
//struct Node {
//	ElementType element;
//	Position next;
//};
//
//List MakeEmpty(List L);
//int IsEmpty(List L);
//int IsLast(Position P, List L);
//void DeleteList(List L);
//void Insert(ElementType X, List L, Position P);
//void PrintList(List L);
//void Delete(ElementType X, List L);
//Position Find(ElementType X, List L);
//Position Find2(ElementType X, List L);
//
//List MakeEmpty(List L) {
//	L = (List)malloc(sizeof(struct Node));
//	L->element = -1;
//	L->next = NULL;
//	return L;
//}
//
//int IsEmpty(List L) {
//	return L->next == NULL;
//}
//int IsLast(Position P, List L) {
//	Position tmp = L;
//	while (tmp->next != NULL) {
//		tmp = tmp->next;
//	}
//	return tmp == P;
//}
//void DeleteList(List L) {
//	Position P;
//	P = L->next;
//	while (P != NULL)
//	{
//		Position remove = P;
//		P = P->next;
//		free(remove);
//	}
//	return;
//}
//
//void Insert(ElementType X, List L, Position P) {
//	Position tmp;
//	tmp = (Position)malloc(sizeof(struct Node));
//	tmp->element = X;
//	tmp->next = P->next;
//	P->next = tmp;
//	return;
//}
//
//void PrintList(List L) {
//	Position tmp = L->next;
//	while (tmp != NULL) {
//		fprintf(output, "key: %d ", tmp->element);
//		tmp = tmp->next;
//	}
//	fprintf(output, "\n");
//	return;
//}
//
//void Delete(ElementType X, List L) {
//	Position pos1, pos2;
//	if (Find2(X, L) != NULL) {
//		pos1 = Find2(X, L);
//		pos2 = Find(X, L);
//		pos1->next = pos2->next;
//		free(pos2);
//	}
//	else DeleteList(L);
//	return;
//}
//
//Position Find(ElementType X, List L) {
//	if (X == -1) return L; //return header
//	Position tmp = L;
//	while (tmp != NULL && tmp->element != X)
//		tmp = tmp->next;
//	return tmp;
//}
//
//Position Find2(ElementType X, List L) {
//	Position tmp = L;
//	while (tmp->next != NULL && tmp->next->element != X)
//		tmp = tmp->next;
//	return tmp;
//}
//
//int main(int argc, char *argv[]) {
//	char command;
//	int key1, key2;
//
//	FILE *input;
//
//	Position header = NULL;
//	Position tmp = NULL;
//
//	//input = fopen(argv[1], "r");
//	input = fopen("input.txt", "r");
//	output = fopen("output.txt", "wt");
//
//	header = MakeEmpty(header);
//
//	while (1) {
//		command = fgetc(input);
//		if (feof(input)) break;
//		switch (command) {
//		case 'i':
//			fscanf(input, "%d %d", &key1, &key2);
//			tmp = Find(key2, header);
//			if (tmp == NULL)
//				fprintf(output, "Insertion(%d) Failed: cannot find the location to be inserted.\n", key1);
//			Insert(key1, header, tmp);
//			/*
//			else {
//				if (key2 != -1)
//					Insert(key1, header, tmp);
//				else
//					Insert(key1, header, header);
//			}
//			*/
//			break;
//		case 'd':
//			fscanf(input, "%d", &key1);
//			Position tmp;
//			tmp = Find(key1, header);
//			if (tmp == NULL)
//				fprintf(output, "Deletion(%d) Failed: Element %d is not in the list.\n", key1, key1);
//			else
//				Delete(key1, header);
//			break;
//		case 'f':
//			fscanf(input, "%d", &key1);
//			tmp = Find2(key1, header);
//			if (IsLast(tmp, header))
//				fprintf(output, "Finding(%d) Failed: Element %d is not in the list.\n", key1, key1);
//			else {
//				if (tmp->element > 0)
//					fprintf(output, "Key of the previous node of %d is %d.\n", key1, tmp->element);
//				else
//					fprintf(output, "Key of the previous node of %d is head.\n", key1);
//			}
//			break;
//		case 'p':
//			PrintList(header);
//			break;
//		default:
//			break;
//		}
//	}
//
//	DeleteList(header);
//	fclose(input);
//	fclose(output);
//
//	return 0;
//}