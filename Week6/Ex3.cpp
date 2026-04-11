#include <bits/stdc++.h>

using namespace std;

// 1. Custom Exception
class MauSoBangKhong : public exception {
public:
    const char* what() const throw() {
        return "Loi: Mau so khong duoc bang 0!";
    }
};

// 2. Xây dựng lớp Phân Số
class PhanSo {
private:
    long long tu;
    long long mau;

public:
    // Constructor 
    PhanSo(long long t = 0, long long m = 1) : tu(t) {
        set_mau(m); 
    }

    // Getter và Setter
    long long get_tu() const { return tu; }
    long long get_mau() const { return mau; }

    void set_tu(long long t) { tu = t; }
    
    void set_mau(long long m) {
        if (m == 0) throw MauSoBangKhong();
        
        // Chuẩn hóa dấu: nếu mẫu âm thì chuyển dấu lên tử
        if (m < 0) { 
            tu = -tu;
            mau = -m;
        } else {
            mau = m;
        }
    }

    // Kiểm tra phân số tối giản (is_toi_gian)
    bool is_toi_gian() const {
        return std::gcd(abs(tu), abs(mau)) == 1;
    }

    // Tìm dạng tối giản (toi_gian) - Tối giản trực tiếp object hiện tại
    PhanSo& toi_gian() {
        long long ucln = std::gcd(abs(tu), abs(mau));
        tu /= ucln;
        mau /= ucln;
        return *this;
    }

    // ---------------- Operator Overloading ----------------

    // Cộng 
    PhanSo operator+(const PhanSo& other) const {
        long long t = tu * other.mau + other.tu * mau;
        long long m = mau * other.mau;
        return PhanSo(t, m).toi_gian();
    }

    // Trừ
    PhanSo operator-(const PhanSo& other) const {
        long long t = tu * other.mau - other.tu * mau;
        long long m = mau * other.mau;
        return PhanSo(t, m).toi_gian();
    }

    // Nhân 
    PhanSo operator*(const PhanSo& other) const {
        long long t = tu * other.tu;
        long long m = mau * other.mau;
        return PhanSo(t, m).toi_gian();
    }

    // Chia
    PhanSo operator/(const PhanSo& other) const {
        if (other.tu == 0) throw MauSoBangKhong(); // Tránh lỗi chia cho 0
        long long t = tu * other.mau;
        long long m = mau * other.tu;
        return PhanSo(t, m).toi_gian();
    }
    // So sánh bằng 
    bool operator==(const PhanSo& other) const {
        // Nhân chéo để so sánh giá trị thực
        return tu * other.mau == other.tu * mau; 
    }
    // So sánh nhỏ hơn
    bool operator<(const PhanSo& other) const {
        return tu * other.mau < other.tu * mau;
    }

    // So sánh lớn hơn 
    bool operator>(const PhanSo& other) const {
        return tu * other.mau > other.tu * mau;
    }

    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        if (ps.mau == 1 || ps.tu == 0) {
            os << ps.tu; // In số nguyên nếu mẫu là 1 hoặc tử là 0
        } else {
            os << ps.tu << "/" << ps.mau;
        }
        return os;
    }
};

// Băm phân số dựa trên dạng tối giản để các phân số cùng giá trị (vd 1/2 và 2/4) vào cùng một rổ
namespace std {
    template <>
    struct hash<PhanSo> {
        size_t operator()(const PhanSo& ps) const {
            PhanSo temp = ps;
            temp.toi_gian(); // Đảm bảo băm ở dạng tối giản
            // Kết hợp mã băm của tử số và mẫu số
            return hash<long long>()(temp.get_tu()) ^ (hash<long long>()(temp.get_mau()) << 1);
        }
    };
}

int main() {
    vector<PhanSo> ds;
    int n;
    
    cout << "Nhap so luong phan so: ";
    cin >> n;

    // Yêu cầu: Nhập vào một dãy các phân số
    for (int i = 0; i < n; ++i) {
        long long t, m;
        while (true) {
            cout << "Nhap tu so va mau so cho phan so thu " << i + 1 << ": ";
            cin >> t >> m;
            try {
                PhanSo ps(t, m);
                ds.push_back(ps);
                break; // Hợp lệ thì thoát vòng lặp nhập
            } catch (const MauSoBangKhong& e) {
                cout << e.what() << " Vui long nhap lai.\n";
            }
        }
    }

    // Yêu cầu: In ra màn hình dạng tối giản
    cout << "\n--- Danh sach phan so sau khi toi gian ---\n";
    for (auto& ps : ds) {
        cout << ps.toi_gian() << "  ";
    }
    cout << "\n";

    // Yêu cầu: Sắp xếp tăng dần 
    sort(ds.begin(), ds.end());
    cout << "\n--- Danh sach phan so tang dan ---\n";
    for (const auto& ps : ds) {
        cout << ps << "  ";
    }
    cout << "\n";

    // Lọc các phân số trùng giá trị
    unordered_set<PhanSo> tap_hop_khong_trung(ds.begin(), ds.end());
    cout << "\n--- Tap hop phan so (Da loai bo cac gia tri trung lap) ---\n";
    for (const auto& ps : tap_hop_khong_trung) {
        cout << ps << "  ";
    }
    cout << "\n";

    return 0;
}