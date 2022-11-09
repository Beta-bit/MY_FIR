#pragma once
#include <graphics.h>
#include <vector>

//��ʾ����λ��
struct ChessPos {
	int row;
	int col;
};

typedef enum {
	CHESS_WHITE = -1,  //����
	CHESS_BLACK = 1
}chess_kind_t;

class Chess
{
public:
	Chess(int gradeSize, int margin_x, int margin_y, float chessSize);
	void init();   //��ʼ��

	//�ж�ָ�����꣨x,y)λ�ã��Ƿ���Ч���
	//�����Ч���������Чλ�ã��У��У������ڲ���pos��
	bool clickBoard(int x, int y, ChessPos* pos);
	
	//�����̵�ָ��λ�ã�pos�������ӣ�kind��
	void chessDown(ChessPos* pos, chess_kind_t kind);

	//��ȡ���̴�С��13�� 15�� 19��
	int gerGradeSize(); 

	//��ȡָ��λ���Ǻ��壬���ǰ��壬���ǿհ�
	int getChessDate(ChessPos* pos);
	int getChessDate(int row, int col);
	
	bool checkOver(); //�������Ƿ����

private:
	IMAGE chessBlackImg;  //����
	IMAGE chessWhiteImg;  //����

	int gradeSize;   //���̵Ĵ�С
	int margin_x;    //���̵���߽��С
	int margin_y;    //���̵��ϱ߽��С
	float chessSize; //���ӵĴ�С������һ��Ĵ�С��

	//�洢��ǰ��ֵ����ӷֲ�����0���հ� 1������ -1������
	//���㿪ʼ���б�ʾ
	std::vector < std::vector<int> > chessMap;

	//��ʾ���巽
	bool playerFlag;  //true:��ʾ������
};

