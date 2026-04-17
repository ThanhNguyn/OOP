#include <iostream>
#include <fstream>
#include <list>
#include <memory>
#include <string>
#include "single_include/json.hpp"

using namespace std;
using json = nlohmann::json;

class CanBo {
    protected:
        protected:
    string ho_ten;
    int tuoi;
    string gioi_tinh;
    string dia_chi;

public:
    CanBo(string hoTen, int tuoi, string gioiTinh, string diaChi)
        : ho_ten(hoTen), tuoi(tuoi), gioi_tinh(gioiTinh), dia_chi(diaChi) {}

    virtual ~CanBo() = default;

    virtual json to_json() const {
        return {
            {"ho_ten", ho_ten},
            {"tuoi", tuoi},
            {"gioi_tinh", gioi_tinh},
            {"dia_chi", dia_chi},
            {"loai", "CanBo"}
        };
    }

    virtual void hien_thi() const {
        cout << "CanBo: " << ho_ten
             << ", " << tuoi
             << ", " << gioi_tinh
             << ", " << dia_chi << endl;
    }

    static shared_ptr<CanBo> from_json(const json& j);
};

class CongNhan : public CanBo {
private:
    int bac;

public:
    CongNhan(string hoTen, int tuoi, string gioiTinh, string diaChi, int bac)
        : CanBo(hoTen, tuoi, gioiTinh, diaChi), bac(bac) {}

    json to_json() const override {
        return {
            {"ho_ten", ho_ten},
            {"tuoi", tuoi},
            {"gioi_tinh", gioi_tinh},
            {"dia_chi", dia_chi},
            {"bac", bac},
            {"loai", "CongNhan"}
        };
    }

    void hien_thi() const override {
        cout << "CongNhan: " << ho_ten
             << ", " << tuoi
             << ", " << gioi_tinh
             << ", " << dia_chi
             << ", bac " << bac << endl;
    }
};

shared_ptr<CanBo> CanBo::from_json(const json& j) {
    string loai = j["loai"];

    if (loai == "CongNhan") {
        return make_shared<CongNhan>(
            j["ho_ten"],
            j["tuoi"],
            j["gioi_tinh"],
            j["dia_chi"],
            j["bac"]
        );
    }

    return make_shared<CanBo>(
        j["ho_ten"],
        j["tuoi"],
        j["gioi_tinh"],
        j["dia_chi"]
    );
}

int main() {
    vector<shared_ptr<CanBo>> danh_sach = {
        make_shared<CanBo>("Nguyen An", 30, "Nam", "Ha Noi"),
        make_shared<CongNhan>("Tran Binh", 25, "Nam", "TP.HCM", 5)
    };

    // === LUU ===
    json data = json::array();
    for (const auto& cb : danh_sach) {
        data.push_back(cb->to_json());
    }

    ofstream outFile("canbo.json");
    outFile << data.dump(2);
    outFile.close();

    // === TAI ===
    ifstream inFile("canbo.json");
    json raw;
    inFile >> raw;
    inFile.close();

    vector<shared_ptr<CanBo>> ds_loaded;
    for (const auto& item : raw) {
        ds_loaded.push_back(CanBo::from_json(item));
    }

    for (const auto& cb : ds_loaded) {
        cb->hien_thi();
    }

    return 0;
}