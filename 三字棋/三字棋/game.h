#pragma once
//函数声明
#define ROW 3
#define COL 3

#include <stdlib.h>
#include<time.h>
#include<stdio.h>
//棋盘初始化
void real(char arr[ROW][COL],int row,int col);
//打印棋盘
void Printf_board(char board[ROW][COL]);
//玩家下棋
void playergame(char board[ROW][COL]);
//电脑下棋
void computer(char board[ROW][COL]);
//输赢判断
char is_win(char board[ROW][COL]);
char full_board(char board[ROW][COL]);
void game();
