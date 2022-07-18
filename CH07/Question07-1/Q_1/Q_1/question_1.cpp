/*
* 문제 07-1
* class Car, HybridCar, HybridWaterCar의 생성자 정의
*/

#include <iostream>
#include <cstring>

using namespace std;

class Car {
private:
	int gasolineGauge;			// 가솔린 용량
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
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};
int main() {

	HybridWaterCar mycar(10, 10, 10);
	mycar.ShowCurrentGague();

	return 0;
}