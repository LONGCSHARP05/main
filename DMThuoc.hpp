#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
// dùng ifndef để tránh đụng độ thư viện
#ifndef DMTHUOC_HPP
#define DMTHUOC_HPP

using namespace std;

// DMThuoc:  với các thông tin như mã thuốc, tên thuốc, đơn vị tính, giá bán, công dụng. 
class DMThuoc
{
protected:
    string maThuoc;
    string tenThuoc;
    string donViTinh;
    int giaBan;
    string congDung;

public:
// Hàm tạo mặc định
    DMThuoc(): maThuoc(""), tenThuoc(""), donViTinh(""), giaBan(0), congDung(""){}
    
    // Setter
    // Setter
    void setMaThuoc(string& ma) { maThuoc = ma; }
    void setTenThuoc( string& ten) { tenThuoc = ten; }
    void setDonViTinh( string& donVi) { donViTinh = donVi; }
    void setGiaBan(int gia) { giaBan = gia; }
    void setCongDung( string& congDung) { this->congDung = congDung; }


     // Getter
     string getMaThuoc()  { return maThuoc; }
     string getTenThuoc()  { return tenThuoc; }
     string getDonViTinh()  { return donViTinh; }
     int getGiaBan()  { return giaBan; }
     string getCongDung()  { return congDung; }

     static void docFile(vector<DMThuoc>& ds) {
        ifstream file("DMThuoc.txt", ios::in);
        if (!file.is_open()) {
            std::cout << "Không thể mở file để đọc" << std::endl;
            return;
        }
    
        DMThuoc thuoc;
        while (getline(file, thuoc.maThuoc)) {
            getline(file, thuoc.tenThuoc);
            getline(file, thuoc.donViTinh);
            file >> thuoc.giaBan;
            file.ignore();
            getline(file, thuoc.congDung);
            file.ignore();
            ds.push_back(thuoc);
        }
        file.close();
    }
};
#endif