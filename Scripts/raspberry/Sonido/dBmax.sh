#!/bin/bash

maximo="/home/hdeza/Sonido/dBmax.txt"

/usr/bin/sox /home/hdeza/Sonido/audio.wav -n stat 2>&1 | /usr/bin/grep "Maximum amplitude:" | /usr/bin/awk '{print $3}'  > $maximo
