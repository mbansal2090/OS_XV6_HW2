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
   check(setpri(1) == 0, "setpri to 1");
   check(setpri(2) == 0, "setpri to 2");
   check(setpri(-1) == -1, "setpri to <0");
   check(setpri(10) == -1, "setpri to 10");
   printf(1, "Should print 1 then 2");
   exit();
}
