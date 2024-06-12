#include "header.h"
#include "SinhVien.h"
#include "HocPhan.h"
#include "TKB.h"

int main() {
    LinkedListSV SV;
    LinkedListHP HP;

    InitListSV (SV);
    InitListHP (HP);

    SinhVien sv1 = {20214232, "Nguyen Van A", "A@edu.com"};
    SinhVien sv2 = {20214235, "Nguyen Van B", "B@edu.com"};
    SinhVien sv3 = {20214236, "Nguyen Van C", "C@edu.com"};
    insertBeginSV (SV, sv1);
    insertBeginSV (SV, sv2);
    insertBeginSV (SV, sv3);

    HocPhan hp1 = {"IT1110", "Tin hoc dai cuong", 4};
    HocPhan hp2 = {"ET2031", "Ky thuat lap trinh C/C++", 2};
    HocPhan hp3 = {"ET2100", "Cau truc du lieu va giai thuat", 2};
    InsertHPBegin (HP, hp1);
    InsertHPBegin (HP, hp2);
    InsertHPBegin (HP, hp3);
}
    
