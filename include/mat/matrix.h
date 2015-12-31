#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "stdlib.h"

// MatrixException
typedef int MatrixExceptionFlag;
namespace MatrixException {
	const MatrixExceptionFlag mismatchedRow = 1;
	const MatrixExceptionFlag mismatchedColumn = 2;
	const MatrixExceptionFlag mismatchedRowAndColumn = 3;
}

// Matrix
template <typename T>
class Matrix {	
	public:
		class Iterator {
			public:
				bool operator!(){ return hasNext(); };
				Matrix<T>::Iterator& operator++() { next(); return *this; };
				virtual void next();
				virtual bool hasNext();
				virtual T value();
				virtual int row();
				virtual int column();
		};

		const int row;
		const int column;
		T determinant() throw (MatrixExceptionFlag);

		virtual T& operator()(int r, int c) = 0;
		virtual Matrix<T>* wrapping() = 0;

		// Duplicate all values inside the matrix.
		// LEAK DANGER: please release space by yourselves if you use clone() method.
		virtual Matrix<T>* clone() = 0;

		// Get a traverser of the matrix. ONLY sparse matrices will not return NULL.
		// And only not zero elements could be accessed by the iterator.
		// LEAK DANGER: please release space by yourselves if you use iterator method.

		// While using, we would like you to write so:
		// Matrix<T>::Iterator* iterPointer = matrix.iterator();
		// Matrix<T>::Iterator& iterator;
		// if(iterPointer != NULL)
		// 	for(iterator = *iterPointer; !iterator; iterator ++) {
		//		do whatever you want.
		//	}
		// delete iterPointer;
		virtual Matrix<T>::Iterator* iterator() { return NULL; }

		void add(Matrix<T>& left, Matrix<T>& right) throw (MatrixExceptionFlag);
		void multiply(Matrix<T>& left, Matrix<T>& right) throw (MatrixExceptionFlag);

		void implements(Matrix<T>& source, void (*func)(T&));
		void implements(Matrix<T>& source, void (*func)(T&, int, int));

	protected:
		Matrix(int $row, int $column) : row($row), column($column) {}
};

#include "mat/template/matrix"

#endif
