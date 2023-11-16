// pin defines for Uno
//#define A 12
//#define B 11
//#define C 10
//#define D 9
//#define E 8
//int buttonPin = A0;

#define A 0 //Pin 5 (PB0) on ATtiny85
#define B 1 //Pin 6 (PB1) on ATtiny85
#define C 2 //Pin 7 (PB2) on ATtiny85
#define D 3 // //Pin 2 (PB3) on ATtiny85 
#define E 4 //Pin 3 (PB4) on ATtiny85




//int buttonPin = 0; // Pin 1 (PB5) on ATtiny85 
int pattern = 0;

#define PIN_COUNT 5

#define PIN_CONFIG 0
#define PIN_STATE 1

#define LED_COUNT 20

/*
   If you want to save bytes in SRAM, this could be a collection of bytes for each DDRx and PORTx
   on the AVR chip (up to 8 bits or lines) (8 lines would allow for 56 LEDs)
*/
int matrix[LED_COUNT][2][PIN_COUNT] = {
  /*
      Each row in this matrix respresents the pin modes and pin states for a single LED
  */
  //              PIN_CONFIG                          PIN_STATE
  //    A       B       C      D      E         A     B    C    D    E
  { { OUTPUT, OUTPUT, INPUT, INPUT, INPUT }, { HIGH, LOW, LOW, LOW, LOW } }, // AB 0 LED1
  { { OUTPUT, OUTPUT, INPUT, INPUT, INPUT }, { LOW, HIGH, LOW, LOW, LOW } }, // BA 1 LED2
  { { INPUT, OUTPUT, OUTPUT, INPUT, INPUT }, { LOW, HIGH, LOW, LOW, LOW } }, // BC 2 LED3
  { { INPUT, OUTPUT, OUTPUT, INPUT, INPUT }, { LOW, LOW, HIGH, LOW, LOW } }, // CB 3 LED4
  { { INPUT, INPUT, OUTPUT, OUTPUT, INPUT }, { LOW, LOW, HIGH, LOW, LOW } }, // CD 4 LED5
  { { INPUT, INPUT, OUTPUT, OUTPUT, INPUT }, { LOW, LOW, LOW, HIGH, LOW } }, // DC 5 LED6
  { { INPUT, INPUT, INPUT, OUTPUT, OUTPUT }, { LOW, LOW, LOW, HIGH, LOW } }, // DE 6 LED7
  { { INPUT, INPUT, INPUT, OUTPUT, OUTPUT }, { LOW, LOW, LOW, LOW, HIGH } }, // ED 7 LED8
  { { OUTPUT, INPUT, OUTPUT, INPUT, INPUT }, { HIGH, LOW, LOW, LOW, LOW } }, // AC 8 LED9
  { { OUTPUT, INPUT, OUTPUT, INPUT, INPUT }, { LOW, LOW, HIGH, LOW, LOW } }, // CA 9 LED10
  { { INPUT, INPUT, OUTPUT, INPUT, OUTPUT }, { LOW, LOW, HIGH, LOW, LOW } }, // CE 10 LED11
  { { INPUT, INPUT, OUTPUT, INPUT, OUTPUT }, { LOW, LOW, LOW, LOW, HIGH } },  // EC 11 LED12
  { { INPUT, OUTPUT, INPUT, OUTPUT, INPUT }, { LOW, HIGH, LOW, LOW, LOW } },  // BD 12 LED13
  { { INPUT, OUTPUT, INPUT, OUTPUT, INPUT }, { LOW, LOW, LOW, HIGH, LOW } },  // DB 13 LED14
  { { OUTPUT, INPUT, INPUT, OUTPUT, INPUT }, { HIGH, LOW, LOW, LOW, LOW } },  // AD 14 LED15
  { { OUTPUT, INPUT, INPUT, OUTPUT, INPUT }, { LOW, LOW, LOW, HIGH, LOW } },  // DA 15 LED16
  { { INPUT, OUTPUT, INPUT, INPUT, OUTPUT }, { LOW, HIGH, LOW, LOW, LOW } },  // BE 16 LED17
  { { INPUT, OUTPUT, INPUT, INPUT, OUTPUT }, { LOW, LOW, LOW, LOW, HIGH } },  // EB 17 LED18
  { { OUTPUT, INPUT, INPUT, INPUT, OUTPUT }, { HIGH, LOW, LOW, LOW, LOW } },  // AE 18 LED19
  { { OUTPUT, INPUT, INPUT, INPUT, OUTPUT }, { LOW, LOW, LOW, LOW, HIGH } }  // EA 19 LED20
};

void turnOn( int led ) {
  // set all the pin modes
  delayMicroseconds(100);
  pinMode( A, INPUT);
  pinMode( B, INPUT );
  pinMode( C, INPUT );
  pinMode( D, INPUT );
  pinMode( E, INPUT );

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  delayMicroseconds(100);

  pinMode( A, matrix[led][PIN_CONFIG][0] );
  pinMode( B, matrix[led][PIN_CONFIG][1] );
  pinMode( C, matrix[led][PIN_CONFIG][2] );
  pinMode( D, matrix[led][PIN_CONFIG][3] );
  pinMode( E, matrix[led][PIN_CONFIG][4] );
  // set all the pin states
  digitalWrite( A, matrix[led][PIN_STATE][0] );
  digitalWrite( B, matrix[led][PIN_STATE][1] );
  digitalWrite( C, matrix[led][PIN_STATE][2] );
  digitalWrite( D, matrix[led][PIN_STATE][3] );
  digitalWrite( E, matrix[led][PIN_STATE][4] );

  delayMicroseconds(100);

}

void turnOff() {
  pinMode( A, INPUT);
  pinMode( B, INPUT );
  pinMode( C, INPUT );
  pinMode( D, INPUT );
  pinMode( E, INPUT );

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
}

void setup() {
//Serial.begin(9600); 
pinMode(5, INPUT_PULLUP);

}

void loop() {
  //int rval = analogRead(A0);   //Read the analogue input
 // Serial.println(rval);    


if (analogRead(A0) > 1000) {
  pattern = 1;
  //Serial.print(pattern);
  //  Serial.println("pattern");  
}
  if (analogRead(A0) < 1000 && analogRead(A0) >630) {
  pattern = 2;
  //Serial.print(pattern);
  //  Serial.println("pattern");  
}

// if (analogRead(A0) < 630) {
//  pattern = 1;
//  //Serial.print(pattern);
//  //  Serial.println("pattern");  
//}
  
  
//if (rval < 400 && rval > 300) {
//  pattern = 2 ;
//  //Serial.print(pattern);
//  //  Serial.println("pattern");  
//}


if (pattern == 0){
  // Light up each LED one at a time
  for ( int i = 0; i < 20; i++ ) {
    turnOn( i );
    delay( 75);
  }
}

if (pattern == 1){
//  // Happy face
  for ( int i = 0; i < 250; i++ ) {
    turnOn( 2 );
    turnOn( 3 );
    turnOn( 6 );
    turnOn( 7 );
    turnOn( 10 );
    turnOn( 13 );
    turnOn( 15 );
    turnOn( 17 );
    turnOn( 18 );
    turnOff();
  }
}


if (pattern == 2){
//  //Heart
  for ( int i = 0; i < 250; i++ ) {
    turnOn( 1 );
    turnOn( 2 );
    turnOn( 3 );
    turnOn( 5 );
    turnOn( 6 );
    turnOn( 7 );
    turnOn( 9 );
    turnOn( 12 );
    turnOn( 14 );
    turnOn( 15 );
    turnOn( 16 );
    turnOff();
  }
}

if (pattern == 3){
  // Light up each column
  for ( int i = 0; i < 50; i++ ) {
    turnOn( 0 );
    turnOn( 1 );
    turnOn( 10 );
    turnOn( 11 );
    turnOff();
  }
  for ( int i = 0; i < 50; i++ ) {
    turnOn( 2 );
    turnOn( 3);
    turnOn( 12 );
    turnOn( 13 );
    turnOff();
  }
  for ( int i = 0; i < 50; i++ ) {
    turnOn( 4 );
    turnOn( 5);
    turnOn( 14 );
    turnOn( 15 );
    turnOff();
  }

  for ( int i = 0; i < 50; i++ ) {
    turnOn( 6 );
    turnOn( 7);
    turnOn( 16 );
    turnOn( 17 );
    turnOff();
  }
  for ( int i = 0; i < 50; i++ ) {
    turnOn( 8 );
    turnOn( 9);
    turnOn( 18 );
    turnOn( 19 );
    turnOff();
  }
}

}
