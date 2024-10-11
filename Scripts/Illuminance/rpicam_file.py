from pidng.core import RPICAM2DNG, DNGTags, Tag
from pidng.camdefs import *
import numpy as np

# load raw image data from file into numpy array. RAW frame from HQ camera. 
img = "/home/hdeza/Illuminance/RAW_images/02.raw"
data = np.fromfile(img, dtype=np.uint8)

# choose a predefined camera model, set the sensor mode and bayer layout. 
# this camera model class sets the appropriate DNG's tags needed based on the camera sensor. ( needed for bit unpacking, color matrices )
camera = RaspberryPiHqCamera(1, CFAPattern.BGGR)

# example of adding custom DNG tags to predefined tags from camera model
camera.tags.set(Tag.ApertureValue, [[4,1]])             # F 4.0
camera.tags.set(Tag.ExposureTime, [[1,100]])             # SHUTTER 1/100
camera.tags.set(Tag.PhotographicSensitivity, [100])     # ISO 100

# example of passing a filter over the rawframe before it is saved. This will simply print the dimensions of the raw image. 
def print_dimensions(rawFrame):
    print(rawFrame.shape)
    return rawFrame

# pass camera reference into the converter.
r = RPICAM2DNG(camera)
r.options(path="", compress=True)
r.filter = print_dimensions
r.convert(data, filename="output")
