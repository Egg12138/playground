#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
//缓冲区大小
#define MAX_BUFFER_SIZE 10

struct buf //循环队列
{
	int in; //指向缓冲中下一个空位
	int out; //指向缓冲中第一个满位
	char str[MAX_BUFFER_SIZE]; //存放字母
	int num; //产品个数
	int is_empty; //是否为空
};
struct buf bf; //定义一个循环队列
const int N_Consumer = 2; //消费者数量
const int N_Producer = 2; //生产者数量
const int N_Buffer = 10; //缓冲区大小
const int N_Worktime = 10; //每个进程执行的次数
sem_t full, empty, mutex; //三个信号量
struct timeval start; //开始时间
struct timeval now; //当前时间

int get_rand_num() //0~99 随机数
{
	gettimeofday(&now, NULL);
	int digit;
	srand((unsigned)(now.tv_usec)); //当前时间（微秒）作为随机数种子
	digit = rand() % 100;
	return digit;
}

char get_rand_letter() //随机生成A~Z
{
	gettimeofday(&now, NULL);
	char letter;
	srand((unsigned)(now.tv_usec));
	letter = (char)((rand() % 26) + 'A');
	return letter;
}




void printTime() //输出时间
{
	gettimeofday(&now, NULL);
	double difference = ((double)now.tv_usec - (double)start.tv_usec) / 1000000;
	printf("| %8.4fs    | ", difference);
}

//生产者操作
void *Producer(void *arg)
{
	int i,j;
	int count = 0;
	for (j = 0; j < N_Worktime; j++) //每个线程操作10次
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		//随机等待一段时间(0~99微秒)
		usleep(get_rand_num());
		//向缓冲区添加数据
		char c = get_rand_letter();
		bf.str[bf.in] = c;
		bf.in = (bf.in + 1) % MAX_BUFFER_SIZE;
		bf.is_empty = 0;
		bf.num++;
		int first, last;
		//打印时间
		printTime();
		//打印缓冲区数据
		if (bf.in - 1 >= bf.out)
			last = bf.in - 1;
		else
			last = bf.in - 1 + MAX_BUFFER_SIZE;
		for (first = bf.out; bf.num>0&&first <= last; first++)
		{
			printf("%c ", bf.str[first % MAX_BUFFER_SIZE]);
		}
		int k;
		for (k = bf.num; k <= MAX_BUFFER_SIZE; k++)
		{
			printf("  ");
		}
		printf("|");
		//打印进程编号和产生数据
		printf("   生产者线程%d  |      生产%c       |\n",*(int*)arg, c);
		sem_post(&mutex);
		sem_post(&full);
	}
	return (void*)0;
}

//消费者操作
void *Consumer(void *arg)
{
	int i, j;
	int count = 0;
	for (j = 0; j < N_Worktime; j++) //每个线程操作10次
	{
		sem_wait(&full);
                sem_wait(&mutex);
		//随机等待一段时间(0~99微秒)
		usleep(get_rand_num());
		//从缓冲区取走数据
		char c = bf.str[bf.out];
		bf.out = (bf.out + 1) % MAX_BUFFER_SIZE;
		bf.is_empty = (bf.out == bf.in);
		bf.num--;
		int first, last;
		//打印时间
		printTime();
		//打印缓冲区数据
		if (bf.in - 1 >= bf.out)
			last = bf.in - 1;
		else
			last = bf.in - 1 + MAX_BUFFER_SIZE;
		for (first = bf.out; bf.num>0&&first <= last; first++)
		{
			printf("%c ", bf.str[first % MAX_BUFFER_SIZE]);
		}
		int k;
		for (k = bf.num; k <= MAX_BUFFER_SIZE; k++)
		{
			printf("  ");
		}
		printf("|");
		//打印进程编号和消费数据
		printf("   消费者线程%d  |      消费%c       |\n", *(int*)arg, c);
		sem_post(&mutex);
		sem_posrt(&empty);
	}
	return (void*)0;
}

int main()
{

	printf("| 线程执行时间 |      缓冲区数据       | 当前执行的线程 | 产生或消费的数据 |\n");
	printf("----------------------------------------------------------------------------\n");
	gettimeofday(&start, NULL); //获取开始运行的时间（1970年1月1日到现在的秒和微秒）

	//创建并初始化3个信号量
	if (sem_init(&full, 0, 0) < 0)
	{
		perror("创建信号量SEM_FULL失败!\n");
		exit(1);
	}
	if (sem_init(&empty, 0, 10) < 0)
	{
		perror("创建信号量SEM_EMPTY失败!\n");
		exit(1);
	}
	if (sem_init(&mutex, 0, 1) < 0)
	{
		perror("创建信号量MUTEX失败!\n");
		exit(1);
	}

	//初始化缓冲区

	memset(bf.str, '\0', sizeof(bf.str));
	bf.out = 0;
	bf.in = 0;
	bf.is_empty = 1;
	bf.num = 0;

	//定义4个线程
	pthread_t producer0;
	pthread_t producer1;
	pthread_t consumer0;
	pthread_t consumer1;

	int arg0 = 0, arg1 = 1; //传入函数的参数（代表进程编号）

	//创建线程
	if (pthread_create(&producer0, NULL, Producer, &arg0) != 0)
	{
		perror("创建生产者线程失败！\n");
		exit(1);
	}
	if (pthread_create(&producer1, NULL, Producer, &arg1) != 0)
	{
		perror("创建生产者线程失败！\n");
		exit(1);
	}
	if (pthread_create(&consumer0, NULL, Consumer, &arg0) != 0)
	{
		perror("创建消费者线程失败！\n");
		exit(1);
	}
	if (pthread_create(&consumer1, NULL, Consumer, &arg1) != 0)
	{
		perror("创建消费者线程失败！\n");
		exit(1);
	}
	//ret:接收函数pthread_join中被等待线程的返回值
	int  ret1,ret2,ret3,ret4;
	pthread_join(producer0, (void **)&ret1);
	pthread_join(producer1, (void **)&ret2);
	pthread_join(consumer0, (void **)&ret3);
	pthread_join(consumer1, (void **)&ret4);

	printf("----------------------------------------------------------------------------\n");
	printf("程序结束!\n");

	return 0;
}