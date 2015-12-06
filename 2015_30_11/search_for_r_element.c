#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *next;
};

struct tables_of_n1_and_n2
{
	int n1,n2,r;
}list[]={
			{3,5,5},
			{1,2,5},
			{-3,-6,8},
			{-2,6,8},
			{0,5,7},
			{0,4,6}
		};

void create(struct node **start,int key);
void search_for_r_element(struct node *head1,struct node *head2,int r);
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
		int n1=list[index].n1;//intialize the value of n1
		int n2=list[index].n2;//intialize the value of n2
		int r=list[index].r;//intialize the value of r
		struct node *head1,*head2;
		head1=head2=NULL;
		int *arr1,*arr2;
		arr1=(int *)calloc(r,sizeof(int));//create arrays to store the tables
		arr2=(int *)calloc(r,sizeof(int));
		arr1[0]=n1;
		arr2[0]=n2;
		for(int i=1;i<r;i++)//store the multiples of n1
		{
			arr1[i]=arr1[i-1]+n1;
		}
		for(int i=1;i<r;i++)//store the multiples of n2
		{
			arr2[i]=arr2[i-1]+n2;
		}
		for(int i=0;i<r;i++)//create a linked list for n1
			create(&head1,arr1[i]); 
		for(int i=0;i<r;i++)//create a linked list for n2
			create(&head2,arr2[i]);
		search_for_r_element(head1,head2,r);//search for r element from the n1 and n2  multiples linked lists

 		free(arr1);//free the allocated memory
		free(arr2);
		free(head1);
		free(head2);
	}
}

void create(struct node **start,int key)
{
	struct node** current = start;
 
    while (*current != NULL)
    {
        current = &((*current)->next);/* traverse the list */
    }
 
    struct node* temp = (struct node*)malloc(sizeof(struct node));/* make new node and re-link */
    temp->num = key;
    temp->next = *current;
    *current = temp;
}

void search_for_r_element(struct node *head1,struct node *head2,int r)
{
	struct node *temp1,*temp2;
	int i=1;
	for(temp1=head1,temp2=head2;i<=r;i++)//end when we hit the rth element 
	{
		if(temp1->num >temp2->num)//if the number of the second linked list is less than that of the first linked list
		{
			if(i==r)//if we reach the r th element
				printf("%d\n",temp2->num);//display the value of temp2
			temp2=temp2->next;//update the value of second linked list
		}
		else if(temp1->num < temp2->num)//if the number of the first linked list is less than that of the second linked list 
		{
			if(i==r)//if we reach the r th element
				printf("%d\n",temp1->num);//display the value of temp1
			temp1=temp1->next;//update the value of first linked list
		}
		else// if it is equal
		{
			if(i==r)//if we reach the r th element
				printf("%d\n",temp1->num);//display the either of temp1 or temp2
			temp1=temp1->next;//update the value of first linked list
			temp2=temp2->next;//update the value of second linked list
		}
	}
}
