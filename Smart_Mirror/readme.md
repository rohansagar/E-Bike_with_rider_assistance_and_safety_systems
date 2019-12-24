# Smart Mirror Module:

The instructions to setup the smart mirror module on a Raspberry Pi 3 Model B+:
Setup raspbian OS on an SD card. Then follow the instructions in access_point.md to setup the pi as an access point.

After the access point is succesfully setup, download the camera_stream.py to any location on the file system.
Then setup the script to run on startup by adding it to .bashrc.
```
echo 'path/to/script/camera_stream.py' >> ~/.bashrc
```
The script captures the video from the camera using the picamera pythin module and streams it to the webpage that 
is hosted on the network created by the pi.
The script captures an M-JPEG stream using the video mode of the camera. This stream is sent to the webpage that is hosted on the network created by the pi. The stream has a resolution of 640X360 and has a framerate of 40 fps (the low resolution allows for minimal latency). The script uses python’s ‘pi camera’ module to capture the video.
