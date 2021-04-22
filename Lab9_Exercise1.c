#include <stdio.h>
#include <pthread.h>
int balance = 1000;
void *deposite(void *p) {
    balance = balance + 10;
    pthread_exit(NULL);

}
void *witdraw(void *p) {
    balance = balance - 5;
    pthread_exit(NULL);
}
int main() {

    pthread_t thread_1;
    pthread_t thread_2;
    pthread_create (&thread_1, NULL, deposite,NULL);
    int* ptr;
    for (int i = 0; i <500 ; ++i) {
        pthread_create (&thread_1, NULL, deposite,NULL);
        pthread_join(thread_1, (void**)&ptr);

    }
    printf("after thread deposite %d\n",balance);

    int* ptr2;
    for (int i = 0; i <500 ; ++i) {
        pthread_create (&thread_2, NULL, witdraw,NULL);
        pthread_join(thread_2, (void**)&ptr);

    }
    printf("after thread witdraw %d\n",balance);
    pthread_create (&thread_2, NULL, witdraw,NULL);
    printf("Exiting from main program balance= %d\n",balance);




    return 0;
}

