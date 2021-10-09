#!/bin/sh

make program
echo "33 11">>answer.txt
./program > output.txt
diff answer.txt output.txt>>result.txt
make clean

