/* -------------------------------------------------------------------------
@file frames_from_camera.c

@date 04/12/17 01:04:10
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
test from:
http://stackoverflow.com/questions/11830517/reading-output-of-a-usb-webcam-in-linux
@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 307200

int main(void) {
   FILE* camera;
   FILE* grab;
   camera = fopen("/dev/video0", "rb");
   grab = fopen("grab.png", "wb");
   unsigned char data[SIZE];
   fread(data, sizeof(data[0]), SIZE, camera);
   fwrite(data, sizeof(data[0]), SIZE, grab);
   fclose(camera);
   fclose(grab);
   return 0;
}
