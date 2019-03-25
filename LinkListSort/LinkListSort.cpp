#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct LNode{
	elemType data;
	struct LNode *next;
}LNode;

LNode *createList(elemType a[],int len){
	LNode *L,*r,*s;
	int i;
	if(len <= 0)
		return NULL;
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL){
		printf("¿Õ¼ä·ÖÅäÊ§°Ü.\n");
			exit(0);
	}
	r = L;
	for(i = 0;i < len;i++){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}
void printList(LNode *L){
	LNode *p = L->next;
	while(p != NULL){
		printf("%d->",p->data);
		p = p->next;
	}
	printf("\n");
}
void swap(elemType *a,elemType *b){
	elemType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void linkListSelectSort(LNode **L){
	LNode *p = (*L)->next;
	LNode *min,*q;
	while(p->next != NULL){
		min = p;
		q = p->next;
		while(q != NULL){
			if(min->data > q->data)
				min = q;
			q = q->next;
		}
		swap(&(min->data),&(p->data));
		p = p->next;
	}
}
void linkListInsertSort(LNode **L){
	LNode *p,*pre,*q;
	p = (*L)->next->next;
	(*L)->next->next = NULL;
	while(p != NULL){
		q = p->next;
		pre = (*L);
		while((pre->next != NULL) && (pre->next->data < p->data))
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}
int main(){
	elemType a[] = {3,16,6,32,4,14,25,42,29,22,36,39,68};
	int len = sizeof(a)/sizeof(a[0]);
	LNode *L;
	L = createList(a,len);
	printList(L);
	//linkListSelectSort(&L);
	linkListInsertSort(&L);
	printList(L);
}
