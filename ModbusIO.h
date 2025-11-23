/*! @file ModbusIO.h
 * @author Sascha Heimfarth
 * @brief Dient dazu der modbus Bibliothek einen Objektorientierten Wrapper mit Error handling zu geben.
 */

#ifndef ModbusIO_h
#define ModbusIO_h

#include <iostream>
#include <stdexcept>
#include <errno.h>
#include <vector>

#include "ModbusIOException.h"

#include "../libmodbus/modbus.h"

namespace Modbus
{

    /**
    * Diese Klasse dient dazu ein einfachen und Objektartigen Zugriff auf die
    * Modbus Hardware zugewährleisten zzgl. Fehler behandlung.
    */
    class IO
    {
    private:
        /// @brief Konsante der Maximalen Spannung zur Berechnung der Register für die Analog Funktionen
        const float MAX_VOLTAGE = 10;
        /// @brief ModbusTCP connection pointer
        modbus_t *ctx;
    public:

        /*! @brief ReadBits (Coils)
        * Mit dieser Funktion können einzelne Bytes (Coils) gelesen werden
        * (adresse+512 um Ausgangsbits zurück zu lesen)
        * @param adress    Start-Adresse des zu lesenden Coils
        * @param dest       Ziel der zu lesenden Bools
        * @param count     Anzahl der Bits
        */
        void readBits(int address, uint8_t* dest, int count);

        /*! @brief writeBit (single bit)
        * Mit dieser Funktion kann man ein einzelens Bit schreiben
        * @param address   Adresse des Bit
        * @param count     Wert des Bit als bool
        *
        */
        void writeBit(int address, const bool &value);

        /*! @brief writeBits (Coils)
        * Mit dieser Funktion können einzelne Bytes (Coils) geschrieben werden
        * @param adress    Start-Adresse der zu schreibenden Coils
        * @param src       Quelle der zu schreibenden Bools
        * @param count     Anzahl der Bits
        */
        void writeBits(int address, bool* src, int count);

        /*! @brief readRegisters
        * Mit dieser Funktion können ganze Register gelesen werden
        * (adresse+512 um Ausgangsregister zurück zu lesen)
        * @param adress    Start-Adresse der zu lesenden Register
        * @param dest      Ziel der zu lesenden Register
        * @param count     Anzahl der Register
        */
        void readRegisters(int address, uint16_t *dest, int count);

        /*! @brief writeRegister (Singelregister)
        * Mit dieser Funktion kann ein Register geschrieben werden
        * @param adress    Adresse des zu beschreibenden Register
        * @param value     Zuschreibender Wert
        */
        void writeRegister(int address, const uint16_t &value);

        /*! @brief writeRegisters (Multiregister)
        * Mit dieser Funktion können ganze Register geschrieben werden
        * @param adress    Start-Adresse der zu beschreibenden Register
        * @param src       Quelle der Register die geschrieben werden sollen
        * @param count     Anzahl der Register
        */
        void writeRegisters(int address, uint16_t *src, int count);

        /*! @brief readAnalog (Spannungen)
        * abstrahierte Version von writeRegister um direkt Spannungen in die Register
        * zuschreiben (mit Convertierung) [Spannungsbereich: -10 --> 0 --> +10V]
        * @param adress    Start-Adresse der zu beschreibenden Register
        * @param dest      Ziel der Spannungswert-Register die gelesen werden sollen
        * @param count     Anzahl der Spannungswert-Register
        *
        */
        void readAnalog(int address, float *dest, int count);

        /*! @brief writeAnalog (Spannungen)
        * abstrahierte Version von readRegister um direkt Spannungen aus denn Registern
        * zulesen (mit Convertierung) [Spannungsbereich: 0 --> 10V]
        * @param adress    Start-Adresse der zu beschreibenden Register
        * @param src       Quelle der Spannungswert-Register die geschrieben werden sollen
        * @param count     Anzahl der Spannungswert-Register
        *
        */
        void writeAnalog(int address, float *src, int count);
        /*! @brief writeAnalog (Komfort überlagerung der normalen writeAnalog-Funktion)
        * Hat die selbe Funktion wie die bool writeAnalog(int address, float *src, int count) Funktion,
        * nimmt nur einen einzelen Wert statt eines Arrays. (Komfort-Funktion)
        * @param address   Adresse des Analogausgang
        * @param value     Wert für denn Analogausgang
        */
        void writeAnalog(int address, float value);

        /*! @brief IO Konstruktor
        * Dient zur Erstellung des IO Objektes
        * @param ip Char-Array mit der IP-Adresse des Clients
        * @param port Port der Hardware des Clients
        */
        IO(const char* ip, int port);
        /*! @brief IO Dekonstruktor
        * Schließt die Verbindung zum Client
        */
        ~IO();
    };
}
#endif
