#!/usr/bin/env bash

readonly HERE=$(dirname "$0")

mkdir "${HERE}/usr"
cp -r /usr/include "${HERE}/usr/include"
