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

void normalized(float* f){
    union{
        double input;
        long output;
    }data;

    data.input = *f;
    char result[33] = "";
    for (int i = 0 ; i < 32 ; i++){
        int temp = data.output & 0x1;
        result[31-i] = (char) (temp + '0');
        data.output = data.output >> 1;
    }
    printf("Normalized: %s\n", result);
}

void Denomalized(float* f){
    union{
        double input;
        long output;
    }data;

    data.input = *f;
    char result[33] = "";
    for (int i = 0 ; i < 32 ; i++){
        int temp = data.output & 0x1;
        result[31-i] = (char) (temp + '0');
        data.output = data.output >> 1;
    }
    printf("Denomalized: %s\n", result);
}

void Infinity(float* f){
    union{
        double input;
        long output;
    }data;

    data.input = *f;
    char result[33] = "";
    for (int i = 0 ; i < 32 ; i++){
        int temp = data.output & 0x1;
        result[31-i] = (char) (temp + '0');
        data.output = data.output >> 1;
    }
    printf("Infinity: %s\n", result);
}

void notANumber(float* f){
    union{
        double input;
        long output;
    }data;

    data.input = *f;
    char result[33] = "";
    for (int i = 0 ; i < 32 ; i++){
        int temp = data.output & 0x1;
        result[31-i] = (char) (temp + '0');
        data.output = data.output >> 1;
    }
    printf("Nan: %s\n", result);
}

void setup() {
  Serial.begin(115200);
  printf_begin();
}

void loop(){
    printf("Test 3\n");
    float nor = 3.14f;
    float deno = 0.000000000000000000000000000000000000000001f;
    float infi = 1/0.0f;
    float nan = 0/0.0f;

    float* pointer_nor = &nor;
    float* pointer_deno = &deno;
    float* pointer_infi = &infi;
    float* pointer_nan = &nan;

    normalized(pointer_nor);
    Denomalized(pointer_deno);
    Infinity(pointer_infi);
    notANumber(pointer_nan);

    delay(100000);
}
