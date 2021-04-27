#ifndef CALENDARDATE_H_
#define CALENDARDATE_H_

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

namespace Time
{

class CalendarDate
{
public:
    CalendarDate();
    CalendarDate(double jd);
	CalendarDate(const char *date);
    CalendarDate(int y, int mo, int d, int h, int mi, float sec);
    ~CalendarDate();

    void normalize();
	double julian_day();
	void set_from_julian_day(double jd);
	void set_from_iso_string(const char *date);
	void set_from_isot_string(const char *date);

	string string_iso();
	string string_isot();

    int year, month, day, hour, minute;
    double second;
};

} // namespace Time

#endif /* CALENDARDATE_H_ */
