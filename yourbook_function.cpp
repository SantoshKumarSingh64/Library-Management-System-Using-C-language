void yourbooks()
{
   FILE *fp;
   int c=25,r=13,count=0;
   color();
   setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(140,30,"MY BOOKS PAGE");
   fp=fopen("isbook.txt","rb");
   fread(&st1,sizeof(st1),1,fp);
   while(!feof(fp))
   {
      if((strcmp(myuser,st1.studentid))==0)
      {
	 if(count==0)
	 {
	   gotoxy(c,r);
	   printf("ALLOTED BOOKS   : %s",st1.bookid);
	 }
	 else
	 {
	   gotoxy(c,r);
	   printf("                : %s",st1.bookid);
	 }
	 r=r+2;
	 count++;
      }
      fread(&st1,sizeof(st1),1,fp);
   }
   if(count==0)
   {
     gotoxy(25,15);
     printf("ALLOTED BOOKS   : NO BOOKS ALLOTED");
   }
   gotoxy(35,18);
   getch();
   studentmenu();
}
