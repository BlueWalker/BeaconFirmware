#ifndef TRANSMIT_MODE_H_
#define TRANSMIT_MODE_H_

#include "ModeInterface.h"
#include "ModeController.h"

class TransmitMode : public ModeInterface
{
public:
  TransmitMode();
  virtual ~TransmitMode();
  
  virtual void NextState(ModeController* pModeController = 0);
};

#endif // TRANSMIT_MODE_H_
