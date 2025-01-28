/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nthroot.c
 *
 * Code generation for function 'nthroot'
 *
 */

/* Include files */
#include "nthroot.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = {
    7,         /* lineNo */
    "nthroot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "scalar\\nthroot.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    9,         /* lineNo */
    "nthroot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "scalar\\nthroot.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    12,        /* lineNo */
    "nthroot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "scalar\\nthroot.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI =
    {
        71,      /* lineNo */
        "power", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

static emlrtRTEInfo e_emlrtRTEI =
    {
        82,         /* lineNo */
        5,          /* colNo */
        "fltpower", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pName
                                                                          */
};

/* Function Definitions */
real_T nthroot(const emlrtStack *sp, real_T x, real_T n)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (x < 0.0) {
    st.site = &r_emlrtRSI;
    y = -muDoubleScalarPower(-x, 1.0 / n);
  } else {
    st.site = &s_emlrtRSI;
    y = muDoubleScalarPower(x, 1.0 / n);
  }
  if ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y)) &&
      ((!muDoubleScalarIsInf(n)) && (!muDoubleScalarIsNaN(n))) && (x != 0.0)) {
    real_T d;
    real_T y2n;
    st.site = &t_emlrtRSI;
    b_st.site = &u_emlrtRSI;
    if ((y < 0.0) && (muDoubleScalarFloor(n) != n)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                    "Coder:toolbox:power_domainError",
                                    "Coder:toolbox:power_domainError", 0);
    }
    y2n = muDoubleScalarPower(y, n);
    d = y2n - x;
    if (d != 0.0) {
      y -= d / (n * (y2n / y));
    }
  }
  return y;
}

/* End of code generation (nthroot.c) */
