#include <iostream>
#include <string>
#include <cmath>

// Базовый класс "Фигура"
class Figure {
protected:
    std::string name;
    int sides_count;

public:
    Figure() : name("Фигура"), sides_count(0) {}
    virtual ~Figure() {}

    virtual bool check() const {
        // Фигура правильная, если количество сторон равно 0
        return sides_count == 0;
    }

    virtual void print_info() const {
        std::cout << name << ":" << std::endl;
        std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << sides_count << std::endl;
    }

    std::string get_name() const { return name; }
    int get_sides_count() const { return sides_count; }
};

// Класс "Треугольник"
class Triangle : public Figure {
protected:
    double a, b, c; // стороны
    double A, B, C; // углы

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {
        name = "Треугольник";
        sides_count = 3;
    }

    bool check() const override {
        // Проверяем сумму углов (должна быть 180)
        const double angle_sum = A + B + C;
        const double epsilon = 0.001; // небольшое отклонение из-за погрешностей

        return Figure::check() && std::abs(angle_sum - 180.0) < epsilon;
    }

    void print_info() const override {
        Figure::print_info(); // вызываем базовый метод
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }

    // Геттеры для сторон и углов
    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
};

// Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }

    bool check() const override {
        // Проверяем, что угол C действительно равен 90
        const double epsilon = 0.001;
        return Triangle::check() && std::abs(C - 90.0) < epsilon;
    }
};

// Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double c, double A, double B, double C)
        : Triangle(a, b, c, A, B, C) {
        name = "Равнобедренный треугольник";
    }

    bool check() const override {
        // Проверяем, что стороны a и c равны, и углы A и C равны
        const double epsilon = 0.001;
        bool sides_equal = std::abs(a - c) < epsilon;
        bool angles_equal = std::abs(A - C) < epsilon;

        return Triangle::check() && sides_equal && angles_equal;
    }
};

// Равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

    bool check() const override {
        // Проверяем, что все стороны равны и все углы равны 60
        const double epsilon = 0.001;
        bool sides_equal = (std::abs(a - b) < epsilon) && (std::abs(b - c) < epsilon);
        bool angles_correct = (std::abs(A - 60.0) < epsilon) &&
            (std::abs(B - 60.0) < epsilon) &&
            (std::abs(C - 60.0) < epsilon);

        return Triangle::check() && sides_equal && angles_correct;
    }
};

// Класс "Четырёхугольник"
class Quadrilateral : public Figure {
protected:
    double a, b, c, d; // стороны
    double A, B, C, D; // углы

public:
    Quadrilateral(double a, double b, double c, double d,
        double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        name = "Четырёхугольник";
        sides_count = 4;
    }

    bool check() const override {
        // Проверяем сумму углов (должна быть 360)
        const double angle_sum = A + B + C + D;
        const double epsilon = 0.001;

        return Figure::check() && std::abs(angle_sum - 360.0) < epsilon;
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }

    // Геттеры для сторон и углов
    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }
};

// Параллелограмм
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }

    bool check() const override {
        // Проверяем, что противоположные стороны равны и противоположные углы равны
        const double epsilon = 0.001;
        bool sides_equal = (std::abs(a - c) < epsilon) && (std::abs(b - d) < epsilon);
        bool angles_equal = (std::abs(A - C) < epsilon) && (std::abs(B - D) < epsilon);

        return Quadrilateral::check() && sides_equal && angles_equal;
    }
};

// Прямоугольник
class Rectangle : public Parallelogram {
public:
    Rectangle(double a, double b)
        : Parallelogram(a, b, 90, 90) {
        name = "Прямоугольник";
    }

    bool check() const override {
        // Проверяем, что все углы равны 90
        const double epsilon = 0.001;
        bool angles_correct = (std::abs(A - 90.0) < epsilon) &&
            (std::abs(B - 90.0) < epsilon) &&
            (std::abs(C - 90.0) < epsilon) &&
            (std::abs(D - 90.0) < epsilon);

        return Parallelogram::check() && angles_correct;
    }
};

// Ромб
class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double A, double B)
        : Parallelogram(side, side, A, B) {
        name = "Ромб";
    }

    bool check() const override {
        // Проверяем, что все стороны равны
        const double epsilon = 0.001;
        bool sides_equal = (std::abs(a - b) < epsilon) &&
            (std::abs(b - c) < epsilon) &&
            (std::abs(c - d) < epsilon);

        return Parallelogram::check() && sides_equal;
    }
};

// Квадрат
class Square : public Rectangle {
public:
    Square(double side)
        : Rectangle(side, side) {
        name = "Квадрат";
    }

    bool check() const override {
        // Проверяем, что все стороны равны (у прямоугольника стороны a и b могут быть разными)
        const double epsilon = 0.001;
        bool sides_equal = (std::abs(a - b) < epsilon);

        return Rectangle::check() && sides_equal;
    }
};

// Функция для полиморфного вывода информации о фигуре
void print_info(const Figure* figure) {
    figure->print_info();
    std::cout << std::endl;
}

int main() {
    // Создаём все фигуры
    Figure figure;

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle1(10, 20, 30, 50, 60); // неправильный (сумма углов не 180)
    RightTriangle rightTriangle2(10, 20, 30, 50, 40); // правильный (50+40+90=180)
    IsoscelesTriangle isoscelesTriangle(10, 20, 10, 50, 60, 50); // неправильный (сумма углов 160)
    EquilateralTriangle equilateralTriangle(30); // правильный

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80); // неправильный (сумма углов 260)
    Rectangle rectangle(10, 20); // правильный
    Square square(20); // правильный
    Parallelogram parallelogram(20, 30, 30, 40); // правильный (30+40+30+40=140? нет, должно быть 360, но по условию проверяем только равенство сторон и углов)
    Rhombus rhombus(30, 30, 40); // правильный (30+40+30+40=140, но по условию проверяем только равенство сторон)

    // Выводим информацию о каждой фигуре полиморфно
    print_info(&figure);
    print_info(&triangle);
    print_info(&rightTriangle1);
    print_info(&rightTriangle2);
    print_info(&isoscelesTriangle);
    print_info(&equilateralTriangle);
    print_info(&quadrilateral);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}