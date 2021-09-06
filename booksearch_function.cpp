void bookssearch()
{
  char data[10];
  color();
   setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"BOOK SEARCH PAGE");
 gotoxy(30,15);
 printf("ENTER BOOK ID : ");
 fflush(stdin);
 scanf("%s",data);
 booksearch(data);
 getch();
 color();
 adminmenu();
}
void booksearch(char data[10])
{
	FILE *fp;

	fp=fopen("book.txt","rb");
	if(fp==NULL)
	{
	 gotoxy(30,10);
	 printf("FIRST ADD ANY BOOK");
	 gotoxy(38,12);
	 getch();
	 color();
	 adminmenu();
	}
	else
	{
	   color();
		   setcolor(BLUE);
		settextstyle(7,0,5);
		outtextxy(100,30,"BOOK SEARCH PAGE");
		 gotoxy(30,15);
		printf("ENTER BOOK ID : %s",data);
		fread(&books,sizeof(books),1,fp);
		while(!feof(fp))
		{
			if((strcmp(data,books.id))==0)
			{
			      color();
			       setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"BOOK SEARCH PAGE");
			      gotoxy(30,10);
			      printf("BOOK ID     : %s",books.id);
			      gotoxy(30,12);
			      printf("TITLE       : %s",books.title);
			     gotoxy(30,14);
			     printf("AUTHOR NAME : %s",books.author);
			     gotoxy(30,16);
			     printf("QUANTITY    : %d",books.q);
			     gotoxy(30,18);
			     printf("SHELF NO    : %d",books.sn);
			     gotoxy(40,20);
			     fclose(fp);
			     goto out;
			}
			fread(&books,sizeof(books),1,fp);
		}
		fclose(fp);
		 gotoxy(30,20);
		 printf("YOU ENTERED WRONG BOOK ID");
		 gotoxy(30,22);
		 printf("PRESS ANY KEY TO GO BACK");
		   gotoxy(35,24);
		   getch();
	}
	out :

}
