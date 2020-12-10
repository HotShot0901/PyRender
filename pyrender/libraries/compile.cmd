@echo off

echo Compiling...

g++ -c -fPIC "source/arrayHelper.cpp" -o "bin-int/arrayhelper.o"
g++ -shared -W "bin-int/arrayhelper.o" -o "bin/arrayHelper.dll"

echo Done

Pause
CLS
