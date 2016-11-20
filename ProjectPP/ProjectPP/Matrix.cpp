#include "stdafx.h"
#include "Matrix.h"
#include <boost/range/algorithm/transform.hpp>

using namespace std;


IMatrix::IMatrix(vector<vector<double>> & inputMatrix)
	:m_matrix(inputMatrix)
{
	m_height = inputMatrix.size();
	m_width = inputMatrix[0].size();
	CalculateDeterminant();
}

std::vector<std::vector<double>> IMatrix::GetMatrix()
{
	return m_matrix;
}

double IMatrix::GetDeterminant() const
{
	return m_determinant;
}

/*std::vector<std::vector<double>> CMatrix::GetAdditionsMatrix()
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
}*/


IMatrix::~IMatrix()
{
}


bool SwapRows(vector<vector<double>> & matrix, size_t index, bool & positive) 
{
	if (matrix[index][index] == 0)
	{
		for (size_t i = index + 1; i < matrix.size(); i++)
		{
			if (matrix[i][i] != 0)
			{
				swap(matrix[index], matrix[i]);
				positive = (positive ? false : true);
				return true;
			}
		}
		return false; //false - детерминант равен 0
	}
	return true;
}

/*double IMatrix::GetMinorItem(size_t row, size_t column)
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
	IMatrix shortMatrix(newMatrix);
	return shortMatrix.GetDeterminant();
}*/

void IMatrix::CalculateDeterminant()
{
	auto tempMatrix = m_matrix;
	bool isPositive = true;
	for (size_t iter = 0; iter < m_height - 1; iter++) //будет (количество строк - 1) итераций
	{
		for (size_t i = iter + 1; i < m_height; i++)
		{
			if (!SwapRows(tempMatrix, iter, isPositive))
			{
				m_determinant = 0;
				break;
			}
			if (tempMatrix[i][iter] == 0)
			{
				continue;
			}
			double coef = static_cast<double>(tempMatrix[i][iter]) / static_cast<double>(tempMatrix[iter][iter]);
			for (size_t j = iter; j < m_width; j++)
			{
				tempMatrix[i][j] -= tempMatrix[iter][j] * coef;
			}
		}
	}
	for (size_t i = 0; i < m_height; i++)
	{
		m_determinant *= tempMatrix[i][i];
	}
	m_determinant *= (isPositive ? 1 : -1);
}

void IMatrix::Print()
{
	for (size_t i = 0; i < m_matrix.size(); i++)
	{
		for (size_t j = 0; j < m_matrix[0].size(); j++)
		{
			cout << m_matrix[i][j] << " ";
		}
		cout << endl;
	}
}