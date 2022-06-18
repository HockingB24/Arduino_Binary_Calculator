# Arduino Binary Calculator


Serves as both a CLI binary calculator and an Arduino binary calculator. Only accepts operands of up to three bits (0-7) and unsigned.


Allows for input of two operands using an Infrared remote and IR sensor on an Arduino. Performs &, |, ^, +, or - operations on the two operands. Each operand and the answer are displayed on-screen and also are illuminated in binary on the breadboard.


Instructions for building Arduino breadboard:
- LED Connections
  - Blues: 2-4
  - Yellow: 5-7
  - Green: 8-11
- The IR Receiver connects to Ground, 5V, and Pin 12 (G, R, Y)


Created as a Platform.io project on VSCode. The Platform.io extension is likely required to run.
