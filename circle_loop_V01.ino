//by Zaynab Zi

#include <Adafruit_NeoPixel.h>

//O/I initialisation

int ledPin = 6;
int encoderPin1 = 2;
int encoderPin2 = 3;
int encoderSwitchPin = 4;
int lednumb = 12;
long lastEncoded = 0;
int R = 255;
int B = 255;
int G =255;
int brightness =10;
int n=2;


Adafruit_NeoPixel Ring = Adafruit_NeoPixel(lednumb, ledPin, NEO_GRB + NEO_KHZ800);

void setup(){
Serial.begin(9600);  
Ring.begin();
Ring.setBrightness(brightness);
Ring.show(); //intialize all pixels to 'off'

}

void loop(){
 // color();
//num_led();
//TO_led();
//disp_led();
  for(int x =0; x<=11 ; x++){
  ring_g(x,1);
  Serial.println(x);
  delay(1000);
  }
}






void color(){
   for( int j=0;j<=12;j++){
   Ring.setPixelColor(j,R,G,B);
   Ring.show(); 
   delay(10);
    
   }
}




void TO_led(){
  for( int j=0; j<=lednumb ; j=j+2){
  Ring.setPixelColor(j,R,G,B);
  Ring.show();
  delay(1000);
  }
}  
void setColor(int startled, boolean state){
  int y = n+startled;
  if (startled<0){
     startled = 12+ startled;
     
  }
     if (startled>11){
     startled =0;
     
  }
  //if (startled==11){
  //setColor(startled+n-1,1);
 // }
      if(state){
         Ring.setPixelColor(startled,R,G,B);
         Ring.show();
         }
      else{
           Ring.setPixelColor(startled,0,0,0);
           Ring.show();
          }


}
 
void ring_g(int startled, boolean dir){
  if(dir){
{
   
      
        
      
    int y = n+startled;
      if (y >11){
      y = 0;
      }                
    setColor(startled-1,0);
    setColor(startled,1);
    setColor(y,1);
    setColor(y+1,0);
    Ring.show();
  }
  }
  
  else{
      
      int y = n+startled;
      setColor(y-1,1);
      setColor(startled,1);
      setColor(startled,0);
      setColor(y,0);
      Ring.show();
      }
     
}
