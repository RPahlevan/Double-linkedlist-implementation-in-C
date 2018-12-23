#include <stdio.h>
#include <stdlib.h>

/*double linked list creation*/
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

/*doubly linkedlist initialisation*/
node* left=NULL;
node* right=NULL;
node* root=NULL;

/*function prtotype*/
void Add_At_Begin(int );
void append(int );
int Length(void);
void display(void);
void addafter(int Input_Data,int location);

int main (int argc, char* argv[])
{
	
	Add_At_Begin(10);
	Add_At_Begin(11);
	append(12);
	printf("\nlength of the linked list = %d",Length());
	display();
	addafter(13,3);
	display();
	return 0;
}
void addafter(int Input_Data,int location)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=Input_Data;
	temp->right=NULL;
	temp->left=NULL;
	if (location>Length() && location!=1)
	{
		return;
	}
	node* p;
	p=root;
	if (location==1)
	{
		temp->right=root;
		root=temp;
	}else
	{
		int count=1;
		while(count<location-1)
		{
			p=p->right;
			count++;
		}
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
	}
}


/*add a node to the end of the the doubly linkedlist*/
void append(int Input_Data)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));

	temp->data=Input_Data;
	temp->left=NULL;
	temp->right=NULL;

	/*linkedlist is empty!*/
	if(root==NULL)
	{
		root=temp;
		return;
	}
	node* p;
	p=root;
	while(p->right!=NULL)
	{
		p=p->right;
	}
	p->right=temp;
	temp->left=p;
	

}

/*add a node at the begining of the doublylinkedlist */
void Add_At_Begin(int Input_Data)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=Input_Data;
	temp->left=NULL;
	temp->right=NULL;

	/*linkedlist is emty!*/
	if (root==NULL)
	{
		root=temp;
		return;
	}
	temp->right=root;
	root->left=temp;
	root=temp;
}

/*length of the doubly linkedlist*/
int Length(void)
{
	node* temp;
	temp=root;
	if (root==NULL)
	{
		return 0;
	}
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->right;
		count++;
	}
	return count;
}

/*display all the elements of the doubly linkedlist*/
void display(void)
{
	node* temp;
	temp=root;
	if (root==NULL)
	{
		printf("\ndoubly linkedlist is empty\n");
		return;
	}
	printf("\n\nelements: ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->right;
	}
	printf("\n");
}
