#define MAXCAUHOI 200
#define MAXMONHOC 100
#define MAXSINHVIEN 100
#include <iostream>
using namespace std;
//----------DANH SACH CAU HOI(DS TUYEN TINH)-----------
typedef struct CauHoi
{
    int ID;
    string NOIDUNG;
    string A;
    string B;
    string C;
    string D;
    char DA;
} CauHoi;

typedef struct DSCauHoi
{
    CauHoi list[MAXCAUHOI];
    int tong = 0;
} DSCauHoi;

//---------DANH SACH MON HOC(CAY NHI PHAN TIM KIEM)------------
typedef struct MonHoc
{
    char MAMH[16];
    char TENMH[25];
    DSCauHoi dsch;
} MonHoc;

struct NodeMonHoc
{
    MonHoc mon;
    struct NodeMonHoc *pLeft;
    struct NodeMonHoc *pRight;
};
typedef struct NodeMonHoc *NodeMH;

typedef struct DSMonHoc
{
	NodeMonHoc *DSMH[200];
	int tong = 0;
} DSMH;

void Insert_MH(NodeMH &p, MonHoc mh) { //them 1 mh vao cay nhi phan
    if (p == NULL) {
        p = new NodeMonHoc;
        p -> mon = mh;
        p -> pLeft = NULL;
        p -> pRight = NULL;
    } else {
        if (mh.MAMH < p -> mon.MAMH) Insert_MH(p -> pLeft, mh);
        else if (mh.MAMH > p -> mon.MAMH) Insert_MH(p -> pRight, mh);
    }
}

void Insert_MH_toArray(NodeMH &p, DSMH &dsmh){
	if(p!=NULL){
		Insert_MH_toArray(p -> pLeft, dsmh);
    	dsmh.DSMH[dsmh.tong] = new NodeMonHoc;
    	dsmh.DSMH[dsmh.tong] = p;
    	dsmh.tong++;
        Insert_MH_toArray(p -> pRight, dsmh);
	}
}

//----------DANH SACH CAU HOI DA THUC HIEN------------
typedef struct ChiTietCauHoi
{
    int id;
    char svChon;
} ChiTietCauHoi;

//----------DANH SACH DIEM(DS LIEN KET DON)-----------
typedef struct Diem
{
    char MAMH[16];
    float DIEMTHI;
    Diem *pNext;
    ChiTietCauHoi CAUHOISV[MAXCAUHOI];
} Diem;

typedef struct DSDiem
{
    Diem *pHead = NULL;
    int tong = 0;
} DSDiem;

//----------DANH SACH SINH VIEN(DS LIEN KET DON)------
typedef struct SinhVien
{
    char MSSV[20];
    char HO[20];
    char TEN[20];
    char PASS[20];
    bool PHAI;
    SinhVien *pNext;
    DSDiem DSDIEM;
    void Init(){
    	strcpy(this->MSSV,"");
    	strcpy(this->HO,"");
    	strcpy(this->TEN,"");
    	strcpy(this->PASS,"");
    	this->PHAI=false;
    	this->pNext=NULL;
	}
} SV;

struct NodeSV{
	SV sv;
	NodeSV *next;
};

NodeSV* CreateNodeSV(SV sv){
	NodeSV* node = new NodeSV;
	node->sv = sv;
	node->next = NULL;
	return node;
}

typedef struct DSSinhVien
{
    NodeSV *first;
    NodeSV *last;
    int tong = 0;
    NodeSV *ArrSinhVien[MAXSINHVIEN];
    
    void Init(){
    	this->first = NULL;
		this->last = NULL;
	}
	void Add_SV_Last(NodeSV *node){
		if(this->first == NULL){
			this->first = node;
			this->last = node;
			this->tong++;
		}
		else{
			this->last->next = node;
			this->last = node;
			this->tong++;
		}
	}
	void Insert_DSSV_to_ArrSinhVien(){
		int dem =0;
		for(NodeSV *p = first; p!=NULL; p= p->next){
			ArrSinhVien[dem] = new NodeSV;
			ArrSinhVien[dem] = p;
			dem++;
		}
	}
} DSSinhVien;



//------------DANH SACH LOP(MANG CON TRO)-----------------
typedef struct Lop
{
    char MALOP[20];
    char TENLOP[40];
    DSSinhVien *DSSV = new DSSinhVien;
    int soluong = 0;
} Lop;

typedef struct DSLop
{
    Lop *node[MAXMONHOC];
    int n = 0;

    void Add_Lop(Lop lop)
    {
        if (n > MAXMONHOC)
        {
            cout << "DANH SACH LOP DA DAY!";
        }
        else
        {
            this->node[n] = new Lop;
            strcpy(this->node[n]->MALOP, lop.MALOP);
            strcpy(this->node[n]->TENLOP, lop.TENLOP);
            this->node[n]->DSSV = lop.DSSV;
            this->n++;
        }
    }
    void DeleteAllNode()
    {
        while (this->n > 0)
        {
            this->node[this->n - 1] = NULL;
            this->n--;
        }
    }
    void Init()
    {
        n = 0;
    }
} DSLop;
