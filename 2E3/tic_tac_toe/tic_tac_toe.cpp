#include <iostream>
#include <climits>
using namespace std;

const int NUMBER = 9;
int board[NUMBER] = {0}; // initialize the board with zeros
const int num_lines = 8, num_elements = 3;
int lines[num_lines * num_elements] = {
	// rows
	0, 1, 2,
	3, 4, 5,
	6, 7, 8,
	// columns
	0, 3, 6,
	1, 4, 7,
	2, 5, 8,
	// diagonals
	0, 4, 8,
	2, 4, 6
};

int check_win()
{
	for (int i=0; i<num_lines; i++)
	{
		int value = board[lines[i * num_elements]];
		if (value != 0)
		{
			int unequal_count = 0;
			for (int j=1; j<num_elements; j++)
			{
				if (value != board[lines[i * num_elements + j]])
				{
					unequal_count++;
					break;
				}
			}
			if (unequal_count == 0)
			{
				return value;
			}
		}
	}
	return -1;
}

void make_move(int player)
{	
	int position = INT_MIN;
	do 
	{
		if (position == INT_MIN)
		{
			cout<<"Player "<<player<<"\tPlease choose a position (1-9):"<<endl;
		} 
		else
		{
			cout<<"Player "<<player<<"\tInvalid position. Choose a position again (1-9):"<<endl;
		}
		cin>>position;
		position--;
	} while (!(position >= 0 && position < NUMBER && board[position] == 0));
	board[position] = player;
}

void print_board()
{
	const int row = 3, column = 3;
	char signs[] = " XO";
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<column; j++)
		{
			int index = i * column + j;
			if (board[index] == 1 || board[index] == 2)
			{
				cout<<signs[board[index]]<<"\t";
			} 
			else
			{
				cout<<index+1<<"\t";
			}
		}
		cout<<endl;
	}
}

void fill_zero()
{
	for (int i=0; i<NUMBER; i++)
	{
		board[i] = 0;
	}
}

void main()
{
	cout<<"Tic-tac-toe"<<endl;
	char again = NULL;
	do 
	{
		int count = 0;
		fill_zero();
		while (count < NUMBER)
		{
			print_board();
			int player = (count % 2 == 0) ? 1 : 2;
			make_move(player);
			int winner = check_win();
			if (winner > 0)
			{
				print_board();
				cout<<"Player "<<winner<<" win."<<endl;
				break;
			}
			count++;
		}
		if (count >= NUMBER)
		{
			print_board();
			cout<<"It's a draw."<<endl;
		}
		cout<<"Would you like to play again? (y/n)"<<endl;
		cin>>again;
	} while (again == 'Y' || again == 'y');
}
