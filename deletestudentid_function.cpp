void deletestudentid()
{
  FILE *fp,*fp1;
  char data[15],ch;
  int flag=1;
  color();
  setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(30,30,"DELETE STUDENT ID PAGE");
  gotoxy(30,14);
 printf("ENTER STUDENT ID : ");
 scanf("%s",&data);
 fp=fopen("student.txt","rb");
  fread(&student,sizeof(student),1,fp);
  while(!feof(fp))
  {
    if((strcmp(data,student.id))==0)
     {
       flag = 0;
     }
   fread(&student,sizeof(student),1,fp);
  }
  fclose(fp);
  if(flag!=0)
  {
    gotoxy(30,18);
    printf("YOU ENTERED WRONG STUDENT ID");
    gotoxy(30,20);
    printf("PRESS ANY KEY FOR BACK MENU");
    gotoxy(40,22);
    getch();
    goto out ;
  }
   gotoxy(30,18);
   printf("PRESS D TO DELETE : ");
   fflush(stdin);
   scanf("%s",&ch);
   if(ch=='D'||ch=='d')
   {
	fp1=fopen("student1.txt","wb");
	if(fp1==NULL)
	{
	    printf("Unable to open file!!!");
	    getch();
	    exit(0);
	}
       fp=fopen("student.txt","rb");
       fread(&student,sizeof(student),1,fp);
       if(flag==0)
       {
	 while(!feof(fp))
	 {
	   if((strcmp(data,student.id))!=0)
	   fwrite(&student,sizeof(student), 1, fp1);
	   fread(&student,sizeof(student),1,fp);
	 }
       }
       fclose(fp);
       fclose(fp1);
      remove("student.txt");
      rename("student1.txt","student.txt");
      fp1=fopen("isbook1.txt","wb");
      if(fp1==NULL)
      {
       printf("Unable to open file!!!");
       getch();
       exit(0);
      }
     fp=fopen("isbook.txt","rb");
     fread(&st1,sizeof(st1),1,fp);
     if(flag==0)
     {
      while(!feof(fp))
      {
	if((strcmp(data,student.id))!=0)
	  fwrite(&st1,sizeof(st1), 1, fp1);
	fread(&st1,sizeof(st1),1,fp);
      }
     }
    fclose(fp);
    fclose(fp1);
    remove("isbook.txt");
    rename("isbook1.txt","isbook.txt");
    fp1=fopen("fine1.txt","wb");
      if(fp1==NULL)
      {
       printf("Unable to open file!!!");
       getch();
       exit(0);
      }
     fp=fopen("fine.txt","rb");
     fread(&f,sizeof(f),1,fp);
     if(flag==0)
     {
      while(!feof(fp))
      {
	if((strcmp(data,f.studentid))!=0)
	  fwrite(&f,sizeof(f), 1, fp1);
	fread(&f,sizeof(f),1,fp);
      }
     }
    fclose(fp);
    fclose(fp1);
    remove("fine.txt");
    rename("fine1.txt","fine.txt");
   gotoxy(38,22);
   printf("DELETED");
   gotoxy(42,24);
  }
  else
  {
   gotoxy(38,22);
   printf("NOT DELETED");
   gotoxy(42,24);
  }
   out :
   getch();
   studentid1();
}
