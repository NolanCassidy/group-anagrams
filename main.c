#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anagram.h"


void toLower(char *word){
  int i;
  for(i=0; word[i]; i++)
  if (word[i]>=65 && word[i]<=90)
     {
    word[i] += 32;
  }
}

int cmpfunc(const void *a, const void *b) {
    if((*(char*)a) == (*(char*)b)){
        return 0;
    }else if((*(char*)a) < (*(char*)b)){
        return -1;
    }else{
        return 1;
    }
}

int is_anagram(char *word1, char *word2) {
    char * w1=malloc(sizeof(word1));
    strcpy(w1,word1);
    char * w2=malloc(sizeof(word2));
    strcpy(w2,word2);
    toLower(w2);
    qsort(w1, strlen(word1), sizeof(*word1), cmpfunc);
    qsort(w2, strlen(word2), sizeof(*word2), cmpfunc);
    toLower(w1);
    toLower(w2);
    if (strcmp(w1, w2) == 0) {
        free(w1);
        free(w2);
        return 1;
    }
    free(w1);
    free(w2);
    return 0;
}

int main(int argc, char *argv[])
{

  if((argc >3))
  {
    exit(0);
  }

  FILE *input=NULL,*output=NULL;

  input = fopen(argv[1],"r");
  if(argc >=2)
  {
    input = fopen(argv[1],"r");
  }else
  {
    input = stdin;
  }
  if(input == NULL)
  {
    exit(0);
  }

  if(argc==3)
  {
    output = fopen(argv[2],"w");
  }else
  {
    output=stdout;
  }

  char buffer[1024];
  char tmp[1024];
  int first = 0;
  struct AnagramList *head=NULL;
  struct StringList * ts;
  char * wordb;
  while(fgets(buffer, sizeof buffer, input)!=NULL)
  {

    int i, j;
    int n = strlen(buffer);
    if (n > 0 && buffer[n-1] == '\n') {
        buffer[n-1] = '\0';
      }
      wordb=malloc(sizeof(buffer));
      strcpy(wordb,buffer);
    if(first==0){
          first=1;
          head = MallocAList(wordb);
    }else{
      struct AnagramList * temp = head;
      int found = 0;
      while(temp!=NULL){
        if(is_anagram(temp->Anagram, wordb)!=0){
          found = 1;
          ts =MallocSList(wordb);
          AppendSList(&temp->Words,ts);

        }
        temp = temp->Next;

      }
      if(found==0){
            AddWordAList(&head,wordb);
      }
    }

  }
  PrintAList(output,head);
  FreeAList(&head);
  //  PrintAList(output,head);
//PrintAList(output,head);




  fclose(output);
  fclose(input);
  return 0;

}
