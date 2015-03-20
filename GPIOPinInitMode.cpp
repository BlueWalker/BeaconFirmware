#include "GPIOPinInitMode.h"

GPIOPinInitMode::GPIOPinInitMode(int pinNumber) :
  pinNumber(pinNumber)
{
}

GPIOPinInitMode::~GPIOPinInitMode()
{
}

void GPIOPinInitMode::NextMode(ModeController* pModeController)
{
  // Determine the next mode to run by looking at the value
  // of the pin at the specified pin number, then call
  // pModeController's NextMode() function.
  
}
