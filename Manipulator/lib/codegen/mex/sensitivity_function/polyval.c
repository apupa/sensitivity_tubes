/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polyval.c
 *
 * Code generation for function 'polyval'
 *
 */

/* Include files */
#include "polyval.h"
#include "rt_nonfinite.h"
#include "sensitivity_function_emxutil.h"
#include "sensitivity_function_types.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRTEInfo u_emlrtRTEI = {
    33,        /* lineNo */
    20,        /* colNo */
    "polyval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" /* pName
                                                                            */
};

static emlrtRTEInfo v_emlrtRTEI = {
    37,        /* lineNo */
    5,         /* colNo */
    "polyval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" /* pName
                                                                            */
};

static emlrtRTEInfo w_emlrtRTEI = {
    39,        /* lineNo */
    9,         /* colNo */
    "polyval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" /* pName
                                                                            */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    39,        /* lineNo */
    13,        /* colNo */
    "polyval", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" /* pName
                                                                            */
};

static emlrtRSInfo jb_emlrtRSI = {
    39,        /* lineNo */
    "polyval", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" /* pathName
                                                                            */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emxArray_real_T *in2,
                             const emxArray_real_T *in3, int32_T in4);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emxArray_real_T *in2,
                             const emxArray_real_T *in3, int32_T in4)
{
  emxArray_real_T *b_in2;
  const real_T *in2_data;
  const real_T *in3_data;
  real_T b_in3;
  real_T *b_in2_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  b_in3 = in3_data[in4 + 1];
  emxInit_real_T(sp, &b_in2, 2, &ab_emlrtRTEI);
  i = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = 1;
  if (in1->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in1->size[1];
  }
  b_in2->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in2, i, &ab_emlrtRTEI);
  b_in2_data = b_in2->data;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in1->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_1] * in1_data[i * stride_1_1] + b_in3;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &ab_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in2_data[i];
  }
  emxFree_real_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void polyval(const emlrtStack *sp, const emxArray_real_T *p,
             const emxArray_real_T *x, emxArray_real_T *y)
{
  emlrtStack st;
  const real_T *p_data;
  const real_T *x_data;
  real_T *y_data;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T y_idx_1;
  st.prev = sp;
  st.tls = sp->tls;
  x_data = x->data;
  p_data = p->data;
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y_idx_1 = x->size[1];
  y->size[1] = x->size[1];
  emxEnsureCapacity_real_T(sp, y, i, &u_emlrtRTEI);
  if ((x->size[1] != 0) && (p->size[0] != 0)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(sp, y, i, &v_emlrtRTEI);
    y_data = y->data;
    for (i = 0; i < y_idx_1; i++) {
      y_data[i] = p_data[0];
    }
    i = p->size[0];
    for (k = 0; k <= i - 2; k++) {
      if (x->size[1] == y->size[1]) {
        real_T b_p;
        int32_T loop_ub;
        int32_T scalarLB;
        int32_T vectorUB;
        b_p = p_data[k + 1];
        loop_ub = x->size[1] - 1;
        i1 = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = y_idx_1;
        emxEnsureCapacity_real_T(sp, y, i1, &w_emlrtRTEI);
        y_data = y->data;
        scalarLB = (x->size[1] / 2) << 1;
        vectorUB = scalarLB - 2;
        for (i1 = 0; i1 <= vectorUB; i1 += 2) {
          __m128d r;
          r = _mm_loadu_pd(&y_data[i1]);
          _mm_storeu_pd(&y_data[i1],
                        _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&x_data[i1]), r),
                                   _mm_set1_pd(b_p)));
        }
        for (i1 = scalarLB; i1 <= loop_ub; i1++) {
          y_data[i1] = x_data[i1] * y_data[i1] + b_p;
        }
      } else {
        st.site = &jb_emlrtRSI;
        binary_expand_op(&st, y, x, p, k);
      }
    }
  }
}

/* End of code generation (polyval.c) */
