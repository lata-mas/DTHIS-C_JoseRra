#!/bin/bash

AUDIO="/home/dthisc/dthis-c/sound/audio.wav"
MAXIMO="/home/dthisc/dthis-c/sound/dBmax.txt"

/usr/bin/sox "$AUDIO" -n stat 2>&1 \
  | awk '/Maximum.*amplitude/ {print $3}' \
  > "$MAXIMO"
