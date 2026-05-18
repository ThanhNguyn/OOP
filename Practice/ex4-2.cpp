#include <iostream>
#include <string>
using namespace std;

class TuLanh {
private:
    string nhanhieu, maso, nuocsx;
    bool tkdien;
    int dungtich, gia;

public:
    TuLanh() : nhanhieu("Elextrolux"), maso("UNKNOWN"), nuocsx("Việt Nam"),
               tkdien(true), dungtich(256), gia(7000000) {}

    TuLanh(string nhanhieu, string maso, string nuocsx, bool tkdien, int dungtich, int gia)
        : nhanhieu(nhanhieu), maso(maso), nuocsx(nuocsx),
          tkdien(tkdien), dungtich(dungtich), gia(gia) {}

    TuLanh(const TuLanh& tl) : nhanhieu(tl.nhanhieu), maso(tl.maso), nuocsx(tl.nuocsx),
                                tkdien(tl.tkdien), dungtich(tl.dungtich), gia(tl.gia) {}

    void makeCopy(TuLanh tl) {
        nhanhieu = tl.nhanhieu; maso = tl.maso; nuocsx = tl.nuocsx;
        tkdien = tl.tkdien; dungtich = tl.dungtich; gia = tl.gia;
    }

    void nhapThongTin() {
        getline(cin, nhanhieu); getline(cin, maso); getline(cin, nuocsx);
        string s; getline(cin, s);
        tkdien = (s == "True" || s == "true" || s == "1");
        cin >> dungtich >> gia; cin.ignore();
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

class TuLanhTest {
public:
    void testCase() {
        string line, p[6];
        getline(cin, line);
        int idx = 0; string cur = "";
        for (char c : line) {
            if (c == '|') { p[idx++] = cur; cur = ""; }
            else cur += c;
        }
        p[idx] = cur;
        TuLanh tu1(p[0], p[1], p[2], p[3] == "True", stoi(p[4]), stoi(p[5]));

        getline(cin, line);
        idx = 0; cur = "";
        for (char c : line) {
            if (c == '|') { p[idx++] = cur; cur = ""; }
            else cur += c;
        }
        p[idx] = cur;
        TuLanh tu2(p[0], p[1], p[2], p[3] == "True", stoi(p[4]), stoi(p[5]));

        cout << "= = = = = = = =\n";
        tu1.print();
        cout << "= = = = = = = =\n";
        tu2.print();
        cout << "= = = = = = = =\n";
    }
};