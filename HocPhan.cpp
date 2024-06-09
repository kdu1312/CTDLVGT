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

void InitListHP(LinkedListHP& H) {
    H = nullptr;
}

int isEmptyHP(LinkedListHP H) {
    return H == nullptr;
}

void InsertHPBegin(LinkedListHP& H, const char* maHP, const char* tenHP, int tinchi) {
    NodeHP* newNode = new NodeHP;
    strcpy(newNode->data.MaHP, maHP);
    strcpy(newNode->data.TenHP, tenHP);
    newNode->data.Tinchi = tinchi;
    newNode->next = H;
    H = newNode;
}

void InsertHPAfter(LinkedListHP& H, const char* targetMaHP, const char* maHP, const char* tenHP, int tinchi) {
    NodeHP* current = searchHP(H, targetMaHP);
    if (current != nullptr) {
        NodeHP* newNode = new NodeHP;
        strcpy(newNode->data.MaHP, maHP);
        strcpy(newNode->data.TenHP, tenHP);
        newNode->data.Tinchi = tinchi;
        newNode->next = current->next;
        current->next = newNode;
    }
}

void InsertHPBefore(LinkedListHP& H, const char* targetMaHP, const char* maHP, const char* tenHP, int tinchi) {
    if (strcmp(H->data.MaHP, targetMaHP) == 0) {
        InsertHPBegin(H, maHP, tenHP, tinchi);
        return;
    }

    NodeHP* prev = nullptr;
    NodeHP* current = H;

    while (current != nullptr && strcmp(current->data.MaHP, targetMaHP) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        NodeHP* newNode = new NodeHP;
        strcpy(newNode->data.MaHP, maHP);
        strcpy(newNode->data.TenHP, tenHP);
        newNode->data.Tinchi = tinchi;
        prev->next = newNode;
        newNode->next = current;
    }
}

PNodeHP searchHP(LinkedListHP H, const char* MaHP) {
    NodeHP* current = H;
    while (current != nullptr) {
        if (strcmp(current->data.MaHP, MaHP) == 0) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void deleteHocPhan(LinkedListHP& H, const char* MaHP) {
    NodeHP* current = H;
    NodeHP* prev = nullptr;

    while (current != nullptr && strcmp(current->data.MaHP, MaHP) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        return; 
    }

    if (prev == nullptr) {
        H = H->next;
    } else {
        prev->next = current->next;
    }
    delete current;
}

void display(LinkedListHP H) {
    NodeHP* current = H;
    while (current != nullptr) {
        cout << "MaHP: " << current->data.MaHP << ", TenHP: " << current->data.TenHP << ", Tinchi: " << current->data.Tinchi << endl;
        current = current->next;
    }
}

