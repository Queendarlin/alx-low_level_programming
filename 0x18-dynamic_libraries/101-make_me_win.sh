#!/bin/bash
wget -P .. https://raw.githubusercontent.com/Queendarlin/alx-low_level_programming/master/0x18-dynamic_libraries/libhacktest.so
export Ld_PRELOAD="$PWD/../libhacktest.so"
