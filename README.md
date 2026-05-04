# Object-Oriented Programming (OOP) Coursework 🚀

![Course](https://img.shields.io/badge/Course-OOP-orange)
![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Python](https://img.shields.io/badge/Python-3.x-yellow)
![Status](https://img.shields.io/badge/Status-Learning-success)

This repository contains my source code and assignments for the **Object-Oriented Programming** course — Information Systems major at [Vietnam Japan University](https://vju.ac.vn/).

## 🛠 Tech Stack
- **Language:** C++ (primary), Python
- **Standard:** C++17
- **Libraries:** [nlohmann/json](https://github.com/nlohmann/json) (Week 7)
- **IDE/Tools:** VS Code, g++ (MinGW)

## 📂 Folder Structure

```text
OOP/
├── Week1/   — Hello World
│   ├── Week1.cpp            : Print Hello World (C++)
│   └── Week1.py             : Print Hello World (Python)
│
├── Week2/   — Basic syntax & exercises
│   ├── Ex1.2.cpp            : Time conversion, distance, pace, speed
│   ├── BAI1.2.cpp           : Additional exercise
│   ├── Ex5.1.cpp            : Epoch time, days since 01/01/1970
│   ├── Ex2.2.py             : Sphere volume, wholesale cost, breakfast time
│   └── Ex3.3.py             : Draw 2x2 and 4x4 text grids
│
├── Week3/   — Classes & Objects
│   ├── bai1.py              : Point2D class (symmetry, distance)
│   ├── dog.cpp              : Dog class with behaviors
│   ├── vehicle.cpp          : Vehicle class
│   ├── bank.cpp             : Bank account class
│   ├── bai2.cpp             : Class exercise 2
│   ├── bai3.cpp             : Class exercise 3
│   └── ex15.1.cpp           : Extended class exercise
│
├── Week4/   — Encapsulation & Methods
│   ├── Ex1.cpp              : NhanVien (Employee) — salary calculation
│   ├── Ex2.cpp              : Exercise 2
│   └── Ex3.cpp              : Exercise 3
│
├── Week5/   — Inheritance & Polymorphism
│   ├── Ex1.cpp              : HangHoa hierarchy (DienMay, SanhSu, ThucPham)
│   ├── Ex2.cpp              : NhanVien hierarchy (CongTacVien, NVCT, TruongPhong)
│   ├── Ex3.cpp              : CanBo hierarchy (CongNhan, KySu, NhanVien) + management menu
│   ├── Rewrite_example1..cpp: Rewrite exercise
│   └── bonus.cpp            : Poker game (Card, Hand, Deck, Player, PokerGame)
│
├── Week6/   — Exception Handling & Operator Overloading
│   ├── Ex1.cpp              : Custom exceptions (GiaKhongHopLe, MaHangTrungLap) + file I/O
│   ├── Ex2.cpp              : Exercise 2
│   └── Ex3.cpp              : Exercise 3
│
├── Week7/   — File I/O, Dict (map), JSON Serialization
│   ├── baitap.cpp            : ★ Full homework — QuanLyCanBo with CSV/JSON/CLI menu
│   ├── canbo.csv             : Sample data (10 staff members)
│   ├── canbo.json            : Auto-generated JSON output
│   ├── canbo_json.cpp        : Early JSON serialization draft
│   └── single_include/
│       └── json.hpp          : nlohmann/json header-only library
│
├── Week8/   — Use Case Diagram
│   ├── README.md             : Mô tả biểu đồ use case
│   └── diagrams/
│       └── week8_usecase_diagram.png
│
└── Bonus/   — OOP-Grader (sv12.bcse-vju.com)
    ├── ex1-1.cpp             : Point class (read, print, move, distance)
    ├── ex1-2.cpp             : PointTest — test Point class
    ├── ex2-1.cpp             : LineSegment class (length, angle, move)
    ├── ex2-2.cpp             : LineSegmentTest — test LineSegment class
    ├── ex3-1.cpp             : ColorPoint class (kế thừa Point)
    ├── ex3-2.cpp             : ColorPointTest — test ColorPoint class
    ├── ex4-1.cpp             : TuLanh (Refrigerator) class
    ├── ex4-2.cpp             : TuLanhTest — test TuLanh class
    └── Topic/                : Đề bài gốc (PDF)
        ├── Bai 1.1.pdf … Bai 4.2.pdf
```

## 📝 Weekly Topics

| Week | Topic | Key Concepts |
|------|-------|-------------|
| 1 | Hello World | Basic I/O |
| 2 | Syntax & Exercises | Variables, math, time |
| 3 | Classes & Objects | Constructors, methods, encapsulation |
| 4 | Encapsulation | Getters/setters, salary calculation |
| 5 | Inheritance & Polymorphism | Virtual functions, `override`, class hierarchy |
| 6 | Exception Handling | Custom exceptions, operator overloading, file I/O |
| 7 | File I/O & Serialization | CSV parsing, `map`, JSON (`nlohmann/json`), CLI menu |
| 8 | Use Case Diagram | Actors, use cases, UML diagram (Draw.io) |

## 🚀 How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/ThanhNguyn/OOP.git
   cd OOP
   ```
2. Open the project in your IDE (VS Code recommended).
3. Run files by language:
   - **C++:**
     ```bash
     g++ -std=c++17 Week7/baitap.cpp -o baitap
     ./baitap
     ```
   - **Python:**
     ```bash
     python Week3/bai1.py
     ```

## 🎯 Bonus — OOP-Grader

Bài tập thực hành trên nền tảng [OOP-Grader VJU BCSE](https://sv12.bcse-vju.com/) — hệ thống chấm bài tự động (C++, Python, Java).

| Bài | File | Nội dung |
|-----|------|----------|
| 1.1 | `ex1-1.cpp` | Lớp `Point` — read, print, move, distance |
| 1.2 | `ex1-2.cpp` | `PointTest` — kiểm thử lớp Point |
| 2.1 | `ex2-1.cpp` | Lớp `LineSegment` — length, angle, move |
| 2.2 | `ex2-2.cpp` | `LineSegmentTest` — kiểm thử lớp LineSegment |
| 3.1 | `ex3-1.cpp` | Lớp `ColorPoint` — kế thừa Point, thêm màu sắc |
| 3.2 | `ex3-2.cpp` | `ColorPointTest` — kiểm thử lớp ColorPoint |
| 4.1 | `ex4-1.cpp` | Lớp `TuLanh` — quản lý thông tin tủ lạnh |
| 4.2 | `ex4-2.cpp` | `TuLanhTest` — kiểm thử lớp TuLanh |

## 👤 Author
- **Name:** Nguyen Tuan Thanh
- **Student ID:** 25112107
- **Email:** 25112107@vnu.edu.vn
- **GitHub:** [ThanhNguyn](https://github.com/ThanhNguyn)
