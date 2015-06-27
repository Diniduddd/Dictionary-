 /*Project II: Dynamic Dictionary
 
 Author: Handunpathirana, H.P.D.B.  E/10/119
 *
 * Date: 27-May-2013
*/
#include<stdio.h>
#include<stdlib.h>


struct item
{
	int key;
	unsigned int value;
	struct item* next;
};

typedef struct item dict;

dict* new_dictionary(){ 
/*creat the head and return the address of head*/
	dict* nw;
	nw=malloc(sizeof(dict));
	nw->value=0;
	nw->key=0;
	nw->next=NULL;
	return nw;
	}
	
int add_item(dict* dictionary, int key){
	dict* nxt;
	dict* nw;
	/* the first data entry for the dinctionary*/
	if (dictionary->next==NULL){
		nw=malloc(sizeof(dict));
		dictionary->next=nw;
		nw->key=key;
		nw->value=1;
		nw->next=NULL;
		return 1;
		}
	else{	
		nw=dictionary->next;
		/*check for existing entris for same key and updatevalue if any*/
		while(nw!=NULL){
			if (nw->key== key){
				nw->value= nw->value +1;
				return 1;
				}
			nxt=nw;
			nw=nw->next;
		}
		/* If there is no exeisting entry add the new key to the dictionary*/	
		nw=malloc(sizeof(dict));
		nxt->next=nw;
		nw->key=key;
		nw->value=1;
		nw->next=NULL;
		return 1;
		}
		return 0;
		}
		
		
void sort_by_value(dict* dictionary){

	dict*next1;
	dict*next2;
	dict*back;
	dict*frnt;
	int num1,num2,n,m;
	next1=dictionary;
	/* count the elements in the dictionary*/
	for(n=0;next1!=NULL;n++){
		next1=next1->next;
	}
	n=n-2;
	/*check value and send lower values to the end of the list*/
	while(n!=1){
		next1=dictionary->next;
		next2=next1->next;
		back=dictionary;
		for(m=0;m<n;m++){
			if(next1->value < next2->value){
				back->next=next2;
				frnt=next2->next;
				next2->next=next1;
				next1->next=frnt;
				
				back=next2;
				next2=frnt;
				}
				
			else{
				back=next1;
				next1=next2;
				next2=next2->next;
			}
		}
		n=n-1;
		}
	}
					



unsigned int get_value_by_position(dict* dictionary, int position){
	int n=0;
	dict* next1;
	next1=dictionary;
	/*count the elements in the dictionary*/
	for(n=0;next1!=NULL;n++){
		next1=next1->next;
	}
	n=n-1;
	/*chack weather the position given is exist in the dictionary and if not return 0*/ 
	if (n<position){
	 return 0;
	 }
	 
	else{
		n=0;
		while (n<position){
			dictionary=dictionary->next;
			n++;
			}
		
		return dictionary->value;
	}
	}
	
int get_key_by_position(dict* dictionary, int position){
/* return the key for the positin*/
	int n=0;
	while (n<position){
		dictionary=dictionary->next;
		n++;
		}
	
	return dictionary->key;
	}

	

	