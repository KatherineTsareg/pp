#pragma once
#include <vector>


class CMatrix
{
public:
	CMatrix(std::vector<std::vector<double>> & inputMatrix);
	std::vector<std::vector<double>> GetMatrix();
	double GetDeterminant() const;
	std::vector<std::vector<double>> GetAdditionsMatrix();

	static void Print(std::vector<std::vector<double>> matrix);
	void Print();
	~CMatrix();
private:
	std::vector<std::vector<double>> m_matrix;
	size_t m_width;
	size_t m_height;
	double m_determinant = 1;
	
	double GetMinorItem(size_t i, size_t j);
	void CalculateDeterminant();
};

