typedef struct{
    int value;
    data *next;
    data *before;
} data;

// 各関数のプロトタイプ
data* init_list(int);
void add_element_on_tail(data*,int);
void add_element_on_top(data*,int);
void add_element_on_anywhere(data*,int,int);
int get_list_length(data*);
int get_data_with_index(data*,int);
void free_list(data*);
void remove_with_index(data*,int);