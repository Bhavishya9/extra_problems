#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *next;
};

struct lists_to_be_merged
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
void merge_sorted_lists(struct node *head1,struct node *head2,struct node **starts);
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
		merge_sorted_lists(head1,head2,&head3);//merge the sorted linked lists
		printf("TestCase: %d\n",index);
		display(head3);//display the linked lists
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

void merge_sorted_lists(struct node *head1,struct node *head2,struct node **start)
{
	struct node *temp1,*temp2;
	for(temp1=head1,temp2=head2;temp1!=NULL && temp2!=NULL;)//continue in the loop until either of the given lists end
	{
		struct node **current = start;
		while (*current != NULL)//traverse the third linked list to the last node
    	{
       		current = &((*current)->next);
    	}
		if(temp1->num >temp2->num)//if the number of the second linked list is less than that of the first linked list   
		{
			struct node* temp = (struct node*)malloc(sizeof(struct node));
    		temp->num = temp2->num;//then copy contents of the second linked list to the new node in the third linked list
    		temp->next = *current;//assign its link
    		*current = temp;//add it to the list
    		temp2=temp2->next;//update the node of the second linked list
		}
		else if(temp1->num < temp2->num)//if the number of the first linked list is less than that of the second linked list 
		{
			struct node* temp = (struct node*)malloc(sizeof(struct node));
    		temp->num = temp1->num;;//then copy contents of the first linked list to the new node in the third linked list
    		temp->next = *current;//assign its link
    		*current = temp;//add it to the list
       		temp1=temp1->next;//update the node of the first linked list
		}
		else// if it is equal
		{
			struct node* temp = (struct node*)malloc(sizeof(struct node));
    		temp->num = temp1->num;//copy the contents of the either of the lists
    		temp->next = *current;//assign its link
    		*current = temp;// add it to list
    		temp1=temp1->next;//update the node of the first linked list
    		temp2=temp2->next;//update the node of the second linked list

		}
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

void display(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
		printf("Empty list");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t",temp->num);
			temp=temp->next;
		}
	}
}

