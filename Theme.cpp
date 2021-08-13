#include <windows.h>
//===================================MENU CHINH========================================
const int so_item_menu_Main = 4;
//===========TO MAU==========================
void ColorAll()
{
    system("Color B2");
    SetColor(15);
}
void Normal()
{
    SetColor(12);
    SetBGColor(7);
}

void HighLight()
{
    SetColor(4);
    SetBGColor(15);
}
void HighLight_Text()
{
    SetColor(4);
    SetBGColor(11);
}
void Normal_Text()
{
    SetColor(15);
    SetBGColor(11);
}

//==========VE KHUNG O DAY==================
void Draw_H(int x, int y, int dai)
{
    gotoxy(x, y);
    cout << char(204);
    for (int i = 1; i <= dai; i++)
    {
        gotoxy(x + i, y);
        cout << char(205);
    }
    gotoxy(x + dai + 1, y);
    cout << char(185);
}
void Draw_I(int x, int y, int rong)
{
    gotoxy(x, y);
    cout << char(203);
    for (int i = 1; i <= rong; i++)
    {
        gotoxy(x, y + i);
        cout << char(186);
    }
    gotoxy(x, y + rong + 1);
    cout << char(202);
}
void Draw_Frame_Main(int x, int y, int rong, int dai, string header)
{
    system("cls");
    ColorAll();
    gotoxy(x, y);
    cout << char(201);
    for (int i = 1; i <= rong; i++)
    {
        cout << char(205);
    }
    cout << char(187);
    gotoxy(x, y + 1);
    for (int j = 1; j <= dai; j++)
    {
        gotoxy(x, y + j);
        cout << char(186);
        gotoxy(x + rong + 1, y + j);
        cout << char(186);
    }
    gotoxy(x, y + dai + 1);
    cout << char(200);
    for (int k = 1; k <= rong; k++)
    {
        cout << char(205);
    }
    cout << char(188);
    HighLight();
    gotoxy(3, Y - 1);
    printf(" <ESC ");
    gotoxy(13 + 100, Y - 1);
    printf("%c ", 254);
    gotoxy(11 + 100, Y - 1);
    printf("%c ", 60);
    gotoxy(14 + 100, Y - 1);
    printf(" %c", 62);
    gotoxy(11 + 100, Y - 1 - 1);
    printf("  %c  ", 94);
    gotoxy(11 + 100, Y - 1 + 1);
    printf("  %c  ", 118);
    Normal_Text();
    gotoxy(45, 1);
    cout << header;
    Draw_H(0, 2, rong);
}
void Draw_Frame(int x, int y, int rong, int dai)
{
    gotoxy(x, y);
    printf("%c", char(201));
    for (int i = 1; i <= rong; i++)
    {
        printf("%c", char(205));
    }
    printf("%c", char(187));
    gotoxy(x, y + 1);
    for (int j = 1; j <= dai; j++)
    {
        gotoxy(x, y + j);
        printf("%c", char(186));
        gotoxy(x + rong + 1, y + j);
        printf("%c", char(186));
    }
    gotoxy(x, y + dai + 1);
    printf("%c", char(200));
    for (int k = 1; k <= rong; k++)
    {
        printf("%c", char(205));
    }
    printf("%c", char(188));
}
void Dialog_Notification(string noti,int sleep){
	Normal_Text();
	Draw_Frame(75,15,40,2);
	gotoxy(77,16);
	cout<<"THONG BAO: "+noti;
	Sleep(sleep*1000);
	for(int i=75; i<=75+40 ; i++){
		for(int j=15; j<=15+2; j++){
			gotoxy(i,j);
			cout<"  ";
		}
	}
}
void Clear_Data_Input()
{
	gotoxy(90, 4);
	printf("%s", "                     ");
	gotoxy(90, 6);
	printf("%s", "                     ");
	gotoxy(90, 8);
	printf("%s", "                     ");
	gotoxy(90, 10);
	printf("%s", "                     ");
	gotoxy(90, 12);
	printf("%s", "                     ");
}
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
void Draw_Frame_DSMH_Input_Case1(){
	Draw_Frame(75, 3, 40, 5);
	Draw_H(75, 5, 40);
	Draw_H(75, 7, 40);
	Draw_I(88, 3, 5);
	Clear_Data_Input();
	gotoxy(88, 5);
	printf("%c", char(206));
	gotoxy(77, 4);
	printf("%s", "MA MON");
	gotoxy(77, 6);
	printf("%s", "TEN MON");
	gotoxy(77, 8);
	printf("%s", "TRANG THAI");
}
