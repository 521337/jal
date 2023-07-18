#include  "types.h"

#ifndef NETLINK_CONSTANTS_H
#define NETLINK_CONSTANTS_H

#define NETLINK_ROUTE           0   // Routing/device hook                      
//#define NETLINK_UNUSED        1   // Unused number                           
#define NETLINK_USERSOCK        2   // Reserved for user mode socket protocols 
//#define NETLINK_FIREWALL      3   // Unused number, formerly ip_queue        
#define NETLINK_SOCK_DIAG       4   // socket monitoring                       
//#define NETLINK_NFLOG         5   // netfilter/iptables ULOG                 
#define NETLINK_XFRM            6   // ipsec                                   
#define NETLINK_SELINUX         7   // SELinux event notifications             
#define NETLINK_ISCSI           8   // Open-iSCSI                              
#define NETLINK_AUDIT           9   // auditing                                
#define NETLINK_FIB_LOOKUP      10
#define NETLINK_CONNECTOR       11
#define NETLINK_NETFILTER       12  // netfilter subsystem                     
//#define NETLINK_IP6_FW        13
#define NETLINK_DNRTMSG         14  // DECnet routing messages                 
#define NETLINK_KOBJECT_UEVENT  15  // Kernel messages to userspace            
#define NETLINK_GENERIC         16
// leave room for NETLINK_DM (DM Events)
#define NETLINK_SCSITRANSPORT   18  // SCSI Transports
#define NETLINK_ECRYPTFS        19
#define NETLINK_RDMA            20
#define NETLINK_CRYPTO          21  // Crypto layer
#define NETLINK_SMC             22  // SMC monitoring


#define SOCK_DIAG_BY_FAMILY 20


/* Flags values */

/* Standard flags */
#define NLM_F_REQUEST		0x01	/* It is request message. 	*/
#define NLM_F_MULTI		    0x02	/* Multipart message, terminated by NLMSG_DONE */
#define NLM_F_ACK		    0x04	/* Reply with ack, with zero or error code */
#define NLM_F_ECHO		    0x08	/* Echo this request 		*/
#define NLM_F_DUMP_INTR		0x10	/* Dump was inconsistent due to sequence change */
#define NLM_F_DUMP_FILTERED	0x20	/* Dump was filtered as requested */

/* Modifiers to GET request */
#define NLM_F_ROOT	    0x100	/* specify tree	root	*/
#define NLM_F_MATCH	    0x200	/* return all matching	*/
#define NLM_F_ATOMIC	0x400	/* atomic GET		*/
#define NLM_F_DUMP	(NLM_F_ROOT|NLM_F_MATCH)


// Network link message header
struct nlmsghdr {
    unsigned int   nlmsg_len;    /* Length of message including header */
    unsigned short nlmsg_type;   /* Type of message content */
    unsigned short nlmsg_flags;  /* Additional flags */
    unsigned int   nlmsg_seq;    /* Sequence number */
    unsigned int   nlmsg_pid;    /* Sender port ID */
};

/* Socket identity */
struct inet_diag_sockid {
	uint16_t	idiag_sport;
	uint16_t	idiag_dport;
	uint32_t	idiag_src[4];
	uint32_t	idiag_dst[4];
	uint32_t	idiag_if;
	uint32_t	idiag_cookie[2];
#define INET_DIAG_NOCOOKIE (~0U)
};

/* Base info structure. It contains socket identity (addrs/ports/cookie)
 * and, alas, the information shown by netstat. */
struct inet_diag_msg {
	uint8_t	idiag_family;
	uint8_t	idiag_state;
	uint8_t	idiag_timer;
	uint8_t	idiag_retrans;

	struct inet_diag_sockid id;

	uint32_t	idiag_expires;
	uint32_t	idiag_rqueue;
	uint32_t	idiag_wqueue;
	uint32_t	idiag_uid;
	uint32_t	idiag_inode;
};


struct nlmsgerr {
	int		error;
	struct nlmsghdr msg;
	/*
	 * followed by the message contents unless NETLINK_CAP_ACK was set
	 * or the ACK indicates success (error == 0)
	 * message length is aligned with NLMSG_ALIGN()
	 */
	/*
	 * followed by TLVs defined in enum nlmsgerr_attrs
	 * if NETLINK_EXT_ACK was set
	 */
};

struct sockaddr_nl {
    unsigned short  nl_family;  /* AF_NETLINK */
    unsigned short  nl_pad;     /* Zero */
    int             nl_pid;     /* Port ID */
    unsigned int    nl_groups;  /* Multicast groups mask */
};

#define NLMSG_ALIGNTO	4U
#define NLMSG_ALIGN(len) ( ((len)+NLMSG_ALIGNTO-1) & ~(NLMSG_ALIGNTO-1) )
#define NLMSG_HDRLEN	 ((int) NLMSG_ALIGN(sizeof(struct nlmsghdr)))
#define NLMSG_LENGTH(len) ((len) + NLMSG_HDRLEN)

#endif

