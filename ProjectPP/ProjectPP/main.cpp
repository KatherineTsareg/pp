// ProjectPP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Matrix.h"
#include <ctime>

using namespace std;

vector<vector<double>> GenerateRandomMatrix(const int width, const int height)
{
	vector<vector<double>> matrix;
	matrix.resize(height);
	for (size_t i = 0; i < height; i++)
	{
		matrix[i].resize(width);
		for (size_t j = 0; j < width; j++)
		{
			matrix[i][j] = (rand() % 200) - 100;
		}
	}
	return matrix;
}

int main()
{
	int n = 10;
	srand(time(0));
	CMatrix matrix(GenerateRandomMatrix(n, n));
	CMatrix::Print(matrix.GetAdditionsMatrix());
	return 0;
}