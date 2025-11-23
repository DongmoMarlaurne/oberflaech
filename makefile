objects = ModbusIO.o Convert2K.o modio.o
CXXFLAGS = -Wall -fPIC -shared -L../libs -lmodbus -lconfig
libmodio.so: $(objects)
	@echo "Linking as $@..."
	@$(CXX) $(CXXFLAGS) $? -o $@

libmodio.dll: CXX := x86_64-w64-mingw32-g++
libmodio.dll: $(objects)
	@echo "Linking as $@..."
	@$(CXX) $(CXXFLAGS) -lws2_32 -static-libstdc++ -static-libgcc $? -o $@

%.c:
	touch $@

%.o: %.cpp
	@echo Building $@...
	@$(CXX) $(CXXFLAGS) -c $? -o $@

clear:
	@rm -f *.o
	@rm -f libmodio.dll libmodio.so
	@echo Clean up...
