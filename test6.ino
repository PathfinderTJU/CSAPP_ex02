#include <stdio.h>

struct stype_one{
    char *a;
    short b;
    double c;
    char d;
    float e;
    char f;
    long long g;
    void *h;
};

struct stype_two{
    double c;
    long long g;
    float e;
    char *a;
    void *h;
    short b;
    char d;
    char f;
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

void printOne(stype_one* s1){
    /*
     *对于char*类型的变量，直接cout会输出指针指向的字符串内容（char[]字符串）
     *若想输出char变量的地址，需要将它强制转换为void*或int*类型
     */
    char* pointer_d = &((*s1).d);
    char* pointer_f = &((*s1).f);
    void* temp_d = (void*)pointer_d;
    void* temp_f = (void*)pointer_f;
    printf("Struct type_one:\n");
    printf("Total size: %d\n", sizeof(*s1));
    printf("Elements size: ");
    printf("char *a(%p): %d\n", &((*s1).a), sizeof((*s1).a));
    printf("short b(%p): %d\n", &((*s1).b), sizeof((*s1).b));
    printf("double c(%p): %d\n", &((*s1).c), sizeof((*s1).c));
    printf("char d(%p): %d\n", temp_d, sizeof((*s1).d));
    printf("float e(%p): %d\n", &((*s1).e), sizeof((*s1).e));
    printf("char f(%p): %d\n", temp_f, sizeof((*s1).f));
    printf("long long(%p): %d\n", &((*s1).g), sizeof((*s1).g));
    printf("void *h(%p): %d\n", &((*s1).h), sizeof((*s1).h));
    printf("\n");
}

void printTwo(stype_two* s2){
    char* pointer_d = &((*s2).d);
    char* pointer_f = &((*s2).f);
    void* temp_d = (void*)pointer_d;
    void* temp_f = (void*)pointer_f;
    printf("Struct type_two:\n");
    printf("Total size: %d\n", sizeof(*s2));
    printf("Elements size: ");
    printf("double c(%p): %d\n", &((*s2).c), sizeof((*s2).c));
    printf("long long g(%p): %d\n", &((*s2).g), sizeof((*s2).g));
    printf("float e(%p): %d\n", &((*s2).e), sizeof((*s2).e));
    printf("char *a(%p): %d\n", &((*s2).a), sizeof((*s2).a));
    printf("void *h(%p): %d\n", &((*s2).h), sizeof((*s2).h));
    printf("short b(%p): %d\n", &((*s2).b), sizeof((*s2).b));
    printf("char d(%p): %d\n", temp_d, sizeof((*s2).d));
    printf("char f(%p): %d\n", temp_f, sizeof((*s2).f));
    printf("\n");
}

void setup() {
  Serial.begin(115200);
  printf_begin();
}

void loop(){
    stype_one s1;
    stype_two s2;

    stype_one* ps1 = &s1;
    stype_two* ps2 = &s2;

    printOne(ps1);
    printTwo(ps2);

    delay(100000);
}
