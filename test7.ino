#include <stdio.h>
using namespace std;

union ele{
    struct{
        int *p;
        int y;
    }e1;
    struct{
        int x;
        union ele *next;
    }e2;
};

int serial_putc( char c, struct __file * )
{
  Serial.write( c );
  return c;
}

void printf_begin(void)
{
  fdevopen( &serial_putc, 0 );
}

void printUnion(union ele* e){
    printf("Union ele:\n");
    printf("Total size: %d\n", sizeof(*e));
    printf("Elements size: ");
    printf("struct_e1(%p): %d\n", &((*e).e1), sizeof((*e).e1));
    printf("int *p(%p): %d\n", &((*e).e1.p), sizeof((*e).e1.p));
    printf("int y(%p): %d\n", &((*e).e1.y), sizeof((*e).e1.y));
    printf("struct_e2(%p): %d\n", &((*e).e2), sizeof((*e).e2));
    printf("int x(%p): %d\n", &((*e).e2.x), sizeof((*e).e2.x));
    printf("union ele* next(%p): %d\n", &((*e).e2.next), sizeof((*e).e2.next));
}

void setup() {
    Serial.begin(115200);
    printf_begin();
}

void loop(){
    printf("Test7 \n");
    union ele ele_test;
    union ele* p = &ele_test;
    printUnion(p);
    delay(100000);
}
