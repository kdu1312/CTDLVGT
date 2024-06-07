#pragma once
#include "SinhVien.h"
#include "info.txt"
int find(const string MSSV[], const string pass[], const string& _id, const string& _pass, int n) {
    for (int i = 0; i < n; i++) {
        if (MSSV[i] == _id && pass[i] == _pass) {
            return i;
        }
    }
    return -1;
}

int dangnhap() {
    int vitri;
    int n = 0; // Vị trí của tài khoản
    string MSSV[100];
    string pass[100];
    fstream link;
    
    // Mở file chứa tài khoản và mật khẩu có sẵn
    link.open("info.txt");
    if (!link.is_open()) {
        cout << "Khong the mo file info.txt" << endl;
        return -1;
    }
    
    while (!link.eof() && n < 100) {
        link >> MSSV[n] >> pass[n];
        n++;
    }
    link.close(); // Đóng file
    
    string _id(""), _pass(""); // Nhập MSSV và mật khẩu từ bàn phím
    while (true) { // Vòng lặp vô tận
        cout << "Hay dang nhap:" << endl;
        cout << "Nhap MSSV: ";
        cin >> _id;
        cout << "Nhap mat khau: ";
        cin >> _pass;
        int index = find(MSSV, pass, _id, _pass, n);
        if (index != -1) {
            vitri = index; // Kiểm tra MSSV và mật khẩu nhập vào với file có sẵn
            cout << "\n\tDang nhap thanh cong, nhan phim 'a' de tiep tuc: ";
            break;
        }
        cout << "\n\tSai mat khau hoac tai khoan. Vui long thu lai.\n";
    }
    return vitri;
}

