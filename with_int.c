#include<stdlib.h>
#include"head.h"

// リストを初期化する関数
data* init_list(int value){
    data *element = (data*)malloc(sizeof(data));
    element->value = value;
    element->next = NULL;
    element->before = NULL;

    return element;
}

// 末尾に要素を追加する関数
void add_element_on_tail(data *tail,int value){
    data *new_element = (data*)malloc(sizeof(data));
    new_element->before = tail;
    new_element->next = NULL;
    new_element->value = value;

    tail->next = new_element;

    return;
}

//先頭に要素を追加する関数
void add_element_on_top(data *top,int value){
    data *new_element = (data*)malloc(sizeof(data));
    new_element->before=NULL;
    new_element->next=top;
    new_element->value=value;

    top->before = new_element;

    return;
}

//指定した位置に要素を追加する関数
void add_element_on_anywhere(data *top,int index,int value){
    data *next,*before;
    data *new_element = (data*)malloc(sizeof(data));

    data *cursor = top;
    for(int i =0;i<index;i++){
        cursor = cursor->next;
    }

    before = cursor;
    next = cursor->next;

    new_element->next = next;
    new_element->before = before;
    new_element->value = value;

    before->next = new_element;
    new_element->before=new_element;

    return;
}

// リストの長さを取得する関数
int get_list_length(data *top){
    data *cursor = top;
    int length;
    for(length = 1;cursor->next != NULL;length++);

    return length;
}

// 指定のindexのデータを取得する関数
int get_data_with_index(data *top,int index){
    data *cursor = top;
    for(int i = 0;i<index;i++){
        cursor = cursor->next;
    }

    return cursor->value;
}

// リストを開放する関数
void free_list(data *tail){
    data *cursor = tail->before;

    while(cursor->before != NULL){
        free(cursor->next);
        cursor = cursor->before;
    }

    free(cursor);

    return;
}

// 特定のインデックスのデータを削除する関数
 void remove_with_index(data* top,int index){
    data *cursor;
    data *before,*next;
    for(int i = 0;i<index;i++) cursor = cursor->next;
    before = cursor->before;
    next = cursor->next;

    before->next = next;
    next->before = before;

    free(cursor);

    return;
 }