#!/bin/bash

AUDIO="/home/dthisc/dthis-c/sound/audio.wav"
MINIMO="/home/dthisc/dthis-c/sound/dBmin.txt"

/usr/bin/sox "$AUDIO" -n stat 2>&1 \
  | awk '/Minimum.*amplitude/ {print $3}' \
  > "$MINIMO"
