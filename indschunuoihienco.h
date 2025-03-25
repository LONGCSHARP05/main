#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // Để định dạng bảng
using namespace std;

// Lớp DMChuNuoi
class DMChuNuoi {
public:
    string maKH;
    string tenChuNuoi;
    string diaChi;
    string soDienThoai;
    string thongTinThuCung;

    // Hàm hiển thị thông tin chủ nuôi
    void hienThi() const {
        cout << left << setw(10) << maKH
             << setw(20) << tenChuNuoi
             << setw(50) << diaChi
             << setw(15) << soDienThoai
             << setw(15) << thongTinThuCung << endl;
    }
};

// Hàm đọc dữ liệu từ tệp và lưu vào vector
void docDuLieuChuNuoi(const string &filePath, vector<DMChuNuoi> &danhSachChuNuoi) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Khong the mo tep " << filePath << endl;
        return;
    }

    DMChuNuoi chuNuoi;
    while (file >> chuNuoi.maKH >> chuNuoi.tenChuNuoi >> chuNuoi.diaChi >> chuNuoi.soDienThoai >> chuNuoi.thongTinThuCung) {
        danhSachChuNuoi.push_back(chuNuoi);
    }

    file.close();
}

// Hàm hiển thị danh sách chủ nuôi
void hienThiDanhSachChuNuoi(const vector<DMChuNuoi> &danhSachChuNuoi) {
    cout << left << setw(10) << "MaKH"
         << setw(20) << "TenChuNuoi"
         << setw(50) << "DiaChi"
         << setw(15) << "SoDienThoai"
         << setw(15) << "ThongTinThuCung" << endl;
    cout << string(115, '-') << endl;

    for (const auto &chuNuoi : danhSachChuNuoi) {
        chuNuoi.hienThi();
    }
}

// Hàm chính
int main() {
    vector<DMChuNuoi> danhSachChuNuoi;

    // Đọc dữ liệu từ tệp
    string filePath = "DMChuNuoi.txt";
    docDuLieuChuNuoi(filePath, danhSachChuNuoi);

    // Hiển thị danh sách chủ nuôi
    if (!danhSachChuNuoi.empty()) {
        cout << "Danh sach chu nuoi hien co:\n";
        hienThiDanhSachChuNuoi(danhSachChuNuoi);
    } else {
        cout << "Khong co du lieu de hien thi.\n";
    }

    return 0;
}