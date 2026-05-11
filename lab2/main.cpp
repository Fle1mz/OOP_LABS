#include <iostream>
#include <vector>
#include <windows.h> 
#include "triangle.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Point a, b, c;

    std::cout << "Введіть координати вершин трикутника:\n";
    std::cout << "Вершина A (x y): ";
    std::cin >> a.x >> a.y;
    std::cout << "Вершина B (x y): ";
    std::cin >> b.x >> b.y;
    std::cout << "Вершина C (x y): ";
    std::cin >> c.x >> c.y;

    if (isDegenerate(a, b, c)) {
        std::cout << "Помилка: Трикутник вироджений (вершини лежать на одній прямій або збігаються).\n";
        return 1;
    }

    int n;
    std::cout << "\nСкільки точок ви хочете перевірити? ";
    std::cin >> n;

    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Введіть координати точки " << i + 1 << " (x y): ";
        std::cin >> points[i].x >> points[i].y;
    }

    std::cout << "\n--- Результати ---\n";
    for (int i = 0; i < n; ++i) {
        PointLocation loc = checkPointLocation(points[i], a, b, c);
        std::cout << "Точка " << i + 1 << " (" << points[i].x << ", " << points[i].y << "): ";
        
        switch (loc) {
            case INSIDE:
                std::cout << "знаходиться всередині трикутника.\n";
                break;
            case OUTSIDE:
                std::cout << "знаходиться зовні трикутника.\n";
                break;
            case ON_BOUNDARY:
                std::cout << "лежить на межі трикутника.\n";
                break;
            case DEGENERATE_TRIANGLE:
                std::cout << "помилка трикутника.\n";
                break;
        }
    }

    return 0;
}