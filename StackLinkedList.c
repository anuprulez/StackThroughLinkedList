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
    
int main()
{
	int counter, how_many_characters = 0, pop_counter = 0, list_size = 0, action_key = 0;
	char data_char;
	list head, temp, tail, current = NULL, previous = NULL, iterator = NULL;
	head = NULL, temp = NULL, tail = NULL;
	printf("\nHow many characters: \n");
	scanf("%d", &how_many_characters);
	printf("Enter the characters: \n");
	for(counter = 0; counter < how_many_characters; counter++)
	{
		temp = (list) malloc(sizeof(node));
		scanf(" %c", &data_char);
		temp->data = data_char;
		temp->next = NULL;
		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			current->next = temp;
		}
		current = temp;
	}
	printf("\nThe original list: \n");
	prints_list(head);
	//push(head);
	//pop(head);
	// list_size = find_size(head);	
	// for(pop_counter = 0; pop_counter < list_size; pop_counter++){
		// pop(head);
	// }
	//is_empty(head);
	do {
	    printf("\nEnter 1: Pop, 2: Push, 3: Print, 4: Size, 5: Is Empty, 6: Exit \n");
		scanf("%d", &action_key);
		switch(action_key){
			case 1:
				pop(head);
				break;
			case 2:
				push(head);
				break;
			case 3:
				prints_list(head);
				break;
			case 4:
				find_size(head);
			    break;
			case 5:
				is_empty(head);
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

int push(list list_head)
{
	char c;
	list tail = NULL, current = NULL, iterator = NULL;
	printf("\nenter a character\n");
    scanf(" %c", &c);
    tail = (list) malloc(sizeof(node));
    tail->data = c;
    tail->next = NULL;
    current = list_head;
    while(current->next)
	{
		current = current->next;
	}
    current->next = tail;
	printf("\nThe updated list after push is: \n");
	prints_list(list_head);
	return 0;
}

int pop(list head_list)
{
    list previous = NULL, current = NULL;
	current = head_list;
	while(current->next)
	{
		previous = current;
		current = current->next;
	}
	current = NULL;	
	//previous->next = NULL;	
	printf("\nThe list is:\n");
	is_empty(head_list);	
	return 0;
}

int find_size(list head_list){
	list iterator = NULL;
	int size = 0;
	iterator = head_list;
	while(iterator != NULL){
		iterator = iterator->next;
		size++;
	}
	printf("The size of the linked list is: %d", size);
	return size;
}

int is_empty(list head_list){
	list iterator = NULL;
	iterator = head_list;
	if(iterator == NULL){
		printf("\nThe list is empty\n");
	}
	else
	{
		prints_list(head_list);
	}
	return 0;
}

int prints_list(list head_list){
    list iterator = NULL;
	iterator = head_list;	
	while(iterator != NULL)
	{
		printf("%c \n", iterator->data);
		iterator = iterator->next;
	}    	
	return 0;
}
