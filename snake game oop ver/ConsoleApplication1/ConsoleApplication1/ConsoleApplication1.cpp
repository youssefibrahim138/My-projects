#include <iostream>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace ::std;
class game
{
	enum dir
	{
		Top = 1, Down, Left, Right
	};
	int width;
	int height;
	//---
	int fruit_x;
	int fruit_y;
	//----
	int snake_x;
	int snake_y;
	 dir directions;
	//------
	int score;
	bool lose;
public:

	void generate()
	{
		srand(time(NULL));
		fruit_x = rand() % (width - 2) + 1;
		fruit_y = rand() % (height - 2) + 1;
	}


	game()
	{
		width = 70;
		height = 27;

		snake_x = width / 2;
		snake_y = height / 2;

		generate();

		score = 0;
		lose = false;
	}

	
	bool get_player_status()
	{
		return lose;
	}

	void draw()
	{
		system("cls");
		for (int i = 0; i < height ; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 || j == 0 || j == width - 1 || i == height - 1)
				{
					cout << '*';
				}
				else if (i == fruit_y && j == fruit_x)
				{
					cout << "$";
				}
				else if (i == snake_y && j == snake_x)
				{
					cout << "O";
				}
				else
				{
					cout << ' ';
				}
			}
			cout << endl;
		}
		cout << "score: " << score << endl;
	}


	void input()
	{
		if (_kbhit())
		{
			char c = _getch();
			switch (c)
			{
			case('w'): directions = Top; break;
			case('s'):directions = Down; break;
			case('a'):directions = Right; break;
			case('d'):directions = Left; break;
			case('x'):exit(0); break;
			}
		}
	}

	void move()
	{
		switch (directions)
		{
		case game::Top: snake_y--;
			break;
		case game::Down:snake_y++;
			break;
		case game::Left:snake_x++;
			break;
		case game::Right:snake_x--;
			break;
		default:
			break;
		}
		if (snake_y == 0 || snake_x == 0 || snake_y == height - 1 || snake_x == width - 1)
		{
			lose = true;
        }
		if (fruit_y == snake_y && fruit_x == snake_x)
		{
			generate();
			score++;
		}
	}



};


int main()
{
	char  key = 'R';
	while (key!='X')
	{
		game sn;
		while (!sn.get_player_status())
		{
			sn.draw();
			sn.input();
			sn.move();
			Sleep(55);
		}
		cout << "Game Over" << endl;
		cout << "If you want to play again press R, if you want to exit press X" << endl;
		cin >> key;
	}

	

	return 0;
}
