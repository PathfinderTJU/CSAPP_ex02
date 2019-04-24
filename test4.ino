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

void printAddress(int* a[], int x, int y){
    for (int i = 0 ; i < x ; i++){
        printf("a[%d](%p): ", i, ((a) + (y * i)));//编译器的优化，地址加一个int数，会自动乘以int的大小2
        for (int j = 0 ; j < y ; j++){
            printf("%d(%p) ", a[i][j], (a)+ (i*y+j));
        }
        printf("\n");
    }
}

void showEle(int a[], int x){
    printf("The address of a[0]: %p\n", a);
    printf("The address of a[%d]: %p\n", x, a+x);
}

void pointerPrint(int* a, int n){
    for (int i = 0 ; i < n ; i++){
        printf("a[%d]: %d(%p)\n", i, *(a + i), (a + i));
    }
    *(a+5) = 10;
    printf("Modified a[5] by 10: *(a+5) = 10. Result a[5] = %d\n", a[5]);
}

void pointerShow(int* a[], int x, int y){
    for (int i = 0 ; i < x ; i++){
        for (int j = 0 ; j < y ; j++){
            printf("a[%d][%d]: %d(%p)\n", i, j, *(a + i*y + j), a + i*y + j);
        }
    }
}

void setup() {
  Serial.begin(115200);
  printf_begin();
}

void loop(){
    printf("Test 4.1\n");
    int a[5] = {1,5,2,1,3};
    int b[5] = {0,2,1,3,9};
    int c[5] = {9,4,7,2,0};
    int* d[3] = {a, b, c};
    printAddress(d, 3, 5);

    printf("Test 4.2\n");
    int t[6] = {1,2,3,4,5,6};
    showEle(t, 6);

    printf("Test 4.3\n");
    int m[5] = {1,2,3,4,5};
    pointerPrint(m, 5);
    int* dd[3] = {b, c, a};
    pointerShow(dd, 3, 5);

    delay(100000);
}
