#pragma once

//表示落子位置
struct ChessPos {
	int row;
	int col;
};

typedef enum {
	CHESS_WHITE = -1,  //白棋
	CHESS_BLACK = 1
}chess_kind_t;

class ChessGame
{
public:
	void chessDown(ChessPos* pos, chess_kind_t kind);
	bool clickBoard(int x, int y, ChessPos *pos);
	void init();   //初始化
	int gerGradeSize();  //获取棋盘大小（13， 15， 19）
	bool checkOver(); //检查棋局是否结束
};

