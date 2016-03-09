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
   int lowpriorityrun = 0;
   int highpriorityrun = 0;
   int rc = fork();
   int i;
   if(rc == 0)
   {
	spin();
	spin();
	sleep(500);
	exit();
   }
   sleep(100);
   check(setpri(2) == 0, "setpri");
   check(getpinfo(&st_before) == 0, "getpinfo");
   printf(1, "\n ****PInfo before**** \n");
   print(&st_before);
   sleep(500);  
   check(getpinfo(&st_after) == 0, "getpinfo");
   printf(1, "\n ****PInfo after**** \n");
   print(&st_after);
   for(i = 0; i < NPROC; ++i)
   {
	if(st_before.pid[i] == rc && st_after.pid[i] == rc)
	{
		if(st_before.lticks[i] < st_after.lticks[i])
			lowpriorityrun = 1;
		if(st_before.hticks[i] < st_after.hticks[i])
			highpriorityrun = 1;
	}		
   }
   check(highpriorityrun == 0, "Expected no high priority ticks when low priority running");
   check(lowpriorityrun == 1, "Expected low priority process to have run when high priority process was put to sleep");
   wait();
   printf(1, "Should print 1 then 2"); 
   exit();
}
