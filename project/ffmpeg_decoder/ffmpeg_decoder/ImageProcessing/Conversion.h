#pragma once
//-----include header files, �ޤJ���Y��-----
#include <stdio.h>														//	include "stdio.h" header file, �ޤJ���Y��stdio.h
#include "DIPDefine\\DIPDefine.h"

//-----funtion declaration, �Ƶ{���ŧi��-----
unsigned char Clip(int clr);
RGBQUAD ConvertYCrCbToRGB(
	int y,
	int cr,
	int cb
);
