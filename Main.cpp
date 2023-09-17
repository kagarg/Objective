#include "Header.h"


int main() {
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(0));
	std::cout << "Введите v, (v > 0) >";
	double v;
	std::cin >> v;
	if (v <= 0) { std::cout << "Ошибка ввода"; exit(-1); }
	// standart function print
	std::cout << "Дисперсия равна " << Dispersion_calc(v) << std::endl << "Коэф. эксцесса равен " << Excess_calc(v) << std::endl
			  << "Плотность распределения равна " << Density_calc(0,v) << std::endl;

	// random value modeling print for standart func
	std::cout << std::endl << "Случайная величина для стандартного распределения > " << Random_item(v)<<std::endl;
	
	//mixed function print
	std::cout << "Введите параметр смеси р > ";
	double p;
	std::cin >> p;
	std::cout << "Введите параметр v для второго распределения (для смеси) > ";
	double v2;
	std::cin >> v2;
	
	std::vector<double>vec = Mixed_Func_calc(p, 0,v,3,2, 0,v2,3,2);
	std::cout << std::endl << "Параметры смеси распределений : " << std::endl;
	std::cout << "dispersion " << vec[0] << std::endl << "excess "<<vec[1]<< std::endl<< "density " << vec[2] << std::endl << "expected value " << vec[3] << std::endl << "asymmetry " << vec[4] << std::endl;
	
	// random value modeling print for function mix
	std::cout << std::endl << "Случайная величина для смеси распределений > "<< Mixed_Random_value(p, v, v2);


	
}