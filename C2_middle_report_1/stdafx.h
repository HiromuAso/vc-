#pragma once

//�Q�ƃ��C�u����
#include <stdio.h>
#include <tchar.h>
#include <curses.h>
#include <stdlib.h>
#include <windows.h>
#include <cmath>

//�}�N����`
#define BUFFSIZE 1024 //�ő�o�b�t�@�[�T�C�Y
#define YEAR 12 //2001�`2012�N��12�N
#define MONTH 12
#define DAYS 365+1		// �v�f��=365+1(�P�N��+���邤�N)

//�֐��v���g�^�C�v�錾
float round_n(float number, double n);
bool CSV2Array(const char* a_filename, double a_data[DAYS]);
bool Array2CSV(const char* a_filename, double a_mdata[YEAR][MONTH], int month);
bool convDay2Month2(double a_data[DAYS], double a_mdata[YEAR][MONTH], int a_days[12], int year);
bool GetDaysPerMonth(const char* a_filename, int a_days[12]);
bool draw_graph(const char* a_filename);
void draw_Graphtemplate();