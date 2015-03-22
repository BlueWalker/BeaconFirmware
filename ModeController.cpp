
#include "ModeController.h"

ModeController::ModeController() : pCurrentMode(0)
{
}
 
ModeController::~ModeController()
{
}
 
void ModeController::NextMode()
{
  this->pCurrentMode->NextMode(this);
}

const ModeInterface& ModeController::GetMode() const
{
  return *(this->pCurrentMode);
}
  
void ModeController::SetMode(ModeInterface* pMode)
{
  // Free the current mode
  delete this->pCurrentMode;
  
  this->pCurrentMode = pMode;
}
