#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double y(double x)
{
//�h����x^4-3x^3+6x^2-68
double z;
z = pow(x,4) - 3*pow(x,3) + 6*pow(x,2) - 68;
return(z);
}

double yp(double x)
{
//�h���O�@�L��4x^3-9x^2+12x
double z;
z = 4*pow(x,3) - 9*pow(x,2) + 12*x;
return(z);
}

int main(void)
{
//��X��l��
double a, b, xa, xb, i, j;
double ans[20];
int TotalAns = 0, k, n;
a = -10;
b = 10;
for (i=a,j=a;i<=b;j=i,i+=0.1)
if (y(i)*y(j) < 0)
ans[TotalAns++] = j;

n = 1;
//���y�k�D��
for (k=0;k<TotalAns;k++) {
xa = ans[k];
while(1) {
xb = xa-y(xa)/yp(xa);
if (xa-xb < 0.0000000001 && xa-xb > -0.0000000001) break;
xa = xb;
}
printf("X%d = %.9f\n\n",n++,xa);
}
//���h����4�ӸѬ� 3.2001,-2.0425,0.92122+3.0911i,0.92122-3.0911i

   return 0;
}
