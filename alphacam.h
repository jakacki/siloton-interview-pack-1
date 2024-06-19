#ifndef __ALPHACAM_H__
#define __ALPHACAM_H__

#include <inttypes.h>

int alphaCamInitCamera(int cameraIndex, int framesPerSecond); 
    // returns a non-negative camera handle of one of connected cameras (selected by cameraIndex); 
    // returns negative value on error
    // the first camera on the system has cameraIndex == 0

int alphaCamBytesFromSensorNonBlocking(int cameraHandle, int* buffer, int bufsize); 
    // reads up to bufsize pixels from camera's circular buffer (FIFO), pixels not read in time are overwritten
    // returns the number of pixels read (always no more than bufsize, but can be less)
    
int alphaCamcloseCamera(int cameraHandle);
    // releases resources associated with cameraHandle

const char* alphaCamGetErrorDescription(int error);

#endif
