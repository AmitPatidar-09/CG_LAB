#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1, y1, x2, y2;

    printf("Enter Point 1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter Point 2: ");
    scanf("%d %d", &x2, &y2);

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    int i;
    for(i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5 + 50), (int)(y + 0.5 + 50), RED);
        x = x + xInc;
        y = y + yInc;
        //delay(10);
    }

    getch();
    closegraph();
}
