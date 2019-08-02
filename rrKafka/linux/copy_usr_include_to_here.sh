#!/usr/bin/env bash

readonly SCRIPT_DIR=$(dirname "$0")

mkdir "$SCRIPT_DIR"/usr
cp -r /usr/include "$SCRIPT_DIR"/usr/include
