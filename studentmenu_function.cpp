void studentmenu()
{
    int ch;
    color();
       setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"STUDENT MENU PAGE");
    gotoxy(30,10);
    printf("PRESS 1 FOR BOOK SEARCH");
    gotoxy(30,12);
    printf("PRESS 2 FOR YOUR BOOK");
    gotoxy(30,14);
    printf("PRESS 3 FOR LOGOUT");
    fflush(stdin);
    gotoxy(40,17);
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
	     booksstudentsearch();
	     break;
      case 2:
	     yourbooks();
	     break;
      case 3:
	     secondpage();
    }
}
