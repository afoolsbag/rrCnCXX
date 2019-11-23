#!/usr/bin/env bash

cnt=0
while (( cnt < 66 )); do
        echo $(( ++cnt ))
        sleep 1
done
exit 0
