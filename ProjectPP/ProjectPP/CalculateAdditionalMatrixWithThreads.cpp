#include "stdafx.h"
#include "CalculateAdditionalMatrixWithThreads.h"

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

CCalculateAdditionalMatrixWithThreads::CCalculateAdditionalMatrixWithThreads(std::vector<std::vector<double>> & inputMatrix) : IMatrix(inputMatrix)
{
}


CCalculateAdditionalMatrixWithThreads::~CCalculateAdditionalMatrixWithThreads()
{
}

std::vector<std::vector<double>> CCalculateAdditionalMatrixWithThreads::GetAdditionsMatrix()
{
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
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
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time with thread: "
		<< std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
		<< " secs" << endl;
	return additionMatrix;
}

void CCalculateAdditionalMatrixWithThreads::SetThreadCount(size_t threadsCount)
{
	m_threadCount = threadsCount;
}

DWORD WINAPI CCalculateAdditionalMatrixWithThreads::CalculateMinorItem(LPVOID param)
{
	SParams * params = (SParams*)param;
	
	auto submatrix = GetSubmatrix(&(params->matrix), params->row, params->column);
	CCalculateAdditionalMatrixWithThreads shortMatrix(submatrix);
	params->additionMatrix[params->row][params->column] = pow(-1, params->row + params->column) * shortMatrix.GetDeterminant();
	return 0;
}