import toolspath
from testing import Xv6Build, Xv6Test

class Scheduling1(Xv6Test):
   name = "getpinfo"
   description = "call getpinfo() from a user program \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/getpinfo.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 10

class Scheduling2(Xv6Test):
   name = "setpri"
   description = "call setpri() from a user program \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/setpri.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 10

class Scheduling3(Xv6Test):
   name = "processesinuse"
   description = "check number of processes in use by calling getpinfo() \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/processesinuse.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 20

class Scheduling4(Xv6Test):
   name = "default_priority"
   description = "check default priority set for processes by measuring hticks \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/default_priority.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 20

class Scheduling5(Xv6Test):
   name = "check_hticks"
   description = "check if hticks being incremented for high priority process \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/check_hticks.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 20

class Scheduling6(Xv6Test):
   name = "change_priority"
   description = "check if hticks and lticks being incremented as expected when the priority is changed back and forth \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/change_priority.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 20


class Scheduling7(Xv6Test):
   name = "run_high_priority"
   description = "check no low priority processes are running when there is high priority \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/run_high_priority.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 20

class Scheduling8(Xv6Test):
   name = "sleep_high_priority"
   description = "check if low priority processes run when high priority is put to sleep \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/sleep_high_priority.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 20

class Scheduling9(Xv6Test):
   name = "awake_high_priority"
   description = "check if only high priority process run when high priority is awake from sleep \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/awake_high_priority.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 20

class Scheduling10(Xv6Test):
   name = "multiple_high_priority"
   description = "check if multiple high priority processes run in round robin \n The corresponding test file is at ~cs537-1/ta/tests/2b/ctests/multiple_high_priority.c"
   tester = "ctests/" + name + ".c"
   make_qemu_args = "CPUS=1"
   point_value = 20


import toolspath
from testing.runtests import main
main(Xv6Build, [Scheduling1, Scheduling2, Scheduling3, Scheduling4, Scheduling5, Scheduling6, Scheduling7, Scheduling8, Scheduling9, Scheduling10])
