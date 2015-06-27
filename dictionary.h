/* The header file for the dictionary data structure
 *
 * Author: Pramod Herath
 *
 * Date: 12-May-2013
 */

// The data structure for each element in the dictionary
struct item
{
	int key;
	unsigned int value;
	struct item* next;
};

typedef struct item dict;
 
/* create the head of the dictionary structure. Head is
   a node with key and value set to zero and therefore
   will not be used to store a key, value pair   */
dict* new_dictionary();

/* add a new item to the dictionary with key as key. 
   Return 1 for successful addition and 0 for failure */  
int add_item(dict* dictionary, int key);

/* sort the dictionary by value in descending order and
   return the new dictionary */
void sort_by_value(dict* dictionary);

/* should return the value in the item at the given position. 
   The positions start from 1 based count from the second node
   (first node is the head) */
unsigned int get_value_by_position(dict* dictionary, int position);

/* should return the key in the item at the given position. 
   The positions start from 1 based count from the second node
   (first node is the head) */
int get_key_by_position(dict* dictionary, int position);

int count(dict* dic);
int print(dict* dic);



		
	
		
		
		
	
	
		
	
	
	
	