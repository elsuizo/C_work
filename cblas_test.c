/*
 * Author:  Nicu Tofan
 * License: BSD
 *
 * See below for getRealTime() license.
 */


#include <cblas.h>

#include <stdlib.h>
#include <stdio.h>

#define test_m          2
#define test_k          3
#define test_n          4
#define test_m_extra    5
#define test_k_extra    7
#define test_n_extra    8

#define test_row_major  1
#define test_col_major  0


double getRealTime();


//! prints a matrix in either row major or column major order
static void printMatrix (double *data, int rows, int cols, int row_major)
{
    int i,j;

    // column header
    printf ("        ");
    for(j=0; j<cols;j++) {
        printf (" Col %2d  ", j+1);
    }
    printf ("\n");

    for(i=0; i<rows;i++) {
        printf ("Row %2d: ", i+1);
        for(j=0; j<cols;j++) {
            if (row_major) {
                printf ("%7.4f  ", data[i*cols+j]);
            } else {
                printf ("%7.4f  ", data[j*rows+i]);
            }
        }
        printf ("\n");
    }
    printf ("\n--------------------------------------------------------\n\n");
}

//! test printMatrix() to make sure it works
static void testPrintMatrix()
{
    printf ("==========================================================\n");
    printf ("Test print function\n");
    printf ("==========================================================\n\n");

    printf ("Matrix in row major order\n\n");
    double A[2*3] = {
        1, 2, 3,
        4, 5, 6
    };
    printMatrix (A, 2, 3, test_row_major);

    printf ("Matrix in column major order\n\n");
    double B[2*3] = {
        1, 4,
        2, 5,
        3, 6
    };
    printMatrix (B, 2, 3, test_col_major);
}


//! testing the extra-space
static void testMulColMajorExtraSpace()
{
    printf ("==========================================================\n");
    printf ("Extra space in matrix not used in ops\n");
    printf ("==========================================================\n\n");

    /*          MATRIX A[2x3]

                Col  1  Col  2  Col  3
        Row  1: 1.0000  2.0000  3.0000
        Row  2: 4.0000  5.0000  6.0000

    */

    printf ("A\n\n");
    double A[] = {
        1, 4, 9, 9, 9, // 9's will not affect the computation
        2, 5, 9, 9, 9,
        3, 6, 9, 9, 9
    };
    printMatrix (A, test_m_extra, test_k, test_col_major);

    /*          MATRIX B[3x4]

                Col  1  Col  2  Col  3  Col  4
        Row  1: 1.0000  2.0000  3.0000  4.0000
        Row  2: 0.1000  0.2000  0.3000  0.4000
        Row  3: 0.0100  0.0200  0.0300  0.0400

    */
    printf ("B\n\n");
    double B[] = {
        1.0, 0.1, 0.01, 9.0, 9.0, 9.0, 9.0, // 9's will not affect the computation
        2.0, 0.2, 0.02, 9.0, 9.0, 9.0, 9.0,
        3.0, 0.3, 0.03, 9.0, 9.0, 9.0, 9.0,
        4.0, 0.4, 0.04, 9.0, 9.0, 9.0, 9.0,
    };
    printMatrix (B, test_k_extra, test_n, test_col_major);

    /*          MATRIX C[2x4]

                Col  1  Col  2  Col  3  Col  4
        Row  1:  1.2300  2.4600  3.6900  4.9200
        Row  2:  4.5600  9.1200 13.6800 18.2400
    */
    double C[test_n_extra*test_n] = {0};

    printf ("C\n\n");
    // C = alpha*A*B+beta*C
    cblas_dgemm(
          CblasColMajor,
          CblasNoTrans, // TRANSA:
          CblasNoTrans, // TRANSB:
          test_m,   // A matrix: m rows, k columns
          test_n,   // B matrix: k rows, n columns
          test_k,   // C matrix: m rows, n columns
          1.0,      // alpha = 1.0
          A,        // A source matrix
          test_m_extra,   // true lenght of a column in A
                    //   if TRANSA = 'N' then >= m
                    //   if TRANSA = 'T' then >= k
          B,        // B source matrix
          test_k_extra,   // true lenght of a column in B
                    //   if TRANSB = 'N' then >= k
                    //   if TRANSB = 'T' then >= n
          0.0,      // beta = 0.0
          C,        // C destination matrix
          test_n_extra);  // true lenght of a row in C
                    //   must be >= m
    printMatrix (C, test_n_extra, test_n, test_col_major);
}

//! blas expects column major order
static void testMulColMajor()
{
    printf ("==========================================================\n");
    printf ("Test BLAS multiply - column major order\n");
    printf ("==========================================================\n\n");

    /*          MATRIX A[2x3]

                Col  1  Col  2  Col  3
        Row  1: 1.0000  2.0000  3.0000
        Row  2: 4.0000  5.0000  6.0000

    */

    printf ("A\n\n");
    double A[test_m*test_k] = {
        1, 4,
        2, 5,
        3, 6
    };
    printMatrix (A, test_m, test_k, test_col_major);

    /*          MATRIX B[3x4]

                Col  1  Col  2  Col  3  Col  4
        Row  1: 1.0000  2.0000  3.0000  4.0000
        Row  2: 0.1000  0.2000  0.3000  0.4000
        Row  3: 0.0100  0.0200  0.0300  0.0400

    */
    printf ("B\n\n");
    double B[test_k*test_n] = {
        1.0, 0.1, 0.01,
        2.0, 0.2, 0.02,
        3.0, 0.3, 0.03,
        4.0, 0.4, 0.04
    };
    printMatrix (B, test_k, test_n, test_col_major);

    /*          MATRIX C[2x4]

                Col  1  Col  2  Col  3  Col  4
        Row  1:  1.2300  2.4600  3.6900  4.9200
        Row  2:  4.5600  9.1200 13.6800 18.2400
    */
    double C[test_m*test_n] = {0};

    printf ("C\n\n");
    // http://www.math.utah.edu/software/lapack/lapack-blas/dgemm.html
    /*
    cblas_dgemm(
          'N',      // TRANSA: N - do not transpose A, T - transpose A
          'N',      // TRANSB: N - do not transpose A, T - transpose A
          test_m,   // A matrix: m rows, k columns
          test_n,   // B matrix: k rows, n columns
          test_k,   // C matrix: m rows, n columns
          1.0,      // alpha = 1.0
          A,        // A source matrix
          test_m,   // true lenght of a column in A
                    //   if TRANSA = 'N' then >= m
                    //   if TRANSA = 'T' then >= k
          B,        // B source matrix
          test_k,   // true lenght of a column in B
                    //   if TRANSB = 'N' then >= k
                    //   if TRANSB = 'T' then >= n
          0.0,      // beta = 0.0
          C,        // C destination matrix
          test_m);  // true lenght of a row in C
                    //   must be >= m
                    */
    // C = alpha*A*B+beta*C
    cblas_dgemm(
          CblasColMajor,
          CblasNoTrans, // TRANSA:
          CblasNoTrans, // TRANSB:
          test_m,   // A matrix: m rows, k columns
          test_n,   // B matrix: k rows, n columns
          test_k,   // C matrix: m rows, n columns
          1.0,      // alpha = 1.0
          A,        // A source matrix
          test_m,   // true lenght of a column in A
                    //   if TRANSA = 'N' then >= m
                    //   if TRANSA = 'T' then >= k
          B,        // B source matrix
          test_k,   // true lenght of a column in B
                    //   if TRANSB = 'N' then >= k
                    //   if TRANSB = 'T' then >= n
          0.0,      // beta = 0.0
          C,        // C destination matrix
          test_m);  // true lenght of a row in C
                    //   must be >= m
    printMatrix (C, test_m, test_n, test_col_major);
}

//! attempt the trickery
static void testMulRowMajor_trickery()
{
    printf ("==========================================================\n");
    printf ("Test BLAS multiply - row major order with trickery\n");
    printf ("==========================================================\n\n");

    /*          MATRIX A[2x3]

                Col  1  Col  2  Col  3
        Row  1: 1.0000  2.0000  3.0000
        Row  2: 4.0000  5.0000  6.0000

    */

    printf ("A\n\n");
    double A[test_m*test_k] = {
        1, 2, 3,
        4, 5, 6
    };
    printMatrix (A, test_m, test_k, test_row_major);

    /*          MATRIX B[3x4]

                Col  1  Col  2  Col  3  Col  4
        Row  1: 1.0000  2.0000  3.0000  4.0000
        Row  2: 0.1000  0.2000  0.3000  0.4000
        Row  3: 0.0100  0.0200  0.0300  0.0400

    */
    printf ("B\n\n");
    double B[test_k*test_n] = {
        1.00, 2.00, 3.00, 4.00,
        0.10, 0.20, 0.30, 0.40,
        0.01, 0.02, 0.03, 0.04
    };
    printMatrix (B, test_k, test_n, test_row_major);

    /*          MATRIX C[2x4]

                Col  1  Col  2  Col  3  Col  4
        Row  1:  1.2300  2.4600  3.6900  4.9200
        Row  2:  4.5600  9.1200 13.6800 18.2400
    */
    double C[test_m*test_n] = {0};

    printf ("C\n\n");

    // C = alpha*A*B+beta*C
    cblas_dgemm(
        CblasColMajor,
        CblasNoTrans, // TRANSA:
        CblasNoTrans, // TRANSB:
        test_n,   // B matrix: k rows, n columns
        test_m,   // A matrix: m rows, k columns
        test_k,   // C matrix: m rows, n columns
        1.0,      // alpha = 1.0
        B,        // B source matrix
        test_n,   // true lenght of a column in B
                  //   if TRANSB = 'N' then >= k
                  //   if TRANSB = 'T' then >= n
        A,        // A source matrix
        test_k,   // true lenght of a column in A
                  //   if TRANSA = 'N' then >= m
                  //   if TRANSA = 'T' then >= k
        0.0,      // beta = 0.0
        C,        // C destination matrix
        test_n);  // true lenght of a row in C
                  //   must be >= m
    printMatrix (C, test_m, test_n, test_row_major);
}

//! build in version
static void testMulRowMajor()
{
    printf ("==========================================================\n");
    printf ("Test BLAS multiply - row major order without trickery\n");
    printf ("==========================================================\n\n");

    /*          MATRIX A[2x3]

                Col  1  Col  2  Col  3
        Row  1: 1.0000  2.0000  3.0000
        Row  2: 4.0000  5.0000  6.0000

    */

    printf ("A\n\n");
    double A[test_m*test_k] = {
        1, 2, 3,
        4, 5, 6
    };
    printMatrix (A, test_m, test_k, test_row_major);

    /*          MATRIX B[3x4]

                Col  1  Col  2  Col  3  Col  4
        Row  1: 1.0000  2.0000  3.0000  4.0000
        Row  2: 0.1000  0.2000  0.3000  0.4000
        Row  3: 0.0100  0.0200  0.0300  0.0400

    */
    printf ("B\n\n");
    double B[test_k*test_n] = {
        1.00, 2.00, 3.00, 4.00,
        0.10, 0.20, 0.30, 0.40,
        0.01, 0.02, 0.03, 0.04
    };
    printMatrix (B, test_k, test_n, test_row_major);

    /*          MATRIX C[2x4]

                Col  1  Col  2  Col  3  Col  4
        Row  1:  1.2300  2.4600  3.6900  4.9200
        Row  2:  4.5600  9.1200 13.6800 18.2400
    */
    double C[test_m*test_n] = {0};

    printf ("C\n\n");

    // C = alpha*A*B+beta*C
    cblas_dgemm(
          CblasRowMajor,
          CblasNoTrans, // TRANSA:
          CblasNoTrans, // TRANSB:
          test_m,   // A matrix: m rows, k columns
          test_n,   // B matrix: k rows, n columns
          test_k,   // C matrix: m rows, n columns
          1.0,      // alpha = 1.0
          A,        // A source matrix
          test_k,   // true lenght of a column in A
                    //   if TRANSA = 'N' then >= m
                    //   if TRANSA = 'T' then >= k
          B,        // B source matrix
          test_n,   // true lenght of a column in B
                    //   if TRANSB = 'N' then >= k
                    //   if TRANSB = 'T' then >= n
          0.0,      // beta = 0.0
          C,        // C destination matrix
          test_n);  // true lenght of a row in C
                    //   must be >= m
    printMatrix (C, test_m, test_n, test_col_major);
}

#undef test_m
#undef test_n
#undef test_k

#define test_m          500
#define test_k          600
#define test_n          700

#define test_spins      5

// ---------------------------------------------------------------------
#define IMPLEMENTATION_ROW_MAJOR \
    cblas_dgemm( \
                CblasRowMajor, CblasNoTrans, CblasNoTrans, test_m, test_n, \
                test_k, 1.0, A, test_k, B, test_n, 0.0, C, test_n); \
    startTime = getRealTime (); \
    for(i=0; i<test_spins;i++) { \
        cblas_dgemm( \
                    CblasRowMajor, CblasNoTrans, CblasNoTrans, test_m, test_n, \
                    test_k, 1.0, A, test_k, B, test_n, 0.0, C, test_n); \
    } \
    endTime = getRealTime (); \
    printf ("- Build-in implementation - row major (%d) = %lf\n", test_spins, (endTime - startTime) );
// ---------------------------------------------------------------------
#define IMPLEMENTATION_TRICKERY \
    cblas_dgemm( \
                CblasColMajor, CblasNoTrans, CblasNoTrans, test_n, test_m, \
                test_k, 1.0, B, test_n, A, test_k, 0.0, C, test_n); \
    startTime = getRealTime (); \
    for(i=0; i<test_spins;i++) { \
        cblas_dgemm( \
                    CblasColMajor, CblasNoTrans, CblasNoTrans, test_n, test_m, \
                    test_k, 1.0, B, test_n, A, test_k, 0.0, C, test_n); \
    } \
    endTime = getRealTime (); \
    printf ("- Trickery implementation (%d)= %lf\n", test_spins, (endTime - startTime) );
// ---------------------------------------------------------------------
#define IMPLEMENTATION_COL_MAJOR \
    cblas_dgemm( \
                CblasColMajor, CblasNoTrans, CblasNoTrans, test_m, test_n, \
                test_k, 1.0, A, test_m, B, test_k, 0.0, C, test_m); \
    startTime = getRealTime (); \
    for(i=0; i<test_spins;i++) { \
        cblas_dgemm( \
                    CblasColMajor, CblasNoTrans, CblasNoTrans, test_m, test_n, \
                    test_k, 1.0, A, test_m, B, test_k, 0.0, C, test_m); \
    } \
    endTime = getRealTime (); \
    printf ("- Build-in implementation - column major (%d) = %lf\n", test_spins, (endTime - startTime) );
// ---------------------------------------------------------------------


//! test my undestanding of the parameters
void compareBuildInWithTrickery()
{

    printf ("==========================================================\n");
    printf ("Compare these two methods\n");
    printf ("==========================================================\n\n");

    // srand((unsigned)time(NULL));

    double startTime, endTime;
    int i;

    double *A = (double*)malloc(test_m*test_k*sizeof(double));
    int a_tot = test_m*test_k;
    double *iter = A;
    for (i = 0; i<a_tot; i++) {
        *iter = ((double)rand()/(double)RAND_MAX);;
        iter++;
    }

    double *B = (double*)malloc(test_k*test_n*sizeof(double));
    int b_tot = test_k*test_n;
    iter = B;
    for (i = 0; i<b_tot; i++) {
        *iter = ((double)rand()/(double)RAND_MAX);;
        iter++;
    }

    double *C = (double*)malloc(test_m*test_n*sizeof(double));
    iter = C;
    int c_tot = test_m*test_n;
    for (i = 0; i<c_tot; i++) {
        *iter = 0.0;
        iter++;
    }

    IMPLEMENTATION_ROW_MAJOR;
    IMPLEMENTATION_TRICKERY;
    IMPLEMENTATION_COL_MAJOR;

    IMPLEMENTATION_TRICKERY;
    IMPLEMENTATION_ROW_MAJOR;
    IMPLEMENTATION_COL_MAJOR;

    IMPLEMENTATION_ROW_MAJOR;
    IMPLEMENTATION_COL_MAJOR;
    IMPLEMENTATION_TRICKERY;

    IMPLEMENTATION_COL_MAJOR;
    IMPLEMENTATION_ROW_MAJOR;
    IMPLEMENTATION_TRICKERY;

    IMPLEMENTATION_COL_MAJOR;
    IMPLEMENTATION_TRICKERY;
    IMPLEMENTATION_ROW_MAJOR;

    IMPLEMENTATION_TRICKERY;
    IMPLEMENTATION_COL_MAJOR;
    IMPLEMENTATION_ROW_MAJOR;

}


int main(int argc, char **argv)
{
    testPrintMatrix();
    testMulColMajorExtraSpace();
    testMulColMajor();
    testMulRowMajor_trickery();
    testMulRowMajor();

    compareBuildInWithTrickery();

    return 0;
}






/*
 * Author:  David Robert Nadeau
 * Site:    http://NadeauSoftware.com/
 * License: Creative Commons Attribution 3.0 Unported License
 *          http://creativecommons.org/licenses/by/3.0/deed.en_US
 *
 * http://nadeausoftware.com/articles/2012/04/c_c_tip_how_measure_elapsed_real_time_benchmarking
 */
#if defined(_WIN32)
#include <Windows.h>

#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
#include <unistd.h>	/* POSIX flags */
#include <time.h>	/* clock_gettime(), time() */
#include <sys/time.h>	/* gethrtime(), gettimeofday() */

#if defined(__MACH__) && defined(__APPLE__)
#include <mach/mach.h>
#include <mach/mach_time.h>
#endif

#else
#error "Unable to define getRealTime( ) for an unknown OS."
#endif





/**
 * Returns the real time, in seconds, or -1.0 if an error occurred.
 *
 * Time is measured since an arbitrary and OS-dependent start time.
 * The returned real time is only useful for computing an elapsed time
 * between two calls to this function.
 */
double getRealTime( )
{
#if defined(_WIN32)
    FILETIME tm;
    ULONGLONG t;
#if defined(NTDDI_WIN8) && NTDDI_VERSION >= NTDDI_WIN8
    /* Windows 8, Windows Server 2012 and later. ---------------- */
    GetSystemTimePreciseAsFileTime( &tm );
#else
    /* Windows 2000 and later. ---------------------------------- */
    GetSystemTimeAsFileTime( &tm );
#endif
    t = ((ULONGLONG)tm.dwHighDateTime << 32) | (ULONGLONG)tm.dwLowDateTime;
    return (double)t / 10000000.0;

#elif (defined(__hpux) || defined(hpux)) || ((defined(__sun__) || defined(__sun) || defined(sun)) && (defined(__SVR4) || defined(__svr4__)))
    /* HP-UX, Solaris. ------------------------------------------ */
    return (double)gethrtime( ) / 1000000000.0;

#elif defined(__MACH__) && defined(__APPLE__)
    /* OSX. ----------------------------------------------------- */
    static double timeConvert = 0.0;
    if ( timeConvert == 0.0 )
    {
        mach_timebase_info_data_t timeBase;
        (void)mach_timebase_info( &timeBase );
        timeConvert = (double)timeBase.numer /
            (double)timeBase.denom /
            1000000000.0;
    }
    return (double)mach_absolute_time( ) * timeConvert;

#elif defined(_POSIX_VERSION)
    /* POSIX. --------------------------------------------------- */
#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0)
    {
        struct timespec ts;
#if defined(CLOCK_MONOTONIC_PRECISE)
        /* BSD. --------------------------------------------- */
        const clockid_t id = CLOCK_MONOTONIC_PRECISE;
#elif defined(CLOCK_MONOTONIC_RAW)
        /* Linux. ------------------------------------------- */
        const clockid_t id = CLOCK_MONOTONIC_RAW;
#elif defined(CLOCK_HIGHRES)
        /* Solaris. ----------------------------------------- */
        const clockid_t id = CLOCK_HIGHRES;
#elif defined(CLOCK_MONOTONIC)
        /* AIX, BSD, Linux, POSIX, Solaris. ----------------- */
        const clockid_t id = CLOCK_MONOTONIC;
#elif defined(CLOCK_REALTIME)
        /* AIX, BSD, HP-UX, Linux, POSIX. ------------------- */
        const clockid_t id = CLOCK_REALTIME;
#else
        const clockid_t id = (clockid_t)-1;	/* Unknown. */
#endif /* CLOCK_* */
        if ( id != (clockid_t)-1 && clock_gettime( id, &ts ) != -1 )
            return (double)ts.tv_sec +
                (double)ts.tv_nsec / 1000000000.0;
        /* Fall thru. */
    }
#endif /* _POSIX_TIMERS */

    /* AIX, BSD, Cygwin, HP-UX, Linux, OSX, POSIX, Solaris. ----- */
    struct timeval tm;
    gettimeofday( &tm, NULL );
    return (double)tm.tv_sec + (double)tm.tv_usec / 1000000.0;
#else
    return -1.0;		/* Failed. */
#endif
}

