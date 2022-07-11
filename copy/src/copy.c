#include<thread_copy.h>



void * copy(void * args)
{
	Args* aaa = (Args*)args;
	
	char buffer[aaa->blocksize];
	bzero(buffer, sizeof(buffer));
	ssize_t readlen;

	int sfd = open(aaa->sfile, O_RDONLY);
	int dfd = open(aaa->dfile, O_RDWR|O_CREAT, 0664);

	lseek(sfd, aaa->pos, SEEK_SET);
	lseek(dfd, aaa->pos, SEEK_SET);

    	readlen = read(sfd,buffer,sizeof(buffer));
    	write(dfd,buffer,readlen);

    	close(sfd);
    	close(dfd);

	free(args);
	args = NULL;
	aaa = NULL;

	return 0;
}

