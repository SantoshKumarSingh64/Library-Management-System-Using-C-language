void studentpage()
{
   char user[20],mch;
   char pass[20];
   int ind;
   FILE *fp;
   color();
   setcolor(BLUE);
   settextstyle(7,0,5);
   outtextxy(180,30,"STUDENT PAGE");
   gotoxy(30,12);
   printf("USERNAME : ");
   fflush(stdin);
   scanf("%s",&user);
   gotoxy(30,14);
   printf("PASSWARD : ");
   fflush(stdin);
   mch=getch();
   while(mch!=13)
   {
	  pass[ind++]=mch;
	  printf("*");
	  mch=getch();
   }
   pass[ind]=0;
  //scanf("%s",&pass);
   fp=fopen("student.txt","rb");
   fread(&student,sizeof(student),1,fp);
   while(!feof(fp))
   {
     if(((strcmp(user,student.id))==0)&&((strcmp(pass,student.pass))==0))
     {
       strcpy(myuser,user);
       studentmenu();
     }
     fread(&student,sizeof(student),1,fp);
   }
   gotoxy(25,18);
   printf("YOU ENTERED WRONG USER ID OR PASSWARD");
   getch();
   secondpage();
}
