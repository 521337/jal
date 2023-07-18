struct iovec
{
	void  *iov_base;	/* BSD uses caddr_t (1003.1g requires void *) */
	size_t iov_len; /* Must be size_t (1003.1g) */
};
