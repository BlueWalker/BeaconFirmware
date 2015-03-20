#ifndef BEACON_CONTROLLER_H_
#define BEACON_CONTROLLER_H_

#include "ModeController.h"

class BeaconController
{
public:
  BeaconController(ModeController& modeContext);
  
  virtual ~BeaconController();
  
  virtual void Run();
  
private:
  // Handles moding for the beacon
  ModeController& modeController;
};

#endif // BEACON_CONTROLLER_H_
