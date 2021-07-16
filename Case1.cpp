//========================CASE 1===================
const int MAX_LIST = 20;

void Clear_Data_Input()
{
	gotoxy(90, 4);
	printf("%s", "                     ");
	gotoxy(90, 6);
	printf("%s", "                     ");
}
void Draw_Frame_DSLop()
{
	Draw_Frame_Main(0, 0, X, Y, "QUAN LI LOP - THI TRAC NGHIEM");
	Draw_Frame(3, 3, 70, 22);
	Draw_H(3, 5, 70);
	Draw_I(28, 3, 22);
	gotoxy(28, 5);
	printf("%c", char(206));
	gotoxy(13, 4);
	printf("%s", "MA LOP");
	gotoxy(45, 4);
	printf("%s", "TEN LOP");
}
void Draw_Frame_DSLop_Input()
{
	Draw_Frame(75, 3, 40, 3);
	Draw_H(75, 5, 40);
	Draw_I(88, 3, 3);
	gotoxy(88, 5);
	printf("%c", char(206));
	gotoxy(77, 4);
	printf("%s", "MA LOP");
	gotoxy(77, 6);
	printf("%s", "TEN LOP");
}
void Add_Lop(DSLop &dsl)
{
	Normal_Text();
	Clear_Data_Input();
	Draw_Frame_DSLop_Input();
	int chon = 0;
	Lop lop;
	strcpy(lop.MALOP, "");
	strcpy(lop.TENLOP, "");
	do
	{
		gotoxy(90, 4 + chon * 2);
		if (wherey() == 4)
		{
			cout << lop.MALOP;
			char str[sizeof(lop.MALOP)] = "";
			strcpy(str, lop.MALOP);
			strcpy(lop.MALOP, Input_Str_Int(str, 90, 4 + chon * 2, sizeof(lop.MALOP) - 1));
		}
		else if (wherey() == 6)
		{
			cout << lop.TENLOP;
			char str[sizeof(lop.TENLOP)] = "";
			strcpy(str, lop.TENLOP);
			strcpy(lop.TENLOP, Input_Str_Int(str, 90, 4 + chon * 2, sizeof(lop.TENLOP) - 1));
		}
		int key = GetKey();
		switch (key)
		{
		case UP:
			if (chon > 0)
			{
				chon--;
			}
			break;
		case DOWN:
			if (chon + 1 < 2)
			{
				chon++;
			}
			break;
		case ENTER:
			if (chon + 1 < 2)
			{
				chon++;
			}
			break;
		case TAB:
			if (chon + 1 < 2)
			{
				chon++;
			}
			break;
		case CTRL_S:
			dsl.Add_Lop(lop);
			Save_DS_Lop_File(dsl);
			Read_DS_Lop_File(dsl);
			return;
		case ESC:
			return;
		}

	} while (1);
}
void Show_1_Lop(Lop *lop, int x, int y)
{
	gotoxy(x, y);
	printf("%s", lop->MALOP);
	gotoxy(x + 25, y);
	printf("%s", lop->TENLOP);
	Clear_Data_Input();
	gotoxy(90, 4);
	printf("%s", lop->MALOP);
	gotoxy(90, 6);
	printf("%s", lop->TENLOP);
}
void Clear_Data_DSLop()
{
	int x = 5, y = 6;
	Normal_Text();
	Lop lop;
	strcpy(lop.MALOP, "                   ");
	strcpy(lop.TENLOP, "                    ");
	for (int i = 0; i < MAX_LIST; i++)
	{
		Show_1_Lop(&lop, x, y + i);
	}
}
void Show_DSLop(DSLop dsl, int start, int end, int pos)
{
	Clear_Data_DSLop();
	int x = 5, y = 6;
	Normal_Text();
	for (int i = start; i < end; i++)
	{
		Show_1_Lop(dsl.node[i], x, y + i - start);
	}
	HighLight_Text();
	Show_1_Lop(dsl.node[start + pos], x, y + pos);
}
void Draw_Frame_DSSV()
{
	Draw_Frame_Main(0, 0, X, Y, "QUAN LI LOP - THI TRAC NGHIEM");
	Draw_Frame(3, 3, 70, 22);
	Draw_H(3, 5, 70);
	Draw_I(28, 3, 22);
	Draw_I(65, 3, 22);
	gotoxy(28, 5);
	printf("%c", char(206));
	gotoxy(65, 5);
	printf("%c", char(206));
	gotoxy(13, 4);
	printf("%s", "MSSV");
	gotoxy(40, 4);
	printf("%s", "TEN SINH VIEN");
	gotoxy(68, 4);
	printf("%s", "PHAI");
}
void Draw_Frame_DSSV_Input()
{
	Draw_Frame(75, 3, 40, 9);
	Draw_H(75, 5, 40);
	Draw_H(75, 7, 40);
	Draw_H(75, 9, 40);
	Draw_H(75, 11, 40);
	Draw_I(88, 3, 9);
	gotoxy(88, 5);
	printf("%c", char(206));
	gotoxy(88, 7);
	printf("%c", char(206));
	gotoxy(88, 9);
	printf("%c", char(206));
	gotoxy(88, 11);
	printf("%c", char(206));
	gotoxy(77, 4);
	printf("%s", "MSSV");
	gotoxy(77, 6);
	printf("%s", "HO");
	gotoxy(77, 8);
	printf("%s", "TEN");
	gotoxy(77, 10);
	printf("%s", "PHAI");
	gotoxy(77, 12);
	printf("%s", "PASSWORD");
}

void Add_SinhVien()
{
	Normal_Text();
	Clear_Data_Input();
	Draw_Frame_DSSV_Input();
	int chon = 0;
	SV sv;
	sv.Init();
	do
	{
		gotoxy(90, 4 + chon * 2);
		if (wherey() == 4)
		{
			cout << sv.MSSV;
			char str[sizeof(sv.MSSV)] = "";
			strcpy(str, sv.MSSV);
			strcpy(sv.MSSV, Input_Str_Int(str, 90, 4 + chon * 2, sizeof(sv.MSSV) - 1));
		}
		else if (wherey() == 6)
		{
			cout << sv.HO;
			char str[sizeof(sv.HO)] = "";
			strcpy(str, sv.HO);
			strcpy(sv.HO, Input_Str_Int(str, 90, 4 + chon * 2, sizeof(sv.HO) - 1));
		}
		else if (wherey() == 8)
		{
			cout << sv.TEN;
			char str[sizeof(sv.TEN)] = "";
			strcpy(str, sv.TEN);
			strcpy(sv.TEN, Input_Str_Int(str, 90, 4 + chon * 2, sizeof(sv.TEN) - 1));
		}
		else if (wherey() == 10)
		{
			
		}
		else if (wherey() == 12)
		{
			cout << sv.PASS;
			char str[sizeof(sv.PASS)] = "";
			strcpy(str, sv.PASS);
			strcpy(sv.PASS, Input_Str_Int(str, 90, 4 + chon * 2, sizeof(sv.PASS) - 1));
		}
		int key = GetKey();
		switch (key)
		{
		case UP:
			if (chon > 0)
			{
				chon--;
			}
			break;
		case DOWN:
			if (chon + 1 < 5)
			{
				chon++;
			}
			break;
		case ENTER:
			if (chon + 1 < 5)
			{
				chon++;
			}
			break;
		case TAB:
			if (chon + 1 < 5)
			{
				chon++;
			}
			break;
		case CTRL_S:
			return;
		case ESC:
			return;
		}

	} while (1);
}
void Giaodien_Dssv()
{
	Draw_Frame_DSSV();
	Draw_Frame_DSSV_Input();
	char key;
	while (true)
	{
		key = GetKey();
		switch (key)
		{
			case F2:
				Add_SinhVien();
				break;
			case ESC:
				return;
		}
	}
}
void Case1(DSLop &dsl)
{
	Draw_Frame_DSLop();
	Draw_Frame_DSLop_Input();
	Read_DS_Lop_File(dsl);
	char key;
	int pos = 0;
	int start = 0, end = 0;
	if (dsl.n > MAX_LIST)
	{
		end = MAX_LIST;
	}
	else
		end = dsl.n;
	while (true)
	{
		Show_DSLop(dsl, start, end, pos);
		key = GetKey();
		switch (key)
		{
		case UP:
			if (pos > 0)
			{
				pos--;
			}
			if (start > 0 && pos == 0)
			{
				start--;
				end--;
			}
			break;
		case DOWN:
			if (pos < MAX_LIST - 1)
			{
				pos++;
			}
			if (end < dsl.n && pos == MAX_LIST - 1)
			{
				start++;
				end++;
			}
			break;
		case F2:
			Add_Lop(dsl);
			pos = MAX_LIST - 1;
			end = dsl.n;
			start = end - pos - 1;
			break;
		case ENTER:
			Giaodien_Dssv();
			break;
		case ESC:
			return;
		}
	}
}
