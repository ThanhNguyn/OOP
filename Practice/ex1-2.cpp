class PointTest {
public:
    void testCase() {
        Point def;
        def.print();

        Point B;
        B.read();
        B.print();

        Point C(B.getX(), B.getY());
        C.move(1, 1);
        C.print();

        double d = C.distance();
        if (d == (int)d)
            cout << fixed << setprecision(1) << d << "\n";
        else
            cout << d << "\n";
    }
};