#include "Header.h"


int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "������� v, (v > 0) >";
	double v;
	std::cin >> v;
	if (v <= 0) { std::cout << "������ �����"; exit(-1); }
	std::cout << "��������� ����� " << Dispersion_calc(v) << std::endl << "����. �������� ����� " << Excess_calc(v) << std::endl
			  << "��������� ������������� ����� " << Density_calc(0,v) << std::endl;
}