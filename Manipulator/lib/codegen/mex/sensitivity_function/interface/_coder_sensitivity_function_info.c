/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sensitivity_function_info.c
 *
 * Code generation for function 'sensitivity_function'
 *
 */

/* Include files */
#include "_coder_sensitivity_function_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[4] = {
      "789cc593df4a024114c6c73089c0f22ae825a46e24ba2bcb2850c3b56e9ab075e78853f3"
      "679bd911171fa2d7e911baea3ae86552d7755d615841b47373f6e3c7"
      "cc77ceb7bb28775bcf21840e50549f85a81767ba34eb3b285dcb3c67e971eda27cea5ccc"
      "3f66dd932280611009e172989f249253e18aa01dfa801468c90640a6",
      "a44719b42907675134268ad716d05c4cd0e4b9da07efcd311ca9be4e26648b629ec78f65"
      "dffc8a79284b1ea525fe74fd5c3dc70f1a94c6ae200af095f40c0711"
      "687cd172aae3789464d801a16940073408b1637c50efc6258a7a1ab7c09763245588ebae"
      "a0be61ee586046bb5827873a3d23bc804a51e6e93dfd35f7dccfd833",
      "e63cecf892850454daff654dff82d53f22449a2e83c4ef6b4dbfbed52fcd37f95e932ccb"
      "3c2bc7c315f7b2fdbf45b437eddf37bf53b42dbfd171836fd32faeff"
      "f21b5aee5bf5bb3cb2f89596b8aeb49c9e435e2b274d76fa485473503bbbbb4ce6b8cff0"
      "c99a0359f4a6efff03c2609990",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1744U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 11);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("sensitivity_function"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(11.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:"
          "\\Users\\andre\\Documents\\ARSControl\\Sensitivity\\Superquadrics\\R"
          "epository\\Manipulator\\lib\\sensitivity_function.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739640.70614583336));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2740171 (R2024b) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("BKiG0sLNEbXxMRWHoQRTSG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_sensitivity_function_info.c) */
