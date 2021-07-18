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

void Case2(){
	Draw_Frame_DSMH();
	Draw_Frame_DSMH_Input();
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
			break;
		case ENTER:
			break;
		case ESC:
			return;
		}
	}
}
