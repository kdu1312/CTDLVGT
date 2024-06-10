#include "SinhVien.h"

struct HocPhan {
    char MaHP[100];
    char TenHP[100];
    int Tinchi;
};

struct NodeHP {
    HocPhan data;
    PNodeHP next;
};

typedef NodeHP* PNodeHP;
typedef NodeHP* LinkedListHP;

void InitListHP(LinkedListHP& H) {
    H = NULL;
}

int isEmptyHP(LinkedListHP H) {
    return H == NULL;
}

void InsertHPBegin(LinkedListHP& H, const char* maHP, const char* tenHP, int tinchi) {
    PNode Q = new NodeHP;
    Q->data.Tinchi = tinchi;
    strcpy(Q->data.MaHP, maHP);
    strcpy(Q->data.TenHP, tenHP);  
    if (H==NULL){
        Q->next = NULL;
        H = Q;
    }
    else {
        Q->next = H;
        H = Q;
    }
}
void InsertHPAfter(LinkedListHP& H, const char* targetMaHP, const char* maHP, const char* tenHP, int tinchi) {
    PNode P = searchHP(H, targetMaHP);
    PNode Q = new NodeHP;
    Q->data.Tinchi = tinchi;
    strcpy(newNode->data.MaHP, maHP);
    strcpy(newNode->data.TenHP, tenHP);
    if (H == NULL) {
        Q->next = NULL;
        H = Q;
        }    
    else {
        if (P == NULL) return NULL;
            Q->next = P->next;
            P->next = Q;
    }
    return Q;
}

void InsertHPBefore(LinkedListHP& H, const char* targetMaHP, const char* maHP, const char* tenHP, int tinchi) {
    PNode P = searchHP (H, targetMAHP);
    PNode Q = new NodeHP;
    Q->data.Tinchi = tinchi;
    strcpy(Q->data.MaHP, maHP);
    strcpy(Q->data.TenHP, tenHP);
    if (strcmp(H->data.MaHP, targetMaHP) == 0) {
        InsertHPBegin(H, maHP, tenHP, tinchi);
        return;
     }

    NodeHP* prev = NULL;
    NodeHP* P = H;

    while (P != NULL && strcmp(P->data.MaHP, targetMaHP) != 0) {
        prev = P;
        P = P->next;
    }

    if (P != NULL) {
        PNodeHP newNode = new NodeHP;
        strcpy(newNode->data.MaHP, maHP);
        strcpy(newNode->data.TenHP, tenHP);
        newNode->data.Tinchi = tinchi;
        prev->next = newNode;
        newNode->next = P;
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

