/*! @file modio.cpp
 * @author Sascha Heimfarth
 */

#include "ModbusIO.h"
#include "modio.h"
#include "../libconfig/Log.h"

bool modio::GetBitStatus(int address)
{
  uint8_t ret;
  this->io.readBits(address+512, &ret, 1);
  return ret;
}

bool modio::GetBit(int address)
{
  uint8_t ret;
  this->io.readBits(address, &ret, 1);
  return ret;
}

void modio::SetBit(int address)
{
  this->io.writeBit(address, 1);
}

void modio::DelBit(int address)
{
  this->io.writeBit(address, 0);
}

uint16_t modio::ReadRegister(int address)
{
  uint16_t ret;
  this->io.readRegisters(address, &ret, 1);
  return ret;
}
void modio::WriteRegister(int address, uint16_t value)
{
  this->io.writeRegister(address, value);
}

float modio::ReadAnalog(int address)
{
  float ret;
  this->io.readAnalog(address, &ret, 1);
  return ret;
}

void modio::WriteAnalog(int address, float value)
{
  this->io.writeAnalog(address, value);
}
