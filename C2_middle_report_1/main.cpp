#include "stdafx.h"

int main()
{
	//�ǂ̃p�X�̂ǂ̃t�@�C����,�������������ݒ�
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

	// �J�����g�f�B���N�g���̎擾
	char s_currentDir[_MAX_PATH];
	GetCurrentDirectory(sizeof(s_currentDir), s_currentDir);

	// �t�@�C���p�X�̍쐬(ini�t�@�C������ǂݍ���)
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
		MessageBox(NULL, _T("ini�t�@�C������t�@�C���p�X���ǂݍ��߂܂���ł����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}

	double d_data[DAYS]; // 1�N�Ԃ̍ō��C���f�[�^�i�[�z��
	double d_mdata[YEAR][MONTH]; //20XX�N,Y���̍ō��C�����i�[

	// ���P�ʂ̓��������߂�
	int days1[12];
	// 2001�N�̂P�N�Ԃ̋C���f�[�^���擾����
	if (CSV2Array(s_inputdata1, d_data) == false)
	{
		MessageBox(NULL, _T("2001�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata1, days1);
	// ���P�ʂ̍ō��C���f�[�^�����P�ʂ̕��ύō��C���ɕϊ�����
	convDay2Month2(d_data, d_mdata, days1, 1);

	//�ȉ�����
	int days2[12];
	if (CSV2Array(s_inputdata2, d_data) == false)
	{
		MessageBox(NULL, _T("2002�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata2, days2);
	convDay2Month2(d_data, d_mdata, days2, 2);

	int days3[12];
	if (CSV2Array(s_inputdata3, d_data) == false)
	{
		MessageBox(NULL, _T("2003�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata3, days3);
	convDay2Month2(d_data, d_mdata, days3, 3);

	int days4[12];	
	if (CSV2Array(s_inputdata4, d_data) == false)
	{
		MessageBox(NULL, _T("2004�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata4, days4);
	convDay2Month2(d_data, d_mdata, days4, 4);

	int days5[12];
	if (CSV2Array(s_inputdata5, d_data) == false)
	{
		MessageBox(NULL, _T("2005�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata5, days5);
	convDay2Month2(d_data, d_mdata, days5, 5);

	int days6[12];
	if (CSV2Array(s_inputdata6, d_data) == false)
	{
		MessageBox(NULL, _T("2006�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata6, days6);
	convDay2Month2(d_data, d_mdata, days6, 6);

	int days7[12];
	if (CSV2Array(s_inputdata7, d_data) == false)
	{
		MessageBox(NULL, _T("2007�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata7, days7);
	convDay2Month2(d_data, d_mdata, days7, 7); 

	int days8[12];
	if (CSV2Array(s_inputdata8, d_data) == false)
	{
		MessageBox(NULL, _T("2008�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata8, days8);
	convDay2Month2(d_data, d_mdata, days8, 8);

	int days9[12];
	if (CSV2Array(s_inputdata9, d_data) == false)
	{
		MessageBox(NULL, _T("2009�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata9, days9);
	convDay2Month2(d_data, d_mdata, days9, 9);

	int days10[12];
	if (CSV2Array(s_inputdata10, d_data) == false)
	{
		MessageBox(NULL, _T("2010�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata10, days10);
	convDay2Month2(d_data, d_mdata, days10, 10);

	int days11[12];
	if (CSV2Array(s_inputdata11, d_data) == false)
	{
		MessageBox(NULL, _T("2011�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata11, days11);
	convDay2Month2(d_data, d_mdata, days11, 11);

	int days12[12];
	if (CSV2Array(s_inputdata12, d_data) == false)
	{
		MessageBox(NULL, _T("2012�N�̂P�N�Ԃ̋C���f�[�^�ǂݍ��݂Ɏ��s���܂����B"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}
	GetDaysPerMonth(s_inputdata12, days12);
	convDay2Month2(d_data, d_mdata, days12, 12);

	//�[������J�n
	initscr();
	//�J�[�\�����\��
	curs_set(0);
	//�L�[���������炷���ɂ��̕������v���O��������ǂݎ���悤�ɂ���
	cbreak();
	//���͂����L�[����ʂɕ\�����Ȃ��悤�ɂ���
	noecho();
	//���L�[��t�@���N�V�����L�[�Ȃǂ̓���L�[�𗘗p�\�ɂ���
	keypad(stdscr, TRUE);

	//�ŏ���1���̕��ύō��C����`��
	draw_Graphtemplate();
	mvaddstr(1, 25, "1��");
	Array2CSV(s_outputdata, d_mdata, 1);
	draw_graph(s_outputdata);

	int cnt_month = 1;

	//���L�[�ɉ�����,�\�����錎��ς���
	while (TRUE)
	{
		int key = getch(); //�������͎�t

		if (key == KEY_RIGHT)
		{
			erase(); //��ʏ���(���Z�b�g)
			draw_Graphtemplate();
			cnt_month++;
			if (cnt_month > 12)
			{
				cnt_month = 1; //12�̎���1
			}
		}

		if (key == KEY_LEFT)
		{
			erase();
			draw_Graphtemplate();
			cnt_month--;
			if (cnt_month < 1)
			{
				cnt_month = 12; //1�̑O��12
			}
		}

		if (key == KEY_DOWN) break; // �I��

		//���L�[�ɉ����ĕ\�����錎��؂�ւ�
		switch(cnt_month)
		{
			case 1:
				mvaddstr(1, 25, "1��");
				Array2CSV(s_outputdata, d_mdata, 1);
				draw_graph(s_outputdata);
				break;
			case 2:
				mvaddstr(1, 25, "2��");
				Array2CSV(s_outputdata, d_mdata, 2);
				draw_graph(s_outputdata);
				break;
			case 3:
				mvaddstr(1, 25, "3��");
				Array2CSV(s_outputdata, d_mdata, 3);
				draw_graph(s_outputdata);
				break;
			case 4:
				mvaddstr(1, 25, "4��");
				Array2CSV(s_outputdata, d_mdata, 4);
				draw_graph(s_outputdata);
				break;
			case 5:
				mvaddstr(1, 25, "5��");
				Array2CSV(s_outputdata, d_mdata, 5);
				draw_graph(s_outputdata);
				break;
			case 6:
				mvaddstr(1, 25, "6��");
				Array2CSV(s_outputdata, d_mdata, 6);
				draw_graph(s_outputdata);
				break;
			case 7:
				mvaddstr(1, 25, "7��");
				Array2CSV(s_outputdata, d_mdata, 7);
				draw_graph(s_outputdata);
				break;
			case 8:
				mvaddstr(1, 25, "8��");
				Array2CSV(s_outputdata, d_mdata, 8);
				draw_graph(s_outputdata);
				break;
			case 9:
				mvaddstr(1, 25, "9��");
				Array2CSV(s_outputdata, d_mdata, 9);
				draw_graph(s_outputdata);
				break;
			case 10:
				mvaddstr(1, 24, "10��");
				Array2CSV(s_outputdata, d_mdata, 10);
				draw_graph(s_outputdata);
				break;
			case 11:
				mvaddstr(1, 24, "11��");
				Array2CSV(s_outputdata, d_mdata, 11);
				draw_graph(s_outputdata);
				break;
			case 12:
				mvaddstr(1, 24, "12��");
				Array2CSV(s_outputdata, d_mdata, 12);
				draw_graph(s_outputdata);
				break;
			}
	}

	endwin(); //curses���I��

	return 0;
}