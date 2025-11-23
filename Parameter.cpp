/*! @file Parameter.h
 * @author Sascha Heimfarth
 */

#include "Parameter.h"

#include <cstdint>

#include "Config.h"

void Parameter::Store()
{
  // Variabeln für Autosampler
  this->StoreValue<uint8_t>("addrXAxis", this->addrXAxis);
  this->StoreValue<uint8_t>("addrYAxis", this->addrYAxis);
  this->StoreValue<uint8_t>("addrZAxis", this->addrZAxis);

  this->StoreValue<uint8_t>("readyXAxis", this->readyXAxis);
  this->StoreValue<uint8_t>("readyYAxis", this->readyYAxis);
  this->StoreValue<uint8_t>("readyZAxis", this->readyZAxis);

  this->StoreValue<uint8_t>("modeXAxis", this->modeXAxis);
  this->StoreValue<uint8_t>("modeYAxis", this->modeYAxis);
  this->StoreValue<uint8_t>("modeZAxis", this->modeZAxis);

  this->StoreValue<int>("xSpeed", this->xSpeed);
  this->StoreValue<int>("ySpeed", this->ySpeed);
  this->StoreValue<int>("zSpeed", this->zSpeed);

  this->StoreValue<int>("xRefSpeed", this->xRefSpeed);
  this->StoreValue<int>("xRefSpeed", this->xRefSpeed);
  this->StoreValue<int>("xRefSpeed", this->xRefSpeed);

  this->StoreValue<int>("tipCalXSpeed", this->tipCalXSpeed);
  this->StoreValue<int>("tipCalZSpeed", this->tipCalZSpeed);

  this->StoreValue<double>("tipCalXStart", this->tipCalXStart);
  this->StoreValue<double>("tipCalZStart", this->tipCalZStart);

  this->StoreValue<int>("tipCalXWeg", this->tipCalXWeg);
  this->StoreValue<int>("tipCalZWeg", this->tipCalZWeg);

  this->StoreValue<int>("tipCalAD", this->tipCalAD);

  this->StoreValue<double>("tipCalibInt", this->tipCalibInt);

  this->StoreValue<double>("xFaktor", this->xFaktor);
  this->StoreValue<double>("yFaktor", this->yFaktor);
  this->StoreValue<double>("zFaktor", this->zFaktor);

  this->StoreValue<double>("maxXAxis", this->maxXAxis);
  this->StoreValue<double>("maxYAxis", this->maxYAxis);
  this->StoreValue<double>("maxZAxis", this->maxZAxis);
}

void Parameter::Load()
{
  // Variabeln für Autosampler
  this->LoadValue<uint8_t>("addrXAxis", this->addrXAxis);
  this->LoadValue<uint8_t>("addrYAxis", this->addrYAxis);
  this->LoadValue<uint8_t>("addrZAxis", this->addrZAxis);

  this->LoadValue<uint8_t>("readyXAxis", this->readyXAxis);
  this->LoadValue<uint8_t>("readyYAxis", this->readyYAxis);
  this->LoadValue<uint8_t>("readyZAxis", this->readyZAxis);

  this->LoadValue<uint8_t>("modeXAxis", this->modeXAxis);
  this->LoadValue<uint8_t>("modeYAxis", this->modeYAxis);
  this->LoadValue<uint8_t>("modeZAxis", this->modeZAxis);

  this->LoadValue<int>("xSpeed", this->xSpeed);
  this->LoadValue<int>("ySpeed", this->ySpeed);
  this->LoadValue<int>("zSpeed", this->zSpeed);

  this->LoadValue<int>("xRefSpeed", this->xRefSpeed);
  this->LoadValue<int>("xRefSpeed", this->xRefSpeed);
  this->LoadValue<int>("xRefSpeed", this->xRefSpeed);

  this->LoadValue<int>("tipCalXSpeed", this->tipCalXSpeed);
  this->LoadValue<int>("tipCalZSpeed", this->tipCalZSpeed);

  this->LoadValue<double>("tipCalXStart", this->tipCalXStart);
  this->LoadValue<double>("tipCalZStart", this->tipCalZStart);

  this->LoadValue<int>("tipCalXWeg", this->tipCalXWeg);
  this->LoadValue<int>("tipCalZWeg", this->tipCalZWeg);

  this->LoadValue<int>("tipCalAD", this->tipCalAD);

  this->LoadValue<double>("tipCalibInt", this->tipCalibInt);

  this->LoadValue<double>("xFaktor", this->xFaktor);
  this->LoadValue<double>("yFaktor", this->yFaktor);
  this->LoadValue<double>("zFaktor", this->zFaktor);

  this->LoadValue<double>("maxXAxis", this->maxXAxis);
  this->LoadValue<double>("maxYAxis", this->maxYAxis);
  this->LoadValue<double>("maxZAxis", this->maxZAxis);
}
