#!/bin/sh

CUR=`pwd`;

for var in "$@"
do
  echo $var
  case $var in
    -cmake)
    cd $CUR/build
    rm -rf CMakeFiles
    rm -f CMakeCache.txt
    cmake $CUR -DCMAKE_BUILD_TYPE=Debug
    ;;
    -xcode)
    cd $CUR/build-xcode
    rm -rf CMakeFiles
    rm -f CMakeCache.txt
    cmake $CUR -G Xcode
    ;;
    -vs)
    cd $CUR/build-vs
    rm -rf CMakeFiles
    rm -f CMakeCache.txt
    cmake $CUR -G "Visual Studio 12 2013 Win64"
    ;;
    -build)
    cd $CUR/build
    make
    ;;
  esac
done
