#include <iostream>

using namespace std;

// Using global variables 
char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int col;
char token = 'X';
bool tie = false;
string pers1;
string pers2;

void	matrice()
{
	// creating Tic_Tac_Toe structure 
	cout << "	|	|	\n";
	cout << "   "<<matrix[0][0]<<"	|   "<<matrix[0][1]<<"   |   "<<matrix[0][2]<<" \n";
	cout << "________|_______|________\n";
	cout << "	|	|	\n";
	cout << "   "<<matrix[1][0]<<"	|   "<<matrix[1][1]<<"   |   "<<matrix[1][2]<<" \n";
	cout << "________|_______|________\n";
	cout <<	"	|	|	\n";
	cout << "   "<<matrix[2][0]<<"	|   "<<matrix[2][1]<<"   |   "<<matrix[2][2]<<" \n";
	cout << "	|	|	\n";
}

void	pos()
{
	int	digit;

	if (token == 'X')
	{
		cout<<pers1<<", enter a digit between 1 and 9: ";
		cin>>digit;
	}

	if(token == '0')
	{
		cout<<pers2<<", enter a digit between 1 and 9: ";
		cin>>digit;
	}

	if (digit == 1)
	{
		row = 0;
		col = 0;
	}
	else if (digit == 2)
	{
		row = 0;
		col = 1;
	}
	else if (digit == 3)
	{
		row = 0;
		col = 2;
	}
	else if (digit == 4)
	{
		row = 1;
		col = 0;
	}
	else if (digit == 5)
	{
		row = 1;
		col = 1;
	}
	else if (digit == 6)
	{
		row = 1;
		col = 2;
	}
	else if (digit == 7)
	{
		row = 2;
		col = 0;
	}
	else if (digit == 8)
	{
		row = 2;
		col = 1;
	}
	else if (digit == 9)
	{
		row = 2;
		col = 2;
	}
	else 
		cout<<"Invalid Number"<<endl;

	if (token == 'X' && matrix[row][col] != 'X' && matrix[row][col] != '0')
	{
		matrix[row][col] = 'X';
		token = '0';
	}
	else if (token == '0' && matrix[row][col] != 'X' && matrix[row][col] != '0')
	{
		matrix[row][col] = '0';
		token = 'X';
	}
	else
	{
		cout << "No space available"<< endl;
		pos();
	}
}

bool	score()
{
	// Check lines
	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2] || matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
		return true;
	}
	// Check diagonales
	if (matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] || matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
	{
		return true;
	}
	
	// Check empty space
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != 'X' && matrix[i][j] != '0')
				return false;
		}
	}
	tie = true;
	return false;
}


int main(void)
{
	cout << "Entrez le nom du premier joueur: \n";
	getline(cin, pers1);
	cout << "Entrez le nom du second joueur: \n";
	getline(cin, pers2);
	cout << pers1 << " est le joueur qui commence\n";
	while (!score())
	{
		matrice();
		pos();
		score();
	}

	if (token == 'X' && tie == false)
		cout<<pers2<<" won!!"<<endl;
	else if (token == '0' && tie == false)
		cout<<pers1<<" won!!"<<endl;
	else
		cout<<"It's a draw!"<<endl;

	return (0);
}
