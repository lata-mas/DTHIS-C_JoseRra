#!/bin/bash

DATE=$(date +"%Y-%m-%d_%H%M")
IMG_DIR="/home/hdeza/Illuminance/images"
HDR_IMG="/home/hdeza/Illuminance/HDR_images"
MAPS_DIR="/home/hdeza/Illuminance/maps"
OUTPUT_DIR="/home/hdeza/Illuminance"

# Loop through shutter speeds and capture images
SHUTTERS=(1000 2000 4000 8000 16000 32000 64000 128000 256000 512000)

for i in "${!SHUTTERS[@]}"; do
  rpicam-still --raw -n --gain 1 -t 500 --shutter "${SHUTTERS[$i]}" -o "$IMG_DIR/$(printf "%02d" $((i+1))).jpg"
done

# Run raw2hdr with the path to the images and save as image.hdr
raw2hdr -a -e -g -f -h -w -o "$HDR_IMG/image.hdr" "$IMG_DIR"/*dng

# Get info about the final HDR
getinfo "$HDR_IMG/image.hdr"

# Nullify exposure value and save in OUTPUT_DIR
ra_xyze -r -o "$HDR_IMG/image.hdr" > "$OUTPUT_DIR/image_nullEV.hdr"

# Resize image and save in OUTPUT_DIR
pfilt -1 -x 1000 -y 1000 "$OUTPUT_DIR/image_nullEV.hdr" > "$OUTPUT_DIR/image_resize.hdr"

# Make photometric adjustment and save in OUTPUT_DIR
pcomb -s 1.8 "$OUTPUT_DIR/image_resize.hdr" > "$OUTPUT_DIR/image_photometric.hdr"

# Change view angle for fisheye and save the final image in IMG_DIR
getinfo -a "VIEW= -vta -vv 121 -vh 121" < "$OUTPUT_DIR/image_photometric.hdr" > "$IMG_DIR/image_final.hdr"

# Print illuminance value and save result in OUTPUT_DIR
echo "Total illuminance is: "
evalglare -V "$IMG_DIR/image_final.hdr"
evalglare -V "$IMG_DIR/image_final.hdr" > "$OUTPUT_DIR/illuminance.txt"

# Move final HDR image to HDR_images with the current date
mv "$IMG_DIR/image_final.hdr" "$HDR_IMG/$DATE.hdr"

# Make the luminance map
falsecolor -i "$HDR_IMG/$DATE.hdr" > "$MAPS_DIR/${DATE}_map.hdr"
