#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//插入排序算法
//int *a 传递一个数组 ; n为数组大小
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
//打印数组
void printarr(int *a, unsigned n) {
	for (int i = 0;i < n;i++) {
		printf("%d ", a[i]);
	}
}
//生成一个数组，，每个元素都被赋一个100以内随机数
int* make(unsigned n) {
	int* a = (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	for (int i = 0;i < n;i++) {
		a[i] = rand()%100;
	}
	return a;
}
int main() {
	unsigned n=18;//n值可随意修改
	int* a = make(n);//生成大小为n的数组并赋随机值
	cr(a,n);//插入排序函数
	printarr(a,n);//打印
	free(a);
}