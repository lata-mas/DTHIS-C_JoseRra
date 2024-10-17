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
