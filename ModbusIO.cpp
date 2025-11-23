/*! @file ModbusIO.cpp
 * @author Sascha Heimfarth
 */

#include "Convert2K.h"
#include "ModbusIO.h"
#include "ModbusIOException.h"

namespace Modbus
{
    void bitView(uint16_t value)
    {
        for (int i=0; i < 16; i++)
        {
            std::cout << "bit " << i << ": " << ((value & 1 << i) >> i) << std::endl;
        }
    }

    IO::IO(const char* ip, int port)
    {
        this->ctx = modbus_new_tcp(ip, port); //erstellt eine neue Modbus TCP instance
        //Prüft ob die Inizialisierung funktioniert hat.
        if (this->ctx == nullptr) {
            std::cerr << "Unable to create the modbus.so context" << std::endl;
            throw Exception::MissingLibraryError;
        }
        //Prüft ob eine Verbindung aufgebaut wurde.
        if (modbus_connect(this->ctx) == -1) {
            std::cerr << "Connection failed: " << modbus_strerror(errno) << std::endl;
            throw Exception::ConnectError;
        }
    }
    IO::~IO()
    {
        //Schließe Verbindung
        modbus_close(ctx);
        //Gebe Resourcen frei
        modbus_free(ctx);
    }

    void IO::readBits(int address, uint8_t* dest, int count)
    {
        int rc = modbus_read_bits(this->ctx, address, count, (uint8_t*) dest);
        //Prüfung ob das lesen erfolgreich war.
        if (rc == -1) {
            std::cerr << "Failed to read bits: " << modbus_strerror(errno) << std::endl;
            throw Exception::ReadError;
        }
    }
    void IO::writeBit(int address, const bool &value)
    {
        int rc = modbus_write_bit(this->ctx, address, value);
        //Prüft ob schreiben erfolgreich war.
        if (rc == -1)
        {
            std::cerr << "Failed to write bit: " << modbus_strerror(errno) << std::endl;
            throw Exception::WriteError;
        }

    }
    void IO::writeBits(int address, bool* src, int count)
    {
        int rc = modbus_write_bits(this->ctx, address, count, (uint8_t*) src);
        //Prüfung ob das schreiben erfolgreich war.
        if (rc == -1) {
            std::cerr << "Failed to write bits: " << modbus_strerror(errno) << std::endl;
            throw Exception::WriteError;
        }
    }

    void IO::writeRegister(int address, const uint16_t &value)
    {
        int rc = modbus_write_register(this->ctx, address, value);
        //Prüfe ob das schreiben erfolgreich war.
        if (rc == -1)
        {
            std::cerr << "Failed to write register: " << modbus_strerror(errno) << std::endl;
            throw Exception::WriteError;
        }
    }

    void IO::readRegisters(int address, uint16_t *dest, int count)
    {
        int rc = modbus_read_registers(this->ctx, address, count, dest);
        //Prüfe ob das lesen erfolgreich war.
        if (rc == -1)
        {
            std::cerr << "Failed to read registers: " << modbus_strerror(errno) << std::endl;
            throw Exception::ReadError;
        }
    }

    void IO::writeAnalog(int address, float *src, int count)
    {
        uint16_t uint16_registers[count];
        //Geht float für float aus der liste durch
        for (int i=0; i < count; i++)
        {
            //Convertiert jeweils einen Float in eine 16 Bit 2K Darstellung
            uint16_registers[i] = ConvertTo2K(src[i], IO::MAX_VOLTAGE);
        }
        //Beschreibt die Register
        this->writeRegisters(address, uint16_registers, count);
    }

    void IO::writeAnalog(int address, float value)
    {
        //Convertiert Vorzeichenhaftes Float zu 16Bit 2K-Wert und schreibt
        //diesen in das Register an dieser Adresse
        this->writeRegister(address, ConvertTo2K(value, IO::MAX_VOLTAGE));
    }

    void IO::readAnalog(int address, float *dest, int count)
    {
        uint16_t uint16_registers[count];
        //Kopiert die Wert der Register in das uint16_t array
        this->readRegisters(address, uint16_registers, count);
        //geht Bit für Bit durch
        for (int i=0; i < count; i++)
        {
            //Convertiert 16Bit 2K Wert zu einem Vorzeichenhaften Float
            dest[i] = ConvertFrom2K(uint16_registers[i], IO::MAX_VOLTAGE);
        }
    }

    void IO::writeRegisters(int address, uint16_t *src, int count)
    {
        int rc = modbus_write_registers(this->ctx, address, count, src);
        //Prüfe ob das schreiben erfolgreich war.
        if (rc == -1) {
            std::cerr << "Failed to write registers: " << modbus_strerror(errno) << std::endl;
            throw Exception::WriteError;
        }
    }
}
