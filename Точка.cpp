#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    friend std::istream& operator>>(std::istream& is, Point& point) {
        is >> point.x >> point.y;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    void quadrant() const {
        if (x > 0 && y > 0) {
            std::cout << "Квадрант I" << std::endl;
        }
        else if (x < 0 && y > 0) {
            std::cout << "Квадрант II" << std::endl;
        }
        else if (x < 0 && y < 0) {
            std::cout << "Квадрант III" << std::endl;
        }
        else if (x > 0 && y < 0) {
            std::cout << "Квадрант IV" << std::endl;
        }
        else {
            std::cout << "На оси" << std::endl;
        }
    }

    void positionRelativeToLine(double a, double b) const {
        double line_y = a * x + b;
        if (y > line_y) {
            std::cout << "Над линией y = " << line_y << std::endl;
        }
        else if (y < line_y) {
            std::cout << "Ниже линии y = " << line_y << std::endl;
        }
        else {
            std::cout << "На линии y = " << line_y << std::endl;
        }
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    Point p1, p2;

    std::cout << "Введите первую точку (x y): ";
    std::cin >> p1;

    std::cout << "Введите вторую точку (x y): ";
    std::cin >> p2;

    if (p1 == p2) {
        std::cout << "Точки равны." << std::endl;
    }
    else {
        std::cout << "Точки не равны." << std::endl;
    }

    p1.quadrant();
    p2.quadrant();

    double a, b;
    std::cout << "Введите коэффициенты прямой (a, b) в уравнение y = ax + b: ";
    std::cin >> a >> b;

    p1.positionRelativeToLine(a, b);
    p2.positionRelativeToLine(a, b);

    return 0;
}
