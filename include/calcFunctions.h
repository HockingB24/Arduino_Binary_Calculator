/* Header File for Binary Calculator */


//Retrieves 3-bit integer number from Serial Monitor input (0-7)
int getNumFromInput();
//Retrieves binary array from 3-bit integer value (0-7)
void binaryArrayFromInt(int* array, int num, int size);
//Prints out binary array 
void printArray(int* array, int size);
//Lights up binary on board
void lightUpBinary(int* array, int startingNum, int size);
//Combines above functions to retrieve the number (for further calculation)
//AND lights up the breadboard in binary.
int getNumAndLightUp(int num1, int startingPort, int bitSize);
//Prints operation choices
void printOperations();
//Prints selected operation
void printSelectedOp(int op);
//Does operation and returns int answer
int doOperation(int num1, int num2, int op);