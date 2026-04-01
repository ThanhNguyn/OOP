#include <bits/stdc++.h>
using namespace std;
class CanBo{
    protected:
        string hoTen;
        int tuoi;
        string gioiTinh;
        string diaChi;
    public:
        CanBo() {
            hoTen = " ";
            tuoi = 0;
            gioiTinh = " ";
            diaChi = " ";
        }
        CanBo(string name, int age, string gender, string address){
            hoTen = name;
            tuoi = age;
            gioiTinh = gender;
            diaChi = address;
        }
        virtual void input(){
                cout << "Nhap ho ten: ";
                getline(cin >> ws, hoTen);
                cout << "Nhap tuoi: ";
                cin >> tuoi;
                cout << "Nhap gioi tinh: ";
                getline(cin >> ws, gioiTinh);
                cout << "Nhap dia chi: ";
                getline(cin >> ws, diaChi);
        }
        virtual void output() const {
            cout << "Ho ten: " << hoTen << '\n';
            cout << "Tuoi: " << tuoi << '\n';
            cout << "Gioi tinh: " << gioiTinh << '\n';
            cout << "Dia chi: " << diaChi << '\n';
        }
        string get_hoTen(){
            return hoTen;
        }
        virtual ~CanBo() {} // Virtual destructor
};
class CongNhan : public CanBo{
    private:
        int bac;
    public:
        void input() override {
            cout << "Nhap thong tin Cong Nhan:\n";
            CanBo::input();
            cout << "Nhap bac: ";
            cin >> bac;
        }
        void output() const override {
            cout << "Thong tin Cong Nhan:\n";
            CanBo::output();
            cout << "Bac: " << bac << '\n';
        }
};
class KySu : public CanBo{
    private:
        string nganhDaoTao;
    public:
        void input() override {
            cout << "Nhap thong tin Ky Su:\n";
            CanBo::input();
            cout << "Nhap nganh dao tao: ";
            getline(cin >> ws, nganhDaoTao);
        }
        void output() const override {
            cout << "Thong tin Ky Su:\n";
            CanBo::output();
            cout << "Nganh dao tao: " << nganhDaoTao << '\n';
        }
};
class NhanVien : public CanBo{
    private:
        string congViec;
    public:
        void input() override {
            cout << "Nhap thong tin Nhan Vien:\n";
            CanBo::input();
            cout << "Nhap cong viec: ";
            getline(cin >> ws, congViec);
        }
        void output() const override {
            cout << "Thong tin Nhan Vien:\n";
            CanBo::output();
            cout << "Cong viec: " << congViec << '\n';
        }
};
class management{
    private:
    vector<CanBo*> danhsach;
    public:
    void addCanBo() {
        int loai;
        cout << "Nhap loai can bo (1: Cong Nhan, 2: Ky Su, 3: Nhan Vien): ";
        cin >> loai;
        CanBo* cb = nullptr;
        if (loai == 1) {
            cb = new CongNhan();
        } else if (loai == 2) {
            cb = new KySu();
        } else if (loai == 3) {
            cb = new NhanVien();
        } else {
            cout << "Loai can bo khong hop le.\n";
            return;
        }
        cb -> input();
        danhsach.push_back(cb);
        cout << "Da them can bo vao danh sach.\n";
    }
    void searchByName() {
        string ten_can_tim;
        cout << "Nhap ten can bo can tim: ";
        getline(cin >> ws, ten_can_tim);
        bool found = false;
        for (const auto& cb : danhsach) {
            if (cb->get_hoTen() == ten_can_tim) {
                cb->output();
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay can bo co ten: " << ten_can_tim << '\n';
        }
    }
    void hienthiDanhSach() const {
        cout << "Danh sach can bo:\n";
        if (danhsach.empty()) {
            cout << "Danh sach trong.\n";
            return;
        }
        for (const auto& cb : danhsach) {
            cb->output();
            cout << "-------------------------\n";
        }
    }
    ~management() {
        for (auto cb : danhsach) {
            delete cb;
        }
    }
};
int main(){
    management quanly;
    int n;
    do {
        cout << "1. Them can bo\n";
        cout << "2. Tim kiem can bo theo ten\n";
        cout << "3. Hien thi danh sach can bo\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> n;
        switch (n) {
            case 1:
                quanly.addCanBo();
                break;
            case 2:
                quanly.searchByName();
                break;
            case 3:
                quanly.hienthiDanhSach();
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }
    } while (n != 0);
    return 0;
}