/*
   SimpleSender.cpp

    Demonstrates sending IR codes in standard format with address and command
    An extended example for sending can be found as SendDemo.

    Copyright (C) 2020-2021  Armin Joachimsmeyer
    armin.joachimsmeyer@gmail.com

    This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.

    MIT License
*/
#include <Arduino.h>

/*
   Define macros for input and output pin etc.
*/
#include "PinDefinitionsAndMore.h"

//#define SEND_PWM_BY_TIMER
//#define USE_NO_SEND_PWM

#include <IRremote.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);

  // Just to know which program is running on my Arduino
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

  /*
     The IR library setup. That's all!
  */
  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

  Serial.print(F("Ready to send IR signals at pin "));
  Serial.println(IR_SEND_PIN);
}

/*
   Set up the data to be sent.
   For most protocols, the data is build up with a constant 8 (or 16 byte) address
   and a variable 8 bit command.
   There are exceptions like Sony and Denon, which have 5 bit address.
*/
uint16_t sAddress = 0x0102;
uint8_t sCommand = 0x34;

uint16_t sAddress1 = 0x0101;
uint8_t sCommand1 = 0x35;

uint16_t sAddress2 = 0x0103;
uint8_t sCommand2 = 0x36;

uint8_t sRepeats = 0;

void loop() {

  Serial.println(F("Send NEC with 16 bit address"));
  Serial.flush();

  // Results for the first loop to: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
  IrSender.sendNEC(sAddress, sCommand, sRepeats);
  delay(1000);
  IrSender.sendNEC(sAddress1, sCommand1, sRepeats);
  delay(1000);
  IrSender.sendNEC(sAddress2, sCommand2, sRepeats);

  /*
     If you cannot avoid to send a raw value directly like e.g. 0xCB340102 you must use sendNECRaw()
  */
  //    Serial.println(F("Send NECRaw 0xCB340102"));
  //    IrSender.sendNECRaw(0xCB340102, sRepeats);

  delay(1000);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
}
