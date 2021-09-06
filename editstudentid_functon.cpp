void editstudentid()
{
   char b[20],mid[20];
   int value,ch;
   char ch1;
   FILE *fp,*fp1;
   color();
   setcolor(BLUE);
   settextstyle(7,0,4);
   outtextxy(60,30,"EDIT STUDENT DETAILS PAGE");
   fp=fopen("student.txt","rb");
   if(fp==NULL)
   {
	 gotoxy(30,10);
	 printf("FIRST ADD ANY STUDENT");
	 gotoxy(38,12);
	 getch();
	 adminmenu();
   }
   else
   {
   gotoxy(35,10);
   printf("STUDENT DETAILS UPDATE");
   gotoxy(30,14);
   printf("ENTER STUDENT ID : ");
   fflush(stdin);
   scanf("%s",b);

   fread(&student,sizeof(student),1,fp);
   while(!feof(fp))
   {
     if((strcmp(b,student.id))==0)
     {
	  color();
	  setcolor(BLUE);
   settextstyle(7,0,4);
   outtextxy(60,30,"EDIT STUDENT DETAILS PAGE");
	gotoxy(30,10);
	printf("STUDENT ID       : %s",student.id);
	gotoxy(30,12);
	printf("STUDENT PASSWORD : %s",student.pass);
	gotoxy(30,14);
	printf("STUDENT NAME     : %s",student.name);
	gotoxy(30,16);
	printf("STUDENT BRANCH   : %s",student.branch);
	gotoxy(30,22);
	fclose(fp);
	goto out;
     }
	fread(&student,sizeof(student),1,fp);
   }
   //fclose(fp);
    gotoxy(30,20);
    printf("YOU ENTERED WRONG STUDENT ID");
    gotoxy(30,22);
    printf("PRESS ANY KEY TO GO BACK");
    gotoxy(35,24);
    getch();
    studentid1();
    out :
     gotoxy(30,20);
     printf("PRESS 1 FOR EDIT STUDENT PASSWORD");
     gotoxy(30,21);
     printf("PRESS 2 FOR EDIT STUDENT NAME");
     gotoxy(30,22);
     printf("PRESS 3 FOR EDIT STUDENT BRANCH");
     gotoxy(30,23);
     printf("PRESS 4 FOR BACK MENU");
     gotoxy(40,25);
     scanf("%d",&ch);
     switch(ch)
     {
      case 1:
	     color();
	      setcolor(BLUE);
   settextstyle(7,0,4);
   outtextxy(60,30,"EDIT STUDENT DETAILS PAGE");
	     gotoxy(30,13);
	     printf("ENTER PASSWORD : ");
	     fflush(stdin);
	     scanf("%s",&mid);
	      gotoxy(30,16);
	      printf("PRESS Y TO UPDATE DETAILS : ");
	      fflush(stdin);
	      scanf("%s",&ch1);
	      if(ch1=='y'||ch1=='Y')
	     {
	     fp1=fopen("student1.txt","wb");
	     fp=fopen("student.txt","rb");
	     fread(&student,sizeof(student),1,fp);
	     while(!feof(fp))
	     {
	       if((strcmp(b,student.id))!=0)
		  fwrite(&student,sizeof(student),1,fp1);
	       if((strcmp(b,student.id))==0)
	       {
		 strcpy(student.pass,mid);
		 fwrite(&student,sizeof(student),1,fp1);
	       }
	       fread(&student,sizeof(student),1,fp);
	     }
	     fclose(fp);
	     fclose(fp1);
	     remove("student.txt");
	     rename("student1.txt","student.txt");
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
   settextstyle(7,0,4);
   outtextxy(60,30,"EDIT STUDENT DETAILS PAGE");
	     gotoxy(30,13);
	     printf("ENTER STUDENT NAME : ");
	     fflush(stdin);
	      scanf("%[^\n]s",&mid);
	     gotoxy(30,16);
	     printf("PRESS Y TO UPDATE DETAILS : ");
	     fflush(stdin);
	     scanf("%s",&ch1);
	     if(ch1=='y'||ch1=='Y')
	    {
	     fp1=fopen("student1.txt","wb");
	     fp=fopen("student.txt","rb");
	     fread(&student,sizeof(student),1,fp);
	     while(!feof(fp))
	     {
	       if((strcmp(b,student.id))!=0)
		  fwrite(&student,sizeof(student),1,fp1);
	       if((strcmp(b,student.id))==0)
	       {
		 strcpy(student.name,mid);
		 fwrite(&student,sizeof(student),1,fp1);
	       }
	       fread(&student,sizeof(student),1,fp);
	     }
	     fclose(fp);
	     fclose(fp1);
	     remove("student.txt");
	     rename("student1.txt","student.txt");
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
   settextstyle(7,0,4);
   outtextxy(60,30,"EDIT STUDENT DETAILS PAGE");
	     gotoxy(30,13);
	     printf("ENTER BRANCH : ");
	     fflush(stdin);
	     scanf("%[^\n]s",&mid);
	      gotoxy(30,16);
	      printf("PRESS Y TO UPDATE DETAILS : ");
	      fflush(stdin);
	      scanf("%s",&ch1);
	      if(ch1=='y'||ch1=='Y')
	     {
	     fp1=fopen("student1.txt","wb");
	     fp=fopen("student.txt","rb");
	     fread(&student,sizeof(student),1,fp);
	     while(!feof(fp))
	     {
	       if((strcmp(b,student.id))!=0)
		  fwrite(&student,sizeof(student),1,fp1);
	       if((strcmp(b,student.id))==0)
	       {
		 strcpy(student.branch,mid);
		 fwrite(&student,sizeof(student),1,fp1);
	       }
	       fread(&student,sizeof(student),1,fp);
	     }
	     fclose(fp);
	     fclose(fp1);
	     remove("student.txt");
	     rename("student1.txt","student.txt");
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
	     studentid1();
     default:
	      editstudentid();
    }
   getch();
   studentid1();
 }
}
