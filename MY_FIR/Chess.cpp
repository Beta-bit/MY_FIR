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
    //创建游戏窗口
    initgraph(897, 895);

    //显示棋盘图片
    loadimage(0, "../res/棋盘2.jpg");
    //播放开始提示音
    mciSendString("play ../res/start.wav", 0, 0, 0);

    //加载棋子的图片
    loadimage(&chessBlackImg, "../res/black.png", chessSize, chessSize, true);
    loadimage(&chessWhiteImg, "../res/white.png", chessSize, chessSize, true);

    //棋盘清零
    for (int i = 0; i < gradeSize; i++) {
        for (int j = 0; j < gradeSize; j++) {
            chessMap[i][j] = 0;
        }
    }

    playerFlag = true;
}

bool Chess::clickBoard(int x, int y, ChessPos* pos)
{
    return false;
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
