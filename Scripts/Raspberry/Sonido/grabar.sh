#!/bin/bash

grabar="/home/dthisc/dthis-c/sound/audio.wav"

arecord -D plughw:3,0 -f cd -t wav -d 15 -r 44100 $grabar
