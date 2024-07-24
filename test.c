#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

	pthread_mutex_t *mutex;

void	*routine(void *data)
{
	pthread_mutex_lock(&mutex[0]);
	printf("ahmet\n");
	//pthread_mutex_unlock(&mutex[0]);
	return NULL;
}

int main()
{
	pthread_t *threads;

	int	i;

	i = 0;
	threads = malloc(sizeof(pthread_t) * 2);
	mutex = malloc(sizeof(pthread_mutex_t) * 2);
	while (i < 2)
		pthread_mutex_init(&mutex[i++], NULL);
	i = 0;
	while (i < 2)
	{
		int *a; 
		a = malloc(sizeof(int));
		*a = i;
		pthread_create(&threads[i++], NULL, &routine, a);
	}
	i = 0;
	while (i < 2)
		pthread_join(threads[i++], NULL);
	i = 0;
	while (i < 2)
		pthread_mutex_destroy(&mutex[i++]);
}