#include "Man.h"

void Man::init(Chess* chess)
{
	this->chess = chess;
}

void Man::go()
{
	MOUSEMSG msg;
	ChessPos pos;
	//��ȡ�������Ϣ
	msg = GetMouseMsg();

	while (1) {
		//ͨ��chess���������ã��ж������Ƿ���Ч���Լ����ӹ���
		if (msg.uMsg == WM_LBUTTONDOWN && chess->clickBoard(msg.x, msg.y, &pos)) {
			break;
		}
	}

	//����
	chess->chessDown(&pos, CHESS_BLACK);
}
