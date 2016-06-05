
void freef(char *p)
{
  printf("freef called with p=%p\n", (void *) p);
if(p!=0){
   /* you write the  code for the freef function here */
  struct blockl *temp = (struct blockl *)p;
  temp->tag = FREETAG;
  char *temp2 = p;
  temp2 += temp->size;
  temp2 += (TAGSIZE*2);
  struct blockr *temp3 = (struct blockr *)temp2;
  temp3->tag = FREETAG;
  struct blockr *temp4 = (struct blockr *)(p - TAGSIZE);
  //temp4 -= 1;
  if (temp4->tag == FREETAG) {
	struct blockl *temp5 = (struct blockl *)(temp4 - temp4->size-(TAGSIZE));
	coalesce(temp5, temp);	
  }
  else{
	enchain(temp);
  }
  temp2 += TAGSIZE;
  struct blockl *temp6 = (struct blockl *)temp2;
  if (temp6->tag == FREETAG){
	unchain(temp6);
	coalesce(temp, temp6);
  }
}
}



void freef(void *f)  
{  
   struct blockl *q;  
   struct blockr *r;  
   struct blockl *s;  
  
   char *p = (char *)f;  
   printf("freef called with p=%p\n", p);  
  
   if (p < allocbuf || p > allocbuf + ALLOCSIZE) {  
      printf("freef: bad pointer to block to be freed, %p\n", (void *) p);  
      return;  
   }  
   p = p - TAGSIZE;             /* undo offset added by alloc()  */  
   q = (struct blockl *) p; /* make pointer to struct blockl */  
   if (q->tag != USEDTAG) {  
      printf("freef: block being freed is not in use, %p\n", (void *) p);  
      return;  
   }  
   r = (struct blockr *) (p + q->size - TAGSIZE); /* point to blockr */  
   if (r->tag != USEDTAG) {  
      printf("freef: block being freed is not in use, %p\n", (void *) p);  
      return;  
   }  
   q->tag = (r->tag = FREETAG);  /* set tags to show it is free         */  
   r->size = q->size;          /* set size in blockr                  */  
                 /* look for opportunity to coalesce    */  
                 /* with next lower block               */  
   r = (struct blockr *) (p - TAGSIZE);  
   if ((char *) r >= allocbuf && r->tag == FREETAG) {  
      s =  (struct blockl *) (p - r->size);  
      p = p - r->size;  
      coalesce(s,q);  
      q = s;  
   } else  
   enchain(q);           /* return to the free list             */  
                 /* look for opportunity to coalesce    */  
                 /* with next higher block              */  
   s = (struct blockl *) (p + q->size);  
   if ((char *) s < allocbuf + ALLOCSIZE && s->tag == FREETAG) {  
      unchain(s);  
      coalesce(q,s);  
   }  
} 

