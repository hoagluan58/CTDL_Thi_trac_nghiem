#define MAXCAUHOI 200
#define MAXMONHOC 100
#include<iostream>
using namespace std;
//----------DANH SACH CAU HOI(DS TUYEN TINH)-----------
typedef struct CauHoi{
    int ID;
    string NOIDUNG;
    string A;
    string B;
    string C;
    string D;
    char DA;
}CauHoi;

typedef struct DSCauHoi{
    CauHoi list[MAXCAUHOI];
    int tong = 0;
}DSCauHoi;


//---------DANH SACH MON HOC(CAY NHI PHAN TIM KIEM)------------
typedef struct MonHoc{
    char MAMH[16];
    string TENMH;
    DSCauHoi dsch;
}MonHoc;

typedef struct DSMonHoc {
	MonHoc mon;
    struct DSMonHoc *pLeft;
    struct DSMonHoc *pRight;
}DSMonHoc;
typedef struct DSMonHoc NODE;
typedef NODE* TREE;

//----------DANH SACH CAU HOI DA THUC HIEN------------
typedef struct ChiTietCauHoi{
	int id;
	char svChon;
}ChiTietCauHoi;

//----------DANH SACH DIEM(DS LIEN KET DON)-----------
typedef struct Diem{
    char MAMH[16];
    float DIEMTHI;
    Diem *pNext;
    ChiTietCauHoi CAUHOISV[MAXCAUHOI];
}Diem;

typedef struct DSDiem{
    Diem *pHead =NULL;
    int tong = 0;
}DSDiem;

//----------DANH SACH SINH VIEN(DS LIEN KET DON)------
typedef struct SinhVien{
    string MSSV;
    string HO;
    string TENDEM;
    string TEN;
    string PASS;
    bool PHAI;
    SinhVien *pNext;
    DSDiem DSDIEM;
}SV;

typedef struct DSSinhVien{
    SV *pHead = NULL;
    int tong = 0;
}DSSinhVien;

//------------DANH SACH LOP(MANG CON TRO)-----------------
typedef struct Lop{
    char MALOP[20];
    char TENLOP[40];
    DSSinhVien *DSSV;
}Lop;
 
typedef struct DSLop{
    Lop *node[MAXMONHOC];
    int n = 0;
    
	void Add_Lop(Lop lop){
		if(n > MAXMONHOC){
			cout << "DANH SACH LOP DA DAY!";
		}
		else{	
			this->node[n] = new Lop;
			strcpy(this->node[n]->MALOP,lop.MALOP);
			strcpy(this->node[n]->TENLOP,lop.TENLOP);
	        this->n++;
		}
	}
	void DeleteAllNode(){
		while(this->n>0){
			this->node[this->n-1]=NULL;
			this->n--;
		}
	}
	void Init(){
		n=0;
	}
}DSLop;











