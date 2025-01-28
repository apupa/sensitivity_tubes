/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "norm.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = {
    119,    /* lineNo */
    "norm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" /* pathName
                                                                        */
};

static emlrtRSInfo x_emlrtRSI = {
    156,        /* lineNo */
    "mat2norm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" /* pathName
                                                                        */
};

static emlrtRSInfo y_emlrtRSI = {
    28,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo ab_emlrtRSI = {
    107,          /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo bb_emlrtRSI = {
    31,       /* lineNo */
    "xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    205,            /* lineNo */
    "ceval_xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    111,          /* lineNo */
    5,            /* colNo */
    "callLAPACK", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo g_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

/* Function Definitions */
real_T b_norm(const emlrtStack *sp, const real_T x[144])
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 's', 'v', 'd'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T A[144];
  real_T s[12];
  real_T superb[11];
  real_T y;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &w_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  y = 0.0;
  for (i = 0; i < 144; i++) {
    real_T absx;
    absx = muDoubleScalarAbs(x[i]);
    if (muDoubleScalarIsNaN(absx) || (absx > y)) {
      y = absx;
    }
  }
  if ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y))) {
    ptrdiff_t info_t;
    b_st.site = &x_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    d_st.site = &ab_emlrtRSI;
    e_st.site = &bb_emlrtRSI;
    memcpy(&A[0], &x[0], 144U * sizeof(real_T));
    info_t = LAPACKE_dgesvd(102, 'N', 'N', (ptrdiff_t)12, (ptrdiff_t)12, &A[0],
                            (ptrdiff_t)12, &s[0], NULL, (ptrdiff_t)1, NULL,
                            (ptrdiff_t)1, &superb[0]);
    f_st.site = &cb_emlrtRSI;
    if ((int32_T)info_t < 0) {
      if ((int32_T)info_t == -1010) {
        emlrtErrorWithMessageIdR2018a(&f_st, &g_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&f_st, &h_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      14, &fname[0], 12, (int32_T)info_t);
      }
    }
    if ((int32_T)info_t > 0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    }
    y = s[0];
  }
  return y;
}

/* End of code generation (norm.c) */
