/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diag.c
 *
 * Code generation for function 'diag'
 *
 */

/* Include files */
#include "diag.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void diag(const real_T v[6], real_T d[36])
{
  int32_T j;
  memset(&d[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    d[j + 6 * j] = v[j];
  }
}

/* End of code generation (diag.c) */
