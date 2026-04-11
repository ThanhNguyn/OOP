#include "..\Week5\Ex1.cpp"
#include <bits/stdc++.h>
using namespace std;

// Exception
class GiaKhongHopLe : public exception {
public:
    const char* what() const noexcept override { return "Gia khong hop le!"; }
};
class MaHangTrungLap : public exception {
public:
    const char* what() const noexcept override { return "Ma hang trung lap!"; }
};

// Abstract class
class HangHoa {
protected:
    string ma_hang, ten_hang;
    double gia;
public:
    HangHoa(string ma, string ten, double g){
        ma_hang= ma;
        ten_hang= ten;
        gia= g;
    }
    virtual string loai_hang() const = 0;
    virtual void inTTin() const = 0;
    string getMaHang() const { return ma_hang; }
    string getTenHang() const { return ten_hang; }
    double getGia() const { return gia; }
    void setGia(double g) {
        if (g < 0) throw GiaKhongHopLe();
        gia = g;
    }
    virtual ~HangHoa() {}
};

class HangDienMay : public HangHoa {
public:
    HangDienMay(string ma, string ten, double g) : HangHoa(ma, ten, g) {}
    string loai_hang() const override { return "Dien May"; }
    void nhapTTin() {
        cout << "Dien May: " << ma_hang << ", " << ten_hang << ", " << gia << endl;
    }
    void inTTin() const override {
        cout << "Dien May: " << ma_hang << ", " << ten_hang << ", " << gia << endl;
    }
};
class HangSanhSu : public HangHoa {
public:
    HangSanhSu(string ma, string ten, double g) : HangHoa(ma, ten, g) {}
    string loai_hang() const override { return "Sanh SU";}
    void nhapTTin() {
    cout << "Dien May: " << ma_hang << ", " << ten_hang << ", " << gia << endl;
    }
    void inTTin() const override {
        cout << "Sanh Su: " << ma_hang << ", " << ten_hang << ", " << gia << endl;
    }
};
class HangThucPham : public HangHoa{
public:
    HangThucPham(string ma, string ten, double g) : HangHoa(ma , ten, g) {}
    string loai_hang() const override { return "Thuc Pham";}
    void nhapTTin() {
        cout << "Thuc Pham: " << ma_hang << ", " << ten_hang << ", " << gia << endl;
    }
    void inTTin() const override {
        cout << "Thuc Pham: " << ma_hang << ", " << ten_hang << ", " << gia << endl;
    }
};

bool operator==(const HangHoa& a, const HangHoa& b) {
    return a.getMaHang() == b.getMaHang();
}
bool operator<(const HangHoa& a, const HangHoa& b) {
    return a.getGia() < b.getGia();
}

void saveToFile(const vector<HangHoa*>& ds, const string& filename) {
    ofstream fout(filename);
    for (auto sp : ds) {
        fout << sp->getMaHang() << "," << sp->getTenHang() << "," << sp->getGia() << "\n";
    }
}

int main() {
    vector<HangHoa*> ds;
    try {
        ds.push_back(new HangDienMay("DM01", "May lanh", 5000));
        ds.push_back(new HangDienMay("DM02", "Tu lanh", 7000));
        ds.push_back(new HangSanhSu("SS01", "Binh hoa", 3000));
        ds.push_back(new HangThucPham("TP01", "Vinamilk", 1000));
        saveToFile(ds, "hanghoa.txt");
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    for (auto p : ds) delete p;
    return 0;
}