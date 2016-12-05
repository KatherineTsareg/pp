// ProjectPP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CalculateAdditionalMatrixWithoutThreads.h"
#include "CalculateAdditionalMatrixWithThreads.h"

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
	auto vecvec = GenerateRandomMatrix(n, n);
	
	
	CCalculateAdditionalMatrixWithoutThreads matrix(vecvec);
	matrix.GetAdditionsMatrix();
	
	CCalculateAdditionalMatrixWithThreads threadMatrix(vecvec);
	threadMatrix.SetThreadCount(7);
	threadMatrix.GetAdditionsMatrix();
	
	return 0;
}