#include <Arduino.h>
#include <calcFunctions.h>
  
  //Retrieve number from serial monitor input
  int getNumFromInput(){
    Serial.print("\nPlease input a number from 0 to 7.\n");
    while (Serial.available() == 0){
    }
    int num1 = Serial.parseInt();
    while (num1 > 7 || num1 < 0){
        Serial.print("Wrong number. Please input a number from 0 to 7.\n");
        while (Serial.available() == 0){}
        num1 = Serial.parseInt();
    }
    Serial.print("Input: ");
    Serial.println(num1);
    return num1;
  }

//Returns pointer to array of binary representing integer val
  void binaryArrayFromInt(int* numBin, int num, int size){
    int i = size-1;
    while (num > 0){
        int bit = num%2;
        num /= 2;
        numBin[i] = bit;
        i--;
    }
    while (i >= 0){
      numBin[i] = 0;
      i--;
    }
  }

//Prints integer array of binary
void printArray(int* array, int size){
    Serial.print("Binary: ");
    for (int i = 0; i < size; i++){
        Serial.print(array[i]);
    }
    Serial.println("\n");
}

//Lights up the LED lights based on the starting port and bit length of light
void lightUpBinary(int* array, int startingNum, int size){
    for (int i = 0, j = startingNum; i < size; i++, j++){
        if (array[i]){
        digitalWrite(j, HIGH);
        }
  }
}

//Combines above functions -- Gets num from input, prints, lights up LED lights
int getNumAndLightUp(int num1, int startingPort, int bitSize){
  int* numBin = (int*) malloc(sizeof(int)*3);
  numBin[0] = 0;
  numBin[1] = 0;
  numBin[2] = 0;
  Serial.println(num1);
  binaryArrayFromInt(numBin, num1, 3);
  printArray(numBin, bitSize);
  lightUpBinary(numBin, startingPort, bitSize);
  return num1;
}

void printOperations(){
  Serial.println("Select Operation On Remote...");
  Serial.println("1: & (AND)");
  Serial.println("2: | (OR)");
  Serial.println("3: ^ (XOR)");
  Serial.println("4: + (PLUS)");
  Serial.println("5: - (MINUS)\n");
}

//Print selected operation 
void printSelectedOp(int op){
  switch(op){
    case 1:
      Serial.println("~~ & ~~\n");
      break;
    case 2:
      Serial.println("~~ | ~~\n");
      break;
    case 3:
      Serial.println("~~ ^ ~~\n");
      break;
    case 4:
      Serial.println("~~ + ~~\n");
      break;
    case 5:
      Serial.println("~~ - ~~\n");
      break;

    default:
      break; 
  }
}

int doOperation(int num1, int num2, int op){
  int ans = -1000;
  switch(op){
    case 1:
      ans = num1 & num2;
      break;
    case 2:
      ans = num1 | num2;
      break;
    case 3: 
      ans = num1 ^ num2;
      break;
    case 4:
      ans = num1 + num2;
      break;
    case 5:
      ans = num1 - num2;
      break;

    default:
      return ans;
  }
  return ans;
}