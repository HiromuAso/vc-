#pragma once

//参照ライブラリ
#include <stdio.h>
#include <tchar.h>
#include <curses.h>
#include <stdlib.h>
#include <windows.h>
#include <cmath>

//マクロ定義
#define BUFFSIZE 1024 //最大バッファーサイズ
#define YEAR 12 //2001～2012年の12年
#define MONTH 12
#define DAYS 365+1		// 要素数=365+1(１年間+うるう年)

//関数プロトタイプ宣言
float round_n(float number, double n);
bool CSV2Array(const char* a_filename, double a_data[DAYS]);
bool Array2CSV(const char* a_filename, double a_mdata[YEAR][MONTH], int month);
bool convDay2Month2(double a_data[DAYS], double a_mdata[YEAR][MONTH], int a_days[12], int year);
bool GetDaysPerMonth(const char* a_filename, int a_days[12]);
bool draw_graph(const char* a_filename);
void draw_Graphtemplate();