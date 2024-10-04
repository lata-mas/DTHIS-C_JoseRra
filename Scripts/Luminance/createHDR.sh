#!/bin/bash

DATE=$(date +"%Y-%m-%d_%H%M")  

libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 100 -o ~/Radiance/Images 1.jpg
libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 500 -o ~/Radiance/Images 2.jpg
libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 1000 -o ~/Radiance/Images 3.jpg
libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 5000 -o ~/Radiance/Images 4.jpg
libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 10000 -o ~/Radiance/Images 5.jpg
libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 50000 -o ~/Radiance/Images 6.jpg
libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 100000 -o ~/Radiance/Images 7.jpg
libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 500000 -o ~/Radiance/Images 8.jpg
libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 1000000 -o ~/Radiance/Images 9.jpg
libcamera-still -n -r --gain 1 --awb daylight -t 500 --shutter 2000000 -o ~/Radiance/Images 10.jpg

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
