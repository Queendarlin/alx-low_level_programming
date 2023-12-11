#!/bin/bash
wget -P .. https://raw.githubusercontent.com/Queendarlin/alx-low_level_programming/master/0x18-dynamic_libraries/libgiga.so

export Ld_PRELOAD="$PWD/../libgiga.so"
