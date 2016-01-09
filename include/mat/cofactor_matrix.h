#ifndef __COFACTOR_MATRIX_H__
#define __COFACTOR_MATRIX_H__

#include "mat/matrix.h"

// CofactorMatrix
template <typename T>
class CofactorMatrix : public Matrix<T> {
	private:
		Matrix<T>* originalMatrix;
		int cofactRow; int cofactColumn;
	public:
		CofactorMatrix(Matrix<T>& matrix, int $cofactRow, int $cofactColumn);
		T& operator()(int r, int c);
		Matrix<T>* wrapping() { return originalMatrix -> wrapping(); }
		Matrix<T>* clone() { return new CofactorMatrix(*(originalMatrix->clone()), cofactRow, cofactColumn); }
		Matrix<T>* make(int row, int column) { return originalMatrix->make(row, column); }
};

#include "mat/template/cofactor_matrix"

#endif
