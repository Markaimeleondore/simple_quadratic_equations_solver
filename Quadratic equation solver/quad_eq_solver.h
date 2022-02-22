#pragma once
#include <iostream>

std::tuple<double, double, double> get_coeffs();
double get_discriminant(std::tuple<double, double, double> coeffs);
std::pair<double, double> get_roots_positive_discriminant_case(double discriminant, std::pair<double, double> a_and_b_coeffs);
std::pair<double, double> get_roots_negative_discriminant_case(double discriminant, std::pair<double, double> a_and_b_coeffs);
double get_roots_zero_discriminant_case(std::pair<double, double> a_and_b_coeffs);
void solve();