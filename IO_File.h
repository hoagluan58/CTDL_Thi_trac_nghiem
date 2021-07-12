#include <fstream>
#include <iostream>

using namespace std;

int Convert_String_to_Int(string s) {
    int number = 0;
    for (auto ch: s) {
        number = (number * 10) + (ch - '0');
    }
    return number;
}
char * Convert_String_to_Char(string s, char str[]) {
    int k = sizeof(str);
    char str1[k];
    for (int i = 0; i < k; i++) {
        str1[i] = s[i];
    }
    printf("Toi day!! %s",str1);
    return str1;
}
void Write_DS_Lop_File(DSLop dsl, fstream &writeFile) {
    if (dsl.n <= 0) {
        printf("DANH SACH LOP RONG!");
    } else {
//        writeFile << dsl.n<< endl;
        for (int i = 0; i < dsl.n; i++) {
        	printf("%s %s",dsl.node[i] ->MALOP,dsl.node[i] ->TENLOP);
            writeFile << dsl.node[i] -> MALOP << "," << dsl.node[i] -> TENLOP << endl;
        }
    }
}

void Save_DS_Lop_File(DSLop &dsl) {
    fstream writeFile;
    writeFile.open("DSLop.txt", ios::out | ios::trunc);
    Write_DS_Lop_File(dsl, writeFile);
    writeFile.close();
}

void Read_DS_Lop_File(DSLop &dsl){
	fstream readFile;
	readFile.open("DSLop.txt", ios:: in );
	string data = "";
	dsl.DeleteAllNode();
	while(!readFile.eof()){
		Lop lop;
		getline(readFile, data, ',');
		strcpy(lop.MALOP, data.c_str());
		getline(readFile, data);
		strcpy(lop.TENLOP, data.c_str());
		dsl.Add_Lop(lop);
	}
}



