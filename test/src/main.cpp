#include <iostream>
#include <stdio.h>
#include "Time.h"

using namespace std;

int main(int argc, char *argv[])
{

	Time::CalendarDate date(2451232.41823751234);

	cout << date.string_isot() << endl;

	printf("%.16lf\n", date.julian_day());

	Time::CalendarDate date2;
	date2.set_from_isot_string("1999-02-22T22:02:15.721077");

	printf("%.16lf\n", date2.julian_day());

	Time::CalendarDate date3(Time::julian_day_now());


	cout << date3.string_iso() << endl;



	return 0;
}

