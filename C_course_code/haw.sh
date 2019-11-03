#! /bin/bash


cmake . -B debug_build -DDebug=$2 -Df=$1
cd debug_build
make
./C_course