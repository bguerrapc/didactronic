char buf;
float tensao;
float tensao_lida;
// Uno Monitor Via Bluetooth
// By keuwlsoft:  www.keuwl.com  26th Sept 2015
// cc Attribution-ShareAlike
String colors[] = {"R0G0B0", "R0G150B0"}; //App Light colours for LOW and HIGH
String receive_chars = "abcdefghijkl"; //so app knows which data goes where
float voltage; //Assumes 0-1023 range over 5V
float tensao_digital;
float r = 10.0;
void setup()
{
  //Define os pinos dos leds como saida
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)
  {
    buf = Serial.read();
  }

  switch (buf)
  {
    case 'V':
      tensao_lida  = analogRead(0);
      tensao_digital = 5.0 * tensao_lida / 1024;
      tensao = tensao_digital / (1 / ( 1 + r));
      Serial.print("*Y");
      Serial.println("A tensão lida é: ");
      Serial.println(tensao_digital);
      break;
    case'O':
      Serial.print("*G"); //using 'G' as receive char for graph in app
      voltage = analogRead(1) * 0.0048828;
      Serial.print(String(voltage) + ",");
      Serial.print("*");
      //Pause before taking next measurement
      break;
  }
  delay(100);

}
