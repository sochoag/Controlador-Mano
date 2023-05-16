#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
  private:
    byte pwmPin;
    byte dirPin1;
    byte dirPin2;
    byte endstop1;
    byte endstop2;
    bool isMoving;

  public:
    Motor()
    {
    }

    void init(byte dir1, byte dir2, byte pwm, byte fc1, byte fc2)
    {
      pwmPin = pwm;
      dirPin1 = dir1;
      dirPin2 = dir2;
      endstop1 = fc1;
      endstop2 = fc2;

      pinMode(pwmPin, OUTPUT);
      pinMode(dirPin1, OUTPUT);
      pinMode(dirPin2, OUTPUT);
      pinMode(endstop1, INPUT_PULLUP);
      pinMode(endstop2, INPUT_PULLUP);
      Serial.println("Dedo Iniciado");
    }

    void forward(int duty)
    {
      digitalWrite(dirPin1, HIGH);
      digitalWrite(dirPin2, LOW);
      analogWrite(pwmPin, duty);
      isMoving = true;
    }

    void reverse(int duty)
    {
      digitalWrite(dirPin1, LOW);
      digitalWrite(dirPin2, HIGH);
      analogWrite(pwmPin, duty);
      isMoving = true;
    }

    void stop()
    {
      digitalWrite(dirPin1, LOW);
      digitalWrite(dirPin2, LOW);
      analogWrite(pwmPin, 0);
      isMoving = false;
    }

    bool getEndstop1()
    {
      return !digitalRead(endstop1);
    }

    bool getEndstop2()
    {
      return !digitalRead(endstop2);
    }

    bool moving()
    {
      return isMoving;
    }
};

#endif