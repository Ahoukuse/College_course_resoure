#include "TestModule/AhoTestModule.h"

struct Aho_chain
{
    int number;
    unsigned times;
    struct Aho_chain *pre;
    struct Aho_chain *next;
};

typedef struct Aho_chain Aho_chain;

Aho_chain *head = NULL;
Aho_chain *tail = NULL;

int swarp_node(Aho_chain *pre,Aho_chain *curr){
    /* 是不是首节点 */
    if (pre == head)
    {
        head = curr;
                    
    } else {
        pre->pre->next = curr;
    }
    /* 我是不是尾节点 */
    if (curr == tail)
    {
        tail = pre;
        
    } else{
        curr->next->pre = pre;
    }
    pre->next       = curr->next;
    curr->next      = pre;
    curr->pre       = pre->pre;
    pre->pre        = curr;
    
    return 0;
}


int check(int number){
    Aho_chain *curr;
    
    for (curr = head;curr != NULL;curr = curr->next)
    {
        if (curr->number == number)
        {
            curr->times++;
            curr = curr->pre;
            for(;curr && curr->times <= curr->next->times;curr = curr->pre->pre)
            {

                if (curr->times == curr->next->times && 
                    curr->number < curr->next->number)
                {
                    return 0;
                }

                swarp_node(curr,curr->next);
                
            } 
            
            return 1;
        }
        
    }
    curr = malloc(sizeof(Aho_chain));


    if (tail && head)
    {
        tail->next   = curr;
        curr->pre    = tail;
        tail = curr;
    } else if (tail == NULL && head == NULL){
        head = curr;
        tail = curr;
        curr->pre    = NULL;
        curr->next    = NULL;
    }
    


    curr->number = number;
    curr->times  = 1;
    return 0;
}


int main() {
    INIT
    Aho_chain *curr;
    int colum = 0,i,x;
    TEST_SECTION_BEGIN(1)

    scanf("%d",&colum);

    for (i = 0; i < colum; i++)
    {
        scanf("%d",&x);
        check(x);
    }
    for (curr = head;curr && curr->times == head->times; curr = curr->next)
    {
        printf("%d %d\n",curr->number,curr->times); 

    }


    TEST_SECTION_END
    DROP
    return 0;
}