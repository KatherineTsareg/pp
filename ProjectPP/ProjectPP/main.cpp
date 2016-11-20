// ProjectPP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "LinearlMatrix.h"
#include <ctime>

using namespace std;

void PrintMatrix(const vector<vector<double>> & matrix)
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[0].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<double>> GenerateRandomMatrix(const int width, const int height)
{
	vector<vector<double>> matrix;
	matrix.resize(height);
	for (size_t i = 0; i < height; i++)
	{
		matrix[i].resize(width);
		for (size_t j = 0; j < width; j++)
		{
			matrix[i][j] = (rand() % 20) - 10;
			matrix[i][j] /= 5;
		}
	}
	return matrix;
}

int main()
{
	int n = 100;
	srand(time(0));
	CLinearlMatrix matrix(GenerateRandomMatrix(n, n));
	/*std::vector<std::vector<double>> matrix1 = {
		{1, 2, 4, 5},
		{0, 5, 6, 8},
		{0, 0, 1, 4},
		{0, 0, 0, 2},
	};
	CLinearlMatrix matrix(matrix1);*/
	PrintMatrix(matrix.GetAdditionsMatrix());
	return 0;
}