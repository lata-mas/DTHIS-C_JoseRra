#!/bin/bash

DATE=$(date +"%Y-%m-%d_%H%M")
IMG_DIR="/home/hdeza/Illuminance/images"
HDR_IMG="/home/hdeza/Illuminance/HDR_images/$DATE.hdr"

# Loop through shutter speeds and capture images
SHUTTERS=(1000 2000 4000 8000 16000 32000 64000 128000 256000 512000)

for i in "${!SHUTTERS[@]}"; do
  rpicam-still --raw -n --gain 1 -t 500 --shutter "${SHUTTERS[$i]}" -o "$IMG_DIR/$(printf "%02d" $((i+1))).jpg"
done

# Run raw2hdr with the path to the images and save with date in filename
raw2hdr -a -e -g -f -h -w -o "$HDR_IMG" "$IMG_DIR"/*dng
