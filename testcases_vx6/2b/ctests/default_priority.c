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
	for(i = 0; i < 10; ++i)
	{
		for(j = 0; j < 10000000; j++)
			k = j % 11;
	}
}
int
main(int argc, char *argv[])
{
   struct pstat st;
   int highpriority = 0;
   int pid = getpid();
   int defaultpriorityrun = 0;
   spin();
   check(getpinfo(&st) == 0, "getpinfo");

   int i;
   printf(1, "\n **** PInfo **** \n"); 
   for(i = 0; i < NPROC; i++) {
      if (st.inuse[i]) {
	 if(st.hticks[i] != 0)
		highpriority++;
	 if(st.pid[i] == pid && st.lticks[i] > 20)
		defaultpriorityrun = 1;
         printf(1, "pid: %d hticks: %d lticks: %d\n", st.pid[i], st.hticks[i], st.lticks[i]);
      }
   }

   check(highpriority == 0, "getpinfo shouldn't return any process with hticks not equal to 0, default priority should be low(1) ");
   check(defaultpriorityrun == 1, "getpinfo should return a process having run with default priority");
   printf(1, "Should print 1 then 2");
   exit();
}
