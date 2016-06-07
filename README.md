ofxDrawCamera
=====================================


This addon draws a camera fustrum. It is the only thing it does.

It is usefull for debuging 3d scenes with more than a single camera.

It is based on some code by @elliotwoods

##Usage

Add this addon to your project using openFrameworks's project generator or the OF Plugin for your IDE of choice.

At the top of your .cpp or .h file add

``` #include "ofxDrawCamera.h"```


then in the draw just call

``` ofxDrawCamera::draw(anOfCameraInstance); ```
