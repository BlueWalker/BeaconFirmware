#ifndef GPIO_PIN_INIT_MODE_H_
#define GPIO_PIN_INIT_MODE_H_

#include "ModeInterface.h"
#include "ModeController.h"

class GPIOPinInitMode : public ModeInterface
{
public:
  GPIOPinInitMode(int pinNumber);
  virtual ~GPIOPinInitMode();
  
  virtual void NextMode(ModeController* pModeController = 0);

private:
  int pinNumber;
};

#endif // GPIO_PIN_INIT_MODE_H_
