@echo off

echo Compiling...

echo Making Object files...
g++ -c -fPIC "source\2d_drawCalls.cpp" -O2 -o "bin-int\2d_drawCalls.o"
g++ -c -fPIC "source\3d_drawCalls.cpp" -O2 -o "bin-int\3d_drawCalls.o"

echo Making dll's...
g++ -shared -Wl,-soname,"bin\2d_drawCalls.dll" -O2 -o "bin\2d_drawCalls.dll" "bin-int\2d_drawCalls.o"
g++ -shared -Wl,-soname,"bin\3d_drawCalls.dll" -O2 -o "bin\3d_drawCalls.dll" "bin-int\3d_drawCalls.o"

echo Copying...
copy "bin\2d_drawCalls.dll"
copy "bin\3d_drawCalls.dll"

echo Done

Pause
