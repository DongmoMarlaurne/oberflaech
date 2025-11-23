root_dir = $(shell pwd)
CC=x86_64-w64-mingw32-gcc
CXX=x86_64-w64-mingw32-g++
prepare:
	cd src && mkdir -p work
	cd src/work && ../configure --host=x86_64-w64-mingw32 --enable-unicode --with-msw --disable-shared
build: prepare
	cd src/work && $(MAKE)
install:
	cd src/work && $(MAKE) install
uninstall:
	cd src/work && $(MAKE) uninstall
