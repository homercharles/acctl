/*
 * =====================================================================================
 *
 *       Filename:  arg.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月18日 17时37分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jianxi sun (jianxi), ycsunjane@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __ARG_H__
#define __ARG_H__
#include <netinet/in.h>
#include <linux/if_ether.h>
#include <net/if.h>
#include <getopt.h>

#define ACPORT 	(7960)
struct arg_t {
	int 	port;
#ifdef SERVER
	int  	brditv;
	int 	reschkitv;
#endif
#ifdef CLIENT
	int 	reportitv; 
	struct  sockaddr_in acaddr;
#endif
	int 	msgitv;
	char 	nic[IFNAMSIZ];
	char 	mac[ETH_ALEN];
	struct  sockaddr_in addr;
};

enum {
	ARG_DEBUG = 1,
	ARG_WARN,
	ARG_LOCK,
};

extern struct arg_t argument;
extern int debug;
extern int daemon_mode;

void help();
void proc_cfgarg();
void proc_cmdarg(int argc, char *argv[]);
void proc_arg(int argc, char *argv[]);
#endif /* __ARG_H__ */
