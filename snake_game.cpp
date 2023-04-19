// C++ program to build the complete
// snake game
#include <bits/stdc++.h>
#include <conio.h>
#include <unistd.h>
using namespace std;

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;
// Function to generate the fruit
// within the boundary
void setup()
{
	gameover = 0;

	// Stores height and width
	x = height / 2;
	y = width / 2;
	fruitx = rand() % 20;
	while (fruitx == 0)
	{
		fruitx = rand() % 20;
	}

	fruity = rand() % 20;
	while (fruity == 0)
	{
		fruity = rand() % 20;
	}
	score = 0;
}

// Function to draw the boundaries
void draw()
{

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
			{
				cout << ("#");
			}
			else
			{
				if (i == x && j == y)
					cout << ("0");
				else if (i == fruitx && j == fruity)
					cout << ("*");
				else
					cout << (" ");
			}
		}
		cout << ("\n");
	}

	// Print the score after the
	// game ends
	cout << ("score = ", score);
	cout << ("\n");
	cout << ("press X to quit the game") << endl;
}

// Function to take the input
void input()
{
	if (kbhit())
	{
		switch (getch())
		{
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}

// Function for the logic behind
// each movement
void logic()
{
	sleep(1);
	switch (flag)
	{
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}

	// If the game is over
	if (x < 0 || x > height || y < 0 || y > width)
		gameover = 1;

	// If snake reaches the fruit
	// then update the score
	if (x == fruitx && y == fruity)
	{

		fruitx = rand() % 20;
		while (fruitx == 0)
		{
			fruitx = rand() % 20;
		}

		// After eating the above fruit
		// generate new fruit
		fruity = rand() % 20;
		while (fruity == 0)
		{
			fruity = rand() % 20;
		}
		score += 10;
	}
}

// Driver Code
int main()
{
	int m, n;

	// Generate boundary
	setup();

	// Until the game is over
	while (!gameover)
	{

		// Function Call
		draw();
		input();
		logic();
	}
}
