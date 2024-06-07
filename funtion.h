#pragma once
#include "SinhVien.h"
#include "TKB.h"
#include "HocPhan.h"
#include "dangnhap.h"

void processMSSV(long mssv){
    long mssvt = mssv;
}
;
PNodeSV searchSV(LinkedListSV H, long mssvt) {
    PNodeSV P = H;
    while (P != NULL) {
        if (P->data.mssv == mssvt)
            return P;
        else
            P = P->next;
    }
    return NULL;
}

