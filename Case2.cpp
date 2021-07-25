//========================CASE 2===================
void Draw_Frame_DSMH(){
	system("cls");
	Draw_Frame_Main(0, 0, X, Y, "QUAN LI MON HOC - THI TRAC NGHIEM");
	Draw_Frame(3, 3, 70, 22);
	Draw_H(3, 5, 70);
	Draw_I(28, 3, 22);
	gotoxy(28, 5);
	printf("%c", char(206));
	gotoxy(11, 4);
	printf("%s", "MA MON HOC");
	gotoxy(45, 4);
	printf("%s", "TEN MON HOC");
}

void Draw_Frame_DSMH_Input(){
	Draw_Frame(75, 3, 40, 3);
	Draw_H(75, 5, 40);
	Draw_I(88, 3, 3);
	Clear_Data_Input();
	gotoxy(88, 5);
	printf("%c", char(206));
	gotoxy(77, 4);
	printf("%s", "MA MON");
	gotoxy(77, 6);
	printf("%s", "TEN MON");
}

void Show_1_MonHoc(MonHoc mh, int x, int y)
{
	gotoxy(x, y);
	printf("%s", mh.MAMH);
	gotoxy(x + 25, y);
	printf("%s", mh.TENMH);
	Clear_Data_Input();
	gotoxy(90, 4);
	printf("%s", mh.MAMH);
	gotoxy(90, 6);
	printf("%s", mh.TENMH);
}
void Clear_Data_DSMonHoc()
{
	int x = 5, y = 6;
	Normal_Text();
	MonHoc mh;
	strcpy(mh.MAMH, "                     ");
	strcpy(mh.TENMH, "                      ");
	for (int i = 0; i < MAX_LIST; i++)
	{
		Show_1_MonHoc(mh, x, y + i);
	}
}

void Show_DSMonHoc(DSMH dsmh, int start, int end, int pos)
{
	Clear_Data_DSLop();
	int x = 5, y = 6;
	Normal_Text();
	for (int i = start; i < end; i++)
	{
		Show_1_MonHoc(dsmh.DSMH[i]->mon, x, y + i - start);
	}
	HighLight_Text();
	Show_1_MonHoc(dsmh.DSMH[start + pos]->mon, x, y + pos);
}

void Add_MonHoc(NodeMH &nodeMH)
{
	Normal_Text();
	Draw_Frame_DSMH_Input();
	int chon = 0;
	MonHoc mh;
	strcpy(mh.MAMH,"");
	strcpy(mh.TENMH,"");
	do
	{
		gotoxy(90, 4 + chon * 2);
		if (wherey() == 4)
		{
			cout << mh.MAMH;
			char str[sizeof(mh.MAMH)] = "";
			strcpy(str, mh.MAMH);
			strcpy(mh.MAMH, Input_Str_Int(str, 90, 4 + chon * 2, sizeof(mh.MAMH) - 1));
		}
		else if (wherey() == 6)
		{
			cout << mh.TENMH;
			char str[sizeof(mh.TENMH)] = "";
			strcpy(str, mh.TENMH);
			strcpy(mh.TENMH, Input_Str_Int(str, 90, 4 + chon * 2, sizeof(mh.TENMH) - 1));
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
			Insert_MH(nodeMH,mh);
			return;
		case ESC:
			return;
		}

	} while (1);
}

void Clear_Data_Input_DSCH(){
	gotoxy(67, 4);
	printf("%s", "                          ");
	gotoxy(67, 6);  
	printf("%s", "                          ");
	gotoxy(67, 8);
	printf("%s", "                         ");
	gotoxy(67, 10);
	printf("%s", "                         ");
	gotoxy(67, 12);
	printf("%s", "                         ");
	gotoxy(67, 14);
	printf("%s", "                         ");
}

void Draw_Frame_DSCH(){
	system("cls");
	Draw_Frame_Main(0, 0, X, Y, "QUAN LI CAU HOI - THI TRAC NGHIEM");
	Draw_Frame(3, 3, 50, 22);
	Draw_H(3, 5, 50);
	gotoxy(20, 4);
	printf("%s", "DANH SACH CAU HOI");
}

void Draw_Frame_DSCH_Input(){
	Draw_Frame(55, 3, 62, 11);
	Draw_H(55, 5, 62);
	Draw_H(55, 7, 62);
	Draw_H(55, 9, 62);
	Draw_H(55, 11, 62);
	Draw_H(55, 13, 62);
	Draw_I(65, 3, 11);
	Clear_Data_Input_DSCH();
	gotoxy(65, 5);
	printf("%c", char(206));
	gotoxy(56, 4);
	printf("%s", "CAU HOI");
	gotoxy(56, 6);
	printf("%s", "CAU A");
	gotoxy(56, 8);
	printf("%s", "CAU B");
	gotoxy(56, 10);
	printf("%s", "CAU C");
	gotoxy(56, 12);
	printf("%s", "CAU D");
	gotoxy(56, 14);
	printf("%s", "DAP AN");
}

void Show_1_CauHoi(CauHoi ch, int x, int y)
{
	gotoxy(x, y);
	printf("%s", ch.NOIDUNG);
	Clear_Data_Input_DSCH();
	gotoxy(67, 4);
	printf("%s", ch.NOIDUNG);
	gotoxy(67, 6);
	printf("%s", ch.A);
	gotoxy(67, 8);
	printf("%s", ch.B);
	gotoxy(67, 10);
	printf("%s", ch.C);
	gotoxy(67, 12);
	printf("%s", ch.D);
	gotoxy(67, 14);
	printf("%s", ch.DA);
}
void Clear_Data_DSCauHoi()
{
	int x = 5, y = 6;
	Normal_Text();
	CauHoi ch;
	strcpy(ch.NOIDUNG, "                             ");
	strcpy(ch.A, "                               ");
	strcpy(ch.B, "                               ");
	strcpy(ch.C, "                               ");
	strcpy(ch.D, "                               ");
	strcpy(ch.DA, "                               ");
	
	for (int i = 0; i < MAX_LIST; i++)
	{
		Show_1_CauHoi(ch, x, y + i);
	}
}

void Show_DSCauHoi(DSCauHoi dsch, int start, int end, int pos)
{
	Clear_Data_DSCauHoi();
	int x = 5, y = 6;
	Normal_Text();
	for (int i = start; i < end; i++)
	{
		Show_1_CauHoi(dsch.dsch[i], x, y + i - start);
	}
	HighLight_Text();
	Show_1_CauHoi(dsch.dsch[start + pos], x, y + pos);
}

void Add_CauHoi(DSCauHoi &dsch)
{
	Normal_Text();
	Draw_Frame_DSCH_Input();
	int chon = 0;
	CauHoi ch;
	strcpy(ch.NOIDUNG,"");
	strcpy(ch.A,"");
	strcpy(ch.B,"");
	strcpy(ch.C,"");
	strcpy(ch.D,"");
	strcpy(ch.DA,"");
	do
	{
		gotoxy(67, 4 + chon * 2);
		if (wherey() == 4)
		{
			cout << ch.NOIDUNG;
			char str[sizeof(ch.NOIDUNG)] = "";
			strcpy(str, ch.NOIDUNG);
			strcpy(ch.NOIDUNG, Input_Str_Int(str, 67, 4 + chon * 2, sizeof(ch.NOIDUNG) - 1));
		}
		else if (wherey() == 6)
		{
			cout << ch.A;
			char str[sizeof(ch.A)] = "";
			strcpy(str, ch.A);
			strcpy(ch.A, Input_Str_Int(str, 67, 4 + chon * 2, sizeof(ch.A) - 1));
		}
		else if (wherey() == 8)
		{
			cout << ch.B;
			char str[sizeof(ch.B)] = "";
			strcpy(str, ch.B);
			strcpy(ch.B, Input_Str_Int(str, 67, 4 + chon * 2, sizeof(ch.B) - 1));
		}
		else if (wherey() == 10)
		{
			cout << ch.C;
			char str[sizeof(ch.C)] = "";
			strcpy(str, ch.C);
			strcpy(ch.C, Input_Str_Int(str, 67, 4 + chon * 2, sizeof(ch.C) - 1));
		}
		else if (wherey() == 12)
		{
			cout << ch.D;
			char str[sizeof(ch.D)] = "";
			strcpy(str, ch.D);
			strcpy(ch.D, Input_Str_Int(str, 67, 4 + chon * 2, sizeof(ch.D) - 1));
		}
		else if (wherey() == 14)
		{
			cout << ch.DA;
			char str[sizeof(ch.DA)] = "";
			strcpy(str, ch.DA);
			strcpy(ch.DA, Input_Str_Int(str, 67, 4 + chon * 2, sizeof(ch.DA) - 1));
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
			if (chon + 1 < 6)
			{
				chon++;
			}
			break;
		case ENTER:
			if (chon + 1 < 6)
			{
				chon++;
			}
			break;
		case TAB:
			if (chon + 1 < 6)
			{
				chon++;
			}
			break;
		case CTRL_S:
			dsch.InsertCauHoi(ch);
			return;
		case ESC:
			return;
		}

	} while (1);
}

void GiaoDien_QuanLiCauHoi(DSCauHoi &dsch){
	Draw_Frame_DSCH();
	Draw_Frame_DSCH_Input();
	char key;
	int pos = 0;
	int start = 0, end = 0;
	if (dsch.tong > MAX_LIST)
	{
		end = MAX_LIST;
	}
	else
		end = dsch.tong;
	while(true){
		Show_DSCauHoi(dsch, start, end, pos);
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
			if (pos < MAX_LIST - 1 && pos < dsch.tong - 1)
			{
				pos++;
			}
			if (end < dsch.tong && pos == MAX_LIST - 1)
			{
				start++;
				end++;
			}
			break;
		case F2:
			Add_CauHoi(dsch);
			break;
		case ENTER:
			break;
		case ESC:
			return;
		}
	}
}

void Case2(NodeMH &nodeMH){
	Draw_Frame_DSMH();
	Draw_Frame_DSMH_Input();
	Read_DS_MH_File(nodeMH);
	DSMH dsmh;
	Insert_MH_toArray(nodeMH,dsmh);
	char key;
	int pos = 0;
	int start = 0, end = 0;
	if (dsmh.tong > MAX_LIST)
	{
		end = MAX_LIST;
	}
	else
		end = dsmh.tong;
	while(true){
		Show_DSMonHoc(dsmh, start, end, pos);
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
			if (pos < MAX_LIST - 1 && pos < dsmh.tong - 1)
			{
				pos++;
			}
			if (end < dsmh.tong && pos == MAX_LIST - 1)
			{
				start++;
				end++;
			}
			break;
		case F2:
			Add_MonHoc(nodeMH);
			Save_Tree_File(nodeMH);
			break;
		case DEL:
			Remove_MH(nodeMH,dsmh.DSMH[start+pos]->mon.MAMH);
			Save_Tree_File(nodeMH);
			Read_DS_MH_File(nodeMH);
			break;
		case ENTER:
			GiaoDien_QuanLiCauHoi(dsmh.DSMH[start+pos]->mon.dsch);
			Save_Tree_File(nodeMH);
			Draw_Frame_DSMH();
			Draw_Frame_DSMH_Input();
			break;
		case ESC:
			return;
		}
	}
}
