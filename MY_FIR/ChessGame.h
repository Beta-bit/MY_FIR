#pragma once

//��ʾ����λ��
struct ChessPos {
	int row;
	int col;
};

typedef enum {
	CHESS_WHITE = -1,  //����
	CHESS_BLACK = 1
}chess_kind_t;

class ChessGame
{
public:
	void chessDown(ChessPos* pos, chess_kind_t kind);
	bool clickBoard(int x, int y, ChessPos *pos);
	void init();   //��ʼ��
	int gerGradeSize();  //��ȡ���̴�С��13�� 15�� 19��
	bool checkOver(); //�������Ƿ����
};

