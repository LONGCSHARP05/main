#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h> // Thư viện để tạo giao diện console trên Windows
#include <iomanip>
using namespace std;
void NhapThemDuLieuMoi() {
    cout << "Nhập thêm dữ liệu mới...\n";
}

void InDanhSachChuNuoi() {
    cout << "In danh sách chủ nuôi...\n";
}

void InDanhSachThuoc() {
    cout << "In danh sách thuốc...\n";
}

void InDanhSachPhieuKhamBenh() {
    cout << "In danh sách phiếu khám bệnh...\n";
}

void TimKiemPhieuKhamBenh() {
    cout << "Tìm kiếm phiếu khám bệnh...\n";
}

void ThongKeDoanhThu() {
    cout << "Thống kê doanh thu...\n";
}

void ThongKeThuocSuDungNhieuNhat() {
    cout << "Thống kê thuốc sử dụng nhiều nhất...\n";
}

void XuatPhieuKhamBenhRaFile() {
    cout << "Xuất phiếu khám bệnh ra file...\n";
}

void LichNhacTiemPhong() {
    cout << "Lịch nhắc tiêm phòng...\n";
}
// Lưu thông tin phiếu khám bệnh
struct PhieuKhamBenh {
    string SoPhieu;
    string NgayKham;
    string MaChuNuoi;
    string MaThuoc;
    int SoLuongThuoc;
    string TrieuChung;
    string ChanDoan;
};

// Hàm đọc dữ liệu từ file PhieuKhamBenh.txt
vector<PhieuKhamBenh> DocDuLieuPhieuKhamBenh() {
    vector<PhieuKhamBenh> danhSachPhieu;
    ifstream inputFile("PhieuKhamBenh.txt");
    if (!inputFile.is_open()) {
        cerr << "Khong the mo file PhieuKhamBenh.txt!" << endl;
        return danhSachPhieu;
    }

    PhieuKhamBenh phieu;
    while (getline(inputFile, phieu.SoPhieu)) {
        getline(inputFile, phieu.NgayKham);
        getline(inputFile, phieu.MaChuNuoi);
        getline(inputFile, phieu.MaThuoc);
        inputFile >> phieu.SoLuongThuoc;
        inputFile.ignore(); // Bỏ qua ký tự newline sau số lượng thuốc
        getline(inputFile, phieu.TrieuChung);
        getline(inputFile, phieu.ChanDoan);

        danhSachPhieu.push_back(phieu);
    }

    inputFile.close();
    return danhSachPhieu;
}

// Hàm ghi dữ liệu vào file
void GhiDuLieuPhieuKhamBenh(const vector<PhieuKhamBenh>& danhSachPhieu, const string& tenFile) {
    ofstream outputFile(tenFile);
    if (!outputFile.is_open()) {
        cerr << "Khong the mo file de ghi!" << endl;
        return ;
    }

    for (const auto& phieu : danhSachPhieu) {
        outputFile << phieu.SoPhieu << endl;
        outputFile << phieu.NgayKham << endl;
        outputFile << phieu.MaChuNuoi << endl;
        outputFile << phieu.MaThuoc << endl;
        outputFile << phieu.SoLuongThuoc << endl;
        outputFile << phieu.TrieuChung << endl;
        outputFile << phieu.ChanDoan << endl;
    }

    outputFile.close();
    cout << "Da ghi du lieu vao file: " << tenFile << endl;
}

// Hàm tạo báo cáo khám bệnh
void TaoBaoCaoKhamBenh(const vector<PhieuKhamBenh>& danhSachPhieu, const string& soPhieu) {
    for (const auto& phieu : danhSachPhieu) {
        if (phieu.SoPhieu == soPhieu) {
            cout << "\n===== BÁO CÁO KHÁM BỆNH =====" << endl;
            cout << "Số phiếu: " << phieu.SoPhieu << endl;
            cout << "Ngày khám: " << phieu.NgayKham << endl;
            cout << "Mã chủ nuôi: " << phieu.MaChuNuoi << endl;
            cout << "Mã thuốc: " << phieu.MaThuoc << endl;
            cout << "Số lượng thuốc: " << phieu.SoLuongThuoc << endl;
            cout << "Triệu chứng: " << phieu.TrieuChung << endl;
            cout << "Chẩn đoán: " << phieu.ChanDoan << endl;
            cout << "=============================" << endl;
            return;
        }
    }
 
    cout << "Không tìm thấy phiếu khám bệnh có số " << soPhieu << endl;
}
void taobaocaokhambenhtheongay(const vector<PhieuKhamBenh>& danhSachPhieu, const string& NgayKham){
    cout << "\n====== BÁO CÁO KHÁM BỆNH NGÀY   " << NgayKham<<"  =======" << endl;
    cout << "| Ngày khám | Số phiếu | Mã chủ nuôi | Mã thuốc | Slg thuốc |     Triệu chứng   |   Chẩn đoán        |" << endl;
    for (const auto& phieu : danhSachPhieu){
        if (phieu.NgayKham == NgayKham){
            cout << left << setw(15) << phieu.NgayKham << setw(10) << phieu.SoPhieu << setw(13) << phieu.MaChuNuoi 
                 << setw(15) << phieu.MaThuoc << setw(12) << phieu.SoLuongThuoc << setw(25) << phieu.TrieuChung
                 << setw(25) << phieu.ChanDoan << endl;
            cout << "========================================================================================================" << endl;
        } else cout<<"Không có dữ liệu ngày báo cáo.";
    }
}
// Hàm tạo giao diện người dùng đồ họa 
void GiaoDienNguoiDung() {
    cout << "==============================================|\n";
    cout << "|       PHẦN MỀM QUẢN LÝ PHÒNG KHÁM THÚ Y     \n";
    cout << "==============================================|\n";
    cout << "|  1. Nhập thêm dữ liệu mới                   |\n";
    cout << "|  2. In danh sách chủ nuôi                   |\n";
    cout << "|  3. In danh sách thuốc                      |\n";
    cout << "|  4. In danh sách phiếu khám bệnh            |\n";
    cout << "|  5. Tìm kiếm phiếu khám bệnh                |\n";
    cout << "|  6. Thống kê doanh thu                      |\n";
    cout << "|  7. Thống kê thuốc sử dụng nhiều nhất       |\n";
    cout << "|  8. Tạo báo cáo khám bệnh cá nhân           |\n";
    cout << "|  9. Xuất phiếu khám bệnh ra file            |\n";
    cout << "|  10. Lịch nhắc tiêm phòng                   |\n";
    cout << "|  11. Tạo báo cáo khám bệnh theo ngày        |\n";
    cout << "|   0. Thoát                                  |\n";
    cout << "==============================================\n";
    cout << "Nhập lựa chọn của bạn: ";
}


int main() {

    vector<PhieuKhamBenh> danhSachPhieu = DocDuLieuPhieuKhamBenh();

    int luaChon;
    do {
        GiaoDienNguoiDung(); // Hiển thị giao diện người dùng
        cin>>luaChon;

        switch (luaChon) {
            case 1:
                NhapThemDuLieuMoi();
                break;
            case 2:
                InDanhSachChuNuoi();
                break;
            case 3:
                InDanhSachThuoc();
                break;
            case 4:
                InDanhSachPhieuKhamBenh();
                break;
            case 5:
                TimKiemPhieuKhamBenh();
                break;
            case 6:
                ThongKeDoanhThu();
                break;
            case 7:
                ThongKeThuocSuDungNhieuNhat();
                break;
            case 8: {
                    string soPhieu;
                    cout << "Nhập số phiếu cần tạo báo cáo: ";
                    cin >> soPhieu;
                    TaoBaoCaoKhamBenh(danhSachPhieu, soPhieu); // Truyền danh sách phiếu và số phiếu
                    break;
                }
            case 9: {
                    string tenFile;
                    cout << "Nhập tên file để ghi dữ liệu: ";
                    cin >> tenFile;
                    GhiDuLieuPhieuKhamBenh(danhSachPhieu, tenFile); // Ghi dữ liệu danh sách phiếu khám bệnh vào file
                    break;
                }
            case 10:
                LichNhacTiemPhong();
                break;
            case 11: {
                    string NgayKham;
                    cout << "Nhập ngày khám cần tạo báo cáo: ";
                    cin >> NgayKham;
                    taobaocaokhambenhtheongay(danhSachPhieu, NgayKham); 
                    break;
            }
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng thử lại.\n";
                break;
            
        }
        cout << "Nhấn phím bất kỳ để tiếp tục...\n";
        _getch(); // Dừng màn hình để người dùng xem kết quả
    } while (luaChon != 0);

    return 0;
}