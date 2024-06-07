#pragma once
#include "header.h"
#include "HocPhan.h"

struct SinhVien {
    long mssv;
    char hoTen[100];
    char email[100];
};

struct NodeSV {
    SinhVien data;
    NodeSV* next;
    NodeTKB* TKB;
};

typedef NodeSV* LinkedListSV;
typedef NodeSV* PNodeSV;

void InitListSV(LinkedListSV& H); //khởi tạo danh sách sinh viên

int isEmptySV(LinkedListSV H); //kiểm tra rỗng danh sách sinh viên

void insertBeginSV(LinkedListSV& H, long mssvtarget, long mssv, const char* hoTen, const char* email); //Thêm 1 sinh viên vào đầu danh sách

void insertAfterSV(LinkedListSV& H, long mssvtarget, long mssv, const char* hoTen, const char* email); //Thêm 1 sinh viên vào sau một sinh viên có mssv cho trước

void insertBeforeSV(LinkedListSV& H, long mssvtarget, long mssv, const char* hoTen, const char* email);//Thêm 1 sinh viên vào trước một sinh viên có mssv cho trước

PNodeSV searchSV(LinkedListSV H, long mssv); //Tìm kiếm sinh viên có mssv cho trước

void DelectSV (LinkedListSV H, long mssv); //Xóa sinh viên có mssv cho trước

void displaySV(LinkedListSV H); //Hiển thị danh sách sinh viên