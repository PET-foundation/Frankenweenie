
int ena1 = 5;
int in1 = 6;
int in2 = 7;
int ena2 = 10;
int in3 = 8;
int in4 = 9;


void setup() {
  Serial.begin(9600);
  pinMode(ena1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void loop() {
 if (Serial.available() > 0) {
   char command = Serial.read();
   Serial.print(command);

   switch (command) {
     case 'F':
       analogWrite(ena1, 255);
       analogWrite(ena2, 255);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
       break;
     case 'B':
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
       break;
     case 'L':
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);
       break;
     case 'R':
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
       break;
   }
 }
}
