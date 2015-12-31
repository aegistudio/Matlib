#ifndef __TRANSPOSED_MATRIX_H__
#define __TRANSPOSED_MATRIX_H__

#include "mat/matrix.h"

// TransposedMatrix
template <typename T>
class TransposedMatrix : public Matrix<T> {
	private:
		Matrix<T>* originalMatrix;
	public:
		TransposedMatrix(Matrix<T>& matrix);
		T& operator()(int r, int c);
		Matrix<T>* wrapping() { return originalMatrix -> wrapping(); }
		Matrix<T>* clone() { return new TransposedMatrix(*originalMatrix); }
};

#include "mat/template/transposed_matrix"

#endif
