#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>

const int ir = 7;
const int led = 8;
int i = 0;
IRrecv irrecv(ir);
decode_results results;
unsigned long key = 0;
String a;
String arr[4] = {"0","1","2","3"};

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(led,OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key;

        switch(results.value){
          case 0xFFA25D:
          a = "CH-";
          break;
          case 0xFF629D:
          a = "CH";
          break;
          case 0xFFE21D:
          a = "CH+";
          break;
          case 0xFF22DD:
          a = "|<<";
          break;
          case 0xFF02FD:
          a = ">>|";
          break ;  
          case 0xFFC23D:
          a = ">|";
          break ;               
          case 0xFFE01F:
          a = "-";
          break ;  
          case 0xFFA857:
          a = "+";
          break ;  
          case 0xFF906F:
          a = "EQ";
          break ;  
          case 0xFF6897:
          a = "0";
          break ;  
          case 0xFF9867:
          a = "100+";
          break ;
          case 0xFFB04F:
          a = "200+";
          break ;
          case 0xFF30CF:
          a = "1";
          break ;
          case 0xFF18E7:
          a = "2";
          break ;
          case 0xFF7A85:
          a = "3";
          break ;
          case 0xFF10EF:
          a = "4";
          break ;
          case 0xFF38C7:
          a = "5";
          break ;
          case 0xFF5AA5:
          a = "6";
          break ;
          case 0xFF42BD:
          a = "7";
          break ;
          case 0xFF4AB5:
          a = "8";
          break ;
          case 0xFF52AD:
          a = "9";
          break ;      
        }
        key = results.value;
        Serial.println(a);
        if(arr[i].equals(a)){
          i++;
        }
        else{
          i=0;
        }
        if(i==4){
          digitalWrite(led,HIGH);
        }
        irrecv.resume(); 
  }

  
}





