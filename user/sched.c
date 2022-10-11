//
// Created by os on 12/31/21.
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void usage_msg() {
    fprintf(2, "Usage: sched sjf preemptive({0, 1}) alpha([0, 100]) t0([0, ...])\n");
    fprintf(2, "Usage: sched cfs\n");
}

int main(int argc, char *argv[]) {

    if(argc < 2){
        usage_msg();
        exit(1);
    }

    if (!strcmp(argv[1], "sjf")) {
        if (argc != 5) {
            usage_msg();
            exit(1);
        }

        int p = atoi(argv[2]);
        int a = atoi(argv[3]);
        int t = atoi(argv[4]);

        if (p < 0 || a < 0 || t < 0 || p > 1 || a > 100) {
            usage_msg();
            exit(1);
        }

        set_sched_sjf(p, a, t);
    }
    else if (!strcmp(argv[1], "cfs")) {
        if (argc != 2) {
            usage_msg();
            exit(1);
        }

        set_sched_cfs();
    }
    else {
        usage_msg();
        exit(1);
    }

    exit(0);

}