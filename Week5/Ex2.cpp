#include <bits/stdc++.h>
using namespace std;
// UML : https://drive.google.com/file/d/1ze8qoLp32w9IE1vNyXnVY10pmpaxe66Q/view?usp=sharing
const double LUONG_CO_SO = 1800000;

class NhanVien {
protected:
    string maNV;
    string hoTen;
    int namSinh;
    string gioiTinh;
    string diaChi;
    double heSoLuong;
    double luongToiDa;

public:
    NhanVien(string maNV = "", string hoTen = "", int namSinh = 0,
             string gioiTinh = "", string diaChi = "",
             double heSoLuong = 1, double luongToiDa = 0) {
        this->maNV = maNV;
        this->hoTen = hoTen;
        this->namSinh = namSinh;
        this->gioiTinh = gioiTinh;
        this->diaChi = diaChi;

        if (heSoLuong <= 0)
            this->heSoLuong = 1;
        else
            this->heSoLuong = heSoLuong;

        if (luongToiDa < 0)
            this->luongToiDa = 0;
        else
            this->luongToiDa = luongToiDa;
    }

    double tinhLuongCoBan() const {
        double luong = heSoLuong * LUONG_CO_SO;
        if (luong > luongToiDa)
            luong = luongToiDa;
        return luong;
    }

    virtual double tinhThuNhap() const = 0;

    virtual void xuatThongTin() const {
        cout << "Ma NV: " << maNV << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "He so luong: " << heSoLuong << endl;
        cout << "Luong toi da: " << luongToiDa << endl;
        cout << "Luong co ban: " << tinhLuongCoBan() << endl;
    }

    virtual ~NhanVien() {
    }
};

class CongTacVien : public NhanVien {
private:
    string thoiHanHopDong;
    double phuCapLaoDong;

public:
    CongTacVien(string maNV = "", string hoTen = "", int namSinh = 0,
                string gioiTinh = "", string diaChi = "",
                double heSoLuong = 1, double luongToiDa = 0,
                string thoiHanHopDong = "3 thang", double phuCapLaoDong = 0)
        : NhanVien(maNV, hoTen, namSinh, gioiTinh, diaChi, heSoLuong, luongToiDa) {

        if (thoiHanHopDong != "3 thang" &&
            thoiHanHopDong != "6 thang" &&
            thoiHanHopDong != "1 nam")
            this->thoiHanHopDong = "3 thang";
        else
            this->thoiHanHopDong = thoiHanHopDong;

        this->phuCapLaoDong = phuCapLaoDong;
    }

    double tinhThuNhap() const {
        return tinhLuongCoBan() + phuCapLaoDong;
    }

    void xuatThongTin() const {
        cout << "===== CONG TAC VIEN =====" << endl;
        NhanVien::xuatThongTin();
        cout << "Thoi han hop dong: " << thoiHanHopDong << endl;
        cout << "Phu cap lao dong: " << phuCapLaoDong << endl;
        cout << "Thu nhap: " << tinhThuNhap() << endl;
        cout << endl;
    }
};

class NhanVienChinhThuc : public NhanVien {
protected:
    string viTriCongViec;

public:
    NhanVienChinhThuc(string maNV = "", string hoTen = "", int namSinh = 0,
                      string gioiTinh = "", string diaChi = "",
                      double heSoLuong = 1, double luongToiDa = 0,
                      string viTriCongViec = "")
        : NhanVien(maNV, hoTen, namSinh, gioiTinh, diaChi, heSoLuong, luongToiDa) {
        this->viTriCongViec = viTriCongViec;
    }

    double tinhThuNhap() const {
        return tinhLuongCoBan();
    }

    void xuatThongTin() const {
        cout << "===== NHAN VIEN CHINH THUC =====" << endl;
        NhanVien::xuatThongTin();
        cout << "Vi tri cong viec: " << viTriCongViec << endl;
        cout << "Thu nhap: " << tinhThuNhap() << endl;
        cout << endl;
    }
};

class TruongPhong : public NhanVienChinhThuc {
private:
    string ngayBatDauQuanLy;
    double phuCapQuanLy;

public:
    TruongPhong(string maNV = "", string hoTen = "", int namSinh = 0,
                string gioiTinh = "", string diaChi = "",
                double heSoLuong = 1, double luongToiDa = 0,
                string viTriCongViec = "",
                string ngayBatDauQuanLy = "", double phuCapQuanLy = 0)
        : NhanVienChinhThuc(maNV, hoTen, namSinh, gioiTinh, diaChi,
                            heSoLuong, luongToiDa, viTriCongViec) {
        this->ngayBatDauQuanLy = ngayBatDauQuanLy;
        this->phuCapQuanLy = phuCapQuanLy;
    }

    double tinhThuNhap() const {
        return tinhLuongCoBan() + phuCapQuanLy;
    }

    void xuatThongTin() const {
        cout << "===== TRUONG PHONG =====" << endl;
        NhanVien::xuatThongTin();
        cout << "Vi tri cong viec: " << viTriCongViec << endl;
        cout << "Ngay bat dau quan ly: " << ngayBatDauQuanLy << endl;
        cout << "Phu cap quan ly: " << phuCapQuanLy << endl;
        cout << "Thu nhap: " << tinhThuNhap() << endl;
        cout << endl;
    }
};

int main() {
    CongTacVien ctv("CTV01", "Nguyen Van A", 2000, "Nam", "Ha Noi",
                    1.8, 4000000, "6 thang", 500000);

    NhanVienChinhThuc nvct("NV01", "Tran Thi B", 1998, "Nu", "Da Nang",
                           2.5, 6000000, "Ke toan");

    TruongPhong tp("TP01", "Le Van C", 1985, "Nam", "TP HCM",
                   3.2, 8000000, "Quan ly phong", "01/01/2022", 2000000);

    list<NhanVien*> ds;
    ds.push_back(&ctv);
    ds.push_back(&nvct);
    ds.push_back(&tp);

    cout << "===== DANH SACH NHAN VIEN =====" << endl << endl;

    for (const auto& nv : ds) {
        nv->xuatThongTin();
    }

    return 0;
}