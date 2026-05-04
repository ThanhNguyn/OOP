#include <iostream>
#include <string>
using namespace std;

class TuLanh {
private:
    string nhanhieu;
    string maso;
    string nuocsx;
    bool tkdien;
    int dungtich;
    int gia;

public:
    TuLanh() : nhanhieu("Elextrolux"), maso("UNKNOWN"), nuocsx("Việt Nam"),
               tkdien(true), dungtich(256), gia(7000000) {}

    TuLanh(string nhanhieu, string maso, string nuocsx, bool tkdien, int dungtich, int gia)
        : nhanhieu(nhanhieu), maso(maso), nuocsx(nuocsx),
          tkdien(tkdien), dungtich(dungtich), gia(gia) {}

    TuLanh(const TuLanh& tl) : nhanhieu(tl.nhanhieu), maso(tl.maso), nuocsx(tl.nuocsx),
                                tkdien(tl.tkdien), dungtich(tl.dungtich), gia(tl.gia) {}

    void makeCopy(TuLanh tl) {
        nhanhieu = tl.nhanhieu;
        maso = tl.maso;
        nuocsx = tl.nuocsx;
        tkdien = tl.tkdien;
        dungtich = tl.dungtich;
        gia = tl.gia;
    }

    void nhapThongTin() {
        getline(cin, nhanhieu);
        getline(cin, maso);
        getline(cin, nuocsx);
        string s;
        getline(cin, s);
        tkdien = (s == "True" || s == "true" || s == "1");
        cin >> dungtich;
        cin >> gia;
        cin.ignore();
    }

    void hienThi() {
        cout << "Nhãn hiệu: " << nhanhieu << "\n";
        cout << "Mã số: " << maso << "\n";
        cout << "Nước SX: " << nuocsx << "\n";
        cout << "T/K điện: " << (tkdien ? "Có" : "Không") << "\n";
        cout << "Dung tích: " << dungtich << "L\n";
        cout << "Giá: " << gia << "VNĐ\n";
    }

    void print() { hienThi(); }

    string layNhanHieu() { return nhanhieu; }
    int layGia() { return gia; }

    int soNguoiSD() { return dungtich / 100; }

    bool cungNhanHieu(TuLanh tl) { return nhanhieu == tl.nhanhieu; }

    bool nhHon(TuLanh tl) { return dungtich < tl.dungtich; }
};