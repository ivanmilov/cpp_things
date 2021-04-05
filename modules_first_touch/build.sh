rm foo.o foo.pcm a.out

export GCC_PRECOMPILE_PREFIX_HEADER=NO

echo prebuild module
clang++ --std=c++2a -fmodules --precompile foo.cppm

echo "----------------------------------------------------------------"
echo "make .o"
clang++ --std=c++2a -fmodules -c foo.pcm
echo "----------------------------------------------------------------"
echo "compile"
clang++ --std=c++2a -fmodules -fprebuilt-module-path=. -fbuiltin-module-map  foo.o main.cpp
echo "----------------------------------------------------------------"
