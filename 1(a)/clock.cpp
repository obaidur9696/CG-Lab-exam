#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>

int hr,sec,min;

void drawClock(int xc,int yc)
{
int i,inr=70,outr=80;
int hdeg,mindeg,secdeg,x,y;
circle(xc,yc,outr);
setfillstyle(SOLID_FILL,WHITE);
fillellipse(xc,yc,2,2);
for(i=180;i>-360;i-=6)
{
if(i%5==0)
 fillellipse(xc+inr*sin(i*3.14f/180),yc+inr*cos(i*3.14f/180),2,2);
else
 fillellipse(xc+inr*sin(i*3.14f/180),yc+inr*cos(i*3.14f/180),1,1);
//draw hands
hdeg=hr*360/12+30*min/60;
mindeg=min*6;
secdeg=sec*6;
x=xc+40*sin(hdeg*3.14f/180);
y=yc-40*cos(hdeg*3.14f/180);
line(xc,yc,x,y);
x=xc+55*sin(mindeg*3.14f/180);
y=yc-55*cos(mindeg*3.14f/180);

line(xc,yc,x,y);
}

}

main()
{

time_t now;
struct tm *timeinfo;
int gd=DETECT,gm,midx,midy;
int tsec,tmin,thr;
initgraph(&gd,&gm,"..\\BGI\\");
midx=getmaxx()/2;
midy=getmaxy()/2;


hr=9;
min=00;


while(!kbhit())
{
drawClock(midx,midy);
delay(200000);
cleardevice();

tmin=00;
thr=9;
}
}