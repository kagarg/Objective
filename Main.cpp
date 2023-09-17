#include "Header.h"


int main() {
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(0));
	std::cout << "������� v, (v > 0) >";
	double v;
	std::cin >> v;
	if (v <= 0) { std::cout << "������ �����"; exit(-1); }
	// standart function print
	std::cout << "��������� ����� " << Dispersion_calc(v) << std::endl << "����. �������� ����� " << Excess_calc(v) << std::endl
			  << "��������� ������������� ����� " << Density_calc(0,v) << std::endl;
	std::cout << std::endl << "�������� ��� ���������� �������������: " << std::endl;
	//mixed function print
	std::vector<double>vec = Mixed_Func_calc(0.5, 0,1.5,3,2, 0,1.5,3,2);
	std::cout << "dispersion " << vec[0] << std::endl << "excess "<<vec[1]<< std::endl<< "density " << vec[2] << std::endl << "expected value " << vec[3] << std::endl << "asymmetry " << vec[4] << std::endl;
	// random value modeling print
	if (1 <= v < 2){ std::cout << std::endl <<"��������� �������� > " << Random_item12(v); }
	else if (v >= 2) { std::cout << std::endl << "��������� �������� > " << Random_item2(v); }

	
}