/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polyval.h
 *
 * Code generation for function 'polyval'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "sensitivity_function_types.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void polyval(const emlrtStack *sp, const emxArray_real_T *p,
             const emxArray_real_T *x, emxArray_real_T *y);

/* End of code generation (polyval.h) */
