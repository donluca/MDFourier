/* 
 * MDFourier
 * A Fourier Transform analysis tool to compare different 
 * Sega Genesis/Mega Drive audio hardware revisions, and
 * other hardware in the future
 *
 * Copyright (C)2019 Artemio Urbina
 *
 * This file is part of the 240p Test Suite
 *
 * You can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA	02111-1307	USA
 *
 * Requires the FFTW library: 
 *	  http://www.fftw.org/
 * 
 */

#ifndef MDFOURIER_WINDOWS_H
#define MDFOURIER_WINDOWS_H

#include "mdfourier.h"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

double *hannWindow(long int n);
double *flattopWindow(long int n);
double *tukeyWindow(long int n);
double *hammingWindow(long int n);

int initWindows(windowManager *wm, int SamplesPerSec, char winType, parameters *config);
double *getWindowByLength(windowManager *wm, long int frames, double framerate);
double *CreateWindow(windowManager *wm, long int frames, double framerate);
void freeWindows(windowManager *windows);
double CompensateValueForWindow(double value, char winType);
double CalculateCorrectionFactor(windowManager *wm, long int frames);

#endif