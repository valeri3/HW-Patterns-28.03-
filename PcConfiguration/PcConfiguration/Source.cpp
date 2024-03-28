#include <iostream>
#include <string>
#include <clocale> // ��� setlocale


using namespace std;

/*
��������� ����� (Factory Method) � ����������� ������ ��������������, ��������������� ���������� ��������� ��� �������� ����������� ���������� ������.
� ������ �������� ���������� ����� ����������, ����� ����� ���������������. ����� �������, ������� ���������� �������� �������� ����������� ������������� ������.
��� ��������� ������������ � ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
��������� �����  ���������� ��������� ��� �������� �������, �� ��������� ���������� ������� � ���, ����� ����� ���������������.

������������:
-	������ ������� ����������, ������� ����� ���������� ��� ����� ���������.
-	����� ������������� ���, ����� �������, ������� �� ������, ����������������� �����������.
-	����� ���������� ���� ����������� ������ �� ���������� ��������������� ����������, � ����������� ������������ ������ � ���, ����� ����� ��������� ��� ����������� �� ����.

�����������:
��������� ������ ��������� �������������� �� ������������� ���������� � ��� ��������� �� ���������� ������. ��� ����� ���� ������ � �����������
������ Product, ������� �� ����� �������� � ������ ������������� �������������� �������� ���������� ���������.
����������:
������������� ���������� ���������� ������ ������� � ���, ��� ��������, ��������, �������� ��������� �������� ������ Creator ��� �������� ���� ������ ������� ConcreteProduct.
*/

//������� (PC) ���������� ��������� ��������, ����������� ��������� �������
class PC abstract
{
protected:
	string box = "";
	string processor = "";
	string mainboard = "";
	string hdd = "";
	string memory = "";
public:
	virtual void SetBox() = 0;
	virtual void SetProcessor() = 0;
	virtual void SetMainBoard() = 0;
	virtual void SetHdd() = 0;
	virtual void SetMemory() =  0;
	virtual void ShowPC()
	{
		cout << "\nBox: " + box + "\nProcessor: " + processor + "\nMainBoard: " + mainboard + "\nHDD: " + hdd + "\nMemory: " + memory;
	}
 };

 // ���������� ������� ��������� ��������� Product (� ����� ������, PC)
 class OfficePC : public PC
 {
 public:
	 void SetBox()override
	 {
		 box = "BlackBox";
	 }
	 void SetProcessor()override
	 {
		 processor = "AMD Athlon II X4 840 (3.1 GHz)";
	 }
	 void SetMainBoard()override
	 {
		mainboard = "AMD A58 FCH (Bolton D2)";
	 }
	 void SetHdd()override
	 {
		 hdd = "Seagate Desktop HDD 7200.12 500GB";
	 }
	 void SetMemory()override
	 {
		 memory = "4 Gb DDR3-1600 MHz";
	 }
 };

 // ���������� ������� ��������� ��������� Product (� ����� ������, PC)

 class HomePC : public PC
 {
 public:
	 void SetBox()override
	 {
		 box = "SilverBox";
	 }
	 void SetProcessor()override
	 {
		 processor = "Intel Core i7-4790 (3.6 GHz)";
	 }
	 void SetMainBoard()override 
	 {
		 mainboard = "Intel B85";
	 }
	 void SetHdd()override
	 {
		 hdd = "Western Digital Elements 1.5TB";
	 }
	 void SetMemory()override
	 {
		 memory = "16 GB DDR3-1600";
	 }
 };

 class GamePC : public PC
 {
 public:
	 void SetBox()override
	 {
		 box = "WhiteBox";
	 }
	 void SetProcessor()override
	 {
		 processor = "Intel Core i7-13600kf (5.1 GHz)";
	 }
	 void SetMainBoard()override
	 {
		 mainboard = "Intel Z690";
	 }
	 void SetHdd()override
	 {
		 hdd = "Western Digital Elements 3TB";
	 }
	 void SetMemory()override
	 {
		 memory = "32 GB DDR5-6000";
	 }
 };

 // ��������� ��������� ��������� �����, ������������ ������ ���� Product.
 class Creator abstract
 {
 public:
	 virtual PC* FactoryMethod() = 0;
 };

 // ���������� ��������� �������������� ��������� �����, ������������ ������ ConcreteProduct.
 class CreatorHomePC : public Creator
 {
 public:
	 PC* FactoryMethod()override
	 {
		 PC *pc = new HomePC();
		 pc->SetBox();
		 pc->SetProcessor();
		 pc->SetMainBoard();
		 pc->SetMemory();
		 pc->SetHdd();
		 return pc;
	 }
 };

 // ���������� ��������� �������������� ��������� �����, ������������ ������ ConcreteProduct.
 class CreatorOfficePC : public Creator
 {
 public:
	 PC* FactoryMethod()override
	 {
		 PC* pc = new OfficePC();
		 pc->SetBox();
		 pc->SetProcessor();
		 pc->SetMainBoard();
		 pc->SetMemory();
		 pc->SetHdd();
		 return pc;
	 }
 };

 class CreatorGamePC : public Creator
 {
 public:
	 PC* FactoryMethod()override
	 {
		 PC* pc = new GamePC();
		 pc->SetBox();
		 pc->SetProcessor();
		 pc->SetMainBoard();
		 pc->SetMemory();
		 pc->SetHdd();
		 return pc;
	 }
 };

 // ������� ��������� ������������ � ���������� ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
 void Factory(Creator** creators, int size)
 {
	 // ��������� ������������ �� ���� ��������� � ����������� ���������� ������, ������� ����� ���������� ��������� ����������� ����������� ��������.
	 for(int i = 0; i < size; i++)
	 {
		 PC *pc = creators[i]->FactoryMethod();
		 pc->ShowPC();
	 }
 }

 void main()
 {
	 setlocale(LC_ALL, "Russian");

	 Creator* creators[3];
	 creators[0] = new CreatorHomePC();
	 creators[1] = new CreatorOfficePC();
	 creators[2] = new CreatorGamePC();

	 Factory(creators, 3);

	 int choice;
	 int counter = 0;
	 while (counter < 10)
	 {
		 cout << "�������� ��� ���������� ��� ��������:" << endl;
		 cout << "1. �������� PC" << endl;
		 cout << "2. ������� PC" << endl;
		 cout << "3. ������� PC" << endl;
		 cout << "��� �����: ";
		 cin >> choice;

		 // �������� �����
		 if (cin.fail() || choice < 1 || choice > 3) 
		 {
			 cout << "������������ ����. ���������� �����." << endl;
			 cin.clear(); 
			 cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������������ ���������� ���� �� ����� ������

			 continue; 
		 }

		 PC* pc = creators[choice - 1]->FactoryMethod(); // ������� ��������� ���������� ����
		 pc->ShowPC(); 

		 cout << endl; 

		 counter++; 
	 }

	
	 for (int i = 0; i < 3; ++i)
	 {
		 delete creators[i];
	 }

	 system("pause");
 }