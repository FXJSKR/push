#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//���������㷨
//int *a ����һ������ ; nΪ�����С
void cr(int *a,unsigned n) {
	short flag = -1;
	for (int i = 1;i < n;i++) {
		for (int j = i-1;j>=0;j--) {
			if (a[i] < a[j])
				flag = j;
		}
		if (flag != -1) {
			int t = a[i];
			for (int j = i;j - 1 >= flag;j--) {
				a[j] = a[j - 1];
			}
			a[flag] = t;
		}
			flag = -1;
	}
}
//��ӡ����
void printarr(int *a, unsigned n) {
	for (int i = 0;i < n;i++) {
		printf("%d ", a[i]);
	}
}
//����һ�����飬��ÿ��Ԫ�ض�����һ��100���������
int* make(unsigned n) {
	int* a = (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	for (int i = 0;i < n;i++) {
		a[i] = rand()%100;
	}
	return a;
}
int main() {
	unsigned n=18;//nֵ�������޸�
	int* a = make(n);//���ɴ�СΪn�����鲢�����ֵ
	cr(a,n);//����������
	printarr(a,n);//��ӡ
	free(a);
}