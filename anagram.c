#include <stdio.h>
#include <stdlib.h>
#include "anagram.h"

void toLower1(char *word){
  int i;
  for(i=0; word[i]; i++)
  if (word[i]>=65 && word[i]<=90)
     {
    word[i] += 32;
  }
}

int cmpfunc1(const void *a, const void *b) {
    if((*(char*)a) == (*(char*)b)){
        return 0;
    }else if((*(char*)a) < (*(char*)b)){
        return -1;
    }else{
        return 1;
    }
}


struct StringList *MallocSList(char *word){
  struct StringList * node;
  node = malloc(sizeof(struct StringList));
  node->Word = word;
  node->Next = NULL;
  return node;
}

void AppendSList(struct StringList **head, struct StringList *node){
  struct StringList *last = *head;
  while (last->Next != NULL)
    last = last->Next;
  last->Next = node;
}

void FreeSList(struct StringList **node){
  struct StringList* tmp;
  struct StringList *nnode = *node;
  while (nnode != NULL)
  {
     tmp = nnode;
     nnode= nnode->Next;
     free(tmp);
  }
}

void PrintSList(FILE *file,struct StringList *node){
  //qsort(node, sizeof(*node), sizeof(*node), cmpfunc1);
  while (node != NULL)
  {
     fprintf(file,"\t%s\n", node->Word);
     node = node->Next;
  }
}

int SListCount(struct StringList *node){
  struct StringList *counter = node;
  int c = 0;
  while(counter != NULL)
  {
    c++;
    counter = counter->Next;
  }
  return c;
}


struct AnagramList* MallocAList(char *word){
  struct AnagramList * node;
  node = malloc(sizeof(struct AnagramList));
  char * wordsorted=malloc(sizeof(word));
  strcpy(wordsorted,word);
  qsort(wordsorted, strlen(wordsorted), sizeof(*wordsorted), cmpfunc1);
  toLower1(wordsorted);
  node->Anagram =  wordsorted;
  node->Words = MallocSList(word);
  node->Next = NULL;
  return node;
}

void FreeAList(struct AnagramList **node){
	struct AnagramList* tmp;
  struct AnagramList *nnode = *node;
  while (nnode != NULL)
  {
     tmp = nnode;
     FreeSList(&tmp->Words);
     nnode= nnode->Next;
     free(tmp->Anagram);
     free(tmp);
  }
  
}

void PrintAList(FILE *file,struct AnagramList *node){
	//struct AnagramList* tmp = node;
	while (node != NULL)
  {
    if(SListCount(node->Words)>=2){
     fprintf(file,"%s: %d\n", node->Anagram, SListCount(node->Words));
		 PrintSList(file, node->Words);
    }
     node = node->Next;
  }
}

void AddWordAList(struct AnagramList **node, char *word){
  if(*node!=NULL){
    struct AnagramList *last=*node;
    struct AnagramList *new = MallocAList(word);
    while(last->Next!=NULL){
      last = last->Next;
    }
    last->Next = new;
  }
}
