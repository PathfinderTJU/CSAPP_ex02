#include <stdio.h>

int serial_putc( char c, struct __file * )
{
  Serial.write( c );
  return c;
}

void printf_begin(void)
{
  fdevopen( &serial_putc, 0 );
}

void getIntAddress(int* i){
    printf("The address of int: %p\n", i);
}

void getFloatAddress(float* f){
    printf("The address of float: %p\n", f);
}

void getDoubleAddress(double* d){
    printf("The address of double: %p\n", d);
}

void getCharAddress(char* c){
    /*
     *对于char*类型的变量，直接cout会输出指针指向的字符串内容（char[]字符串）
     *若想输出char变量的地址，需要将它强制转换为void*或int*类型
     */
    void* temp = (void*)c;
    printf("The address of char: %p\n", temp);
}

void compare32and64(){
    short a;
    int b;
    float c;
    double d;
    char e;
    long f;
    long long g;
    void* h;

    printf("short: %x\n", sizeof(a));
    printf("int: %x\n", sizeof(b));
    printf("float: %x\n", sizeof(c));
    printf("double: %x\n", sizeof(d));
    printf("char: %x\n", sizeof(e));
    printf("long: %x\n", sizeof(f));
    printf("long long: %x\n", sizeof(g));
    printf("void*: %x\n", sizeof(h));
 
}

void setup() {
  Serial.begin(115200);
  printf_begin();
}

void loop(){
    printf("Test 1.1\n");
    int a1 = 1;
    float b1 = 1.1f;
    double c1 = 1.1d;
    char d1 = 'a';

    int* pointer_a1 = &a1;
    float* pointer_b1 = &b1;
    double* pointer_c1 = &c1;
    char* pointer_d1 = &d1;

    getIntAddress(pointer_a1);
    getFloatAddress(pointer_b1);
    getDoubleAddress(pointer_c1);
    getCharAddress(pointer_d1);

    printf("Test 1.2\n");
    compare32and64();

    delay(100000);
}
