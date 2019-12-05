
/* Create macros so that the matrices are stored in column-major order */

#define A(i,j) a[ (j)*lda + (i) ]
#define B(i,j) b[ (j)*ldb + (i) ]
#define C(i,j) c[ (j)*ldc + (i) ]

/* Block sizes */
#define mc 256
#define kc 128

#define min( i, j ) ( (i)<(j) ? (i): (j) )

/* Routine for computing C = A * B + C */

void AddDot4x4( int, double *, int, double *, int, double *, int );

void MY_MMult( int m, int n, int k, double *a, int lda, 
                                    double *b, int ldb,
                                    double *c, int ldc )
{
  int i, j, p, pb, ib;

  /* This time, we compute a mc x n block of C by a call to the InnerKernel */

  for ( p=0; p<k; p+=kc ){
    pb = min( k-p, kc );
    for ( i=0; i<m; i+=mc ){
      ib = min( m-i, mc );
      InnerKernel( ib, n, pb, &A( i,p ), lda, &B(p, 0 ), ldb, &C( i,0 ), ldc );
    }
  }
}

void InnerKernel( int m, int n, int k, double *a, int lda, 
                                       double *b, int ldb,
                                       double *c, int ldc )
{
  int i, j;

  for ( j=0; j<n; j+=4 ){        /* Loop over the columns of C, unrolled by 4 */
    for ( i=0; i<m; i+=4 ){        /* Loop over the rows of C */
      /* Update C( i,j ), C( i,j+1 ), C( i,j+2 ), and C( i,j+3 ) in
	 one routine (four inner products) */

      AddDot4x4( k, &A( i,0 ), lda, &B( 0,j ), ldb, &C( i,j ), ldc );
    }
  }
}

#include <mmintrin.h>
#include <xmmintrin.h>  // SSE
#include <pmmintrin.h>  // SSE2
#include <emmintrin.h>  // SSE3
#include <immintrin.h>   //AVX

typedef union
{
  __m256d v;
  double d[4];
} v2df_t;

void AddDot4x4( int k, double *a, int lda,  double *b, int ldb, double *c, int ldc )
{
  /* So, this routine computes a 4x4 block of matrix A

           C( 0, 0 ), C( 0, 1 ), C( 0, 2 ), C( 0, 3 ).  
           C( 1, 0 ), C( 1, 1 ), C( 1, 2 ), C( 1, 3 ).  
           C( 2, 0 ), C( 2, 1 ), C( 2, 2 ), C( 2, 3 ).  
           C( 3, 0 ), C( 3, 1 ), C( 3, 2 ), C( 3, 3 ).  

     Notice that this routine is called with c = C( i, j ) in the
     previous routine, so these are actually the elements 

           C( i  , j ), C( i  , j+1 ), C( i  , j+2 ), C( i  , j+3 ) 
           C( i+1, j ), C( i+1, j+1 ), C( i+1, j+2 ), C( i+1, j+3 ) 
           C( i+2, j ), C( i+2, j+1 ), C( i+2, j+2 ), C( i+2, j+3 ) 
           C( i+3, j ), C( i+3, j+1 ), C( i+3, j+2 ), C( i+3, j+3 ) 
    
     in the original matrix C 

     And now we use vector registers and instructions */

  int p;

  v2df_t c_00_c_10_c_20_c_30_vreg;// column 0 of c
  v2df_t c_01_c_11_c_21_c_31_vreg;// column 1 of c
  v2df_t c_02_c_12_c_22_c_32_vreg;// column 2 of c
  v2df_t c_03_c_13_c_23_c_33_vreg;// colunm 3 of c
  v2df_t b_p0_vreg, b_p1_vreg, b_p2_vreg, b_p3_vreg; 

  v2df_t a_0p_a_1p_a_2p_a_3p;// one colunm of A
  double 
    /* Point to the current elements in the four columns of B */
    *b_p0_pntr, *b_p1_pntr, *b_p2_pntr, *b_p3_pntr; 
    
  b_p0_pntr = &B( 0, 0 );
  b_p1_pntr = &B( 0, 1 );
  b_p2_pntr = &B( 0, 2 );
  b_p3_pntr = &B( 0, 3 );


  c_00_c_10_c_20_c_30_vreg.v = _mm256_setzero_pd();   
  c_01_c_11_c_21_c_31_vreg.v = _mm256_setzero_pd();  
  c_02_c_12_c_22_c_32_vreg.v = _mm256_setzero_pd();  
  c_03_c_13_c_23_c_33_vreg.v = _mm256_setzero_pd();  


  for ( p=0; p<k; p++ ){
    a_0p_a_1p_a_2p_a_3p.v = _mm256_loadu_pd( (double *) &A( 0, p ) );

    b_p0_vreg.v = _mm256_broadcast_sd( (double *) b_p0_pntr++ ); 
    b_p1_vreg.v = _mm256_broadcast_sd( (double *) b_p1_pntr++ ); 
    b_p2_vreg.v = _mm256_broadcast_sd( (double *) b_p2_pntr++ ); 
    b_p3_vreg.v = _mm256_broadcast_sd( (double *) b_p3_pntr++ ); 
  
    c_00_c_10_c_20_c_30_vreg.v = _mm256_fmadd_pd (b_p0_vreg.v, a_0p_a_1p_a_2p_a_3p.v, c_00_c_10_c_20_c_30_vreg.v);
    c_01_c_11_c_21_c_31_vreg.v = _mm256_fmadd_pd (b_p1_vreg.v, a_0p_a_1p_a_2p_a_3p.v, c_01_c_11_c_21_c_31_vreg.v);
    c_02_c_12_c_22_c_32_vreg.v = _mm256_fmadd_pd (b_p2_vreg.v, a_0p_a_1p_a_2p_a_3p.v, c_02_c_12_c_22_c_32_vreg.v);
    c_03_c_13_c_23_c_33_vreg.v = _mm256_fmadd_pd (b_p3_vreg.v, a_0p_a_1p_a_2p_a_3p.v, c_03_c_13_c_23_c_33_vreg.v);
  }

  C( 0, 0 ) += c_00_c_10_c_20_c_30_vreg.d[0];
  C( 1, 0 ) += c_00_c_10_c_20_c_30_vreg.d[1];
  C( 2, 0 ) += c_00_c_10_c_20_c_30_vreg.d[2];
  C( 3, 0 ) += c_00_c_10_c_20_c_30_vreg.d[3];

  C( 0, 1 ) += c_01_c_11_c_21_c_31_vreg.d[0];
  C( 1, 1 ) += c_01_c_11_c_21_c_31_vreg.d[1];
  C( 2, 1 ) += c_01_c_11_c_21_c_31_vreg.d[2];
  C( 3, 1 ) += c_01_c_11_c_21_c_31_vreg.d[3];

  C( 0, 2 ) += c_02_c_12_c_22_c_32_vreg.d[0];
  C( 1, 2 ) += c_02_c_12_c_22_c_32_vreg.d[1];
  C( 2, 2 ) += c_02_c_12_c_22_c_32_vreg.d[2];
  C( 3, 2 ) += c_02_c_12_c_22_c_32_vreg.d[3];

  C( 0, 3 ) += c_03_c_13_c_23_c_33_vreg.d[0];
  C( 1, 3 ) += c_03_c_13_c_23_c_33_vreg.d[1];
  C( 2, 3 ) += c_03_c_13_c_23_c_33_vreg.d[2];
  C( 3, 3 ) += c_03_c_13_c_23_c_33_vreg.d[3];
}
