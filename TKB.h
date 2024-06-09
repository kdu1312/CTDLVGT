//#pragma once
#include "HocPhan.h"
#include "tkb.txt"

struct TKB {
    HocPhan data;
    int Thu;
    int Start, End;
    int Tuan;
    char PhongHoc[100];
    char Kihoc[100];
};

struct NodeTKB {
    TKB data;
    NodeTKB* next;
};

typedef NodeTKB* PNodeTKB;

// Hàm kiểm tra học phần đã tồn tại trong TKB hay chưa
bool hocPhanDaTonTaiTrongFile(const char* MaHP);

// Hàm thêm học phần vào TKB của sinh viên
void themHocPhanVaoTKB(PNodeSV sv, const char* MaHP, const char* TenHP, int Tinchi);

// Hàm tìm học phần theo mã học phần
PNodeTKB timHocPhanTheoMaHP(PNodeSV sv, const char* MaHP);

// Hàm xóa học phần theo mã học phần
void xoaHocPhanTheoMaHP(PNodeSV sv, const char* MaHP);

// Hàm đăng ký học phần
void dangKyHocPhan(PNodeSV sv, const char* MaHP, const char* TenHP, int Tinchi);

// Hàm in thời khóa biểu từ file 
void inTKBtuFile(PNodeSV sv) ;

/*
// Thêm Học Phần vào Thời Khóa Biểu của 1 sinh viên
void ThemHP(PNodeSV SV, const char* MaHP, const char* TenHP, int Tinchi, int Thu, int Start, int End, int Tuan, const char* PhongHoc, const char* Kihoc);

// Tìm học phần trong TKB trả về con trỏ trỏ vào HP đó
PNodeTKB searchTKB  (PNodeSV SV, const char* MaHP);

// Xóa học phần trong tkb của Sinh Viên
void DeleteTKB(PNodeSV& SV, const char* MaHP);

//Hiển thị ra màn hình thời khóa biểu 
void displayTKB(PNodeSV SV);
*/


