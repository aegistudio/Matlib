#ifndef __CONCRETE_MATRIX_H__
#define __CONCRETE_MATRIX_H__

#include "mat/matrix.h"

// ConcreteMatrix
template <typename T>
class ConcreteMatrix : public Matrix<T> {
	private:
		T* matrix;
	public:
		ConcreteMatrix(int $row, int $column);
		~ConcreteMatrix();
		T& operator()(int r, int c);
		Matrix<T>* wrapping() { return this; }
		Matrix<T>* clone();
};

#include "mat/template/concrete_matrix"

#endif
