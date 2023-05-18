#ifndef LIS_HPP_
#define LIS_HPP_

void solveLISTopDown(int* a, int n);
void solveLISBottomUp(int* a, int n);
void demoLIS();
int LISRecursion(int* a, int n, int prev, int cur, int** memoTable);

#endif