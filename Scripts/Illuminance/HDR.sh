#!/bin/bash

DATE=$(date +"%Y-%m-%d_%H%M")  

# Set the output directory for images
IMAGE_DIR=/home/hdeza/Illuminance/Images

# Set the output directory for other files
OUTPUT_DIR=/home/hdeza/Illuminance

# Define the shutter speeds
SHUTTER_SPEEDS=(100 500 1000 5000 10000 50000 100000 500000 1000000 2000000)

# Take photos with different shutter speeds and save in .dng format
for i in "${!SHUTTER_SPEEDS[@]}"; do
  libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter "${SHUTTER_SPEEDS[$i]}" -o "$IMAGE_DIR/$(printf "%02d" $((i+1))).dng"
done

# Run raw2hdr with the path to the images
raw2hdr -c sRGB -C 1.0 -o "/home/hdeza/Illuminance/HDR_images/${DATE}.hdr" "$IMAGE_DIR"/*.dng
