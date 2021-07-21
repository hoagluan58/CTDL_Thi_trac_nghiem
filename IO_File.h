#include <fstream>
#include <iostream>

using namespace std;

int Convert_String_to_Int(string s)
{
    int number = 0;
    for (auto ch : s)
    {
        number = (number * 10) + (ch - '0');
    }
    return number;
}
char *Convert_String_to_Char(string s, char str[])
{
    int k = sizeof(str);
    char str1[k];
    for (int i = 0; i < k; i++)
    {
        str1[i] = s[i];
    }
    printf("Toi day!! %s", str1);
    return str1;
}
void Write_DS_Lop_File(DSLop dsl, fstream &writeFile)
{
    if (dsl.n <= 0)
    {
        printf("DANH SACH LOP RONG!");
    }
    else
    {
        //        writeFile << dsl.n<< endl;
        for (int i = 0; i < dsl.n; i++)
        {
            writeFile << dsl.node[i]->MALOP << "," << dsl.node[i]->TENLOP << "," << dsl.node[i]->DSSV->tong << endl;
            DSSinhVien *dssv = dsl.node[i]->DSSV;
            for(NodeSV *p=dssv->first; p != NULL; p= p->next){
            	writeFile<< p->sv.MSSV << "," << p->sv.HO << "," << p->sv.TEN << "," << p->sv.PHAI << "," << p->sv.PASS << endl;
			}
        }
    }
}

void Save_DS_Lop_File(DSLop &dsl)
{
    fstream writeFile;
    writeFile.open("DSLop.txt", ios::out | ios::trunc);
    Write_DS_Lop_File(dsl, writeFile);
    writeFile.close();
}

void Read_DS_Lop_File(DSLop &dsl)
{
    fstream readFile;
    readFile.open("DSLop.txt", ios::in);
    string data = "";
    dsl.DeleteAllNode();
    while (!readFile.eof())
    {
        Lop lop;
        getline(readFile, data, ',');
        strcpy(lop.MALOP, data.c_str());
        getline(readFile, data, ',');
        strcpy(lop.TENLOP, data.c_str());
        lop.DSSV->Init();
        getline(readFile, data);
        int n = Convert_String_to_Int(data);
        for(int i=0; i<n ; i++){
        	SV sv;
        	getline(readFile, data, ',');
        	strcpy(sv.MSSV, data.c_str());
        	getline(readFile, data, ',');
        	strcpy(sv.HO, data.c_str());
        	getline(readFile, data, ',');
        	strcpy(sv.TEN, data.c_str());
        	getline(readFile, data, ',');
        	sv.PHAI = Convert_String_to_Int(data);
        	getline(readFile, data);
        	strcpy(sv.PASS, data.c_str());
        	if (strcmp(sv.MSSV, "") != 0) lop.DSSV->Add_SV_Last(CreateNodeSV(sv));
		}
        if (strcmp(lop.MALOP, "") != 0)
            dsl.Add_Lop(lop);
        // do no se doc dong cuoi cung, ma dong cuoi cung khong co gia tri no cung doc, nen khac null moi duoc them vao
    }
}

//ghi danh sach mon hoc vao file
void Write_Tree_File(NodeMH & p, fstream & write) {
    if (p != NULL) {
        write << p->mon.MAMH<< "," << p->mon.TENMH<< endl;
        Write_Tree_File(p -> pLeft, write);
        Write_Tree_File(p -> pRight, write);
    }
}
void Save_Tree_File(NodeMH & p) {
    fstream write;
    write.open("DSMonHoc.txt", ios::out | ios::trunc);
    Write_Tree_File(p, write);
    write.close();
}
void Read_DS_MH_File(NodeMH &nodeMH)
{
    fstream readFile;
    readFile.open("DSMonHoc.txt", ios::in);
    string data = "";
    while (!readFile.eof())
    {
        MonHoc mh;
        getline(readFile, data, ',');
        strcpy(mh.MAMH, data.c_str());
        getline(readFile, data);
        strcpy(mh.TENMH, data.c_str());
        if (strcmp(mh.MAMH, "") != 0)
        Insert_MH(nodeMH,mh);
        // do no se doc dong cuoi cung, ma dong cuoi cung khong co gia tri no cung doc, nen khac null moi duoc them vao
    }
}

