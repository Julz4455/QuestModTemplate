#!/bin/bash

./build.sh

cp ./libs/arm64-v8a/lib#{id}.so ./lib#{id}.so
cp ./libs/arm64-v8a/libbeatsaber-hook_1_0_12.so ./libbeatsaber-hook_1_0_12.so

zip "#{id}_v0.1.0.zip" "./lib#{id}.so" "./libbeatsaber-hook_1_0_12.so" "./bmbfmod.json"

rm -rf ./lib#{id}.so ./libbeatsaber-hook_1_0_12.so
