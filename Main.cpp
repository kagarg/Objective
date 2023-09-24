#include "Header.h"
#include <fstream>

int main() {
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(0));
	std::cout << "Введите v (v > 0), p (0 < p < 1), v2 (v2 > 0), l1, l2, u1, u2 > ";
	double v, l1, l2, u1, u2, p, v2;
	std::cin >> v >> p >> v2 >> l1 >> l2 >> u1 >> u2;

	while (std::cin.fail()) {							// проверка вводимых данных
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Ошибка ввода. Введите значения повторно > ";
		std::cin >> p >> v2 >> l1 >> l2 >> u1 >> u2;
	}
	while (v <= 0) {
		std::cout << "Ошибка ввода v. Введите значение повтороно > ";
		std::cin >> v;
	}
	while (v2 <= 0) {
		std::cout << "Ошибка в v2. Введите значение больше нуля > ";
		std::cin >> v2;
	}
	while ((p >= 1)||(p <=0)) {
		std::cout << "Ошибка в p. Введите значение повтороно > ";
		std::cin >> p;
	}													//


	auto vec = Create_std_set(1000, v);
	auto func = Create_std_graph(vec, v, u1, l1, 1000);
	std::ofstream file1("standart_distr.txt");
	for (int i = 0; i < func.size(); ++i) {
		file1 << func[i].first << "\t" << func[i].second << std::endl;
	}
		

	auto func2 = Generate_empric_graph(vec, 1000);
	std::ofstream file2("empiric_distr.txt");
	for (int i = 0; i < func2.size(); ++i) {
		file2 << func2[i].first << "\t" << func2[i].second << std::endl;
	}

	auto mixed_vec = Create_mixed_set(v,v2, 1000, p);
	auto func3 = Generate_mixed_graph(mixed_vec,p,v,u1,l1,v2,u2,l2 , 1000);
	std::ofstream file3("mixed_distr.txt");
	for (int i = 0; i < func3.size(); ++i) {
		file3 << func3[i].first << "\t" << func3[i].second << std::endl;
	}
	

	auto func4 = Generate_empric_graph(mixed_vec, 1000);
	std::ofstream file4("empiric_mixed_distr.txt");
	for (int i = 0; i < func4.size(); ++i) {
		file4 << func4[i].first << "\t" << func4[i].second << std::endl;
	}

	//// standart function print
	/*std::cout << "Дисперсия равна " << Dispersion_calc(v) << std::endl << "Коэф. эксцесса равен " << Excess_calc(v) << std::endl
			  << "Плотность распределения равна " << Density_calc(0,v) << std::endl;*/

	//// random value modeling print for standart func
	//std::cout << std::endl << "Случайная величина для стандартного распределения > " << Random_item(v)<<std::endl;
	//
	//mixed function print
	std::vector<double>vec1 = Mixed_Func_calc(p, 0, v, u1, l1, v2, u2, l2);
	std::cout << std::endl << "Параметры смеси распределений : " << std::endl;
	std::cout << "dispersion " << vec1[0] << std::endl << "excess "<<vec1[1]<< std::endl<< "density " << vec1[2] << std::endl << "expected value " << vec1[3] << std::endl << "asymmetry " << vec1[4] << std::endl;
	//
	//// random value modeling print for function mix
	//std::cout << std::endl << "Случайная величина для смеси распределений > "<< Mixed_Random_value(p, v, v2);


	
}