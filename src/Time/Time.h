#ifndef TIME_H
#define TIME_H
#include <math.h>
#include <time.h>
#include <stdio.h>

#include "CalendarDate.h"

#define DAY_TO_SEC 86400

namespace Time {

double julian_day_now();
double julian_day(int r, int m, int d, double h);
double julian_day(const char *date, const char *format);

}

#endif
