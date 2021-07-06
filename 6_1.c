//task 6_1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct IntQueue{
	unsigned int max;
	int num;
	int front;
	int rear;
	int *que;
}IntQueue;

typedef enum Menu{
	EXIT, ENQUE, DEQUE, POP, SEARCH
}Menu;

bool initQue(IntQueue *que_, unsigned int max_);
bool enqueData(IntQueue *que_, int data_);
bool dequeData(IntQueue *que_, int *ret_data_);
void clearQue(IntQueue *que_);
bool popData(IntQueue *que_, int *ret_data_);
bool searchData(IntQueue *que_, int key_, int *ret_data_);
void printQue(IntQueue *que_);
void termQue(IntQueue *que_);

int main(int argc, char *argv[]){
	IntQueue que_4;
	Menu menu;

	int data, key;

	if(!initQue(&que_4, 4)){
		puts("キューの生成に失敗しました.");
		return 1;
	}

	while(true){
		printf("現在のデータ数:%i/%u\n", que_4.num, que_4.max);
		printf("(1)エンキュー (2)デキュー (3)似非ポップ (4)探索 (0)終了:");
		scanf("%i", (int*)&menu);

		if(menu == EXIT){
			break;
		}
		switch(menu){
			case ENQUE:
				printf("データ:");
				scanf("%i", &data);
				if(!enqueData(&que_4, data)){
					puts("\aエラー:エンキューに失敗しました.");
				}
				break;
			case DEQUE:
				if(!dequeData(&que_4, &data)){
					puts("\aエラー:デキューに失敗しました.");
				}else{
					printf("デキューしたデータは%iです.\n", data);
				}
				break;
			case POP:
				if(!popData(&que_4, &data)){
					puts("\aエラー:似非ポップに失敗しました.");
				}else{
					printf("似非ポップしたデータは%iです.\n", data);
				}
				break;
			case SEARCH:
				printf("探索するデータ:");
				scanf("%i", &key);
				if(searchData(&que_4, key, &data)){
					printf("そのデータは添字%iの位置にあります.\n", data);
				}else{
					puts("\aエラー:探索に失敗しました.");
				}
				break;
		}
		
		printQue(&que_4);
	}
	
	termQue(&que_4);
	
	return 0;
}

bool initQue(IntQueue *que_, unsigned int max_){
	que_->num = que_->front = que_->rear = 0;
	que_->que = calloc(max_, sizeof(int));
	if(que_->que == NULL){
		que_->max = 0u;
		return false;
	}
	que_->max = max_;
	return true;
}

bool enqueData(IntQueue *que_, int data_){
	if(que_->num >= (int)que_->max){
		return false;
	}else{
		que_->num++;
		que_->que[que_->rear++] = data_;
		if(que_->rear == que_->max){
			que_->rear = 0;
		}
	}
	return true;
}

bool dequeData(IntQueue *que_, int *ret_data_){
	if(que_->num <= 0){
		return false;
	}else{
		que_->num--;
		*ret_data_ = que_->que[que_->front++];
		if(que_->front == (int)que_->max){
			que_->front = 0;
		}
	}
	return true;
}

void clearQue(IntQueue *que_){
	que_->num = que_->front = que_->rear = 0;
}

bool popData(IntQueue *que_, int *ret_data_){
	if(que_->num <= 0){
		return false;
	}else{
		que_->num--;
		if(--(que_->rear) < 0){
			que_->rear = que_->max-1;
		}
		*ret_data_ = que_->que[que_->rear];
	}
	return true;
}

bool searchData(IntQueue *que_, int key_, int *ret_data_){
	for(int i = 0; i < que_->num; i++){
		*ret_data_ = (i + que_->front) % (int)que_->max;
		if(que_->que[*ret_data_] == key_){
			return true;
		}
	}
	return false;
}

void printQue(IntQueue *que_){
	int tmp = 0;
	for(int i = 0; i < que_->num; i++){
		tmp = (i + que_->front) % (int)que_->max;
		printf("[%i]:%i\n", tmp, que_->que[tmp]);
	}
}

void termQue(IntQueue *que_){
	if(que_->que != NULL){
		free(que_->que);
	}
	que_->max = 0u;
	que_->num = que_->front = que_->rear = 0;
}
