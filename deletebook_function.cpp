void deletebookid()
{
   char b[15];
   color();
    setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"DELETE BOOK PAGE");
   gotoxy(30,14);
   printf("ENTER BOOK ID  : ");
   scanf("%s",b);
   deletebook(b,"deletion");
   adminmenu();
}
void deletebook(char b[15],char status[12])
{
    int flag=1;
    FILE *fp,*fp1;
    char ch;
     if((strcmp(status,"deletion"))==0)
       color();
	fp=fopen("book.txt","rb");
	if(fp==NULL)
	{
	 gotoxy(30,10);
	 printf("FIRST ADD ANY BOOK");
	 gotoxy(38,12);
	 getch();
	 goto out ;
	}
	 gotoxy(34,10);
   if((strcmp(status,"deletion"))==0)
  {
    setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"DELETE BOOK PAGE");
   gotoxy(30,14);
   printf("ENTER BOOK ID  : %s",b);
  }
   fread(&books,sizeof(books),1,fp);
   while(!feof(fp))
   {
     if((strcmp(b,books.id))==0)
     {
       flag = 0;
     }
	fread(&books,sizeof(books),1,fp);
   }
    fclose(fp);
   if(flag!=0)
  {
    gotoxy(30,18);
    printf("YOU ENTERED WRONG BOOK ID");
    gotoxy(30,20);
    printf("PRESS ANY KEY FOR BACK MENU");
    gotoxy(40,22);
    getch();
    goto out ;
  }
   if((strcmp(status,"deletion"))==0)
 {
   gotoxy(30,18);
   printf("PRESS D TO DELETE : ");
   fflush(stdin);
   scanf("%s",&ch);
 }
 else
    ch='d';
   if(ch=='D'||ch=='d')
  {
	fp1=fopen("book1.txt","wb");
	if(fp1==NULL)
	{
	    printf("Unable to open file!!!");
	    getch();
	    exit(0);
	}
       fp=fopen("book.txt","rb");
       fread(&books,sizeof(books),1,fp);
       if(flag==0)
   {
       while(!feof(fp))
     {
       if((strcmp(b,books.id))!=0)
	  fwrite(&books,sizeof(books), 1, fp1);
       fread(&books,sizeof(books),1,fp);
     }
    }
    fclose(fp);
    fclose(fp1);
      remove("book.txt");
       rename("book1.txt","book.txt");
	if((strcmp(status,"deletion"))==0)
       {
       gotoxy(38,22);
       printf("DELETED");
       gotoxy(42,24);
       }
       getch();
       goto out;
   }
   else
   {
     gotoxy(38,22);
     printf("NOT DELETED");
     gotoxy(45,24);
     getch();
    goto out ;
    }
  out :
}
