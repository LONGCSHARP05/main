#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Lớp DMThuoc
class DMThuoc {
public:
    string maThuoc;
    string tenThuoc;
    string donViTinh;
    double giaBan;
    string congDung;
    void nhap() {
    	cout << "Nhap ma thuoc: ";
    	cin >> maThuoc;
        cout << "Nhap ten thuoc: ";
        cin >> tenThuoc;
        cout << "Nhap don vi tinh thuoc: ";
        cin >> donViTinh;
        cout << "Nhap gia ban thuoc: ";
        cin >> giaBan;
        cout << "Nhap cong dung thuoc: ";
        cin >> congDung;  
    }

    void luuVaoFile(ofstream &file) {
        file << maThuoc << " " << tenThuoc << " " << donViTinh << " " << giaBan << congDung << " " << endl;
    }
};

// Lớp DMChuNuoi
class DMChuNuoi {
public:
    string maKH;
    string tenChuNuoi;
    string diaChi;
    string soDienThoai;
    string thongTinThuCung;
    void nhap() {
    	cout << "Nhap ma chu nuoi: ";
        cin >> maKH;
        cout << "Nhap ten chu nuoi: ";
        cin >> tenChuNuoi;
        cout << "Nhap dia chi: ";
        cin >> diaChi;
        cout << "Nhap thong tin thu cung: ";
        cin >> thongTinThuCung;
    }

    void luuVaoFile(ofstream &file) {
        file << maKH << " " << tenChuNuoi << " " << diaChi << " " << soDienThoai << " " << thongTinThuCung << " " << endl;
    }
};

// Lớp PhieuKhamBenh    //số phiếu, ngày khám, mã chủ nuôi, mã thuốc, số lượng thuốc, triệu chứng, chẩn đoán. 

class PhieuKhamBenh {
public:
    string soPhieu;
    string ngayKham;
    string maKH;
    string maThuoc;
    int soLuongThuoc;
    string trieuChung;
    string chanDoan;

    void nhap() {
        cout << "Nhap so phieu: ";
        cin >> soPhieu;
        cout << "Nhap ngay kham (YYYY-MM-DD): ";
        cin >> ngayKham;
        cout << "Nhap ma chu nuoi: ";
        cin >> maKH;
        cout << "Nhap ma thuoc: ";
    	cin >> maThuoc;
        cout << "Nhap so luong thuoc: ";
        cin >> soLuongThuoc;
        cout << "Nhap trieu chung: ";
        cin >> trieuChung;
        cout << "Nhap chan doan: ";
        cin >> chanDoan;
    }

    void luuVaoFile(ofstream &file) {
        file << soPhieu << " " << ngayKham << " " << maKH << " " << maThuoc << " " << soLuongThuoc << trieuChung << " " << chanDoan << " " << endl;
    }
};

// Hàm chính
int main() {
    int choice;

    do {
        cout << "\nChon hanh dong:\n";
        cout << "1. Them du lieu vao DMThuoc.txt\n";
        cout << "2. Them du lieu vao DMChuNuoi.txt\n";
        cout << "3. Them du lieu vao PhieuKhamBenh.txt\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                DMThuoc thuoc;
                thuoc.nhap();
                ofstream file("DMThuoc.txt", ios::app); // Mở tệp ở chế độ ghi thêm
                if (file.is_open()) {
                    thuoc.luuVaoFile(file);
                    file.close();
                    cout << "Du lieu da duoc them vao DMThuoc.txt\n";
                } else {
                    cout << "Khong the mo tep DMThuoc.txt\n";
                }
                break;
            }
            case 2: {
                DMChuNuoi chuNuoi;
                chuNuoi.nhap();
                ofstream file("DMChuNuoi.txt", ios::app); // Mở tệp ở chế độ ghi thêm
                if (file.is_open()) {
                    chuNuoi.luuVaoFile(file);
                    file.close();
                    cout << "Du lieu da duoc them vao DMChuNuoi.txt\n";
                } else {
                    cout << "Khong the mo tep DMChuNuoi.txt\n";
                }
                break;
            }
            case 3: {
                PhieuKhamBenh phieu;
                phieu.nhap();
                ofstream file("PhieuKhamBenh.txt", ios::app); // Mở tệp ở chế độ ghi thêm
                if (file.is_open()) {
                    phieu.luuVaoFile(file);
                    file.close();
                    cout << "Du lieu da duoc them vao PhieuKhamBenh.txt\n";
                } else {
                    cout << "Khong the mo tep PhieuKhamBenh.txt\n";
                }
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui lòng thu lai.\n";
        }
    } while (choice != 0);

    return 0;
}
