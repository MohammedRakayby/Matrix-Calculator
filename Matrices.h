#pragma once

class Matrices
{
public:
	Matrices(void);
	void Choice();
	void input();
	void multiplication();
	void addition();
	void subtraction();
	void MultByConst();
	void Transpose();
	void echelon();
private:
	int row1, col1;
	int row2, col2;
	int con;
	int t_row, t_col;
	char choice;
	int pivot, p_col, counter;
};
