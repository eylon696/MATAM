#include <stdio.h>
#include <math.h>
#include <conio.h>
//define structure
typedef struct Clock
{
	int hour, minute;
}clock_t;

int main()
{
	int addition;
	clock_t time;
	int addMinutes;
	printf("Enter time and minutes to add: ");
	while (1)  //scan a valid time
	{
		scanf("%d %d %d", &(time.hour), &(time.minute), &addMinutes);
		if ((time.hour < 25) && (time.hour>=0) && (time.minute < 60) && (time.minute >= 0))
			break;
		else
			printf("Please enter a valid time:\n");
	}
	if (time.hour == 24)
		time.hour -= 24;
	if (time.hour >= 0 && time.hour <= 9)
	{
		if ((time.minute >= 0) && (time.minute <= 9))
			printf("The time is: 0%d:0%d\n", time.hour, time.minute);
		else
			printf("The time is: 0%d:%d\n", time.hour, time.minute);
	}
	else
	{
		if ((time.minute >= 0) && (time.minute <= 9))
			printf("The time is: %d:0%d\n", time.hour, time.minute);
		else
			printf("The time is: %d:%d\n", time.hour, time.minute);
	}
	addition = time.minute + addMinutes;  //calculates the total minutes
	if (addition < 60)
		time.minute = addition;
	else
		while (addition >= 60)  //the loop calculates the minutes and hours to add
		{
			time.hour += 1;
			time.minute = addition - 60;
			addition -= 60;
			if (time.hour == 24)
				time.hour -= 24;
		}
	if (time.hour >= 0 && time.hour <= 9)
	{
		if ((time.minute >= 0) && (time.minute <= 9))
			printf("The new time is: 0%d:0%d", time.hour, time.minute);
		else
			printf("The new time is: 0%d:%d", time.hour, time.minute);
	}
	else
	{
		if ((time.minute >= 0) && (time.minute <= 9))
			printf("The new time is: %d:0%d", time.hour, time.minute);
		else
			printf("The new time is: %d:%d", time.hour, time.minute);
	}
	getch();
	return 0;
}