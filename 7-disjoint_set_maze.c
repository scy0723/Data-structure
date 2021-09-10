#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE* fi;
FILE* fo;

typedef struct _DisjointSet {
	int size_maze;
	int *ptr_arr;
}DisjointSets;

typedef struct _DisjointSet* DisjointSet_pointer;

//sets,mazs_print �����Ϳ� �̷� ���� ���� num�� �޾� set�� �迭�� 0, maze_print�� �迭�� -1�� �ʱ�ȭ
void init(DisjointSets *sets, DisjointSets *maze_print, int num) {
	sets->size_maze = num * num;
	maze_print->size_maze = 2 * num*(num - 1);
	for (int i = 1; i <= sets->size_maze; i++) {
		sets->ptr_arr[i] = 0;
	}
	for (int i = 1; i <= maze_print->size_maze; i++) {
		maze_print->ptr_arr[i] = -1;
	}
}
//sets �����Ϳ� �� ���� i, j�� �޾� disjointSet���� union ����
void union_(DisjointSets *sets, int i, int j) {
	//WITHOUT ANY CYCLE
	int i_root = Find(sets, i);
	int j_root = Find(sets, j);
	if (i_root == j_root)
		return;
	if (sets->ptr_arr[j] < sets->ptr_arr[i]) {
		sets->ptr_arr[i] = j;
	}
	//sets->ptr_arr[j] < sets->ptr_arr[i]
	else {
		if (sets->ptr_arr[i] == sets->ptr_arr[j]) {
			sets->ptr_arr[i] --;
		}
		sets->ptr_arr[j] = i;
	}
}
//sets �����Ϳ� ���� i�� �޾� �ش� ptr_arr�迭���� i���� ã�´� (root ��ȯ)
int Find(DisjointSets *sets, int i) {
	while (sets->ptr_arr[i] > 0) {
		i = sets->ptr_arr[i];
	}
	return i;
}

//sets,mazs_print �����Ϳ� �̷� ���� ���� num�� �޾� 1(�Ա�)�� num*num(�ⱸ)�� union�� ���°� �� �� ���� �������� find�� union�Լ��� �̿��� �� ����
void createMaze(DisjointSets *sets, DisjointSets *maze_print, int num) {
	init(sets, maze_print, num);
	while (find(sets, 1) != find(sets, num*num)) {
		int ran = rand() % maze_print->size_maze + 1;
		//���κ�
		if (ran <= maze_print->size_maze / 2) {
			int a = ran / (num - 1);//���° ���ΰ�
			int b = ran % (num - 1);//�� �ٿ��� ���° �ΰ�
			if (b == 0) {
				b = num - 1; a--;
			}
			if (Find(sets, a*num + b) != Find(sets, a*num + b + 1)) {
				union_(sets, Find(sets, a*num + b), Find(sets, a*num + b + 1));
				maze_print->ptr_arr[ran] = 0;
			}
		}
		//���κ�
		else {		//ran > maze_print->size_maze / 2
			ran -= maze_print->size_maze / 2;
			int a = ran / num;
			int b = ran % num;
			if (b == 0) {
				b = num; a--;
			};
			if (find(sets, a*num + b) != find(sets, a*num + b + num)) {
				union_(sets, find(sets, a*num + b), find(sets, a*num + b + num));
				maze_print->ptr_arr[ran + maze_print->size_maze / 2] = 0;
			}
		}
	}
}
//�̷� ������ ������ maze �����Ϳ� num�� �ް� �迭�� �ִ� ������ �ش�Ǵ� ��ȣ�� ������Ͽ� ���
void printMaze(DisjointSets *maze_print, int num) {
	for (int i = 0; i <= 2 * num; i++) {
		for (int j = 0; j <= 2 * num; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				fprintf(fo, "+");
			else if ((i == 0 || i == 2 * num) && j % 2 == 1 && i % 2 == 0)
				fprintf(fo, "-");
			else if ((!(j == 0 && i == 1)) && (j == 0 || j == 2 * num) && (!(j == 2 * num&&i == 2 * num - 1)) && i % 2 == 1)
				fprintf(fo, "|");
			else if (j != 0 && j != 2 * num && i % 2 == 1 && j % 2 == 0) {
				int a = ((i - 1) / 2)*(num - 1) + (j / 2);
				if (maze_print->ptr_arr[a] == -1) {
					fprintf(fo, "|");
				}
				else fprintf(fo, " ");
			}
			else if (i != 0 && i != 2 * num && j % 2 == 1 && i % 2 == 0) {
				int a = ((i - 2) / 2)*num + (j + 1) / 2 + maze_print->size_maze / 2;
				if (maze_print->ptr_arr[a] == -1) {
					fprintf(fo, "-");
				}
				else fprintf(fo, " ");
			}
			else fprintf(fo, " ");
		}
		fprintf(fo, "\n");
	}
}
//�� disjointSet�� �����Ҵ� ����
void freeMaze(DisjointSets *sets, DisjointSets *maze_print) {
	free(sets);
	free(maze_print);
	free(sets->ptr_arr);
	free(maze_print->ptr_arr);
}
int main() {
	srand((unsigned int)time(NULL));
	int num;
	fi = fopen("input.txt", "r");
	fo = fopen("output.txt", "wt");
	//fi=fopen(argv[1],"r");
	//fo = fopen(argv[2], "w");
	fscanf(fi, "%d", &num);

	DisjointSet_pointer sets = malloc(sizeof(struct _DisjointSet));
	DisjointSet_pointer maze_print = malloc(sizeof(struct _DisjointSet));
	sets->ptr_arr = malloc(sizeof(int)*num*num);
	maze_print->ptr_arr = malloc(sizeof(int) * 2 * num*(num - 1));

	createMaze(sets, maze_print, num);
	printMaze(maze_print, num);
	fclose(fi);
	fclose(fo);
	freeMaze(sets, maze_print);
}