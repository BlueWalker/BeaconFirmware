#include "TransmitMode.h"
#include "BeaconCommon.h"
#include "BeaconInfo.h"

#include "ble_advdata.h"

TransmitMode::TransmitMode()
{
  // Initialize data to be transmitted over Bluetooth
  uint8_t         flags = BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED;
  

  ble_advdata_manuf_data_t manuf_specific_data;
  manuf_specific_data.company_identifier = APP_COMPANY_IDENTIFIER; // 16-Bit code

  BeaconInfo beaconInfo;
  beaconInfo.deviceType = APP_DEVICE_TYPE;
  beaconInfo.advDataLength = APP_ADV_DATA_LENGTH;
  
  for(int i = 0; i < 16; i++)
  {
    beaconInfo.uuid[i] = APP_BEACON_UUID[i];
  }
  
  beaconInfo.majorValue = 0xFFFF;
  beaconInfo.minorValue = 0xFFFF;
  beaconInfo.measuredRSSI = APP_MEASURED_RSSI;


  manuf_specific_data.data.p_data        = reinterpret_cast<uint8_t*>(&beaconInfo);
  manuf_specific_data.data.size          = APP_BEACON_INFO_LENGTH;

  // Build and set advertising data.
  ble_advdata_t advData;
  memset(&advData, 0, sizeof(advData));

  advData.name_type               = BLE_ADVDATA_NO_NAME;
  advData.flags.size              = sizeof(flags);
  advData.flags.p_data            = &flags;
  advData.p_manuf_specific_data   = &manuf_specific_data;

  uint32_t err_code;
  err_code = ble_advdata_set(&advData, NULL);
  APP_ERROR_CHECK(err_code);

  // Initialize advertising parameters (used when starting advertising).
  memset(&bleAdvParams, 0, sizeof(bleAdvParams));

  bleAdvParams.type        = BLE_GAP_ADV_TYPE_ADV_NONCONN_IND;
  bleAdvParams.p_peer_addr = NULL;                             // Undirected advertisement.
  bleAdvParams.fp          = BLE_GAP_ADV_FP_ANY;
  bleAdvParams.interval    = NON_CONNECTABLE_ADV_INTERVAL;
  bleAdvParams.timeout     = APP_CFG_NON_CONN_ADV_TIMEOUT;
}

TransmitMode::~TransmitMode()
{
}

void TransmitMode::NextMode(ModeController* pModeController)
{
  // Call function to start advertising data if not advertising already
  uint32_t err_code;

  err_code = sd_ble_gap_adv_start(&bleAdvParams);
  APP_ERROR_CHECK(err_code);
  
  while(true)
  {
    // Power manage
    uint32_t err_code = sd_app_evt_wait();
    APP_ERROR_CHECK(err_code);
  }
}
