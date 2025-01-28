/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sensitivity_function.h
 *
 * Code generation for function 'sensitivity_function'
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
void sensitivity_function(const emlrtStack *sp, const real_T a[54],
                          real_T order, const real_T q0[6], const real_T qf[6],
                          real_T t0, real_T tf, real_T ts, const real_T pn[6],
                          real_T var, real_T order_sq, real_T b_value,
                          real_T *myf, emxArray_real_T *myc, real_T myceq[36]);

/* End of code generation (sensitivity_function.h) */
