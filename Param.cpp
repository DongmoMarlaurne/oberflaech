/*! @file Param.cpp
 * @author Sascha Heimfarth
 * @brief Bespiel für die Nutzung des Parameter Objekt.
 */

#include <iostream>

#include "../libconfig/Parameter.h"
int main()
{
  Parameter para;
  std::cout << "Store modeXAxis = 25 to config" << std::endl;
  para.modeXAxis = 25;
  para.Store();

  std::cout << "Set modeXAxis = 100" << std::endl;
  para.modeXAxis = 100;
  std::cout << "modeXAxis = " << int(para.modeXAxis) << std::endl;

  std::cout << "Reading from Config..." << std::endl;
  para.Load();
  std::cout << "modeXAxis = " << int(para.modeXAxis) << std::endl;
  return 0;
}
