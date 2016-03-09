#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
#define check(exp, msg) if(exp) {} else {\
   printf(1, "%s:%d check (" #exp ") failed: %s\n", __FILE__, __LINE__, msg);\
   exit();}

void spin()
{
	int i = 0, j = 0, k = 0;
	for(i = 0; i < 50; ++i)
	{
		for(j = 0; j < 10000000; ++j)
		{
			k = j % 10;
		}
	}
}

void print(struct pstat *st)
{
   int i;
   for(i = 0; i < NPROC; i++) {
      if (st->inuse[i]) {
         printf(1, "pid: %d hticks: %d lticks: %d\n", st->pid[i], st->hticks[i], st->lticks[i]);
      }
   }

}


int
main(int argc, char *argv[])
{
 
   struct pstat st_before, st_after;
   int lowpriorityrun = 0, highpriorityrun = 0;
   int rc = fork();
   int i;
   int pid = getpid();
   if(rc == 0)
   {
	spin();
	sleep(200);
	spin();
	exit();
   }
   check(setpri(2) == 0, "setpri");
   if(fork() == 0)
   {
	sleep(200);
	spin();
        sleep(100);
	printf(1, " then 2");
	exit();
   }
   sleep(200);
   check(getpinfo(&st_before) == 0, "getpinfo");
   printf(1, "\n ****PInfo before**** \n");
   print(&st_before);
   spin();
   spin();
   check(getpinfo(&st_after) == 0, "getpinfo");
   printf(1, "\n ****PInfo after**** \n");
   print(&st_after);
   for(i = 0; i < NPROC; ++i)
   {
	if(st_before.pid[i] != pid && st_before.lticks[i] < st_after.lticks[i] && st_before.hticks[i] < st_after.hticks[i])
		lowpriorityrun++;
	if(st_before.hticks[i] < st_after.hticks[i])
		highpriorityrun++;
   }
   check(lowpriorityrun == 0, "Expected only the high priority process to run once it is awake");
   check(highpriorityrun == 1, "Expected one high priority process to run once it is awake");
   printf(1, "Should print 1"); 
   wait();
   wait();
   exit();
}
