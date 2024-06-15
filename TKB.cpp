#include "header.h"
#include "TKB.h"

// Kiểm tra trùng lịch
bool KiemTraTrungLich(PNodeTKB tkb, const TKB& tkbMoi) {
    PNodeTKB P = tkb; 
    while (P != nullptr) {
        if (P->data.Thu == tkbMoi.Thu && tkbMoi.Start < P->data.End && tkbMoi.End > P->data.Start) {
            return true; // trùng lịch
        }
        P = P->next;
    }
    return false;
}

// Hàm đọc TKB từ file MaLop cho trước
void DocTKB(DSTKB& tkb, const char* MaLop) {
    ifstream file_TKB;
    int vitriLop = 0;
    // Mở file chứa tài khoản và mật khẩu có sẵn
    file_TKB.open("tkb.txt");
    if (!file_TKB.is_open()) {
        cout << "Không thể mở file tkb.txt" << endl;
        return;
    }
    file_TKB >> tkb.n;
    tkb.a = new TKB[tkb.n];
    for (int i = 0; i < tkb.n; i++) {
        file_TKB >> tkb.a[i].MaLop;
        file_TKB >> tkb.a[i].data.MaHP;
        file_TKB >> tkb.a[i].data.TenHP;
        file_TKB >> tkb.a[i].data.Tinchi;
        file_TKB >> tkb.a[i].Thu;
        file_TKB >> tkb.a[i].Start;
        file_TKB >> tkb.a[i].End;
        file_TKB >> tkb.a[i].PhongHoc;
        if (strcmp(tkb.a[i].MaLop, MaLop) == 0) {
            vitriLop = i;
        }
    }
    file_TKB.close();
}

// Hàm thêm 1 lớp vào TKB của Sinh viên
PNodeTKB ThemHP(PNodeSV sv, const TKB& tkbMoi) {
    if (KiemTraTrungLich(sv->tkb, tkbMoi)) {
        cout << "Lớp học mới trùng lịch với một lớp học đã có." << endl;
        return sv->tkb;
    }
    PNodeTKB P = new NodeTKB;
    P->data = tkbMoi;
    P->next = sv->tkb;
    sv->tkb = P;
    cout << "Đã thêm lớp học vào thời khóa biểu của sinh viên." << endl;
    return sv->tkb;
}
// Hàm tìm lớp học theo mã lớp học
PNodeTKB TimLopHoc(PNodeSV sv, const char* MaLop) {
    PNodeTKB P = sv->tkb; 
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
    PNodeTKB P = sv->tkb;

    while (P != nullptr) {
        if (strcmp(P->data.MaLop, MaLop) == 0) {
            if (Q == nullptr) {
                sv->tkb = P->next;
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

void InThoiKhoaBieu(PNodeSV sv) {
    PNodeTKB P = sv->tkb;

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
        cout << " | " << P->data.data.TenHP;
        cout << " | " << P->data.data.Tinchi;
        cout << " | " << P->data.Thu;
        cout << " | " << P->data.Start;
        cout << " | " << P->data.End;
        cout << " | " << P->data.Tuan;
        cout << " | " << P->data.PhongHoc;
        cout << " | " << P->data.Kihoc << " |" << endl;
        P = P->next;
    }
    cout << "--------------------------------------------" << endl;
}
