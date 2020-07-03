/* Aim: Write A Program for Polynomial Addition.
   Author: Pratik.A.Bhudke
   Std.: S.E   Div.: COMPUTER   Roll No.:
   Date: 
*/
/******************* Assingment No. 1 *******************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *next;
}*head1,*head2,*var,*var2,*trav,*temp,*temp1,*temp2;
struct node *insert_at_end1(int val1,int val2,struct node *head)
{
      temp=head;
      var=(struct node *)malloc(sizeof (struct node));
      var->coef=val1;
      var->exp=val2;
      if(head==NULL){ head=var; head->next=NULL; }
      else
      {
          while(temp->next!=NULL)
          temp=temp->next;
          var->next=NULL;
          temp->next=var;
      }
      return head;
}
void append()
{
     temp1=head1;
     while(temp1->next!=NULL)
     temp1=temp1->next;
     temp1->next=head2;
}
void display(struct node *head)
{
     var2=head;
     while(var2!=NULL)
     {
                      if(var2->exp==0) { printf("+ %d ",var2->coef,var2->exp); }
                      else if(var2->exp==1) { printf("+ %dx ",var2->coef,var2->exp); }
                      else { printf("+ %dx^%d ",var2->coef,var2->exp); }
                      var2=var2->next;
     }
}
int delete(int val1,int val2)
{
    temp2=head1;
    while(temp2->next->coef!=val1 || temp2->next->exp!=val2)
    temp2=temp2->next;
    var2=temp2->next;
    temp2->next=var2->next;
    var2->next=NULL;
    free(var2);
    return 0;
}
int add()
{
    temp1=head1;
    temp2=temp1->next;
    while(temp1!=NULL)
    {
                      while(temp2!=NULL)
                      {
                                        if(temp1->exp==temp2->exp)
                                        {
                                                                  temp1->coef+=temp2->coef;
                                                                  delete(temp2->coef,temp2->exp);
                                        }
                                        temp2=temp2->next;
                      }
                      if(temp1->next==NULL)
                      break;
                      temp1=temp1->next;
                      temp2=temp1->next;
    }    
}
void traverse()
{
    int c,e;
    temp=head1;
    while(temp->next!=NULL)
    {
                           trav=temp->next;
                           while(trav!=NULL)
                           {
                                            if(trav->exp > temp->exp)
                                            {
                                                          c=temp->coef;
                                                          temp->coef=trav->coef;
                                                          trav->coef=c;
                                                          e=temp->exp;
                                                          temp->exp=trav->exp;
                                                          trav->exp=e;
                                            }
                                            trav=trav->next;
                           }
                           temp=temp->next;
    }
}
int main()
{
    int c,e,ch;
    printf("********  Polynomial Addition  ********");
    printf("\n\n\n* Designed By:- Pratik A. Bhudke\n\n");
L:  printf("\nEQUATION 1:");
    while(1)
    {
            printf("\nCoefficient=");
            scanf("%d",&c);
            printf("Exponential=");
            scanf("%d",&e);
            head1=insert_at_end1(c,e,head1);
            printf("\nEQUATION 1: ");
            display(head1);
            printf("\n\nPress 1 to add more elements to Equation 1.\nPress 2 to enter Equation 2.\nEnter your Choice:");
            scanf("%d",&ch);
            if(ch==2)
            break;
    }
    printf("\n\nEQUATION 2:");
    while(1)
    {
            printf("\nCoefficient=");
            scanf("%d",&c);
            printf("Exponential=");
            scanf("%d",&e);
            head2=insert_at_end1(c,e,head2);
            printf("\nEQUATION 2: ");
            display(head2);
            printf("\n\nPress 1 to add more elements to Equation 2.\nPress 2 to Add the Equations.\nEnter your Choice:");
            scanf("%d",&ch);
            if(ch==2)
            break;
    }
    printf("\n\n\nEquation 1: ");
    display(head1);
    printf("\nEquation 2: ");
    display(head2);
    printf("\nAddition  : ");
    append();
    add();
    traverse();
    display(head1);
    printf("\n\nPress 1 to repeat OR any other number to exit:");
    scanf("%d",&ch);
    if(ch==1)
    {
             head1=NULL;
             head2=NULL;
             goto L;
    }
    return 0;
}
