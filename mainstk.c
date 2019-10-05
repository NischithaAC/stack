#include<assert.h>
#include "stack.h"
#include "queue.h"

void test_empty_stack()
{
	Stack stk=stack_new(5);
	Stack *stk=&stk;
	Stack_Result res;

	Queue q=queue_new(5);
	Queue *q=&q;
	Queue_Result res;

    stk= stack_push(stk,10,&res);
    stk= stack_push(stk,20,&res);
    stk= stack_push(stk,30,&res);

    assert(stk->data[stk->top]==30);


    q=queue_add(q,stk->data[stk->top],&res);
    stk=stack_pop(stk,&res);
    q=queue_add(q,stk->data[stk->top],&res);
    stk=stack_pop(stk,&res);

    assert(q->data[q->tail]==30);
    assert(q->data[q->head-1]==10);

	assert(stack_full(stk)==0);
	assert(stack_empty(stk));
}

int main()
{
	test_empty_stack();
	return 0;
}