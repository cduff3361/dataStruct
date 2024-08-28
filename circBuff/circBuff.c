#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


#define BUF_CAPACITY	10

typedef enum{
	ERROR_GENERAL = -2,
	ERROR_NULL_PTR = -1,
	CIRC_BUFF_SUCCESS = 0,
	SUCCESSFUL_PUSH = 1,
	SUCCESSFUL_POP = 2,
	BUF_EMPTY = 3
}circBuf_ret;
	

typedef struct circBuff{
	int head;
	int tail;
	int buf[BUF_CAPACITY];
	int capacity;
	int numElements;
}circBuff;


static bool isEmpty(circBuff* buffer){
	(buffer->numElements == 0) ? true : false;
}


circBuff* createCircBuff(void){
	
	circBuff* tempBuf = (circBuff*)malloc(sizeof(circBuff));
	tempBuf->head = 0;
	tempBuf->tail = 0;
	memset(tempBuf->buf, 0, (tempBuf->capacity)*sizeof(tempBuf->buf[0]));
	tempBuf->capacity = BUF_CAPACITY;
	
	return tempBuf;
}


circBuf_ret push(circBuff* buf, int value)
{
	circBuf_ret retVal = ERROR_GENERAL;
	int nextIndex = (buf->head + 1)%buf->capacity;
	
	if(buf == NULL){
		printf("Pushing into NULL pointer not allowed\n");
		retVal = ERROR_NULL_PTR;
		return retVal;
	}
	
	//Full buffer -> discard incoming data
	if(nextIndex == buf->tail){
		printf("Buf full, discarding value\n");
		retVal = ERROR_GENERAL;
		return retVal;
	}
	
	else{
		buf->buf[buf->head] = value;
		buf->head = (buf->head + 1) % buf->capacity;
		buf->numElements++;
	}
	
	retVal = SUCCESSFUL_POP;
	return retVal;
	
	
}//Function: push

circBuf_ret pop(circBuff* buffer, int* returnValue){
		
	circBuf_ret retVal = ERROR_GENERAL;
	
	if(buffer->head == buffer->tail){
		retVal = BUF_EMPTY;
		printf("Buffer empty\n");
		return retVal;
	}
	
	if(buffer == NULL){
		retVal = ERROR_NULL_PTR;
		return retVal;
	}
	
	*returnValue = buffer->buf[buffer->tail];
	
	buffer->tail = (buffer->tail + 1) % buffer->capacity;
	buffer->numElements--;
	
	retVal = SUCCESSFUL_POP;
	return retVal;
	
}


circBuf_ret printBuffer(circBuff* bufToPrint)
{
	circBuf_ret retVal = ERROR_GENERAL;
	
	if(bufToPrint == NULL){
		retVal = ERROR_NULL_PTR;
		return retVal;
	}
	
	int tempIndex = bufToPrint->tail;
	
	while(tempIndex != bufToPrint->head){
		printf("%d\n", bufToPrint->buf[tempIndex]);
		tempIndex = (tempIndex + 1) % bufToPrint->capacity;
	}
}

int main(){

	circBuff* buffer = createCircBuff();
	
	push(buffer, 1);
	push(buffer, 2);
	push(buffer, 3);
	push(buffer, 4);
	push(buffer, 5);
	push(buffer, 6);
	push(buffer, 7);
	push(buffer, 8);
	push(buffer, 9);
	push(buffer, 10);
	push(buffer, 11);
	
	printf("check\n");
	
	printBuffer(buffer);
	
	int popVal = 0;
	
	pop(buffer, &popVal);
	push(buffer, 11);
	push(buffer, 23);
	printf("\nPopping: %d\n\n", popVal);
	printBuffer(buffer);
	
	
	
}