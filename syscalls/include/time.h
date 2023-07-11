#ifndef TIME_H
#define TIME_H

typedef signed long time_t;

struct timespec {
	time_t      	tv_sec;		/* seconds */
	long			tv_nsec;	/* nanoseconds */
};

#endif
