#define CLEAR				0b0000000001
#define CURSOR_HOME 0b0000000010

//Set the data pins
const int db0 = 0;
const int db1 = 1;
const int db2 = 2;
const int db3 = 3;
const int db4 = 4;
const int db5 = 5;
const int db6 = 6;
const int db7 = 7;
const int rw	= 8;
const int rs	= 9;

int character[8]; 

/*
	Function prototypes
*/
void initLCD();

void setup()
{
  /* add setup code here */
	pinMode(db0, OUTPUT);
	pinMode(db1, OUTPUT);
	pinMode(db2, OUTPUT);
	pinMode(db3, OUTPUT);
	pinMode(db4, OUTPUT);
	pinMode(db5, OUTPUT);
	pinMode(db6, OUTPUT);
	pinMode(db7, OUTPUT);
	pinMode(rw,	 OUTPUT);
	pinMode(rs,  OUTPUT);

	//Initialize the LCD
	initLCD();
}

void loop()
{

}
/**
 *Initialize the LCD and sets it to 4-bit mode
 */
void initLCD() {
	//Wait time > 15ms
	delay(20);
	digitalWrite(db4, HIGH);
	digitalWrite(db5, HIGH);
	digitalWrite(db6, LOW);
	digitalWrite(db7, LOW);
	digitalWrite(rw, LOW);
	digitalWrite(rs, LOW);
	//Wait time > 4.1ms
	delay(5);
	digitalWrite(db4, HIGH);
	digitalWrite(db5, HIGH);
	digitalWrite(db6, LOW);
	digitalWrite(db7, LOW);
	digitalWrite(rw, LOW);
	digitalWrite(rs, LOW);
	//Wait time > 100us
	delay(1);
	digitalWrite(db4, HIGH);
	digitalWrite(db5, HIGH);
	digitalWrite(db6, LOW);
	digitalWrite(db7, LOW);
	digitalWrite(rw, LOW);
	digitalWrite(rs, LOW);
	//No Wait
	digitalWrite(db4, LOW);
	digitalWrite(db5, HIGH);
	digitalWrite(db6, LOW);
	digitalWrite(db7, LOW);
	digitalWrite(rw, LOW);
	digitalWrite(rs, LOW);
	
	digitalWrite(db4, LOW);
	digitalWrite(db5, HIGH);
	digitalWrite(db6, LOW);
	digitalWrite(db7, LOW);
	digitalWrite(rw, LOW);
	digitalWrite(rs, LOW);

	//Sets it to two line 4 bit
	digitalWrite(db6, HIGH);
	digitalWrite(db7, HIGH);
	digitalWrite(rw, LOW);
	digitalWrite(rs, LOW);

	//Clear
	clear();

	//Set DDRAM address to 0
	digitalWrite(db4, LOW);
	digitalWrite(db5, LOW);
	digitalWrite(db6, LOW);
	digitalWrite(db7, HIGH);
	digitalWrite(rw, LOW);
	digitalWrite(rs, LOW);

	//Clear
	clear();

	//Set cursor 
	digitalWrite(db4, HIGH);
	digitalWrite(db5, LOW);
	digitalWrite(db6, LOW);
	digitalWrite(db7, LOW);
	digitalWrite(rw, LOW);
	digitalWrite(rs, LOW);
}


void clear (){
  digitalWrite(rs, LOW);
  digitalWrite(rw, LOW);
  digitalWrite(db7, LOW);
  digitalWrite(db6, LOW);
  digitalWrite(db5, LOW);
  digitalWrite(db4, LOW);

  digitalWrite(rs, LOW);
  digitalWrite(rw, LOW);
  digitalWrite(db7, LOW);
  digitalWrite(db6, LOW);
  digitalWrite(db5, LOW);
  digitalWrite(db4, HIGH);
}

void writeStringLCD(){

}


//Write character to the LCD 
void writeDataLCD(char c){
  int ascVal = c;
  decimal_to_binary(ascVal);
  digitalWrite(rs, HIGH);
  digitalWrite(rw, LOW);
  digitalWrite(db7, character[0]);
  digitalWrite(db6, character[1]);
  digitalWrite(db5, character[2]);
  digitalWrite(db4, character[3]);

  digitalWrite(rs, HIGH);
  digitalWrite(rw, LOW);
  digitalWrite(db7, character[4]);
  digitalWrite(db6, character[5]);
  digitalWrite(db5, character[6]);
  digitalWrite(db4, character[7]);
}

void decimal_to_binary(int n){
  int i;
  for (i = 0; i < 8; i++){
    if ( n % 2 == 0){
      character[7-i] = 0;
    }
    else {
      character[7-i] = 1;
    }
    n = n/2;
  }
}


