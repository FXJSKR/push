#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define left 1
#define right 2
#define up 3
#define down 4
#define L 80
#define W 40
typedef struct {
	int x, y;
}xy;
xy food;
xy snake[80];
int direction,lenth=70;
void update() {
	int flag = 0;
	for (int i = 1;i <= W;i++) {
		for (int j = 1;j <=L;j++) {
			if(i==1||i==W)
			printf("#");
			else {
				if (j != 1 && j != L) {
					for (int k = 0;k < lenth;k++) {
						if (snake[k].x == j && snake[k].y == i) {
							printf("*");flag = 1;
							break;
						}
						else flag = 0;
					}
					if (!flag) {
						printf(" ");
					}
				}
				else printf("#");
			}
		}
		printf("\n");
	}
	if (snake[0].y == 1 || snake[0].y == W || snake[0].x == 1 || snake[0].x == L) {
		printf("��ײǽ�ˣ���Ϸ������\n");
		exit(0);
	}
}//���ݼ�������ȡ�÷���
void move() {
	char ch= getchar();
	switch(ch){
	case 'w':
		direction = up;
		break;
	case 's':
		direction = down;
		break;
	case 'a':
		direction = left;
		break;
	case 'd':
		direction = right;
		break;
	case 'e':
		printf("��Ϸ������лл���棡\n");
		exit(0);
	}
}//��ӡ����
void rule() {
	printf("��wǰ��\n��s����\n��a����\n��d����\n");
	puts("��e�˳�");
}//���ݷ����ƶ���ͷ
void head() {
	switch (direction) {
	case right:
		snake[0].x++;
		break;
	case left:
		snake[0].x--;
		break;
	case up:
		snake[0].y--;
		break;
	case down:
		snake[0].y++;
		break;
	}
}
void node() {
	for (int i = lenth-1;i>0;i--)
		snake[i] = snake[i - 1];
}
void setbody(){
	snake[0].x = 70;
		;snake[0].y = 25;
	for (int i = 1;i < lenth;i++) {
		snake[i].x =(snake[i-1].x)-1 ;snake[i].y = 25;
	}
}
int main() {
	setbody();
	rule();//��ӡ��Ϸ����
	update();//��ӡ��ͼ
	while (1) {
		move();//���������ƶ������Ի�÷���direction��ֵ
		node();//������ĸ����ڵ������һ��
		head();//���ݷ���direction��ֵ�ƶ���ͷ����
		update();//��ӡ��ͼ
	}
	
}