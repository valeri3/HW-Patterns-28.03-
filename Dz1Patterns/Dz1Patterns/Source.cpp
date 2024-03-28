#include <iostream>
#include <string>
#include <array>
#include <clocale> 
#include <windows.h> 

using namespace std;

void SetConsoleColor(WORD color) 
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput, color);
}

class Figure  abstract
{
protected:
	array<array<int, 4>, 4> geometry;
	array<unsigned char, 3> color;
	string name;
public:
	virtual void Display()  
	{
		cout << "Figure: " << name << "\nColor: "
			<< static_cast<int>(color[0]) << ", "
			<< static_cast<int>(color[1]) << ", "
			<< static_cast<int>(color[2]) << "\n";

		// Выбор цвета на основе значений RGB
		WORD consoleColor = 0;
		if (color[0] > 128) consoleColor |= FOREGROUND_RED;
		if (color[1] > 128) consoleColor |= FOREGROUND_GREEN;
		if (color[2] > 128) consoleColor |= FOREGROUND_BLUE;
		consoleColor |= FOREGROUND_INTENSITY; 


		for (int i = 0; i < geometry.size(); ++i) 
		{
			for (int j = 0; j < geometry[i].size(); ++j) 
			{
				if (geometry[i][j] == 1) 
				{
					SetConsoleColor(consoleColor);
					cout << "1";
				}
				else 
				{
					cout << " ";
				}
			}
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			cout << "\n";
		}
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Восстанавливаем стандартный цвет 
		cout << endl;
	}

	virtual ~Figure() {}
};

///////////////////////ФИГУРЫ//////////////////////////

class O_Figure : public Figure 
{
public:
	O_Figure() 
	{
		geometry = { {{0,0,0,0}, {0,1,1,0}, {0,1,1,0}, {0,0,0,0}} };
		color = { 255, 255, 0 }; // Yellow
		name = "O";
	}
};
class I_Figure : public Figure 
{
public:
	I_Figure() 
	{
		geometry = { {{0,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,1,0,0}} };
		color = { 0, 255, 255 }; // Cyan
		name = "I";
	}
};

class S_Figure : public Figure 
{
public:
	S_Figure() 
	{
		geometry = { {{0,0,0,0}, {0,1,1,0}, {1,1,0,0}, {0,0,0,0}} };
		color = { 0, 255, 0 }; // Green
		name = "S";
	}
};

class Z_Figure : public Figure 
{
public:
	Z_Figure() 
	{
		geometry = { {{0,0,0,0}, {0,1,1,0}, {0,0,1,1}, {0,0,0,0}} };
		color = { 255, 0, 0 }; // Red
		name = "Z";
	}
};

class L_Figure : public Figure 
{
public:
	L_Figure() 
	{
		geometry = { {{0,1,0,0}, {0,1,0,0}, {0,1,1,0}, {0,0,0,0}} };
		color = { 255, 165, 0 }; // Orange
		name = "L";
	}
};

class J_Figure : public Figure 
{
public:
	J_Figure() 
	{
		geometry = { {{0,0,1,0}, {0,0,1,0}, {0,1,1,0}, {0,0,0,0}} };
		color = { 0, 0, 255 }; // Blue
		name = "J";
	}
};

class T_Figure : public Figure 
{
public:
	T_Figure() 
	{
		geometry = { {{0,0,0,0}, {0,1,1,1}, {0,0,1,0}, {0,0,0,0}} };
		color = { 128, 0, 128 }; // Purple
		name = "T";
	}
};
////////////////////////КРИЕЙТОРЫ////////////////////////////////

class Creator 
{
public:
	virtual Figure* CreateFigure() const = 0;
	virtual ~Creator() {}
};

class CreatorO : public Creator 
{
public:
	Figure* CreateFigure() const override 
	{
		return new O_Figure();
	}
};

class CreatorI : public Creator 
{
public:
	Figure* CreateFigure() const override 
	{
		return new I_Figure();
	}
};


class CreatorS : public Creator 
{
public:
	Figure* CreateFigure() const override 
	{
		return new S_Figure();
	}
};

class CreatorZ : public Creator 
{
public:
	Figure* CreateFigure() const override 
	{
		return new Z_Figure();
	}
};

class CreatorL : public Creator 
{
public:
	Figure* CreateFigure() const override 
	{
		return new L_Figure();
	}
};

class CreatorJ : public Creator 
{
public:
	Figure* CreateFigure() const override 
	{
		return new J_Figure();
	}
};

class CreatorT : public Creator 
{
public:
	Figure* CreateFigure() const override 
	{
		return new T_Figure();
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");

	Creator* creators[] = { new CreatorO(), new CreatorI(), new CreatorS(), new CreatorZ(), new CreatorL(), new CreatorJ(), new CreatorT() };
	
	const int size = sizeof(creators) / sizeof(creators[0]);

	for (int i = 0; i < size; ++i)
	{
		Figure* figure = creators[i]->CreateFigure();
		figure->Display();

		delete figure; 
	}

	// Освобождение ресурсов 
	for (int i = 0; i < size; ++i)
	{
		delete creators[i];
	}

	system("pause");
}