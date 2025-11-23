/*! @file modio.h
 * @author Sascha Heimfarth
 * @brief Stellt das modio Objekt bereit, mit dem über eine ähnliche API wie bei der BTDTIO Bibiliothek mit der Hardware interagiert werden kann.
 */

#ifndef modio_h
#define modio_h

#include <iostream>

#include "ModbusIO.h"

/*! @brief Diese Klasse ist eine moderne reimplementierung der alten API
* Im Fehler fall werden Exception geworfen, siehe hierzu "ModbusIOException.h"
*/

class modio
{
  private:
    Modbus::IO io;
  public:
    /*! @brief GetBitStatus (ähnlich ehm. GitInPort)
    * Gibt denn aktuellen Status eines Ausgangsbits zurück
    * @param address
    */
    bool GetBitStatus(int address);
    /*! @brief Gibt denn aktuellen wert des Bit an der Adresse zurück
    * @param bit
    */
    bool GetBit(int address);

    /*! @brief Setzt ein Bit an Adresse (=1)
    * @param bit
    */
    void SetBit(int address);

    /*! @brief Setzt ein Bit an Adresse zurück (=0)
    * @param address
    */
    void DelBit(int address);

    /*! @brief Hiermit lässt sich ein register vollständig auslesen
    * @param address
    */
    uint16_t ReadRegister(int address);

    /*! @brief WriteRegister (ähnlich ehm. ReadDABoard12)
    * Schreibt ein ganzes Register in denn Speicher
    * @param address
    * @param value Wert der geschrieben werden soll
    */
    void WriteRegister(int address, uint16_t value);

    /*! @brief ReadAnalog (ähnlich ehm. WriteDABoard12)
    * hiermit lassen sich direkt Spannungswerte von denn Eingängen lesen
    * @param address
    * @return Spannung (-10.0 V bis +10.0 V)
    */
    float ReadAnalog(int address);

    /*! @brief hiermit lassen sich direkt Spannungswerte an denn Ausgang schreiben
    * @param address
    * @param value Spannungswert (-10.0 V bis +10.0 V)
    */
    void WriteAnalog(int address, float value);


    /*! @brief Konstruktor
    * @param ip IP-Adresse des Wago Gate
    * @param port Port der vom Wago Gate benutzt wird
    */
    modio(const char* ip, int port): io(ip, port)
    {};
    /*! @brief Konstruktor
    * Überladung des normalen Konstruktor mit vorgegebenen standard Modbus port
    * @param ip IP-Adresse des Wago Gate
    */
    modio(const char* ip): io(ip, 502)
    {}
};

#endif
