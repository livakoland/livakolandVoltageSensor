#include "livakolandVoltageSensor.h"

livakolandVoltageSensor::livakolandVoltageSensor(int pin, float vRef, float adcCorrection, float multiplier) {
  _pin = pin;
  _vRef = vRef;
  _adcCorrection = adcCorrection;
  _multiplier = multiplier;
}

void livakolandVoltageSensor::begin() {
  analogReadResolution(12);
  pinMode(_pin, INPUT);
}

float livakolandVoltageSensor::readVoltage() {
  return readPinVoltage() * _multiplier;
}

float livakolandVoltageSensor::readPinVoltage() {
  int adcValue = analogRead(_pin);
  return (adcValue / 4095.0) * _vRef * _adcCorrection;
}

int livakolandVoltageSensor::readADC() {
  return analogRead(_pin);
}

void livakolandVoltageSensor::setADCCorrection(float correction) {
  _adcCorrection = correction;
}

void livakolandVoltageSensor::setMultiplier(float multiplier) {
  _multiplier = multiplier;
}

void livakolandVoltageSensor::setVRef(float vRef) {
  _vRef = vRef;
}
