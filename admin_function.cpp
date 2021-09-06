void admin()
{
  int i,d,ind=0;
  char user[20];
  char pass[20];
  char mch;
  char ch1;
      color();
      settextstyle(7,0,5);
      outtextxy(180,40,"ADMIN PAGE");
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
     // printf("%s\n",pass);
      //scanf("%s",&pass);
      for(i=0;i<3;i++)
      {
	  d=strcmp(user,adminusername[i]);
	  if(d==0)
	     break;
      }
       if(d==0)
	 d=strcmp(pass,adminpassward[i]);
       if(d==0)
	   adminmenu();
       else
      {
	   gotoxy(25,18);
	   printf("YOU ENTERED WRONG USER ID OR PASSWARD");
	   getch();
	   secondpage();
      }
}
