#ifndef __THICK_LOCKERMATRIX_H__
#define __THICK_LOCKERMATRIX_H__

#include "mat/matrix.h"
#include "mat/concrete_matrix.h"

// ThickLockerMatrix
template <typename T>
class ThickLockerMatrix : public Matrix<T> {
	private:
		Matrix<T>* originalMatrix;
		Matrix<T>* thickMatrix;
	public:
		ThickLockerMatrix(Matrix<T>& matrix);
		~ThickLockerMatrix();
		T& operator()(int r, int c);
		Matrix<T>* wrapping() { return originalMatrix -> wrapping(); }
		Matrix<T>* clone() { return new ThickLockerMatrix(*(originalMatrix->clone())); }
};

#include "mat/template/thick_lockermatrix"

#endif
