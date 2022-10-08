#include <iostream>

using namespace std;

char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int col;
char token = 'X';
bool tie = false;
string n1;
string n2;

void	matrice()
{
	//creating structure, matrix 
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
		cout<<n1<<", entrez un chiffre entre 1 et 9:";
		cin>>digit;
	}

	if(token == '0')
	{
		cout<<n2<<", entrez un chiffre entre 1 et 9:";
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
		cout<<"Chiffre non valide"<<endl;

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
		cout << "pas d'espace libre"<< endl;
		pos();
	}
}

bool	score()
{
	// check les lignes
	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2] || matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
		return true;
	}
	// les diagonales
	if (matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] || matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
	{
		return true;
	}
	
	// Check les espaces vides
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
	getline(cin, n1);
	cout << "Entrez le nom du second joueur: \n";
	getline(cin, n2);
	cout << n1 << " est le joueur qui commence\n";
	while (!score())
	{
		matrice();
		pos();
		score();
	}
	return (0);
}
