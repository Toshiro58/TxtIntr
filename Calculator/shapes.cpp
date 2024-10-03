#include "shapes.h"

double Shapes::area_circle(double radius) {
    if (radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным.");
    }
    return M_PI * radius * radius;
}

double Shapes::area_triangle(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::invalid_argument("Стороны треугольника должны быть положительными.");
    }
    double s = (a + b + c) / 2;
    if (s <= a || s <= b || s <= c) {
        throw std::invalid_argument("Невозможно построить треугольник с такими сторонами.");
    }
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
