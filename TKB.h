#pragma once
#include "HocPhan.h"

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