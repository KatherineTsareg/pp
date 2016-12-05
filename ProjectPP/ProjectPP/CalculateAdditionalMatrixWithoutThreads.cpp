#include "stdafx.h"
#include "CalculateAdditionalMatrixWithoutThreads.h"

using namespace std;

CCalculateAdditionalMatrixWithoutThreads::CCalculateAdditionalMatrixWithoutThreads(std::vector<std::vector<double>> & inputMatrix):IMatrix(inputMatrix)
{
}

std::vector<std::vector<double>> CCalculateAdditionalMatrixWithoutThreads::GetAdditionsMatrix()
{
	auto additionMatrix = m_matrix;
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	for (size_t i = 0; i < m_height; i++)
	{
		for (size_t j = 0; j < m_width; j++)
		{
			additionMatrix[i][j] = pow(-1, i + j) * GetMinorItem(i, j);
		}
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time linear: "
		<< std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
		<< " secs" << endl;
	return additionMatrix;
}

double CCalculateAdditionalMatrixWithoutThreads::GetMinorItem(size_t row, size_t column)
{
	auto submatrix = GetSubmatrix(&m_matrix, row, column);
	CCalculateAdditionalMatrixWithoutThreads shortMatrix(submatrix);
	return shortMatrix.GetDeterminant();
}
