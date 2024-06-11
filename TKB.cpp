#include "header.h"
#include "TKB.h"

//Kiểm tra trùng lịch
bool KiemTraTrungLich(PNodeTKB tkb, const TKB& tkbMoi){
    PNodeTKB P = tkb; // cho P chạy để tìm ra
    while (P != nullptr){
        if(P->data.Thu == tkb->data.Thu && tkbMoi.Start < P->data.End && tkbMoi.End > P->data.Start )
        return 1; // trùng lịch
        P = P->next;
    } 
    return 0;
}

//Hàm đọc TKB từ file MaLop cho trước
void DocTKB(DSTKB& tkb, const char* MaLop){
    ifstream file_TKB;
    int vitriLop = 0;
    // Mở file chứa tài khoản và mật khẩu có sẵn
    file_TKB.open("tkb.txt");
    if (!file_TKB.is_open()) {
        cout << "Khong the mo file tkb.txt" << endl;
        return -1;
    }
    file_TKB >> tkb.n;
    tkb.a = new TKB[tkb.n];
    for(int i = 0; i < tkb.n ; i++){
        if(tkb.a[i].MaLop == MaLop){
            vitriLop = i;
        }
    }
    getline(file_TKB, tkb.a[vitriLop].MaLop, '#');
    getline(file_TKB, tkb.a[vitriLop].data.MaHP, '#');
    getline(file_TKB, tkb.a[vitriLop].data.TenHP, '#');
    getline(file_TKB, tkb.a[vitriLop].data.Tinchi, '#');
    getline(file_TKB, tkb.a[vitriLop].Thu, '#');
    getline(file_TKB, tkb.a[vitriLop].Start, '#');
    getline(file_TKB, tkb.a[vitriLop].End, '#');
    getline(file_TKB, tkb.a[vitriLop].PhongHoc, '#');

    file_TKB.close();
}

// Hàm thêm 1 lớp vào TKB của Sinh viên
PNodeTKB ThemHP(PNodeSV sv, const TKB& tkbMoi){
    if (KiemTraTrungLich(sv->TKB, tkbMoi)) {
        cout << "Lớp học mới trùng lịch với một lớp học đã có." << endl;
        return;
    }
    PNodeTKB P = new NodeTKB;
    P->data = tkbMoi;
    P->next =sv->TKB;
    sv->TKB = P;
    cout << "Đã thêm lớp học vào thời khóa biểu của sinh viên." << endl;
}



// Hàm tìm lớp học theo mã lớp học
PNodeTKB TimLopHoc(PNodeSV sv, const char* MaLop) {
    PNodeTKB P = sv->TKB; // tạo 1 node P cho chạy
    while (P != nullptr) {
        if (strcmp(P->data.MaLop, MaLop) == 0) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
// Hàm xóa lớp học theo mã lớp học
void XoaLopHoc(PNodeSV sv, const char* MaLop) {
    PNodeTKB Q = nullptr; 
    PNodeTKB P = sv->TKB;

    while (P != nullptr) {
        if (strcmp(P->data.MaLop, MaLop) == 0) {
            if (Q == nullptr) {
                sv->TKB = P->next;
            } else {
                Q->next = P->next;
            }
            delete P;
            cout << "Đã xóa lớp học khỏi thời khóa biểu của sinh viên." << endl;
            return;
        }
        Q = P;
        P = P->next;
    }

    cout << "Không tìm thấy lớp học cần xóa trong thời khóa biểu của sinh viên." << endl;
}

void inThoiKhoaBieu(PNodeSV sv) { // sau dùng display của Học Phần
    PNodeTKB P = sv->TKB ;

    if (P == nullptr) {
        cout << "Thời khóa biểu của sinh viên không có môn học nào." << endl;
        return;
    }

    cout << "Thời khóa biểu của sinh viên:" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "| MaHP |     TenHP     | Tinchi | Thu | Start | End | Tuan |  PhongHoc  |  Kihoc  |" << endl;
    cout << "--------------------------------------------" << endl;

    while (P != nullptr) {
        cout << "| " << P->data.data.MaHP;
        cout << "| " << P->data.data.TenHP;
        cout << "| " << P->data.data.Tinchi;
        cout << "| " << P->data.Thu;
        cout << "| " << P->data.Start;
        cout << "| " << P->data.End;
        cout << "| " << P->data.Tuan;
        cout << "| " << P->data.PhongHoc;
        cout << "| " << P->data.Kihoc << "|" << endl;
        P = P->next;
    }
    cout << "--------------------------------------------" << endl;
}
