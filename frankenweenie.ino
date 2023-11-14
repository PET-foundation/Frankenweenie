bool maximum_torque = true;

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

void stopMotors() {
  analogWrite(ena1, 0);
  analogWrite(ena2, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    Serial.print(command);

    switch (command) {
      case 'F':
        if (maximum_torque) {
          analogWrite(ena1, 255);
          analogWrite(ena2, 255);
        } else {
          analogWrite(ena1, 200); 
          analogWrite(ena2, 200);  
        }
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
      case 'B':
        if (maximum_torque) {
          analogWrite(ena1, 255);
          analogWrite(ena2, 255);
        } else {
          analogWrite(ena1, 200);  
          analogWrite(ena2, 200); 
        }
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
      case 'R':
        if (maximum_torque) {
          analogWrite(ena1, 255);
          analogWrite(ena2, 255);
        } else {
          analogWrite(ena1, 200); 
          analogWrite(ena2, 200);  
        }
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
      case 'L':
        if (maximum_torque) {
          analogWrite(ena1, 255);
          analogWrite(ena2, 255);
        } else {
          analogWrite(ena1, 200);  
          analogWrite(ena2, 200); 
        }
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
      case 'P':
        stopMotors();
        delay(100);
        break;
      case 'S':
        maximum_torque = false; 
        break;
      case 'O':
        maximum_torque = true;  
        break;
    }
  }
}