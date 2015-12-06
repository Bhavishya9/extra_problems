#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *next;
};

struct listOfNumbers
{
	int arr[10],len;
}list[]={
			{{1,2,3,4,5,6},6},
			{{1},1},
			{{1,2,3,4,5},5},
			{{-5,-2,0,4,9},5},
			{{-1,-1,-1,-1,-1,-1},6},
			{{-10,-6,-5,-4,-3,-2,-1,0},8},
			{{},0}
		};

void create(struct node **start,int key);
void display(struct node *head);
float median(struct node *head);
void testCases();

int main()
{
	testCases();
}

void testCases()
{
	int index;
	int check=0;
	int noOfElements = sizeof(list) / sizeof(list[0]); // calculate the no of testcases
	for(index=0;index < noOfElements;index++)
	{
		struct node *head;
		head=NULL;
		for(int i=0;i<list[index].len;i++) //for each testcase array create a linked list
		{
			create(&head,list[index].arr[i]);
		}
		printf("TestCase: %d\n",index);
		float med=median(head); // for every testcase calculate the median of the corresponding linked list
		printf("\tMedian:=%.2f\n",med);// display the median 
		free(head);// free the space allocated for that lined list
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

float median(struct node *head)
{
	struct node *temp;
	temp=head;
	int pos,flag=0;
	float med;
	if(temp==NULL)//check if the list is empty
	{
		printf("The list is empty\n");
		return NULL;
	}
	else
	{
		int count=0;
		while(temp!=NULL)//count the no of elements in the list
		{
			count++;
			temp=temp->next;
		}
		if(count%2!=0)//check if the no of elements in the list are odd or even.
		{
			pos=(count+1)/2;// if no of elements in the list are odd then store the position of  mid element
		}
		else
		{
			pos=(count+1)/2;// if no of elements in the list are even then store the position of  mid element and
			flag=1;//set flag to 1 to know that no of elements are even.
		}
		temp=head;
		int index=1;
		while(index<pos)//traverse the list
		{
			temp=temp->next;
			index++;
		}
		med=temp->num; // store the value of mid element in median
		if(flag==0) // if no of elements is odd then return the value of median
			return med;
		else //if no of elements is even the take of average of the two mid elements 
		{
			temp=temp->next;
			med=(med+temp->num)/2;
			return med; // return the mid element
		}
	}
}
