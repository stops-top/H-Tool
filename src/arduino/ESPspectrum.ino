/* ESP8266/32 Audio Spectrum Analyser
 * The MIT License (MIT) Copyright (c) 2017 by David Bird. 
 * The formulation and display of an Audio Spectrum using an ESp8266 or ESP32
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files 
 * (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, but not to use it commercially for profit making or to sub-license and/or to sell copies of the Software or to 
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:  
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software. 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE 
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
 * See more at http://dsbird.org.uk 
*/

// Works with https://github.com/martin-ger/adafruit_guide_fft FFT vizualizer

#include "arduinoFFT.h"

arduinoFFT FFT = arduinoFFT();

#define SAMPLES 256              //Must be a power of 2
#define SAMPLING_FREQUENCY 5000  //Hz, must be less than the ADC conversion time. Determines maximum frequency that can be analysed by the FFT.

const int MAX_CHARS = 65;              // Max size of the input command buffer
char commandBuffer[MAX_CHARS];

unsigned int sampling_frequency = SAMPLING_FREQUENCY;
unsigned int sampling_period_us = 1000000/SAMPLING_FREQUENCY;
unsigned long microseconds;
float samples[SAMPLES];
double vReal[SAMPLES];
double vImag[SAMPLES];

void parseCommand(char* command) {
  if (strcmp(command, "GET MAGNITUDES") == 0) {
    for (int i = 0; i < SAMPLES; i++) {
      Serial.println(vReal[i]);
    }
  }
  else if (strcmp(command, "GET SAMPLES") == 0) {
    for (int i = 0; i < SAMPLES; i++) {
      Serial.println(samples[i]);
    }
  }
  else if (strcmp(command, "GET FFT_SIZE") == 0) {
    Serial.println(SAMPLES);
  }
  else if (strcmp(command, "GET SAMPLE_RATE_HZ") == 0) {
    Serial.println(sampling_frequency);
  }
  else if (strstr(command, "SET SAMPLE_RATE_HZ ") != NULL) {
    sampling_frequency = atoi(command+(sizeof("SET SAMPLE_RATE_HZ ")-1));
    sampling_period_us = 1000000 / sampling_frequency;
  }
}

void parserLoop() {
  // Process any incoming characters from the serial port
  while (Serial.available() > 0) {
    char c = Serial.read();
    // Add any characters that aren't the end of a command (semicolon) to the input buffer.
    if (c != ';') {
      c = toupper(c);
      strncat(commandBuffer, &c, 1);
    }
    else
    {
      // Parse the command because an end of command token was encountered.
      parseCommand(commandBuffer);
      // Clear the input buffer
      memset(commandBuffer, 0, sizeof(commandBuffer));
    }
  }
}

void setup() {
  Serial.begin(115200);
  sampling_period_us = 1000000 / sampling_frequency;
}

void loop() {
  unsigned long endTime;
  int count = 0;

  // Sample loop
  for (int i = 0; i < SAMPLES; i++) {
    endTime = micros() + sampling_period_us;
    samples[i] = analogRead(A0); // A conversion takes about 1mS on an ESP8266
    vReal[i] = samples[i];
    vImag[i] = 0;
    while (micros() < endTime) { count++; }
  }

  // Compute FFT
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);

  parserLoop();
}
