#ifndef MODE_INTERFACE_H_
#define MODE_INTERFACE_H_

#include "ModeController.h"

class ModeController;

class ModeInterface
{
public:
  virtual ~ModeInterface()
  {
  }
  
  virtual void NextMode(ModeController* pModeController = 0) = 0;

};

#endif // MODE_INTERFACE_H_

