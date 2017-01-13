                       
byte scene000[8]  =   {0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000};

byte scene001[8]  =   {0b11111111,
                       0b11111111,
                       0b11111111,
                       0b11111111,
                       0b11111111,
                       0b11111111,
                       0b11111111,
                       0b11111111};
                       
byte scene011[8]  =   {0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00010000};

byte scene012[8]  =   {0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00010000,
                       0b00000000};

byte scene013[8]  =   {0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00010000,
                       0b00000000,
                       0b00000000};

byte scene014[8]  =   {0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00010000,
                       0b00000000,
                       0b00000000,
                       0b00000000};

byte scene015[8]  =   {0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00010000,
                       0b00000000,
                       0b00000000,
                       0b00000000,
                       0b00000000};

byte scene020[8]  =   {0b00000000,
                       0b00000000,
                       0b00010000,
                       0b00101000,
                       0b00010000,
                       0b00000000,
                       0b00000000,
                       0b00000000};

byte scene021[8]  =   {0b00000000,
                       0b00010000,
                       0b00111000,
                       0b01101100,
                       0b00111000,
                       0b00010000,
                       0b00000000,
                       0b00000000};

byte scene022[8]  =   {0b00010000,
                       0b00111000,
                       0b01101100,
                       0b11000110,
                       0b01101100,
                       0b00111000,
                       0b00010000,
                       0b00000000};

byte scene023[8]  =   {0b00110000,
                       0b01001100,
                       0b11000110,
                       0b10000011,
                       0b11000110,
                       0b01101100,
                       0b00111000,
                       0b00000000}; 

byte scene024[8]  =   {0b00010000,
                       0b00000100,
                       0b10000010,
                       0b10000001,
                       0b10000010,
                       0b01000100,
                       0b00010000,
                       0b00000000};  

byte scene031[8]  =   {0b10000001,
                       0b10000001,
                       0b10000001,
                       0b11111111,
                       0b10000001,
                       0b10000001,
                       0b10000001,
                       0b10000001};

byte scene032[8]  =   {0b10000000,
                       0b10000000,
                       0b10000000,
                       0b11111111,
                       0b10000001,
                       0b10000001,
                       0b10000001,
                       0b10000001};

byte scene033[8]  =   {0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000};
                       
byte scene034[8]  =   {0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000,
                       0b10000000};

byte scene035[8]  =   { 0b01000000,
                        0b01000000,
                        0b01000000,
                        0b01000000,
                        0b01000000,
                        0b01000000,
                        0b01000000,
                        0b01000000};

                                                                                               
void setup() {
  // put your setup code here, to run once:
  for(int pin = 0;pin<22;pin++){
    pinMode(pin,OUTPUT);
  }//사용되는 핀들을 모두 출력으로 지정합니다.
  for(int pin = 14;pin<22;pin++){
    digitalWrite(pin,LOW);
//    delay(100);
  }
  for(int pin = 0;pin<8;pin++){
    digitalWrite(pin,HIGH);
//    delay(100);
  }
  //위의 두 for문은 약간의 start스크린처럼 보이기 위함입니다.
}

void setonoff(byte state){
  for(int i = 0;i<8;i++){
    int a = ((state>>i&0x01)==0x01? LOW:HIGH);
    digitalWrite(i+14,a);
  }
}//1byte의 각 비트를 핀의 HIGH LOW로 바꿔주기 위한 코드입니다.

void setScene(byte scene[8]) {
  for(int i =0 ;i<8;i++){
    setonoff(scene[i]);
    digitalWrite(i,HIGH);
    delay(1);
    digitalWrite(i,LOW);
  }//각층을 순차적으로 출력하기 위함입니다.
}

void showScene(byte scene[8], int duration) {
  for(int i =0 ;i<duration/2.5;i++){
    setScene(scene);
  }
}

void loop() {
//  showScene(scene000, 100);
//  showScene(scene001, 100);
  showScene(scene011, 10);
  showScene(scene012, 20);
  showScene(scene013, 40);
  showScene(scene014, 80);
  showScene(scene015, 160);
//  showScene(scene014, 40);
//  showScene(scene013, 30);
//  showScene(scene012, 20);
  showScene(scene020, 5);
  showScene(scene021, 10);
  showScene(scene022, 40);
  showScene(scene023, 80);
  showScene(scene024, 160);
  showScene(scene000, 320);
  showScene(scene031, 40);
  showScene(scene032, 40);
  showScene(scene033, 40);
  showScene(scene034, 40);  

}
