void issuebook()
{
 FILE *fp;
 FILE *fp1;
 FILE *fp2;
 char studentid[15],bookid[15];
 char ch;
 color();
  setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"ISSUE BOOK PAGE");
 gotoxy(30,10);
 printf("ENTER STUDDENT ID      : ");
 fflush(stdin);
 scanf("%s",&studentid);
 fp1=fopen("student.txt","rb");
   if(fp1==NULL)
   {
    printf("Can't open student file!!!");
    getch();
    exit(0);
   }
   fread(&student,sizeof(student),1,fp1);
   while(!feof(fp1))
   {
     if((strcmp(studentid,student.id))==0)
     {
       fclose(fp1);
       goto out2;
     }
      fread(&student,sizeof(student),1,fp1);
   }
   fclose(fp1);
   gotoxy(25,16);
   printf("THIS STUDENT ID HAS NOT CREATED YET");
   gotoxy(40,18);
   getch();
   studentid1();
   out2 :
   gotoxy(30,12);
   printf("ENTER BOOK ID          : ");
   fflush(stdin);
   scanf("%s",&bookid);
   fp2=fopen("book.txt","rb");
   if(fp2==NULL)
   {
     printf("Can't open book file!!!");
     getch();
     exit(0);
   }
   fread(&books,sizeof(books),1,fp2);
   while(!feof(fp2))
   {
     if((strcmp(bookid,books.id))==0)
     {
       fclose(fp2);
       goto out1;
     }
     fread(&books,sizeof(books),1,fp2);
   }
   fclose(fp2);
   gotoxy(25,16);
   printf("THIS BOOK ID HAS NOT CREATED YET");
   gotoxy(40,18);
   getch();
   studentid1();
   out1:
   fp=fopen("isbook.txt","rb");
   fread(&st1,sizeof(st1),1,fp);
   while(!feof(fp))
   {
     if(((strcmp(st1.bookid,bookid))==0)&&((strcmp(st1.studentid,studentid))==0))
     {
       gotoxy(25,16);
       printf("YOU HAVE ALREADY ISSUED THIS BOOK");
       gotoxy(40,18);
       getch();
       studentid1();
     }
     fread(&st1,sizeof(st1),1,fp);
   }
   fclose(fp);
   gotoxy(30,14);
   printf("ENTER DATE(DD MM YYYY) : ");
   fflush(stdin);
   scanf("%d %d %d",&st1.date,&st1.month,&st1.year);
   gotoxy(25,18);
   printf("PRESS I FOR ISSUE THIS BOOK : ");
   fflush(stdin);
   scanf("%s",&ch);
   if(ch=='i'||ch=='I')
   {
      strcpy(st1.studentid,studentid);
      strcpy(st1.bookid,bookid);
      fp=fopen("isbook.txt","ab");
      if(fp==NULL)
      {
	printf("Can't open file!!");
	getch();
	exit(0);
      }
      fwrite(&st1,sizeof(st1),1,fp);
      gotoxy(40,20);
      printf("ISSUED");
      gotoxy(43,22);
      fclose(fp);
   }
   else
   {
     gotoxy(40,20);
     printf("NOT ISSUED");
     gotoxy(43,22);
   }
   getch();
   studentid1();
}
