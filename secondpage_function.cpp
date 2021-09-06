void secondpage()
{
   int ch;
   color();
   setcolor(RED);
   settextstyle(7,0,3);
   outtextxy(150,40,"PRESS 1 FOR ADMIN");
   outtextxy(150,120,"PRESS 2 FOR STUDENTS");
   outtextxy(150,200,"PRESS 3 FOR EXIT");
   gotoxy(38,17);
   fflush(stdin);
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
	    admin();
	    break;
     case 2:
	    studentpage();
	    break;
     case 3:
	    closegraph();
	    exit(0);
     default:
	     secondpage();
   }
}
