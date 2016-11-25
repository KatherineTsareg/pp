#pragma once
#include "Matrix.h"

class CLinearlMatrix : public IMatrix
{
public:
	CLinearlMatrix(std::vector<std::vector<double>> & inputMatrix);
	~CLinearlMatrix() = default;
	std::vector<std::vector<double>> GetAdditionsMatrix() override;
private:
	double GetMinorItem(size_t row, size_t column);
};

