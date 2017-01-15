unsigned long lastTime=millis();
bool change=false;
uint8_t p=0;
uint32_t c=strip.Color(255,0,0);
uint8_t i=0, j=0;
int wait=500;
int width=5; //width
bool major=false;



//On new HTTP request for pattern change
void handlePattern(){
  digitalWrite(wifiStatusLed, 1);

  for (int i = 0; i < server.args(); i++) {
    Serial.print(server.argName(i));
    Serial.print(": ");
    Serial.println(server.arg(i));
  } 
  
  String tp=server.arg("p");
  if(tp.length()<=0 || tp.toInt()>5) return;
  p=tp.toInt();
  
  String tw=server.arg("wait");
  if(tw.length()>0) 
    wait=tw.toInt();

  String tr=server.arg("r");
  String tg=server.arg("g");
  String tb=server.arg("b");
  if(tr.length()>0 && tg.length()>0 && tb.length()>0)
    c=strip.Color(tr.toInt(), tg.toInt(), tb.toInt());

  tw=server.arg("width");
  if(tw.length()>0) 
    width=tw.toInt();

  change=true;
  i=0; j=0;lastTime=millis()-wait*2;

  server.send(200, "text/plain", "I am working it");
  digitalWrite(wifiStatusLed, 0);
}


//Color Wipe
void colorWipe(bool major){
  if(major)
    strip.setPixelColor(i++, c);
}

//Theater Chase
void theaterChase(bool major){
  if(major){
    i++;j=0;
    i%=width*2;
  }else{
    strip.setPixelColor(j,(j-i)%(width*2)<width?c:strip.Color(0,0,0));
    j++;
  }
}

void ledLoop(){
  if(i>=strip.numPixels())return;
  
/*  if(change){ 
    i=0; j=0;change=false;lastTime=millis()-wait*2;
  }*/

  major = false;
  if(millis()-lastTime>wait){
    major=true;
    lastTime=millis();
  }

  switch(p){
    case 0: //Color Wipe
        colorWipe(major);
        break;
    case 1: //Theater Chase
        theaterChase(major);
        break;
  }
  strip.show();
  
}


void testLedStrip(){
  for(int i=0;i<NUM_LEDS;i++){
    Serial.print("i");
    Serial.print("=");
    Serial.println(String(i));
    strip.setPixelColor(i, strip.Color(150,150,0)); // Moderately bright green color.
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(100); // Delay for a period of time (in milliseconds).
  }
}

