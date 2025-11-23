# libmodio
Dieses Modul kümmert sich um die Ansteuerung der WAGO IOKarte, es benutzt eine klassenbasierte API ähnlich, welche der BTDTIO Bibliothek der alten Hardware nachempfunden ist.

In der Header-Datei modio.h befindet sich das modio Objekt, mit ihm lassen sich die Eingänge lesen und Ausgänge ansteuern. Es ist eine Wrapper-Bibliothek für das Modbus::IO Objekt aus der ModbusIO.h Library. Das modio Objekt besitzt eine ähnliche Aufrufstruktur der damaligen Funktionen der BTDTIO Bibliothek. Mit .GetBit, .SetBit, .DelBit können Bits anhand der Hardware Adressierung manipuliert werden.

Per .ReadRegister bzw. .WriteRegister lassen sich 16 Bitregister lesen und schreiben.

Und mithilfe der .ReadAnalog bzw. WriteAnalog können direkt Spannungswerte ausgegeben oder gelesen werden.

Die ModbusIO.h Bibliothek fungiert hier als objektorientiertes Backend und weiterer Wrapper für das in C geschriebene libmodbus Module.

In ModbusIOException.h befindet sich ein enum mit allen Exceptions, die durch das Modbus::IO Objekt geworfen werden könnten, um sicherzustellen, dass die Hardware nur angesprochen werden kann, sofern alles funktioniert und im Fehlerfall ein richtiges Handeln zu ermöglichen.

## Hängt abvon
- [libmodbus](https://libmodbus.org/) \([Github](https://github.com/stephane/libmodbus)\)

## Building
Es sollte über das Haupt Makefile erzeugt werden, kann aber auch manuell einzeln gebaut werden.
- Linux: `make libmodio.so`
- Windows: `make libmodio.dll`

**Achtung**: das File muss dann manuell in den libs/ Ordner kopiert werden. Außerdem muss zuvor libmodbus und libconfig gebaut worden sein und im libs/ Ordner liegen.

## Aufräumen
Das Haupt Makefile kann hierfür benutzt werden, oder manuell nur für dieses Module: `make clear`
