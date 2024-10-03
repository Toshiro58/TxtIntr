#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "shapes.h"

void print_usage() {
    std::cout << "Использование:\n";
    std::cout << "  -o circle <радиус>\n";
    std::cout << "  -o triangle <сторона1> <сторона2> <сторона3>\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        print_usage();
        return 1;
    }

    Shapes shapes;
    std::string operation = argv[1];
    
    if (operation == "-o") {
        std::string op = argv[2];

        if (op == "circle") {
            if (argc != 4) {
                std::cerr << "Ошибка: Для операции 'circle' требуется один операнд (радиус).\n";
                return 1;
            }
            double radius = std::atof(argv[3]);
            try {
                double area = shapes.area_circle(radius);
                std::cout << "Площадь круга с радиусом " << radius << ": " << area << "\n";
            } catch (const std::invalid_argument& e) {
                std::cerr << "Ошибка: " << e.what() << "\n";
                return 1;
            }

        } else if (op == "triangle") {
            if (argc != 6) {
                std::cerr << "Ошибка: Для операции 'triangle' требуется три операнда (стороны).\n";
                return 1;
            }
            double a = std::atof(argv[3]);
            double b = std::atof(argv[4]);
            double c = std::atof(argv[5]);
            try {
                double area = shapes.area_triangle(a, b, c);
                std::cout << "Площадь треугольника со сторонами " << a << ", " << b << ", " << c << ": " << area << "\n";
            } catch (const std::invalid_argument& e) {
                std::cerr << "Ошибка: " << e.what() << "\n";
                return 1;
            }

        } else {
            std::cerr << "Ошибка: Неизвестная операция. Используйте 'circle' или 'triangle'.\n";
            return 1;
        }
    } else {
        print_usage();
        return 1;
    }

    return 0;
}
