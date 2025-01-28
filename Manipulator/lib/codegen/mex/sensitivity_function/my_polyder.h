/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * my_polyder.h
 *
 * Code generation for function 'my_polyder'
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
void my_polyder(const emlrtStack *sp, const emxArray_real_T *a,
                emxArray_real_T *da);

/* End of code generation (my_polyder.h) */
