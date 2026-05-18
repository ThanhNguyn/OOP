class Point {
    private:
        int x,y;
    public:
        Point() : x(0), y(1) {}
        Point(int x, int y) : x(x), y(y) {}
        void read() {
            cin >> x >> y;
        }
        void print() const {
            cout << "(" << x << ", " << y << ")\n";
        }
        void move(int dx, int dy) {
            x += dx;
            y += dy;
        }
        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }
        double distance() const {
            return sqrt(x * x + y * y);
        }

        double distance(Point P) const {
            double dx = x - P.getX();
            double dy = y - P.getY();
            return std::sqrt(dx * dx + dy * dy);
        }
};