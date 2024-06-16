#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include "SinhVien.h"
#include "menudangnhap.h"

    int find(const string mssv[], const string pass[], const string& _id, const string& _pass, int n) {
        for (int i = 0; i < n; i++) {
            if (mssv[i] == _id && pass[i] == _pass) {
                return i;
            }
        }
        return -1;
    }

    long convertStringToLong(const string& str) {
    try {
        return stol(str); // Chuyển đổi từ string sang long
    } catch (const invalid_argument& e) {
        cerr << "Lỗi: " << e.what() << endl;
        return 0; // Trả về giá trị mặc định hoặc thông báo lỗi tùy ý
    } catch (const out_of_range& e) {
        cerr << "Lỗi: " << e.what() << endl;
        return 0; // Trả về giá trị mặc định hoặc thông báo lỗi tùy ý
    }
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
    char tieptuc;
	cin >> tieptuc;
	while (tieptuc != 'a') {
		system("cls");
		cout << "Nhap 'a' de tiep tuc: ";
		cin >> tieptuc;
	}
	system("cls");
	return convertStringToLong(_id);
}


