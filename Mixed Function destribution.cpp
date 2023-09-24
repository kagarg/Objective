#include "Header.h"


std::vector<double> Mixed_Func_calc(double p, double x, double v1, double u1, double l1, double v2, double u2, double l2) {
	std::vector<double>results1 = Modified_Func_calc(x, v1, u1, l1);
	std::vector<double>results2 = Modified_Func_calc(x, v2, u2, l2);
	double mixed_density = ((1 - p) * results1[2]) + (p * results2[2]);
	double mixed_expected_value = ((1 - p) * results1[3]) + (p * results2[3]); /*((1 - p) * Modified_Density_calc(x, v1, u1, l1) + p * Modified_Density_calc(x, v2, u2, l2));*/
	double mixed_dispersion = (1 - p) * (pow(results1[3], 2) + results1[0]) - pow(mixed_expected_value, 2) + (p * (pow(results2[3], 2) + results2[0]) - pow(mixed_expected_value, 2));
	double asymmetry = (1 / (pow(mixed_dispersion, 3 / 2))) * ((1 - p) * (pow(results1[3] - mixed_expected_value, 3) + 3 * (results1[3] - mixed_expected_value) * results1[0] + pow(results1[0], 3 / 2) * Asymmetry_calc()) + p * (pow(results2[3] - mixed_expected_value, 3) + 3 * (results2[3] - mixed_expected_value) * results2[0] + pow(results2[0], 3 / 2) * Asymmetry_calc()));
	double excess = (1 / pow(mixed_dispersion, 3)) * ((1 - p) * (pow(results1[3] - mixed_expected_value, 4) + 6 * pow(results1[3] - mixed_expected_value, 2) * results1[0] + 4 * (results1[3] - mixed_expected_value) * pow(results1[0], 3 / 2) * Asymmetry_calc() + pow(results1[0], 2) * Excess_calc(v1)) - 3 + p * ((pow(results2[3] - mixed_expected_value, 4) + 6 * pow(results2[3] - mixed_expected_value, 2) * results2[0] + 4 * (results2[3] - mixed_expected_value) * pow(results2[0], 3 / 2) * Asymmetry_calc() + pow(results2[0], 2) * Excess_calc(v2))) - 3);
	std::vector<double> vec = { mixed_dispersion, excess, mixed_density, mixed_expected_value, asymmetry };
	return vec;
}

//std::vector<double> Mixed_Func_calc(double p, double x, double v1, double u1, double l1, double v2, double u2, double l2) {
//	std::vector<double>results1 = Modified_Func_calc(x, v1, u1, l1);
//	std::vector<double>results2 = Modified_Func_calc(x, v2, u2, l2);
//	double mixed_expected_value = ((1 - p) * Modified_Expected_value_calc(u1)) + (p * Modified_Expected_value_calc(u2));
//	double mixed_density =((1 - p) * Modified_Density_calc(x, v1, u1, l1) + p * Modified_Density_calc(x, v2, u2, l2));
//	double mixed_dispersion = (1 - p) * (pow(Modified_Expected_value_calc(u1), 2) + Modified_Dispersion_calc(v1,l1)) - pow(mixed_expected_value, 2) + (p * (pow(Modified_Expected_value_calc(u2), 2) + Modified_Dispersion_calc(v2, l2)) - pow(mixed_expected_value, 2));
//	double asymmetry = (1 / (pow(mixed_dispersion, 3 / 2))) * ((1 - p) * (pow(Modified_Expected_value_calc(u1) - mixed_expected_value, 3) + 3 * (Modified_Expected_value_calc(u1) - mixed_expected_value) * Modified_Dispersion_calc(v1, l1) + pow(Modified_Dispersion_calc(v1, l1), 3 / 2) * Asymmetry_calc()) + p * (pow(Modified_Expected_value_calc(u2) - mixed_expected_value, 3) + 3 * (Modified_Expected_value_calc(u2) - mixed_expected_value) * Modified_Dispersion_calc(v2,l2) + pow(Modified_Dispersion_calc(v2, l2), 3 / 2) * Asymmetry_calc()));
//	double excess = (1 / pow(mixed_dispersion, 3)) * ((1 - p) * (pow(results1[3] - mixed_expected_value, 4) + 6 * pow(results1[3] - mixed_expected_value, 2) * results1[0] + 4 * (results1[3] - mixed_expected_value) * pow(results1[0], 3 / 2) * Asymmetry_calc() + pow(results1[0], 2) * Excess_calc(v1)) - 3 + p * ((pow(results2[3] - mixed_expected_value, 4) + 6 * pow(results2[3] - mixed_expected_value, 2) * results2[0] + 4 * (results2[3] - mixed_expected_value) * pow(results2[0], 3 / 2) * Asymmetry_calc() + pow(results2[0], 2) * Excess_calc(v2))) - 3);
//	std::vector<double> vec = { mixed_dispersion, excess, mixed_density, mixed_expected_value, asymmetry };
//	return vec;
//}

double Mixed_Random_value(double p, double v1, double v2) {
	double r = Randomizer();
	if (r > p) {
		return Random_item(v1);
	}
	else { return Random_item(v2); }
}

std::vector<double>Create_mixed_set(double v1, double v2, double n,double p ) {
	std::vector<double>vec;
	for (int i = 0; i < n; i++) {
		vec.push_back(Mixed_Random_value(p,v1,v2));
	}
	sort(vec.begin(), vec.end());
	return vec;
}
std::vector<std::pair<double, double>> Generate_mixed_graph(std::vector<double> vec, double p, double v1, double u1, double l1, double v2, double u2, double l2, const int n) {
	std::vector<std::pair<double, double>> result;
	for (int i = 0; i < n; ++i) {
		auto mixed_density = Mixed_Func_calc(p, vec[i], v1, u1, l1, v2, u2, l2)[2];
		result.push_back(std::make_pair(vec[i],mixed_density));
	}
	return result;
}