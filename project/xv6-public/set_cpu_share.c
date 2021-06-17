#include "types.h"
#include "defs.h"

int
set_cpu_share(int a)
{
    return a;
}

int
sys_set_cpu_share(void)
{
    int a = 0;
    return set_cpu_share(a);
}
