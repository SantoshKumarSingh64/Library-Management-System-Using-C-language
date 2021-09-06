void showstudentdetails()
{
  FILE *fp,*fp1,*fp2;
  char data[10];
  int c=30,r=18,count=0;
  color();
      setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(50,30,"STUDENT DETAILS PAGE");
  gotoxy(25,13);
  printf("ENTER STUDENT ID : ");
  scanf("%s",&data);
  fp=fopen("student.txt","rb");
  if(fp==NULL)
  {
   printf("Can't Open Student File");
   getch();
   exit(0);
  }
   fread(&student,sizeof(student),1,fp);
   while(!feof(fp))
   {
     if((strcmp(data,student.id))==0)
     {
      color();
	 setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(50,30,"STUDENT DETAILS PAGE");
      gotoxy(30,8);
      printf("STUDENT ID          : %s",student.id);
      gotoxy(30,10);
      printf("STUDENT ID PASSWORD : %s",student.pass);
      gotoxy(30,12);
      printf("STUDENT NAME        : %s",student.name);
      gotoxy(30,14);
      printf("STUDENT BRANCH      : %s",student.branch);
      fclose(fp);
      fp2=fopen("fine.txt","rb");
      fread(&f,sizeof(f),1,fp2);
      while(!feof(fp2))
      {
       if((strcmp(f.studentid,data))==0)
       {  gotoxy(30,16);
	  printf("FINE                : %d",f.price);
	  goto out3 ;
       }
	fread(&f,sizeof(f),1,fp2);
      }
       gotoxy(30,16);
       printf("FINE                : 0");
      out3 :
      fclose(fp2);
      fp1=fopen("isbook.txt","rb");
      fread(&st1,sizeof(st1),1,fp1);
       while(!feof(fp1))
      {
	if((strcmp(st1.studentid,data))==0)
	{
	    if(count==0)
	 {
	   gotoxy(c,r);
	   printf("ALLOTED BOOKS       : %s",st1.bookid);
	 }
	 else
	 {
	   gotoxy(c,r);
	   printf("                    : %s",st1.bookid);
	 }
	 r=r+2;
	 count++;
	}
	fread(&st1,sizeof(st1),1,fp1);
      }
      fclose(fp1);
      gotoxy(45,25);
      goto out;
   }
    fread(&student,sizeof(student),1,fp);
  }
  fclose(fp);
  gotoxy(25,18);
  printf("YOU ENTERED WRONG STUDENT ID");
  gotoxy(35,20);
  out :
  gotoxy(45,23);
  getch();
  studentid1();
}
