#pragma once
//��������
#define ROW 3
#define COL 3

#include <stdlib.h>
#include<time.h>
#include<stdio.h>
//���̳�ʼ��
void real(char arr[ROW][COL],int row,int col);
//��ӡ����
void Printf_board(char board[ROW][COL]);
//�������
void playergame(char board[ROW][COL]);
//��������
void computer(char board[ROW][COL]);
//��Ӯ�ж�
char is_win(char board[ROW][COL]);
char full_board(char board[ROW][COL]);
void game();
