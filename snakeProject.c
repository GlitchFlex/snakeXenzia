#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>

typedef struct tail{
	int tailX;
	int tailY;
	struct tail* next;
}snakeTail;

int height=20,width=30;
int x,y,fruitX,fruitY,gameOver,score,flag;
int countTail=0;
snakeTail* head;

snakeTail* incrceaseLength(snakeTail*n,int xc,int yc){
	snakeTail* temp1=(snakeTail*)malloc(sizeof(snakeTail));
	int c=countTail;
	temp1->tailX=xc;
	temp1->tailY=yc;
	temp1->next=n;
	if(c==0){
		free(temp1);
	}else{
		n=temp1;
	}
	snakeTail*temp2 = n; 
	while(temp2!=NULL){
		if(c==1){
			temp2->next=NULL;
			break;
		}
		c--;
		temp2=temp2->next;
	}
	return n;
}

void setup(){
	gameOver=0;
	x=width/2;
	y=height/2;
	label1:
	fruitX=rand()%20;
	if(fruitX==0){
		goto label1;
	}
	label2:
	fruitY=rand()%20;
	if(fruitY==0){
		goto label2;
	}
	head=(snakeTail*)malloc(sizeof(snakeTail));
	head = NULL;
}

void draw(){
	int i,j,k;
	system("cls");
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			if(i==0 || i==height-1 || j==0 || j==width-1){
				printf("#");
			}else{
				if(i==y&&j==x){
					printf("0");
				}else if(i==fruitY&&j==fruitX){
					printf("*");
				}else{
					int ch=0;
					snakeTail*p;
					p=head;
					while(p!=NULL){
						if(j==p->tailX && i==p->tailY){
							printf("o");
							ch=1;
						}
						p=p->next;
					}
					if(ch==0)
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
void input(){
	if(kbhit()){
		int key=getch();
		switch(tolower(key)){
			case 's':
				flag=1;
				break;
			case 'a':
				flag=3;
				break;
			case 'd':
				flag=4;
				break;
			case 'w':
				flag=2;
				break;
			case 'x':
				gameOver=1;
				
		}
	}
}

void makeLogic(){
	
	head=incrceaseLength(head,x,y);
	
	switch(flag){
		case 1:
			y++;
			break;
		case 2:
			y--;
			break;
		case 3:
			x--;
			break;
		case 4:
			x++;
			break;
		default:
			break;
	}
	if(x<0 || x>width || y<0 || y>height){
		gameOver=1;
	}
	snakeTail*q=(snakeTail*)malloc(sizeof(snakeTail));
	q=head;
	while(q!=NULL){
		if(x==q->tailX && y==q->tailY){
			gameOver=1;
		}
		q=q->next;
	}
	if(x==fruitX&&y==fruitY){
	label3:
	fruitX=rand()%20;
	if(fruitX==0){
		goto label3;
	}
	label4:
	fruitY=rand()%20;
	if(fruitY==0){
		goto label4;
	}
	score+=1;
	countTail++;
	}
	
}

int main(){
	printf("-----------------------WELCOME TO SNAKE GAME-----------------------\n");
	printf("\n\t\t\tHERE'S HOW YOU PLAY-\n");
	printf("\t\t\t	 / \\  	\n");
	printf("\t\t\t	  |   	\n");
	printf("\t\t\t	  W   	\n");
	printf("\n\t\t\t<--A	  	 D-->\n");
	printf("\n\t\t\t	  S  	\n");
	printf("\t\t\t	  |   	\n");
	printf("\t\t\t	 \\ /   	\n");
	char name[100];
	printf("\n\nEnter Name:\n");
	scanf("%s",name);
	int speed,m,n;
	label6:
	printf("Enter Speed- 1(slow), 2(medium) or 3(fast) \n");
	scanf("%d",&speed);
	switch(speed){
		case 1:
			speed=10000;
			break;
		case 2:
			speed=1000;
			break;
		case 3:
			speed=0;
			break;
		default:
			goto label6;
	}
	
	label5:
	setup();
	while(1){
		draw();
		input();
		makeLogic();
		if(gameOver==1){
			break;
		}
		for(m=0;m<speed;m++){
			for(n=0;n<speed;n++){
				
			}
		}
	}
	printf("\nGAME OVER!\n");
	printf("\nScore-");
	printf("\n%s: %d ",name,score);
	printf("\nPress 'c' to continue or any other button to exit\n");
	char ch;
	scanf("%s",&ch);
	if(ch=='c'||ch=='C'){
		goto label5;
	}
	else{
		exit(0);
	}
	
	return 0;
}
