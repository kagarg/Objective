#include "Header.h"


double Density_calc(double x, double v) {
	double density = (v / (2 * tgamma(1 / v)) * exp(-pow(abs(x), v)));
	return density;
}
double Standart(double x, double l, double u) {
	double xmod = ((x - u) / l);
	return xmod;
}

double Modified_Density_calc(double x, double v, double u, double l) {
	double xmod = Standart(x, l, u);
	double mod_density = (v / (2 * tgamma(1 / v)) * exp(-pow(abs(xmod), v))) / l;
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
double Randomizer() {
	double r;
	do r = (double)rand() / RAND_MAX; while (r == 0 || r == 1);
	return r;
}
// part of an algorithm for v in range [1;2)
double Random_item12(double v) {
	double r = Randomizer();
	double a = (1 / v) - 1;
	double b = 1 / (pow(v, 1/v));
	double x = 0;
	if (r <= 0.5) {
		x = b * log(2 * r);
	}
	else if (r > 0.5) {
		x = -b * log(2 * (1 - r));
	}
	double r2 = Randomizer();
	if (log(r2) <= (exp(v * (-log(abs(x)))) + (abs(x) / b) + a)) { return x; }
	else {return  Random_item12(v); }
}
// part of an algorithm for v in range [2; inf)
double Random_item2(double v) {
	double a = (1 / v) - 0.5;
	double b = 1 / (pow(v, 1 / v));
	double c = 2* pow(b,2);
	double r = Randomizer();
	double r2 = Randomizer();
	double x = b * sqrt(-2 * log(r))* cos(2*M_PI*r2);
	double r3 = Randomizer();
	if (log(r3) <=( exp(v * ( - log(abs(x)))) + (pow(x, 2) / c) + a)) { return x; }
	else {return Random_item2(v); }
}
// function for the whole algorithm use
double Random_item(double v, double u, double l) {
	double result;
	if ((1 <= v)&&(v<2)) {result= Random_item12(v); }
	else if (v >= 2) {result= Random_item2(v); }
	return ((result *l +u));
}

std::vector<double> Create_std_set(const int n, double v, double u, double l) {
	std::vector<double> result;
	for (int i = 0; i < n; i++) {
		result.push_back(Random_item(v, u, l));
	}
	sort(result.begin(), result.end());
	return result;
}

std::vector<std::pair<double, double>> Create_std_graph(std::vector<double> vec, double v, double u, double l,const int n) {
	std::vector<std::pair<double, double>> result;
	for (int i = 0; i < n; ++i) {
		result.push_back(std::make_pair(vec[i], Modified_Density_calc(vec[i], v, u, l)));
	}
	return result;
}