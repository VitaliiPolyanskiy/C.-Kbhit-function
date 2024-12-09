#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	enum Direction{ UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80};

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor;
	cursor.X = 0;
	cursor.Y = 0;

	Direction dir = RIGHT;

	while (true)
	{
		while (!_kbhit())
		{
			system("cls");
			SetConsoleCursorPosition(h, cursor);
			cout << char(2);
			Sleep(100);
			switch (dir)
			{
			case UP: // код клавиши UP
				cursor.Y--;
				break;
			case LEFT: // код клавиши LEFT
				cursor.X--;
				break;
			case RIGHT: // код клавиши RIGHT
				cursor.X++;
				break;
			case DOWN: // код клавиши DOWN
				cursor.Y++;
				break;
			}
		}
		int result = _getch();
		if (result == 224)
		{
			system("cls");
			result = _getch();
			if (result == UP || result == DOWN || result == LEFT || result == RIGHT)
				dir = (Direction)result;
		}
	}

	return 0;
}