#include <bits/stdc++.h>
using namespace std;

// 1. Custom Exception
class TuoiKhongHopLe : public exception {
public:
    const char* what() const throw() {
        return "Loi: Tuoi phai tu 18 den 65!";
    }
};

class BacKhongHopLe : public exception {
public:
    const char* what() const throw() {
        return "Loi: Bac phai tu 1 den 10!";
    }
};

// 2. Abstract Base Class (ABC)
class CanBo {
protected:
    string hoTen;
    int tuoi;
    string gioiTinh;
    string diaChi;

public:
    CanBo() : hoTen(""), tuoi(0), gioiTinh(""), diaChi("") {}
    CanBo(string name, int age, string gender, string address) 
        : hoTen(name), tuoi(age), gioiTinh(gender), diaChi(address) {}
    
    virtual ~CanBo() {}

    // abstract method 
    virtual void mo_ta() const = 0; 
    
    // Hàm phụ trợ hỗ trợ ghi file
    virtual int getLoai() const = 0; 
    virtual string getThuocTinhRieng() const = 0;

    virtual void input() {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        
        // Validation Tuoi 
        while (true) {
            cout << "Nhap tuoi (18-65): ";
            cin >> tuoi;
            try {
                if (tuoi < 18 || tuoi > 65) throw TuoiKhongHopLe();
                break; // Hợp lệ thì thoát vòng lặp
            } catch (const TuoiKhongHopLe& e) {
                cout << e.what() << " Vui long nhap lai.\n";
            }
        }
        
        cout << "Nhap gioi tinh: ";
        getline(cin >> ws, gioiTinh);
        cout << "Nhap dia chi: ";
        getline(cin >> ws, diaChi);
    }

    string get_hoTen() const { return hoTen; }
    int getTuoi() const { return tuoi; }
    string getGioiTinh() const { return gioiTinh; }
    string getDiaChi() const { return diaChi; }

    // Overload (theo họ tên + tuổi)
    bool operator==(const CanBo& other) const {
        return (hoTen == other.hoTen && tuoi == other.tuoi);
    }

    // Overload (sắp xếp theo tên ABC)
    bool operator<(const CanBo& other) const {
        return hoTen < other.hoTen;
    }

    // Overload (In đầy đủ thông tin)
    friend ostream& operator<<(ostream& os, const CanBo& cb) {
        cb.mo_ta(); // Gọi hàm đa hình
        return os;
    }
    
    // Hàm nạp dữ liệu từ file
    void setChung(string ten, int t, string gt, string dc) {
        hoTen = ten; tuoi = t; gioiTinh = gt; diaChi = dc;
    }
};

// 3. Các lớp dẫn xuất
class CongNhan : public CanBo {
private:
    int bac;
public:
    int getLoai() const override { return 1; }
    string getThuocTinhRieng() const override { return to_string(bac); }
    
    void setBac(int b) { bac = b; }

    void input() override {
        cout << "--- Nhap thong tin Cong Nhan ---\n";
        CanBo::input();
        
        // Validation Bậc
        while (true) {
            cout << "Nhap bac (1-10): ";
            cin >> bac;
            try {
                if (bac < 1 || bac > 10) throw BacKhongHopLe();
                break;
            } catch (const BacKhongHopLe& e) {
                cout << e.what() << " Vui long nhap lai.\n";
            }
        }
    }

    // Override mo_ta() -> đa hình
    void mo_ta() const override {
        cout << "[Cong Nhan] Ho ten: " << hoTen << " | Tuoi: " << tuoi 
             << " | Gioi tinh: " << gioiTinh << " | Dia chi: " << diaChi 
             << " | Bac: " << bac << '\n';
    }
};

class KySu : public CanBo {
private:
    string nganhDaoTao;
public:
    int getLoai() const override { return 2; }
    string getThuocTinhRieng() const override { return nganhDaoTao; }
    
    void setNganh(string nganh) { nganhDaoTao = nganh; }

    void input() override {
        cout << "--- Nhap thong tin Ky Su ---\n";
        CanBo::input();
        cout << "Nhap nganh dao tao: ";
        getline(cin >> ws, nganhDaoTao);
    }

    void mo_ta() const override {
        cout << "[Ky Su] Ho ten: " << hoTen << " | Tuoi: " << tuoi 
             << " | Gioi tinh: " << gioiTinh << " | Dia chi: " << diaChi 
             << " | Nganh: " << nganhDaoTao << '\n';
    }
};

class NhanVien : public CanBo {
private:
    string congViec;
public:
    int getLoai() const override { return 3; }
    string getThuocTinhRieng() const override { return congViec; }
    
    void setCongViec(string cv) { congViec = cv; }

    void input() override {
        cout << "--- Nhap thong tin Nhan Vien ---\n";
        CanBo::input();
        cout << "Nhap cong viec: ";
        getline(cin >> ws, congViec);
    }

    void mo_ta() const override {
        cout << "[Nhan Vien] Ho ten: " << hoTen << " | Tuoi: " << tuoi 
             << " | Gioi tinh: " << gioiTinh << " | Dia chi: " << diaChi 
             << " | Cong viec: " << congViec << '\n';
    }
};

// 4. Lớp Quản Lý
class management {
private:
    vector<CanBo*> danhsach;
public:
    ~management() {
        for (auto cb : danhsach) delete cb;
    }

    void addCanBo() {
        int loai;
        cout << "Loai can bo (1: Cong Nhan, 2: Ky Su, 3: Nhan Vien): ";
        cin >> loai;
        CanBo* cb = nullptr;
        
        if (loai == 1) cb = new CongNhan();
        else if (loai == 2) cb = new KySu();
        else if (loai == 3) cb = new NhanVien();
        else {
            cout << "Loai can bo khong hop le.\n";
            return;
        }
        
        cb->input();
        danhsach.push_back(cb);
        cout << "=> Da them can bo!\n";
    }

    void searchByName() {
        string ten_can_tim;
        cout << "Nhap ten can bo can tim: ";
        getline(cin >> ws, ten_can_tim);
        bool found = false;
        
        string ten_thuong = ten_can_tim;
        transform(ten_thuong.begin(), ten_thuong.end(), ten_thuong.begin(), ::tolower);

        for (const auto& cb : danhsach) {
            string ten_cb = cb->get_hoTen();
            transform(ten_cb.begin(), ten_cb.end(), ten_cb.begin(), ::tolower);
            
            if (ten_cb.find(ten_thuong) != string::npos) {
                cout << *cb; // Sử dụng toán tử << đã nạp chồng
                found = true;
            }
        }
        if (!found) cout << "Khong tim thay!\n";
    }

    void sapXepVaHienThi() {
        if (danhsach.empty()) {
            cout << "Danh sach trong.\n";
            return;
        }
        // Sử dụng __lt__ (toán tử <) đã nạp chồng trong CanBo
        sort(danhsach.begin(), danhsach.end(), [](CanBo* a, CanBo* b) {
            return *a < *b; 
        });

        cout << "\n--- Danh sach can bo (Da sap xep theo ten) ---\n";
        for (const auto& cb : danhsach) {
            cout << *cb; // Đa hình qua toán tử <<
        }
    }

    // Tương đương "with open('canbo.txt', 'w')"
    void luuFile() {
        ofstream fo("canbo.txt");
        if (!fo) { cout << "Loi mo file!\n"; return; }
        
        for (auto cb : danhsach) {
            fo << cb->getLoai() << '\n'
               << cb->get_hoTen() << '\n'
               << cb->getTuoi() << '\n'       // Gọi qua getter
               << cb->getGioiTinh() << '\n'   // Gọi qua getter
               << cb->getDiaChi() << '\n'     // Gọi qua getter
               << cb->getThuocTinhRieng() << '\n';
        }
        fo.close();
        cout << "=> Da luu danh sach vao file canbo.txt\n";
    }

    void docFile() {
        ifstream fi("canbo.txt");
        if (!fi) { cout << "File chua ton tai, tao moi...\n"; return; }
        
        // Xoá danh sách cũ tránh trùng lặp khi đọc lại
        for (auto cb : danhsach) delete cb;
        danhsach.clear();

        int loai;
        while (fi >> loai) {
            fi.ignore();
            string ten, gt, dc, thuoc_tinh_rieng;
            int t;
            getline(fi, ten);
            fi >> t; fi.ignore();
            getline(fi, gt);
            getline(fi, dc);
            getline(fi, thuoc_tinh_rieng);

            CanBo* cb = nullptr;
            if (loai == 1) {
                CongNhan* cn = new CongNhan();
                cn->setBac(stoi(thuoc_tinh_rieng));
                cb = cn;
            } else if (loai == 2) {
                KySu* ks = new KySu();
                ks->setNganh(thuoc_tinh_rieng);
                cb = ks;
            } else if (loai == 3) {
                NhanVien* nv = new NhanVien();
                nv->setCongViec(thuoc_tinh_rieng);
                cb = nv;
            }
            if (cb) {
                cb->setChung(ten, t, gt, dc);
                danhsach.push_back(cb);
            }
        }
        fi.close();
        cout << "=> Da doc du lieu tu file canbo.txt\n";
    }
};

int main() {
    management quanly;
    quanly.docFile(); // Tự động load dữ liệu từ file khi mở chương trình

    int n;
    do {
        cout << "\n===== QUAN LY CAN BO =====\n";
        cout << "1. Them can bo\n";
        cout << "2. Tim kiem can bo theo ten\n";
        cout << "3. Hien thi danh sach (Da sap xep)\n";
        cout << "4. Luu danh sach vao file\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> n;
        
        switch (n) {
            case 1: quanly.addCanBo(); break;
            case 2: quanly.searchByName(); break;
            case 3: quanly.sapXepVaHienThi(); break;
            case 4: quanly.luuFile(); break;
            case 0: 
                quanly.luuFile(); // Tự động lưu trước khi thoát
                cout << "Thoat chuong trinh.\n"; 
                break;
            default: cout << "Lua chon khong hop le.\n";
        }
    } while (n != 0);
    
    return 0;
}