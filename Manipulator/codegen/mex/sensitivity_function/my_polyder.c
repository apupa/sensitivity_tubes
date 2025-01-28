/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * my_polyder.c
 *
 * Code generation for function 'my_polyder'
 *
 */

/* Include files */
#include "my_polyder.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "sensitivity_function_data.h"
#include "sensitivity_function_emxutil.h"
#include "sensitivity_function_types.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = {
    4,            /* lineNo */
    "my_polyder", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\my_polyder.m" /* pathName */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    4,            /* lineNo */
    13,           /* colNo */
    "da",         /* aName */
    "my_polyder", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\my_polyder.m", /* pName */
    0                                      /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    4,            /* lineNo */
    15,           /* colNo */
    "da",         /* aName */
    "my_polyder", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\my_polyder.m", /* pName */
    0                                      /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    7,            /* lineNo */
    19,           /* colNo */
    "a",          /* aName */
    "my_polyder", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\my_polyder.m", /* pName */
    0                                      /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    7,            /* lineNo */
    12,           /* colNo */
    "da",         /* aName */
    "my_polyder", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\my_polyder.m", /* pName */
    0                                      /* checkKind */
};

static emlrtRTEInfo x_emlrtRTEI = {
    4,            /* lineNo */
    5,            /* colNo */
    "my_polyder", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\my_polyder.m" /* pName */
};

/* Function Definitions */
void my_polyder(const emlrtStack *sp, const emxArray_real_T *a,
                emxArray_real_T *da)
{
  emlrtStack st;
  const real_T *a_data;
  real_T *da_data;
  int32_T iv[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  a_data = a->data;
  if (a->size[0] - 1 < 1) {
    loop_ub = 0;
  } else {
    if (a->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, a->size[0], &g_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((a->size[0] - 1 < 1) || (a->size[0] - 1 > a->size[0])) {
      emlrtDynamicBoundsCheckR2012b(a->size[0] - 1, 1, a->size[0], &h_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = a->size[0] - 1;
  }
  iv[0] = 1;
  iv[1] = loop_ub;
  st.site = &j_emlrtRSI;
  indexShapeCheck(&st, a->size[0], iv);
  i = da->size[0];
  da->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, da, i, &x_emlrtRTEI);
  da_data = da->data;
  for (i = 0; i < loop_ub; i++) {
    da_data[i] = a_data[i];
  }
  /*      da = zeros(n-1,1); */
  i = a->size[0];
  for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
    if (loop_ub + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i, &i_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (loop_ub + 1 > da->size[0]) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, da->size[0], &j_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    da_data[loop_ub] = a_data[loop_ub] * (real_T)((a->size[0] - loop_ub) - 1);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

/* End of code generation (my_polyder.c) */
