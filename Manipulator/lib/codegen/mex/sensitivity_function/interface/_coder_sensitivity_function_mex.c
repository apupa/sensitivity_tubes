/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sensitivity_function_mex.c
 *
 * Code generation for function '_coder_sensitivity_function_mex'
 *
 */

/* Include files */
#include "_coder_sensitivity_function_mex.h"
#include "_coder_sensitivity_function_api.h"
#include "rt_nonfinite.h"
#include "sensitivity_function_data.h"
#include "sensitivity_function_initialize.h"
#include "sensitivity_function_terminate.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&sensitivity_function_atexit);
  sensitivity_function_initialize();
  sensitivity_function_mexFunction(nlhs, plhs, nrhs, prhs);
  sensitivity_function_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

void sensitivity_function_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                      int32_T nrhs, const mxArray *prhs[11])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 11) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 11, 4,
                        20, "sensitivity_function");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "sensitivity_function");
  }
  /* Call the function. */
  sensitivity_function_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_sensitivity_function_mex.c) */
