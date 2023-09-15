#include "Header.h"


double Density_calc(double x, double v) {
	double density = (v / (2 * tgamma(1 / v)) * exp(pow(-abs(x), v)));
	return density;
}

double Modified_Density_calc(double x, double v, double u, double l) {
	double mod_density = (v / (2 * tgamma(1 / v)) * exp(pow(-abs((x - u) / l), v))) / l;
	return mod_density;
}
double Expected_value() { return 0; }

double Modified_Expected_value_calc(double u) {
	double mod_expected_value = Expected_value() + u;
	return mod_expected_value;
}

double Dispersion_calc(double v) {
	double dispersion = (tgamma(3 / v) / tgamma(1 / v));
	return dispersion;
}

double Modified_Dispersion_calc(double v, double l) {
	double mod_dispersion = (tgamma(3 / v) / tgamma(1 / v)) * pow(l, 2);
	return mod_dispersion;
}

double Asymmetry_calc() { return 0; }

double Excess_calc(double v) {
	double excess = ((tgamma(5 / v) * tgamma(1 / v) / pow(tgamma(3 / v), 2)) - 3);
	return excess;
}


std::vector<double> Modified_Func_calc(double x, double v, double u, double l) { //подсчет всех параметров для модифицированной функции
	std::vector<double> vec = { Modified_Dispersion_calc(v, l), Excess_calc(v), Modified_Density_calc(x,v,u,l), Modified_Expected_value_calc(v) };
	return vec;
}

std::vector<double> Mixed_Func_calc(double p, double x1, double v1, double u1, double l1, double x2, double v2, double u2, double l2) {
	std::vector<double>results1 = Modified_Func_calc(x1, v1, u1, l1);
	std::vector<double>results2 = Modified_Func_calc(x2, v2, u2, l2);
	double mixed_density = ((1 - p) * results1[2]) + (p * results2[2]);
	double mixed_expected_value = ((1 - p) * results1[3]) + (p * results2[3]);
	double mixed_dispersion = (1 - p) * (pow(results1[3], 2) + results1[0]) - pow(mixed_expected_value, 2) + (p * (pow(results2[3], 2) + results2[0]) - pow(mixed_expected_value, 2));
	double asymmetry = (1 / (pow(mixed_dispersion, 3 / 2))) * ((1 - p) * (pow(results1[3] - mixed_expected_value, 3) + 3 * (results1[3] - mixed_expected_value) * results1[0] + pow(results1[0], 3 / 2) * Asymmetry_calc()) + p * (pow(results2[3] - mixed_expected_value, 3) + 3 * (results2[3] - mixed_expected_value) * results2[0] + pow(results2[0], 3 / 2) * Asymmetry_calc()));
	double excess = (1 / pow(mixed_dispersion, 3)) * ((1 - p) * (pow(results1[3] - mixed_expected_value, 4) + 6 * pow(results1[3] - mixed_expected_value, 2) * results1[0] + 4 * (results1[3] - mixed_expected_value) * pow(results1[0], 3 / 2) * Asymmetry_calc() + pow(results1[0], 2) * Excess_calc(v1)) - 3 + p * ((pow(results2[3] - mixed_expected_value, 4) + 6 * pow(results2[3] - mixed_expected_value, 2) * results2[0] + 4 * (results2[3] - mixed_expected_value) * pow(results2[0], 3 / 2) * Asymmetry_calc() + pow(results2[0], 2) * Excess_calc(v2))) - 3);
	std::vector<double> vec = {mixed_dispersion, excess, mixed_density, mixed_expected_value, asymmetry};
	return vec;
}
