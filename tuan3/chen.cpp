
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &a);
void XuatNgay(NGAY a);
void NhapSinhVien(SINHVIEN &a);
void XuatSinhVien(SINHVIEN a);
NODE* CreateNode(SINHVIEN x);
void CreateEmptyList(LIST &L);
void AddTail(LIST& l, NODE* p);
void XuatDS(LIST L);
void NhapDS(LIST &L, int n);
void ChenGiam(LIST &, SINHVIEN);

int main() {
    LIST L;
    int n;
    SINHVIEN sv;

    NhapSinhVien(sv);

    cin >> n ;
    NhapDS(L, n);

    ChenGiam(L, sv);

    XuatDS(L);

    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}

NODE* CreateNode(SINHVIEN x){
    NODE* p = new NODE;
    p->key = x;
    p ->pNext = nullptr;
    return p;
}
void CreateEmptyList(LIST &L){
    L.pHead = L.pTail = nullptr;
}
void AddTail(LIST& L, NODE* p){
    if(L.pHead == nullptr){
        L.pHead = L.pTail = p;
    }
    else{
        L.pTail->pNext=p;
        L.pTail=p;
    }
}
void XuatDS(LIST L){
    if(L.pHead == nullptr) {cout<<"Empty List."; return;}
    else{
        for(NODE* p = L.pHead; p!=nullptr; p = p->pNext){
            XuatSinhVien(p->key);
            cout<<"\n";

        }
    }
}
void NhapDS(LIST &L, int x){
    CreateEmptyList(L);
    for(int i=0; i<x;++i){
        SINHVIEN sv;
        NhapSinhVien(sv);
        AddTail(L, CreateNode(sv));
    }
}
void SapXep(LIST &L){
    for(NODE* p = L.pHead; p!=nullptr; p = p->pNext){
            for(NODE* q = p->pNext; q!=nullptr; q = q->pNext){
                if(p->key.MASV<q->key.MASV) {SINHVIEN tmp = p->key; p->key = q->key; q->key=tmp;}
            }
        }
}

void ChenGiam(LIST &L, SINHVIEN x){
  
    AddTail(L, CreateNode(x));
    SapXep(L);
}