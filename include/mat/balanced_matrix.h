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
		Matrix<T>* make(int row, int column) { return matrix->make(row, column); }

		LoadMatrix<T>* clone();
		Matrix<T>* wrapping() { return matrix->wrapping(); }
		Matrix<T>* monitoring() { return matrix; }
		void flush();

		T& operator()(int r, int c);
		int loadValue() { flush(); return notZeroCounter; }
		float loadRatio() { return 1.0f * loadValue() 
			/ (Matrix<T>::row * Matrix<T>::column); }
};

#ifndef __BALANCED_MATRIX_DEFAULT_CEIL__
	#define __BALANCED_MATRIX_DEFAULT_CEIL__ 0.75
#endif

#ifndef __BALANCED_MATRIX_DEFAULT_FLOOR__
	#define __BALANCED_MATRIX_DEFAULT_FLOOR__ 0.25
#endif

/**
 * BalanceMatrix auto balances the storage class of internal matrix, regarding
 * the count of zero elements inside the matrix.
 * This class uses State design pattern.
 */

template<typename T>
class BalancedMatrix : public Matrix<T> {
	private:
		Matrix<T>* matrix;
		LoadMatrix<T>* loadMatrix;
		const float ceil, floor;
		int state; // 0 - sparse matrix, 1 - concrete matrix.
		void balance();
		BalancedMatrix<T>(int $row, int $column, float $ceil, float $floor, int state) 
			: Matrix<T>($row, $column), ceil($ceil), floor($floor), state(0) {};
	public:
		BalancedMatrix<T>(int $row, int $column, float $ceil, float $floor) 
			: BalancedMatrix<T>($row, $column, $ceil, $floor, 0) {
			matrix = new SparseMatrix<T>($row, $column);
			loadMatrix = new LoadMatrix<T>(matrix);
		};
		BalancedMatrix<T>(int $row, int $column) : BalancedMatrix<T>($row, $column, 
			__BALANCED_MATRIX_DEFAULT_CEIL__, __BALANCED_MATRIX_DEFAULT_FLOOR__){};
		~BalancedMatrix() {
			if(matrix != NULL) delete matrix;
			if(loadMatrix != NULL) delete loadMatrix;
		}
		T& operator()(int r, int c);

		BalancedMatrix<T>* clone();
		Matrix<T>* wrapping() { return this; }
		Matrix<T>* make(int row, int column) { 
			return new BalancedMatrix<T>(Matrix<T>::row, Matrix<T>::column, ceil, floor);
		}

		bool sparse() { return state == 0; }
};

#include "mat/template/balanced_matrix"

#endif
