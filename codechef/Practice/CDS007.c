#include<stdio.h>
#include<string.h>
typedef struct listnode{
  char code[16];
  char place[200];
  int codelen;
  int rate;
}list;
typedef struct callnode{
  char num[16];
  int time;
}call;
void solver()
{
  list nat[200],idd[200],temp;
  call calls[200],temp2;
  int natlen=0,iddlen=0,callsz=0,i,j,len,k,found;
  char subscriber[8],*p1,*p2,rest[100];
  float rt,charge;
  while(1)
    {j=0;
      scanf("%s",temp.code);
      if(strcmp(temp.code,"000000")==0)
	break;
      temp.codelen=strlen(temp.code);
      scanf("%s",temp.place);
      p1=temp.place;
      while(*p1!='$')
	p1++;
      p2=p1+1;
      *p1='\0';
      temp.rate=atoi(p2);
	if(temp.code[1]=='0')
	  idd[iddlen++]=temp;
	else
	  nat[natlen++]=temp;
    }
    while(1)
    {
        scanf("%s",temp2.num);
	if(strcmp(temp2.num,"#")==0)
	  break;
        scanf("%d",&temp2.time);
	calls[callsz++]=temp2;
    }
    
    /*   printf("National Directory\nCode:\tPlace:\tCodelen:\tRate:\n");
   for(i=0;i<natlen;i++)
     printf("%s  %s          %d        %d \n",nat[i].code,nat[i].place,nat[i].codelen,nat[i].rate);
   printf("International\n");
   for(i=0;i<iddlen;i++)
     printf("%s  %s          %d        %d \n",idd[i].code,idd[i].place,idd[i].codelen,idd[i].rate);
    printf("Calls List:\n");
   for(i=0;i<callsz;i++)
     printf("%s  %d\n",calls[i].num,calls[i].time);
    */
   for(i=0;i<callsz;i++)
      {j=0;k=0;found=0;
	if(calls[i].num[0]!='0')
	  {
	    found=1;
	  printf("%s Local %s %d 0.00 0.00\n",calls[i].num,calls[i].num,calls[i].time);
	  }
	else if(calls[i].num[1]=='0')
	  {
	    while(j<iddlen)
	      {
		if( strncmp(calls[i].num,idd[j].code,idd[j].codelen)==0)
		  {
		    found=1;
		    rt=(float)idd[j].rate/100;
		     charge=rt*calls[i].time;
		       p1=calls[i].num;
		       printf("%s %s %s %d %.2f %.2f\n",calls[i].num,idd[j].place,p1+idd[j].codelen,calls[i].time,rt,charge );
		    break;
		  }
		j++;
	      }
	  }
	else if(calls[i].num[0]=='0')
	  {j=0;
	    while(j<natlen)
	      {
		if( strncmp(calls[i].num,nat[j].code,nat[j].codelen)==0)
		  {
		    found=1;
		    rt=(float)nat[j].rate/100;
	            charge=rt*calls[i].time;
         	    p1=calls[i].num;
		    printf("%s %s %s %d %.2f %.2f\n",calls[i].num,nat[j].place,p1+nat[j].codelen,calls[i].time,rt,charge );
		    break;
		  }
		j++;
	      }
	  }
	if(found==0)
	  printf("%s Unknown %d -1.00\n",calls[i].num,calls[i].time);
      }
    
}
int main()
{
 solver();
return 0;
}

