#include <iostream>
#include<conio.h>
#include<Windows.h>
using namespace ::std;
enum dir { top =1, down, rigt,let };
struct Map
{
	int width;
	int height;
	char fruit;
	int fruit_x;
	int fruit_y;
};
struct player
{
	int score;
	bool lose;
};
struct snake
{
	int snake_x;
	int snake_y;
	dir direction;
};

Map window;
player user;
snake avatar;
void generate_fruit()
{
	srand(time(NULL));
	window.fruit_x = rand() % (window.width - 2) + 1;
	window.fruit_y = rand() % (window.height - 2) + 1;
}
void set_up()
{
	window.width = 80;
	window.height = 27;
	generate_fruit();
	//------
	avatar.snake_x = window.width / 2;
	avatar.snake_y = window.height / 2;
	//--------
	user.lose = false;
	user.score = 0;
}
void draw()
{
	system("cls");
	for (int i = 0; i < window.height; i++)
	{
		for (int j = 0; j < window.width; j++)
		{
			if (j == 0 || j == window.width - 1 ||i == 0 || i == window.height-1)
			{
				cout << "*";
			}
			else if(i == window.fruit_y && j == window.fruit_x)
			{
				cout << '$';
			}
			else if (i == avatar.snake_y && j == avatar.snake_x)
			{
				cout << "Q";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << "Score: " << user.score << endl;
}
void input()
{
	if (_kbhit())
	{
		char c = _getch();
		switch (c)
		{
		case 'w': avatar.direction = top; break;
		case 's': avatar.direction = down; break;
		case 'd': avatar.direction = rigt; break;
		case 'a': avatar.direction = let; break;
		case 'x': exit(0);
		}
	}
}

void move()
{
	switch (avatar.direction)
	{
	case top: avatar.snake_y--; break;
	case down: avatar.snake_y++; break;
	case rigt: avatar.snake_x++; break;
	case let: avatar.snake_x--; break;
	}
	 if (avatar.snake_x >= window.width || avatar.snake_x <= 0 || avatar.snake_y >= window.height || avatar.snake_y <= 0)
	 {
		 user.lose = true;
	 }
	 if (avatar.snake_x == window.fruit_x && avatar.snake_y == window.fruit_y)
	 {
		 generate_fruit();
		 user.score++;
	 }
}

int main()
{
	char key = 'r';
	while (key == 'r')
	{
		set_up();
		while (!user.lose)
		{
			draw();
			input();
			move();
			Sleep(50);
		}
		cout << "If you want to play again press 'r', if you want to exit press 'x' " << endl;
		cin >> key;
		user.lose = false;
	}

	return 0;
}
