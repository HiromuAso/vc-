#include "stdafx.h"

int main()
{
	//どのパスのどのファイルか,を示す文字列を設定
	char s_inputdata1[_MAX_PATH];
	char s_inputdata2[_MAX_PATH];
	char s_inputdata3[_MAX_PATH];
	char s_inputdata4[_MAX_PATH];
	char s_inputdata5[_MAX_PATH];
	char s_inputdata6[_MAX_PATH];
	char s_inputdata7[_MAX_PATH];
	char s_inputdata8[_MAX_PATH];
	char s_inputdata9[_MAX_PATH];
	char s_inputdata10[_MAX_PATH];
	char s_inputdata11[_MAX_PATH];
	char s_inputdata12[_MAX_PATH];
	char s_outputdata[_MAX_PATH];

	// カレントディレクトリの取得
	char s_currentDir[_MAX_PATH];
	GetCurrentDirectory(sizeof(s_currentDir), s_currentDir);

	// ファイルパスの作成(iniファイルから読み込み)
	char s_inifile[_MAX_PATH];
	sprintf_s(s_inifile, "%s\\C2_middle_report_1.ini", s_currentDir);
	DWORD nRet2001 = GetPrivateProfileString("filepath", "readfile_2001", "", s_inputdata1, _MAX_PATH, s_inifile);
	DWORD nRet2002 = GetPrivateProfileString("filepath", "readfile_2002", "", s_inputdata2, _MAX_PATH, s_inifile);
	DWORD nRet2003 = GetPrivateProfileString("filepath", "readfile_2003", "", s_inputdata3, _MAX_PATH, s_inifile);
	DWORD nRet2004 = GetPrivateProfileString("filepath", "readfile_2004", "", s_inputdata4, _MAX_PATH, s_inifile);
	DWORD nRet2005 = GetPrivateProfileString("filepath", "readfile_2005", "", s_inputdata5, _MAX_PATH, s_inifile);
	DWORD nRet2006 = GetPrivateProfileString("filepath", "readfile_2006", "", s_inputdata6, _MAX_PATH, s_inifile);
	DWORD nRet2007 = GetPrivateProfileString("filepath", "readfile_2007", "", s_inputdata7, _MAX_PATH, s_inifile);
	DWORD nRet2008 = GetPrivateProfileString("filepath", "readfile_2008", "", s_inputdata8, _MAX_PATH, s_inifile);
	DWORD nRet2009 = GetPrivateProfileString("filepath", "readfile_2009", "", s_inputdata9, _MAX_PATH, s_inifile);
	DWORD nRet2010 = GetPrivateProfileString("filepath", "readfile_2010", "", s_inputdata10, _MAX_PATH, s_inifile);
	DWORD nRet2011 = GetPrivateProfileString("filepath", "readfile_2011", "", s_inputdata11, _MAX_PATH, s_inifile);
	DWORD nRet2012 = GetPrivateProfileString("filepath", "readfile_2012", "", s_inputdata12, _MAX_PATH, s_inifile);
	DWORD nRet_write = GetPrivateProfileString("filepath", "writefile", "", s_outputdata, _MAX_PATH, s_inifile);

	if (nRet2001<=0 || nRet2002<=0 || nRet2003<=0 || nRet2004<=0 || nRet2005<=0 || nRet2006<=0 
		|| nRet2007<=0 || nRet2008<=0 || nRet2009<=0 || nRet2010<=0 || nRet2011<=0 || nRet2012<=0)
	{
		MessageBox(NULL, _T("iniファイルからファイルパスが読み込めませんでした。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}

	double d_data[DAYS]; // 1年間の最高気温データ格納配列
	double d_mdata[YEAR][MONTH]; //20XX年,Y月の最高気温を格納

	// 月単位の日数を求める
	int days1[12];
	// 2001年の１年間の気温データを取得する
	if (CSV2Array(s_inputdata1, d_data) == false)
	{
		MessageBox(NULL, _T("2001年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata1, days1);
	// 日単位の最高気温データを月単位の平均最高気温に変換する
	convDay2Month2(d_data, d_mdata, days1, 1);

	//以下同文
	int days2[12];
	if (CSV2Array(s_inputdata2, d_data) == false)
	{
		MessageBox(NULL, _T("2002年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata2, days2);
	convDay2Month2(d_data, d_mdata, days2, 2);

	int days3[12];
	if (CSV2Array(s_inputdata3, d_data) == false)
	{
		MessageBox(NULL, _T("2003年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata3, days3);
	convDay2Month2(d_data, d_mdata, days3, 3);

	int days4[12];	
	if (CSV2Array(s_inputdata4, d_data) == false)
	{
		MessageBox(NULL, _T("2004年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata4, days4);
	convDay2Month2(d_data, d_mdata, days4, 4);

	int days5[12];
	if (CSV2Array(s_inputdata5, d_data) == false)
	{
		MessageBox(NULL, _T("2005年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata5, days5);
	convDay2Month2(d_data, d_mdata, days5, 5);

	int days6[12];
	if (CSV2Array(s_inputdata6, d_data) == false)
	{
		MessageBox(NULL, _T("2006年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata6, days6);
	convDay2Month2(d_data, d_mdata, days6, 6);

	int days7[12];
	if (CSV2Array(s_inputdata7, d_data) == false)
	{
		MessageBox(NULL, _T("2007年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata7, days7);
	convDay2Month2(d_data, d_mdata, days7, 7); 

	int days8[12];
	if (CSV2Array(s_inputdata8, d_data) == false)
	{
		MessageBox(NULL, _T("2008年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata8, days8);
	convDay2Month2(d_data, d_mdata, days8, 8);

	int days9[12];
	if (CSV2Array(s_inputdata9, d_data) == false)
	{
		MessageBox(NULL, _T("2009年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata9, days9);
	convDay2Month2(d_data, d_mdata, days9, 9);

	int days10[12];
	if (CSV2Array(s_inputdata10, d_data) == false)
	{
		MessageBox(NULL, _T("2010年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata10, days10);
	convDay2Month2(d_data, d_mdata, days10, 10);

	int days11[12];
	if (CSV2Array(s_inputdata11, d_data) == false)
	{
		MessageBox(NULL, _T("2011年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata11, days11);
	convDay2Month2(d_data, d_mdata, days11, 11);

	int days12[12];
	if (CSV2Array(s_inputdata12, d_data) == false)
	{
		MessageBox(NULL, _T("2012年の１年間の気温データ読み込みに失敗しました。"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata12, days12);
	convDay2Month2(d_data, d_mdata, days12, 12);

	//端末制御開始
	initscr();
	//カーソルを非表示
	curs_set(0);
	//キーを押したらすぐにその文字がプログラムから読み取れるようにする
	cbreak();
	//入力したキーを画面に表示しないようにする
	noecho();
	//矢印キーやファンクションキーなどの特殊キーを利用可能にする
	keypad(stdscr, TRUE);

	//最初は1月の平均最高気温を描画
	draw_Graphtemplate();
	mvaddstr(1, 25, "1月");
	Array2CSV(s_outputdata, d_mdata, 1);
	draw_graph(s_outputdata);

	int cnt_month = 1;

	//矢印キーに応じて,表示する月を変える
	while (TRUE)
	{
		int key = getch(); //文字入力受付

		if (key == KEY_RIGHT)
		{
			erase(); //画面消去(リセット)
			draw_Graphtemplate();
			cnt_month++;
			if (cnt_month > 12)
			{
				cnt_month = 1; //12の次は1
			}
		}

		if (key == KEY_LEFT)
		{
			erase();
			draw_Graphtemplate();
			cnt_month--;
			if (cnt_month < 1)
			{
				cnt_month = 12; //1の前は12
			}
		}

		if (key == KEY_DOWN) break; // 終了

		//矢印キーに応じて表示する月を切り替え
		switch(cnt_month)
		{
			case 1:
				mvaddstr(1, 25, "1月");
				Array2CSV(s_outputdata, d_mdata, 1);
				draw_graph(s_outputdata);
				break;
			case 2:
				mvaddstr(1, 25, "2月");
				Array2CSV(s_outputdata, d_mdata, 2);
				draw_graph(s_outputdata);
				break;
			case 3:
				mvaddstr(1, 25, "3月");
				Array2CSV(s_outputdata, d_mdata, 3);
				draw_graph(s_outputdata);
				break;
			case 4:
				mvaddstr(1, 25, "4月");
				Array2CSV(s_outputdata, d_mdata, 4);
				draw_graph(s_outputdata);
				break;
			case 5:
				mvaddstr(1, 25, "5月");
				Array2CSV(s_outputdata, d_mdata, 5);
				draw_graph(s_outputdata);
				break;
			case 6:
				mvaddstr(1, 25, "6月");
				Array2CSV(s_outputdata, d_mdata, 6);
				draw_graph(s_outputdata);
				break;
			case 7:
				mvaddstr(1, 25, "7月");
				Array2CSV(s_outputdata, d_mdata, 7);
				draw_graph(s_outputdata);
				break;
			case 8:
				mvaddstr(1, 25, "8月");
				Array2CSV(s_outputdata, d_mdata, 8);
				draw_graph(s_outputdata);
				break;
			case 9:
				mvaddstr(1, 25, "9月");
				Array2CSV(s_outputdata, d_mdata, 9);
				draw_graph(s_outputdata);
				break;
			case 10:
				mvaddstr(1, 24, "10月");
				Array2CSV(s_outputdata, d_mdata, 10);
				draw_graph(s_outputdata);
				break;
			case 11:
				mvaddstr(1, 24, "11月");
				Array2CSV(s_outputdata, d_mdata, 11);
				draw_graph(s_outputdata);
				break;
			case 12:
				mvaddstr(1, 24, "12月");
				Array2CSV(s_outputdata, d_mdata, 12);
				draw_graph(s_outputdata);
				break;
			}
	}

	endwin(); //cursesを終了

	return 0;
}