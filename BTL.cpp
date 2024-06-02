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

    //Trả về con trỏ trỏ vào thời khóa biểu
    NodeTKB* getTKB() const { return TKB; }
    void setTKB(NodeTKB* tkb) { TKB = tkb; } 
    SinhVien& getData() { return data; }
};

class NodeHP {
private:
    HocPhan data;
    NodeHP* next;
public:
    NodeHP(const char* MaHP, const char* TenHP, int Tinchi)
    : data(MaHP, TenHP, Tinchi), next(nullptr) {}

    const char* getMaHP() const {return data.getMaHP();}
    const char* getTenHP() const {return data.getTenHP();}
    int getTinchi() const {return data.getTinchi();}

    NodeHP* getNext() const { return next; }
    void setNext(NodeHP* nextNode) { next = nextNode; }
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

    NodeTKB* getNext() const { return next; }
    void setNext(NodeTKB* nextNode ){ next = nextNode; } 

    HocPhan& getData() { return data; }
    int getThu() const { return Thu ; }
    int getStart() const { return Start; }
    int getEnd() const { return End; }
    int getTuan() const { return Tuan; }
    const char* getPhongHoc() const { return PhongHoc; }
    const char* getKihoc() const { return Kihoc; }





};

typedef NodeSV* LinkedList;
typedef NodeHP* LinkedListHP;
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
        H = Q;   // Q -> next == NULL
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

void displaySV
(LinkedList H) {
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

void InitListHP(LinkedListHP& H){
    H = NULL;
}
bool isEmptyHocPhan(LinkedListHP H){
    return ( H==NULL );
}
// Thêm 1 học phần vào trước danh sách
void InsertHPBegin(LinkedListHP& H, const char* maHP, const char* tenHP, int tinchi){ 
    PNodeHP Q = new NodeHP(maHP, tenHP, tinchi);
    if(isEmptyHocPhan(H)){
        Q->setNext(NULL);
        H = Q;
    } else {
        Q->setNext(H);
        H = Q;   
    }
}
// Thêm 1 học phần vào sau 1 HP trỏ bởi P trong danh sách
void InsertHPAfter(LinkedListHP& H, PNodeHP P, const char* maHP, const char* tenHP, int tinchi){
    PNodeHP Q = new NodeHP(maHP, tenHP, tinchi);
    if(isEmptyHocPhan(H)){
        Q->setNext(NULL);
        H = Q;
    } else {
        if(P == NULL){
            cout << "Khong co hoc phan trong danh sach" << endl;
            return;
        }
        else {
            Q->setNext(P->getNext());
            P->setNext(Q);
        }
    }
}

// Hiển thị ra màn hình các học phần
void display(LinkedListHP H){
    PNodeHP P = H;
    while (P != NULL){
        cout << P->getMaHP() << " " << P->getTenHP() << " " << P->getTinchi() << endl;
        P = P->getNext();
    }
}
// Tìm học phần có mã cho trước
PNodeHP searchHP(LinkedListHP H, const char* MaHP){
    PNodeHP P = H;
    while (P != NULL){
        if(strcmp(P->getData().getMaHP(), MaHP) == 0){ // So sánh
            return P;
        } else P = P->getNext();
    }
    return NULL;
}

// Xóa học phần có mã HP cho trước
PNodeHP deleteHocPhan(LinkedListHP& H, const char* MaHP){
    PNodeHP P = H;
    PNodeHP R = NULL;
    if(isEmptyHocPhan(H)){
        cout << "Danh sach khong co gi de xoa\n";
        return;
    }
    while (P != NULL &&  strcmp(P->getData().getMaHP(), MaHP) != 0){
        R = P;
        P = P ->getNext();
    }
    if (P == NULL ) { "Khong tim thay mon hoc\n";}
    if (R == NULL){ // Trường hợp P ở đầu danh sách 
        H = P->getNext();
    } else {
        R->setNext(P->getNext());
    }
    delete P;
}

// Thời Khóa Biểu
// Thêm Học Phần vào Thời Khóa Biểu của 1 sinh viên
void ThemHP(PNodeSV SV, const char* MaHP, const char* TenHP, int Tinchi, int Thu, int Start, int End, int Tuan, const char* PhongHoc, const char* Kihoc){
    PNodeTKB P = new NodeTKB (MaHP, TenHP, Tinchi, Thu, Start, End, Tuan, PhongHoc, Kihoc);
    if(SV->getTKB() == NULL){ // Không có môn học nào trong TKB thêm môn P vào
        SV->setTKB(P);
    } else {  // có môn học
        PNodeTKB Q = SV->getTKB(); // cho Q chạy hết danh sách TKB
        while (Q->getNext() != NULL){
            Q = Q->getNext();
        }
        Q ->setNext(P);
    }
}
// Tìm học phần trong TKB trả về con trỏ trỏ vào HP đó
PNodeTKB searchTKB  (PNodeSV SV, const char* MaHP){
    PNodeTKB P = SV->getTKB(); //Cho P chạy 
    while (P != NULL ){
        if(strcmp(P->getData().getMaHP(), MaHP) == 0){ // 2 chuỗi giống nhau
            return P;
        } P = P->getNext();
    }
    // Không tìm thấy
    return NULL;
}

// Xóa học phần trong tkb của Sinh Viên
void DeleteTKB(PNodeSV& SV, const char* MaHP){
    PNodeTKB P = SV->getTKB();
    PNodeTKB R = NULL;
    while (P != NULL &&  strcmp(P->getData().getMaHP(), MaHP) != 0){
        R = P;
        P = P ->getNext();
    }
    if ( P == NULL ) { cout << "Khong tim thay\n"; }
    if (R == NULL){ // P ở đầu danh sách
        SV->setTKB(P->getNext());
    } else {
        R->setNext(P->getNext());
    }
    delete P;
}

//Hiển thị ra màn hình thời khóa biểu 
void displayTKB(PNodeSV SV){
    PNodeTKB P = SV->getTKB();
    while (P != NULL ){
        cout << P->getData().getMaHP() << " " << P ->getData().getTenHP() << " " << P->getData().getTinchi() << " ";
        cout << P->getThu() << " " << P->getStart() << " " << P->getEnd() << " " << P->getTuan() << " ";
        cout << P->getPhongHoc() << " " << P->getKihoc() << endl;
        P = P->getNext();
    }
}