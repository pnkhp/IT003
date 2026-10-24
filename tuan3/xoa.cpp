
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

void NhapNgay(NGAY &);
void XuatNgay(NGAY );
void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN );
NODE* CreateNode(SINHVIEN );
void CreateEmptyList(LIST &);
void AddTail(LIST&, NODE* );
void XuatDS(LIST );
void NhapDS(LIST &, int n);
bool Xoa_TheoHoTen(LIST &, string);

int main() {
    LIST L;
    int n;
    string hoten;

    getline(cin, hoten);
    cin >> n ;

    NhapDS(L, n);

    Xoa_TheoHoTen(L, hoten);

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

bool Xoa_TheoHoTen(LIST &L, string x) {
    NODE* q = nullptr;
    bool daXoa = false;

    for (NODE* p = L.pHead; p != nullptr; ) {
        if (p->key.HoTen != x) {
            q = p;
            p = p->pNext;
        } else {
            NODE* tiep = p->pNext;

            if (q == nullptr)
                L.pHead = tiep;
            else
                q->pNext = tiep;

            if (p == L.pTail)
                L.pTail = q;

            delete p;
            p = tiep;
            daXoa = true;
        }
    }

    return daXoa;
}