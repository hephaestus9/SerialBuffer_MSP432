#include <SerialBuffer.h>

#define BUFFER_SIZE 64
byte buffer[BUFFER_SIZE];

// declare the serial buffer
SerialBuffer serialBuffer;

void setup() {

  // set up the buffer storage and maximum size
  serialBuffer.buffer = buffer;
  serialBuffer.bufferSize = BUFFER_SIZE;

  // reset the buffer
  serialBuffer.reset();

  // bring up the serial port
  Serial.begin(9600);

}

void loop() {
  int maxBytes = Serial.available();
  while (maxBytes--) {

    byte inputByte = Serial.read();

    // present the input byte to the serial buffer for decoding
    // whenever receive() returns >= 0, there's a complete message
    // in the buffer ready for processing at offset zero.
    // (return value is message length)
    int bufferStatus = serialBuffer.receive(inputByte);

    if (bufferStatus >= 0) {

      // handle message
      // ...
      // ...

    }
  }
}
