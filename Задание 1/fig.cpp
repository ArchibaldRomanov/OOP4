#include <iostream>
#include <string>

// Базовый класс "Фигура"
class Figure {
private:
    int sides_count;
    std::string name;

protected:
    // Защищённый конструктор для наследников
    Figure(int sides, const std::string& figureName) : sides_count(sides), name(figureName) {}

public:
    // Конструктор по умолчанию для неизвестной фигуры
    Figure() : sides_count(0), name("Фигура") {}

    // Метод для получения количества сторон
    int get_sides_count() const {
        return sides_count;
    }

    // Метод для получения названия фигуры
    std::string get_name() const {
        return name;
    }
};

// Класс "Треугольник" - наследник Figure
class Triangle : public Figure {
public:
    Triangle() : Figure(3, "Треугольник") {}
};

// Класс "Четырёхугольник" - наследник Figure
class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

int main() {
    // Создаем экземпляры классов
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    // Выводим информацию о количестве сторон
    std::cout << "Количество сторон:" << std::endl;
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

    return 0;
}