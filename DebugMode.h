#ifndef DEBUG_MODE_H_
#define DEBUG_MODE_H_

#include "ModeInterface.h"

class DebugMode : public ModeInterface
{
public:
  DebugMode();
  virtual ~DebugMode();
  
  virtual void NextState(ModeController* pModeController = 0);
};

#endif // DEBUG_MODE_H_
