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

	// random value modeling print for standart func
	std::cout << std::endl << "��������� �������� ��� ������������ ������������� > " << Random_item(v)<<std::endl;
	
	//mixed function print
	std::cout << "������� �������� ����� � > ";
	double p;
	std::cin >> p;
	std::cout << "������� �������� v ��� ������� ������������� (��� �����) > ";
	double v2;
	std::cin >> v2;
	
	std::vector<double>vec = Mixed_Func_calc(p, 0,v,3,2, 0,v2,3,2);
	std::cout << std::endl << "��������� ����� ������������� : " << std::endl;
	std::cout << "dispersion " << vec[0] << std::endl << "excess "<<vec[1]<< std::endl<< "density " << vec[2] << std::endl << "expected value " << vec[3] << std::endl << "asymmetry " << vec[4] << std::endl;
	
	// random value modeling print for function mix
	std::cout << std::endl << "��������� �������� ��� ����� ������������� > "<< Mixed_Random_value(p, v, v2);


	
}