#include<thread_copy.h>

int main(int argc, char ** argv){
    int thread_num;
    if(argv[3]==0)
        thread_num = 3;
    else
        thread_num = atoi(argv[3]);
    //参数校验
    pram_check(argc,argv[1],thread_num);
    //任务量计算
    int blocksize;
    blocksize = file_block(argv[1],thread_num);
    //进程创建
    pthread_t * tid = thread_create(argv[1],argv[2],blocksize,thread_num);
    //
    thread_join(tid , thread_num);
    return 0;

}

