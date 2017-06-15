#include <pthread.h>
#include <stdio.h>


struct count_number_params
{
int number;
int sum;
};

void* count_number(void* parameters) 
{
struct count_number_params* p = (struct count_number_params*)parameters;
p->sum=0;
for (int i = 0; i < p->number; ++i)
	{
	p->sum+=i;
}
}

int main() 
{
pthread_t thread1_id;
struct count_number_params thread1_args;
printf("%s\n", "Enter your number: ");
scanf("%i", &thread1_args.number);
pthread_create(&thread1_id, NULL, &count_number, &thread1_args);
pthread_join (thread1_id, NULL);
printf("The result is %d.\n", thread1_args.sum);
return 0;
}