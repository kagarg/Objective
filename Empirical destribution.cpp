#include "Header.h"

double H_calc(double N, double min, double max) {
	return (max - min) / ((int)(1 + log(2)));
}

std::vector<double> Intervals_creation(double min, double max, double h ) {
	std::vector<double> vec;
	double buffer = min;
	vec.push_back(buffer);
	while (buffer < max) {
		buffer += h;
		vec.push_back(buffer);
	}
	return vec;
}

int Get_interval_index(const std::vector<double>& intervals, const double x) {// всегда возвращает левую границу интервала
	if (intervals.size() < 2) {												 // always returns the left side of the interval
		return 0;
	}
	if (x >= intervals[intervals.size() - 2] && x <= intervals[intervals.size() - 1]) {
		return intervals.size() - 2;
	}
	for (int i = 0; i < intervals.size() - 1; ++i) {
		if (x >= intervals[i] && x < intervals[i + 1]) {
			return i;
		}
	}
}
double Empiric_Expected_value_calc(std::vector<double> vec) {
	double summ = 0;
	for (int i = 0; i < vec.max_size(); i++) {
		summ += vec[i];
	}
	return summ / vec.size();

}

double Empiric_Dispersion_calc(std::vector<double> vec) {
	double summ = 0;
	double M = Empiric_Expected_value_calc(vec);
	for (int i = 0; i < vec.max_size(); i++) {
		summ += pow((vec[i] - M),2);
	}
	return summ / vec.size();
}

double Empiric_Asymmetry_calc(std::vector<double> vec) {
	double summ = 0;
	double M = Empiric_Expected_value_calc(vec);
	double D = Empiric_Dispersion_calc(vec);
	for (int i = 0; i < vec.max_size(); i++) {
		summ += pow((vec[i] - M), 3);
	}
	return (summ / (vec.size()* pow(D, 3/2)));
}

double Empiric_Excess_calc(std::vector<double> vec) {
	double summ = 0;
	double M = Empiric_Expected_value_calc(vec);
	double D = Empiric_Dispersion_calc(vec);
	for (int i = 0; i < vec.max_size(); i++) {
		summ += pow((vec[i] - M), 4);
	}
	return ((summ / (vec.size() * pow(D, 2))) - 3);
}

double Empirical_Density_calc(std::vector<double> vec, double x) {
	double h = H_calc(vec.size(),vec[0],vec[vec.size()-1]);
	auto intervals = Intervals_creation(vec[0], vec[vec.size() - 1], h);
	int index = Get_interval_index(intervals, x);
	int left = 0;
	int right = vec.size() - 1;
	if (index == 0) { // еслм х лежит в первом интервале
		right = 0;
		while (vec[right] < intervals[1]) {
			++right;
		}
	} // в результате в right получаем правую границу первого интервала (тоетсь длину интервала - 1)
	else if (index == intervals.size() - 2) { // если х лежит в последнем интервале
		left = vec.size() - 1;
		while (vec[left] > intervals[intervals.size() - 2]) {
			--left;
		}
	}// в результате в left получаем левую границу последнего интервала (тоетсь длину интервала - 1)
	else {
		while (vec[left] < intervals[index]) { //в left значение левой границы интервала в котором х
			++left;
		}
		right = left;
		while (vec[right] < intervals[index + 1]) {//в right значение левой границы интервала следующего после того, в котором х
			++right;							  // и соответственно правой границы х интервала 
		}
	}
	return (right - left + 1) / (vec.size() * h); // делим длину интервала в котором лежит х на всю длину прямой
}

std::vector<std::pair<double, double>> Generate_empric_graph(std::vector<double> vec, const int n) {
	std::vector<std::pair<double, double>> result;
	for (int i = 0; i < n; ++i) {
		result.push_back(std::make_pair(vec[i], Empirical_Density_calc(vec, vec[i])));
	}
	return result;
}