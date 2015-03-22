#ifndef TRANSMIT_MODE_H_
#define TRANSMIT_MODE_H_

#include "ModeInterface.h"
#include "ModeController.h"
#include "ble_gap.h"

class TransmitMode : public ModeInterface
{
public:
  TransmitMode();
  virtual ~TransmitMode();
  
  virtual void NextMode(ModeController* pModeController = 0);
  
private:
  ble_gap_adv_params_t  bleAdvParams;
};

#endif // TRANSMIT_MODE_H_
