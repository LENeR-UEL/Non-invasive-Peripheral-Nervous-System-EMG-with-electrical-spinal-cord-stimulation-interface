//tSCS - Version  1.1 esp32 C3 supermini - 28 JAN 2024 using ECG (AD 8232) sensor 
//No buffer to MES - Time on = 60s
//With coil amplifier (trafo)

#include <Arduino.h>
#include <ArduinoJson.h>
#include <math.h>
#include <filters.h>  // available in: https://github.com/MartinBloedorn/libFilter

float EMG = 0;
int led = 8;

// tilt sensor
//int tilt = 6;  // tilt sensor - adjust the sensitivity in embedded potentiometer

//MES
float MValue = 0;  //MES - Myo Electrical Signal
float Voltage;
float x = 0;
float difficult = 16;  // Difficult to App inventor (16%)
float filteredval = 0;
float filteredval1 = 0;
float filteredval2 = 0;
float filteredval3 = 0;
float filteredval4 = 0;
float filteredval5 = 0;
float filteredval6 = 0;
float filteredval7 = 0;
float filteredval8 = 0;
float filteredval9 = 0;
float filteredval10 = 0;
float filteredval11 = 0;
float filteredval12 = 0;
float filteredval13 = 0;
float filteredval14 = 0;
float filteredval15 = 0;
float filteredval16 = 0;
float filteredval17 = 0;
float filteredval18 = 0;
float filteredval19 = 0;
float filteredval20 = 0;

float MES01 = 0;
float MES02 = 0;

float MES_X = 0;
float MES1 = 0;
float MES2 = 0;
float MESth = 0;

float MES_001A = 0;
float MES_001B = 0;
float MES_002A = 0;
float MES_002B = 0;

//MES Filter
const float f2 = 40.0;               //Cutoff frequency in Hz
const float f1 = 10.0;               //Cutoff frequency in Hz
const float sampling_time = 0.01;    //Sampling time in seconds.
IIR::ORDER order = IIR::ORDER::OD3;  // Butterworth - Oder (OD1 to OD4)
IIR::TYPE typeHP = IIR::TYPE::HIGHPASS;
Filter fHP(f1, sampling_time, order, typeHP);  //configure high pass filter (40 Hz)
Filter fLP(f2, sampling_time, order);          //configure low pass filter (10 Hz)

//tSCS
float th = 2000;     //Initial Threshold - to do not trigger
int intensity = 40;  //Initial PWM - FES intensity
int flag = 0;
int cont = 1;
int time_on = 60;  //initial FES time (60s)
float Freq_port = 1;
float off_port = 100;
int H1 = 1;
int H2 = 2;

void setup() {
  MValue = (analogRead(EMG));  //MES
  pinMode(led, OUTPUT);        //LED red

    digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);

  Serial.begin(9600);  //Initialize Serial Monitor

  //FES to H bridge
  pinMode(H1, OUTPUT);  //FES_1
  pinMode(H2, OUTPUT);  //FES_2
}

void MES_00()  //Read samples - Avoid create buffer in code, create false positive electrical stimulation activations
{
  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval1 = fLP.filterIn(Voltage);
  filteredval1 = fHP.filterIn(filteredval1);
  filteredval1 = abs(filteredval1);
  filteredval1 = filteredval1 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval2 = fLP.filterIn(Voltage);
  filteredval2 = fHP.filterIn(filteredval2);
  filteredval2 = abs(filteredval2);
  filteredval2 = filteredval2 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval3 = fLP.filterIn(Voltage);
  filteredval3 = fHP.filterIn(filteredval3);
  filteredval3 = abs(filteredval3);
  filteredval3 = filteredval3 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval4 = fLP.filterIn(Voltage);
  filteredval4 = fHP.filterIn(filteredval4);
  filteredval4 = abs(filteredval4);
  filteredval4 = filteredval4 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval5 = fLP.filterIn(Voltage);
  filteredval5 = fHP.filterIn(filteredval5);
  filteredval5 = abs(filteredval5);
  filteredval5 = filteredval5 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval6 = fLP.filterIn(Voltage);
  filteredval6 = fHP.filterIn(filteredval6);
  filteredval6 = abs(filteredval6);
  filteredval6 = filteredval6 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval7 = fLP.filterIn(Voltage);
  filteredval7 = fHP.filterIn(filteredval7);
  filteredval7 = abs(filteredval7);
  filteredval7 = filteredval7 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval8 = fLP.filterIn(Voltage);
  filteredval8 = fHP.filterIn(filteredval8);
  filteredval8 = abs(filteredval8);
  filteredval8 = filteredval8 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval9 = fLP.filterIn(Voltage);
  filteredval9 = fHP.filterIn(filteredval9);
  filteredval9 = abs(filteredval9);
  filteredval9 = filteredval9 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval10 = fLP.filterIn(Voltage);
  filteredval10 = fHP.filterIn(filteredval10);
  filteredval10 = abs(filteredval10);
  filteredval10 = filteredval10 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval11 = fLP.filterIn(Voltage);
  filteredval11 = fHP.filterIn(filteredval11);
  filteredval11 = abs(filteredval11);
  filteredval11 = filteredval11 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval12 = fLP.filterIn(Voltage);
  filteredval12 = fHP.filterIn(filteredval12);
  filteredval12 = abs(filteredval12);
  filteredval12 = filteredval12 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval13 = fLP.filterIn(Voltage);
  filteredval13 = fHP.filterIn(filteredval13);
  filteredval13 = abs(filteredval13);
  filteredval13 = filteredval13 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval14 = fLP.filterIn(Voltage);
  filteredval14 = fHP.filterIn(filteredval14);
  filteredval14 = abs(filteredval14);
  filteredval14 = filteredval14 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval15 = fLP.filterIn(Voltage);
  filteredval15 = fHP.filterIn(filteredval15);
  filteredval15 = abs(filteredval15);
  filteredval15 = filteredval15 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval16 = fLP.filterIn(Voltage);
  filteredval16 = fHP.filterIn(filteredval16);
  filteredval16 = abs(filteredval16);
  filteredval16 = filteredval16 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval17 = fLP.filterIn(Voltage);
  filteredval17 = fHP.filterIn(filteredval17);
  filteredval17 = abs(filteredval17);
  filteredval17 = filteredval17 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval18 = fLP.filterIn(Voltage);
  filteredval18 = fHP.filterIn(filteredval18);
  filteredval18 = abs(filteredval18);
  filteredval18 = filteredval18 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval19 = fLP.filterIn(Voltage);
  filteredval19 = fHP.filterIn(filteredval19);
  filteredval19 = abs(filteredval19);
  filteredval19 = filteredval19 * 100;
  delay(1);

  MValue = (analogRead(EMG));
  Voltage = ((((3.3 / 1024.0) * (MValue))));
  float filteredval20 = fLP.filterIn(Voltage);
  filteredval20 = fHP.filterIn(filteredval20);
  filteredval20 = abs(filteredval20);
  filteredval20 = filteredval20 * 100;
  delay(1);


  //10ms average -  build AWL to calculate the threshold
  MES01 = (filteredval1 + filteredval2 + filteredval3 + filteredval4 + filteredval5 + filteredval6 + filteredval7 + filteredval8 + filteredval9 + filteredval10) / 10;

  //10ms average -  build AWL to calculate the threshold
  MES02 = (filteredval11 + filteredval12 + filteredval13 + filteredval14 + filteredval15 + filteredval16 + filteredval17 + filteredval18 + filteredval19 + filteredval20) / 10;

  MES01 = MES01 * 10;  //adjusted AD 8232 ECG. 10 is good.
  MES02 = MES02 * 10;  //adjusted AD 8232 ECG. 10 is good.



  //MES_X - create average 20ms (like root mean square)
  MES_X = (MES01 + MES02) / 20;  //adjusted AD 8232 ECG. 20 is good
  // values must be between 1 and 3 during rest and greater than 10 during contraction.
  //tilt = digitalRead(14);
}

void tSCS_port() {
  for (float Freq_port = 1; Freq_port <= 30; Freq_port = Freq_port + 1)  
  {
    digitalWrite(led, HIGH);  //red led on
    digitalWrite(H1, HIGH);
    digitalWrite(H2, LOW);
    delayMicroseconds(intensity);
    digitalWrite(H1, LOW);
    digitalWrite(H2, LOW);
    //delayMicroseconds(5);  //interpulse 10us off time
    digitalWrite(H2, HIGH);
    digitalWrite(H1, LOW);
    delayMicroseconds(intensity);
    digitalWrite(H2, LOW);
    digitalWrite(H1, LOW);
    off_port = (100 - (intensity * 2));
    if (off_port <= 1) { off_port = 1; }
    delayMicroseconds(off_port);
    //FREq port 30 = 3 ms on - 10kHz.
    //FREq port 300 = 30 ms on - 10kHz.
  }
}

void loop() {

  //MES1 - RMS-40ms
  MES_00();
  MES_001A = MES_X;  //20ms
  MES_00();
  MES_001B = MES_X;  //20ms
  MES1 = (MES_001A + MES_001B) / 2;

  //MES2 - RMS-40ms
  MES_00();
  MES_002A = MES_X;  //20ms
  MES_00();
  MES_002B = MES_X;  //20ms
  MES2 = (MES_002A + MES_002B) / 2;

  //configure moving threshold
  th = (1 + (difficult / 100));
  MESth = th * MES1;

  // MESth = 2.8;
  //check "impedance" - if MES1 > 10, the red led will be on to warning about the impedance
  if (MES1 > 10) {
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    delay(50);
  }                                 //LED red
  else { digitalWrite(led, LOW); }  //LED red
  Serial.print(MESth);
  Serial.print(" ");
  Serial.println(MES2);


  if (MES2 >= MESth && MES1 <= 60 && flag == 0 && MESth > 3 && MES2 >= 2)  //01/17/2023 REMOVED "&& MES2 <= 2*MESth"
  {
    flag = 1;
    while (flag == 1 && cont <= time_on * 30) {
      tSCS_port();  //if tSCS = 3 ms, delay = 30.3
      delay(30.3);  //if tSCS = 30 ms, delay = 0.3
      cont++        //33ms
        ;
    }

    cont = 1;
    flag = 0;
    digitalWrite(led, LOW);
    delay(1);
    //red led off

    MES2 = 0;
 
  }
}
//end
