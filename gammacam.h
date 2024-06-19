#ifndef __GAMMACAM_H__
#define __GAMMACAM_H__

#include <inttypes.h>

 /*
  * register callback(bufsize, buffer) which is called each time data from the camera is available
  * bufsize is always > 0 and never exceeds maxbufsize
  * to avoid data loss callback needs to be registered before acquisition begins
  * if callback does not finish before the next chunk of data is available, data may be lost
  * the number of lost pixels will be passed via lostcount on the next callback 
  * the acquisition continues as long as callback() returns 0
  */
void gammacam_register_callback(char* cam_ident, int maxbufsize, int (*callback)(int16_t bufsize, int8_t* buffer, int lostcount));

/*
 * starts acquisiton from the camera identified by cam_ident at the speed given
 * by default the first camera on the system is 'cam0'
 */
void gammacam_acquire(char* cam_ident, int32_t pixels_per_sec);

 /*
  * returns the last error code in the current thread
  */
int gammacam_get_last_error();

 /*
  * writes at most bufsize characters to a pre-allocated buffer
  # @returns number of characters written, including trailing zero
  */
int gammacam_last_error_snprintf(char *buffer, int bufsize);


#endif
