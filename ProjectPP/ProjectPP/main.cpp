// ProjectPP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "LinearlMatrix.h"
#include "ThreadMatrix.h"
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
	int n = 1000;
	srand(time(0));
	auto vecvec = GenerateRandomMatrix(n, n);
	
	
	CLinearlMatrix matrix(vecvec);
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	auto results = matrix.GetAdditionsMatrix();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Printing took "
		<< std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
		<< " secs" << endl;

	//CLinearlMatrix matrix(vecvec);
	//PrintMatrix(matrix.GetAdditionsMatrix());
	
	/*CThreadMatrix threadMatrix(vecvec);
	threadMatrix.SetThreadCount(7);
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	auto results = threadMatrix.GetAdditionsMatrix();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Printing took "
		<< std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
		<< " secs" << endl;*/
	
	
	//PrintMatrix(results);
	
	return 0;
}