#include "header.h"
#include "TKB.h"
#include "SinhVien.h"

// Hàm kiểm tra xem lớp học có trùng thời gian hay không
bool KiemTraTrungLich(PNodeTKB tkb, const TKB& tkbMoi) {
    PNodeTKB P = tkb;
    while (P != nullptr) {
        if (P->data.Thu == tkbMoi.Thu &&
            tkbMoi.Start < tkb->data.End && tkbMoi.End > tkb->data.Start) {
            return true; // Trùng lịch
        }
        P = P->next;
    }
    return false; // Không trùng lịch
}

// Hàm thêm lớp học vào TKB của sinh viên
void ThemLH(PNodeSV sv, const TKB& tkbMoi) {
    if (KiemTraTrungLich(sv->TKBx, tkbMoi)) {
        cout << "Lớp học mới trùng lịch với một lớp học đã có." << endl;
        return;
    }

    PNodeTKB Q = new NodeTKB();
    Q->data = tkbMoi;
    Q->next = sv->TKBx;
    sv->TKBx = Q;

    ofstream file("TKB.txt", ios::app);
    if (!file.is_open()) {
        cout << "Không thể mở file!" << endl;
        return;
    }

    file << tkbMoi.data.MaHP << " " << tkbMoi.data.TenHP << " " << tkbMoi.data.Tinchi << " "
         << tkbMoi.Thu << " " << tkbMoi.Start << " " << tkbMoi.End << " " << tkbMoi.Tuan << " "
         << tkbMoi.PhongHoc << " " << tkbMoi.Kihoc << " " << tkbMoi.MaLop << endl;
    file.close();

    cout << "Đã thêm lớp học vào thời khóa biểu của sinh viên." << endl;
}

// Hàm tìm lớp học theo mã lớp học
PNodeTKB TimLopHoc(PNodeSV sv, const char* MaHP) {
    PNodeTKB P = sv->TKBx;
    while (P != nullptr) {
        if (strcmp(P->data.data.MaHP, MaHP) == 0) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

// Hàm xóa lớp học theo mã lớp học
void XoaLopHoc(PNodeSV sv, const char* MaHP) {
    PNodeTKB Q = nullptr;
    PNodeTKB P = sv->TKBx;

    while (P != nullptr) {
        if (strcmp(P->data.data.MaHP, MaHP) == 0) {
            if (Q == nullptr) {
                sv->TKBx = P->next;
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

// Hàm đọc thời khóa biểu từ file và thêm vào TKB của sinh viên
void docTKBtuFile(PNodeSV sv) {
    ifstream file("TKB.txt");
    if (!file.is_open()) {
        cout << "Không thể mở file!" << endl;
        return;
    }

    char MaHP[100];
    char TenHP[100];
    int Tinchi;
    int Thu;
    int Start;
    int End;
    int Tuan;
    char PhongHoc[100];
    char Kihoc[100];
    char MaLop[100];

    while (file >> MaHP >> TenHP >> Tinchi >> Thu >> Start >> End >> Tuan >> PhongHoc >> Kihoc >> MaLop) {
        TKB tkbMoi;
        strcpy(tkbMoi.data.MaHP, MaHP);
        strcpy(tkbMoi.data.TenHP, TenHP);
        tkbMoi.data.Tinchi = Tinchi;
        tkbMoi.Thu = Thu;
        tkbMoi.Start = Start;
        tkbMoi.End = End;
        tkbMoi.Tuan = Tuan;
        strcpy(tkbMoi.PhongHoc, PhongHoc);
        strcpy(tkbMoi.Kihoc, Kihoc);
        strcpy(tkbMoi.MaLop, MaLop);

        ThemLH(sv, tkbMoi);
    }

    file.close();
    cout << "Đã thêm các lớp học từ file vào thời khóa biểu của sinh viên." << endl;
}

// Hàm in ra thời khóa biểu từ file
void inThoiKhoaBieuTuFile(const char* MaLop) {
    ifstream file("TKB.txt");
    if (!file.is_open()) {
        cout << "Không thể mở file!" << endl;
        return;
    }

    char MaHP[100];
    char TenHP[100];
    int Tinchi;
    int Thu;
    int Start;
    int End;
    int Tuan;
    char PhongHoc[100];
    char Kihoc[100];
    char fileMaLop[100];

    cout << "Thời khóa biểu của lớp " << MaLop << ":\n";
    while (file >> MaHP >> TenHP >> Tinchi >> Thu >> Start >> End >> Tuan >> PhongHoc >> Kihoc >> fileMaLop) {
        if (strcmp(fileMaLop, MaLop) == 0) {
            cout << "Mã HP: " << MaHP << ", Tên HP: " << TenHP << ", Tín chỉ: " << Tinchi
                 << ", Thứ: " << Thu << ", Bắt đầu: " << Start << ", Kết thúc: " << End 
                 << ", Tuần: " << Tuan << ", Phòng: " << PhongHoc << ", Kì học: " << Kihoc << endl;
        }
    }

    file.close();
}
