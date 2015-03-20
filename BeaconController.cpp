
#include "BeaconController.h"
#include "GPIOPinInitMode.h"


BeaconController::BeaconController(ModeController& modeController) :
  modeController(modeController)
{
  // Initialize the SoftDevice handler module.

  // Enable BLE stack 

}

BeaconController::~BeaconController()
{

}

void BeaconController::Run()
{
  GPIOPinInitMode initMode(24);
  this->modeController.SetMode(&initMode);
  
  while(true)
  {
    this->modeController.NextMode();
  }
}

