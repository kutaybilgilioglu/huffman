#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<strings.h>
#include<stdbool.h>

typedef struct node{
	char harf;
	int frequency;
	struct node *left,*right,*next;
	
}
node;
bool check(node* ,char harf);
void sort(node *current, node *head);
void print(node *current);


int main(){
	char *filename=malloc(sizeof(char));

	int g=0;
	char f;

	printf("dosya ismi girin\n");
    	while((f=getchar())!='\n'){
		realloc(filename,sizeof(char));
		filename[g++]=f;
	}
	filename[g]='\0';
	FILE *text=fopen(filename,"r");
	if(text==NULL){
		return 1;
	}
	fseek(text,0,2);
	int size=ftell(text);
	printf("%d\n",size);
	char *kelime=malloc(size+1);
	
	fseek(text,0,0);
	printf("%d\n",size);

      fgets(kelime,size+1,text);
      
	
	fclose(text);
printf("%s\n",kelime);
printf("%c",kelime[0]);
	
	node *head=malloc(sizeof(node));
	head->harf=kelime[0];
	head->frequency=1;
	head->next,head->left,head->right=NULL;
	node *current=malloc(sizeof(node));
int i;
printf("%c",head->harf);
	bool b;
	printf("%d",(int)kelime[8]);
	for(i=1;(int)kelime[i]!=0;i++){
	
		current=head;
		
	b=check(head,kelime[i]);//check function
	printf("%d",b);
		
		if(b==1){
			continue;
		}
		else{
				printf("%c",tolower(kelime[1]));	
			current=head;
			node *list=malloc(sizeof(node));
			list->next,list->left,list->right=NULL;
			list->harf=kelime[i];
			list->frequency=1;
			while(current->next!=NULL){
				current=current->next;				
			}
			current->next=list;					
		}
		printf("%c",kelime[1]);		
	}
	printf("%c\n",tolower(kelime[1]));
	printf("%d",head->frequency);
	
		current=head;
		sort(current,head);
		current=head;
		printf("%c",kelime[1]);
		print(current);
		
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
void sort(node *current, node *head){
		node *curnext=malloc(sizeof(node));
		node *prev=malloc(sizeof(node));
		prev->next,prev->right,prev->left=NULL;
		curnext->left,curnext->right=NULL;
		*curnext=*current->next;
	while(curnext==NULL){
		while(curnext->frequency>current->frequency||curnext==head){
			*current=*head;
			while(current->next==curnext){
				*current=*current->next;
			}
			if(curnext->frequency<current->frequency){
				current->next=curnext->next;
				prev->next=curnext;
				curnext->next=current;
				curnext=current->next;
		}
		else{
			curnext=curnext->next;
			continue;
		}                                         			
		
		}
					
	}
}
void print(node *current){
	while(current!=NULL){
		printf("%c %d",current->harf,current->frequency);
		*current=*current->next;
	}
}
bool check(node *head,char harf){
	node* tmp=head;
	char c;
	while(true){
		c=tmp->harf;
		
		if((int)c==(int)harf||(int)c+32==(int)harf||(int)c-32==(int)harf){
			printf("control2");
	    tmp->frequency++;		
		return true;
	}
	    else{
	    	if(tmp->next==NULL){
	    	    printf("control5");
	    		return false;
			}
			else{
				printf("control3");
		        tmp=tmp->next;
				continue;	
			}
	    	
	}
printf("control4");
	}


}



