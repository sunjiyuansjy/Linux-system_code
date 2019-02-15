/*  同步：吃方便面
 *      一个线程卖方便面
 *      一个线程吃方便面
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_cond_t full;
pthread_cond_t empty;
pthread_mutex_t mutex;
int have_noodle = 0;
void *sale_noodle(void *arg)
{
    while(1) {
        pthread_mutex_lock(&mutex);
        while(have_noodle != 0) {
            //有面则等待
            pthread_cond_wait(&full, &mutex);
        }
        sleep(1);
        printf("create noodle\n");
        have_noodle = 1;
        //int pthread_cond_broadcast(pthread_cond_t *cond);
        //int pthread_cond_signal(pthread_cond_t *cond);
        //signal    单个唤醒
        //broadcast 广播唤醒
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void *buy_noodle(void *arg)
{
    while(1) {
        pthread_mutex_lock(&mutex);
        while(have_noodle == 0) {
            //没有面，则等待
            //int pthread_cond_timedwait(pthread_cond_t *restrict
            //  cond,pthread_mutex_t *restrict mutex,
            //  const struct timespec *restrict abstime);
            //int pthread_cond_wait(pthread_cond_t *restrict cond,
            //  pthread_mutex_t *restrict mutex);
            //
            //  timedwait:  等待指定时间
            //  wait：      死等
            //  cond:       条件变量
            //  mutex：     互斥锁
            //  死等之前需要解锁，并且解锁和死等必须是原子操作，
            //  被唤醒后需要加锁,但是这个加锁不是阻塞的，意味着
            //  不管是否能加锁都会往操做，访问临界资源，如果被唤醒
            //  的是多个线程，则会出问题，因此需要循环的条件判断
            pthread_cond_wait(&full, &mutex);
        }
        printf("eat noodle !! delicious!!\n");
        have_noodle = 0;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&full);
    }
    return NULL;
}
int main()
{
    pthread_t tid1, tid2;
    int ret;

    //int pthread_cond_init(pthread_cond_t *restrict cond,
    //  const pthread_condattr_t *restrict attr);
    //pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    //条件变量初始化
    //cond:     条件变量
    //attr：    条件变量属性
    //成功：0   失败：errno
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);
    pthread_mutex_init(&mutex, NULL);
    ret = pthread_create(&tid1, NULL, sale_noodle, NULL);
    if (ret != 0) {
        printf("create sale thread error\n");
        return -1;
    }
    int i;
    for (i = 0; i < 3; i++) {
        ret = pthread_create(&tid2, NULL, buy_noodle, NULL);
        if (ret != 0) {
            printf("create sale thread error\n");
            return -1;
        }
    }
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    //int pthread_cond_destroy(pthread_cond_t *cond)
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);
    pthread_mutex_destroy(&mutex);
    return 0;
}
