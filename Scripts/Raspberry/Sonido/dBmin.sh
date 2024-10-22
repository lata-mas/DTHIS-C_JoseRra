#!/bin/bash

minimo="/home/hdeza/Sonido/dBmin.txt"

/usr/bin/sox /home/hdeza/Sonido/audio.wav -n stat 2>&1 | /usr/bin/grep "Minimum amplitude:" | /usr/bin/awk '{print $3}' > $minimo
