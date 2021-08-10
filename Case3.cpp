// draw case 3
opTest optionTest;
MonHoc monhoc_canthi;
SV sinhvien;
DSLop dsl_temp;

void SearchSv(char masosv[]){
	Read_DS_Lop_File(dsl_temp);
	sinhvien = dsl_temp.SearchSinhVien(masosv);
}

void Swap(int* number_1, int* number_2)
{
	int temp = *number_1;
	*number_1 = *number_2;
	*number_2 = temp;
}
void ShuffleArray(int* arr, int n)
{
	srand(time(NULL));

	int minPosition;
	int maxPosition = n - 1;
	int swapPosition;

	int i = 0;
	while (i < n - 1)
	{
		minPosition = i + 1;
		swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;

		Swap(&arr[i], &arr[swapPosition]);
		i++;
	}
}

void Draw_Dialog_Input()
{
	Normal_Text();
    Draw_Frame(75, 3, 40, 5);
    gotoxy(77, 4);
    cout << "So phut: ";
    gotoxy(77, 6);
    cout << "So cau : ";
}
void Clear_Draw_Dialog_Input(){
	for(int i = 75; i < 118; i++){
		for(int j = 3; j < 10; j++){
			gotoxy(i,j);
			cout<<" ";
		}
	}
}

void Draw_Answer_Highligh(char td[so_item_menu_Main][100], int cot, int dong, int chon)
{
    HighLight();
    string tt ="";
    switch(chon){
		case 0:
			tt = "A";
			break;
		case 1:
			tt = "B";
			break;
		case 2:
			tt = "C";
			break;
		case 3:
			tt = "D";
			break;
	}
    gotoxy(cot, dong + 1 + (chon)*4);
    printf("%s", "                            ");
    gotoxy(cot, dong + 2 + (chon)*4);
    cout<<tt;
    printf(". %s",td[chon]);
    gotoxy(cot, dong + 3 + (chon)*4);
    printf("%s", "                            ");
}
void Draw_Answer_Normal(char td[so_item_menu_Main][100], int cot, int dong, int chon)
{
    Normal();
    string tt="";
    switch(chon){
		case 0:
			tt = "A";
			break;
		case 1:
			tt = "B";
			break;
		case 2:
			tt = "C";
			break;
		case 3:
			tt = "D";
			break;
	}
    gotoxy(cot, dong + 1 + (chon)*4);
    printf("%s", "                            ");
    gotoxy(cot, dong + 2 + (chon)*4);
    cout<<tt;
    printf(". %s",td[chon]);
    gotoxy(cot, dong + 3 + (chon)*4);
    printf("%s", "                            ");
}
void Draw_CauTracNghiem(int i){
	system("cls");
	Draw_Frame_Main(0, 0, X, Y, "CAU HOI - THI TRAC NGHIEM");
}

char* Show_1_CauTracNghiem(CauHoi ch,int tt){
	Draw_CauTracNghiem(tt);
	Draw_Frame(8,3, 110, 3);
	gotoxy(9,4);
	cout<<"Cau "<<tt+1<<": "<<ch.NOIDUNG;
	int cot_menu = 6 + X / 2 - 20;
    int dong_menu = Y / 2 - 5;
    char dapan[5][100] = {};
    strcpy(dapan[0],ch.A);
    strcpy(dapan[1],ch.B);
    strcpy(dapan[2],ch.C);
    strcpy(dapan[3],ch.D);
	char kytu;
	int chon = 0;
	for (int i = 0; i < 4; i++)
    {
        Draw_Answer_Normal(dapan, cot_menu, dong_menu, i);
    }
    Draw_Answer_Highligh(dapan, cot_menu, dong_menu, chon);
	do
    {
        kytu = GetKey();
        switch (kytu)
        {
        case UP:
            if (chon > 0)
            {
                Draw_Answer_Normal(dapan, cot_menu, dong_menu, chon);
                chon--;
                Draw_Answer_Highligh(dapan, cot_menu, dong_menu, chon);
            }
            break;
        case DOWN:
            if (chon + 1 < 4)
            {
                Draw_Answer_Normal(dapan, cot_menu, dong_menu, chon);
                chon++;
                Draw_Answer_Highligh(dapan, cot_menu, dong_menu, chon);
            }
            break;
        case ENTER:
           if(chon==0) return "A";
           if(chon==1) return "B";
           if(chon==2) return "C";
           if(chon==3) return "D";
           break;
        } // end switch
    } while (1);
}

void Test(){
	Diem diem;
	if(optionTest.soCau > monhoc_canthi.dsch.tong)
	{
		Dialog_Notification("So cau hoi khong hop le",2);
		return;
	}
	if(sinhvien.DSDIEM.MonDaThi(monhoc_canthi.MAMH)){
		Dialog_Notification("Sinh vien da thi mon nay",2);
		return;
	}
	int rand[optionTest.soCau+1];
	char *cautraloi[optionTest.soCau+1];
	for(int i=0;i<optionTest.soCau;i++){
		rand[i]=i;
	}
	ShuffleArray(rand,optionTest.soCau);
	for(int i=0; i<optionTest.soCau; i++){
		cautraloi[rand[i]] = Show_1_CauTracNghiem(monhoc_canthi.dsch.dsch[rand[i]],i);
	}
	Draw_CauTracNghiem(0);
	
	
	strcpy(diem.MAMH,monhoc_canthi.MAMH);
	int socaudung = 0;
	for(int i=0; i<optionTest.soCau; i++){
		if(strcmp(cautraloi[rand[i]],monhoc_canthi.dsch.dsch[rand[i]].DA)==0){
			socaudung++;
		}
	}
	diem.soCau = optionTest.soCau;
	diem.DIEMTHI = (10/optionTest.soCau)*socaudung;
	for(int i=0 ;i<optionTest.soCau; i++){
		ChiTietCauHoi ctch;
		ctch.id = rand[i];
		strcpy(ctch.svChon,cautraloi[rand[i]]);
		diem.CAUHOISV[i]=ctch;
	}
	sinhvien.DSDIEM.Insert_Diem_Last(diem);
	dsl_temp.UpdateSinhVien(sinhvien);
	Save_DS_Lop_File(dsl_temp);
	Read_DS_Lop_File(dsl_temp);
	gotoxy(20,20);
	printf("So cau dung la %d/%d, Diem cua ban thi duoc la %f",socaudung,optionTest.soCau, diem.DIEMTHI);
	gotoxy(20,21);
	printf("Nhan ENTER de tro ve");
	char key;
	while(1){
		key = GetKey();
		if(key = ENTER) return;
	}
}

void Input_Option_Test(){
	Normal_Text();
	Draw_Dialog_Input();
	int chon = 0;
	optionTest.soCau = 0;
	optionTest.soPhut = 0;
	do
	{
		gotoxy(90, 8);
		Normal();
		cout<<" VAO THI ";
		Normal_Text();
		gotoxy(90, 4 + chon * 2);
		if (wherey() == 4)
		{
			optionTest.soPhut = Input_Int(optionTest.soPhut,90,4+chon*2);
		}
		else if (wherey() == 6)
		{
			optionTest.soCau = Input_Int(optionTest.soCau,90,4+chon*2);
		}
		else if (wherey() == 8)
		{
			gotoxy(90, 8);
			HighLight();
			cout<<" VAO THI ";
			Normal_Text();
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
			if (chon + 1 < 3)
			{
				chon++;
			}
			break;
		case ENTER:
			if (chon + 1 < 3)
			{
				chon++;
			}
			if(wherey()==8){
				Test();
				Clear_Draw_Dialog_Input();
				return;
			}
			break;
		case TAB:
			if (chon + 1 < 2)
			{
				chon++;
			}
			break;
		case CTRL_S:
			return;
		case ESC:
			Clear_Draw_Dialog_Input();
			return;
		}

	} while (1);
}
void Draw_Frame_DSMH_Case3(){
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


void Show_1_MonHoc_Case3(MonHoc mh, int x, int y)
{
	gotoxy(x, y);
	printf("%s", mh.MAMH);
	gotoxy(x + 27, y);
	printf("%s", mh.TENMH);
}
void Clear_Data_DSMonHoc_Case3()
{
	int x = 5, y = 6;
	Normal_Text();
	MonHoc mh;
	strcpy(mh.MAMH, "             ");
	strcpy(mh.TENMH, "                        ");
	for (int i = 0; i < MAX_LIST; i++)
	{
		Show_1_MonHoc_Case3(mh, x, y + i);
	}
}

void Show_DSMonHoc_Case3(DSMH dsmh, int start, int end, int pos)
{
	Clear_Data_DSMonHoc_Case3();
	int x = 5, y = 6;
	Normal_Text();
	for (int i = start; i < end; i++)
	{
		Show_1_MonHoc_Case3(dsmh.DSMH[i]->mon, x, y + i - start);
	}
	HighLight_Text();
	Show_1_MonHoc_Case3(dsmh.DSMH[start + pos]->mon, x, y + pos);
}

void Case3(NodeMH &nodeMH,char masosv[]){
	Draw_Frame_DSMH_Case3();
	Read_DS_MH_File(nodeMH);
	SearchSv(masosv);
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
		Show_DSMonHoc_Case3(dsmh, start, end, pos);
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
		case ENTER:
			monhoc_canthi = dsmh.DSMH[start + pos]->mon;
			Input_Option_Test();
			Draw_Frame_DSMH_Case3();
			break;
		case ESC:
			return;
		}
	}
}
