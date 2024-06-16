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

void setINFO(string MSSV, string& pass) {
    int id = 0;
    fstream link;
    std::string temp[100];
    int n = 0;

    // Mở tệp info.txt để đọc thông tin
    link.open("info.txt", ios::in);
    if (!link.is_open()) {
        cerr << "Khong mo duoc file info.txt" << endl;
        return;
    }

    // Đọc dữ liệu từ tệp vào mảng temp
    while (link >> temp[n] && n < 100) {
        n++;
    }
    link.close();

    // Cập nhật thông tin sinh viên tại vị trí id
    if (id >= 0 && id < n) {
        temp[id] = MSSV + " " + pass;
    } else {
        cerr << "ID khong hop le" << endl;
        return;
    }

    // Ghi lại dữ liệu đã cập nhật vào tệp info.txt
    link.open("info.txt", ios::out | ios::trunc);
    if (!link.is_open()) {
        cerr << "Khong mo duoc file info.txt" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        link << temp[i] << endl;
    }
    link.close();
}