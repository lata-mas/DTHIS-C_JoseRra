export PATH="/home/dthisc/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

#!/bin/bash

DATE=$(date +"%Y-%m-%d_%H%M")
IMG_DIR="/home/dthisc/dthis-c/illuminance/images"
HDR_IMG="/home/dthisc/dthis-c/illuminance/hdr_images"
SET_DIR="/home/dthisc/dthis-c/illuminance/set_images"
MAPS_DIR="/home/dthisc/dthis-c/illuminance/maps"
OUTPUT_DIR="/home/dthisc/dthis-c/illuminance"

# Loop through shutter speeds and capture images
SHUTTERS=(100 500 1000 5000 10000 50000 100000 500000 1000000 2000000)

for i in "${!SHUTTERS[@]}"; do
  rpicam-still --raw -n --gain 1 -t 500 --shutter "${SHUTTERS[$i]}" \
    -o "$IMG_DIR/$(printf "%02d" $((i+1))).jpg"
done

# Generate HDR from raw images
raw2hdr -a -e -g -f -h -w \
  -o "$HDR_IMG/image_$DATE.hdr" "$IMG_DIR"/*dng

# Info about HDR
getinfo "$HDR_IMG/image_$DATE.hdr"

# Nullify exposure 
ra_xyze -r -o "$HDR_IMG/image_$DATE.hdr" > "$SET_DIR/image_nullEV_$DATE.hdr"

# Resize 
pfilt -1 -x 1000 -y 1000 "$SET_DIR/image_nullEV_$DATE.hdr" \
  > "$SET_DIR/image_resize_$DATE.hdr"

# Photometric adjustment 
pcomb -s 1.8 "$SET_DIR/image_resize_$DATE.hdr" \
  > "$SET_DIR/image_photometric_$DATE.hdr"

# Change view angle for fisheye 
getinfo -a "VIEW= -vta -vv 160 -vh 160" \
  < "$SET_DIR/image_photometric_$DATE.hdr" \
  > "$IMG_DIR/image_final_$DATE.hdr"

# Print illuminance and save to text
echo "Total illuminance is: "
evalglare -V "$IMG_DIR/image_final_$DATE.hdr"
evalglare -V "$IMG_DIR/image_final_$DATE.hdr" > "$OUTPUT_DIR/illuminance.txt"

mv "$IMG_DIR/image_final_$DATE.hdr" "$HDR_IMG/image_final_$DATE.hdr"

# Crop to radius 444.44 
pcomb \
  -e 'Cx:xmax/2;Cy:ymax/2;R:444.44;sq(x):x*x' \
  -e 'inC=sq(R)-sq(x-Cx)-sq(y-Cy)' \
  -e 'ro=if(inC,ri(1),0);go=if(inC,gi(1),0);bo=if(inC,bi(1),0)' \
  "$HDR_IMG/image_final_$DATE.hdr" \
  > "$HDR_IMG/image_crop_$DATE.hdr"

# Make the luminance map with falsecolor
falsecolor -s 5000 -d 1 \
  -i "$HDR_IMG/image_crop_$DATE.hdr" --log 3 \
  > "$MAPS_DIR/$DATE.hdr"