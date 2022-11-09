#include "Man.h"

void Man::init(Chess* chess)
{
	this->chess = chess;
}

void Man::go()
{
	MOUSEMSG msg;
	ChessPos pos;
	//获取鼠标点击消息
	msg = GetMouseMsg();

	while (1) {
		//通过chess对象，来调用，判断落子是否有效，以及落子功能
		if (msg.uMsg == WM_LBUTTONDOWN && chess->clickBoard(msg.x, msg.y, &pos)) {
			break;
		}
	}

	//落子
	chess->chessDown(&pos, CHESS_BLACK);
}
