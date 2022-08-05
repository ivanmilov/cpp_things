#!/bin/bash

CLEAR=0
VERBOSE=""
DIAGRAM=""

while getopts "vc" opt; do
  case "$opt" in
    v)  VERBOSE="-v"
      ;;
    c)  CLEAR=1
      ;;
    d)  DIAGRAM="--graphviz=foo.dot" # https://cmake.org/cmake/help/latest/module/CMakeGraphVizOptions.html
      ;;
  esac
done

cd `dirname $0`

source ~/qnx700/qnxsdp-env.sh

declare -r BUILD_DIR="build_qnx"

TARGET=gcc_ntoaarch64le

if [ -z $QNX_HOST ]
then
	echo "Please source qnx compiler"
	exit
fi

[ "$CLEAR" -eq "1" ] && rm -rf $BUILD_DIR

cmake -B$BUILD_DIR -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=qcc -DCMAKE_CXX_COMPILER=q++ -DCMAKE_C_COMPILER_TARGET=$TARGET -DCMAKE_CXX_COMPILER_TARGET=$TARGET -DCMAKE_SYSTEM_PROCESSOR=aarch64 -DCMAKE_SYSTEM_NAME=QNX $DIAGRAM
cmake --build $BUILD_DIR/ -j8 $VERBOSE
