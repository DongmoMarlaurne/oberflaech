/**
 * @file Main.cpp
 * @author Sascha Heimfarth
 * @brief Analog IO Beispiel mithilfe des modio Modul.
 */

#include <iostream>
#include "../libmodio/modio.h"
int main()
{
  modio io("192.168.1.2");
  io.WriteAnalog(3, 10);
  std::cout << io.ReadAnalog(3) << std::endl;
  std::cout << io.ReadRegister(3) << std::endl;
  Sleep(1);
  io.WriteRegister(3, 3200);
  Sleep(1);
  std::cout << io.ReadAnalog(3) << std::endl;
  std::cout << io.ReadRegister(3) << std::endl;
  return 0;
}
