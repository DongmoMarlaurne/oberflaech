/*! @file ModbusIOException.h
 * @author Sascha Heimfarth
 * @brief Dient dazu die möglichen Exceptions für die Modbus::IO Klasse bereitzustellen.
 */

#ifndef ModbusIOException_H
#define ModbusIOException_H

#include "../libconfig/Log.h"

namespace Modbus
{
    enum Exception
    {
        MissingLibraryError,
        ConnectError,
        WriteError,
        ReadError
    };
}

/*! @brief MODBUS_ERROR
* Ein Macro um im Log denn Typ des geworfenen Fehlers anzugegeben
* @param target Log Objekt
* @param e Die geworfene Exception
* @param arg Nachricht die in denn Log soll
*/
#define MODBUS_ERROR(target, e, arg): switch(e){\
  case Modbus::MissingLibraryError:\
  {\
    LOG(target, "MissingLibraryError: " + arg);\
    break;\
  }\
  case Modbus::ConnectError:\
  {\
    LOG(target, "ConnectError: " + arg);\
    break;\
  }\
  case Modbus::WriteError:\
  {\
    LOG(target, "WriteError: " + arg);\
    break;\
  }\
  case Modbus::ReadError:\
  {\
    LOG(target, "ReadError: " + arg);\
    break;\
  }\
  default:\
  {\
    LOG(target, "UndefinedError: " + arg);\
    break;\
  }\
}
#endif
