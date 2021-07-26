#include "Theme.cpp"
#include "Input.h"
#include "Case1.cpp"
#include "Case2.cpp"
using namespace std;
DSLop dsl;
NodeMH nodeMH; 

//===========LOGIN==============
void Menu_GV();
void DrawLoginForm(int x, int y, int rong, int dai)
{
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
    gotoxy(45, 2);
    gotoxy(52, 10);
    cout << " DANG NHAP ";
    gotoxy(40, 14);
    cout << "Tai khoan: ";
    gotoxy(40, 16);
    cout << "Mat khau : ";
}
void Login()
{
    char username[15] = "", password[20] = "";
    int chon = 0;
    Read_DS_Lop_File(dsl);
    DrawLoginForm(32, 10, 50, 10);
    do
	{
		gotoxy(52, 18);
		Normal();
		cout<<" Dang nhap ";
		Normal_Text();
		gotoxy(52, 14 + chon * 2);
		if (wherey() == 14)
		{
			cout << username;
			char str[sizeof(username)] = "";
			strcpy(str, username);
			strcpy(username, Input_Str_Int(str, 52, 14 + chon * 2, sizeof(username) - 1));
		}
		else if (wherey() == 16)
		{
			cout << password;
			char str[sizeof(password)] = "";
			strcpy(str, password);
			strcpy(password, Input_Str_Int(str, 52, 14 + chon * 2, sizeof(password) - 1));
		}
		else if (wherey() == 18)
		{
			gotoxy(52, 18);
			HighLight();
			cout<<" Dang nhap ";
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
			if(wherey()==18){
				if (!strcmp(username, "GV") && !strcmp(password, "GV"))
			    {
			        cout << "\n Dang nhap thanh cong";
			        Menu_GV();
			    }
			    else
			    {
			        if(dsl.LoginSinhVien(username,password)){
			        	cout << "\n Dang nhap sinh vien thanh cong";
			        	break;
					}else{
						cout << "\n Tai khoan hoac mat khau chua dung";
						chon = 0;
					}
			    }    
			}
			break;
		case TAB:
			if (chon + 1 < 3)
			{
				chon++;
			}
			break;
		}

	} while (1);

}

//=========================MENu=================
void Draw_Button_Menu_Highligh(char td[so_item_menu_Main][50], int cot, int dong, int chon)
{
    HighLight();
    gotoxy(cot, dong + 1 + (chon)*4);
    printf("%s", "                            ");
    gotoxy(cot, dong + 2 + (chon)*4);
    printf("%s", td[chon]);
    gotoxy(cot, dong + 3 + (chon)*4);
    printf("%s", "                            ");
}
void Draw_Button_Menu_Normal(char td[so_item_menu_Main][50], int cot, int dong, int chon)
{
    Normal();
    gotoxy(cot, dong + 1 + (chon)*4);
    printf("%s", "                            ");
    gotoxy(cot, dong + 2 + (chon)*4);
    printf("%s", td[chon]);
    gotoxy(cot, dong + 3 + (chon)*4);
    printf("%s", "                            ");
}
int Up_Down_Menu_Chinh(char td[so_item_menu_Main][50])
{
    int cot_menu = 6 + X / 2 - 20;
    int dong_menu = Y / 2 - 10;
    Normal();
    system("cls");
    Draw_Frame_Main(0, 0, X, Y, NAME_PROGRAM);
    int chon = 0;
    for (int i = 0; i < so_item_menu_Main; i++)
    {
        Draw_Button_Menu_Normal(td, cot_menu, dong_menu, i);
    }
    Draw_Button_Menu_Highligh(td, cot_menu, dong_menu, chon);
    char kytu;
    do
    {
        kytu = GetKey();
        switch (kytu)
        {
        case UP:
            if (chon > 0)
            {
                Draw_Button_Menu_Normal(td, cot_menu, dong_menu, chon);
                chon--;
                Draw_Button_Menu_Highligh(td, cot_menu, dong_menu, chon);
            }
            break;
        case DOWN:
            if (chon + 1 < so_item_menu_Main)
            {
                Draw_Button_Menu_Normal(td, cot_menu, dong_menu, chon);
                chon++;
                Draw_Button_Menu_Highligh(td, cot_menu, dong_menu, chon);
            }
            break;
        case ENTER:
            return chon + 1;
        case ESC:
            return ESC;
        } // end switch
    } while (1);
}

void Menu_GV()
{
    char thucdon[so_item_menu_Main][50] = {
        "     1. QUAN LI LOP         ",
        "     2. QUAN LI MON HOC     ",
        "     3. THI TRAC NGHIEM     ",
        "     4. EXIT                "};
    int chon = 0;
    while (1)
    {
        chon = Up_Down_Menu_Chinh(thucdon);
        switch (chon)
        {
        case 1:
            Case1(dsl);
            break;
        case 2:
        	Case2(nodeMH);
            break;
        case 3:
            break;
        case 4:
            //system("exit");
            exit(1);
        case ESC:
            break;
        }
    }
}
void theme()
{
    ColorAll();
    Draw_Frame_Main(0, 0, X, Y, NAME_PROGRAM);
    //intro();
    Login();
}
