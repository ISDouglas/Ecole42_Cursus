/* #include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig)
{
	printf("Received SIGINT! Exiting...\n");
	_exit(0);
}

int main()
{
	// 注册 SIGINT 信号的处理函数
	signal(SIGINT, handle_sigint);

	// 无限循环，等待信号
	while (1)
	{
		printf("Waiting for signal...\n");
		sleep(1);
	}

	return 0;
} */

/* #include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig)
{
	// Ignore the default behavior of SIGINT, preventing ^C from being shown
	signal(SIGINT, SIG_IGN);

	printf("Received SIGINT! Exiting...\n");
	_exit(0);
}

int main()
{
	// Register SIGINT signal handler
	signal(SIGINT, handle_sigint);

	// Infinite loop, waiting for signals
	while (1)
	{
		printf("Waiting for signal...\n");
		sleep(1);
	}

	return 0;
} */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig)
{
	// Ignore the default behavior of SIGINT, preventing ^C from being shown
	printf("Received SIGINT! Exiting...\n");
	_exit(0);
}

int main()
{
	struct sigaction sa;

	// Set up the sigaction struct
	sa.sa_handler = handle_sigint;
	sa.sa_flags = 0;		  // No special flags
	sigemptyset(&sa.sa_mask); // No additional signals to block

	// Register the SIGINT handler
	sigaction(SIGINT, &sa, NULL);

	// Infinite loop, waiting for signals
	while (1)
	{
		printf("Waiting for signal...\n");
		sleep(1);
	}

	return 0;
}
