/*
  RB-Dfr-720 :: Weatherproof Ultrasonic Sensor w/ Separate Probe
  http://www.robotshop.com/en/weatherproof-ultrasonic-sensor-separate-probe.html
*/

#define ECHOPIN 2// Pin to receive echo pulse
#define TRIGPIN 3// Pin to send trigger pulse

void setup(void)
{
  Serial.begin(9600);
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  
  digitalWrite(ECHOPIN, HIGH);
}

void loop(void)
{
  // Set the trigger pin to low for 2uS
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);

  // Send a 10uS high to trigger ranging
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);

  // Send pin low again
  digitalWrite(TRIGPIN, LOW);

  // Read in times pulse
  int distance = pulseIn(ECHOPIN, HIGH,26000);
  distance= distance/58;

  // Display values
  Serial.print(distance);
  Serial.println("   cm");

  // Wait 50mS before next ranging
  delay(50);
}

