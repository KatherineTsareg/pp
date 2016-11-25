#pragma once
#include <Windows.h>
#include "Matrix.h"

class CThreadMatrix : public IMatrix
{
public:
	CThreadMatrix(std::vector<std::vector<double>> & inputMatrix);
	~CThreadMatrix();
	std::vector<std::vector<double>> GetAdditionsMatrix() override;
	void SetThreadCount(size_t threadsCount);
private:
	static DWORD WINAPI CalculateMinorItem(LPVOID param);//size_t row, size_t column);

	size_t m_threadCount = 1;

	
};

