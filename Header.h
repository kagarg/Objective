#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>


double Density_calc(double x, double v);
double Modified_Density_calc(double x, double v, double u, double l);
double Expected_value();
double Modified_Expected_value_calc(double u);
double Dispersion_calc(double v);
double Modified_Dispersion_calc(double v, double l);
double Asymmetry_calc();
double Excess_calc(double v);
std::vector<double> Modified_Func_calc(double x, double v, double u, double l);
std::vector<double> Mixed_Func_calc(double p, double x1, double v1, double u1, double l1, double x2, double v2, double u2, double l2);
double Randomizer();
double Random_item12(double v);
double Random_item2(double v);
double Random_item(double v);
double Mixed_Random_value(double p, double v1, double v2);
double H_calc(double N, double min, double max);
std::vector<double> Intervals_creation(double min, double max, double h);
int Get_interval_index(const std::vector<double>& intervals, const double x);
double Empiric_Expected_value_calc(std::vector<double> vec);
double Empiric_Dispersion_calc(std::vector<double> vec);
double Empiric_Asymmetry_calc(std::vector<double> vec);
double Empiric_Excess_calc(std::vector<double> vec);
double Empirical_Density_calc(std::vector<double> vec, double x);
std::vector<std::pair<double, double>> Generate_empric_graph(std::vector<double> vec, const int n);
