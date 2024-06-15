#include <iostream>
#include <cstdlib> // Thư viện cho hàm system
#include "SinhVien.h"
#include "TKB.h"
#include "HocPhan.h"
#include "dangnhap.h"
#include "header.h"

using namespace std;

void menu() {
batdau:
    cout << "\t\t\t\tXin chao cac ban!!!!" << endl;
    cout << "\t\t\t\tNhan phim [1] de dang nhap" << endl;
    cout << "\t\t\t\tNhan phim [2] de thoat chuong trinh" << endl;
    cout << "Nhap lua chon cua ban: ";
    int pick;
    cin >> pick;
    int id = -1;
    system("cls"); // Xóa sạch màn hình
    if (pick == 1) {
        id = dangnhap();
    }
    if (pick == 2) {
        exit(0);
    }
}

void menu1(NodeSV* PNodeSV) {
thaydoi:
    cout << "\t CHAO MUNG " << PNodeSV->data.mssv << "!" << endl;
    cout << "\n Nhan phim [2] de them mon hoc vao thoi khoa bieu sinh vien" << endl;
    cout << " Nhan phim [1] de doi mat khau" << endl;
    cout << " Nhan phim [3] de xoa mon hoc khoi thoi khoa bieu sinh vien" << endl;
    cout << " Nhan phim [4] de tim mon hoc trong thoi khoa bieu" << endl;
    cout << " Nhan phim [5] de xem thoi khoa bieu sinh vien" << endl;
    cout << "\n\nLua chon cua ban la: ";
    int pick1;
    cin >> pick1;
    if (pick1 == 1) {
        string MSSV, pass;
        int id;
        cout << "Nhap ma so sinh vien:" << " ";
        cin >> MSSV;
        cout << "Nhap mat khau moi:" << " ";
        cin >> pass;
        setINFO(MSSV, pass);
        cout << "Chuc nang chua duoc trien khai!" << endl;
    }
    if (pick1 == 2) {
        // Thêm môn học vào thời khóa biểu sinh viên
        // (Chưa triển khai, có thể thêm vào sau)
       cout << "Chuc nang chua duoc trien khai!" << endl;
    }
    if (pick1 == 3) {
        // Xoá môn học khỏi thời khóa biểu sinh viên
        // (Chưa triển khai, có thể thêm vào sau)
        cout << "Chuc nang chua duoc trien khai!" << endl;
    }
    if (pick1 == 4) {
        // Tìm môn học trong thời khóa biểu
        // (Chưa triển khai, có thể thêm vào sau)
        cout << "Chuc nang chua duoc trien khai!" << endl;
    }
    if (pick1 == 5) {
        // In ra màn hình thời khóa biểu sinh viên
        // (Chưa triển khai, có thể thêm vào sau)
        cout << "Chuc nang chua duoc trien khai!" << endl;
    }
    cout << "Nhan a de thoat ";
    char tieptuc1;
    cin >> tieptuc1;
    if (tieptuc1 == 'a') {
        system("cls");
        goto thaydoi;
    }
}


