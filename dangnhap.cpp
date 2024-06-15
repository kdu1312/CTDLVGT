#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "SinhVien.h"

using namespace std;

    int find(const string mssv[], const string pass[], const string& _id, const string& _pass, int n) {
        for (int i = 0; i < n; i++) {
            if (mssv[i] == _id && pass[i] == _pass) {
                return i;
            }
        }
        return -1;
    }

    int dangnhap() {
        int vitri;
        int n = 0; // Vị trí của tài khoản
        string mssv[100];
        string pass[100];
        fstream link;
        
        // Mở file chứa tài khoản và mật khẩu có sẵn
        link.open("info.txt");
        if (!link.is_open()) {
            cout << "Khong the mo file info.txt" << endl;
            return -1;
        }
        
        while (!link.eof() && n < 100) {
            link >> mssv[n] >> pass[n];
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
            int index = find(mssv, pass, _id, _pass, n);
            if (index != -1) {
                vitri = index; // Kiểm tra MSSV và mật khẩu nhập vào với file có sẵn
                cout << "\n\tDang nhap thanh cong, nhan phim 'a' de tiep tuc: ";
                break;
            }
            cout << "\n\tSai mat khau hoac tai khoan. Vui long thu lai.\n";
        }
         void menu1();
        return vitri;
    }


