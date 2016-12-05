#pragma once
#include "Matrix.h"

class CCalculateAdditionalMatrixWithoutThreads : public IMatrix
{
public:
	CCalculateAdditionalMatrixWithoutThreads(std::vector<std::vector<double>> & inputMatrix);
	~CCalculateAdditionalMatrixWithoutThreads() = default;
	std::vector<std::vector<double>> GetAdditionsMatrix() override;
private:
	double GetMinorItem(size_t row, size_t column);
};

