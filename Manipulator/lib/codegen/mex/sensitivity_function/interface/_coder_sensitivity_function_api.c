/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sensitivity_function_api.c
 *
 * Code generation for function '_coder_sensitivity_function_api'
 *
 */

/* Include files */
#include "_coder_sensitivity_function_api.h"
#include "rt_nonfinite.h"
#include "sensitivity_function.h"
#include "sensitivity_function_data.h"
#include "sensitivity_function_emxutil.h"
#include "sensitivity_function_types.h"

/* Variable Definitions */
static emlrtRTEInfo y_emlrtRTEI = {
    1,                                 /* lineNo */
    1,                                 /* colNo */
    "_coder_sensitivity_function_api", /* fName */
    ""                                 /* pName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u);

static const mxArray *c_emlrt_marshallOut(real_T u[36]);

static const mxArray *emlrt_marshallOut(const real_T u);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[54];

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[54];

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier);

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[6];

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[6];

static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[54];

static real_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6];

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  u->canFreeData = false;
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *c_emlrt_marshallOut(real_T u[36])
{
  static const int32_T i = 0;
  static const int32_T i1 = 36;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[54]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[54];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[54]
{
  real_T(*y)[54];
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = n_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[6]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[6];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = p_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[6]
{
  real_T(*y)[6];
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[54]
{
  static const int32_T dims = 54;
  real_T(*ret)[54];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[54])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6]
{
  static const int32_T dims = 6;
  real_T(*ret)[6];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[6])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void sensitivity_function_api(const mxArray *const prhs[11], int32_T nlhs,
                              const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *myc;
  real_T(*a)[54];
  real_T(*myceq)[36];
  real_T(*pn)[6];
  real_T(*q0)[6];
  real_T(*qf)[6];
  real_T b_value;
  real_T myf;
  real_T order_sq;
  real_T t0;
  real_T tf;
  real_T ts;
  real_T var;
  st.tls = emlrtRootTLSGlobal;
  myceq = (real_T(*)[36])mxMalloc(sizeof(real_T[36]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  a = k_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "a");
  myf = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "order");
  q0 = o_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "q0");
  qf = o_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "qf");
  t0 = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "t0");
  tf = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "tf");
  ts = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "ts");
  pn = o_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "pn");
  var = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "var");
  order_sq = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "order_sq");
  b_value = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "value");
  /* Invoke the target function */
  emxInit_real_T(&st, &myc, 1, &y_emlrtRTEI);
  sensitivity_function(&st, *a, myf, *q0, *qf, t0, tf, ts, *pn, var, order_sq,
                       b_value, &myf, myc, *myceq);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(myf);
  if (nlhs > 1) {
    myc->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(myc);
  }
  emxFree_real_T(&st, &myc);
  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(*myceq);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_sensitivity_function_api.c) */
