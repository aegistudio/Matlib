#ifndef __BALANCED_MATRIX_H__
#define __BALANCED_MATRIX_H__

#include "mat/matrix.h"
#include "mat/sparse_matrix.h"
#include "mat/concrete_matrix.h"

template<typename T>
class LoadMatrix : public Matrix<T> {
	private:
		Matrix<T>* matrix;
		int previousRow, previousColumn;
		T previousValue;
		int notZeroCounter;
	public:
		// wrappedMatrix should be an empty matrix.
		LoadMatrix(Matrix<T>* wrappedMatrix);

		Matrix<T>* clone();
		Matrix<T>* wrapping() { return matrix->wrapping(); }

		T& operator()(int r, int c);
		int loadValue() { return notZeroCounter; }
		float loadRatio() { return 1.0f * notZeroCounter 
			/ (Matrix<T>::row * Matrix<T>::column); }
};

#ifndef __BALANCED_MATRIX_DEFAULT_CEIL__
	#define __BALANCED_MATRIX_DEFAULT_CEIL__ 0.75
#endif

#ifndef __BALANCED_MATRIX_DEFAULT_FLOOR__
	#define __BALANCED_MATRIX_DEFAULT_FLOOR__ 0.25
#endif

template<typename T>
class BalancedMatrix : public Matrix<T> {
	private:
		Matrix<T>* matrix;
		LoadMatrix<T>* loadMatrix;
		float ceil, floor;
	public:
		BalancedMatrix<T>(int $row, int $column, float $ceil, float $floor) 
			: Matrix<T>($row, $column), ceil($ceil), floor($floor) {
			matrix = new SparseMatrix<T>($row, $column);
			loadMatrix = new LoadMatrix<T>(matrix);
		};
		~BalancedMatrix() {
			if(matrix != NULL) delete matrix;
			if(loadMatrix != NULL) delete loadMatrix;
		}
		T& operator()(int r, int c);
};

#include "mat/template/balanced_matrix"

#endif
