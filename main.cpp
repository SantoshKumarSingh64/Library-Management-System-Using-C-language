void main()
{
  int gd=DETECT;
  int gm;
  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
  color();
  setcolor(BLUE);
  settextstyle(7,0,5);
  outtextxy(90,200,"WELCOME TO LIBRARY");
  getch();
  secondpage();
  getch();
}
