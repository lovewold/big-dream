#pragma once
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROW1 ROW+2
#define COL1 COL+2
#define lei1 10

//���̳�ʼ��
void initboard(char board[ROW1][COL1], int row1, int col1, char set);

//��ӡ����
void printboard(char board[ROW1][COL1], int row, int col);

//������
void lei(char board[ROW1][COL1]);

//����
void playboard(char mine[ROW1][COL1], char show[ROW1][COL1],int i,int j);
//�Ƿ��������

void findboard(char show[ROW1][COL1]);

void pailei(char mine[ROW1][COL1], char show[ROW1][COL1], int x, int y);