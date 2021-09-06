void adminmenu()
{
   int ch;
   color();
   settextstyle(7,0,5);
   setcolor(RED);
   outtextxy(180,25,"ADMIN MENU");
   gotoxy(30,8);
   printf("PRESS 1 FOR ADD BOOKS");
   gotoxy(30,10);
   printf("PRESS 2 FOR BOOKS SEARCH");
   gotoxy(30,12);
   printf("PRESS 3 FOR BOOKS UPDATE");
   gotoxy(30,14);
   printf("PRESS 4 FOR DELETE BOOKS");
   gotoxy(30,16);
   printf("PRESS 5 FOR STUDENT IDS");
   gotoxy(30,18);
   printf("PRESS 6 FOR LOGOUT");
   gotoxy(41,21);
   fflush(stdin);
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
	     addbooks();
	     break;
     case 2:
	     bookssearch();
	     break;
     case 3:
	   booksupdate();
	    break;
     case 4:
	   deletebookid();
	    break;
     case 5:
	    studentid1();
	    break;
     case 6:
	    secondpage();
	    break;
     default:
	     initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	     adminmenu();
   }
}
