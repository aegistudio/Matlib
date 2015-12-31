#ifndef __SPARSE_LOCKERMATRIX_H__
#define __SPARSE_LOCKERMATRIX_H__

#include "mat/matrix.h"

// SparseLockerMatrix
template <typename T>
struct MatrixWriteTransation {
	int row, column;
	T element;
	MatrixWriteTransation<T>* next;
};

template <typename T>
class SparseLockerMatrix : public Matrix<T>{
	private:
		Matrix<T>* originalMatrix;
		MatrixWriteTransation<T> elements;
		MatrixWriteTransation<T>* last;
	public:
		SparseLockerMatrix(Matrix<T>& matrix);
		~SparseLockerMatrix();
		T& operator()(int r, int c);
		Matrix<T>* wrapping() { return originalMatrix -> wrapping(); }
		Matrix<T>* clone() { return new SparseLockerMatrix(*(originalMatrix->clone())); }
};

#include "mat/template/sparse_lockermatrix"

#endif
