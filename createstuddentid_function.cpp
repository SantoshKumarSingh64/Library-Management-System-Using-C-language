void createstudentid1()
{
   char ch,data[15];
   int choice;
   FILE *fp;
   color();
   setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(30,30,"CREATE STUDENT ID PAGE");
   gotoxy(22,8);
   printf("ENTER STUDENT ID              : ");
   fflush(stdin);
   scanf("%s",data);
   fp=fopen("student.txt","ab");
   if(fp==NULL)
   {
    printf("Can't open student file!!!");
    getch();
    exit(0);
   }
   fclose(fp);
   fp=fopen("student.txt","rb");
   if(fp==NULL)
   {
    printf("Can't open student file!!!");
    getch();
    exit(0);
   }
   fread(&student,sizeof(student),1,fp);
   while(!feof(fp))
   {
     if((strcmp(data,student.id))==0)
     {
      gotoxy(27,12);
      printf("THIS STUDENT ID HAS BEEN ALREADY ADDED");
      gotoxy(35,14);
      printf("SELECT CHOICE");
      gotoxy(35,16);
      printf("1) CREATE ID");
      gotoxy(35,18);
      printf("2) BACK MENU ");
      gotoxy(40,20);
      scanf("%d",&choice);
      if(choice==1)
	   createstudentid1();
      else
	   studentid1();
     }
      fread(&student,sizeof(student),1,fp);
   }
   fclose(fp);
   strcpy(student.id,data);
   gotoxy(22,10);
   printf("ENTER STUDENT ID PASSWORD     : ");
   fflush(stdin);
   scanf("%s",&student.pass);
   gotoxy(22,12);
   printf("ENTER STUDENT NAME            : ");
   fflush(stdin);
   scanf("%[^\n]s",&student.name);
   gotoxy(22,14);
   printf("ENTER STUDENT'S BRANCH        : ");
   fflush(stdin);
   scanf("%[^\n]s",&student.branch);
   gotoxy(22,17);
   printf("PRESS C FOR CREATE STUDENT ID : ");
   fflush(stdin);
   scanf("%s",&ch);
   if(ch=='c'||ch=='C')
   {
	fp=fopen("student.txt","ab");
	if(fp==NULL)
       {
	 printf("Can't open student file!!!");
	 getch();
	 exit(0);
       }
       fwrite(&student,sizeof(student),1,fp);
       fclose(fp);
	gotoxy(45,20);
	printf("CREATED");
	gotoxy(48,22);
	getch();
	studentid1();
   }
   else
   {
	gotoxy(45,20);
	printf("NOT CREATED");
	gotoxy(48,22);
	getch();
	studentid1();
   }
}
