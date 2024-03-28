#include <iostream>
using namespace std;

/*
��������� ����� (Factory Method) � ����������� ������ ��������������, ��������������� ���������� ��������� ��� �������� ����������� ���������� ������.
� ������ �������� ���������� ����� ����������, ����� ����� ���������������. ����� �������, ������� ���������� �������� �������� ����������� ������������� ������.
��� ��������� ������������ � ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
��������� �����  ���������� ��������� ��� �������� �������, �� ��������� ���������� ������� � ���, ����� ����� ���������������.

������������
-	������ ������� ����������, ������� ����� ���������� ��� ����� ���������.
-	����� ������������� ���, ����� �������, ������� �� ������, ����������������� �����������.
-	����� ���������� ���� ����������� ������ �� ���������� ��������������� ����������, � ����������� ������������ ������ � ���, ����� ����� ��������� ��� ����������� �� ����.

�����������
��������� ������ ��������� �������������� �� ������������� ���������� � ��� ��������� �� ���������� ������. ��� ����� ���� ������ � �����������
������ Product, ������� �� ����� �������� � ������ ������������� �������������� �������� ���������� ���������.
����������
������������� ���������� ���������� ������ ������� � ���, ��� ��������, ��������, �������� ��������� �������� ������ Creator ��� �������� ���� ������ ������� ConcreteProduct.
*/

//������� (House) ���������� ��������� ��������, ����������� ��������� �������
class House abstract
{ 
};

// ���������� ������� ��������� ��������� Product (� ����� ������, House)
class PanelHouse : public House
{
public:
	PanelHouse()
	{
		cout << "Panel house built\n";
	}
};

// ���������� ������� ��������� ��������� Product (� ����� ������, House)
class WoodHouse : public House
{
public:
	WoodHouse()
	{
		cout << "Wooden house built\n";
	}
};

class BrickHouse : public House
{
public:
	BrickHouse()
	{
		cout << "Brick house built\n";
	}
};

class D3House : public House
{
public:
	D3House()
	{
		cout << "3D house built\n";
	}
};

// Creator ��������� ��������� �����, ������������ ������ ���� Product.
// ����������� ����� ������������ ��������
class Developer abstract
{
	// ��������� �����
public:
	virtual House* Create() = 0;
};

// ���������� ��������� �������� ��������� �����, ������������ ������ ConcreteProduct.
// ������ ��������� ����
class PanelDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new PanelHouse;
	}
};

// ���������� ��������� �������� ��������� �����, ������������ ������ ConcreteProduct.
// ������ ���������� ����
class WoodDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new WoodHouse;
	}
};

class BrickDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new BrickHouse;
	}
};

class D3HouseDeveloper : public Developer
{
public:
	House* Create() override
	{
		return new D3House;
	}
};

// ������� ��������� ������������ � ���������� ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
House * Client(Developer *pDev)
{
	return pDev->Create();
}

void main()
{
	Developer *pDev = new PanelDeveloper();
	House * pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	pDev = new WoodDeveloper();
	pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	pDev = new BrickDeveloper();
	pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	pDev = new D3HouseDeveloper();
	pHouse = Client(pDev);
	delete pHouse;
	delete pDev;

	system("pause");
}
