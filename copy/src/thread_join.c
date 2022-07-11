#include "thread_copy.h"

int thread_join(pthread_t* tid, int thread_num)
{
	for (int flag = 0; flag < thread_num; flag++)
	{
		pthread_join(tid[flag], NULL);
	}

	free(tid);
	tid = NULL;
	return 0;
}
