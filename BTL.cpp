#include <iostream>
#include <cstring>
using namespace std;

class SinhVien {
private:
    long mssv;
    char hoTen[100];
    char email[100];
public:
    SinhVien(long mssv, const char* hoTen, const char* email)
    : mssv(mssv) {
        strcpy(this->hoTen, hoTen);
        strcpy(this->email, email);
    }

    long getMSSV() const { return mssv; }
    const char* getHoTen() const { return hoTen; }
    const char* getEmail() const { return email; }

    void setMSSV(long mssv) { this->mssv = mssv; }
    void setHoTen(const char* hoTen) { strcpy(this->hoTen, hoTen); }
    void setEmail(const char* email) { strcpy(this->email, email); }
};

class HocPhan {
private:
    char MaHP[100];
    char TenHP[100];
    int Tinchi;
public:
    HocPhan(const char* MaHP, const char* TenHP, int Tinchi)
    : Tinchi(Tinchi) {
        strcpy(this->MaHP, MaHP);
        strcpy(this->TenHP, TenHP);
    }

    const char* getMaHP() const { return MaHP; }
    const char* getTenHP() const { return TenHP; }
    int getTinchi() const { return Tinchi; }
};

class NodeSV {
private:
    SinhVien data;
    NodeSV* next;
    NodeTKB* TKB;
public:
    NodeSV(long mssv, const char* hoTen, const char* email)
    : data(mssv, hoTen, email), next(nullptr), TKB(nullptr) {}

    long getMSSV() const { return data.getMSSV(); }
    const char* getHoTen() const { return data.getHoTen(); }
    const char* getEmail() const { return data.getEmail(); }

    NodeSV* getNext() const { return next; }
    void setNext(NodeSV* nextNode) { next = nextNode; }

    SinhVien& getData() { return data; }
};

class NodeHP {
private:
    HocPhan data;
    NodeHP* next;
public:
    NodeHP(const char* MaHP, const char* TenHP, int Tinchi)
    : data(MaHP, TenHP, Tinchi), next(nullptr) {}

    HocPhan& getData() { return data; }
};

class NodeTKB {
private:
    HocPhan data;
    int Thu;
    int Start, End;
    int Tuan;
    char PhongHoc[100];
    char Kihoc[100];
    NodeTKB* next;
public: 
    NodeTKB(const char* MaHP, const char* TenHP, int Tinchi, int Thu, int Start, int End, int Tuan, const char* PhongHoc, const char* Kihoc)
    : data(MaHP, TenHP, Tinchi), Thu(Thu), Start(Start), End(End), Tuan(Tuan), next(nullptr) {
        strcpy(this->PhongHoc, PhongHoc);
        strcpy(this->Kihoc, Kihoc);
    }
};

typedef NodeSV* LinkedList;
typedef NodeSV* PNodeSV;
typedef NodeHP* PNodeHP;
typedef NodeTKB* PNodeTKB;

void InitList(LinkedList& H) {
    H = nullptr;
}

int isEmpty(LinkedList H) {
    return (H == nullptr);
}

void insertBeginSV(LinkedList& H, long mssv, const char* hoTen, const char* email) {
    PNodeSV Q = new NodeSV(mssv, hoTen, email);
    if (isEmpty(H)) {
        H = Q;
    } else {
        Q->setNext(H);
        H = Q;
    }
}

void insertAfterSV(LinkedList& H, PNodeSV P, long mssv, const char* hoTen, const char* email) {
    PNodeSV Q = new NodeSV(mssv, hoTen, email);
    if (isEmpty(H)) {
        H = Q;
    } else {
        if (P != nullptr) {
            Q->setNext(P->getNext());
            P->setNext(Q);
        }
    }
}

void insertBeforeSV(LinkedList& H, PNodeSV P, long mssv, const char* hoTen, const char* email) {
    PNodeSV Q = new NodeSV(mssv, hoTen, email);
    if (isEmpty(H)) {
        H = Q;
    } else if (P != nullptr) {
        Q->setNext(P->getNext());
        P->setNext(Q);
        SinhVien temp = P->getData();
        P->getData() = Q->getData();
        Q->getData() = temp;
    }
}

void display(LinkedList H) {
    PNodeSV P = H;
    while (P != nullptr) {
        cout << P->getMSSV() << "  " << P->getHoTen() << "  " << P->getEmail() << endl;
        P = P->getNext();
    }
}

PNodeSV searchSV(LinkedList H, long mssv) {
    PNodeSV P = H;
    while (P != nullptr) {
        if (P->getMSSV() == mssv)
            return P;
        else
            P = P->getNext();
    }
    return nullptr;
}

void DelectSV (LinkedList H, long mssv) {
    PNodeSV P = searchSV (H, mssv);
    if (P != NULL)
        delete P;
}
