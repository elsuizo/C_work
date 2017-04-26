/* -------------------------------------------------------------------------
@file main.c

@date 04/06/17 17:35:55
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

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
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv/cv.h"
/* #include<opencv/cvaux.h> */
/* #include<opencv/highgui.h> */
/* #include<opencv/cxcore.h> */
/* #include<opencv/cv.h> */


#include<stdio.h>
#include<stdlib.h>


int main()
{
  IplImage* img = cvLoadImage("/home/elsuizo/Dropbox/Freelance/Imges_merge/back.png");

  if (!img)
  {
    printf("Image can NOT Load!!!\n");
    return 1;
  }

  cvNamedWindow("myfirstwindow", CV_WINDOW_AUTOSIZE);
  cvShowImage("myfirstwindow", img);

  cvWaitKey(0);
  cvReleaseImage(&img);

return 0;
}

