#include "Header.h"


int main() {
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(0));

	std::cout << "������� v (v > 0), p (0 < p < 1), v2 (v2 > 0), l1, l2, u1, u2 > ";
	double v, l1, l2, u1, u2, p, v2;
	std::cin >> v >> p >> v2 >> l1 >> l2 >> u1 >> u2;

	while (std::cin.fail()) {							// �������� �������� ������
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "������ �����. ������� �������� �������� > ";
		std::cin >> p >> v2 >> l1 >> l2 >> u1 >> u2;
	}
	while (v <= 0) {
		std::cout << "������ ����� v. ������� �������� ��������� > ";
		std::cin >> v;
	}
	while (v2 <= 0) {
		std::cout << "������ � v2. ������� �������� ������ ���� > ";
		std::cin >> v2;
	}
	while ((p >= 1)||(p <=0)) {
		std::cout << "������ � p. ������� �������� ��������� > ";
		std::cin >> p;
	}													//
	
	// standart function print
	std::cout << "��������� ����� " << Dispersion_calc(v) << std::endl << "����. �������� ����� " << Excess_calc(v) << std::endl
			  << "��������� ������������� ����� " << Density_calc(0,v) << std::endl;

	// random value modeling print for standart func
	std::cout << std::endl << "��������� �������� ��� ������������ ������������� > " << Random_item(v)<<std::endl;
	
	//mixed function print
	std::vector<double>vec = Mixed_Func_calc(p, 0,v,u1,l1, 0,v2,u2,l2);
	std::cout << std::endl << "��������� ����� ������������� : " << std::endl;
	std::cout << "dispersion " << vec[0] << std::endl << "excess "<<vec[1]<< std::endl<< "density " << vec[2] << std::endl << "expected value " << vec[3] << std::endl << "asymmetry " << vec[4] << std::endl;
	
	// random value modeling print for function mix
	std::cout << std::endl << "��������� �������� ��� ����� ������������� > "<< Mixed_Random_value(p, v, v2);


	
}