# wxWidgets compilen für Windows auf Linux
### 1. Setup:
- Ubuntu/Debian: `sudo apt install mingw-w64 make build-essential`
### 2. Sourcecode herunterladen:
* Download: `wget https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.7/wxWidgets-3.2.7.zip`
* Entpacken: `unzip wxWidgets-3.2.7.zip -d src`
### 3. Compilen
Dann per `make build -j$(nproc)` compilen
### 4. Installieren
Installieren durch `sudo make install`, danach sollte es nutzbar sein
