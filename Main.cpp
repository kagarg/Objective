#include "Header.h"
#include <fstream>

int main() {
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(0));
	double v, l1, l2, u1, u2, p, v2;
	std::cout << "Введите: " << std::endl << "1, для стандартного распределения" << std::endl << "2, для смеси распределений" << std::endl << "> ";
	int flag;
	std::cin >> flag;
	switch (flag) {
		case 1:
		{
			std::cout << "Введите: v (v > 0), l, u> ";
			std::cin >> v >> l1>> u1;
			while (std::cin.fail()) {							// проверка вводимых данных
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Ошибка ввода. Введите значения повторно > ";
				std::cin >> v >> l1>> u1;
			}
			while (v <= 0) {
				std::cout << "Ошибка ввода v. Введите значение повтороно > ";
				std::cin >> v;
			}
			auto vec = Create_std_set(1000, v,u1,l1);
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
			// standart function print
			std::cout << "Для стандартного распределения ";
			std::cout << "Дисперсия равна: " << Modified_Dispersion_calc(v,l1) << std::endl << "Эксцесс:  " << Excess_calc(v) << std::endl
					  << "Плотность распределения в точке " << u1 << " равна: " << Modified_Density_calc(u1, v, u1, l1) << std::endl << "Мат. Ожидание:  "
					  <<Modified_Expected_value_calc(u1) << std::endl << "Асимметрия:  " <<Asymmetry_calc() << std::endl;
			
			std::cout << "Для эмпирического распределения "<<std::endl;
			std::cout << "Мат. Ожидание:  " << Empiric_Expected_value_calc(vec) << std::endl << "Дисперсия: " 
					  << Empiric_Dispersion_calc(vec) << std::endl << "Эксцесс:  " << Empiric_Excess_calc(vec) << std::endl
					  << "Плотность распределения в точке "<< u1<<" равна: " << Empiric_Density_calc(vec, u1) << std::endl  << "Асимметрия : " 
					<< Empiric_Asymmetry_calc(vec) << std::endl;
			break;
		}
		case 2: 
		{
			std::cout << "Введите v (v > 0), p (0 < p < 1), v2 (v2 > 0), l1, l2, u1, u2 > ";
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
			while ((p >= 1) || (p <= 0)) {
				std::cout << "Ошибка в p. Введите значение повтороно > ";
				std::cin >> p;
			}

			auto mixed_vec = Create_mixed_set(v, v2, 1000, p, u1, l1, u2, l2);
			auto func3 = Generate_mixed_graph(mixed_vec, p, v, u1, l1, v2, u2, l2, 1000);
			std::ofstream file3("mixed_distr.txt");
			for (int i = 0; i < func3.size(); ++i) {
				file3 << func3[i].first << "\t" << func3[i].second << std::endl;
			}


			auto func4 = Generate_empric_graph(mixed_vec, 1000);
			std::ofstream file4("empiric_mixed_distr.txt");
			for (int i = 0; i < func4.size(); ++i) {
				file4 << func4[i].first << "\t" << func4[i].second << std::endl;
			}
			std::cout << "Для смеси распределений ";
			std::vector<double>vec1 = Mixed_Func_calc(p, 0, v, u1, l1, v2, u2, l2);
			std::cout << std::endl << "Параметры смеси распределений : " << std::endl;
			std::cout << "Дисперсия: " << vec1[0] << std::endl << "Эксцесс: " << vec1[1] << std::endl << "Плотность в точке 0: " << vec1[2] << std::endl << "Мат. ожидание " << vec1[3] << std::endl << "Асимметрия: " << vec1[4] << std::endl;
			
			std::cout << "Для эмпирического распределения ";
			std::cout << "Дисперсия равна " << Empiric_Dispersion_calc(mixed_vec) << std::endl << "Эксцесс:  " << Empiric_Excess_calc(mixed_vec) << std::endl
				<< "Плотность распределения в точке 0 равна: " << Empiric_Density_calc(mixed_vec, 0) << std::endl << "Мат. Ожидание:  "
				<< Empiric_Expected_value_calc(mixed_vec) << std::endl << "Асимметрия:  " << Empiric_Asymmetry_calc(mixed_vec) << std::endl;
			break;
		}
		default: 
			std::cout << "bad input" << std::endl;
			break;
	}

	return 0;
}