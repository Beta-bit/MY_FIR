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

class Chess
{
public:
	void init();   //初始化

	//判断指定坐标（x,y)位置，是否有效点击
	//如果有效点击，把有效位置（行，列）保存在参数pos中
	bool clickBoard(int x, int y, ChessPos* pos);
	
	//在棋盘的指定位置（pos），落子（kind）
	void chessDown(ChessPos* pos, chess_kind_t kind);

	//获取棋盘大小（13， 15， 19）
	int gerGradeSize(); 

	//获取指定位置是黑棋，还是白棋，还是空白
	int getChessDate(ChessPos* pos);
	int getChessDate(int row, int col);
	
	bool checkOver(); //检查棋局是否结束
};

