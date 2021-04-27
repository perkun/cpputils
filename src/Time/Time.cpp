#include "Time.h"

namespace Time {

double julian_day_now()
{
	//	wzięte z sterownia_unc09.h
	/// current UT -> JD

    int r,m,d;
	double aa, yy, mm, h;
    time_t rawtime;
    struct tm * ptm;

    time(&rawtime);
    ptm=gmtime(&rawtime);
    r=1900+(ptm->tm_year);
    m=1+(ptm->tm_mon);
    d=(ptm->tm_mday);
    h=1.0*(ptm->tm_hour) + (ptm->tm_min)/60.0 + (ptm->tm_sec)/3600.0;

	aa=floor((14.0-m)/12.0);
	yy=r+4800.0-aa;
	mm=m+12.0*aa-3.0;
	return (d + floor(0.2*(153.0*mm+2.0)) + 365.0*yy + floor(0.25*yy)
					- floor(0.01*yy) + floor(0.0025*yy) - 32045.5 + h/24.0);
}

double julian_day(int r, int m, int d, double h)
{
	double aa, yy, mm;
	aa=floor((14.0-m)/12.0);
	yy=r+4800.0-aa;
	mm=m+12.0*aa-3.0;
	return (d + floor(0.2*(153.0*mm+2.0)) + 365.0*yy + floor(0.25*yy)
					- floor(0.01*yy) + floor(0.0025*yy) - 32045.5 + h/24.0);
}



double julian_day(const char *date, const char *format)
{
    /// format needs 6 fields: Y M D h m s
	/// e.g. "Y-M-D-h:m:s", "h m s Y/M/D"

    int year, month, day, hour, minute;
    double sec;

    int num_items =
        sscanf(date, format, &year, &month, &day, &hour, &minute, &sec);

	if (num_items != 6)
	{
		cout << "Error reading formatted date" << endl;
		return -1.0;
	}

    return julian_day(year, month, day, hour + minute / 60. + sec / 3600.);
}
}
