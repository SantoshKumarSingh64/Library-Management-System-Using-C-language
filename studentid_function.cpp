void studentid1()
{
   int ch;
   color();
   setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(180,25,"ADMIN MENU");
   gotoxy(30,8);
   printf("PRESS 1 FOR CREATE STUDENT ID");
   gotoxy(30,10);
   printf("PRESS 2 FOR DELETE ID");
   gotoxy(30,12);
   printf("PRESS 3 FOR EDIT STUDENT ID");
   gotoxy(30,14);
   printf("PRESS 4 FOR SHOW STUDENT DETAILS");
   gotoxy(30,16);
   printf("PRESS 5 FOR ISSUE BOOK");
   gotoxy(30,18);
   printf("PRESS 6 FOR RETURN BOOK");
   gotoxy(30,20);
   printf("PRESS 7 FOR FINE PAYMENTS");
   gotoxy(30,22);
   printf("PRESS 8 FOR BACK MENU");
   gotoxy(38,24);
   fflush(stdin);
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
	     createstudentid1();
	     break;
     case 2:
	     deletestudentid();
	     break;
     case 3:
	     editstudentid();
	     break;
     case 4:
	     showstudentdetails();
	     break;
     case 5:
	    issuebook();
	     break;
     case 6:
	     returnbook();
	     break;
     case 7:
	     finepayment();
	     break;
     case 8:
	     adminmenu();
   }
}
