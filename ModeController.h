#ifndef MODE_CONTROLLER_H_
#define MODE_CONTROLLER_H_

#include "ModeInterface.h"

class ModeInterface;

class ModeController
{
public:
  ModeController();
  
  virtual ~ModeController();
  
  virtual void NextMode();
  
  virtual const ModeInterface& GetMode() const;
  
  virtual void SetMode(ModeInterface* pMode);
  

protected:
  // Holds the current mode state of the beacon
  ModeInterface* pCurrentMode;
};

#endif // MODE_CONTROLLER_H_
