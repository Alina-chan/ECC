#include <stdio.h>
#include <math.h>

int main(void)
{
  long a = 1180, b = 482, gcd, x, y;

  extendedGCD(a, b, &x, &y, &gcd);
  printf(" gcd = %ld\n x = %ld\n y = %ld\n", gcd, x, y);
  return 0;
}


void extendedGCD(long a, long b, long *x,long *y, long *gcd){

  long q, r, x1, x2, y1, y2;

  if (b == 0) {
    *gcd = a;
	*x = 1;
	*y = 0;
    return;
  }
  
  x2 = 1;
  x1 = 0;
  y2 = 0;
  y1 = 1;
 
  while (b > 0) {
    q = a / b;
	r = a - (q * b);
    *x = x2 - (q * x1);
	*y = y2 - (q * y1);
    a = b;
	b = r;
    x2 = x1;
	x1 = *x;
	y2 = y1;
	y1 = *y;
  }
  
  *gcd = a;
  *x = x2;
  *y = y2;
}


