#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int s=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in saddr;
    
    saddr.sin_family=AF_INET;
    saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    saddr.sin_port=htons(1999);
    
    socklen_t slen=sizeof(saddr);
    
    connect(s,(struct sockaddr*)&saddr,slen);
    
    char b[1024];
    
    while(1)
    {
        char b[1024];
        char b1[1024];
        recv(s,b1,sizeof(b1),0);
        printf("Message from server : %s\n", b1);
        
        fgets(b,sizeof(b),stdin);
        send(s,b,sizeof(b),0);
        
        
    }
    

    
    close(s);
}
