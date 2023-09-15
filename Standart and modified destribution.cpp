#include "Header.h"


double Density_calc(double x, double v) {
	/*double density = (v / (2 * tgamma(1 / v)) * exp(pow(-abs(x), v)));*/
	double density = (v / (2 * tgamma(1 / v)) * exp(exp(v * log(-abs(x)))));
	return density;
}

double Modified_Density_calc(double x, double v, double u, double l) {
	//double mod_density = (v / (2 * tgamma(1 / v)) * exp(pow(-abs((x - u) / l), v))) / l;
	double mod_density = (v / (2 * tgamma(1 / v)) * exp(exp(v*log(-abs(x))))) / l;
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

double Excess_calc(double v) {
	double excess = ((tgamma(5 / v) * tgamma(1 / v) / pow(tgamma(3 / v), 2)) - 3);
	return excess;
}

double Asymmetry_calc() { return 0; }

std::vector<double> Modified_Func_calc(double x, double v, double u, double l) { //подсчет всех параметров для модифицированной функции
	std::vector<double> vec = { Modified_Dispersion_calc(v, l), Excess_calc(v), Modified_Density_calc(x,v,u,l), Modified_Expected_value_calc(v) };
	return vec;
}


