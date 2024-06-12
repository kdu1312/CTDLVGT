#pragma once
#include "HocPhan.h"

struct TKB {
    HocPhan data;
    int Thu;
    int Start, End;
    int Tuan;
    char PhongHoc[100];
    char Kihoc[100];
    long MaLop;
};

struct NodeTKB {
    TKB data;
    NodeTKB* next;
};

typedef NodeTKB* PNodeTKB;
typedef NodeTKB* LinkedListTKB;

void InitListTKB(LinkedListTKB& H); //khởi tạo danh sách sinh viên

int isEmptyTKB(LinkedListTKB H); //kiểm tra rỗng danh sách sinh viên

void insertBeginTKB(LinkedListTKB& H, long MaLop, TKB& TKB); //Thêm 1 sinh viên vào đầu danh sách

void insertAfterTKB(LinkedListTKB& H, long MaLop, TKB& TKB); //Thêm 1 sinh viên vào sau một sinh viên có mssv cho trước

void insertBeforeTKB(LinkedListTKB& H, long MaLop, TKB& TKB);//Thêm 1 sinh viên vào trước một sinh viên có mssv cho trước

PNodeTKB searchTKB(LinkedListTKB H, long MaLop); //Tìm kiếm sinh viên có mssv cho trước

void DelectTKB (LinkedListTKB H, long Malop); //Xóa sinh viên có mssv cho trước

void displayTKB(LinkedListTKB H); //Hiển thị danh sách sinh viên

void DangkyTKB (LinkedListSV& H, long mssv, long MaLop);

