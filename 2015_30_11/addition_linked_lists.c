#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *next;
};

struct lists_to_be_added
{
	int arr1[10],arr2[10],len1,len2;
}list[]={
			{{1,2,3,4,5},{6,7,8,9,10},5,5},
			{{1,1,1},{2,2,2},3,3},
			{{2,4,6,8,10},{1,3,5,7,9},5,5},
			{{-5,-2,0,4,9},{-6,-4,-3,1,8},5,5},
			{{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},5,5},
			{{1,4,6},{3,4,7,10,12},3,5},
			{{},{},0,0}
		};

void create(struct node **start,int key);
void display(struct node *head);
void addition(struct node *head1,struct node *head2,struct node **start);
void testCases();

int main(void)
{
	testCases();
}

void testCases()
{
	int index;
	int noOfElements = sizeof(list) / sizeof(list[0]); // calculate the no of testcases
	for(index=0;index < noOfElements;index++)
	{
		struct node *head1,*head2,*head3;
		head1=head2=head3=NULL;
		for(int i=0;i<list[index].len1;i++) //for each testcase array create a linked list
		{
			create(&head1,list[index].arr1[i]);
		}
		for(int i=0;i<list[index].len2;i++)
		{
			create(&head2,list[index].arr2[i]);
		}
		addition(head1,head2,&head3);//add the values of the linked lists and store them in an linked list
		printf("TestCase: %d\n",index);
		display(head3);
		printf("\n");
	}
}

void create(struct node **start,int key)
{
	struct node** current = start;
 
    while (*current != NULL)
    {
        current = &((*current)->next); //traverse the list 
    }
    struct node* temp = (struct node*)malloc(sizeof(struct node)); //make new node and re-link
    temp->num = key;
    temp->next = *current;
   	*current = temp; 	
}


void display(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)//check if the list is empty 
		printf("Empty list");
	else // else display the contents of the list
	{
		while(temp!=NULL)
		{
			printf("%d\t",temp->num);
			temp=temp->next;
		}
	}
}

void addition(struct node *head1,struct node *head2,struct node **start)
{
	struct node *temp1,*temp2;
	for(temp1=head1,temp2=head2;temp1!=NULL && temp2!=NULL;)// continue in the loop until either of the given lists end
	{
		struct node **current = start;
		while (*current != NULL)//traverse the third linked list to the last node
    	{
       		current = &((*current)->next);
    	}
    	struct node* temp = (struct node*)malloc(sizeof(struct node));//create a new node
    	temp->num = (temp1->num) + (temp2->num); // add the corresponding values of the nodes in linked lists and store them in an node
    	temp->next = *current;
    	*current = temp;
    	temp2=temp2->next;//update the linked lists to next nodes
    	temp1=temp1->next;
    }
    if(temp1!=NULL)//if either one of the linked list didnt teminate 
    {
    	struct node **current = start;
		while(temp1!=NULL)//copy its contents directly into the resultant linked list 
		{
			while (*current != NULL)
       			current = &((*current)->next);
       		struct node* temp = (struct node*)malloc(sizeof(struct node));
    		temp->num = temp1->num;
    		temp->next = *current;
    		*current = temp;
       		temp1=temp1->next;

    	}
    }
    if(temp2!=NULL)
	{
		struct node **current = start;
		while(temp2!=NULL)
		{
			while (*current != NULL)
       			current = &((*current)->next);
       		struct node* temp = (struct node*)malloc(sizeof(struct node));
    		temp->num = temp2->num;
    		temp->next = *current;
    		*current = temp;
       		temp2=temp2->next;

    	}
	}	
}



