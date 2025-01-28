/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sensitivity_function_initialize.c
 *
 * Code generation for function 'sensitivity_function_initialize'
 *
 */

/* Include files */
#include "sensitivity_function_initialize.h"
#include "_coder_sensitivity_function_mex.h"
#include "rt_nonfinite.h"
#include "sensitivity_function_data.h"

/* Function Declarations */
static void sensitivity_function_once(void);

/* Function Definitions */
static void sensitivity_function_once(void)
{
  mex_InitInfAndNan();
}

void sensitivity_function_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    sensitivity_function_once();
  }
}

/* End of code generation (sensitivity_function_initialize.c) */
