// ConsoleApplication12.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>


static int me; //自分が出す手の数字をいれる変数
static int pc; //相手が出す手の数字をいれる変数
static int win;//勝った数を数える変数
static int lose;//負けた数を入れる変数

int player1();
int player2();
void judge(int me, int pc);

int main() {
	int game = 1; //ゲームを始めるかどうかの判定
	printf("ゲームを始めますか？\n");
	printf("\t1:はい\n");
	printf("\t2:いいえ\n");

	scanf_s("%d", &game);

	while (game == 1) {//最初に「はい」を選ぶとgame = 1となり、"9:終了"を押すまでじゃんけんをする

		me =player1();
		if (me >= 1 && me <= 3) {//グーチョキパーどれかが選択されたとき、pcから手が返ってきて勝敗判定をさせる
			pc = player2();
			judge(me, pc);
		}
		else if (me == 9) {
			printf("%d勝%d敗\n", win, lose);
			game = 0;//while文から抜け、ゲームを終了させる
		}
		else if (me == 0) {
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
int player1() {
	
	printf("何を出すか選んでください\n");
	printf("\t1:グー\n");
	printf("\t2:チョキ\n");
	printf("\t3:パー\n");
	printf("\t9:終了\n");
	printf("\t0:ヘルプ\n");

	scanf_s("%d", &me);

		return me;
}

//相手の手の数を出す
int player2() {
	pc = rand() % 3 + 1;//1から3までの乱数を生成し、pcの出した手を出力
	if (pc == 1) {
		printf("グー\n");//自分の手と同様に、1：グー　2:チョキ　3:パー　とする
	}
	else if (pc == 2) {
		printf("チョキ\n");
	}
	else {
		printf("パー\n");
	}

	return pc;
}


//勝敗判定
void judge(int me, int pc) {

	/*勝ち負けを数字で以下のように定義する
	meの出した手の勝ち：0　負け：2　あいこ：1
	出す手の組み合わせは　3×3=9　通りあるので二次元配列に
	判定の数字を入れる*/

	int janken[3][3] = { { 1, 0, 2 },
						{ 2, 1, 0 },
						{ 0, 2, 1 } };

	
	switch (janken[me - 1][pc - 1]) {//ex)me = 1(グー), pc = 1(グー)のとき、janken[0][0]を見るとあいこを表す1があるためdraw
	case 0:
		printf("win\n");
		win = win + 1; //勝った数をカウント
		break;
	case 1:
		printf("draw\n");
		break;
	case 2:
		printf("lose\n");
		lose = lose + 1;//負けた数をカウント
		break;
	default:
		break;
	}

}