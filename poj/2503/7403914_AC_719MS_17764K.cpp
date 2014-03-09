#include<iostream>
#include<stdlib.h>
using namespace std  ;
const int maxs = 27 ;
const int maxlen = 15;
const int maxn =100;

struct node{
       char word[maxlen];
       node* next[maxs]; 
       node(){  memset(next,0,sizeof(next));}
};

typedef node* Node;
Node T;
char eh[]="eh";

void ins(char *s,char *dic)
{     
     Node p = T;
     for( int i=0 ; i<strlen(s) ; i ++ )
     {   
         int pos = s[i] - 'a';
         if(p ->next[pos] == NULL) 
         {  
              p ->next[pos] = new node();
         }
         p = p->next[pos];
     }
     strcpy(p->word,dic);
}

char* find(char *s)
{     
      Node p = T;
      for(int i=0 ; i<strlen(s); ++i)
      {    
           int pos = s[i] - 'a';
           if(p==NULL) return eh;
           p = p ->next[pos];
      }
      return p->word;
}
           
           
void clear(Node Trie){
     if(Trie==NULL) return ;
     for(int i = 0;i<maxs; ++i)
       clear(Trie->next[i]);
     delete Trie;
}
     
void can()
{    
     char info[100],s[maxn],dic[maxn];
     int i,j,k;
     while(strcmp(gets(info),"")!=0)
     {  
         sscanf(info,"%s %s",s,dic);    
         ins(dic,s);  
     }
     while(gets(info)!=NULL)
     {  
        //if(!strcmp(info,"end")) break;
        printf("%s\n",find(info));
     }
}

int main(){
     T = new node();
     can();
     clear(T);
     return 0;
}
  
    
