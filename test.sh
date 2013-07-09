#!/usr/bin/env bash
# test sh script

cd bin
pwd
echo 'RENDERING TEST FILE'
time lua ritest_co.lua | rndr -p
