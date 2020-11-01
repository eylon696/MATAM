#include<stdio.h>
#include<math.h>
#include<conio.h>
typedef struct Point //structure definition, point type (x, y)
{
	float x, y;
}Point;
typedef struct Circle//structure definition, circle type o(x, y),radius
{
	Point point;
	float radius;
}Circle;
/*functions declaration*/
int pointincircle(Point c, Circle d);
int main()
{
	Point a;
	Circle b;
	printf("Enter the coordinates of your point:");
	scanf("%f %f", &a.x, &a.y);
	printf("Enter the radius and the center of your circle:");
	scanf("%f %f %f", &b.radius, &b.point.x, &b.point.y);
	if (pointincircle(a, b))//If the function returns one point within the circle else the point is not within the circle
		printf("The point is included in the circle");
	else
		printf("The point is not included in the circle");
	getch();
	return 0;
}
int pointincircle(Point c, Circle d)//A function that checks whether the radius is greater than the straightness connecting the two points
{
	if (d.radius > sqrt((d.point.x - c.x)*(d.point.x - c.x) + (d.point.y - c.y)*(d.point.y - c.y)))
		return 1;
	return 0;
}