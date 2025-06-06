#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 10
void charu(int* a,int j,int i) {
    int temp = a[j];
    for (int q = 1;q <= i;q++) {
        a[q - 1] = a[q];
    }
    a[i] = temp;
}
void paixu(int* a, int n) {
    int temp,isswap,j,i;
    for (j = 0;j <= n - 3;j++) {
        flag:
        isswap = 0;
        //��һ�����������
        f:
        for (i = j + 1;i+1 <=n-1;i++)
        {
            if (a[j] > a[i] && a[j] < a[i + 1]) {
                printf("���һ��֮ǰ��\n");
                temp = a[j];
                for (int q = j;q+1 <= i;q++) {
                    a[q] = a[q+1];
                }
                a[j] = temp;
                for (int m = 0;m < n;m++) {
                    printf("%d ", a[m]);
                }printf("\n");
                goto f;
            }
        }
        //û����ˣ���һ���ܷ�������һ���ĺ���
        if (a[j] >= a[n - 1]) {
            printf("�����\n");
            temp = a[j];
            for (int q = 1;q <= n - 1;q++) {
                a[q - 1] = a[q];
            }
            a[n-1] = temp;
            goto flag;
            printf("���j%d\n",j);
            for (int m = 0;m < size;m++) {
                printf("%d ", a[m]);
            }
            printf("\n");

        }
    }
}
    

    int main(){
        srand(time(NULL));
        int a[size];
        printf("��ʼ\n");
  
        for (int i = 0;i < size;i++) {
            a[i] = rand() % size;
            printf("%d ", a[i]);
        }printf("\n");
        paixu(a, 3);
        printf("\n");
        printf("main���\n");
        for (int i = 0;i < size;i++) {
            printf("%d ", a[i]);
        }
    }
    //1 3 2 0
    //
    //
    //