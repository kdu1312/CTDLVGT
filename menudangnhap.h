#include "SinhVien.h"
#include "TKB.h"
#include "HocPhan.h"
void menu1(NodeSV* PNodeSV ) {
thaydoi:
    cout << "\t CHAO MUNG " << PNodeSV << "!" << endl;
    cout << "\n Nhan phim [1] de chinh sua thong tin ca nhan" << endl;
    cout << " Nhan phim [2] de sua thong tin dang nhap" << endl;
    cout << " Nhan phim [3] de them mon hoc vao thoi khoa bieu sinh vien" << endl;
    cout << " Nhan phim [4] de xoa mon hoc khoi thoi khoa bieu sinh vien" << endl;
    cout << " Nhan phim [5] de tim mon hoc trong thoi khoa bieu" << endl;
    cout << " Nhan phim [6] de xem thoi khoa bieu sinh vien" << endl;
    cout << "\n\nLua chon cua ban la: ";
    int pick1;
    cin >> pick1;
    if (pick1 == 1) {
        // Sửa thông tin cá nhân
        /*string name1;
        int age1, height1, weight1;
        cout << "Nhap ten cua ban: ";
        cin >> name1;
        cout << "Nhap tuoi cua ban: ";
        cin >> age1;
        cout << "Nhap chieu cao cua ban: ";
        cin >> height1;
        cout << "Nhap can nang cua ban: ";
        cin >> weight1;
        GYM.setINFO(name1, age1, height1, weight1);
        system("cls");
        cout << "Thay doi thong tin thanh cong" << endl;
    }
    */
    if (pick1 == 2) {
        // Sửa thông tin đăng nhập
        // (Chưa triển khai, có thể thêm vào sau)
        cout << "Chuc nang chua duoc trien khai!" << endl;
    }
    if (pick1 == 3) {
        // Thêm môn học vào thời khoá biểu sinh viên
        // (Sử dụng hàm ThemHP đã được định nghĩa trước đó)
        // (Chưa triển khai, có thể thêm vào sau)
        cout << "Chuc nang chua duoc trien khai!" << endl;
    }
    if (pick1 == 4) {
        // Xoá môn học khỏi thời khoá biểu sinh viên
        // (Sử dụng hàm DeleteTKB đã được định nghĩa trước đó)
        // (Chưa triển khai, có thể thêm vào sau)
        cout << "Chuc nang chua duoc trien khai!" << endl;
    }
    if (pick1 == 5) {
        // Tìm môn học trong thời khoá biểu
        // (Chưa triển khai, có thể thêm vào sau)
        cout << "Chuc nang chua duoc trien khai!" << endl;
    }
    if (pick1 == 6) {
        // In ra màn hình thời khoá biểu sinh viên
       // displayTKB(GYM); // Sử dụng hàm đã được định nghĩa trước đó
    }
    cout << "Nhan a de thoat ";
    char tieptuc1;
    cin >> tieptuc1;
    if (tieptuc1 == 'a') {
        system("cls");
        goto thaydoi;
    }
}
}
