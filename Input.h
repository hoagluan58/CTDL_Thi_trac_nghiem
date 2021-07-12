int GetKey() {
    char key;
    key = _getch();
    if (key == -32 || key == 0)
        return -_getch();
    else return key;
}

//==========XU LI CHUOI=====================
char * Input_Str(char str[], int x, int y, int length) {
    int k;
    int len;
    Normal_Text();
    gotoxy(x, y);
    len = strlen(str);
    cout << str;
    while (1) {
        k = GetKey();
        if (k >= 97 && k <= 122 && len < length) {
            str[len] = k - 32;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k >= 65 && k <= 96 && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == BACKSPACE) {
            str[len - 1] = NULL;
            for (int i = 0; i < strlen(str) + 5; i++) {
                gotoxy(x + i, y);
                printf("   ");
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == SPACE) {
            if (str[len - 1] != char(255) && len > 0 && len < length) {
                str[len] = 255;
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == ENTER || k == TAB || k == DOWN || k == ESC || k == UP) {
            gotoxy(x, y);
            HighLight_Text();
            cout << str;
            return str;
        }
    };
    return str;
}
char * Input_Str_Int(char str[], int x, int y, int length) {
    int k;
    int len;
    Normal_Text();
    gotoxy(x, y);
    len = strlen(str);
    cout << str;
    while (1) {
        k = GetKey();
        if (k >= 97 && k <= 122 && len < length) {
            str[len] = k - 32;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k >= 65 && k <= 96 && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k >= 48 && k <= 57 && len < length) {
            str[len] = k;
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == BACKSPACE) {
            str[len - 1] = NULL;
            for (int i = 0; i < strlen(str) + 5; i++) {
                gotoxy(x + i, y);
                printf("   ");
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == SPACE) {
            if (str[len - 1] != char(255) && len > 0 && len < length) {
                str[len] = 255;
            }
            gotoxy(x, y);
            len = strlen(str);
            cout << str;
        } else if (k == ENTER || k == TAB || k == DOWN || k == ESC || k == UP) {
            gotoxy(x, y);
            HighLight_Text();
            cout << str;
            return str;
        }
    };
    return str;
}

