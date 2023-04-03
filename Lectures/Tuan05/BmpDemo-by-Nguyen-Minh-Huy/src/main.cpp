// Bitmap Demo 
// Copyright (c) 2015, Nguyen Minh Huy, nmhuy@fit.hcmus.edu.vn
//
// This software is provided 'as-is', without any implied warranty.
// The authors will not be held liable for any damages arising from
// the use of this software.
//
// Permission is granted to anyone to use, alter, and redistribute
// this software freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
// 2. This notice may not be removed or altered from any source distribution.
//
// ****************************************************************
// This file contains entry point and demonstration of Bitmap Demo.
// ****************************************************************

#include "bmp.h"
#include "BmpDraw.h"

#define BMP_SOURCE		"lena.bmp"

void changeBmp(Bmp &bmp) {
	for (int i = 0; i < bmp.dib.imageHeight; ++i)
		for (int j = 0; j < bmp.dib.imageWidth; ++j) {
			Color *c = &bmp.pixelArray.pixels[i][j];
			Color *d = &bmp.pixelArray.pixels[i][j];

			c->red = d->red; 
			c->green = d->green;
			c->blue = d->blue;
		}
}

int main() {
	Bmp bmpSource;

	readBmpFile(BMP_SOURCE, bmpSource);
	printHeader(bmpSource);
	printDib(bmpSource);

	getchar();

	changeBmp(bmpSource);
	//drawBmpByPixels(bmpSource);
  drawBmpByLib(bmpSource);
	
  getchar();

  Bmp bmpDest;
  copyBmp(bmpSource, 200, 100, 300, 300, bmpDest);
  //drawBmpByPixels(bmpDest);
  drawBmpByLib(bmpDest);
  releasePixelArray(bmpDest);

	releasePixelArray(bmpSource);
}
