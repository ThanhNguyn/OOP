#include <bits/stdc++.h>/
using namespace std;
// UML : https://drive.google.com/file/d/1fxYmTflEloUKM3xhoQN-DJ8iQ5_tfZON/view?usp=sharing
class HangHoa{
protected:
    string maHang;
    string tenHang;
    string nhaSanXuat;
    double gia;
public:
    HangHoa(){
        maHang = "";
        tenHang = "";
        nhaSanXuat = "";
        gia = 0;
    }
    virtual void nhap(){
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cout << "Nhap ten hang: ";
        cin >> tenHang;
        cout << "Nhap nha san xuat: ";
        cin >> nhaSanXuat;
        cout << "Nhap gia: ";
        cin >> gia;
    }
    virtual void xuat(){
        cout << "Ma hang: " << maHang << endl;
        cout << "Ten hang: " << tenHang << endl;
        cout << "Nha san xuat: " << nhaSanXuat << endl;
        cout << "Gia: " << gia << endl;
    }
    virtual ~HangHoa(){}
};
class HangDienMay : public HangHoa{
private:
    int thoiGianBaoHanh;
    double dienAp;
    double congSuat;
public:
    HangDienMay() : HangHoa(){
        thoiGianBaoHanh = 0;
        dienAp = 0;
        congSuat = 0;
    }
    void nhap() override{
        HangHoa::nhap();
        cout << "Nhap thoi gian bao hanh: ";
        cin >> thoiGianBaoHanh;
        cout << "Nhap dien ap: ";
        cin >> dienAp;
        cout << "Nhap cong suat: ";
        cin >> congSuat;
    }
    void xuat() override{
        HangHoa::xuat();
        cout << "Thoi gian bao hanh: " << thoiGianBaoHanh << endl;
        cout << "Dien ap: " << dienAp << endl;
        cout << "Cong suat: " << congSuat << endl;
    }
};
class HangSanhSu : public HangHoa{
private:
    string loaiNguyenLieu;
public:
    HangSanhSu() : HangHoa(){
        loaiNguyenLieu = "";
    }
    void nhap() override{
        HangHoa::nhap();
        cout << "Nhap loai nguyen lieu: ";
        cin >> loaiNguyenLieu;
    }
    void xuat() override{
        HangHoa::xuat();
        cout << "Loai nguyen lieu: " << loaiNguyenLieu << endl;
    }
};
class HangThucPham : public HangHoa{
private:
    string ngaySanXuat;
    string ngayHetHan;
public:
    HangThucPham() : HangHoa(){
        ngaySanXuat = "";
        ngayHetHan = "";
    }
    void nhap() override{
        HangHoa::nhap();
        cout << "Nhap ngay san xuat: ";
        cin >> ngaySanXuat;
        cout << "Nhap ngay het han: ";
        cin >> ngayHetHan;
    }
    void xuat() override{
        HangHoa::xuat();
        cout << "Ngay san xuat: " << ngaySanXuat << endl;
        cout << "Ngay het han: " << ngayHetHan << endl;
    }
};
int main(){
    HangDienMay dienMay;
    HangSanhSu sanhSu;
    HangThucPham thucPham;

    cout << "Nhap thong tin hang dien may:" << endl;
    dienMay.nhap();
    cout << "\nNhap thong tin hang sanh su:" << endl;
    sanhSu.nhap();
    cout << "\nNhap thong tin hang thuc pham:" << endl;
    thucPham.nhap();

    cout << "\nThong tin hang dien may:" << endl;
    dienMay.xuat();
    cout << "\nThong tin hang sanh su:" << endl;
    sanhSu.xuat();
    cout << "\nThong tin hang thuc pham:" << endl;
    thucPham.xuat();

    return 0;
}