#ifndef PHIEUKHAMBENH_H //khai báo ifndef, define để tránh đụng độ thư viện, tránh việc bị định nghĩa lại
#define PHIEUKHAMBENH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class PhieuKhamBenh : public DMChuNuoi, public DMThuoc
{
private:
    string soPhieu;
    string ngayKham;
    string maChuNuoi;  // Chỉ lưu mã chủ nuôi, không kế thừa toàn bộ lớp DMChuNuoi
    string maThuoc;    // Chỉ lưu mã thuốc, không kế thừa toàn bộ lớp DMThuoc
    int soLuongThuoc;
    string trieuChung;
    string chanDoan;

public:
// hàm tạo mặc định
    PhieuKhamBenh() : soPhieu(""), ngayKham(""), maChuNuoi(""), maThuoc(""), soLuongThuoc(0), trieuChung(""), chanDoan("") {}

    // sử dụng setter để gán giá trị cho các thuộc tính
    // sử dụng getter để lấy giá trị của các thuộc tính
    void setSoLuongThuoc(int soLuong) { soLuongThuoc = soLuong; }
    void setMaThuoc(string ma) { maThuoc = ma; }
    void setSoPhieu(string so) { soPhieu = so; }
    void setNgayKham(string ngay) { ngayKham = ngay; }
    void setMaChuNuoi(string ma) { maChuNuoi = ma; }
    void setTrieuChung(string trieuChung) { trieuChung = trieuChung; }
    void setChanDoan(string chanDoan) { chanDoan = chanDoan; }

    string getNgayKham() const { return ngayKham; }
    string getMaThuoc() const { return maThuoc; }
    string getTenThuoc() const { return tenThuoc; }
   
    int getSoLuongThuoc() const { return soLuongThuoc; }
    string getSoPhieu() const { return soPhieu; }

    string getMaChuNuoi() const { return maChuNuoi; }
    string getTrieuChung() const { return trieuChung; }
    string getChanDoan() const { return chanDoan; }


    /*1. In danh sách phiếu khám bệnh theo thứ tự thời gian*/
    static void docFile(vector <PhieuKhamBenh> &ds) {
        ifstream file("PhieuKhamBenh.txt", ios::in);
        if (!file.is_open()) {
            cout << "Không thể mở file để đọc" << endl;
            return;
        }

        
        PhieuKhamBenh pkb;
        while (getline(file, pkb.soPhieu)) {
            getline(file, pkb.ngayKham);
            getline(file, pkb.maChuNuoi);
            getline(file, pkb.maThuoc);
            file >> pkb.soLuongThuoc;
            file.ignore();
            getline(file, pkb.trieuChung);
            getline(file, pkb.chanDoan);
            file.ignore();
            ds.push_back(pkb);
        }
        file.close();
    }

    static bool sosanh( PhieuKhamBenh &a, PhieuKhamBenh &b) {
        return a.ngayKham < b.ngayKham;  // Sắp xếp theo ngày giảm dần
    }

    static void inPhieuKhamBenh(vector <PhieuKhamBenh> ds) {
        if (ds.empty()) {
            cout << "Danh sách phiếu khám bệnh rỗng!" << endl;
            return;
        }

        for (int i =0; i<ds.size();i++)
        {
            for (int j = i+1; j<ds.size();j++)
            {
            if (sosanh(ds[i],ds[j]))
            {
                PhieuKhamBenh temp = ds[i];
                ds[i]=ds[j];
                ds[j]=temp;
            }
            }
        }

        for ( PhieuKhamBenh pkb : ds) {
            cout << "----------------------------" << endl;
            cout << "Số Phiếu: " << pkb.soPhieu << endl;
            cout << "Ngày Khám: " << pkb.ngayKham << endl;
            cout << "Mã Chủ Nuôi: " << pkb.maChuNuoi << endl;
            cout << "Mã Thuốc: " << pkb.maThuoc << endl;
            cout << "Số Lượng Thuốc: " << pkb.soLuongThuoc << endl;
            cout << "Triệu Chứng: " << pkb.trieuChung << endl;
            cout << "Chẩn Đoán: " << pkb.chanDoan << endl;
        }
    }

    /*2. Tìm kiếm và in nội dung phiếu khám bệnh bằng cách nhập vào số phiếu cần tìm*/
    static void inPhieuCanTim(vector<PhieuKhamBenh> ds)
    {
        // Nhập số phiếu cần tìm
    string soPhieuCanTim;
    
    cout<< "\nma so phieu can tim la: "; 
    getline(cin, soPhieuCanTim);

    // Tìm kiếm và in thông tin phiếu khám bệnh dựa trên số phiếu nhập vào
    for (int i =0; i<ds.size();i++)
        {
            if(soPhieuCanTim != ds[i].soPhieu) //nếu khác số phiếu trong vector thì in ra không tìm thấy
            {
                cout <<"Không tìm thấy kết quả!\n" <<endl;
                break;
            }
            else //nếu trùng số phiếu trong vector thì in ra thông tin phiếu khám bệnh
            {
        
                    cout << "----------------------------" << endl;
                    cout << "Số Phiếu: " << ds[i].soPhieu << endl;
                    cout << "Ngày Khám: " << ds[i].ngayKham << endl;
                    cout << "Mã Chủ Nuôi: " << ds[i].maChuNuoi << endl;
                    cout << "Mã Thuốc: " << ds[i].maThuoc << endl;
                    cout << "Số Lượng Thuốc: " << ds[i].soLuongThuoc << endl;
                    cout << "Triệu Chứng: " << ds[i].trieuChung << endl;
                    cout << "Chẩn Đoán: " << ds[i].chanDoan << endl;
            }
        }
        
        

    /*3. Thống kê doanh thu theo ngày tháng năm*/

    return;
    }
    

};

#endif  //kết thúc ifndef, define