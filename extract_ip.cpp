#include <iostream>

using namespace std;


#define MAX_CNT 1024

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
/*
    0                   1                   2                   3   
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |Ver= 4 |IHL= 5 |Type of Service|       Total Length = 276      |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |     Identification = 111      |Flg=1|     Fragment Offset = 0 |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |   Time = 119  | Protocol = 6  |        Header Checksum        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                         source address                        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                      destination address                      |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                             data                              |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                             data                              |
   \                                                               \
   \                                                               \
   |                             data                              |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                             data                              |
*/
typedef struct ip_hdr
{
    uint8 ip_version : 4;
    uint8 ip_header_len : 4;
    uint8 service_tyoe;
    uint16 total_len;
    uint16 id;
    uint16 flg;
    uint8 time : 4;
    uint8 protocol :4;
    uint16 header_checksum;
    uint32 src;
    uint32 dest;
}IPV4_HDR;

int main()
{
    const char* pack_name = "ip_packet";
    FILE *fp = fopen(pack_name,"r");
    if(fp==NULL)
    {
        exit(1);
    }
    char buf [MAX_CNT]={0};
    //read one line
    fgets(buf,1,fp);

    IPV4_HDR* ip_header = (IPV4_HDR*)buf;
    //resolve ip address
    uint32 ip_src=ip_header->src;
    uint32 ip_dest=ip_header->dest;
    //convert ip to string

    
    if(fp!=NULL)
    {
        fclose(fp);
    }
    return 0;
}