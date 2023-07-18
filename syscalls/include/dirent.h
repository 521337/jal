#ifndef DIRENT_H
#define DIRENT_H

struct linux_dirent64 {
	uint64_t	   d_ino;
	int64_t		   d_off;
	unsigned short d_reclen;
	unsigned char  d_type;
	char		   d_name[];
};

#endif // DIRENT_H