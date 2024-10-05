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
  libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter ${SHUTTER_SPEEDS[$i]} -o "$IMAGE_DIR/$((i+1)).dng"
done

raw2hdr -a -e -g -f -h -w -o im.hdr *.dng

#Get info about the final HDR
getinfo im.hdr

#Nullificate exposure value
ra_xyze -r -o im.hdr > image_nullEV.hdr

#Crop image (not cropping for the fisheye of this raspberry) 
#pcompos -x 2060 -y 2060 image_nullEV.hdr -550 -10 > crop.hdr

#Resize image
pfilt -1 -x 1000 -y 1000 image_nullEV.hdr > image_resize.hdr


#Make photometric adjustment
pcomb -s 1.8 image_resize.hdr > image_photometric.hdr

#Change view angle for fisheye
getinfo -a "VIEW= -vta -vv 121 -vh 121" < image_photometric.hdr > image_final.hdr 

#Print illuminance value
echo "Total illuminance is: "

evalglare -V image_final.hdr

evalglare -V image_final.hdr > illuminance.txt

# Move output files to the directory
mv image_nullEV.hdr $OUTPUT_DIR/
mv image_photometric.hdr $OUTPUT_DIR/
mv image_resize.hdr $OUTPUT_DIR/
mv illuminance.txt $OUTPUT_DIR/

mv image_final.hdr /home/hdeza/Illuminance/HDR_images/$DATE.hdr
