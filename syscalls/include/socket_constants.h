#ifndef SOCKET_CONSTANTS_H
#define SOCKET_CONSTANTS_H

#include "ip_constants.h" // Things that have to do with IP sockets.

/* Protocol families.  */
#define PF_UNSPEC	0	/* Unspecified.  */
#define PF_LOCAL	1	/* Local to host (pipes and file-domain).  */
#define PF_UNIX		PF_LOCAL /* POSIX name for PF_LOCAL.  */
#define PF_FILE		PF_LOCAL /* Another non-standard name for PF_LOCAL.  */
#define PF_INET		2	/* IP protocol family.  */
#define PF_AX25		3	/* Amateur Radio AX.25.  */
#define PF_IPX		4	/* Novell Internet Protocol.  */
#define PF_APPLETALK	5	/* Appletalk DDP.  */
#define PF_NETROM	6	/* Amateur radio NetROM.  */
#define PF_BRIDGE	7	/* Multiprotocol bridge.  */
#define PF_ATMPVC	8	/* ATM PVCs.  */
#define PF_X25		9	/* Reserved for X.25 project.  */
#define PF_INET6	10	/* IP version 6.  */
#define PF_ROSE		11	/* Amateur Radio X.25 PLP.  */
#define PF_DECnet	12	/* Reserved for DECnet project.  */
#define PF_NETBEUI	13	/* Reserved for 802.2LLC project.  */
#define PF_SECURITY	14	/* Security callback pseudo AF.  */
#define PF_KEY		15	/* PF_KEY key management API.  */
#define PF_NETLINK	16
#define PF_ROUTE	PF_NETLINK /* Alias to emulate 4.4BSD.  */
#define PF_PACKET	17	/* Packet family.  */
#define PF_ASH		18	/* Ash.  */
#define PF_ECONET	19	/* Acorn Econet.  */
#define PF_ATMSVC	20	/* ATM SVCs.  */
#define PF_RDS		21	/* RDS sockets.  */
#define PF_SNA		22	/* Linux SNA Project */
#define PF_IRDA		23	/* IRDA sockets.  */
#define PF_PPPOX	24	/* PPPoX sockets.  */
#define PF_WANPIPE	25	/* Wanpipe API sockets.  */
#define PF_LLC		26	/* Linux LLC.  */
#define PF_IB		27	/* Native InfiniBand address.  */
#define PF_MPLS		28	/* MPLS.  */
#define PF_CAN		29	/* Controller Area Network.  */
#define PF_TIPC		30	/* TIPC sockets.  */
#define PF_BLUETOOTH	31	/* Bluetooth sockets.  */
#define PF_IUCV		32	/* IUCV sockets.  */
#define PF_RXRPC	33	/* RxRPC sockets.  */
#define PF_ISDN		34	/* mISDN sockets.  */
#define PF_PHONET	35	/* Phonet sockets.  */
#define PF_IEEE802154	36	/* IEEE 802.15.4 sockets.  */
#define PF_CAIF		37	/* CAIF sockets.  */
#define PF_ALG		38	/* Algorithm sockets.  */
#define PF_NFC		39	/* NFC sockets.  */
#define PF_VSOCK	40	/* vSockets.  */
#define PF_KCM		41	/* Kernel Connection Multiplexor.  */
#define PF_QIPCRTR	42	/* Qualcomm IPC Router.  */
#define PF_SMC		43	/* SMC sockets.  */
#define PF_XDP		44	/* XDP sockets.  */
#define PF_MCTP		45	/* Management component transport protocol.  */
#define PF_MAX		46	/* For now..  */

/* Address families.  */
#define AF_UNSPEC	PF_UNSPEC
#define AF_LOCAL	PF_LOCAL
#define AF_UNIX		PF_UNIX
#define AF_FILE		PF_FILE
#define AF_INET		PF_INET
#define AF_AX25		PF_AX25
#define AF_IPX		PF_IPX
#define AF_APPLETALK	PF_APPLETALK
#define AF_NETROM	PF_NETROM
#define AF_BRIDGE	PF_BRIDGE
#define AF_ATMPVC	PF_ATMPVC
#define AF_X25		PF_X25
#define AF_INET6	PF_INET6
#define AF_ROSE		PF_ROSE
#define AF_DECnet	PF_DECnet
#define AF_NETBEUI	PF_NETBEUI
#define AF_SECURITY	PF_SECURITY
#define AF_KEY		PF_KEY
#define AF_NETLINK	PF_NETLINK
#define AF_ROUTE	PF_ROUTE
#define AF_PACKET	PF_PACKET
#define AF_ASH		PF_ASH
#define AF_ECONET	PF_ECONET
#define AF_ATMSVC	PF_ATMSVC
#define AF_RDS		PF_RDS
#define AF_SNA		PF_SNA
#define AF_IRDA		PF_IRDA
#define AF_PPPOX	PF_PPPOX
#define AF_WANPIPE	PF_WANPIPE
#define AF_LLC		PF_LLC
#define AF_IB		PF_IB
#define AF_MPLS		PF_MPLS
#define AF_CAN		PF_CAN
#define AF_TIPC		PF_TIPC
#define AF_BLUETOOTH	PF_BLUETOOTH
#define AF_IUCV		PF_IUCV
#define AF_RXRPC	PF_RXRPC
#define AF_ISDN		PF_ISDN
#define AF_PHONET	PF_PHONET
#define AF_IEEE802154	PF_IEEE802154
#define AF_CAIF		PF_CAIF
#define AF_ALG		PF_ALG
#define AF_NFC		PF_NFC
#define AF_VSOCK	PF_VSOCK
#define AF_KCM		PF_KCM
#define AF_QIPCRTR	PF_QIPCRTR
#define AF_SMC		PF_SMC
#define AF_XDP		PF_XDP
#define AF_MCTP		PF_MCTP
#define AF_MAX		PF_MAX

#define SOCK_STREAM     1 /* Sequenced, reliable, connection-based byte streams.  */
#define SOCK_DGRAM      2 /* Connectionless, unreliable datagrams of fixed maximum length.  */
#define SOCK_RAW        3 /* Raw protocol interface.  */
#define SOCK_RDM        4 /* Reliably-delivered messages.  */
#define SOCK_SEQPACKET  5 /* Sequenced, reliable, connection-based, datagrams of fixed maximum length.  */
#define SOCK_DCCP       6 /* Datagram Congestion Control Protocol.  */

/* Linux specific way of getting packets
   at the dev level.  For writing rarp and
   other similar things on the user level. */
#define SOCK_PACKET 10

  /* Flags to be ORed into the type parameter of socket and socketpair and
     used for the flags parameter of paccept.  */

#define SOCK_CLOEXEC  02000000 /* Atomically set close-on-exec flag for the new descriptor(s).  */
#define SOCK_NONBLOCK 00004000 /* Atomically mark descriptor(s) as non-blocking.  */


////////////////////////////////////////////////

#define IFNAMSIZ 16
#define IFHWADDRLEN 6

typedef struct {
	unsigned int clock_rate; /* bits per second */
	unsigned int clock_type; /* internal, external, TX-internal etc. */
	unsigned short loopback;
} sync_serial_settings;          /* V.35, V.24, X.21 */

typedef struct {
	unsigned int clock_rate; /* bits per second */
	unsigned int clock_type; /* internal, external, TX-internal etc. */
	unsigned short loopback;
	unsigned int slot_map;
} te1_settings;                  /* T1, E1 */

typedef struct {
	unsigned short encoding;
	unsigned short parity;
} raw_hdlc_proto;

typedef struct {
	unsigned int t391;
	unsigned int t392;
	unsigned int n391;
	unsigned int n392;
	unsigned int n393;
	unsigned short lmi;
	unsigned short dce; /* 1 for DCE (network side) operation */
} fr_proto;

typedef struct {
	unsigned int dlci;
} fr_proto_pvc;          /* for creating/deleting FR PVCs */

typedef struct {
	unsigned int dlci;
	char master[IFNAMSIZ];	/* Name of master FRAD device */
}fr_proto_pvc_info;		/* for returning PVC information only */

typedef struct {
    unsigned int interval;
    unsigned int timeout;
} cisco_proto;



typedef struct {
	unsigned short dce; /* 1 for DCE (network side) operation */
	unsigned int modulo; /* modulo (8 = basic / 128 = extended) */
	unsigned int window; /* frame window size */
	unsigned int t1; /* timeout t1 */
	unsigned int t2; /* timeout t2 */
	unsigned int n2; /* frame retry counter */
} x25_hdlc_proto;

struct if_settings {
    unsigned int type;  /* Type of physical device or protocol */
    unsigned int size;  /* Size of the data allocated by the caller */
    union {
        /* {atm/eth/dsl}_settings anyone ? */
        raw_hdlc_proto      *raw_hdlc;
        cisco_proto     *cisco;
        fr_proto        *fr;
        fr_proto_pvc        *fr_pvc;
        fr_proto_pvc_info   *fr_pvc_info;
        x25_hdlc_proto      *x25;

        /* interface settings */
        sync_serial_settings    *sync;
        te1_settings        *te1;
    } ifs_ifsu;
};

struct ifmap {
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned short base_addr;
    unsigned char irq;
    unsigned char dma;
    unsigned char port;
    /* 3 bytes spare */
};

typedef unsigned short int sa_family_t;

struct sockaddr{
    sa_family_t sa_family;
    char sa_data[14];       /* Address data.  */
};

struct ifreq {
    union
    {
        char    ifrn_name[IFNAMSIZ];        /* if name, e.g. "en0" */
    } ifr_ifrn;

    union {
        struct  sockaddr ifru_addr;
        struct  sockaddr ifru_dstaddr;
        struct  sockaddr ifru_broadaddr;
        struct  sockaddr ifru_netmask;
        struct  sockaddr ifru_hwaddr;
        short   ifru_flags;
        int ifru_ivalue;
        int ifru_mtu;
        struct  ifmap ifru_map;
        char    ifru_slave[IFNAMSIZ];   /* Just fits the size */
        char    ifru_newname[IFNAMSIZ];
        void *  ifru_data;
        struct  if_settings ifru_settings;
    } ifr_ifru;
};

struct ifconf  {
    int ifc_len;            /* size of buffer   */
    union {
        char *ifcu_buf;
        struct ifreq *ifcu_req;
    } ifc_ifcu;
};

#define ifc_buf ifc_ifcu.ifcu_buf
#define ifc_req ifc_ifcu.ifcu_req       /* array of structures  */
#define ifr_name    ifr_ifrn.ifrn_name /* interface name   */

struct iov_iter {
	unsigned char iter_type;
	_Bool nofault;
	_Bool data_source;
	size_t iov_offset;
	size_t count;
	union {
		const struct iovec *iov;
		const struct kvec *kvec;
		const struct bio_vec *bvec;
		struct xarray *xarray;
		struct pipe_inode_info *pipe;
	};
	union {
		unsigned long nr_segs;
		struct {
			unsigned int head;
			unsigned int start_head;
		};
		long long xarray_start;
	};
};

// The message layout that recvmsg uses.
struct msghdr {
	void		*msg_name;	/* ptr to socket address structure */
	int		msg_namelen;	/* size of socket address structure */
	struct iov_iter	msg_iter;	/* data */

	/*
	 * Ancillary data. msg_control_user is the user buffer used for the
	 * recv* side when msg_control_is_user is set, msg_control is the kernel
	 * buffer used for all other cases.
	 */
	union {
		void		*msg_control;
		void *msg_control_user;
	};
	_Bool		msg_control_is_user : 1;
	unsigned long	msg_controllen;	/* ancillary data buffer length */
	unsigned int	msg_flags;	/* flags on received message */
	struct kiocb	*msg_iocb;	/* ptr to iocb for async requests */
};

#endif
