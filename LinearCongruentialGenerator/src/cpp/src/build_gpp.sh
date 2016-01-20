#!/bin/bash
#
# GTEST_ROOT and compiler versions to be set accordingly
export CC=gcc-5
export CXX=g++-5
export GTEST_ROOT=~/work/gtest
export BINDIR=../bin
if [ ! -d $BINDIR ]; then
  mkdir $BINDIR
fi
cmake -H. -B$BINDIR
pushd $BINDIR
make
./lcgdemo
./lcgtest
./boostlcgtest
popd

