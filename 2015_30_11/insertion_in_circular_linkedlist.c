#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *next;
}*head;

struct circular_linked_list
{
	int arr[10],position,key,len;
}list[]={
			{{1,3,5,7,9},1,0,5},
			{{1,3,5,7,9},2,2,5},
			{{1,3,5,7,9},3,4,5},
			{{1,3,5,7,9},5,10,5},
			{{1,3,5,7,9},6,11,5}
		};

void create(int key);
void display(struct node *head);
void insert(int pos,int key);
void testCases();

int main()
{
	testCases();
}



void testCases()
{
	int index;
	int noOfElements = sizeof(list) / sizeof(list[0]); // calculate the no of testcases
	for(index=0;index < noOfElements;index++)
	{
		head=NULL;
		for(int i=0;i<list[index].len;i++) //for each testcase array create a linked list
		{
			create(list[index].arr[i]);
		}
		printf("TestCase: %d\n",index);
		insert(list[index].position,list[index].key);//pass parameters, the position where the element should be inserted and value to be inserted
		display(head);// display after the insertion
		printf("\n");
	}
}	

void create(int key)
{
	struct node *temp;
	if(head==NULL)//check if the list is empty 
	{
		head=(struct node *)malloc(sizeof(struct node));//create the node and link it to itself
    	head->next=head;
   		head->num=key;
    	temp=head;
    }
    else
    {
    	temp->next=(struct node *)malloc(sizeof(struct node));//create a new node
    	temp=temp->next;
    	temp->next=head;//intialize its link to the head
    	temp->num=key;
    }
}	

void insert(int pos,int key)
{
	struct node *current,*temp;
	current=head;
	if(pos==1)//if position is front of the list
	{
		if(current==NULL)//check if it is null
		{
			temp=(struct node *)malloc(sizeof(struct node));//if it is then create a node and return it
			temp->num=key;
			temp->next=temp;
			head=temp;
		}
		else
		{
			while(current->next!=head)//traverse the list
				current=current->next;
			temp=(struct node *)malloc(sizeof(struct node));// create a new noe
			temp->num=key;
			temp->next=head;//intialise its link to the head
			head=temp;//make it is a head
			current->next=head;//intialise the link of the last node to the head
		}
	}
	else
	{
		int total=1;
		while(current->next!=head)//calculate total no of elements in the list
		{
			current=current->next;
			total++;
		}
		if(pos>total)// if the given position is greater than the no of elements in the list then print following message
			printf("Position limit exceeds the number of the elements : INSERTION INVALID\n");
		else if(pos<total)// else pos is less than no of elements insert a new node in between
		{
			struct node *temp,*prev;
			current=head;
			int i=0;
			while(i<pos-1)//traverse until you the position 
			{
				prev=current;
				current=current->next; 
				i++;
			}
			temp=(struct node *)malloc(sizeof(struct node));//create the new node
			temp->num=key;
			prev->next=temp; 
			temp->next=current;
		}
		else//if the total no of elements in the list is equal to position then it should be inserted in the end of the list
		{
			if(head==NULL)// it is null then create a new node
			{
				temp=(struct node *)malloc(sizeof(struct node));
				temp->num=key;
				temp->next=temp;
				head=temp;
			}
			else// create a node attatch it in the last
			{
				temp=(struct node *)malloc(sizeof(struct node));
				temp->num=key;
				current->next=temp;
				temp->next=head;
			}
		}
	}
}

void display(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)//check if the list is empty 
		printf("Empty list");
	else   // else display the contents of the list
	{
		while(temp->next!=head)
		{
			printf("%d\t",temp->num);
			temp=temp->next;
		}
		printf("%d\t",temp->num);
		temp=temp->next;
		printf("%d",temp->num);
	}
}
