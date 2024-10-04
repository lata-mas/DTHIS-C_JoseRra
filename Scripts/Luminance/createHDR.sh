#!/bin/bash

DATE=$(date +"%Y-%m-%d_%H%M")

libcamera-still --nopreview -o 1.jpg --raw -t 500ms --shutter 100us --gain 1 --awb sunlight
libcamera-still --nopreview -o 2.jpg --raw -t 500ms --shutter 500us --gain 1 --awb sunlight
libcamera-still --nopreview -o 3.jpg --raw -t 500ms --shutter 1000us --gain 1 --awb sunlight
libcamera-still --nopreview -o 4.jpg --raw -t 500ms --shutter 5000us --gain 1 --awb sunlight
libcamera-still --nopreview -o 5.jpg --raw -t 500ms --shutter 10000us --gain 1 --awb sunlight
libcamera-still --nopreview -o 6.jpg --raw -t 500ms --shutter 50000us --gain 1 --awb sunlight
libcamera-still --nopreview -o 7.jpg --raw -t 500ms --shutter 100000us --gain 1 --awb sunlight
libcamera-still --nopreview -o 8.jpg --raw -t 500ms --shutter 500000us --gain 1 --awb sunlight
libcamera-still --nopreview -o 9.jpg --raw -t 500ms --shutter 1000000us --gain 1 --awb sunlight
libcamera-still --nopreview -o 10.jpg --raw -t 500ms --shutter 2000000us --gain 1 --awb sunlight

python3 PyDNG/examples/utility.py 1.jpg
python3 PyDNG/examples/utility.py 2.jpg
python3 PyDNG/examples/utility.py 3.jpg
python3 PyDNG/examples/utility.py 4.jpg
python3 PyDNG/examples/utility.py 5.jpg
python3 PyDNG/examples/utility.py 6.jpg
python3 PyDNG/examples/utility.py 7.jpg
python3 PyDNG/examples/utility.py 8.jpg
python3 PyDNG/examples/utility.py 9.jpg
python3 PyDNG/examples/utility.py 10.jpg

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

mv image_final.hdr HDR_images/$DATE.hdr

rclone copy --update --verbose --transfers 5 --checkers 2 --contimeout 60s --timeout 300s --retries 3 --low-level-retries 5 --stats 1s "/home/pi/Desktop/Picture_Apolo_1/HDR_images" "HDR: drive"
