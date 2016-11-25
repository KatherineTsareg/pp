#include "stdafx.h"
#include "LinearlMatrix.h"

using namespace std;

CLinearlMatrix::CLinearlMatrix(std::vector<std::vector<double>> & inputMatrix):IMatrix(inputMatrix)
{
}

std::vector<std::vector<double>> CLinearlMatrix::GetAdditionsMatrix()
{
	auto additionMatrix = m_matrix;
	for (size_t i = 0; i < m_height; i++)
	{
		for (size_t j = 0; j < m_width; j++)
		{
			additionMatrix[i][j] = pow(-1, i + j) * GetMinorItem(i, j);
		}
	}
	return additionMatrix;
}

double CLinearlMatrix::GetMinorItem(size_t row, size_t column)
{
	vector<vector<double>> newMatrix;
	newMatrix.resize(m_height - 1);
	for (size_t i = 0, x = 0; i < m_height - 1; i++, x++)
	{
		newMatrix[i].resize(m_width - 1);
		x = (x == row ? x + 1 : x);
		for (size_t j = 0, y = 0; j < m_width - 1; j++, y++)
		{
			y = (y == column ? y + 1 : y);
			newMatrix[i][j] = m_matrix[x][y];
		}
	}
	CLinearlMatrix shortMatrix(newMatrix);
	return shortMatrix.GetDeterminant();
}
