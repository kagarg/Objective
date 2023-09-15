#include "Header.h"


int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Введите v, (v > 0) >";
	double v;
	std::cin >> v;
	if (v <= 0) { std::cout << "Ошибка ввода"; exit(-1); }
	std::cout << "Дисперсия равна " << Dispersion_calc(v) << std::endl << "Коэф. эксцесса равен " << Excess_calc(v) << std::endl
			  << "Плотность распределения равна " << Density_calc(0,v) << std::endl;
}