#include "CalendarDate.h"


namespace Time
{

CalendarDate::CalendarDate()
    : year(2000), month(1), day(1), hour(0), minute(0), second(0)
{
}

CalendarDate::CalendarDate(double jd)
{
	set_from_julian_day(jd);
}

CalendarDate::CalendarDate(const char *date)
{
	/// Sets from ISO format
	set_from_iso_string(date);
}

CalendarDate::CalendarDate(int y, int mo, int d, int h, int mi, float sec)
    : year(y), month(mo), day(d), hour(h), minute(mi), second(sec)
{
    normalize();
}


CalendarDate::~CalendarDate()
{
}

void CalendarDate::normalize()
{
    while (month > 12)
        month -= 12;
    while (month <= 0)
        month += 12;

    while (day > 31)
        day -= 31;
    while (day <= 0)
        day += 31;

    while (hour >= 24)
        hour -= 24;
    while (hour < 0)
        hour += 24;

    while (minute >= 60)
        minute -= 60;
    while (minute < 0)
        minute += 60;

    while (second >= 60)
        second -= 60;
    while (second < 0)
        second += 60;
}


double CalendarDate::julian_day()
{

	double aa, yy, mm;
	aa=floor((14.0 - month)/12.0);
	yy=year + 4800.0 - aa;
	mm=month + 12.0 * aa - 3.0;
	double h = hour + minute/60. + second/3600.;
	return (day + floor(0.2*(153.0*mm+2.0)) + 365.0*yy + floor(0.25*yy)
					- floor(0.01*yy) + floor(0.0025*yy) - 32045.5 + h/24.0);
}


void CalendarDate::set_from_iso_string(const char *date)
{

    int num_items = sscanf(date, "%d-%d-%d %d:%d:%lf", &year, &month, &day,
                           &hour, &minute, &second);

    if (num_items != 6)
    {
        cout << "Error reading formatted date." << endl;
    }
    normalize();
}


void CalendarDate::set_from_isot_string(const char *date)
{

    int num_items = sscanf(date, "%d-%d-%dT%d:%d:%lf", &year, &month, &day,
                           &hour, &minute, &second);

    if (num_items != 6)
    {
        cout << "Error reading formatted date." << endl;
    }
    normalize();
}


void CalendarDate::set_from_julian_day(double input_jd)
{
    double JD, MJD, year, day, hour, minute, second, F, A, a, Z, B, C, D, E;
    int month;

    if (input_jd < 2378496.5)
        JD = input_jd + 2400000.5;
    else
        JD = input_jd;


    Z = (int)(JD + 0.5);
    F = (JD + 0.5) - Z;

    if (Z < 2299161)
        A = Z;
    else
    {
        a = (int)((Z - 1867216.25) / 36524.25);
        A = Z + 1 + a - (int)(a / 4.0);
    }

    B = A + 1524;
    C = (int)((B - 122.1) / 365.25);
    D = (int)(365.25 * C);
    E = (int)((B - D) / 30.6001);


    day = B - D - (int)(30.6001 * E) + F;

    if (E < 13.5)
        month = E - 1;
    else
        month = E - 13;


    if (month > 2.5)
        year = C - 4716;
    else
        year = C - 4715;

    hour = (int)((day - (int)day) * 24.0);
    minute = (int)(((day - (int)day) * 24.0 - hour) * 60.0);
    second = ((((day - (int)day) * 24.0 - hour) * 60.0) - minute) * 60.0;

    day = (int)day;

    this->year = (int)year;
	this->month = (int)month;
	this->day = (int)day;
	this->hour = (int)hour;
	this->minute = (int)minute;
    this->second = second;
}

string CalendarDate::string_iso()
{
    char tmp[100];
    sprintf(tmp, "%d-%02d-%02d %02d:%02d:%013.10lf", year, month, day, hour, minute,
            second);
    return string(tmp);
}


string CalendarDate::string_isot()
{
    char tmp[100];
    sprintf(tmp, "%d-%02d-%02dT%02d:%02d:%013.10lf", year, month, day, hour, minute,
            second);
    return string(tmp);
}



} // namespace Time
