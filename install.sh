#!/usr/bin/sh

SRC=./badc
DEST=/usr/local/bin

pybadc $SRC/main.badc -S
sudo mv Temporary $DEST/badc
