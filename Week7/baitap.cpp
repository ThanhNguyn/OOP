/*
 * Bai tap ve nha - Thuc hanh File I/O, Dict, Serialization tren bai Can Bo
 * Ho va ten: Nguyen Tuan Thanh
 * MSSV: 25112107
 *
 * Yeu cau:
 *   1. Doc du lieu tu canbo.csv -> danh sach doi tuong (xu ly exception)
 *   2. Luu vao map<string, shared_ptr<CanBo>> (key = ho ten)
 *      Thao tac: them, xoa, tim theo ten, tim theo loai, in top 3 bac/luong cao nhat
 *   3. to_json() / from_json() -> luu/tai canbo.json (ensure_ascii tuong duong UTF-8)
 *   4. Lop QuanLyCanBo voi menu CLI, tu dong luu JSON, xu ly moi ngoai le
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include "single_include/json.hpp"

using namespace std;
using json = nlohmann::json;

// ======================== LOP CAN BO (BASE) ========================
class CanBo {
protected:
    string hoTen;
    int tuoi;
    string gioiTinh;
    string diaChi;

public:
    CanBo() : hoTen(""), tuoi(0), gioiTinh(""), diaChi("") {}

    CanBo(string hoTen, int tuoi, string gioiTinh, string diaChi)
        : hoTen(hoTen), tuoi(tuoi), gioiTinh(gioiTinh), diaChi(diaChi) {}

    virtual ~CanBo() {}

    // --- Getter ---
    string getHoTen() const { return hoTen; }
    int getTuoi() const { return tuoi; }
    string getGioiTinh() const { return gioiTinh; }
    string getDiaChi() const { return diaChi; }

    // --- Lay loai de phan biet ---
    virtual string getLoai() const { return "CanBo"; }

    // --- Lay gia tri de xep hang (bac / nganh / cong viec) ---
    // Doi voi CongNhan: tra ve bac (so), cang cao cang tot
    // Doi voi KySu, NhanVien: tra ve 0 (khong co bac so)
    virtual int getBacSort() const { return 0; }

    // --- Lay thong tin rieng (bac/nganh/cong viec) de hien thi ---
    virtual string getThongTinRieng() const { return ""; }

    // --- Nhap tu ban phim ---
    virtual void input() {
        cout << "  Ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "  Tuoi: ";
        cin >> tuoi;
        cout << "  Gioi tinh: ";
        getline(cin >> ws, gioiTinh);
        cout << "  Dia chi: ";
        getline(cin >> ws, diaChi);
    }

    // --- Hien thi ---
    virtual void output() const {
        cout << "  [" << getLoai() << "] " << hoTen
             << " | Tuoi: " << tuoi
             << " | GT: " << gioiTinh
             << " | DC: " << diaChi;
        string rieng = getThongTinRieng();
        if (!rieng.empty()) cout << " | " << rieng;
        cout << endl;
    }

    // --- Serialize sang JSON ---
    virtual json to_json() const {
        return {
            {"ho_ten", hoTen},
            {"tuoi", tuoi},
            {"gioi_tinh", gioiTinh},
            {"dia_chi", diaChi},
            {"loai", getLoai()}
        };
    }

    // --- Factory: tao doi tuong tu JSON ---
    static shared_ptr<CanBo> from_json(const json& j);
};

// ======================== CONG NHAN ========================
class CongNhan : public CanBo {
private:
    int bac;

public:
    CongNhan() : CanBo(), bac(0) {}

    CongNhan(string hoTen, int tuoi, string gioiTinh, string diaChi, int bac)
        : CanBo(hoTen, tuoi, gioiTinh, diaChi), bac(bac) {}

    string getLoai() const override { return "CongNhan"; }
    int getBacSort() const override { return bac; }
    string getThongTinRieng() const override { return "Bac: " + to_string(bac); }

    void input() override {
        cout << "--- Nhap thong tin Cong Nhan ---\n";
        CanBo::input();
        cout << "  Bac: ";
        cin >> bac;
    }

    json to_json() const override {
        json j = CanBo::to_json();
        j["bac"] = bac;
        return j;
    }
};

// ======================== KY SU ========================
class KySu : public CanBo {
private:
    string nganhDaoTao;

public:
    KySu() : CanBo(), nganhDaoTao("") {}

    KySu(string hoTen, int tuoi, string gioiTinh, string diaChi, string nganh)
        : CanBo(hoTen, tuoi, gioiTinh, diaChi), nganhDaoTao(nganh) {}

    string getLoai() const override { return "KySu"; }
    string getThongTinRieng() const override { return "Nganh: " + nganhDaoTao; }

    void input() override {
        cout << "--- Nhap thong tin Ky Su ---\n";
        CanBo::input();
        cout << "  Nganh dao tao: ";
        getline(cin >> ws, nganhDaoTao);
    }

    json to_json() const override {
        json j = CanBo::to_json();
        j["nganh_dao_tao"] = nganhDaoTao;
        return j;
    }
};

// ======================== NHAN VIEN ========================
class NhanVien : public CanBo {
private:
    string congViec;

public:
    NhanVien() : CanBo(), congViec("") {}

    NhanVien(string hoTen, int tuoi, string gioiTinh, string diaChi, string cv)
        : CanBo(hoTen, tuoi, gioiTinh, diaChi), congViec(cv) {}

    string getLoai() const override { return "NhanVien"; }
    string getThongTinRieng() const override { return "Cong viec: " + congViec; }

    void input() override {
        cout << "--- Nhap thong tin Nhan Vien ---\n";
        CanBo::input();
        cout << "  Cong viec: ";
        getline(cin >> ws, congViec);
    }

    json to_json() const override {
        json j = CanBo::to_json();
        j["cong_viec"] = congViec;
        return j;
    }
};

// ======================== from_json (Factory) ========================
shared_ptr<CanBo> CanBo::from_json(const json& j) {
    string loai = j.at("loai").get<string>();

    string hoTen   = j.at("ho_ten").get<string>();
    int    tuoi    = j.at("tuoi").get<int>();
    string gt      = j.at("gioi_tinh").get<string>();
    string dc      = j.at("dia_chi").get<string>();

    if (loai == "CongNhan") {
        int bac = j.at("bac").get<int>();
        return make_shared<CongNhan>(hoTen, tuoi, gt, dc, bac);
    }
    if (loai == "KySu") {
        string nganh = j.at("nganh_dao_tao").get<string>();
        return make_shared<KySu>(hoTen, tuoi, gt, dc, nganh);
    }
    if (loai == "NhanVien") {
        string cv = j.at("cong_viec").get<string>();
        return make_shared<NhanVien>(hoTen, tuoi, gt, dc, cv);
    }

    // Mac dinh tra ve CanBo goc
    return make_shared<CanBo>(hoTen, tuoi, gt, dc);
}

// ======================== LOP QUAN LY CAN BO ========================
class QuanLyCanBo {
private:
    map<string, shared_ptr<CanBo>> danhSach;
    string jsonFile;

    // --- Trim khoang trang dau cuoi ---
    static string trim(const string& s) {
        size_t start = s.find_first_not_of(" \t\r\n");
        size_t end   = s.find_last_not_of(" \t\r\n");
        if (start == string::npos) return "";
        return s.substr(start, end - start + 1);
    }

    // --- Tach dong CSV thanh cac truong ---
    static vector<string> splitCSV(const string& line, char sep = ',') {
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, sep)) {
            tokens.push_back(trim(token));
        }
        return tokens;
    }

public:
    QuanLyCanBo(string jsonPath = "canbo.json") : jsonFile(jsonPath) {}

    // ==================== YEU CAU 1: Doc tu CSV ====================
    void docCSV(const string& csvFile) {
        ifstream fin(csvFile);
        if (!fin.is_open()) {
            throw runtime_error("FileNotFoundError: Khong the mo file '" + csvFile + "'");
        }

        string line;
        // Bo dong tieu de
        if (!getline(fin, line)) {
            fin.close();
            cout << "[WARN] File CSV rong.\n";
            return;
        }

        int dong = 1; // dem dong (ke ca header)
        int soLuongThem = 0;

        while (getline(fin, line)) {
            dong++;
            line = trim(line);
            if (line.empty()) continue;

            try {
                vector<string> fields = splitCSV(line);
                if (fields.size() < 6) {
                    throw invalid_argument("Thieu truong du lieu");
                }

                string hoTen   = fields[0];
                int    tuoi    = stoi(fields[1]); // co the throw invalid_argument
                string gt      = fields[2];
                string dc      = fields[3];
                string loai    = fields[4];
                string rieng   = fields[5];

                shared_ptr<CanBo> cb;

                if (loai == "CongNhan") {
                    int bac = stoi(rieng); // co the throw
                    cb = make_shared<CongNhan>(hoTen, tuoi, gt, dc, bac);
                } else if (loai == "KySu") {
                    cb = make_shared<KySu>(hoTen, tuoi, gt, dc, rieng);
                } else if (loai == "NhanVien") {
                    cb = make_shared<NhanVien>(hoTen, tuoi, gt, dc, rieng);
                } else {
                    throw invalid_argument("Loai khong hop le: '" + loai + "'");
                }

                danhSach[hoTen] = cb;
                soLuongThem++;

            } catch (const invalid_argument& e) {
                cerr << "[ValueError] Dong " << dong << ": " << e.what()
                     << " -> Bo qua dong nay.\n";
            } catch (const out_of_range& e) {
                cerr << "[ValueError] Dong " << dong << ": Gia tri vuot pham vi"
                     << " -> Bo qua dong nay.\n";
            }
        }

        fin.close();
        cout << "=> Da doc " << soLuongThem << " can bo tu '" << csvFile << "'.\n";
    }

    // ==================== YEU CAU 2: Cac thao tac ====================

    // --- Them can bo ---
    void themCanBo() {
        int loai;
        cout << "Chon loai (1: CongNhan, 2: KySu, 3: NhanVien): ";
        cin >> loai;

        shared_ptr<CanBo> cb;
        if (loai == 1) {
            cb = make_shared<CongNhan>();
        } else if (loai == 2) {
            cb = make_shared<KySu>();
        } else if (loai == 3) {
            cb = make_shared<NhanVien>();
        } else {
            cout << "[LOI] Loai khong hop le.\n";
            return;
        }

        cb->input();

        if (danhSach.count(cb->getHoTen())) {
            cout << "[WARN] Can bo '" << cb->getHoTen() << "' da ton tai, se ghi de.\n";
        }
        danhSach[cb->getHoTen()] = cb;
        cout << "=> Da them: " << cb->getHoTen() << endl;
    }

    // --- Xoa theo ho ten ---
    void xoaCanBo() {
        string ten;
        cout << "Nhap ho ten can bo can xoa: ";
        getline(cin >> ws, ten);

        auto it = danhSach.find(ten);
        if (it != danhSach.end()) {
            danhSach.erase(it);
            cout << "=> Da xoa: " << ten << endl;
        } else {
            cout << "[KHONG TIM THAY] '" << ten << "'\n";
        }
    }

    // --- Tim theo ho ten ---
    void timTheoTen() const {
        string ten;
        cout << "Nhap ho ten can tim: ";
        getline(cin >> ws, ten);

        auto it = danhSach.find(ten);
        if (it != danhSach.end()) {
            cout << "=> Ket qua:\n";
            it->second->output();
        } else {
            cout << "[KHONG TIM THAY] '" << ten << "'\n";
        }
    }

    // --- Tim theo loai ---
    void timTheoLoai() const {
        string loai;
        cout << "Nhap loai (CongNhan / KySu / NhanVien): ";
        getline(cin >> ws, loai);

        bool found = false;
        cout << "=> Danh sach " << loai << ":\n";
        for (const auto& [ten, cb] : danhSach) {
            if (cb->getLoai() == loai) {
                cb->output();
                found = true;
            }
        }
        if (!found) {
            cout << "  (Khong tim thay can bo nao loai '" << loai << "')\n";
        }
    }

    // --- In top 3 bac/luong cao nhat ---
    void inTop3Bac() const {
        // Loc ra CongNhan (co bac so)
        vector<shared_ptr<CanBo>> dsCN;
        for (const auto& [ten, cb] : danhSach) {
            if (cb->getLoai() == "CongNhan") {
                dsCN.push_back(cb);
            }
        }

        if (dsCN.empty()) {
            cout << "Khong co Cong Nhan nao trong danh sach.\n";
            return;
        }

        // Sap xep giam dan theo bac
        sort(dsCN.begin(), dsCN.end(),
            [](const shared_ptr<CanBo>& a, const shared_ptr<CanBo>& b) {
                return a->getBacSort() > b->getBacSort();
            });

        int n = min((int)dsCN.size(), 3);
        cout << "=> Top " << n << " Cong Nhan co bac cao nhat:\n";
        for (int i = 0; i < n; i++) {
            cout << "  #" << (i + 1) << " ";
            dsCN[i]->output();
        }
    }

    // --- Hien thi toan bo ---
    void hienThiTatCa() const {
        if (danhSach.empty()) {
            cout << "Danh sach rong.\n";
            return;
        }
        cout << "========== DANH SACH CAN BO (" << danhSach.size() << ") ==========\n";
        int stt = 1;
        for (const auto& [ten, cb] : danhSach) {
            cout << stt++ << ".";
            cb->output();
        }
        cout << "==================================================\n";
    }

    // ==================== YEU CAU 3: Luu / Tai JSON ====================

    void luuJSON() const {
        json arr = json::array();
        for (const auto& [ten, cb] : danhSach) {
            arr.push_back(cb->to_json());
        }

        ofstream fout(jsonFile);
        if (!fout.is_open()) {
            throw runtime_error("Khong the ghi file '" + jsonFile + "'");
        }
        // dump(2, ' ', false, json::error_handler_t::replace) -> UTF-8, ensure_ascii=false tuong duong
        fout << arr.dump(2, ' ', false, json::error_handler_t::replace);
        fout.close();
        cout << "=> Da luu " << arr.size() << " can bo vao '" << jsonFile << "'.\n";
    }

    void taiJSON() {
        ifstream fin(jsonFile);
        if (!fin.is_open()) {
            throw runtime_error("FileNotFoundError: Khong the mo file '" + jsonFile + "'");
        }

        json raw;
        try {
            fin >> raw;
        } catch (const json::parse_error& e) {
            fin.close();
            throw runtime_error("Loi parse JSON: " + string(e.what()));
        }
        fin.close();

        danhSach.clear();
        int count = 0;
        for (const auto& item : raw) {
            try {
                auto cb = CanBo::from_json(item);
                danhSach[cb->getHoTen()] = cb;
                count++;
            } catch (const exception& e) {
                cerr << "[LOI] Khong the tai 1 ban ghi: " << e.what() << endl;
            }
        }
        cout << "=> Da tai " << count << " can bo tu '" << jsonFile << "'.\n";
    }

    // ==================== YEU CAU 4: Menu CLI ====================
    void menu() {
        // Thu tai JSON khi khoi dong (neu co)
        try {
            ifstream test(jsonFile);
            if (test.good()) {
                test.close();
                taiJSON();
                cout << "[AUTO] Da tai du lieu tu '" << jsonFile << "' khi khoi dong.\n";
            }
        } catch (...) {
            // File chua ton tai hoac loi -> bo qua
        }

        int chon;
        do {
            cout << "\n============ QUAN LY CAN BO ============\n";
            cout << "  1. Doc du lieu tu CSV\n";
            cout << "  2. Them can bo\n";
            cout << "  3. Xoa can bo\n";
            cout << "  4. Tim theo ho ten\n";
            cout << "  5. Tim theo loai (CongNhan/KySu/NhanVien)\n";
            cout << "  6. In top 3 bac cao nhat (CongNhan)\n";
            cout << "  7. Hien thi tat ca\n";
            cout << "  8. Luu vao JSON\n";
            cout << "  9. Tai tu JSON\n";
            cout << "  0. Thoat\n";
            cout << "=========================================\n";
            cout << "Lua chon: ";

            if (!(cin >> chon)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[LOI] Vui long nhap so.\n";
                continue;
            }

            try {
                switch (chon) {
                    case 1: {
                        string csvPath;
                        cout << "Nhap duong dan file CSV: ";
                        getline(cin >> ws, csvPath);
                        docCSV(csvPath);
                        luuJSON(); // tu dong luu sau thao tac
                        break;
                    }
                    case 2:
                        themCanBo();
                        luuJSON();
                        break;
                    case 3:
                        xoaCanBo();
                        luuJSON();
                        break;
                    case 4:
                        timTheoTen();
                        break;
                    case 5:
                        timTheoLoai();
                        break;
                    case 6:
                        inTop3Bac();
                        break;
                    case 7:
                        hienThiTatCa();
                        break;
                    case 8:
                        luuJSON();
                        break;
                    case 9:
                        taiJSON();
                        break;
                    case 0:
                        luuJSON(); // luu truoc khi thoat
                        cout << "Tam biet!\n";
                        break;
                    default:
                        cout << "[LOI] Lua chon khong hop le.\n";
                }
            } catch (const exception& e) {
                cerr << "[EXCEPTION] " << e.what() << endl;
                // Chuong trinh KHONG crash
            }
        } while (chon != 0);
    }
};

// ======================== MAIN ========================
int main() {
    QuanLyCanBo app("canbo.json");
    app.menu();
    return 0;
}
