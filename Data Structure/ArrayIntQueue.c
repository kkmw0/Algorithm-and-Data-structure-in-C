#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

/* ť �ʱ�ȭ */
int Initialize(IntQueue* q, int max) {
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;	/* �������� �ʴ� �迭 que�� �ٸ� �Լ��� ������ �������� 0���� �ʱ�ȭ */
		return -1;
	}
	q->max = max;
	return 0;
}

/* ť�� �����͸� ��ť */
int Enque(IntQueue* q, int x) {
	if (q->num >= q->max)
		return -1;
	else {
		q->num++;
		q->que[q->rear++] = x;

		if (q->rear >= q->max)
			q->rear = 0;
		return 0;
	}
}

/* ť���� �����͸� ��ť */
int Deque(IntQueue* q, int* x) {
	if (q->num <= 0)
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];

		if (q->front >= q->max)
			q->front = 0;
		return 0;
	}
}

/* ť���� �����͸� ��ũ */
int Peek(const IntQueue* q, int* x) {
	if (q->num <= 0)
		return -1;

	*x = q->que[q->front];
	return 0;
}

/* ť�� ���� �Լ� */
void Clear(IntQueue* q) {
	q->num = q->front = q->rear = 0;
}

/* ť�� �ִ� �뷮�� ���� */
int Capacity(const IntQueue* q) {
	return q->max;
}

/* ť�� ����� ������ ������ ���� */
int Size(const IntQueue* q) {
	return q->num;
}

/* ť�� ����ִ��� Ȯ�� */
int isEmpty(const IntQueue* q) {
	return q->num <= 0;
}

/* ť�� ����á���� Ȯ�� */
int isFull(const IntQueue* q) {
	return q->num >= q->max;
}

/* ť���� �˻� */
int Search(const IntQueue* q, int x) {
	int idx;
	for (int i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}
	return -1;
}

/* ť�� �����ϴ� ������ ��� */
void Print(const IntQueue* q) {
	int idx;
	for (int i = 0; i < q->num; i++)
		printf("%d ", q->que[idx = (i + q->front) % q->max]);
	putchar('\n');
}

/* ť ���� */
void Terminate(IntQueue* q) {
	if (q->que != NULL)
		free(q->que);
	q->max = q->front = q->rear = q->num = 0;
}