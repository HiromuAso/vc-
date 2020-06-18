#include "stdafx.h"

// ファイルから１年間の気温データを配列に返す
bool CSV2Array(const char* a_filename, double a_data[DAYS])
{
	int n_day = 0;
	FILE* fp;
	char buf[BUFFSIZE];

	errno_t error = fopen_s(&fp, a_filename, "r");
	if (error != 0)  return false;

	// 読み込み開始
	fgets(buf, BUFFSIZE, fp);  // 先頭行は説明のため読み捨て
	while (fgets(buf, BUFFSIZE, fp) != NULL)
	{
		char s_delim[] = ",";  // 区切り文字
		char* s;
		char* p_work = strtok_s(buf, s_delim, &s);  // 西暦
		p_work = strtok_s(NULL, s_delim, &s);  // 月
		p_work = strtok_s(NULL, s_delim, &s);  // 日付
		p_work = strtok_s(NULL, s_delim, &s); //最高気温
		
		// 最高気温を日単位で戻り値としての引数変数にセットしていく
		a_data[n_day] = atof(p_work);
		n_day++;  // 要素0～要素???=日単位
	}

	// ファイルクローズ
	fclose(fp);

	return true;
}

// 年単位の最高気温をCSVファイルに出力する
bool Array2CSV(const char* a_filename, double a_mdata[YEAR][MONTH], int month)
{
	FILE* fp;

	errno_t error = fopen_s(&fp, a_filename, "w");
	if (error != 0)  return false;

	for (int i = 0; i < 12; i++)
	{
		char s_buf[BUFFSIZE];
		sprintf_s(s_buf, "%d/%d,%lf\n", 2001+ i, month, a_mdata[i][month-1]);
		fputs(s_buf, fp);
	}

	// ファイルクローズ
	fclose(fp);

	return true;
}

//月々の日数を調べる
bool GetDaysPerMonth(const char* a_filename, int a_days[12])
{
	int n_day = 0;
	FILE* fp;
	char buf[BUFFSIZE];

	errno_t error = fopen_s(&fp, a_filename, "r");
	if (error != 0)  return false;

	int cnt_day = 0; //日数をカウント
	int current_month = 1; //月カウント

	// 読み込み開始
	fgets(buf, BUFFSIZE, fp);  // 先頭行は説明のため読み捨て
	while (fgets(buf, BUFFSIZE, fp) != NULL)
	{
		//20XX,3,12(例)の「3」だけを見る
		char s_delim[] = ",";  // 区切り文字
		char* s;
		char* p_work = strtok_s(buf, s_delim, &s);  // 西暦
		p_work = strtok_s(NULL, s_delim, &s); // 月

		//月が替わったら,その月の日数を確定させてcnt_dayをリセット
		if (atoi(p_work) != current_month)
		{
			a_days[current_month - 1] = cnt_day;
			current_month++;
			cnt_day = 0;
		}
		cnt_day++;

		//12月はラスト月のため,上記のif文には入れない. よって個別に日数(cnt_day)書き込む
		if (current_month == 12) a_days[current_month - 1] = cnt_day;
	}

	// ファイルクローズ
	fclose(fp);

	return true;
}

// 日単位の最高気温データを月単位の平均最高気温に変換する
bool convDay2Month2(double a_data[DAYS], double a_mdata[YEAR][MONTH], int a_daysPerMonth[12], int year)
{
	int cnt_day = 0;
	for (int i = 0; i < 12; i++)
	{
		double d_total = 0;
		for (int j = 0; j < a_daysPerMonth[i]; j++)
		{
			d_total += a_data[cnt_day];
			cnt_day++;
		}
		a_mdata[year-1][i] = d_total / a_daysPerMonth[i];  // 月単位の平均最高気温
	}
	return true;
}

//点グラフ形式で平均最高気温をグラフに起こす
bool draw_graph(const char* a_filename)
{
	FILE* fp;
	char buf[BUFFSIZE];
	double month[12];

	errno_t error = fopen_s(&fp, a_filename, "r");
	if (error != 0)  return false;

	// 端末の準備
	initscr();
	// 色の準備
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// 色1に「白地に黒文字」をセット
	attrset(COLOR_PAIR(1));			// 色1 を使う

	int n_month = 0;
	int count = 0;
	char s_delim[] = ",";  // 区切り文字
	char* s;

	//読み込み開始
	while (fgets(buf, BUFFSIZE, fp) != NULL)
	{
		// 説明の先頭行は読み飛ばし
		char* p_work = strtok_s(buf, s_delim, &s);
		//各月の最高気温
		p_work = strtok_s(NULL, s_delim, &s);
		if (p_work != NULL)
		{
			mvaddstr(21 - round_n(atof(p_work), 1) * 0.5, 8 + count, "●");
		}
		//次の月へx座標ポインタを移行
		count += 5;
	}

	//ファイルクローズ
	fclose(fp);
}

void draw_Graphtemplate()
{
	// 端末の準備
	initscr();
	// 色の準備
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// 色1に「白地に黒文字」をセット
	attrset(COLOR_PAIR(1));			// 色1 を使う

	//地域名表示
	mvaddstr(1, 17, "小松市");

	//グラフタイトル表示
	mvaddstr(1, 32, "<平均最高気温>");

	//グラフの横軸描画
	for (int i = 1; i < 18; i++)
	{
		mvaddstr(21 - i, 7, "|");
	}
	mvaddstr(20, 4, "2.0"); mvaddstr(11, 3, "20.0");
	mvaddstr(19, 4, "4.0"); mvaddstr(10, 3, "22.0");
	mvaddstr(18, 4, "6.0"); mvaddstr(9, 3, "24.0");
	mvaddstr(17, 4, "8.0"); mvaddstr(8, 3, "26.0");
	mvaddstr(16, 3, "10.0"); mvaddstr(7, 3, "28.0");
	mvaddstr(15, 3, "12.0"); mvaddstr(6, 3, "30.0");
	mvaddstr(14, 3, "14.0"); mvaddstr(5, 3, "32.0");
	mvaddstr(13, 3, "16.0"); mvaddstr(4, 3, "34.0");
	mvaddstr(12, 3, "18.0"); mvaddstr(3, 3, "(℃)");

	//グラフの縦軸描画
	for (int i = 0; i < 61; i++) {
		mvaddstr(21, 7 + i, "-");
	}
	mvaddstr(22, 8, "1    2    3    4    5    6    7    8    9    10   11   12");
	mvaddstr(22, 68, "(20XX年)");
}

/* 小数点n以下で四捨五入する関数 */
float round_n(float number, double n)
{
	number = number * pow(10, n - 1); //四捨五入したい値を10の(n-1)乗倍する。
	number = round(number); //小数点以下を四捨五入する。
	number /= pow(10, n - 1); //10の(n-1)乗で割る。
	return number;
}
