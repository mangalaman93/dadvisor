#include "dadvisor.h"

/* this file is evpath/examples/net_send.c */
int main(int argc, char **argv)
{
    CManager cm;
    usage_info data;
    EVstone stone;
    EVsource source;
    char string_list[2048];
    attr_list contact_list;
    EVstone remote_stone;

    if(sscanf(argv[1], "%d:%s", &remote_stone, &string_list[0]) != 2) {
	   printf("Bad arguments \"%s\"\n", argv[1]);
	   exit(0);
    }

    cm = CManager_create();
    CMlisten(cm);

    stone = EValloc_stone(cm);
    contact_list = attr_list_from_string(string_list);
    EVassoc_bridge_action(cm, stone, contact_list, remote_stone);

    source = EVcreate_submit_handle(cm, stone, simple_format_list);
    LProcess lp("client", "eth0", "", atoi(argv[2]));
    lp.setHardCpuShares(100);
    lp.setNetworkInBW(1000);
    lp.setNetworkOutBW(100);

    data.id = "client";
    data.cpu_usage = 100;
    data.network_in_usage = 1000;
    data.network_out_usage = 100;
    EVsubmit(source, &data, NULL);
    while(true) {
        sleep(TRIGGER_PERIOD);
        data.cpu_usage = lp.getCpuUsage();
        data.network_in_usage = lp.getNetworkInUsage();
        data.network_out_usage = lp.getNetworkOutUsage();
        EVsubmit(source, &data, NULL);
    }

    return 0;
}