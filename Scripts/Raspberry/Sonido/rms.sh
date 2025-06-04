#!/bin/bash

AUDIO="/home/dthisc/dthis-c/sound/audio.wav"
MEDIA="/home/dthisc/dthis-c/sound/rms.txt"

/usr/bin/sox "$AUDIO" -n stat 2>&1 \
  | awk '/RMS.*amplitude/ {print $3}' \
  > "$MEDIA"
