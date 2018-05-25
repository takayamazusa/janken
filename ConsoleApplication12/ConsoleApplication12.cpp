// ConsoleApplication12.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>


/*int main() {
	int kake[9][9];
	int a;
	int b;
	int c;

	for (a = 1; a < 10; a++) {
		for (b = 1; b < 10; b++) {
			c = a * b;
			printf("%d\t", c);
		}
		printf("\n");
	}
	return 0;
}*/

/*int main(void)
{
	int a;
	int b;
	printf("ひとつめの数字を入力してください\n");
	scanf_s("%d", &a);
	printf("ふたつめの数字を入力してください\n");
	scanf_s("%d", &b);
	
	printf("結果\n%d + %d = %d",a, b, a+b);

	return 0;
}*/


/*int main() {
	srand(time(NULL));
	int a = 0;
	int b;
	int game = 0;
	int win = 0;
	int lose = 0;
	int num = 1;

	printf("ゲームを始めますか？\n");
	printf("\t1:はい\n");
	printf("\t2:いいえ\n");

	scanf_s("%d", &game);

	while (game == 1) {

		printf("%d回目\n", num);
			printf("何を出すか選んでください\n");
			printf("\t1:グー\n");
			printf("\t2:チョキ\n");
			printf("\t3:パー\n");
			printf("\t9:終了\n");
			printf("\t0:ヘルプ\n");

			scanf_s("%d", &a);
			b = rand() % 3 + 1;

			if (a == 1) {

				if (b == 1) {
					printf("draw\n");
				}
				else if (b == 2) {
					printf("win\n");
					lose = lose + 1;
				}
				else {
					printf("lose\n");
					lose = lose + 1;
				}
				num += 1;
			}
			else if (a == 2) {

				if (b == 1) {
					printf("lose\n");
					lose = lose + 1;
				}
				else if (b == 2) {
					printf("draw\n");
				}
				else {
					printf("win\n");
					lose = lose + 1;
				}
				num += 1;
			}
			else if (a == 3) {
				if (b == 1) {
					printf("win\n");
					lose = lose + 1;
				}
				else if (b == 2) {
					printf("lose\n");
					lose = lose + 1;
				}
				else {
					printf("draw\n");
				}
				num += 1;
			}
			else if(a == 9){
				printf("%d勝%d敗です\n", win, lose);
				return 0;
			}
			else if (a == 0){
				printf("じゃんけんのルール\nグーよりパー、パーよりチョキ、チョキよりグーが強い");
			}

			else {
				printf("もう一度入力してください\n");
			}
		
	}
	return 0;
}*/

//迷走
/*int main() {
	//srand(time(NULL));
	int a = 0; //自分
	int b;    //機械
	int game = 1;
	int win = 0;
	int lose = 0;
	int num = 1; //じゃんけんをした回数
	int judge;

	int janken[2][3] = { {1, 2, 3 },
						{3, 2, 1} };


	printf("ゲームを始めますか？\n");
	printf("\t1:はい\n");
	printf("\t2:いいえ\n");

	scanf_s("%d", &game);

	while (game == 1) {

		printf("%d回目\n", num);
		printf("何を出すか選んでください\n");
		printf("\t1:グー\n");
		printf("\t2:チョキ\n");
		printf("\t3:パー\n");
		printf("\t9:終了\n");
		printf("\t0:ヘルプ\n");

		scanf_s("%d\n", &a);
		b = rand() % 3 + 1;
		printf("%d\n", b);

		if (a == 0) {
			printf("じゃんけんのルール\nグーよりパー、パーよりチョキ、チョキよりグーが強い");
		}
		else if (a == 9) {
			printf("%d勝%d敗です\n", win, lose);
			break;
		}
		else if (a == 1){

			judge = (janken[0][a - 1] + janken[1][b - 1]) % 3;

			switch (judge) {
			case 0:
				printf("win\n");
				win = win + 1;
			case 1:
				printf("draw\n");
			case 2:
				printf("lose\n");
				lose = lose + 1;
			}
			num += 1;
		}
		else {
			printf("もう一度入力してください\n");
		}
	}
}*/
static int a;/*1:グー2:チョキ3:パー9:終了 */
static int b;
static int win;
static int lose;

int sub();
int makeb();
void judge(int a, int b);

int main() {
	int game = 1;
	printf("ゲームを始めますか？\n");
	printf("\t1:はい\n");
	printf("\t2:いいえ\n");

	scanf_s("%d", &game);

	while (game == 1) {

		a = sub();
		if (a >= 1 && a <= 3) {
			b = makeb();
			judge(a, b);
		}
		else if (a == 9) {
			printf("%d勝%d敗\n", win, lose);
			game = 0;
		}
		else if (a == 0) {
			printf("じゃんけんのルール: グーよりパー、パーよりチョキ、チョキよりグーが強い\n");
		}
		else {
			printf("もう一度入力してください\n");
		}
		
	}
	if (game == 0) {
	
	}
	return 0;
}

//出す手を入力する
int sub() {
	
	printf("何を出すか選んでください\n");
	printf("\t1:グー\n");
	printf("\t2:チョキ\n");
	printf("\t3:パー\n");
	printf("\t9:終了\n");
	printf("\t0:ヘルプ\n");

	scanf_s("%d", &a);

		return a;
	}

int makeb() {
	b = rand() % 3 + 1;
	if (b == 1) {
		printf("グー\n");
	}
	else if (b == 2) {
		printf("チョキ\n");
	}
	else {
		printf("パー\n");
	}

	return b;
}

void judge(int a, int b) {


	int janken[3][3] = { { 1, 0, 2 },
						{ 2, 1, 0 },
						{ 0, 2, 1 } };

	
	switch (janken[a - 1][b - 1]) {
	case 0:
		printf("win\n");
		win = win + 1;
		break;
	case 1:
		printf("draw\n");
		break;
	case 2:
		printf("lose\n");
		lose = lose + 1;
		break;
	default:
		break;
	}

}