#include <Arduino.h>
#include <SoftSerial.h>
#include <TinyPinChange.h>

const int rx = -3;
const int tx = 1;
const int x = 3;
const int y = 2;
const int z = 0;

int val1 = analogRead(x);
int val2 = analogRead(y);
int val3 = analogRead(z);

SoftwareSerial mySerial(rx,tx);

int i=0;
char buf[12];

void setup()
{
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    //pinMode(rx,INPUT);
    pinMode(tx,OUTPUT);
    pinMode(x, INPUT); //P3 not necessary except to map pins in sketch
    pinMode(y, INPUT); //P4
    pinMode(z, INPUT); //P5
    mySerial.begin(9600);
}

void loop() {
    if (mySerial.available()) {
        xmap = map(val1, 115, 870, 0, 255);
        ymap = map(val2, 115, 870, 0, 255);
        zmap = map(val3, 115, 870, 0, 255);
        mySerial.write('x%9d' % analogRead(x));
        mySerial.write('y%9d' % analogRead(y));
        mySerial.write('z%9d' % analogRead(z));
        delay(100);
    }
}