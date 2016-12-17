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
    if(ev ==MG_EV_ACCEPT){
            mg_send(nc, &(nc->recv_mbuf), nc->recv_mbuf.len);
            cout<<"man it's \n";
    };
    
}

int main(int argc, const char * argv[]) {
    cout << "Hello, there! :>)";
    struct mg_mgr mgr;
    mg_mgr_init(&mgr, NULL);
    mg_bind(&mgr, "1234",&ev_handler);
    
    for ( ; ; ) {
        mg_mgr_poll(&mgr, 1000);
    }
    mg_mgr_free(&mgr);
    
    
    return 0;
}
