#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

#define check(exp, msg) if(exp) {} else {\
   printf(1, "%s:%d check (" #exp ") failed: %s\n", __FILE__, __LINE__, msg);\
   exit();}

int
main(int argc, char *argv[])
{
   struct pstat st;

   check(getpinfo(&st) == 0, "getpinfo");
   printf(1, "\n **** PInfo **** \n");
   int i;
   for(i = 0; i < NPROC; i++) {
      if (st.inuse[i]) {
         printf(1, "pid: %d hticks: %d lticks: %d\n", st.pid[i], st.hticks[i], st.lticks[i]);
      }
   }

   check(getpinfo(NULL) == -1, "getpinfo with bad pointer");
  // printf(1, "Process1 Done\n");
  // printf(1, "Process2 Done\n");
  // printf(1, "Process1 Done\nProcess2 Done\n");
  printf(1, "Should print 1 then 2");
  exit();
}
