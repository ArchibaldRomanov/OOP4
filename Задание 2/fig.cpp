#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;

public:
    Figure() : name("Ôčăóđŕ") {}

    std::string get_name() const {
        return name;
    }

    virtual void print_info() const = 0; 
};

class Triangle : public Figure {
protected:
    double a, b, c; // ńňîđîíű
    double A, B, C; // óăëű

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {
        name = "Ňđĺóăîëüíčę";
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }

    void print_info() const override {
        std::cout << name << ":" << std::endl;
        std::cout << "Ńňîđîíű: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Óăëű: A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Ďđ˙ěîóăîëüíűé ňđĺóăîëüíčę";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double c, double A, double B, double C)
        : Triangle(a, b, c, A, B, C) {
        name = "Đŕâíîáĺäđĺííűé ňđĺóăîëüíčę";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Đŕâíîńňîđîííčé ňđĺóăîëüíčę";
    }
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d; // ńňîđîíű
    double A, B, C, D; // óăëű

public:
    Quadrilateral(double a, double b, double c, double d,
        double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        name = "×ĺňűđ¸őóăîëüíčę";
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }

    void print_info() const override {
        std::cout << name << ":" << std::endl;
        std::cout << "Ńňîđîíű: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Óăëű: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Ďŕđŕëëĺëîăđŕěě";
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double a, double b)
        : Parallelogram(a, b, 90, 90) {
        name = "Ďđ˙ěîóăîëüíčę";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double A, double B)
        : Parallelogram(side, side, A, B) {
        name = "Đîěá";
    }
};

class Square : public Rectangle {
public:
    Square(double side)
        : Rectangle(side, side) {
        name = "Ęâŕäđŕň";
    }
};

int main() {

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isoscelesTriangle(10, 20, 10, 50, 60, 50);
    EquilateralTriangle equilateralTriangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&triangle);
    print_info(&rightTriangle);
    print_info(&isoscelesTriangle);
    print_info(&equilateralTriangle);

    print_info(&quadrilateral);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);
    
    return 0;
}
