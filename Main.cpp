#include <iostream>
#include <math.h>
#include "Header.h"
#include <vector>

double Dispersion_calc(double v) {
	double dispersion = (tgamma(3 / v) / tgamma(1 / v));
	return dispersion;
}

double Excess_calc(double v) {
	double excess = ((tgamma(5 / v) * tgamma(1 / v) / pow(tgamma(3 / v), 2)) - 3);
	return excess;
}

double Density_calc(double x, double v) {
	double density = (v / (2 * tgamma(1 / v)) * exp(pow(-abs(x), v)));
	return density;
}

double Modified_Density_calc(double x, double v, double u, double l) {
	double mod_density = (v / (2 * tgamma(1 / v)) * exp(pow(-abs((x-u)/l), v)))/l;
	return mod_density;
}

std::vector<double> Modified_Func_calc(double x, double v, double u, double l) {
	std::vector<double> vec = {0,0,0};
	double mod_density = (v / (2 * tgamma(1 / v)) * exp(pow(-abs((x - u) / l), v))) / l;
	double excess = ((tgamma(5 / v) * tgamma(1 / v) / pow(tgamma(3 / v), 2)) - 3);
	double dispersion = (tgamma(3 / v) / tgamma(1 / v));
	double expected_value = u;
	vec = { dispersion, excess, mod_density, expected_value };
	return vec;
}
std::vector<double> Mixed_Func_calc(double p, double x1, double v1, double u1, double l1, double x2, double v2, double u2, double l2) {
	std::vector<double>results1 = Modified_Func_calc(x1, v1, u1, l1);
	std::vector<double>results2 = Modified_Func_calc(x2, v2, u2, l2);
	double mixed_density = ((1 - p) * results1[2]) + (p * results2[2]);
	double mixed_expected_value = ((1 - p) * results1[3]) + (p * results2[3]);
	/*double mixed_dispersion = (1 - p)*(pow(results1[3], 2) + results1[0]);*/

}

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Введите v, (v > 0) >";
	double v;
	std::cin >> v;
	if (v <= 0) { std::cout << "Ошибка ввода"; exit(-1); }
	std::cout << "Дисперсия равна " << Dispersion_calc(v) << std::endl << "Коэф. эксцесса равен " << Excess_calc(v) << std::endl
			  << "Плотность распределения равна " << Density_calc(0,v) << std::endl;
}