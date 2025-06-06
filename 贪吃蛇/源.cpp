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
		printf("你撞墙了，游戏结束！\n");
		exit(0);
	}
}//根据键盘输入取得方向
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
		printf("游戏结束，谢谢游玩！\n");
		exit(0);
	}
}//打印规则
void rule() {
	printf("按w前进\n按s后退\n按a左移\n按d右移\n");
	puts("按e退出");
}//根据方向移动蛇头
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
	rule();//打印游戏规则
	update();//打印新图
	while (1) {
		move();//键盘输入移动方向以获得方向direction的值
		node();//让身体的各个节点接上上一截
		head();//根据方向direction的值移动蛇头坐标
		update();//打印新图
	}
	
}