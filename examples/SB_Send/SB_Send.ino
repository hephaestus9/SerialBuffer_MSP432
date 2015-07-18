#include <SerialBuffer.h>
#include <string.h>

char message[] = "Hello World!";
    
#define BUFFER_SIZE 64
byte buffer[BUFFER_SIZE];

// declare the serial buffer
SerialBuffer serialBuffer;

void setup()
{
  // set up the buffer storage and maximum size
  serialBuffer.buffer = buffer;
  serialBuffer.bufferSize = BUFFER_SIZE;
  
  // reset the buffer
  serialBuffer.reset();
  
  // bring up the serial port
  Serial.begin(9600);
  delay(100);
  
  // put message in buffer
  serialBuffer.startMessage();
  for (int i=0;i<sizeof(message);i++){
    serialBuffer.write(message[i]);
  }
  serialBuffer.endMessage();
  
  //send hex message over serial
  for(int i=0;i<sizeof(buffer);i++){
    Serial.print(buffer[i], HEX);
  }
  Serial.println("");
  
  //send regular message over serial
  for(int i=0;i<sizeof(buffer);i++){
    Serial.write(buffer[i]);
  }
  Serial.println("");
}

void loop()
{
   
}

