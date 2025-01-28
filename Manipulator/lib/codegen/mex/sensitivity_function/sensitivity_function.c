/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sensitivity_function.c
 *
 * Code generation for function 'sensitivity_function'
 *
 */

/* Include files */
#include "sensitivity_function.h"
#include "colon.h"
#include "diag.h"
#include "mtimes.h"
#include "my_polyder.h"
#include "norm.h"
#include "nthroot.h"
#include "polyval.h"
#include "rt_nonfinite.h"
#include "sensitivity_function_data.h"
#include "sensitivity_function_emxutil.h"
#include "sensitivity_function_types.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    19,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    26,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    27,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    60,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    61,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    65,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    76,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI =
    {
        125,     /* lineNo */
        "colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

static emlrtRSInfo l_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    142,      /* lineNo */
    "mtimes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    14,        /* lineNo */
    "nthroot", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\nthroot.m" /* pathName
                                                                          */
};

static emlrtRSInfo p_emlrtRSI = {
    66,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    208,        /* lineNo */
    "flatIter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    40,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtMCInfo emlrtMCI = {
    49,                     /* lineNo */
    9,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtMCInfo b_emlrtMCI = {
    51,                     /* lineNo */
    10,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtMCInfo c_emlrtMCI = {
    52,                     /* lineNo */
    12,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtMCInfo d_emlrtMCI = {
    53,                     /* lineNo */
    17,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtMCInfo e_emlrtMCI = {
    53,                     /* lineNo */
    12,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtMCInfo f_emlrtMCI = {
    54,                     /* lineNo */
    17,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtMCInfo g_emlrtMCI = {
    54,                     /* lineNo */
    12,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtMCInfo h_emlrtMCI = {
    55,                     /* lineNo */
    17,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtMCInfo i_emlrtMCI = {
    55,                     /* lineNo */
    12,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    7,                      /* lineNo */
    11,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    4                                                /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    7,                      /* lineNo */
    11,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    1                                                /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    9,                      /* lineNo */
    16,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    1                                                /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    1,                      /* iFirst */
    54,                     /* iLast */
    9,                      /* lineNo */
    16,                     /* colNo */
    "a",                    /* aName */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    0                                                /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    9,                      /* lineNo */
    34,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    1                                                /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    1,                      /* iFirst */
    54,                     /* iLast */
    9,                      /* lineNo */
    34,                     /* colNo */
    "a",                    /* aName */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    0                                                /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,                     /* nDims */
    9,                      /* lineNo */
    5,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                     /* nDims */
    25,                     /* lineNo */
    5,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    -1,                     /* nDims */
    26,                     /* lineNo */
    5,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    48,                     /* lineNo */
    29,                     /* colNo */
    "q_des",                /* aName */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    0                                                /* checkKind */
};

static emlrtECInfo d_emlrtECI = {
    -1,                     /* nDims */
    27,                     /* lineNo */
    5,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    78,                     /* lineNo */
    18,                     /* colNo */
    "q_des",                /* aName */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    0                                                /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo b_emlrtRTEI = {
    12,        /* lineNo */
    5,         /* colNo */
    "nthroot", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\nthroot.m" /* pName
                                                                          */
};

static emlrtDCInfo e_emlrtDCI = {
    30,                     /* lineNo */
    1,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    1                                                /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    66,                     /* lineNo */
    16,                     /* colNo */
    "constr",               /* aName */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    0                                                /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    67,                     /* lineNo */
    16,                     /* colNo */
    "constr",               /* aName */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m", /* pName */
    0                                                /* checkKind */
};

static emlrtRTEInfo i_emlrtRTEI = {
    7,                      /* lineNo */
    1,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    19,                     /* lineNo */
    1,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    21,                     /* lineNo */
    1,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    22,                     /* lineNo */
    1,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    23,                     /* lineNo */
    1,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    25,                     /* lineNo */
    26,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    30,                     /* lineNo */
    1,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    26,                     /* lineNo */
    38,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    77,                     /* lineNo */
    1,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    27,                     /* lineNo */
    50,                     /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    25,                     /* lineNo */
    5,                      /* colNo */
    "sensitivity_function", /* fName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pName */
};

static emlrtRSInfo db_emlrtRSI = {
    49,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    51,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    52,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    53,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    55,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    54,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    25,                     /* lineNo */
    "sensitivity_function", /* fcnName */
    "C:"
    "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\Reposit"
    "ory\\Manipulator\\lib\\sensitivity_function.m" /* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6]);

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_f_mex_,
                               const char_T *identifier, real_T y[12]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[12]);

static const mxArray *df_p_mex(const emlrtStack *sp, const mxArray *m1,
                               emlrtMCInfo *location);

static const mxArray *df_q_mex(const emlrtStack *sp, const mxArray *m1,
                               emlrtMCInfo *location);

static const mxArray *df_u_mex(const emlrtStack *sp, const mxArray *m1,
                               emlrtMCInfo *location);

static const mxArray *dh_q_mex(const emlrtStack *sp, const mxArray *m1,
                               emlrtMCInfo *location);

static void e_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_dh_q_mex_,
                               const char_T *identifier, real_T y[72]);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_h_fun_mex_,
                             const char_T *identifier, real_T y[6]);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[72]);

static const mxArray *f_mex(const emlrtStack *sp, const mxArray *m1,
                            emlrtMCInfo *location);

static const mxArray *full(const emlrtStack *sp, const mxArray *m1,
                           emlrtMCInfo *location);

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_full_,
                               const char_T *identifier, real_T y[144]);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[144]);

static const mxArray *h_fun_mex(const emlrtStack *sp, const mxArray *m1,
                                emlrtMCInfo *location);

static void i_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_full_,
                               const char_T *identifier, real_T y[72]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[72]);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6]);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[12]);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[72]);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[144]);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[72]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_f_mex_,
                               const char_T *identifier, real_T y[12])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(a__output_of_f_mex_), &thisId, y);
  emlrtDestroyArray(&a__output_of_f_mex_);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[12])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *df_p_mex(const emlrtStack *sp, const mxArray *m1,
                               emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "df_p_mex",
                               true, location);
}

static const mxArray *df_q_mex(const emlrtStack *sp, const mxArray *m1,
                               emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "df_q_mex",
                               true, location);
}

static const mxArray *df_u_mex(const emlrtStack *sp, const mxArray *m1,
                               emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "df_u_mex",
                               true, location);
}

static const mxArray *dh_q_mex(const emlrtStack *sp, const mxArray *m1,
                               emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "dh_q_mex",
                               true, location);
}

static void e_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_dh_q_mex_,
                               const char_T *identifier, real_T y[72])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(a__output_of_dh_q_mex_), &thisId, y);
  emlrtDestroyArray(&a__output_of_dh_q_mex_);
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *a__output_of_h_fun_mex_,
                             const char_T *identifier, real_T y[6])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_h_fun_mex_), &thisId, y);
  emlrtDestroyArray(&a__output_of_h_fun_mex_);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[72])
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *f_mex(const emlrtStack *sp, const mxArray *m1,
                            emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "f_mex",
                               true, location);
}

static const mxArray *full(const emlrtStack *sp, const mxArray *m1,
                           emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "full",
                               true, location);
}

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_full_,
                               const char_T *identifier, real_T y[144])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(a__output_of_full_), &thisId, y);
  emlrtDestroyArray(&a__output_of_full_);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[144])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *h_fun_mex(const emlrtStack *sp, const mxArray *m1,
                                emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray,
                               "h_fun_mex", true, location);
}

static void i_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *a__output_of_full_,
                               const char_T *identifier, real_T y[72])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(a__output_of_full_), &thisId, y);
  emlrtDestroyArray(&a__output_of_full_);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[72])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims = 6;
  real_T(*r)[6];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[6])emlrtMxGetData(src);
  for (i = 0; i < 6; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[12])
{
  static const int32_T dims = 12;
  real_T(*r)[12];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[12])emlrtMxGetData(src);
  for (i = 0; i < 12; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[72])
{
  static const int32_T dims[2] = {6, 12};
  real_T(*r)[72];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[72])emlrtMxGetData(src);
  for (i = 0; i < 72; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[144])
{
  static const int32_T dims[2] = {12, 12};
  real_T(*r)[144];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[144])emlrtMxGetData(src);
  for (i = 0; i < 144; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[72])
{
  static const int32_T dims[2] = {12, 6};
  real_T(*r)[72];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[72])emlrtMxGetData(src);
  for (i = 0; i < 72; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

void sensitivity_function(const emlrtStack *sp, const real_T a[54],
                          real_T order, const real_T q0[6], const real_T qf[6],
                          real_T t0, real_T tf, real_T ts, const real_T pn[6],
                          real_T var, real_T order_sq, real_T b_value,
                          real_T *myf, emxArray_real_T *myc, real_T myceq[36])
{
  static const int32_T i2 = 36;
  static const int32_T i3 = 24;
  static const int32_T i4 = 36;
  static const int32_T i5 = 24;
  static const int32_T i6 = 24;
  static const int32_T i7 = 24;
  static const int8_T N[36] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
                               0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
                               0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1};
  __m128d r;
  __m128d r1;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *A;
  emxArray_real_T *b_A;
  emxArray_real_T *b_time;
  emxArray_real_T *constr;
  emxArray_real_T *ddq_des;
  emxArray_real_T *dq_des;
  emxArray_real_T *q_des;
  emxArray_real_T *r2;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *m;
  const mxArray *y;
  real_T df_q[144];
  real_T Pi[72];
  real_T c_dh_q[72];
  real_T df_u[72];
  real_T dh_q[72];
  real_T W[36];
  real_T b_dh_q[36];
  real_T hvars[36];
  real_T fvars[24];
  real_T dx[12];
  real_T x[12];
  real_T u[6];
  real_T alpha;
  real_T alpha1 = 0.0;
  real_T beta1 = 0.0;
  real_T d;
  real_T n;
  real_T n_tmp;
  real_T *A_data;
  real_T *ddq_des_data;
  real_T *dq_des_data;
  real_T *q_des_data;
  real_T *time_data;
  int32_T iv[2];
  int32_T b_loop_ub_tmp;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  uint32_T idx;
  char_T TRANSA1 = '\x00';
  char_T TRANSB1 = '\x00';
  boolean_T b;
  boolean_T b1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (!(order + 1.0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(order + 1.0, &emlrtDCI, (emlrtConstCTX)sp);
  }
  if (order + 1.0 != (int32_T)muDoubleScalarFloor(order + 1.0)) {
    emlrtIntegerCheckR2012b(order + 1.0, &b_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &A, 2, &i_emlrtRTEI);
  loop_ub_tmp = (int32_T)(order + 1.0);
  i = A->size[0] * A->size[1];
  A->size[0] = (int32_T)(order + 1.0);
  A->size[1] = 6;
  emxEnsureCapacity_real_T(sp, A, i, &i_emlrtRTEI);
  A_data = A->data;
  b_loop_ub_tmp = (int32_T)(order + 1.0) * 6;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    A_data[i] = 0.0;
  }
  for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 6; b_loop_ub_tmp++) {
    d = (order + 1.0) * (((real_T)b_loop_ub_tmp + 1.0) - 1.0) + 1.0;
    alpha = (order + 1.0) * ((real_T)b_loop_ub_tmp + 1.0);
    if (d > alpha) {
      i = 0;
      i1 = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &c_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 54)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 54, &emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i = (int32_T)d - 1;
      if (alpha != (int32_T)muDoubleScalarFloor(alpha)) {
        emlrtIntegerCheckR2012b(alpha, &d_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)alpha < 1) || ((int32_T)alpha > 54)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)alpha, 1, 54, &b_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i1 = (int32_T)alpha;
    }
    i1 -= i;
    emlrtSubAssignSizeCheckR2012b(&loop_ub_tmp, 1, &i1, 1, &emlrtECI,
                                  (emlrtCTX)sp);
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      A_data[i1 + A->size[0] * b_loop_ub_tmp] = a[i + i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  r = _mm_loadu_pd(&q0[0]);
  _mm_storeu_pd(&x[0], r);
  r1 = _mm_set1_pd(0.0);
  _mm_storeu_pd(&x[6], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&q0[2]);
  _mm_storeu_pd(&x[2], r);
  _mm_storeu_pd(&x[8], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&q0[4]);
  _mm_storeu_pd(&x[4], r);
  _mm_storeu_pd(&x[10], _mm_mul_pd(r1, r));
  memset(&Pi[0], 0, 72U * sizeof(real_T));
  r = _mm_set1_pd(var);
  _mm_storeu_pd(&u[0], _mm_mul_pd(r, _mm_loadu_pd(&pn[0])));
  _mm_storeu_pd(&u[2], _mm_mul_pd(r, _mm_loadu_pd(&pn[2])));
  _mm_storeu_pd(&u[4], _mm_mul_pd(r, _mm_loadu_pd(&pn[4])));
  diag(u, hvars);
  for (k = 0; k <= 34; k += 2) {
    r = _mm_loadu_pd(&hvars[k]);
    _mm_storeu_pd(&W[k], _mm_mul_pd(r, r));
  }
  st.site = &emlrtRSI;
  emxInit_real_T(&st, &b_time, 2, &j_emlrtRTEI);
  if (muDoubleScalarIsNaN(t0) || muDoubleScalarIsNaN(ts) ||
      muDoubleScalarIsNaN(tf)) {
    i = b_time->size[0] * b_time->size[1];
    b_time->size[0] = 1;
    b_time->size[1] = 1;
    emxEnsureCapacity_real_T(&st, b_time, i, &j_emlrtRTEI);
    time_data = b_time->data;
    time_data[0] = rtNaN;
  } else if ((ts == 0.0) || ((t0 < tf) && (ts < 0.0)) ||
             ((tf < t0) && (ts > 0.0))) {
    b_time->size[0] = 1;
    b_time->size[1] = 0;
  } else if ((muDoubleScalarIsInf(t0) || muDoubleScalarIsInf(tf)) &&
             (muDoubleScalarIsInf(ts) || (t0 == tf))) {
    i = b_time->size[0] * b_time->size[1];
    b_time->size[0] = 1;
    b_time->size[1] = 1;
    emxEnsureCapacity_real_T(&st, b_time, i, &j_emlrtRTEI);
    time_data = b_time->data;
    time_data[0] = rtNaN;
  } else if (muDoubleScalarIsInf(ts)) {
    i = b_time->size[0] * b_time->size[1];
    b_time->size[0] = 1;
    b_time->size[1] = 1;
    emxEnsureCapacity_real_T(&st, b_time, i, &j_emlrtRTEI);
    time_data = b_time->data;
    time_data[0] = t0;
  } else if ((muDoubleScalarFloor(t0) == t0) &&
             (muDoubleScalarFloor(ts) == ts)) {
    i = b_time->size[0] * b_time->size[1];
    b_time->size[0] = 1;
    loop_ub = (int32_T)((tf - t0) / ts);
    b_time->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(&st, b_time, i, &j_emlrtRTEI);
    time_data = b_time->data;
    for (i = 0; i <= loop_ub; i++) {
      time_data[i] = t0 + ts * (real_T)i;
    }
  } else {
    b_st.site = &h_emlrtRSI;
    eml_float_colon(&b_st, t0, ts, tf, b_time);
  }
  emxInit_real_T(sp, &q_des, 2, &k_emlrtRTEI);
  i = q_des->size[0] * q_des->size[1];
  q_des->size[0] = 6;
  loop_ub = b_time->size[1];
  q_des->size[1] = b_time->size[1];
  emxEnsureCapacity_real_T(sp, q_des, i, &k_emlrtRTEI);
  q_des_data = q_des->data;
  b_loop_ub_tmp = 6 * b_time->size[1];
  for (i = 0; i < b_loop_ub_tmp; i++) {
    q_des_data[i] = 0.0;
  }
  emxInit_real_T(sp, &dq_des, 2, &l_emlrtRTEI);
  i = dq_des->size[0] * dq_des->size[1];
  dq_des->size[0] = 6;
  dq_des->size[1] = b_time->size[1];
  emxEnsureCapacity_real_T(sp, dq_des, i, &l_emlrtRTEI);
  dq_des_data = dq_des->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    dq_des_data[i] = 0.0;
  }
  emxInit_real_T(sp, &ddq_des, 2, &m_emlrtRTEI);
  i = ddq_des->size[0] * ddq_des->size[1];
  ddq_des->size[0] = 6;
  ddq_des->size[1] = b_time->size[1];
  emxEnsureCapacity_real_T(sp, ddq_des, i, &m_emlrtRTEI);
  ddq_des_data = ddq_des->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    ddq_des_data[i] = 0.0;
  }
  emxInit_real_T(sp, &constr, 1, &o_emlrtRTEI);
  emxInit_real_T(sp, &r2, 2, &s_emlrtRTEI);
  emxInit_real_T(sp, &b_A, 1, &n_emlrtRTEI);
  for (j = 0; j < 6; j++) {
    i = b_A->size[0];
    b_A->size[0] = (int32_T)(order + 1.0);
    emxEnsureCapacity_real_T(sp, b_A, i, &n_emlrtRTEI);
    time_data = b_A->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      time_data[i] = A_data[i + A->size[0] * j];
    }
    st.site = &kb_emlrtRSI;
    polyval(&st, b_A, b_time, r2);
    time_data = r2->data;
    iv[0] = 1;
    iv[1] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r2->size[0], 2, &b_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < loop_ub; i++) {
      q_des_data[j + 6 * i] = time_data[i];
    }
    i = b_A->size[0];
    b_A->size[0] = (int32_T)(order + 1.0);
    emxEnsureCapacity_real_T(sp, b_A, i, &p_emlrtRTEI);
    time_data = b_A->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      time_data[i] = A_data[i + A->size[0] * j];
    }
    st.site = &b_emlrtRSI;
    my_polyder(&st, b_A, constr);
    st.site = &b_emlrtRSI;
    polyval(&st, constr, b_time, r2);
    time_data = r2->data;
    iv[0] = 1;
    iv[1] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r2->size[0], 2, &c_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < loop_ub; i++) {
      dq_des_data[j + 6 * i] = time_data[i];
    }
    i = b_A->size[0];
    b_A->size[0] = (int32_T)(order + 1.0);
    emxEnsureCapacity_real_T(sp, b_A, i, &r_emlrtRTEI);
    time_data = b_A->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      time_data[i] = A_data[i + A->size[0] * j];
    }
    st.site = &c_emlrtRSI;
    my_polyder(&st, b_A, constr);
    st.site = &c_emlrtRSI;
    my_polyder(&st, constr, b_A);
    st.site = &c_emlrtRSI;
    polyval(&st, b_A, b_time, r2);
    time_data = r2->data;
    iv[0] = 1;
    iv[1] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r2->size[0], 2, &d_emlrtECI,
                                  (emlrtCTX)sp);
    for (i = 0; i < loop_ub; i++) {
      ddq_des_data[j + 6 * i] = time_data[i];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &b_A);
  emxFree_real_T(sp, &r2);
  emxFree_real_T(sp, &A);
  d = 6.0 * (real_T)b_time->size[1] * 2.0;
  if (d != (int32_T)d) {
    emlrtIntegerCheckR2012b(d, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  b_loop_ub_tmp = (int32_T)d;
  i = constr->size[0];
  constr->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(sp, constr, i, &o_emlrtRTEI);
  A_data = constr->data;
  if (d != (int32_T)d) {
    emlrtIntegerCheckR2012b(d, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < b_loop_ub_tmp; i++) {
    A_data[i] = 0.0;
  }
  idx = 2U;
  if (b_time->size[1] - 1 >= 0) {
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    m_t = (ptrdiff_t)12;
    n_t = (ptrdiff_t)6;
    k_t = (ptrdiff_t)12;
    lda_t = (ptrdiff_t)12;
    ldb_t = (ptrdiff_t)12;
    ldc_t = (ptrdiff_t)12;
    n_tmp = 2.0 * order_sq - 1.0;
    if (muDoubleScalarIsNaN(n_tmp) || (muDoubleScalarRem(n_tmp, 2.0) == 1.0)) {
      b = true;
    } else {
      b = false;
    }
    n = 2.0 * order_sq / n_tmp;
    if (muDoubleScalarIsNaN(n) || (muDoubleScalarRem(n, 2.0) == 1.0)) {
      b1 = true;
    } else {
      b1 = false;
    }
  }
  for (k = 0; k < loop_ub; k++) {
    real_T df_p[72];
    real_T P[36];
    boolean_T p;
    if (k + 1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, loop_ub, &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    memcpy(&hvars[0], &x[0], 12U * sizeof(real_T));
    for (i = 0; i < 6; i++) {
      hvars[i + 12] = pn[i];
      b_loop_ub_tmp = i + 6 * k;
      hvars[i + 18] = q_des_data[b_loop_ub_tmp];
      hvars[i + 24] = dq_des_data[b_loop_ub_tmp];
      hvars[i + 30] = ddq_des_data[b_loop_ub_tmp];
    }
    y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i2, mxDOUBLE_CLASS, mxREAL);
    time_data = emlrtMxGetPr(m);
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 36; b_loop_ub_tmp++) {
      time_data[b_loop_ub_tmp] = hvars[b_loop_ub_tmp];
    }
    emlrtAssign(&y, m);
    st.site = &db_emlrtRSI;
    emlrt_marshallIn(&st, h_fun_mex(&st, y, &emlrtMCI), "<output of h_fun_mex>",
                     u);
    memcpy(&fvars[0], &x[0], 12U * sizeof(real_T));
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 6; b_loop_ub_tmp++) {
      fvars[b_loop_ub_tmp + 12] = u[b_loop_ub_tmp];
      fvars[b_loop_ub_tmp + 18] = pn[b_loop_ub_tmp];
    }
    b_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i3, mxDOUBLE_CLASS, mxREAL);
    time_data = emlrtMxGetPr(m);
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 24; b_loop_ub_tmp++) {
      time_data[b_loop_ub_tmp] = fvars[b_loop_ub_tmp];
    }
    emlrtAssign(&b_y, m);
    st.site = &eb_emlrtRSI;
    c_emlrt_marshallIn(&st, f_mex(&st, b_y, &b_emlrtMCI), "<output of f_mex>",
                       dx);
    c_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i4, mxDOUBLE_CLASS, mxREAL);
    time_data = emlrtMxGetPr(m);
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 36; b_loop_ub_tmp++) {
      time_data[b_loop_ub_tmp] = hvars[b_loop_ub_tmp];
    }
    emlrtAssign(&c_y, m);
    st.site = &fb_emlrtRSI;
    e_emlrt_marshallIn(&st, dh_q_mex(&st, c_y, &c_emlrtMCI),
                       "<output of dh_q_mex>", dh_q);
    d_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i5, mxDOUBLE_CLASS, mxREAL);
    time_data = emlrtMxGetPr(m);
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 24; b_loop_ub_tmp++) {
      time_data[b_loop_ub_tmp] = fvars[b_loop_ub_tmp];
    }
    emlrtAssign(&d_y, m);
    st.site = &gb_emlrtRSI;
    g_emlrt_marshallIn(&st,
                       full(&st, df_q_mex(&st, d_y, &d_emlrtMCI), &e_emlrtMCI),
                       "<output of full>", df_q);
    e_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i6, mxDOUBLE_CLASS, mxREAL);
    time_data = emlrtMxGetPr(m);
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 24; b_loop_ub_tmp++) {
      time_data[b_loop_ub_tmp] = fvars[b_loop_ub_tmp];
    }
    emlrtAssign(&e_y, m);
    st.site = &ib_emlrtRSI;
    i_emlrt_marshallIn(&st,
                       full(&st, df_u_mex(&st, e_y, &f_emlrtMCI), &g_emlrtMCI),
                       "<output of full>", df_u);
    f_y = NULL;
    m = emlrtCreateNumericArray(1, (const void *)&i7, mxDOUBLE_CLASS, mxREAL);
    time_data = emlrtMxGetPr(m);
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 24; b_loop_ub_tmp++) {
      time_data[b_loop_ub_tmp] = fvars[b_loop_ub_tmp];
    }
    emlrtAssign(&f_y, m);
    st.site = &hb_emlrtRSI;
    i_emlrt_marshallIn(&st,
                       full(&st, df_p_mex(&st, f_y, &h_emlrtMCI), &i_emlrtMCI),
                       "<output of full>", df_p);
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        d = 0.0;
        for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 12; b_loop_ub_tmp++) {
          d += dh_q[i + 6 * b_loop_ub_tmp] * Pi[b_loop_ub_tmp + 12 * i1];
        }
        b_dh_q[i + 6 * i1] = d;
      }
    }
    memcpy(&hvars[0], &b_dh_q[0], 36U * sizeof(real_T));
    st.site = &d_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    c_st.site = &m_emlrtRSI;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &df_q[0], &lda_t,
          &Pi[0], &ldb_t, &beta1, &dh_q[0], &ldc_t);
    st.site = &e_emlrtRSI;
    p = false;
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 36; b_loop_ub_tmp++) {
      d = W[b_loop_ub_tmp];
      b_dh_q[b_loop_ub_tmp] = d;
      if (p || (d < 0.0)) {
        p = true;
      }
    }
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp <= 34; b_loop_ub_tmp += 2) {
      r = _mm_loadu_pd(&b_dh_q[b_loop_ub_tmp]);
      _mm_storeu_pd(&b_dh_q[b_loop_ub_tmp], _mm_sqrt_pd(r));
    }
    for (i = 0; i < 6; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        d = 0.0;
        for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 6; b_loop_ub_tmp++) {
          d += hvars[i + 6 * b_loop_ub_tmp] * b_dh_q[b_loop_ub_tmp + 6 * i1];
        }
        P[i + 6 * i1] = d;
      }
    }
    for (j = 0; j < 6; j++) {
      real_T b_b[6];
      real_T g_y[6];
      uint32_T b_u;
      int8_T v[6];
      for (i = 0; i < 6; i++) {
        v[i] = N[i + 6 * j];
      }
      for (i = 0; i < 6; i++) {
        d = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          d += P[i1 + 6 * i] * (real_T)v[i1];
        }
        g_y[i] = d;
      }
      st.site = &f_emlrtRSI;
      p = false;
      if (!b) {
        for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 6; b_loop_ub_tmp++) {
          if (p || (g_y[b_loop_ub_tmp] < 0.0)) {
            p = true;
          }
        }
      }
      if (p) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                      "MATLAB:nthroot:NegXNotOddIntegerN",
                                      "MATLAB:nthroot:NegXNotOddIntegerN", 0);
      }
      b_st.site = &o_emlrtRSI;
      c_st.site = &p_emlrtRSI;
      for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 6; b_loop_ub_tmp++) {
        d_st.site = &q_emlrtRSI;
        b_b[b_loop_ub_tmp] = nthroot(&d_st, g_y[b_loop_ub_tmp], n_tmp);
      }
      alpha = 0.0;
      for (i = 0; i < 6; i++) {
        d = 0.0;
        for (i1 = 0; i1 < 6; i1++) {
          d += (real_T)v[i1] * P[i1 + 6 * i];
        }
        alpha += d * b_b[i];
      }
      st.site = &f_emlrtRSI;
      p = false;
      if (!b1) {
        p = (alpha < 0.0);
      }
      if (p) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                      "MATLAB:nthroot:NegXNotOddIntegerN",
                                      "MATLAB:nthroot:NegXNotOddIntegerN", 0);
      }
      b_st.site = &o_emlrtRSI;
      c_st.site = &v_emlrtRSI;
      alpha = nthroot(&c_st, alpha, n);
      b_u = idx + ((uint32_T)j << 1);
      if (((int32_T)(b_u - 1U) < 1) ||
          ((int32_T)(b_u - 1U) > constr->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_u - 1U), 1, constr->size[0],
                                      &e_emlrtBCI, (emlrtConstCTX)sp);
      }
      d = u[j];
      A_data[(int32_T)b_u - 2] = d + alpha;
      if (((int32_T)b_u < 1) || ((int32_T)b_u > constr->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_u, 1, constr->size[0],
                                      &f_emlrtBCI, (emlrtConstCTX)sp);
      }
      A_data[(int32_T)b_u - 1] = d - alpha;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    idx += 12U;
    for (i = 0; i < 12; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        d = 0.0;
        for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 6; b_loop_ub_tmp++) {
          d += df_u[i + 12 * b_loop_ub_tmp] * hvars[b_loop_ub_tmp + 6 * i1];
        }
        b_loop_ub_tmp = i + 12 * i1;
        c_dh_q[b_loop_ub_tmp] = (dh_q[b_loop_ub_tmp] + d) + df_p[b_loop_ub_tmp];
      }
    }
    for (i = 0; i <= 70; i += 2) {
      r = _mm_loadu_pd(&c_dh_q[i]);
      r1 = _mm_loadu_pd(&Pi[i]);
      _mm_storeu_pd(&Pi[i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(ts))));
    }
    for (i = 0; i <= 10; i += 2) {
      r = _mm_loadu_pd(&dx[i]);
      r1 = _mm_loadu_pd(&x[i]);
      _mm_storeu_pd(&x[i], _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(ts))));
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  st.site = &g_emlrtRSI;
  for (i = 0; i < 12; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (b_loop_ub_tmp = 0; b_loop_ub_tmp < 6; b_loop_ub_tmp++) {
        d += Pi[i + 12 * b_loop_ub_tmp] * W[b_loop_ub_tmp + 6 * i1];
      }
      df_u[i + 12 * i1] = d;
    }
  }
  b_st.site = &l_emlrtRSI;
  mtimes(df_u, Pi, df_q);
  st.site = &g_emlrtRSI;
  *myf = b_norm(&st, df_q);
  i = myc->size[0];
  myc->size[0] = constr->size[0] + constr->size[0];
  emxEnsureCapacity_real_T(sp, myc, i, &q_emlrtRTEI);
  time_data = myc->data;
  loop_ub_tmp = constr->size[0];
  b_loop_ub_tmp = (constr->size[0] / 2) << 1;
  loop_ub = b_loop_ub_tmp - 2;
  for (i = 0; i <= loop_ub; i += 2) {
    r = _mm_loadu_pd(&A_data[i]);
    _mm_storeu_pd(&time_data[i], _mm_sub_pd(r, _mm_set1_pd(b_value)));
  }
  for (i = b_loop_ub_tmp; i < loop_ub_tmp; i++) {
    time_data[i] = A_data[i] - b_value;
  }
  for (i = 0; i <= loop_ub; i += 2) {
    r = _mm_loadu_pd(&A_data[i]);
    _mm_storeu_pd(&time_data[i + constr->size[0]],
                  _mm_sub_pd(_mm_set1_pd(-b_value), r));
  }
  for (i = b_loop_ub_tmp; i < loop_ub_tmp; i++) {
    time_data[i + constr->size[0]] = -b_value - A_data[i];
  }
  emxFree_real_T(sp, &constr);
  if (b_time->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, b_time->size[1], &d_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  emxFree_real_T(sp, &b_time);
  r = _mm_loadu_pd(&q_des_data[0]);
  _mm_storeu_pd(&myceq[0], _mm_sub_pd(r, _mm_loadu_pd(&q0[0])));
  r = _mm_loadu_pd(&q_des_data[6 * (q_des->size[1] - 1)]);
  _mm_storeu_pd(&myceq[6], _mm_sub_pd(r, _mm_loadu_pd(&qf[0])));
  r = _mm_loadu_pd(&dq_des_data[0]);
  _mm_storeu_pd(&myceq[12], r);
  r = _mm_loadu_pd(&dq_des_data[6 * (q_des->size[1] - 1)]);
  _mm_storeu_pd(&myceq[18], r);
  r = _mm_loadu_pd(&ddq_des_data[0]);
  _mm_storeu_pd(&myceq[24], r);
  r = _mm_loadu_pd(&ddq_des_data[6 * (q_des->size[1] - 1)]);
  _mm_storeu_pd(&myceq[30], r);
  r = _mm_loadu_pd(&q_des_data[2]);
  _mm_storeu_pd(&myceq[2], _mm_sub_pd(r, _mm_loadu_pd(&q0[2])));
  r = _mm_loadu_pd(&q_des_data[6 * (q_des->size[1] - 1) + 2]);
  _mm_storeu_pd(&myceq[8], _mm_sub_pd(r, _mm_loadu_pd(&qf[2])));
  r = _mm_loadu_pd(&dq_des_data[2]);
  _mm_storeu_pd(&myceq[14], r);
  r = _mm_loadu_pd(&dq_des_data[6 * (q_des->size[1] - 1) + 2]);
  _mm_storeu_pd(&myceq[20], r);
  r = _mm_loadu_pd(&ddq_des_data[2]);
  _mm_storeu_pd(&myceq[26], r);
  r = _mm_loadu_pd(&ddq_des_data[6 * (q_des->size[1] - 1) + 2]);
  _mm_storeu_pd(&myceq[32], r);
  r = _mm_loadu_pd(&q_des_data[4]);
  _mm_storeu_pd(&myceq[4], _mm_sub_pd(r, _mm_loadu_pd(&q0[4])));
  r = _mm_loadu_pd(&q_des_data[6 * (q_des->size[1] - 1) + 4]);
  _mm_storeu_pd(&myceq[10], _mm_sub_pd(r, _mm_loadu_pd(&qf[4])));
  r = _mm_loadu_pd(&dq_des_data[4]);
  _mm_storeu_pd(&myceq[16], r);
  r = _mm_loadu_pd(&dq_des_data[6 * (q_des->size[1] - 1) + 4]);
  emxFree_real_T(sp, &dq_des);
  _mm_storeu_pd(&myceq[22], r);
  r = _mm_loadu_pd(&ddq_des_data[4]);
  _mm_storeu_pd(&myceq[28], r);
  r = _mm_loadu_pd(&ddq_des_data[6 * (q_des->size[1] - 1) + 4]);
  emxFree_real_T(sp, &ddq_des);
  emxFree_real_T(sp, &q_des);
  _mm_storeu_pd(&myceq[34], r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (sensitivity_function.c) */
