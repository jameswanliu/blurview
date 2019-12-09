//
// Created by kevin on 2019/12/7.
//

#ifndef BLURVIEW_BLUR_H
#define BLURVIEW_BLUR_H

#define ABS(a) ((a)<0?(-a):(a))
#define MAX(a, b) ((a>b)?(a):(b))
#define MIN(a, b) ((a<b)?(a):(b))

#include <malloc.h>
int *blur_ARGB_8888(int *, int, int, int);

short *blur_ARGB_565(short *, int, int, int);

#endif //BLURVIEW_BLUR_H
