#include<thread_copy.h>


pthread_t *  thread_create(const char*sfile,const char* dfile,int blocksize,int thread_num)
{
	pthread_t * tid = (pthread_t *)malloc(sizeof(pthread_t) * thread_num);	
        
        for(int flag=0; flag<thread_num ; flag++){
        Args * args = (Args*) malloc(sizeof(Args));
	args->sfile = sfile;
	args->dfile = dfile;
	args->blocksize = blocksize;
	args->pos = flag * blocksize;
	
	pthread_create(&tid[flag],NULL,copy,(void*)args);
    }
    return tid;
}

