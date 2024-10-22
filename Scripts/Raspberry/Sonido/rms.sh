#!/bin/bash

media="/home/hdeza/Sonido/rms.txt"

/usr/bin/sox /home/hdeza/Sonido/audio.wav -n stat 2>&1 | /usr/bin/grep "RMS     amplitude:" | /usr/bin/awk '{print $3}' > $media
