void returnbook()
{
 FILE *fp,*fp1;
 char studentid[10],bookid[10],ch,ch1;
 int fine,flag=0;
 color();
  setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"RETURN BOOK PAGE");
 gotoxy(30,10);
 printf("ENTER STUDENT ID : ");
 scanf("%s",&studentid);
 gotoxy(30,12);
 printf("ENTER BOOK ID : ");
 scanf("%s",&bookid);
 fp=fopen("isbook.txt","rb");
 if(fp==NULL)
 {
   gotoxy(25,17);
   printf("PLEASE ISSUE ANY BOOK");
   gotoxy(35,19);
   getch();
   exit(0);
 }
 fread(&st1,sizeof(st1),1,fp);
 while(!feof(fp))
 {
   if(((strcmp(studentid,st1.studentid))==0)&&((strcmp(bookid,st1.bookid))==0))
   {
     color();
      setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(100,30,"RETURN BOOK PAGE");
     gotoxy(30,10);
     printf("STUDENT ID              : %s ",st1.studentid);
     gotoxy(30,12);
     printf("BOOK ID                 : %s ",st1.bookid);
     gotoxy(30,14);
     printf("ISSUE DATE (dd mm yyyy) : %d %d %d",st1.date,st1.month,st1.year);
     gotoxy(30,16);
     printf("     PRESS R FOR RETURN : ");
     scanf("%s",&ch);
     if(ch=='r'||ch=='R')
    {
     fclose(fp);
     goto out;
    }
     else
    {
    gotoxy(42,21);
    printf("NOT RETURNED");
    gotoxy(45,23);
    getch();
    studentid1();
    }
   }
   fread(&st1,sizeof(st1),1,fp);
 }
 fclose(fp);
 gotoxy(25,16);
 printf("THIS STUDENT ID OR BOOK ID HAS NOT ISSUED");
 gotoxy(35,18);
 getch();
 studentid1();
 out :
  fp1=fopen("isbook1.txt","wb");
  if(fp1==NULL)
  {
      printf("Unable to open file!!!");
      getch();
      exit(0);
  }
   fp=fopen("isbook.txt","rb");
 fread(&st1,sizeof(st1),1,fp);
 while(!feof(fp))
 {
   if(((strcmp(studentid,st1.studentid))!=0)&&((strcmp(bookid,st1.bookid))!=0))
   {
     fwrite(&st1,sizeof(st1),1,fp1);
   }
   fread(&st1,sizeof(st1),1,fp);
 }
 fclose(fp);
 fclose(fp1);
 remove("isbook.txt");
 rename("isbook1.txt","isbook.txt");
 gotoxy(30,18);
 printf(" IS THERE ANY FINE(Y/S) : ");
 fflush(stdin);
 scanf("%s",&ch1);
 if(ch1=='y'||ch1=='Y')
 {
   gotoxy(30,20);
   printf("            FINE IN RS. : ");
   fflush(stdin);
    scanf("%d",&fine);
   fp=fopen("fine.txt","rb");
   fread(&f,sizeof(f),1,fp);
   while(!feof(fp))
   {
    if((strcmp(f.studentid,studentid))==0)
	fine=fine+f.price;
    fread(&f,sizeof(f),1,fp);
   }
   fclose(fp);
  // printf("%d",fine);
   fp1=fopen("fine1.txt","wb");
   fp=fopen("fine.txt","rb");
   fread(&f,sizeof(f),1,fp);
   while(!feof(fp))
   {
    if((strcmp(f.studentid,studentid))!=0)
	fwrite(&f,sizeof(f),1,fp1);
    if((strcmp(f.studentid,studentid))==0)
      {
	flag=1;
	f.price=fine;
	fwrite(&f,sizeof(f),1,fp1);
      }
     fread(&f,sizeof(f),1,fp);
   }
   fclose(fp);
  fclose(fp1);
  if(flag==0)
  {
   fp=fopen("fine1.txt","ab");
   strcpy(f.studentid,studentid);
   f.price=fine;
 // printf("%s %d",f.studentid,f.price);
   fwrite(&f,sizeof(f),1,fp1);
   fclose(fp);
 }
 remove("fine.txt");
 rename("fine1.txt","fine.txt");
 }
 gotoxy(42,23);
 printf("RETURNED");
 gotoxy(45,25);
 getch();
 studentid1();
}
