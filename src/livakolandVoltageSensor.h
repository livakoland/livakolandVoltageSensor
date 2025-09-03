#ifndef livakolandVoltageSensor_h
#define livakolandVoltageSensor_h

#include "Arduino.h"

class livakolandVoltageSensor {
  public:
    livakolandVoltageSensor(int pin, float vRef = 3.3, float adcCorrection = 1.28, float multiplier = 6.2);
    
    void begin();
    float readVoltage();
    float readPinVoltage();
    int readADC();
    
    void setADCCorrection(float correction);
    void setMultiplier(float multiplier);
    void setVRef(float vRef);
    
  private:
    int _pin;
    float _vRef;
    float _adcCorrection;
    float _multiplier;
};

#endif
