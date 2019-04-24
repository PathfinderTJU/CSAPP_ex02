#include <stdio.h>
#include <math.h>
int serial_putc( char c, struct __file * )
{
  Serial.write( c );
  return c;
}

void printf_begin(void)
{
  fdevopen( &serial_putc, 0 );
}

double getTemperature(){
  return analogRead(0);
}

double getLight(){
  return analogRead(1);
}

void setup() {
    Serial.begin(115200);
    printf_begin();
    pinMode(3,OUTPUT);
}

//每个实验请单独进行，将其他实验的代码注释掉
void loop(){
//实验8.2代码
//    printf("Test 8.1: \n");
//    Serial.print("Temperature ADC: ");
//    Serial.println(getTemperature());
//    Serial.print("Light ADC: "); 
//    Serial.println(getLight());

//实验8.3
    for(int i = 255; i > 0; i--){    
      analogWrite(3, i);     
      delay(10);   
    }

//实验8.4
//    while (true){
//      double temp = getTemperature();
//      double virtual_value = 5*(temp/1023);
//      double temperature_value = (5 - virtual_value)/virtual_value * 10000;
//      double result = (1 / (log(temperature_value / 10000)/3435.0 + 1/298.15)) - 273.15;
//      Serial.print("Temperature: ");
//      Serial.println(result);
//      delay(100);
//    }
    
//实验8.5
      while(true){
        char command = Serial.read();
        delay(100);
        if (command == 'A'){
          analogWrite(3, 50);
        }else if(command == 'B'){
          analogWrite(3, 200);
        }else if(command == 'C'){
          analogWrite(3, 250);
        }
      }
      
    delay(10000);
}
