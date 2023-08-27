#!/bin/bash
wget -P /tmp https://github.com/Gideon5348/alx-low_level_programming/tree/main/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD=/tmp/libgiga.so
