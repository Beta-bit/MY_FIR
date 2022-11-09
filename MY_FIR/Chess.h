#pragma once
#include <graphics.h>
#include <vector>

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
	Chess(int gradeSize, int margin_x, int margin_y, float chessSize);
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

private:
	IMAGE chessBlackImg;  //黑子
	IMAGE chessWhiteImg;  //白子

	int gradeSize;   //棋盘的大小
	int margin_x;    //棋盘的左边界大小
	int margin_y;    //棋盘的上边界大小
	float chessSize; //棋子的大小（棋盘一格的大小）

	//存储当前棋局的棋子分布数据0：空白 1：黑子 -1：白字
	//从零开始行列表示
	std::vector < std::vector<int> > chessMap;

	//表示下棋方
	bool playerFlag;  //true:表示黑子走
};

