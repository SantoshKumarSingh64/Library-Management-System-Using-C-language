void booksupdate()
{
   char b[20],mid[20];
   int value,ch;
   char ch1;
   FILE *fp,*fp1;
   color();
   fp=fopen("book.txt","rb");
   if(fp==NULL)
   {
	 gotoxy(30,10);
	 printf("FIRST ADD ANY BOOK");
	 gotoxy(38,12);
	 getch();
	 adminmenu();
   }
   else
   {
   setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"BOOK UPDATE PAGE");
   gotoxy(30,14);
   printf("ENTER BOOK ID : ");
   fflush(stdin);
   scanf("%s",b);

   fread(&books,sizeof(books),1,fp);
   while(!feof(fp))
   {
     if((strcmp(b,books.id))==0)
     {
	color();
	setcolor(BLUE);
	settextstyle(7,0,5);
	 outtextxy(100,30,"BOOK UPDATE PAGE");
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
	gotoxy(33,24);
	fclose(fp);

	goto out;
     }
	fread(&books,sizeof(books),1,fp);
   }
    gotoxy(30,20);
    printf("YOU ENTERED WRONG BOOK ID");
    gotoxy(30,22);
    printf("PRESS ANY KEY TO GO BACK");
    gotoxy(35,24);
    getch();
    adminmenu();
     out :
     gotoxy(30,20);
     printf("PRESS 1 FOR EDIT BOOK TITLE");
     gotoxy(30,21);
     printf("PRESS 2 FOR EDIT AUTHOR NAME");
     gotoxy(30,22);
     printf("PRESS 3 FOR EDIT QUANTITY");
     gotoxy(30,23);
     printf("PRESS 4 FOR EDIT SHELF NO");
     gotoxy(30,24);
     printf("PRESS 5 FOR TO BACK MENU");
     gotoxy(40,25);
     scanf("%d",&ch);
     switch(ch)
     {
      case 1:
	     color();
	      setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"BOOK UPDATE PAGE");
	     gotoxy(30,13);
	     printf("ENTER TITLE : ");
	     fflush(stdin);
	     scanf("%[^\n]s",&mid);
	      gotoxy(30,16);
	      printf("PRESS Y TO UPDATE DETAILS : ");
	      fflush(stdin);
	      scanf("%s",&ch1);
	      if(ch1=='y'||ch1=='Y')
	     {
	     fp1=fopen("book1.txt","wb");
	     fp=fopen("book.txt","rb");
	     fread(&books,sizeof(books),1,fp);
	     while(!feof(fp))
	     {
	       if((strcmp(b,books.id))!=0)
		  fwrite(&books,sizeof(books),1,fp1);
	       if((strcmp(b,books.id))==0)
	       {
		 strcpy(books.title,mid);
		 fwrite(&books,sizeof(books),1,fp1);
	       }
	       fread(&books,sizeof(books),1,fp);
	     }
	     fclose(fp);
	     fclose(fp1);
	     remove("book.txt");
	     rename("book1.txt","book.txt");
	      gotoxy(40,21);
	      printf("UPDATED");
	     gotoxy(43,23);
	     }
	      else
	     {
	      gotoxy(40,21);
	      printf("NOT UPDATED");
	      gotoxy(43,23);
	     }
	     break;
      case 2:
	     color();
	      setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"BOOK UPDATE PAGE");
	     gotoxy(30,13);
	     printf("ENTER AUTHOR NAME : ");
	     fflush(stdin);
	      scanf("%[^\n]s",&mid);
	     gotoxy(30,16);
	     printf("PRESS Y TO UPDATE DETAILS : ");
	     fflush(stdin);
	     scanf("%s",&ch1);
	     if(ch1=='y'||ch1=='Y')
	    {
	     fp1=fopen("book1.txt","wb");
	     fp=fopen("book.txt","rb");
	     fread(&books,sizeof(books),1,fp);
	     while(!feof(fp))
	     {
	       if((strcmp(b,books.id))!=0)
		  fwrite(&books,sizeof(books),1,fp1);
	       if((strcmp(b,books.id))==0)
	       {
		 strcpy(books.author,mid);
		 fwrite(&books,sizeof(books),1,fp1);
	       }
	       fread(&books,sizeof(books),1,fp);
	     }
	     fclose(fp);
	     fclose(fp1);
	     remove("book.txt");
	     rename("book1.txt","book.txt");
	      gotoxy(40,21);
	     printf("UPDATED");
	     gotoxy(43,23);
	     }
	      else
	     {
		gotoxy(40,21);
		printf("NOT UPDATED");
		gotoxy(43,23);
	     }
	     break;
      case 3:
	     color();
	      setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"BOOK UPDATE PAGE");
	     gotoxy(30,13);
	     printf("ENTER QUANTITY : ");
	     fflush(stdin);
	     scanf("%d",&value);
	      gotoxy(30,16);
	      printf("PRESS Y TO UPDATE DETAILS : ");
	      fflush(stdin);
	      scanf("%s",&ch1);
	      if(ch1=='y'||ch1=='Y')
	     {
	     fp1=fopen("book1.txt","wb");
	     fp=fopen("book.txt","rb");
	     fread(&books,sizeof(books),1,fp);
	     while(!feof(fp))
	     {
	       if((strcmp(b,books.id))!=0)
		  fwrite(&books,sizeof(books),1,fp1);
	       if((strcmp(b,books.id))==0)
	       {
		 books.q=value;
		 fwrite(&books,sizeof(books),1,fp1);
	       }
	       fread(&books,sizeof(books),1,fp);
	     }
	     fclose(fp);
	     fclose(fp1);
	     remove("book.txt");
	     rename("book1.txt","book.txt");
	      gotoxy(40,21);
	     printf("UPDATED");
	      gotoxy(43,23);
	     }
	      else
	      {
		  gotoxy(40,21);
		  printf("NOT UPDATED");
		  gotoxy(43,23);
	       }
	     break;
      case 4:
	     color();
	      setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"BOOK UPDATE PAGE");
	     gotoxy(30,13);
	     printf("ENTER SHELF NO : ");
	     scanf("%d",&value);
	     gotoxy(30,16);
	     printf("PRESS Y TO UPDATE DETAILS : ");
	     fflush(stdin);
	     scanf("%s",&ch1);
	     if(ch1=='y'||ch1=='Y')
	    {
	      fp1=fopen("book1.txt","wb");
	     fp=fopen("book.txt","rb");
	     fread(&books,sizeof(books),1,fp);
	     while(!feof(fp))
	     {
	       if((strcmp(b,books.id))!=0)
		  fwrite(&books,sizeof(books),1,fp1);
	       if((strcmp(b,books.id))==0)
	       {
		  books.sn=value;
		 fwrite(&books,sizeof(books),1,fp1);
	       }
		fread(&books,sizeof(books),1,fp);
	     }
	     fclose(fp);
	     fclose(fp1);
	     remove("book.txt");
	     rename("book1.txt","book.txt");
	      gotoxy(40,21);
	     printf("UPDATED");
	     gotoxy(43,23);
	     }
	     else
	    {
		gotoxy(40,21);
		printf("NOT UPDATED");
		gotoxy(43,23);
	    }
	     break;
      case 5:
	     studentid1();
     default:
	     booksupdate();
    }
   getch();
   adminmenu();
}
}
