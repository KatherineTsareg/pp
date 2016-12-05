#pragma once
#include <Windows.h>
#include "Matrix.h"

class CCalculateAdditionalMatrixWithThreads : public IMatrix
{
public:
	CCalculateAdditionalMatrixWithThreads(std::vector<std::vector<double>> & inputMatrix);
	~CCalculateAdditionalMatrixWithThreads();
	std::vector<std::vector<double>> GetAdditionsMatrix() override;
	void SetThreadCount(size_t threadsCount);
private:
	static DWORD WINAPI CalculateMinorItem(LPVOID param);
	size_t m_threadCount = 1;
};

