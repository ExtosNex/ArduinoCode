   /*
Seven Segment Display Layout

       A
     _____
  F |     | B
    |  O  |
     ―――――
    |     | C
  E |     |
     ‾‾‾‾‾
       D

       T
     _____
  Y |     | U
    |  Z  |
     ―――――
    |     | V
  X |     |
     ‾‾‾‾‾
       W

*/

// Define Button Pins
const int buttonPin2 = 50;
const int buttonPin3 = 52;

// Define Pin Outputs for Seven Segment Display
const int A = 30;
const int B = 32;
const int C = 34;
const int D = 36;
const int E = 38;
const int F = 40;
const int O = 42;

const int T = 2;
const int U = 3;
const int V = 4;
const int W = 5;
const int X = 6;
const int Y = 7;
const int Z = 8;



// Counter Var
int count1 = 0;
int count2 = 0;

//Button State Var
int buttonState2;
int buttonState3;


//Defines Variables
void setup() {
  //debugging
  Serial.begin(9600);
  
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(O, OUTPUT);
  pinMode(T, OUTPUT);
  pinMode(U, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(W, OUTPUT);
  pinMode(X, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(Z, OUTPUT);
}
           

void loop() {
  //Checks Button State
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);

//If button2 is pressed, add +1 to count Var
  if (buttonState2 == HIGH) {
    count1++;
    Serial.print(count2);
    Serial.println(count1);

    //Calls the numberdisp() function
    numberdisp();
    //1 Minute Delay
  delay(60000);
  } else if

//If button3 is pressed, add -1 to count Var
    (buttonState3 == HIGH) {
    count1= 0;
    count2= 0;
    Serial.print(count2);
    Serial.println(count1);
    
    //Calls the numberdisp() function
    numberdisp();
    
  delay(100);
  } else{
    Serial.print(count2);
    Serial.println(count1);

    //Calls the numberdisp() function
    numberdisp();
    
  delay(100);
  }

// count1 range between 0 - 9
// If count increments from 9, count = 0
// If count decrements from 0, count = 9
  if (count1 == 10){
    count1 = 0;
    count2++;
  } else if(count1 < 0){
    if(count2 > 0){
    count1 = 9;
    count2--;
    } else {
      count1 = 0;
    }
  }

  if (count2 < 0){
    count2 = 0;
  } else if (count2 == 10){
   count2 = 0; 
  }
}

void numberdisp(){
//Checks the count1 Var and displays it in Screen1
  if (count1 == 0){
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(O, LOW);
  } else if (count1 == 1){
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(O, LOW);
  } else if(count1 == 2) {
    
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(O, HIGH);
  } else if (count1 == 3) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(O, HIGH);
  } else if (count1 == 4) {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(O, HIGH);
  } else if (count1 == 5) {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(O, HIGH);
  } else if (count1 == 6) {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(O, HIGH);
  } else if (count1 == 7) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(O, LOW);
  } else if (count1 == 8) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(O, HIGH);
  } else if (count1 == 9) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(O, HIGH);
  }


  //Checks the count2 Var and displays it in Screen2
  if (count2 == 0){
    digitalWrite(T, HIGH);
    digitalWrite(U, HIGH);
    digitalWrite(V, HIGH);
    digitalWrite(W, HIGH);
    digitalWrite(X, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(Z, LOW);
  } else if (count2 == 1){
    digitalWrite(T, LOW);
    digitalWrite(U, HIGH);
    digitalWrite(V, HIGH);
    digitalWrite(W, LOW);
    digitalWrite(X, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(Z, LOW);
  } else if(count2 == 2) {
    
    digitalWrite(T, HIGH);
    digitalWrite(U, HIGH);
    digitalWrite(V, LOW);
    digitalWrite(W, HIGH);
    digitalWrite(X, HIGH);
    digitalWrite(Y, LOW);
    digitalWrite(Z, HIGH);
  } else if (count2 == 3) {
    digitalWrite(T, HIGH);
    digitalWrite(U, HIGH);
    digitalWrite(V, HIGH);
    digitalWrite(W, HIGH);
    digitalWrite(X, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(Z, HIGH);
  } else if (count2 == 4) {
    digitalWrite(T, LOW);
    digitalWrite(U, HIGH);
    digitalWrite(V, HIGH);
    digitalWrite(W, LOW);
    digitalWrite(X, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(Z, HIGH);
  } else if (count2 == 5) {
    digitalWrite(T, HIGH);
    digitalWrite(U, LOW);
    digitalWrite(V, HIGH);
    digitalWrite(W, HIGH);
    digitalWrite(X, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(Z, HIGH);
  } else if (count2 == 6) {
    digitalWrite(T, HIGH);
    digitalWrite(U, LOW);
    digitalWrite(V, HIGH);
    digitalWrite(W, HIGH);
    digitalWrite(X, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(Z, HIGH);
  } else if (count2 == 7) {
    digitalWrite(T, HIGH);
    digitalWrite(U, HIGH);
    digitalWrite(V, HIGH);
    digitalWrite(W, LOW);
    digitalWrite(X, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(Z, LOW);
  } else if (count2 == 8) {
    digitalWrite(T, HIGH);
    digitalWrite(U, HIGH);
    digitalWrite(V, HIGH);
    digitalWrite(W, HIGH);
    digitalWrite(X, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(Z, HIGH);
  } else if (count2 == 9) {
    digitalWrite(T, HIGH);
    digitalWrite(U, HIGH);
    digitalWrite(V, HIGH);
    digitalWrite(W, LOW);
    digitalWrite(X, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(Z, HIGH);
  }
}

  
  
