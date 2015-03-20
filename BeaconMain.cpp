
#include "BeaconController.h"
#include "ModeController.h"

int main()
{
  ModeController* pModeController = new ModeController();
  
  BeaconController beaconController(*pModeController);
  
  beaconController.Run();

  return 0;
}
