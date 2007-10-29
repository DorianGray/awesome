/*
 * awesome-client.c - awesome client, communicate with socket
 *
 * Copyright © 2007 Julien Danjou <julien@danjou.info>
 * Copyright © 2007 daniel@brinkers.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "awesome-client.h"
#include "util.h"

int
main()
{
    struct sockaddr_un *addr;
    char buf[1024];
    int csfd;
    
    csfd = get_client_socket();
    addr = get_client_addr();

    while(fgets(buf, sizeof(buf), stdin))
        if(sendto(csfd, buf, a_strlen(buf), MSG_NOSIGNAL,
                  (const struct sockaddr *) addr, sizeof(struct sockaddr_un)) == -1)
            perror("error sending datagram");

    return EXIT_SUCCESS;
}
// vim: filetype=c:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:encoding=utf-8:textwidth=99
