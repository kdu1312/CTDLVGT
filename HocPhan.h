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
typedef NodeSV* LinkedListHP;

void InitListHP(LinkedListHP& H);

int isEmptyHP(LinkedListHP H);

void InsertHPBegin(LinkedListHP& H, const char* maHP, const char* tenHP, int tinchi);

void InsertHPAfter(LinkedListHP& H, const char* targetMaHP, const char* maHP, const char* tenHP, int tinchi);

void InsertHPBefore(LinkedListHP& H, const char* targetMaHP, const char* maHP, const char* tenHP, int tinchi);

PNodeHP searchHP(LinkedListHP H, const char* MaHP);

void deleteHocPhan(LinkedListHP& H, const char* MaHP);

void display(LinkedListHP H);


