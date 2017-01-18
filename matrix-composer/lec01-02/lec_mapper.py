def scene(i, dots):
	i = str(i)
	scenenumb = 'scene%s' % i
	
	result = '''
byte %s[8] ={
%s
};
''' % (scenenumb, dots)
	
	return result

def scenefunc(i, s = 10):
	result = '''
	showScene(scene%s, %s);  
	''' % (i, s)
	
	return result

body = '''
void setup() {
  for(int pin = 0;pin<22;pin++){
    pinMode(pin,OUTPUT);
  for(int pin = 14;pin<22;pin++){
    digitalWrite(pin,LOW);
  }
  for(int pin = 0;pin<8;pin++){
    digitalWrite(pin,HIGH);
  }
}
}

void setonoff(byte state){
  for(int i = 0;i<8;i++){
    int a = ((state>>i&0x01)==0x01? LOW:HIGH);
    digitalWrite(i+14,a);
  }
}

void setScene(byte scene[8]) {
  for(int i =0 ;i<8;i++){
    setonoff(scene[i]);
    digitalWrite(i,HIGH);
    delay(1);
    digitalWrite(i,LOW);
  }
}

void showScene(byte scene[8], int duration) {
  for(int i =0 ;i<duration/2.5;i++){
    setScene(scene);
  }
}

void loop() {
'''

dots = [
'''
0b10000001,
0b10000001,
0b00000000,
0b10000001,
0b10000001,
0b10010001,
0b00111000,
0b10111001
''',
    ]

for i in range(len(dots)):
	s = scene(i, dots[i])
	print(s);

print(body)

for i in range(len(dots)):
	print(scenefunc(i))

print("}")
