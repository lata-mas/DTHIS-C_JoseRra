#!/bin/bash

# Take photos with different shutter speeds and save in .jpg format
rpicam-still --raw -n --gain 1 -t 500 --shutter 1000 -o /home/hdeza/Illuminance/images/01.jpg
rpicam-still --raw -n --gain 1 -t 500 --shutter 2000 -o /home/hdeza/Illuminance/images/02.jpg
rpicam-still --raw -n --gain 1 -t 500 --shutter 4000 -o /home/hdeza/Illuminance/images/03.jpg
rpicam-still --raw -n --gain 1 -t 500 --shutter 8000 -o /home/hdeza/Illuminance/images/04.jpg
rpicam-still --raw -n --gain 1 -t 500 --shutter 16000 -o /home/hdeza/Illuminance/images/05.jpg
rpicam-still --raw -n --gain 1 -t 500 --shutter 32000 -o /home/hdeza/Illuminance/images/06.jpg
rpicam-still --raw -n --gain 1 -t 500 --shutter 64000 -o /home/hdeza/Illuminance/images/08.jpg
rpicam-still --raw -n --gain 1 -t 500 --shutter 128000 -o /home/hdeza/Illuminance/images/09.jpg
rpicam-still --raw -n --gain 1 -t 500 --shutter 256000 -o /home/hdeza/Illuminance/images/10.jpg

# Run raw2hdr with the path to the images
raw2hdr -a -e -g -f -h -w -o "/home/hdeza/Illuminance/HDR_images/image.hdr" /home/hdeza/Illuminance/images/*dng



#!/bin/bash

# Define variables for paths, shutter speeds, and date
IMG_DIR="/home/hdeza/Illuminance/images"
DATE=$(date +"%Y-%m-%d_%H%M")
HDR_IMG="/home/hdeza/Illuminance/HDR_images/$DATE.hdr" # Removed "image" from filename
SHUTTERS=(1000 2000 4000 8000 16000 32000 64000 128000 256000)

# Loop through shutter speeds and capture images
for i in "${!SHUTTERS[@]}"; do
  rpicam-still --raw -n --gain 1 -t 500 --shutter "${SHUTTERS[$i]}" -o "$IMG_DIR/$(printf "%02d" $((i+1))).jpg"
done

# Run raw2hdr with the path to the images and save with date in filename
raw2hdr -a -e -g -f -h -w -o "$HDR_IMG" "$IMG_DIR"/*dng
