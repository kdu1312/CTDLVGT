#pragma once
#include "SinhVien.h"

struct HocPhan {
    char MaHP[100];
    char TenHP[100];
    int Tinchi;
};

struct NodeHP {
    HocPhan data;
    NodeHP* next;
};

typedef NodeHP* PNodeHP;
typedef NodeHP* LinkedListHP;

void InitListHP(LinkedListHP& H);

int isEmptyHP(LinkedListHP H);

void InsertHPBegin(LinkedListHP& H, HocPhan& hp);

void InsertHPAfter(LinkedListHP& H, const char* targetMaHP, HocPhan& hp); // thêm học phần vào sau một học phần có mahp cho trước

void InsertHPBefore(LinkedListHP& H, const char* targetMaHP, HocPhan& hp);

void deleteHocPhan(LinkedListHP& H, const char* MaHP);

PNodeHP searchHP(LinkedListHP H, const char* MaHP);

void display(LinkedListHP H);


