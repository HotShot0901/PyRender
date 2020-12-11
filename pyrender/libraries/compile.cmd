@echo off

echo Compiling...

g++ -c -fPIC "source\arrayHelper.cpp" -o "bin-int\arrayhelper.o"
g++ -shared -Wl,-soname,"bin\arrayHelper.dll" -o "bin\arrayHelper.dll" "bin-int\arrayhelper.o"

echo Done

Pause
CLS
