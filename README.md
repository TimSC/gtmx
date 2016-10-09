GTMX
====

GTMX provides the ability to have a GT.M process run with an arbitary process name.  The desired process name is passed as an argument to the gtmrun script along with the name of the routine to be run.  If a process name is not specified then the name of the routine is used as the process name.

GTMX works by having a C executable called gtmrunx that simply runs whatever is in it's .ci file under the entry "gtm".  A script called gtmrun copies gtmrunx into a bin folder and names it whatever name the desired process name should be.  It also creates a .ci file, sets up the GTMCI environment variable to point to the .ci file, and then invokes the renamed copy of the gtmrunx binary.

So, for example, to run the %G routine as a process called global_list you can invoke 

gtmx/gtmrun ^%D global_list

In the process list this process will appear as a process named gtmx/bin/global_list.

If the gtmrun script is called with no specified process name then it will appear in the process list as gtmx/bin/^%G.

A routine called direct.m is also provided that simply places the process in programmer mode.  If this is invoked as gtmx/gtmrun ^direct gtm then a direct mode programmer shell will be created that has a process name of simply gtm.  To use this programmer mode shell then either the gtmx directory needs to be in the gtmroutines path or direct.m should be moved to a folder that is already in the gtmroutines path.

A make file is provided to compile and link gtmrunx.c.

