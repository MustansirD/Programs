#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER; 

int count = 1;
int num = 1;
//int temp;
int num_of_times = 5;
void* function1();
void* function2();
void* function3();
void* function4();
void* function5();
//void* function5();

int main(void)
{

pthread_t thread1,thread2,thread3,thread4,thread5;

pthread_create(&thread1,NULL,function1,NULL);
pthread_create(&thread2,NULL,function2,NULL);
pthread_create(&thread3,NULL,function3,NULL);
pthread_create(&thread4,NULL,function4,NULL);
pthread_create(&thread5,NULL,function5,NULL);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
pthread_join(thread3,NULL);
pthread_join(thread4,NULL);
pthread_join(thread5,NULL);

}

void* function1()
{
	while(num_of_times>=0)
	{
		pthread_mutex_lock(&lock1);
		if(count==1)
		{
			printf("%d\t",num);
			count++;
			//num_of_times--;
			pthread_mutex_unlock(&lock1);
			pthread_cond_broadcast(&cond1);
		//	return NULL;
		}
		else
		{
			pthread_cond_wait(&cond1,&lock1);
			pthread_mutex_unlock(&lock1);
		}
	
	}
	return NULL;
}

void* function2()
{
	while(num_of_times>=0)
	{
		pthread_mutex_lock(&lock1);
		if(count==2)
		{
			printf("%d\t",num*num);
			count++;
			//num_of_times--;
			pthread_mutex_unlock(&lock1);
			pthread_cond_broadcast(&cond1);
		//	return NULL;
		}
		else
		{
			pthread_cond_wait(&cond1,&lock1);
			pthread_mutex_unlock(&lock1);
		}
	
	}
	return NULL;
}

void* function3()
{
	while(num_of_times>=0)
	{
		pthread_mutex_lock(&lock1);
		if(count==3)
		{
			num = num+1;
			printf("%d\t",num);
			count++;
		//	num_of_times--;
			pthread_mutex_unlock(&lock1);
			pthread_cond_broadcast(&cond1);
		//	return NULL;
		}
		else
		{
			pthread_cond_wait(&cond1,&lock1);
			pthread_mutex_unlock(&lock1);
		}
	
	}
	return NULL;
}

void* function4()
{
	while(num_of_times>=0)
	{
		pthread_mutex_lock(&lock1);
		if(count==4)
		{
			printf("%d\t",num*num);
			count++;
		//	num_of_times--;
			pthread_mutex_unlock(&lock1);
			pthread_cond_broadcast(&cond1);
		//	return NULL;
		}
		else
		{
			pthread_cond_wait(&cond1,&lock1);
			pthread_mutex_unlock(&lock1);
		}
	
	}
	return NULL;
}
void* function5()
{
	while(num_of_times>=0)
	{
		pthread_mutex_lock(&lock1);
		if(count==5)
		{
			printf("%d\n",num*num*num);
			num=num+1;
			count=1;
			num_of_times--;
			pthread_mutex_unlock(&lock1);
			pthread_cond_broadcast(&cond1);
		//	return NULL;
		}
		else
		{
			pthread_cond_wait(&cond1,&lock1);
			pthread_mutex_unlock(&lock1);
		}
	
	}
	return NULL;
}
