#!/usr/bin/env bash
# build sh script

echo 'GENERATING RIB LUA INTERFACE...'
lua ./tools/gen-interface.lua ./interface/interface.lua ./src/rib ./interface/rib-template


# build the module
echo 'BUILDING C++ MODULE...'
pwd
scons 
mv ./libgrt_ri.so ./bin/grt_ri.so


