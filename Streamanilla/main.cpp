//
//  main.cpp
//  Streamanilla
//
//  Created by Dmitry Chaban on 12/17/16.
//  Copyright © 2016 dmi3coder. All rights reserved.
//

#include <iostream>
#include "mongoose.h"
using namespace std;

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
    struct mbuf *io = &nc->recv_mbuf;
    
    static int a = 1;
    switch (ev) {
        case MG_EV_ACCEPT:
            cout<<"man it's \n";
            break;
        case MG_EV_SEND:
            cout << "MG_EV_SEND dude,for real! "<< a++ << endl;
            break;
        case MG_EV_RECV:
            // This event handler implements simple TCP echo server
            mg_send(nc, io->buf, io->len);  // Echo received data back
            mbuf_remove(io, io->len);      // Discard data from recv buffer
            break;
        default:
            break;
    }
    
}

int main(int argc, const char * argv[]) {
    cout << "Hello, there! :>)";
    struct mg_mgr mgr;
    mg_mgr_init(&mgr, NULL);
    mg_bind(&mgr, "tcp://192.168.0.100:1234",&ev_handler);
    
    for ( ; ; ) {
        mg_mgr_poll(&mgr, 1000);
    }
    mg_mgr_free(&mgr);
    
    
    return 0;
}
