#include "header.h"
#include "TKB.h"

// Hàm kiểm tra học phần đã tồn tại trong TKB hay chưa
bool hocPhanDaTonTaiTrongFile(const char* MaHP) {
    ifstream file("TKB.txt");
    if (!file.is_open()) {
        cout << "Không thể mở file!" << endl;
        return false;
    }

    char fileMaHP[100];
    char fileTenHP[100];
    int fileTinchi;

    while (file >> fileMaHP >> fileTenHP >> fileTinchi) {
        if (strcmp(fileMaHP, MaHP) == 0) {
            file.close();
            return true; // Học phần đã tồn tại trong file
        }
    }

    file.close();
    return false; // Học phần không tồn tại trong file
}

// Hàm thêm học phần vào TKB của sinh viên
void themHocPhanVaoTKB(PNodeSV sv, const char* MaHP, const char* TenHP, int Tinchi) {
    // Kiểm tra học phần đã tồn tại trong TKB hay chưa
    if (hocPhanDaTonTaiTrongFile(MaHP)) {
        cout << "Học phần đã tồn tại trong thời khóa biểu của sinh viên." << endl;
        return;
    }

    // Thêm học phần mới vào TKB
    PNodeTKB P = new NodeTKB();
    P->next = sv->TKB;
    sv->TKB = P;

    cout << "Đã thêm học phần vào thời khóa biểu của sinh viên." << endl;
}

// Hàm tìm học phần theo mã học phần
PNodeTKB timHocPhanTheoMaHP(PNodeSV sv, const char* MaHP) {
    PNodeTKB P = sv->TKB;
    while (P != nullptr) {
        if (strcmp(P->data.data.MaHP, MaHP) == 0) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

// Hàm xóa học phần theo mã học phần
void xoaHocPhanTheoMaHP(PNodeSV sv, const char* MaHP) {
    PNodeTKB Q = nullptr;
    PNodeTKB P = sv->TKB;

    while (P != nullptr) {
        if (strcmp(P->data.data.MaHP, MaHP) == 0) {
            if (Q == nullptr) {
                sv->TKB = P->next;
            } else {
                Q->next = P->next;
            }
            delete Q;
            cout << "Đã xóa học phần khỏi thời khóa biểu của sinh viên." << endl;
            return;
        }
        Q = P;
        Q = Q->next;
    }

    cout << "Không tìm thấy học phần cần xóa trong thời khóa biểu của sinh viên." << endl;
}

// Hàm đăng ký học phần
void dangKyHocPhan(PNodeSV sv, const char* MaHP, const char* TenHP, int Tinchi) {
    // Thêm học phần vào TKB của sinh viên
    themHocPhanVaoTKB(sv, MaHP, TenHP, Tinchi);

    // Lưu thông tin học phần vào file
    ofstream file("TKB.txt", ios::app);
    if (!file.is_open()) {
        cout << "Không thể mở file!" << endl;
        return;
    }

    file << MaHP << " " << TenHP << " " << Tinchi << endl;
    file.close();
}

// Hàm in thời khóa biểu từ file 
void inTKBtuFile(PNodeSV sv) {
    ifstream file("TKB.txt");
    if (!file.is_open()) {
        cout << "Không thể mở file!" << endl;
        return;
    }

    char MaHP[100];
    char TenHP[100];
    int Tinchi;

    while (file >> MaHP >> TenHP >> Tinchi) {
         cout << "Mã học phần: " << MaHP << ", Tên học phần: " << TenHP << ", Số tín chỉ: " << Tinchi << endl;
    }

    file.close();
    cout << "Đã thêm các học phần từ file vào thời khóa biểu của sinh viên." << endl;
}
