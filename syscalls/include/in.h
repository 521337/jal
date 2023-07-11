#ifndef IN_H
#define IN_H

typedef int socklen_t;

struct sockaddr_in {
  uint16_t sin_family;	/* Address family		*/
  uint16_t sin_port;	/* Port number			*/
  uint32_t sin_addr;	/* Internet address		*/

  /* Pad to size of `struct sockaddr'. */
  uint8_t __pad[8];
};

#endif // IN_H
