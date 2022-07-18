/*
* ���� 07-1
* class Car, HybridCar, HybridWaterCar�� ������ ����
*/

#include <iostream>
#include <cstring>

using namespace std;

class Car {
private:
	int gasolineGauge;			// ���ָ� �뷮
public:
	Car(int gas)
	{
		this->gasolineGauge = gas;
	}
	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int gas, int elec)
		:Car(gas), electricGauge(elec)
	{}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water) 
		:HybridCar(gas, elec), waterGauge(water)
	{}
	void ShowCurrentGague() {
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};
int main() {

	HybridWaterCar mycar(10, 10, 10);
	mycar.ShowCurrentGague();

	return 0;
}