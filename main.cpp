#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
#include "DMThuoc.hpp"
#include "DMChuNuoi.hpp"
#include "PhieuKhamBenh.hpp"
#include "PhieuKhamBenh.cpp"

using namespace std;

int main() {

// int chon;
// cin>>chon;
// switch(chon)
// {
// case 1:
/*1. in danh sách phiếu khám theo thời gian*/
    vector <PhieuKhamBenh> danhSachPhieu;
    // Đọc file vào vector
    PhieuKhamBenh::docFile(danhSachPhieu);

    // In danh sách
    PhieuKhamBenh::inPhieuKhamBenh(danhSachPhieu);

//     break;
// case 2:

/*2. tìm kiếm và in phiếu theo số phiếu đã nhập*/
    PhieuKhamBenh:: inPhieuCanTim(danhSachPhieu);

//     break;
// case 3:

/*3. thống kê doanh thu theo ngày tháng năm*/

vector<DMThuoc> danhSachThuoc;

// Đọc dữ liệu từ file
DMThuoc::docFile(danhSachThuoc);


// Khai báo vector doanh thu
vector<DoanhThu> doanhThuNgay, doanhThuThang, doanhThuNam;

// Tính doanh thu
tinhDoanhThu(danhSachPhieu, danhSachThuoc, doanhThuNgay, doanhThuThang, doanhThuNam);

// Hiển thị thống kê doanh thu
inThongKe(doanhThuNgay, "NGÀY");
inThongKe(doanhThuThang, "THÁNG");
inThongKe(doanhThuNam, "NĂM");

    
//     break;    

// default:
// cout <<"Thoát!";
//  break;
// }

/*4. Thống kê loại thuốc được sử dụng nhiều nhất*/
thongKeLoaiThuoc(danhSachPhieu, danhSachThuoc);



return 0;

}