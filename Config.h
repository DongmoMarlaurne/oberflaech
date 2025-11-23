/*! @file Config.h
 * @author Sascha Heimfarth
 * @brief Platform unabhängiger Header für die Konfiguration
 */

#ifndef libConfig_H
#define libConfig_H

  #include "ConfigExceptions.h"

  //prüft ob das Target-System Linux ist und includiert denn Linux header
  #if defined(__linux__)

    #include "ConfigLinux.h"

  //prüft ob das Target-System Windows ist und includiert denn Windows header
  #elif defined (_WIN32)

    #include "ConfigWin.h"

  #endif

#endif
