#include "header.h"
#include "SinhVien.h"

void InitList(LinkedListSV& H) {
    H = NULL;
}

int isEmpty(LinkedListSV H) {
    return (H == NULL);
}

void insertBeginSV(LinkedListSV& H, SinhVien& sv) {
    PNodeSV Q = new NodeSV;
    Q->data = sv;
    if (isEmpty(H)) {
        Q->next = NULL;
        H = Q;
    }
    else {
        Q->next = H;
        H = Q;
    }
}

void insertAfterSV(LinkedListSV& H, long mssvtarget, SinhVien& sv) {
    PNodeSV P = searchSV(H, mssvtarget);
    PNodeSV Q = new NodeSV;
    Q->data = sv;
    if (isEmpty(H)) {
        Q->next = NULL;
        H = Q;
    }
    else {
        if (P != NULL) {
            Q->next = P->next;
            P->next = Q;
        }
    }
}

void insertBeforeSV(LinkedListSV& H, long mssvtarget, SinhVien& sv) {
    PNodeSV P = searchSV(H, mssvtarget);
    PNodeSV Q = new NodeSV;
    Q->data = sv;
    if (isEmpty(H)) {
        Q->next = NULL;
        H = Q;
    }
    if (P != NULL) {
        Q->data = P->data;
        P->data = sv;
        Q->next = P->next;
        P->next = Q;
    }
}

PNodeSV searchSV(LinkedListSV H, long mssv) {
    PNodeSV P = H;
    while (P != NULL) {
        if (P->data.mssv == mssv)
            return P;
        else
            P = P->next;
    }
    return NULL;
}

void DelectSV (LinkedListSV H, long mssv) {
    PNodeSV P = searchSV(H, mssv);
    if (isEmpty(H))
        cout << "rỗng";
    if (H == P && P->next == NULL) {
        H = NULL;
        delete P;
    }
    if (H == P) {
        H = P->next;
        delete P;
    } else {
    PNodeSV R = H;
    while (R->next != P)
        R = R->next;
    R->next = P->next;
    delete P;
    }
}

void displaySV(LinkedListSV H) {
    PNodeSV P = H;
    while (P != NULL) {
        cout << P->data.mssv << "  " << P->data.hoTen << "  " << P->data.email << endl;
        P = P->next;
    }
}
