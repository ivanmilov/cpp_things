#!/bin/env bash

CLEAR=0
VERBOSE=""

while getopts "vcd" opt; do
  case "$opt" in
    v)  VERBOSE="-v"
      ;;
    c)  CLEAR=1
      ;;
  esac
done

cd `dirname $0`

declare -r BUILD_DIR="build"

[ "$CLEAR" -eq "1" ] && rm -rf $BUILD_DIR

cmake -B$BUILD_DIR -DCMAKE_BUILD_TYPE=Debug
cmake --build $BUILD_DIR/ -j8 $VERBOSE
