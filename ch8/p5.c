#include<stdio.h>
#include<memory.h>

void matrix_multiply( int *m1, int *m2, int *r, int x, int y, int z)
{
  int num_m1 = x * y;
  int num_m2 = y * z;
  int line_m1, line_m2, row_m1, row_m2;
  int temp_result = 0;

  for( line_m1 = 0; line_m1 < x; line_m1++ )
  {
    for( row_m2 = 0; row_m2 < z; row_m2++ )
    {
      //第一个数组的纵坐标和第二个数组的横坐标同时变化
      for ( row_m1 = 0, line_m2 = 0; row_m1 < y; row_m1++, line_m2++ )
      {
          r[line_m1*z + row_m2] += m1[line_m1*y + row_m1] * m2[line_m2*z + row_m2];
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  int m1[] = { 2, -6, 3, 5, 1, -1};
  int m2[] = { 4, -2, -4, -5, -7, -3, 6, 7};
  int r[12];
  int index_x, index_y;

  memset( r, 0, sizeof(r) );
  matrix_multiply( m1, m2, r, 3, 2, 4);
  for( index_x = 0; index_x < 3; index_x++ )
  {
    for( index_y = 0; index_y < 4; index_y++ )
      printf("%d\t",  r[index_x*4+index_y]);
    printf("\n" );
  }
  return 0;
}
