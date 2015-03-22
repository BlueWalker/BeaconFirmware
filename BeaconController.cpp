
#include "BeaconController.h"
#include "GPIOPinInitMode.h"
#include "BeaconCommon.h"

#include "softdevice_handler.h"
#include "string.h"


BeaconController::BeaconController(ModeController& modeController) :
  modeController(modeController)
{
  // Initialize the SoftDevice handler module.
  SOFTDEVICE_HANDLER_INIT(NRF_CLOCK_LFCLKSRC_XTAL_20_PPM, false);

  // Enable BLE stack 
  uint32_t err_code;
  ble_enable_params_t ble_enable_params;
  memset(&ble_enable_params, 0, sizeof(ble_enable_params));
  ble_enable_params.gatts_enable_params.service_changed = false;
  err_code = sd_ble_enable(&ble_enable_params);
  APP_ERROR_CHECK(err_code);

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
