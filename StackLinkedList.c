// Stack implementation through Linked list 
// 1. Push
// 2. Pop

#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>

typedef struct node_type
{
	char data;
	struct node_type *next;
}	node;

typedef node *list; 
list temp, current;

int main()
{
	int action_key = 0;
	do {
	    printf("\nEnter 1: Pop, 2: Push, 3: Print, 4: Size, 5: Is stack empty, 6: Exit \n");
		scanf("%d", &action_key);
		switch(action_key){
			case 1:
				pop();
				break;
			case 2:
				push();
				break;
			case 3:
				prints_list();
				break;
			case 4:
				find_size();
			    break;
			case 5:
				is_empty();
			    break;
			case 6:	
				break;
			default:
				break;
		}
	} while(action_key < 6);
	getch();
	return 0;
}

int push()
{
	char c;
	list tail = NULL;
	printf("\nEnter a character\n");
    scanf(" %c", &c);
    if(current == NULL)
	{
		current = (list) malloc(sizeof(node));
		current->next = NULL;
		current->data = c;
	}
	else
	{
		tail = (list) malloc(sizeof(node));
		tail->next = current;
		tail->data = c;
		current = tail;
	}
	prints_list(current);
	return 0;
}

int pop()
{
    list current_top = NULL;
	current_top = current;
	if(current_top == NULL){
		prints_list(current);
		return 0;
	}
	else{
		current_top = current_top->next;
	}		
    free(current);
    current = current_top;
	prints_list(current);	
	return 0;
}

int find_size()
{
	list iterator = NULL;
	int size = 0;
	iterator = current;
	while(iterator != NULL){
		iterator = iterator->next;
		size++;
	}
	printf("Stack size is: %d", size);
	return size;
}

int is_empty()
{
	list iterator = NULL;
	iterator = current;
	if(iterator == NULL){
		printf("\nThe stack is empty\n");
	}
	else
	{
		printf("\nThe stack is not empty\n");
	}
	return 0;
}

int prints_list()
{
	list iterator = NULL;
    iterator = current;
    if (iterator == NULL)
    {
        printf("\nThe stack is empty\n");
        return 0;
    }
    printf("\nThe list is: \n");
    while (iterator != NULL)
    {
        printf("%c \n", iterator->data);
        iterator = iterator->next;
    }    	
	return 0;
}
