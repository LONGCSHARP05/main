#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // Để định dạng bảng
using namespace std;

// Lớp DMThuoc
class DMThuoc {
public:
    string maThuoc;
    string tenThuoc;
    string donViTinh;
    double giaBan;
    string congDung;

    // Hàm hiển thị thông tin thuốc
    void hienThi() const {
        cout << left << setw(10) << maThuoc
             << setw(25) << tenThuoc
             << setw(10) << donViTinh
             << setw(10) << giaBan
             << setw(50) << congDung << endl;
    }
};

// Hàm đọc dữ liệu từ tệp và lưu vào vector
void docDuLieuThuoc(const string &filePath, vector<DMThuoc> &danhSachThuoc) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Khong the mo tep " << filePath << endl;
        return;
    }

    DMThuoc thuoc;
    while (file >> thuoc.maThuoc >> thuoc.tenThuoc >> thuoc.donViTinh >> thuoc.giaBan) {
        file.ignore(); // Bỏ qua khoảng trắng trước khi đọc công dụng
        getline(file, thuoc.congDung); // Đọc toàn bộ dòng còn lại làm công dụng
        danhSachThuoc.push_back(thuoc);
    }

    file.close();
}

// Hàm hiển thị danh sách thuốc
void hienThiDanhSachThuoc(const vector<DMThuoc> &danhSachThuoc) {
    cout << left << setw(10) << "MaThuoc"
         << setw(25) << "TenThuoc"
         << setw(10) << "DonViTinh"
         << setw(10) << "GiaBan"
         << setw(50) << "CongDung" << endl;
    cout << string(105, '-') << endl;

    for (const auto &thuoc : danhSachThuoc) {
        thuoc.hienThi();
    }
}

// Hàm chính
int main() {
    vector<DMThuoc> danhSachThuoc;

    // Đọc dữ liệu từ tệp
    string filePath = "DMThuoc.txt";
    docDuLieuThuoc(filePath, danhSachThuoc);

    // Hiển thị danh sách thuốc
    if (!danhSachThuoc.empty()) {
        cout << "Danh sach thuoc hien co:\n";
        hienThiDanhSachThuoc(danhSachThuoc);
    } else {
        cout << "Khong co du lieu de hien thi.\n";
    }

    return 0;
}
