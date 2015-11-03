#include <stdio.h>
#include <stdlib.h>
#include "lab07.h"

int main(int argc, char const *argv[])
{
    int n, i, temp;
    char c = '\0';
    
    create_heap(516);
	    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        insert_item(temp);
    }

	while (c != 'f')
	{
	    scanf("%c", &c);
	    
	    switch(c)
	    {
	        case 'i':
	            scanf("%d", &temp);
	            insert_item(temp);
	            break;
            case 'm':
                printf("%d\n", get_min());
                //print_heap();
                break;
            case 'M':
                printf("%d\n", get_max());
                //print_heap();
                break;
        } 
    }  
    printf("\n");
    
    printf("Min-heap: ");
    print_heap_min(); 
        
    printf("Max-heap: ");
    print_heap_max();
    return 0;
}
