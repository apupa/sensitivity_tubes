/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * colon.h
 *
 * Code generation for function 'colon'
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
void eml_float_colon(const emlrtStack *sp, real_T a, real_T d, real_T b,
                     emxArray_real_T *y);

/* End of code generation (colon.h) */
