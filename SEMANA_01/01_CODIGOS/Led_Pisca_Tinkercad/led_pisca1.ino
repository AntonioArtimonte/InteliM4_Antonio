// C++ code
//
void setup()
{
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(11, HIGH);
  delay(400); // Wait for 400 millisecond(s)
  digitalWrite(11, LOW);
  delay(400); // Wait for 400 millisecond(s)
}