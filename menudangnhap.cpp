#include <iostream>
#include <cstdlib> // Thư viện cho hàm system
#include "SinhVien.h"
#include "TKB.h"
#include "HocPhan.h"
#include "dangnhap.h"

using namespace std;

void menu() {
batdau:
    std::cout << "\t\t\t\tXin chao cac ban!!!!" << std::endl;
    std::cout << "\t\t\t\tNhan phim [1] de dang nhap" << std::endl;
    std::cout << "\t\t\t\tNhan phim [2] de thoat chuong trinh" << std::endl;
    std::cout << "Nhap lua chon cua ban: ";
    int pick;
    std::cin >> pick;
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
    std::cout << "\t CHAO MUNG " << PNodeSV->data.mssv << "!" << std::endl;
    std::cout << "\n Nhan phim [2] de them mon hoc vao thoi khoa bieu sinh vien" << std::endl;
    std::cout << " Nhan phim [1] de doi mat khau" << std::endl;
    std::cout << " Nhan phim [3] de xoa mon hoc khoi thoi khoa bieu sinh vien" << std::endl;
    std::cout << " Nhan phim [4] de tim mon hoc trong thoi khoa bieu" << std::endl;
    std::cout << " Nhan phim [5] de xem thoi khoa bieu sinh vien" << std::endl;
    std::cout << "\n\nLua chon cua ban la: ";
    int pick1;
    std::cin >> pick1;
    if (pick1 == 1) {
        // Đổi mật khẩu
        // (Chưa triển khai, có thể thêm vào sau)
        std::cout << "Chuc nang chua duoc trien khai!" << std::endl;
    }
    if (pick1 == 2) {
        // Thêm môn học vào thời khóa biểu sinh viên
        // (Chưa triển khai, có thể thêm vào sau)
        std::cout << "Chuc nang chua duoc trien khai!" << std::endl;
    }
    if (pick1 == 3) {
        // Xoá môn học khỏi thời khóa biểu sinh viên
        // (Chưa triển khai, có thể thêm vào sau)
        std::cout << "Chuc nang chua duoc trien khai!" << std::endl;
    }
    if (pick1 == 4) {
        // Tìm môn học trong thời khóa biểu
        // (Chưa triển khai, có thể thêm vào sau)
        std::cout << "Chuc nang chua duoc trien khai!" << std::endl;
    }
    if (pick1 == 5) {
        // In ra màn hình thời khóa biểu sinh viên
        // (Chưa triển khai, có thể thêm vào sau)
        std::cout << "Chuc nang chua duoc trien khai!" << std::endl;
    }
    std::cout << "Nhan a de thoat ";
    char tieptuc1;
    std::cin >> tieptuc1;
    if (tieptuc1 == 'a') {
        system("cls");
        goto thaydoi;
    }
}


