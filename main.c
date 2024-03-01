//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int z = 5;
    Node a,b,*head ;
    a.value = z;
    a.next=&b;
    head=&a;
    b.value=head->value+3;
    printf("\n");
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    Node c ;
    c.value = 11 ;
    b.next = &c ;
    c.next = NULL ;
    printf("%d\n", head ->next->next->value); //what value for 11
    printf("\n");
//----------------------------------------------------------------------------------------
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
*/
    Node d ;
    d.next = &a ;
    d.value = 2 ;
    head = &d ;
    printf("%d\n", head -> value); //value d
    printf("%d\n", head -> next -> value); //value a
    printf("%d\n", head -> next -> next -> value); //value b
    printf("%d\n", head -> next -> next -> next -> value); //value c
    printf("\n");
//----------------------------------------------------------------------------------------
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    //  Exercise III Use loop to print everything */
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp = tmp -> next ;
        }

    tmp = head ; 
    printf("\n");
    printf("\n");
//----------------------------------------------------------------------------------------
    // Exercise IV change to while loop!! (you can use NULL to help)
       
         while(tmp != NULL){
            printf("%3d", tmp->value);
            tmp = tmp -> next ;
        }
        printf("\n");
        printf("\n");
//----------------------------------------------------------------------------------------
    // 2 5 8 11
    //Exercise V Use malloc to create all nodes, instead of create a struct!!
    //use a loop to help

        typedef Node* nodePtr;
        nodePtr temp ;
        // Create first Node
        head = (nodePtr) malloc(sizeof(Node));
        temp = head ;
        //temp -> value = 1 ;

        /*
        // Secound node
        temp -> next = (nodePtr)malloc(sizeof(Node));
        temp = temp -> next ;
        temp -> value = 4 ;
        
        //Third Node
        temp -> next = (nodePtr)malloc(sizeof(Node));
        temp = temp -> next ;
        temp -> value = 7 ;

        // Forth Node
        temp -> next = (nodePtr)malloc(sizeof(Node));
        temp = temp -> next ;
        temp -> value = 10 ;
        */

        //bring line 77 - 92 into loop
        for(int i = 0; i<4; i++)
        {
            temp -> value = 2+(3*i) ;
            printf("%3d", temp->value);
            if(temp -> value == 12) temp -> next = NULL;
            else{
                temp -> next = (nodePtr)malloc(sizeof(Node));
            }
            temp = temp -> next ;
        }
        printf("\n");
        printf("\n");
//----------------------------------------------------------------------------------------
    //Exercise VI Free all node !!
    //use a loop to help
        // temp = head;
        // head = head -> next ;
        // free(temp);
        
        while (head != NULL)
        {
            temp = head;
            head = head -> next ;
            printf("--- %d --- %d ---\n", temp->value, head->value);
            free(temp);
            printf("--- %d --- %d ---\n\n", temp->value, head->value);
        }
    return 0;
}
