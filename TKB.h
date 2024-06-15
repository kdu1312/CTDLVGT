//#pragma once
#include "HocPhan.h"
#include "tkb.txt"
#include "SinhVien.h"

struct TKB {
    HocPhan data;
    int Thu;
    int Start, End;
    int Tuan;
    char PhongHoc[100];
    char Kihoc[100];
    char MaLop[100];
};
struct DSTKB{
   TKB *a;
   int n; 
};

struct NodeTKB {
    TKB data;
    NodeTKB* next;
};

typedef NodeTKB* PNodeTKB;

// Hàm thêm lớp học vào TKB của sinh viên
PNodeTKB ThemHPX(PNodeSV sv, const TKB& tkbMoi);

// Hàm xóa 1 lớp theo mã lớp học
void XoaLopHoc(PNodeSV sv, const char* MaLop);

// Hàm tìm lớp theo mã lớp học
PNodeTKB TimLopHoc(PNodeSV sv, const char* MaLop);

// Hàm in thời khóa biểu
void inThoiKhoaBieu(PNodeSV sv);

