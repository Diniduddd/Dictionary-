/* The header file for the dictionary data structure
 *
 * Author: Pramod Herath
 *
 * Date: 12-May-2013
 */
#include<stdio.h>
#include<stdlib.h>
#include "dictionary.h"

int main()
{
	dict* myDictionary = new_dictionary();
	int number, k;
	while(1)
	{
		printf("Enter a number (EOF to finish - Ctrl+d in Linux Ctrl+z in Windows):");
		k = scanf("%d",&number);
		if(k == EOF)
			break;
        
		if(!(add_item(myDictionary, number))){
			printf("Error: Insertion of %d failed\n", number);
			exit(-1);
		}
	}
	//printf("\n------------------------------------------------------------------------------\n");
	sort_by_value(myDictionary);
	//print(myDictionary);
	
	if(get_value_by_position(myDictionary,1) == 1)
		printf("Each number is reported only once");
	else
	{
		printf("The mode(s) is/are:");
		
		int mode = get_value_by_position(myDictionary,1);
		int temp;
		int i = 1;
		while(1)
		{
			temp = get_value_by_position(myDictionary,i);
			if(temp != mode)
				break;
			printf("%d ", get_key_by_position(myDictionary,i));
			i++;
		}
		printf("\n");  
	}
	return 0;
}