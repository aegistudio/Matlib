/*******************************************************
 * <iszero.h> is responsible for juding whether a 
 * number is zero. It's important for matrix calculation
 * and function solution.
 * __IS_ZERO_*_CUSTOM__ where * is a type, you can
 * customize a juding method.
 * __IS_ZERO_*_ERROR__ where * is float or double, you 
 * can customize the interval where is a float point number 
 * is judged zero. (Defaultly float is 1e-44 and double 
 * is 1e-99)
 * __IS_ZERO_DONT_INLINE__ is on, the iszero function will
 * not be inlined. (Defaultly it is inlined.)
 *******************************************************/

#ifndef __IS_ZERO_H__
#define __IS_ZERO_H__

#ifndef __IS_ZERO_DONT_INLINE__
	#define __IS_ZERO_INLINE_FLAG__ inline
#else 
	#define __IS_ZERO_INLINE_FLAG__
#endif

#ifndef __IS_ZERO_CHAR_CUSTOM__
	__IS_ZERO_INLINE_FLAG__ bool iszero(char i) { return i == 0; }
#endif

#ifndef __IS_ZERO_INT_CUSTOM__
	__IS_ZERO_INLINE_FLAG__ bool iszero(int i) { return i == 0; }
#endif

#ifndef __IS_ZERO_SHORT_CUSTOM__
	__IS_ZERO_INLINE_FLAG__ bool iszero(short i) { return i == 0; }
#endif

#ifndef __IS_ZERO_LONG_CUSTOM__
	__IS_ZERO_INLINE_FLAG__ bool iszero(long i) {return i == 0; }
#endif

#ifndef __IS_ZERO_LONG_LONG_CUSTOM__
	bool iszero(long long i) {return i == 0;}
#endif

#ifndef __IS_ZERO_FLOAT_CUSTOM__
	#ifndef __IS_ZERO_FLOAT_ERROR__
		#define __IS_ZERO_FLOAT_ERROR__ (1e-44f)
	#endif
	__IS_ZERO_INLINE_FLAG__ bool iszero(float i) {
		return i <= __IS_ZERO_FLOAT_ERROR__ 
			&& i >= __IS_ZERO_FLOAT_ERROR__;
	}
#endif

#ifndef __IS_ZERO_FLOAT_CUSTOM__
	#ifndef __IS_ZERO_DOUBLE_ERROR__
		#define __IS_ZERO_DOUBLE_ERROR__ (1e-99)
	#endif
	__IS_ZERO_INLINE_FLAG__ bool iszero(double i) {
		return i <= __IS_ZERO_DOUBLE_ERROR__
			&& i >= __IS_ZERO_DOUBLE_ERROR__;
	}
#endif

#endif
