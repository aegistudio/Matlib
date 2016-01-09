#ifndef __SPARSE_MATRIX_H__
#define __SPARSE_MATRIX_H__

#include <map>
#include "mat/matrix.h"

template<typename T>
class SparseMatrix : public Matrix<T> {
	private:
		std::map<int, std::map<int, T>*> storage;
		T empty, lastValue;

		SparseMatrix<T>* sparseMatrix;
		int lastRow, lastColumn;
		T& index(int r, int c);
	public:
		class SparseIterator : public Matrix<T>::Iterator {
			private:
				SparseMatrix<T>& matrix;
				typename std::map<int, std::map<int, T>*>::iterator rowIterator;
				typename std::map<int, T>::iterator columnIterator;

			public:
				SparseIterator(SparseMatrix<T>& $matrix);
				void next();
				bool hasNext();
				T value();
				int row();
				int column();
		};

		SparseMatrix(int $row, int $column) : Matrix<T>($row, $column), 
			lastRow(-1), lastColumn(-1), empty(0), lastValue(0){}

		~SparseMatrix();
		T& operator()(int r, int c);
		Matrix<T>* wrapping() {return this;}
		Matrix<T>* clone() { return this; } // NOT IMPLEMENTED.

		Matrix<T>* make(int row, int column) { 
			return new SparseMatrix<T>(Matrix<T>::row, Matrix<T>::column);
		}

		void flush();	// Write back the value.

		/** 
		 * Caution: When using loadValue and loadRatio, the macro __SPARSE_MATRIX_CONSIDER_MAPSIZE__
		 * could be turn on, to tell that load calculation should take map size into consideration,
		 * which may change the decision of load control.
		 */
		int loadValue();
		float loadRatio();
};

#include "mat/template/sparse_matrix"

#endif
