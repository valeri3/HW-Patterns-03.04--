#include <iostream>
#include <map>
#include <string>
#include <clocale>

using namespace std;

class Base abstract
{
protected:
	int speed;
	int power;
public:
	virtual void Move(double longitude, double latitude) abstract;
};


class LightInfantryBase : public Base
{
public:
	LightInfantryBase()
	{
		speed = 20;
		power = 10;
	}

	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "������ ������ %d - ��������, %d - ����; \n����������: %f - ������   %f - �������", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class TransportCarsBase : public Base
{
public:
	TransportCarsBase()
	{
		speed = 70;
		power = 0;
	}

	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "������������ ������ %d - ��������, %d - ����; \n����������: %f - ������   %f - �������", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class HeavyGroundCombatVehiclesBase : public Base
{
public:
	HeavyGroundCombatVehiclesBase()
	{
		speed = 15;
		power = 150;
	}

	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "������� �������� ������ ������� %d - ��������, %d - ����; \n����������: %f - ������   %f - �������", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class LightGroundCombatVehiclesBase : public Base
{
public:
	LightGroundCombatVehiclesBase()
	{
		speed = 50;
		power = 30;
	}

	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "������ �������� ������ ������� %d - ��������, %d - ����; \n����������: %f - ������   %f - �������", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class AircraftBase : public Base
{
public:
	AircraftBase()
	{
		speed = 300;
		power = 100;
	}

	void Move(double longitude, double latitude) override
	{
		char buffer[100];
		snprintf(buffer, sizeof(buffer), "����������� %d - ��������, %d - ����; \n����������: %f - ������   %f - �������", speed, power, latitude, longitude);
		cout << buffer << endl;
	}
};

class BaseFactory
{
	map<string, Base*> Bases;
public:
	BaseFactory()
	{
		Bases["������������"] = new LightInfantryBase();
		Bases["����������������������"] = new TransportCarsBase();
		Bases["��������������������"] = new HeavyGroundCombatVehiclesBase();
		Bases["�������������������"] = new LightGroundCombatVehiclesBase();
		Bases["�������"] = new AircraftBase();
	}
	~BaseFactory()
	{
		delete Bases["������������"];
		delete Bases["����������������������"];
		delete Bases["��������������������"];
		delete Bases["�������������������"];
		delete Bases["�������"];
		Bases.clear();
	}
	Base* GetBase(string key)
	{
		if (Bases[key] != nullptr)
		{
			return Bases[key];
		}
		else
		{
			return nullptr;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	double longitude = 21.33;
	double latitude = 65.77;

	BaseFactory* baseFactory = new BaseFactory();

	for (int i = 0; i < 2; i++)
	{
		Base* Base = baseFactory->GetBase("������������");

		if (Base != nullptr)
		{
			Base->Move(longitude, latitude);
		}

		longitude += 0.2;
		latitude += 0.2;

		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		Base* Base = baseFactory->GetBase("����������������������");

		if (Base != nullptr)
		{
			Base->Move(longitude, latitude);
		}

		longitude += 0.3;
		latitude += 0.3;
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		Base* Base = baseFactory->GetBase("��������������������");

		if (Base != nullptr)
		{
			Base->Move(longitude, latitude);
		}

		longitude += 0.2;
		latitude += 0.2;
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{ 
		Base* Base = baseFactory->GetBase("�������������������");

		if (Base != nullptr)
		{
			Base->Move(longitude, latitude);
		}

		longitude += 1.7;
		latitude += 1.7;
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		Base* Base = baseFactory->GetBase("�������");

		if (Base != nullptr)
		{
			Base->Move(longitude, latitude);
		}

		longitude += 4.45;
		latitude += 4.45;
		cout << endl;
	}

	delete baseFactory;
}