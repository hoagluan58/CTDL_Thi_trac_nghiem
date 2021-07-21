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
	gotoxy(88, 5);
	printf("%c", char(206));
	gotoxy(77, 4);
	printf("%s", "MA MON");
	gotoxy(77, 6);
	printf("%s", "TEN MON");
}

//void Show_1_MonHoc(Lop *lop, int x, int y)
//{
//	gotoxy(x, y);
//	printf("%s", lop->MALOP);
//	gotoxy(x + 25, y);
//	printf("%s", lop->TENLOP);
//	Clear_Data_Input();
//	gotoxy(90, 4);
//	printf("%s", lop->MALOP);
//	gotoxy(90, 6);
//	printf("%s", lop->TENLOP);
//}
//void Clear_Data_DSMonHoc()
//{
//	int x = 5, y = 6;
//	Normal_Text();
//	Lop lop;
//	strcpy(lop.MALOP, "                   ");
//	strcpy(lop.TENLOP, "                    ");
//	for (int i = 0; i < MAX_LIST; i++)
//	{
//		Show_1_Lop(&lop, x, y + i);
//	}
//}
//
//void Show_DSMonHoc(DSLop dsl, int start, int end, int pos)
//{
//	Clear_Data_DSLop();
//	int x = 5, y = 6;
//	Normal_Text();
//	for (int i = start; i < end; i++)
//	{
//		Show_1_Lop(dsl.node[i], x, y + i - start);
//	}
//	HighLight_Text();
//	Show_1_Lop(dsl.node[start + pos], x, y + pos);
//}

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

void Case2(NodeMH &nodeMH){
	Draw_Frame_DSMH();
	Draw_Frame_DSMH_Input();
	Read_DS_MH_File(nodeMH);
	char key;
	int pos = 0;
	int start = 0, end = 0;
	while(true){
		key = GetKey();
		switch (key)
		{
		case UP:
			break;
		case DOWN:
			break;
		case F2:
			Add_MonHoc(nodeMH);
			Save_Tree_File(nodeMH);
			break;
		case ENTER:
			break;
		case ESC:
			return;
		}
	}
}
