/* Deletion from beginning single linklist */
# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
struct node
   {
           int info;
           struct node *link;
     };
struct node *first;
int main (void)

   {
	 void create ();
	 void traverse ();
	 void delete_beginning ( );
	 //clrscr ();
	 create ( );
	 traverse( );
	 delete_beginning ( );
	  printf ("\n After deletion first node");
	 traverse( );
      getch ( );
    }

void create ( )
  {
  struct node * ptr, *cpt;
  char ch;
  ptr = (struct node*) malloc (sizeof (struct node));
  printf ("Input first node information");
  scanf ("%d", &ptr->info);
  first=ptr;
  do
    {
      cpt=(struct node*) malloc(sizeof(struct node));
      printf("Input next node information");
      scanf("%d",&cpt->info);
      ptr->link = cpt;
      ptr = cpt;
   printf ("Press <Y/N> for more node");
     ch = getch ( );
    }
while (ch=='Y');
ptr -> link = NULL;
}

void traverse ( )
{
struct node *ptr;
printf ("\n Traversing of link list:\n");
ptr = first;
while( ptr != NULL)
{
printf ("%d\n", ptr ->info);
ptr = ptr -> link;
}
}

void delete_beginning ( )
{
struct node *ptr;
if (first == NULL)
{
printf ("underflow\n");
return;
}
ptr = first;
first = ptr ->link;
free (ptr);
}