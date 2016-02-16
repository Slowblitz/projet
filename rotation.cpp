#include <stdio.h>

#define N 3
int main(void)
{
  int t0[2][5] = {{ 0, 0, 75, 33, 29 },
                  { 8, 23, 45, 54, 69 } };
  int t1[2][5] = {{ 55, 33, 75, 21, 29 },
                  { 8, 23, 45, 54, 69 } };
  int t2[2][5] = {{ 55, 33, 75, 21, 29 },
                    { 8, 23, 45, 54, 69 } };

int t3[2][5] = {{ 55, 33, 75, 33, 29 },
                  { 8, 23, 45, 54, 69 } };

  /* p est un tableau de 2 pointeurs vers des tableaux de 5 int */
  int (*p[4])[2][5];

  /* Test */
  p[0] = &t0;
  p[1] = &t1;
  p[2] = &t2;
  p[3] = &t3;
for (int i = 0; i < 3; i++) {
  printf("\n");
for (int j= 0; j< 10; j++) {
    printf("%d", (**p[i])[j]);
}

  }



  return 0;
}
