#include <reg51.h>
#define SYSCLK 11059200
#define TCNT 200

bit flag1=0;
void init_intT1(){
    TMOD&=0X10;
    TH1=(65536-SYSCLK/12/TCNT)/256;
    TL1=(65536-SYSCLK/12/TCNT)%256;
    TR1=1;
}

int main(){
    
    unsigned int i=0;
    P2=0;
    init_inT1();
    while(1){
        while(TF1==0);//time =1 go
        TF1=0;
        TH1=(65536-SYSCLK/12/TCNT)/256;
        TL1=(65536-SYSCLK/12/TCNT)%256;
        i++;
        if(i==TCNT){//1s
            P2=~P2;
            i=0;
            
        }
        
    }
    return 0;
    
}