#include "stdint.h"

struct BeaconInfo
{
  uint8_t deviceType;
  uint8_t advDataLength;
  uint8_t uuid[16];
  uint16_t majorValue;
  uint16_t minorValue;
  uint8_t measuredRSSI;
};
