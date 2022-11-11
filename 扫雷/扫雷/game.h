#pragma once
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROW1 ROW+2
#define COL1 COL+2
#define lei1 10

//棋盘初始化
void initboard(char board[ROW1][COL1], int row1, int col1, char set);

//打印棋盘
void printboard(char board[ROW1][COL1], int row, int col);

//生成雷
void lei(char board[ROW1][COL1]);

//排雷
void playboard(char mine[ROW1][COL1], char show[ROW1][COL1],int i,int j);
//是否排完诊断

void findboard(char show[ROW1][COL1]);

void pailei(char mine[ROW1][COL1], char show[ROW1][COL1], int x, int y);