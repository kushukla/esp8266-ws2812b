
void setup(void){
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  setupHttpServer();
  
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  strip.begin(); 
  
  digitalWrite(LED_BUILTIN, LOW);   
}

void loop(void){
  server.handleClient();
  ledLoop();
}
