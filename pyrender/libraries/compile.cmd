@echo off

echo Compiling...

g++ -c -fPIC "source\arrayHelper.cpp" -O2 -o "bin-int\arrayhelper.o"
g++ -shared -Wl,-soname,"bin\arrayHelper.dll" -O2 -o "bin\arrayHelper.dll" "bin-int\arrayhelper.o"

echo Done

Pause
CLS
