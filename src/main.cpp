/* TO BUILD:
LEDs Connect to pins 2 - 11
Blues: 2-4
Yellow: 5-7
Green: 8-11

The IR Receiver connects to Ground, 5V, and Pin 12 (G, R, Y)

*/

#include <Arduino.h>
#include <calcFunctions.h>
#include <IRremote.h>

#define OPERAND_SIZE 3
#define ANSWER_SIZE 4

//Defining the binary bits starting from the left. Ex) B1-B2-B3
#define BLUE1 2
#define BLUE2 3
#define BLUE3 4

#define YELLOW1 5
#define YELLOW2 6
#define YELLOW3 7

#define GREEN1 8
#define GREEN2 9
#define GREEN3 10
#define GREEN4 11 

int receiver = 12;
IRrecv irrecv(receiver);
decode_results results;


int translateNum(){
  while(true){
    switch(results.value){
      case 0xFF6897: return 0;    
      case 0xFF30CF: return 1;    
      case 0xFF18E7: return 2;    
      case 0xFF7A85: return 3;    
      case 0xFF10EF: return 4;    
      case 0xFF38C7: return 5;    
      case 0xFF5AA5: return 6;    
      case 0xFF42BD: return 7;    

      default: 
        Serial.println("Wrong number -- Restarting...");
        return 10;
    }// End Case
  }
}





void setup() {
  // Define pins
  pinMode(BLUE1, OUTPUT);
  pinMode(BLUE2, OUTPUT);
  pinMode(BLUE3, OUTPUT);

  pinMode(YELLOW1, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(YELLOW3, OUTPUT);

  pinMode(GREEN1, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(GREEN3, OUTPUT);
  pinMode(GREEN4, OUTPUT);

  //Begin serial monitor
  Serial.begin(9600);
  irrecv.enableIRIn(); 


}

void loop() {
  int ans = -10;
  int num1 = -10;
  int num2 = -10;
  delay(500);
  for (int i = 1; i <= 11; i++){
    digitalWrite(i, LOW);
  }
  delay(500);
  Serial.println("Please input a number from 0 to 7.");
  while(num1 < 0){
    if (irrecv.decode(&results)){
      num1 = translateNum(); 
      delay(500);
      irrecv.resume();
    }  
  }
  if (num1 == 10){
    return;
  }
  //Get First Operand 
  getNumAndLightUp(num1, BLUE1, OPERAND_SIZE);

  delay(500);
  
  //Get operation 
  printOperations();
  int op = -10;
  while(op < 0){
    if (irrecv.decode(&results)){
      op = translateNum(); 
      delay(500);
      irrecv.resume();
    }  
  }
  if (op == 10){
    return;
  }
  printSelectedOp(op);

  //Get Second Operand 
  Serial.println("Please input a second number from 0 to 7.");
  while(num2 < 0){
    if (irrecv.decode(&results)){
      num2 = translateNum(); 
      delay(500);
      irrecv.resume();
    }  
  }
  if (num2 == 10){
    return;
  }
  //Get Second Operand 
  getNumAndLightUp(num2, YELLOW1, OPERAND_SIZE);

  ans = doOperation(num1, num2, op);
  if (ans < 0){
    Serial.println("Answer is negative -- This is unsigned only.");
    Serial.println("Restarting...");
    return;
  }
  else {
    Serial.print("Answer: ");
    Serial.println(ans);
    int* ansBin = (int*) malloc(sizeof(int)*4);
    ansBin[0] = 0;
    ansBin[1] = 0;
    ansBin[2] = 0;
    ansBin[3] = 0;
    binaryArrayFromInt(ansBin, ans, ANSWER_SIZE);
    printArray(ansBin, 4);
    lightUpBinary(ansBin, GREEN1, ANSWER_SIZE);
}
  delay(5000);

}