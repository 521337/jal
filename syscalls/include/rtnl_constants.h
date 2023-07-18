/* Types of messages */

#define RTM_NEWLINK	16
#define RTM_DELLINK	17
#define RTM_GETLINK	18
#define RTM_SETLINK	19

#define RTM_NEWADDR	20
#define RTM_DELADDR	21
#define RTM_GETADDR	22

#define RTM_NEWROUTE 24
#define RTM_DELROUTE 25
#define RTM_GETROUTE 26

#define RTM_NEWNEIGH 28
#define RTM_DELNEIGH 29
#define RTM_GETNEIGH 30

#define RTM_NEWRULE	32
#define RTM_DELRULE	33
#define RTM_GETRULE	34

#define RTM_NEWQDISC 36
#define RTM_DELQDISC 37
#define RTM_GETQDISC 38

#define RTM_NEWTCLASS 40
#define RTM_DELTCLASS 41
#define RTM_GETTCLASS 42

#define RTM_NEWTFILTER 44
#define RTM_DELTFILTER 45
#define RTM_GETTFILTER 46

#define RTM_NEWACTION 48
#define RTM_DELACTION 49
#define RTM_GETACTION 50

#define RTM_NEWPREFIX 52

#define RTM_GETMULTICAST 58

#define RTM_GETANYCAST 62

#define RTM_NEWNEIGHTBL	64
#define RTM_GETNEIGHTBL	66
#define RTM_SETNEIGHTBL	67

#define RTM_NEWNDUSEROPT 68

#define RTM_NEWADDRLABEL 72
#define RTM_DELADDRLABEL 73
#define RTM_GETADDRLABEL 74

#define RTM_GETDCB 78
#define RTM_SETDCB 79

#define RTM_NEWNETCONF 80
#define RTM_DELNETCONF 81
#define RTM_GETNETCONF 82

#define RTM_NEWMDB 84
#define RTM_DELMDB 85
#define RTM_GETMDB 86

#define RTM_NEWNSID 88
#define RTM_DELNSID 89
#define RTM_GETNSID 90

#define RTM_NEWSTATS 92
#define RTM_GETSTATS 94
#define RTM_SETSTATS 95

#define RTM_NEWCACHEREPORT 96

#define RTM_NEWCHAIN 100
#define RTM_DELCHAIN 101
#define RTM_GETCHAIN 102

#define RTM_NEWNEXTHOP 104
#define RTM_DELNEXTHOP 105
#define RTM_GETNEXTHOP 106

#define RTM_NEWLINKPROP	108
#define RTM_DELLINKPROP	109
#define RTM_GETLINKPROP	110

#define RTM_NEWNVLAN 112
#define RTM_DELVLAN	113
#define RTM_GETVLAN	114

#define RTM_NEWNEXTHOPBUCKET 116
#define RTM_DELNEXTHOPBUCKET 117
#define RTM_GETNEXTHOPBUCKET 118

#define RTM_NEWTUNNEL 120
#define RTM_DELTUNNEL 121
#define RTM_GETTUNNEL 122

/*****************************************************************
 *		Link layer specific messages.
 ****/

/* struct ifinfomsg
 * passes link level specific information, not dependent
 * on network protocol.
 */

struct ifinfomsg {
	unsigned char	ifi_family;
	unsigned char	__ifi_pad;
	unsigned short	ifi_type;		/* ARPHRD_* */
	int		ifi_index;		/* Link index	*/
	unsigned	ifi_flags;		/* IFF_* flags	*/
	unsigned	ifi_change;		/* IFF_* change mask */
};

/****
 *		General form of address family dependent message.
 ****/

struct rtgenmsg {
	unsigned char		rtgen_family;
};

struct nlattr {
    uint16_t           nla_len;
    uint16_t           nla_type;
};

#define NLA_F_NESTED (1 << 15)


#define NLA_ALIGNTO     4
#define NLA_ALIGN(len)      (((len) + NLA_ALIGNTO - 1) & ~(NLA_ALIGNTO - 1))
#define NLA_HDRLEN  ((int) NLA_ALIGN(sizeof(struct nlattr)))

