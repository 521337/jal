#ifndef STAT_H
#define STAT_H

struct stat {
	unsigned long st_dev;
    unsigned long st_ino;
	unsigned long st_nlink;

	unsigned int  st_mode;
	unsigned int  st_uid;
	unsigned int  st_gid;
	unsigned int  __pad0;
	unsigned long st_rdev;
	long		  st_size;
	long		  st_blksize;
	long		  st_blocks;	/* Number 512-byte blocks allocated. */

	unsigned long st_atime;
	unsigned long st_atime_nsec;
	unsigned long st_mtime;
	unsigned long st_mtime_nsec;
	unsigned long st_ctime;
	unsigned long st_ctime_nsec;
	long 		  __unused[3];
};

#endif // STAT_H
