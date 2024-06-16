#include "header.h"
//#include "SinhVien.h"
#include "HocPhan.h"

void InitListHP(LinkedListHP& H) {
    H = NULL;
}

int isEmptyHP(LinkedListHP H) {
    return H == NULL;
}

void InsertHPBegin(LinkedListHP& H, HocPhan& hp) {
    PNodeHP Q = new NodeHP;
    Q->data = hp;
    if (H==NULL){
        Q->next = NULL;
        H = Q;
    }
    else {
        Q->next = H;
        H = Q;
    }
}

void InsertHPAfter(LinkedListHP& H, const char* targetMaHP, HocPhan& hp) {
    PNodeHP P = searchHP(H, targetMaHP);
    PNodeHP Q = new NodeHP;
    Q->data = hp;
    if (H == NULL) {
        Q->next = NULL;
        H = Q;
        }    
    else {
        if (P == NULL) {
            Q->next = P->next;
            P->next = Q;
        }
    }
}

void InsertHPBefore(LinkedListHP& H, const char* targetMaHP, HocPhan& hp) {
    PNodeHP P = searchHP (H, targetMaHP);
    PNodeHP Q = new NodeHP;
    Q->data = hp;
    if (isEmptyHP(H)) {
        Q->next = NULL;
        H = Q;
    }
    if (P != NULL) {
        Q->data = P->data;
        P->data = hp;
        Q->next = P->next;
        P->next = Q;
    }
}

PNodeHP searchHP(LinkedListHP H, const char* MaHP) {
    PNodeHP P = H;
    while (P != NULL) {
        if (strcmp(P->data.MaHP, MaHP) == 0) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteHocPhan(LinkedListHP& H, const char* MaHP) {
    PNodeHP P = H;
    PNodeHP prev = NULL;

    while (P != NULL && strcmp(P->data.MaHP, MaHP) != 0) {
        prev = P;
        P = P->next;
    }

    if (P == NULL) {
        return; 
    }

    if (prev == NULL) {
        H = H->next;
    } else {
        prev->next = P->next;
    }
    delete P;
}

void display(LinkedListHP H) {
    PNodeHP P = H;
    while (P != NULL) {
        cout << "MaHP: " << P->data.MaHP << ", TenHP: " << P->data.TenHP << ", Tinchi: " << P->data.Tinchi << endl;
        P = P->next;
    }
}