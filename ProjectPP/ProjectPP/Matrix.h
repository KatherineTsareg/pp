#pragma once
#include <vector>


class IMatrix
{
public:
	IMatrix(std::vector<std::vector<double>> & inputMatrix);
	std::vector<std::vector<double>> GetMatrix();
	double GetDeterminant() const;
	virtual std::vector<std::vector<double>> GetAdditionsMatrix() = 0;

	void Print();
	~IMatrix();
protected:
	size_t m_width;
	size_t m_height;
	double m_determinant = 1;
	std::vector<std::vector<double>> m_matrix;

	void CalculateDeterminant();
	virtual double GetMinorItem(size_t i, size_t j) = 0;
};

