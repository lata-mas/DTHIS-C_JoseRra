#!/bin/bash

DATE=$(date +"%Y-%m-%d_%H%M")  

# Set the output directory for images
IMAGE_DIR=/home/hdeza/Illuminance/images

# Set the output directory for other files
OUTPUT_DIR=/home/hdeza/Illuminance

# Define the shutter speeds
SHUTTER_SPEEDS=(5000 10000 50000 100000)

# Take photos with different shutter speeds and save in .jpg format
for i in "${!SHUTTER_SPEEDS[@]}"; do
  rpicam-still -n --gain 1 -t 500 --shutter "${SHUTTER_SPEEDS[$i]}" -o "$IMAGE_DIR/$(printf "%02d" $((i+1))).jpg"
done

for i in "${!SHUTTER_SPEEDS[@]}"; do
    python3 Illuminance/PyDNG/examples/utility.py "$IMAGE_DIR/$(printf "%02d" $((i+1))).jpg"
done

# Run raw2hdr with the path to the images
# raw2hdr -a -e -g -f -h -w -o "/home/hdeza/Illuminance/HDR_images/${DATE}.hdr" "$IMAGE_DIR"/*.dng
