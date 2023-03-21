#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void myprint(){
    printf("hello world\n");
}

int simple_function(){
    static int counter = 0;
    counter++;
    return counter;
}

int *arr(int len){
    int *pointer = malloc(sizeof(int) * len);
    printf("create array in %p with len %d\n", pointer, len);
    return pointer;
}

int summ(int *arr, int len){
    int s = 0;
    for(int i = 0; i < len; i++){
        s += arr[i];
    }
    return s;
}

void free_arr(int *arr){
    printf("freeing array in %p\n", arr);
    free(arr);
}

int create_and_summ(int last_elem){
    int *array = arr(last_elem + 1);

    for(int i = 0; i <= last_elem; i++){
        array[i] = i;
    }

    int summ_of_arr = summ(array, last_elem + 1);
    free_arr(array);
    return summ_of_arr;    
}

long long int cut(long long int num){
    int k = 0;
    while(!(num % 2)){
        num /= 2;
        k++;
    }
    return (long long int)pow(2, k);
}

long long int summ_of_rights(long int input){
    long long int summ = 0;

    for(long int i = 1; i <= input; i++){
        summ += cut(i);
    }
    return summ;
}


int hex_to_dec(char hex){
    char values[] = "0123456789ABCDEF";

    return (int)(strchr(values, hex) - values);
}


int *text_to_arr(char *path, long int len){
    FILE *open_file;
    int *array_with_nums;
    char curr_num[2];

    array_with_nums = (int *)malloc(len * sizeof(int));//1310720
    open_file = fopen(path, "r");

    int k = 0;
    int i = 0;
    while((curr_num[k] = fgetc(open_file)) != EOF){
        if(isspace(curr_num[k])){
            continue;
        }
        
        if(k){
            array_with_nums[i] = hex_to_dec(curr_num[0]) * 16 + hex_to_dec(curr_num[1]);
            i++;
            k = 0;
        }

        else{
            k++;
        }  
    }
    fclose(open_file);

    /*
    for(int i = 0; i < len * 3; i++){
        printf("%d ", array_with_nums[i]);
    }
    */

    return array_with_nums;
}

void clear_arr(int *array){
    free(array);
}


void change_arr(char *path, int *non_change_arr){
    FILE *open_file;
    char curr_num[2];

    //printf("%s", path);
    open_file = fopen(path, "r");

    int k = 0;
    int i = 0;
    while((curr_num[k] = fgetc(open_file)) != EOF){
        if(isspace(curr_num[k])){
            continue;
        }
        
        if(k){
            //printf("%d ---- ", non_change_arr[i]);
            non_change_arr[i] = hex_to_dec(curr_num[0]) * 16 + hex_to_dec(curr_num[1]);
            //printf("%d\n", non_change_arr[i]);
            i++;
            k = 0;
        }

        else{
            k++;
        }  
    }
    fclose(open_file);
}

//gcc -shared -o testlib.so -fPIC testlib.c

/*
int main(int argc, char const *argv[])
{
    myprint();
    printf("%d\n", simple_function());

    int *test_arr = arr(5);
    free_arr(test_arr);
    return 0;
}*/

/*
int main(int argc, char const *argv[]){
    //int *arr = text_to_arr("D:/pyth/nti/0.txt", 3 * 1024 * 1280);
    int *arr = malloc(sizeof(int) * 3 * 1024 * 1280);
    change_arr("D:/pyth/nti/0.txt", arr);

    int t = clock();

    for(long int i = (3 * 1024 * 1280) - 50; i < 3 * 1024 * 1280; i++){
        printf("%d ", arr[i]);
    }

    
    //clear_arr(arr);
    free(arr);
    printf("\n%f", ((float)t) / CLOCKS_PER_SEC);
    return 0;
}
*/