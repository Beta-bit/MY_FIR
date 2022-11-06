#pragma once
#include "Man.h"
#include "AI.h"
#include "Chess.h"

class ChessGame
{
public:
	ChessGame(Man* man, AI* ai, Chess* chess);
	void play();  //开始

	//添加数据成员
private:
	Man* man;
	AI* ai;
	Chess* chess;
};

