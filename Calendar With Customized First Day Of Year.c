// MuahmmadAli Alizadeh
// Dr.Sutoodeh(Shiraz IAU)

#include<stdio.h>

int days_in_month[]={0,31,31,31,31,31,31,30,30,30,30,30,29};
char *months[]=
{
	" ",
	"\n\n\nFarvardin",
	"\n\n\nOrdibehesht",
	"\n\n\nKhordad",
	"\n\n\nTir",
	"\n\n\nMordad",
	"\n\n\nShahrivar",
	"\n\n\nMehr",
	"\n\n\nAban",
	"\n\n\nAzar",
	"\n\n\nDey",
	"\n\n\nBahman",
	"\n\n\nEsfand"
};


int inputyear(void)
{
	int year;

	printf("Please enter a year (example: 1401) : ");
	scanf("%d", &year);
	return year;
}

int inputFirstDayOfWeek(void)
{
	int dayOfWeek;

	printf("Please enter the first day of week in number(from 0)(example: 1 for Yek-SHANBE)) : ");
	scanf("%d", &dayOfWeek);
	return dayOfWeek;
}


int determineleapyear(int year)
{
	if(year% 4 == 0 && year%100 != 0 || year%400 == 0)
	{
		days_in_month[2] = 29;
		return 1;
	}
	else
	{
		days_in_month[2] = 28;
		return 0;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSH  1SH  2SH  3SH  4SH  5SH  JOM\n" );

		// Correct the position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}

		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );

			// Is day before JOM? Else start next line SH.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}

int main(void)
{
	int year, firstDay , leapyear;

	year = inputyear();
	firstDay = inputFirstDayOfWeek();
	determineleapyear(year);
	calendar(year, firstDay);
	printf("\n\n\n");
	printf("Developed By : MuhammadAli Alizadeh => Zigbalthazar@gmail.com");
    printf("\n\n\n");
}
