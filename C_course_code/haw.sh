#! /bin/bash


if [ "$1" == "test" ] 
then

    cmake . -B debug_build -DDebug=$3 -Df=$2
    cd debug_build
    make
    ./C_course

elif [ "$1" == "build" ] 
then

    zip -r "$2.zip" TestModule "$2.c"
else
    echo "  haw test <文件名> <测试开关 on|off>"
    echo "  haw build <文件名无需后缀>"
fi