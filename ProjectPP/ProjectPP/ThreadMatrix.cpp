#include "stdafx.h"
#include "ThreadMatrix.h"

using namespace std;

struct SParams
{
	vector<vector<double>> &matrix;
	vector<vector<double>> &additionMatrix;
	size_t row, column;
	size_t width, height;
	SParams(vector<vector<double>> &inputMatrix, vector<vector<double>> &inputAdditionMatrix)
		: matrix(inputMatrix)
		, additionMatrix(inputAdditionMatrix)
	{
		width = inputMatrix.size();
		height = inputMatrix[0].size();
	}
	
};

CThreadMatrix::CThreadMatrix(std::vector<std::vector<double>> & inputMatrix) : IMatrix(inputMatrix)
{
}


CThreadMatrix::~CThreadMatrix()
{
}

std::vector<std::vector<double>> CThreadMatrix::GetAdditionsMatrix()
{
	HANDLE * threads = new HANDLE[m_threadCount];
	auto additionMatrix = m_matrix;
	size_t count = 0;
	vector<SParams> vSParams(m_threadCount, { m_matrix, additionMatrix});
	for (size_t i = 0; i < m_height; i++)
	{
		for (size_t j = 0; j < m_width; j++)
		{
			vSParams[count].row = i;
			vSParams[count].column = j;
			threads[count] = CreateThread(NULL, 0, &CalculateMinorItem, (LPVOID)&vSParams[count], 0, NULL);
			if (count == (m_threadCount - 1))
			{
				WaitForMultipleObjects(m_threadCount, threads, TRUE, INFINITE);
				count = 0;
			}
			else
			{
				++count;
			}
		}
	}
	delete[] threads;
	return additionMatrix;
}

void CThreadMatrix::SetThreadCount(size_t threadsCount)
{
	m_threadCount = threadsCount;
}

DWORD WINAPI CThreadMatrix::CalculateMinorItem(LPVOID param)
{
	SParams * params = (SParams*)param;
	
	vector<vector<double>> newMatrix;
	newMatrix.resize(params->height - 1);
	for (size_t i = 0, x = 0; i < params->height - 1; i++, x++)
	{
		newMatrix[i].resize(params->width - 1);
		x = (x == params->row ? x + 1 : x);
		for (size_t j = 0, y = 0; j < params->width - 1; j++, y++)
		{
			y = (y == params->column ? y + 1 : y);
			newMatrix[i][j] = params->matrix[x][y];
		}
	}
	CThreadMatrix shortMatrix(newMatrix);
	params->additionMatrix[params->row][params->column] = pow(-1, params->row + params->column) * shortMatrix.GetDeterminant();
	return 0;
}