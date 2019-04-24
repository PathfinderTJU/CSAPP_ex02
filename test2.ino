#include <stdio.h>
#include <string.h>
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

void transferFloat(float* f){
    union{//联合体，用于显示浮点数在内存中的实际存储形式
        float input;
        long output;//用来映射结果的int
    }data;
  
    data.input = *f;//只为float赋值
    char result[33] = "";
    for (int i = 0 ; i < 32 ; i++){
        int temp = data.output & 0x1;//获得当前最低位的数
        result[31-i] = (char) (temp + '0');//拼接为字符串
        data.output = data.output >> 1;//右移，获取下一位
    }
    printf("float: %s\n", result);
}

void transferDouble(double* d){
    union{
        double input;
        long output;
    }data;

    data.input = *d;
    char result[33] = "";
    for (int i = 0 ; i < 32 ; i++){
        int temp = data.output & 0x1;
        result[31-i] = (char) (temp + '0');
        data.output = data.output >> 1;
    }
    printf("double: %s\n", result);
}

void setup() {
  Serial.begin(115200);
  printf_begin();
}

void loop(){
    float b1 = 1.1f;
    double c1 = 1.1d;
    float* pointer_b1 = &b1;
    double* pointer_c1 = &c1;
    
    printf("Test 2.1\n");
    transferFloat(pointer_b1);

    printf("Test 2.2\n");
    transferDouble(pointer_c1);

    delay(110000);
}
