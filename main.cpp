#include <iostream>
#include <windows.h>

using namespace std;

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int inp, n = -1;
char player = 'X';

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Draw()
{	
	n++;
	system("cls");
	cout << "\t\t\t ___ ___ ___" << endl;
	for(int i = 0; i < 3; i++)
	{
		cout << "\t\t\t|   |   |   |" << endl << "\t\t\t| ";
		for(int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " | ";
		}
		cout << endl << "\t\t\t|___|___|___|" << endl;
	}
	cout << endl << endl;
}

void Input()
{	
	cout << "Its " << player << " Turn " << "Pres The Number of the field : ";
	cin >> inp;
		if(inp == 1) 
		{
			if(matrix[0][0] == '1')
				matrix[0][0] = player; 
			else {
				cout << "Error Input This Number\n";
				Input();
			}
		}
		else if(inp == 2) 
		{
			if(matrix[0][1] == '2')
				matrix[0][1] = player;
			else {
				cout << "Error Input This Number\n";
				Input();
			}
		}
		else if(inp == 3) 
		{
			if(matrix[0][2] == '3') 
				matrix[0][2] = player;
			else {
				cout << "Error Input This Number\n";
				Input();
			}
		}
		else if(inp == 4)
		{
			if(matrix[1][0] == '4') 
				matrix[1][0] = player; 
			else {
				cout << "Error Input This Number\n";
				Input();
			}
		}
		else if(inp == 5) 
		{
			if(matrix[1][1] == '5')
			 
				matrix[1][1] = player;
			else {
				cout << "Error Input This Number\n";
				Input();
			} 
		}
		else if(inp == 6)
		{
			if(matrix[1][2] == '6')
				matrix[1][2] = player; 
			else {
				cout << "Error Input This Number\n";
				Input();
			}
		}
		else if(inp == 7)
		{
			if(matrix[2][0]  == '7') 
				matrix[2][0] = player; 
			else {
				cout << "Error Input This Number\n";
				Input();
			}
		}
		else if(inp == 8)
		{
			if(matrix[2][1] == '8') 
				matrix[2][1] = player; 
			else {
				cout << "Error Input This Number\n";
				Input();
			}
		}
		else if(inp == 9)
		{ 
			if(matrix[2][2] == '9') 
				matrix[2][2] = player; 
			else {
				cout << "Error Input This Number\n";
				Input();
			}
		} 
		else
		{
			cout << "ERROR This Number\n";
			Input();
		}
}

void TooglePlayer()
{
	if(player == 'X')
		player = 'O';
	else player = 'X';
}

char Logic()
{	
	if(matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') return 'X';
	if(matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X') return 'X';
	if(matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') return 'X';
	if(matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') return 'X';
	if(matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') return 'X';
	if(matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') return 'X';
	if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') return 'X';
	if(matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') return 'X';
	/////////////////////////////////////////////////////////////////////////////////
	if(matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O') return 'O';
	if(matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O') return 'O'; 
	if(matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O') return 'O';
	if(matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O') return 'O';
	if(matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O') return 'O';
	if(matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O') return 'O';
	if(matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return 'O';
	if(matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O') return 'O';
	return '/';
}

int main() 
{	
	Draw();
	while(true)
	{
		Input();
		Draw();
		if(Logic() == 'X')
		{
			cout << "X Wins!\n";
			break;
		}else if(Logic() == 'O')
		{
			cout << "O Wins!\n";
			break;
		}else if(Logic() == '/' && n == 9)
		{
			cout<<"0 - 0\n";
			break;
		}
		TooglePlayer();
	}
	system("Pause");
	return 0;
}
