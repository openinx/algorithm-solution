#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok,
// chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau
char haab[19][10]={ "pop", "no", "zip", "zotz","tzec", "xul",
                  "yoxkin", "mol","chen", "yax", "zac", "ceh", 
                  "mac","kankin", "muan", "pax", "koyab", "cumhu",
                  "uayet"
                 };
char tzolki[20][10]={"ahau","imix", "ik", "akbal", "kan", "chicchan",
                  "cimi", "manik", "lamat", "muluk", 
                  "ok", "chuen", "eb", "ben", 
                  "ix", "mem", "cib", "caban", 
                  "eznab","canac"
                     };               
typedef struct {
 long day,month,year;
}HNode;
long  Haab_to_days(HNode H)
{  long day;
   day=365*H.year;
   day+=H.month*20+H.day+1;
  // printf("day:%ld\n",day);
   return day;
}   
void days_to_Tzolkin(long day)
{ long number,name,year;
  year=day/260;
  name=day%20;
  number=day%13;
  if(!number) number=13;
  printf("%ld %s %ld\n",number,tzolki[name],year);
}
int main()
{  long i,j,size,day;
   char m[25];
   HNode e;
   while(scanf("%ld",&size)!=EOF)
   { 
     for(i=1;i<=size;i++)
     {  scanf("%ld",&e.day);
        getchar();
        scanf("%s",m);
        for(j=0;j<19;j++)
        if(!strcmp(m,haab[j])) { e.month=j;break;}
        scanf("%ld",&e.year);
        day=Haab_to_days(e);
        printf("%ld\n",size);
        days_to_Tzolkin(day);
     }
   }     
   //system("pause");
   return 0;
}   
   

