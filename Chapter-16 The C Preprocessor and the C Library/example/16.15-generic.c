// generic.c - 定义泛型宏
#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG (180 / (4 * atanl(1)))
// 泛型平方根函数
#define SQRT(X) _Generic((X),\
  long double: sqrtl,\
  float: sqrtf,\
  default: sqrt\
)(X)
// 泛型正弦函数，角度的单位为度
#define SIN(X) _Generic((X),\
  long double: sinl((X) / RAD_TO_DEG),\
  float: sinf((X) / RAD_TO_DEG),\
  default: sin((X) / RAD_TO_DEG)\
)

int main(void)
{
  float x = 45.0f;
  double xx = 45.0;
  long double xxx = 45.0L;
  long double y = SQRT(x);
  long double yy = SQRT(xx);
  long double yyy = SQRT(xxx);
  printf("%.17Lf\n", y); // 匹配float
  printf("%.17Lf\n", yy); // 匹配default
  printf("%.17Lf\n", yyy); // 匹配long double
  int i = 45;
  yy = SQRT(i); // 匹配default
  printf("%.17Lf\n", yy);
  yyy = SIN(xxx); // 匹配long double
  printf("%.17Lf\n", yyy);
  return 0;
}