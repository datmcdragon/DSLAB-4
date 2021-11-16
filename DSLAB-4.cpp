#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
using namespace std;
void main()
{
	int x, y, w, chromatic;
	int summond[6];
	int m[15] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5 };
	int n[15] = { 2, 3, 4, 5, 6, 3, 4, 5, 6, 4, 5, 6, 5, 6, 6 };
	int contiguity[6][6];
	int incidence[6][11];
	int Rmn[15];
	cout << "Input values:\n";
	for (int i = 0; i <= 14; i++)
	{
		cin >> Rmn[i];
	}
	int k = 0, j = 0, z = -1;
	for (int i = 0; i <= 5; i++)
	{
		z += 1;
		for (j = z; j <= 5; j++)
		{
			if (i == j)
			{
				contiguity[i][j] = 0;
			}
			else
			{
				contiguity[i][j] = Rmn[k];
				contiguity[j][i] = Rmn[k++];
			}
		}
	}
	cout << "\nMatrix of contiguity:\n\n";
	for (int i = 0; i <= 5; i++)
		for (int k = 0, j = 0; j <= 5; j++)
		{
			cout << contiguity[i][j] << " ";
			if (j == 5) cout << "\n";
		}
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 10; j++)
			incidence[i][j] = 0;
	for (int i = 0, k = 0; i <= 14; i++)
	{
		x = Rmn[i];
		y = m[i] - 1;
		w = n[i] - 1;
		while (x > 0)
		{
			incidence[y][k] = 1;
			incidence[w][k] = 1;
			k++;
			x--;
		}
	}
	_getch();
}
