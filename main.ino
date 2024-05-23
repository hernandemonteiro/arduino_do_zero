#define BUTTON_ONE 10
#define LED_VERMELHO 4
#define LED_VERDE 2
#define LED_AMARELO 3
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

volatile int buttonPressed = LOW;

void setup()
{
  Serial.begin(9600);
  pinModes();
  piscaSequencia();
}

void loop()
{
  if (buttonPressed == HIGH)
  {
    Serial.println("Click!");
    piscaSequencia();
    buttonPressed = LOW;
  }
}

void pinModes()
{
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(BUTTON_ONE, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_ONE), buttonISR, FALLING);
}

void buttonISR()
{
  delay(50); // Debounce
  if (digitalRead(BUTTON_ONE) == LOW)
  {
    buttonPressed = HIGH;
  }
}

void piscaLed(int portaLed)
{
  digitalWrite(portaLed, HIGH);
  delay(UM_SEGUNDO);
  digitalWrite(portaLed, LOW);
  delay(MEIO_SEGUNDO);
}

void piscaSequencia()
{
  piscaLed(LED_VERMELHO);
  piscaLed(LED_VERDE);
  piscaLed(LED_AMARELO);
}
