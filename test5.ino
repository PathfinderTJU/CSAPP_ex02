#include <stdio.h>
using namespace std;

int serial_putc( char c, struct __file * )
{
  Serial.write( c );
  return c;
}

void printf_begin(void)
{
  fdevopen( &serial_putc, 0 );
}

void multi(long* a[], int x, int y){
    long t[y][x];

    for (int i = 0 ; i < x ; i++){//转置
        for (int j = 0 ; j < y ; j++){
            t[j][i] = a[i][j];
        }
    }

    long result[x][x];

    for (int i = 0 ; i < x ; i++){
        for (int j = 0 ; j < x ; j++){
            long temp = 0;
            for (int m = 0 ; m < y ; m++){
                temp += a[i][m] * t[m][j];//乘积之和
            }
            result[i][j] = temp;
        }
    }

    for (int i = 0 ; i < x ; i++){
        for (int j = 0 ; j < x ; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

}

void setup() {
  Serial.begin(115200);
  printf_begin();
}

void loop(){
    long a[5] = {1,5,2,1,3};
    long b[5] = {0,2,1,3,9};
    long c[5] = {9,4,7,2,0};
    long* d[3] = {a, b, c};
    multi(d, 3, 5);

    delay(100000);
}
