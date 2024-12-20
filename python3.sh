#!/usr/bin/sh

SRC=./python3
DEST=/usr/local/bin

sudo cp $SRC/* /usr/local/bin
sudo mv $DEST/main.py $DEST/pybadc
