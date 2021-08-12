#define MAXCAUHOI 200
#define MAXMONHOC 100
#define MAXSINHVIEN 100
#include <iostream>
#include <time.h>
using namespace std;
//----------DANH SACH CAU HOI(DS TUYEN TINH)-----------
typedef struct CauHoi
{
    char NOIDUNG[100];
    char A[100];
    char B[100];
    char C[100];
    char D[100];
    char DA[2];
} CauHoi;

typedef struct DSCauHoi
{
    CauHoi dsch[MAXCAUHOI];
    int tong = 0;
    void InsertCauHoi(CauHoi ch){
    	this->dsch[this->tong]=ch;
    	this->tong ++;
	}
	void Init(){
		tong = 0;
	}
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
        if (strcmp(mh.MAMH,p -> mon.MAMH) < 0) Insert_MH(p -> pLeft, mh);
        else if (strcmp(mh.MAMH,p -> mon.MAMH) > 0) Insert_MH(p -> pRight, mh);
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

bool isExist_MH_(NodeMH &p, MonHoc mh){
	if(p!=NULL){
		isExist_MH_(p -> pLeft, mh);
    	if(p->mon.MAMH==mh.MAMH) return false;
        isExist_MH_(p -> pRight, mh);
	}
}
bool isExist_MH(NodeMH &p, MonHoc mh){
	if(isExist_MH_(p,mh)==false) return false;
	return true;
}


void Remove_MH_case3(NodeMH & p, NodeMH &rp) { // tim nut thay the nut can phai xoa (nut cuc trai cua nhanh phai nut can xoa)
    if (p -> pLeft != NULL) { // neu chua phai la cuc trai thi duyet tiep
        Remove_MH_case3(p -> pLeft, rp);
    } else {
        rp -> mon = p -> mon; //gan nut can xoa bang nut thay the (that ra la xoa nut thay the chu k phai la xoa p)
        rp = p; // gan lai dia chi con tro
        p = p -> pRight; // neu nut thay the co nhanh phai thi gan lai nhanh phai vao nut thay the
    }
}
void Remove_MH(NodeMH & p, char MAMH[]) {
    if (p == NULL) printf("\n\t\tKhong tim thay mon hoc can xoa!\n");
    else {
        if (strcmp(MAMH,p -> mon.MAMH) < 0) Remove_MH(p -> pLeft, MAMH);
        else if (strcmp(MAMH,p -> mon.MAMH) > 0) Remove_MH(p -> pRight, MAMH);
        else { // da tim thay ma mon hoc can xoa
            NodeMH rp = p;
            if (rp -> pLeft == NULL) { // p la nut la hoac nut co 1 cay con ben phai
                p = rp -> pRight;
            } else if (rp -> pRight == NULL) { // p la nut la hoac nut co 1 cay con ben trai
                p = rp -> pLeft;
            } else { // p co 2 cay con ben trai va phai
                Remove_MH_case3(rp -> pRight, p);
            }
            delete rp;
        }
    }
}

void Traverse_LNR(NodeMH & p) {
    if (p != NULL) {
        Traverse_LNR(p -> pLeft);
        printf("\t%s\t%s\t\n", p -> mon.MAMH, p -> mon.TENMH);
        Traverse_LNR(p -> pRight);
    }
}

void DeleteAllMonHoc(NodeMH &node){
	if(node != NULL){
		DeleteAllMonHoc(node->pLeft);
		DeleteAllMonHoc(node->pRight);
		delete node;
//		node = NULL;
	}
}

//----------DANH SACH CAU HOI DA THUC HIEN------------
typedef struct ChiTietCauHoi
{
    int id;
    char svChon[2];
} ChiTietCauHoi;

//----------DANH SACH DIEM(DS LIEN KET DON)-----------
typedef struct Diem
{
    char MAMH[16];
    float DIEMTHI;
    int soCau = 0;
    ChiTietCauHoi CAUHOISV[MAXCAUHOI];
} Diem;

struct NodeDiem{
    Diem diem;
    NodeDiem * pNext;
};

typedef struct DSDiem
{
    NodeDiem *pHead = NULL;
    int tong = 0;
    bool MonDaThi(char mamh[]){
    	for(NodeDiem *p = pHead; p!=NULL; p = p->pNext){
    		if(strcmp(p->diem.MAMH,mamh)==0) return true;
		}
		return false;
	}
    void Insert_Diem_First(Diem & diem) {
	    NodeDiem * node = new NodeDiem;
	    node -> diem = diem;
	    node -> pNext = this->pHead;
	    this->pHead = node;
	}
	void Insert_Diem_After(NodeDiem * & node,Diem & diem) {
	
	    if (node == NULL) {
	        printf("VI TRI THEM KHONG PHU HOP!");
	        return;
	    }
	
	    NodeDiem * nodeNew = new NodeDiem;
	    nodeNew -> diem = diem;
	    nodeNew -> pNext = node -> pNext;
	    node -> pNext = nodeNew;
	}
	void Insert_Diem_Last(Diem & diem) {
	    if (this->pHead == NULL) {
	        Insert_Diem_First(diem);
	    } else {
	        NodeDiem * p;
	        for (p = pHead; p -> pNext != NULL; p = p -> pNext);
	        Insert_Diem_After(p, diem);
	    }
	    tong++;
	}
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
	bool LoginSinhVien(char username[], char password[]){
		for(NodeSV *p = first; p!=NULL; p= p->next){
			if(strcmp(p->sv.MSSV,username)==0 && strcmp(p->sv.PASS,password)==0) return true;
		}
		return false;
	}
	SV SearchSinhVien(char masosv[]){
		SV sv;
		for(NodeSV *p = first; p!=NULL; p= p->next){
			if(strcmp(p->sv.MSSV,masosv)==0) return p->sv;
		}
		return sv;
	}
	void UpdateSinhVien(SV sv){
		for(NodeSV *p = first; p!=NULL; p= p->next){
			if(strcmp(p->sv.MSSV,sv.MSSV)==0) {
				p->sv = sv;
			}
		}
	}
} DSSinhVien;



//------------DANH SACH LOP(MANG CON TRO)-----------------
typedef struct Lop
{
    char MALOP[20];
    char TENLOP[40];
    DSSinhVien *DSSV;
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
    bool LoginSinhVien(char username[], char password[]){
    	for(int i=0; i<this->n; i++)
		{
    		bool check = this->node[i]->DSSV->LoginSinhVien(username,password);
    		if(check) return true;
		}
		return false;
	}
	SV SearchSinhVien(char masosv[]){
		SV sv;
		for(int i=0; i<this->n; i++)
		{
    		sv = this->node[i]->DSSV->SearchSinhVien(masosv);
    		if(strcmp(sv.MSSV,masosv)==0) return sv;
		}
		return sv;
	}
	void UpdateSinhVien(SV sv){
		for(int i=0; i<this->n; i++)
		{
    		this->node[i]->DSSV->UpdateSinhVien(sv);
		}
	}
    void DeleteAllNode()
    {
        while (this->n > 0)
        {
            this->node[this->n - 1] = NULL;
            delete this->node[this->n - 1];
            this->n--;
        }
    }
    void Init()
    {
        n = 0;
    }
} DSLop;

// struct option test
typedef struct OptionTest{
	int soCau;
	int soPhut;
}opTest;
