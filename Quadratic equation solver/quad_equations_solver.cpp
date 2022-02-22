#include "quad_eq_solver.h"
#include <iostream>
#include <locale.h>
// ax^2 + bx + c
// complex alpha = Re(x), betha = Im(x)

std::tuple<double, double, double> get_coeffs()
{
    double a, b, c;
    std::cin >> a >> b >> c;
    return std::make_tuple(a, b, c);
}

double get_discriminant(std::tuple<double, double, double> coeffs)
{
    auto [a, b, c] = coeffs;
    return pow(b, 2) - 4 * a * c;
}

std::pair<double, double> get_roots_positive_discriminant_case(double discriminant, std::pair<double, double> a_and_b_coeffs)
{
    auto [a, b] = a_and_b_coeffs;
    return std::make_pair((-b - sqrt(discriminant)) / (2.0 * a), (-b + sqrt(discriminant)) / (2.0 * a));
}

std::pair<double, double> get_roots_negative_discriminant_case(double discriminant, std::pair<double, double> a_and_b_coeffs)
{
    auto [a, b] = a_and_b_coeffs;
    double alpha = -b / (2.0 * a);
    double betha = sqrt(-discriminant) / (2.0 * a);
    return std::make_pair(alpha, betha);
}

double get_roots_zero_discriminant_case(std::pair<double, double> a_and_b_coeffs)
{
    auto [a, b] = a_and_b_coeffs;
    return -b / (2.0 * a);
}

void solve()
{
    std::cout << "Введите коэффициенты:" << "\n";
    std::tuple<double, double, double> coeffs = get_coeffs();
    double discriminant = get_discriminant(coeffs);
    std::cout << "Дискриминант равен " << discriminant << "\n=> ";
    std::pair<double, double> roots;
    if (discriminant > 0)
    {
        roots = get_roots_positive_discriminant_case(discriminant, std::make_pair(std::get<0>(coeffs), std::get<1>(coeffs)));
        std::cout << "У уравнения вещественные корни: x1 = " << roots.first << " x2 = " << roots.second << "\n";
    }
    else if(discriminant < 0)
    {
        roots = get_roots_negative_discriminant_case(discriminant, std::make_pair(std::get<0>(coeffs), std::get<1>(coeffs)));
        std::cout << "У уравнения комплексные корни: x1 = " << roots.first <<" + " << roots.second << "i " << " x2 = " << roots.first << " - " << roots.second << "i " << "\n";
    }
    else
    {
        roots.first = roots.second = get_roots_zero_discriminant_case(std::make_pair(std::get<0>(coeffs), std::get<1>(coeffs)));
        std::cout << "У уравнения кратные вещественные корни: x1 = " << roots.first << " x2 = " << roots.second << "\n";
    }
}






int main()
{
    setlocale(LC_ALL, "Russian");
    solve();
    return 0;
}

