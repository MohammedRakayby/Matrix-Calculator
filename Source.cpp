#include "Matrices.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<float>> vec1;  //first matrix
vector<vector<float>> vec2;  //second matrix
vector<vector<float>> vec3;  //result matrix
vector<vector<float>> vec_temp; //temp matrix
vector<float> tmp; //temp row/col for echelon form

Matrices::Matrices(void)
{
	row1 = 0, col1 = 0;
	row2 = 0, col2 = 0;
	con = 0;
	t_row = 0, t_col = 0;
}
void Matrices::Choice()
{

	cout << "choices list:" << "\n" << "Press A for addition. \n" << "Press S for Subtraction. \n"
		<< "Press M for multiplication. \n" << "Press C for multiplication by constant. \n" << "Press T for transpose.\nPress E for echelon form." << endl;
	cin >> choice;
	if ((choice == 'A') || (choice == 'a'))
	{
		input();
		addition();
	}
	else if ((choice == 'S') || (choice == 's'))
	{
		input();
		subtraction();
	}
	else if ((choice == 'M') || (choice == 'm'))
	{
		input();
		multiplication();
	}
	else if ((choice == 'C') || (choice == 'c'))
	{
		input();
		MultByConst();
	}
	else if ((choice == 'T') || (choice == 't'))
	{
		input();
		Transpose();
	}
	else if ((choice == 'E') || (choice == 'e'))
	{
		input();
		echelon();
	}
	else
	{
		cout << "choice is not found " << endl;
	}
}
void Matrices::input()
{
	cout << "enter dimensions of first matrix(row,col) : " << endl;
	cin >> row1 >> col1;
	//cout<<"enter dimensions of second matrix(row,col) : "<<endl;

	vec1.resize(row1);
	for (int i = 0; i<row1; i++)
	{
		vec1[i].resize(col1);
	}

	//filling vector 1
	cout << "enter values in matrix 1: " << endl;
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
		{
			cin >> vec1[i][j];
		}
	}cout << endl;


	//printing vector 1
	cout << "first matrix is " << row1 << " x " << col1 << endl;
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
		{
			cout << vec1[i][j] << " ";
		}
		cout << endl;
	}cout << endl;
	if (choice == 'a' || choice == 'A' || choice == 's' || choice == 'S' || choice == 'm' || choice == 'M')
	{

		cout << "enter dimensions of second matrix(row,col) : " << endl;
		cin >> row2 >> col2;
		vec2.resize(row2);
		for (int i = 0; i<row2; i++)
		{
			vec2[i].resize(col2);
		}
		//filling vector 2
		cout << "enter values in matrix 2: " << endl;
		for (int i = 0; i<row2; i++)
		{
			for (int j = 0; j<col2; j++)
			{
				cin >> vec2[i][j];
			}
		}cout << endl;
		//printing vector 2
		cout << "second matrix is " << row2 << " x " << col2 << endl;
		for (int i = 0; i<row2; i++)
		{
			for (int j = 0; j<col2; j++)
			{
				cout << vec2[i][j] << " ";
			}
			cout << endl;
		}cout << endl;
	}
}

void Matrices::multiplication(){
	if (row1 != col2)
	{
		cout << "cannot multiply matrices,\nrows of first matrix not equal to columns of second matrix" << endl;
		exit(0);
	}
	else
	{
		vec3.resize(row1);
		{
			for (int i = 0; i<row1; i++)
			{
				vec3[i].resize(col2);
			}
		}
		//multiplying
		for (int i = 0; i<row1; i++)
		{
			for (int j = 0; j<col2; j++)
			{
				//vec3[i][j]=0;  /*check 3al 7etta di liha lazma ? */
				for (int k = 0; k<col1; k++)
				{
					vec3[i][j] += vec1[i][k] * vec2[k][j];
				}
			}
		}
		//printing 3rd array
		cout << "Result Matrix is " << row1 << " x " << col2 << endl;
		for (int i = 0; i<row1; i++)
		{
			for (int j = 0; j<col2; j++)
			{
				cout << vec3[i][j] << " ";
			}
			cout << endl;
		}
	}
	system("PAUSE");
}
void Matrices::addition()
{

	cout << "Matrix 1 + Matrix 2= " << endl;
	vec3.resize(row1);
	{
		for (int i = 0; i<row1; i++)
		{
			vec3[i].resize(col2);
		}
	}
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
		{
			vec3[i][j] = vec1[i][j] + vec2[i][j]; //filling 3rd vector
		}
	}
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
		{
			cout << vec3[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
}
void Matrices::subtraction()
{
	cout << "Matrix 1-Matrix 2= " << endl;
	vec3.resize(row1);
	{
		for (int i = 0; i<row1; i++)
		{
			vec3[i].resize(col2);
		}
	}
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
		{
			vec3[i][j] = vec1[i][j] - vec2[i][j]; //filling 3rd vector
		}
	}
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
		{
			cout << vec3[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
}
void Matrices::MultByConst()
{
	cout << "Enter a number to multiply the matrix " << endl;
	cin >> con;
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
		{
			vec1[i][j] = vec1[i][j] * con;
		}
	}
	cout << "The matrix multiplied by " << con << endl;
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
		{
			cout << vec1[i][j] << " ";
		}
		cout << endl;
	}

	system("PAUSE");
}
void Matrices::Transpose()
{
	for (int i = 0; i<col1; i++)
	{
		for (int j = 0; j<row1; j++)
		{
			cout << vec1[j][i] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
}
void Matrices::echelon()
{
	tmp.resize(col1);
	for (int i = 0; i<row1; i++)
	{
		int j = 0;
		for (int j = 0; j<col1; j++)
		{
			if ((vec1[i][j] != 0) || (i == 0 && j == 0))
			{
				if ((i == 0 && j == 0) && (vec1[i][j] == 0))
				{
					for (int k = 0; k<col1; k++)
					{
						tmp[k] = vec1[i][k];
						vec1[i][k] = vec1[row1][k];
						vec1[row1 - 1][k] = tmp[k];
					}
				}
				pivot = vec1[i][j];
				for (int k = 0; k<col1; k++)
				{
					vec1[i][k] = vec1[i][k] / pivot;
				}

				for (int n = i + 1; n<row1; n++)
				{
					if (vec1[n][j] != 0)
					{
						p_col = -vec1[n][j];
						for (int m = 0; m<col1; m++)
							vec1[n][m] = (vec1[i][m] * p_col) + vec1[n][m];
					}
				}

				break;
			}
		}
	}
	for (int i = 0; i<row1; i++)
	{
		counter = 0;
		for (int j = 0; j<col1; j++)
		{
			if (vec1[i][j] == 0)
				counter++;
		}
		if (counter == col1)
		{
			for (int k = 0; k<col1; k++)
			{
				tmp[k] = vec1[i][k];
				vec1[i][k] = vec1[row1 - 1][k];
				vec1[row1 - 1][k] = tmp[k];
			}
		}
	}
	// 34an el negative zero elly btytl3
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
		{
			if (vec1[i][j] == -0)
				vec1[i][j] = abs(vec1[i][j]);
		}
	}
	for (int i = 0; i<row1; i++)
	{
		for (int j = 0; j<col1; j++)
			cout << vec1[i][j] << " ";
		cout << endl;
	}

	system("PAUSE");

}