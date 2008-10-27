/*
 * Copyright (c) 1985, 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)math.h	5.8 (Berkeley) 4/2/91
 */

#ifndef	_MATH_H_
#define	_MATH_H_

#include <float.h>

#ifndef BITS
#define BITS(type)	(8 * (int)sizeof(type))
#endif

#define	M_E		2.7182818284590452354	/* e */
#define	M_LOG2E		1.4426950408889634074	/* log 2e */
#define	M_LOG10E	0.43429448190325182765	/* log 10e */
#define	M_LN2		0.69314718055994530942	/* log e2 */
#define	M_LN10		2.30258509299404568402	/* log e10 */
#define	M_PI		3.14159265358979323846	/* pi */
#define	M_PI_2		1.57079632679489661923	/* pi/2 */
#define	M_PI_4		0.78539816339744830962	/* pi/4 */
#define	M_1_PI		0.31830988618379067154	/* 1/pi */
#define	M_2_PI		0.63661977236758134308	/* 2/pi */
#define	M_2_SQRTPI	1.12837916709551257390	/* 2/sqrt(pi) */
#define	M_SQRT2		1.41421356237309504880	/* sqrt(2) */
#define	M_SQRT1_2	0.70710678118654752440	/* 1/sqrt(2) */

#include <sys/cdefs.h>

enum fdversion {fdlibm_ieee = -1, fdlibm_svid, fdlibm_xopen, fdlibm_posix};

#define _LIB_VERSION_TYPE enum fdversion
#define _LIB_VERSION _fdlib_version  

/* if global variable _LIB_VERSION is not desirable, one may 
 * change the following to be a constant by: 
 *	#define _LIB_VERSION_TYPE const enum version
 * In that case, after one initializes the value _LIB_VERSION (see
 * s_lib_version.c) during compile time, it cannot be modified
 * in the middle of a program
 */ 
__BEGIN_DECLS
 _LIB_VERSION_TYPE  _LIB_VERSION;
__END_DECLS

#define _IEEE_  fdlibm_ieee
#define _SVID_  fdlibm_svid
#define _XOPEN_ fdlibm_xopen
#define _POSIX_ fdlibm_posix

struct exception {
	int type;
	char *name;
	double arg1;
	double arg2;
	double retval;
};

/* 
 * set X_TLOSS = pi*2**52, which is possibly defined in <values.h>
 * (one may replace the following line by "#include <values.h>")
 */

#define X_TLOSS		1.41484755040568800000e+16 

#define	DOMAIN		1
#define	SING		2
#define	OVERFLOW	3
#define	UNDERFLOW	4
#define	TLOSS		5
#define	PLOSS		6

__BEGIN_DECLS
int matherr __P((struct exception *));

int signgam;

double erf __P((double));
double erfc __P((double));
double gamma __P((double));
int isnan __P((double));
int finite __P((double));
double j0 __P((double));
double j1 __P((double));
double jn __P((int, double));
double lgamma __P((double));
double y0 __P((double));
double y1 __P((double));
double yn __P((int, double));
double acosh __P((double));
double asinh __P((double));
double cbrt __P((double));
double nextafter __P((double, double));
double remainder __P((double, double));
double significand __P((double));
double copysign __P((double, double));
int ilogb __P((double));
double scalbn __P((double, int));
/*
 * Reentrant version of gamma & lgamma; passes signgam back by reference
 * as the second argument; user must allocate space for signgam.
 */
#ifdef _REENTRANT
double gamma_r __P((double, int *));
double lgamma_r __P((double, int *));
#endif	/* _REENTRANT */

/* ieee style elementary functions */
double __ieee754_sqrt __P((double));			
double __ieee754_acos __P((double));			
double __ieee754_acosh __P((double));			
double __ieee754_log __P((double));			
double __ieee754_atanh __P((double));			
double __ieee754_asin __P((double));			
double __ieee754_atan2 __P((double,double));			
double __ieee754_exp __P((double));
double __ieee754_cosh __P((double));
double __ieee754_fmod __P((double,double));
double __ieee754_pow __P((double,double));
double __ieee754_lgamma_r __P((double,int *));
double __ieee754_gamma_r __P((double,int *));
double __ieee754_lgamma __P((double));
double __ieee754_gamma __P((double));
double __ieee754_log10 __P((double));
double __ieee754_sinh __P((double));
double __ieee754_hypot __P((double,double));
double __ieee754_j0 __P((double));
double __ieee754_j1 __P((double));
double __ieee754_y0 __P((double));
double __ieee754_y1 __P((double));
double __ieee754_jn __P((int,double));
double __ieee754_yn __P((int,double));
double __ieee754_remainder __P((double,double));
int    __ieee754_rem_pio2 __P((double,double*));
#define _SCALB_INT
#ifdef _SCALB_INT
double __ieee754_scalb __P((double,int));
#else
double __ieee754_scalb __P((double,double));
#endif

/* fdlibm kernel function */
double __kernel_standard __P((double,double,int));	
double __kernel_sin __P((double,double,int));
double __kernel_cos __P((double,double));
double __kernel_tan __P((double,double,int));
int    __kernel_rem_pio2 __P((double*,double*,int,int,int,const int*));
__END_DECLS

#if (defined(__GNUC__) || defined(__cplusplus)) && defined(__HAVE_68881__)
#include <math-68881.h>
#else

#define	HUGE_VAL	1e500			/* IEEE: positive infinity */

/*
 * ANSI/POSIX
 */

#define	HUGE	((float)3.40282346638528860e+38)

__BEGIN_DECLS
double acos __P((double));
double asin __P((double));
double atan __P((double));
double atan2 __P((double, double));
double cos __P((double));
double sin __P((double));
double tan __P((double));
double cosh __P((double));
double sinh __P((double));
double tanh __P((double));
double exp __P((double));
double frexp __P((double, int *));
double ldexp __P((double, int));
double log __P((double));
double log10 __P((double));
double modf __P((double, double *));
double pow __P((double, double));
double sqrt __P((double));
double ceil __P((double));
double fabs __P((double));
double floor __P((double));
double fmod __P((double, double));
double hypot __P((double, double));
double atanh __P((double));
double logb __P((double));
#ifdef _SCALB_INT
double scalb __P((double, int));
#else
double scalb __P((double, double));
#endif
double rint __P((double));
double expm1 __P((double));
double log1p __P((double));
__END_DECLS

#endif /* __HAVE_68881__ */

__BEGIN_DECLS
/* These functions are defined in ixemul */
int     isinf __P((double));
int     isnan __P((double));
/* This function had a different name in the old libm.a */
#define drem remainder
/* These functions are missing from the library, but were defined
   in the older libm.a */
double  cabs();		/* we can't describe cabs()'s argument properly */
__END_DECLS

#endif /* _MATH_H_ */
