#include <cmath>
#include "Chess.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

Chess::Chess(int gradeSize, int margin_x, int margin_y, float chessSize)
{
    this->gradeSize = gradeSize;
    this->margin_x = margin_x;
    this->margin_y = margin_y;
    this->chessSize = chessSize;
    playerFlag = CHESS_BLACK;

    for (int i = 0; i < gradeSize; i++) {
        std::vector<int> row;
        for (int j = 0; j < gradeSize; j++) {
            row.push_back(0);
        }
        chessMap.push_back(row);
    }
}

void Chess::init()
{
    //������Ϸ����
    initgraph(897, 895);

    //��ʾ����ͼƬ
    loadimage(0, "../res/����2.jpg");
    //���ſ�ʼ��ʾ��
    mciSendString("play ../res/start.wav", 0, 0, 0);

    //�������ӵ�ͼƬ
    loadimage(&chessBlackImg, "../res/black.png", chessSize, chessSize, true);
    loadimage(&chessWhiteImg, "../res/white.png", chessSize, chessSize, true);

    //��������
    for (int i = 0; i < gradeSize; i++) {
        for (int j = 0; j < gradeSize; j++) {
            chessMap[i][j] = 0;
        }
    }

    playerFlag = true;
}

bool Chess::clickBoard(int x, int y, ChessPos* pos)
{
    int col = (x - margin_x) / chessSize;
    int row = (y - margin_y) / chessSize;
    int leftTopPosX = margin_x + chessSize * col;
    int leftTopPosY = margin_y + chessSize * row;
    int offset = chessSize * 0.4;  //ƫ����

    int len;
    bool ret = true;

    do {
        //�ж��Ƿ������Ͻ�
        len = sqrt(pow((x - leftTopPosX), 2) + pow((y - leftTopPosY), 2));
        if (len < offset) {
            pos->row = row;
            pos->col = col;
            if (chessMap[pos->row][pos->col] == 0) {
                ret = true;
            }
            break;
        }

        //���Ͻ��ж�
        int x2 = leftTopPosX + chessSize;
        int y2 = leftTopPosY;
        len = sqrt(pow((x - x2), 2) + pow((y - y2), 2));
        if (len < offset) {
            pos->row = row;
            pos->col = col + 1;
            if (chessMap[pos->row][pos->col] == 0) {
                ret = true;
            }
            break;
        }

        //���½��ж�
        x2 = leftTopPosX;
        y2 = leftTopPosY + chessSize;
        len = sqrt(pow((x - x2), 2) + pow((y - y2), 2));
        if (len < offset) {
            pos->row = row + 1;
            pos->col = col;
            if (chessMap[pos->row][pos->col] == 0) {
                ret = true;
            }
            break;
        }

        //���½��ж�
        x2 = leftTopPosX + chessSize;
        y2 = leftTopPosY + chessSize;
        len = sqrt(pow((x - x2), 2) + pow((y - y2), 2));
        if (len < offset) {
            pos->row = row + 1;
            pos->col = col + 1;
            if (chessMap[pos->row][pos->col] == 0) {
                ret = true;
            }
            break;
        }
    } while (0);

    return ret;
}

void Chess::chessDown(ChessPos* pos, chess_kind_t kind)
{
}

int Chess::gerGradeSize()
{
    return 0;
}

int Chess::getChessDate(ChessPos* pos)
{
    return 0;
}

int Chess::getChessDate(int row, int col)
{
    return 0;
}

bool Chess::checkOver()
{
    return false;
}
