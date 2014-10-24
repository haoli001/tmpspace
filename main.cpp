#include <reg51.h>

sbit KEY=P3^3;

bit flag1=0;
void init_int1(){
    
    IT1=0;
    EA=1;
    
    EX1=1;
    
}



void delay(unsigned int i){
    
    for(; i>0;i--);
    
}

int  f(int tmpp,int flag){
    
    P2=tmpp;
    int tmppp=tmpp;
    delay(5000);
    if(!flag){
        
        //tmpp<<=1;
        tmpp-=tmppp&0xf;
        tmpp+=tmppp&0xf0;
        
        //if(tmpp!=0xfe)tmpp|=1;
        if(!(tmpp&0xff))tmpp=0x7e;
        
    }
    
    else  {
        
        //tmpp>>=1;
        tmpp+=tmppp&0xf;
        tmpp-=tmppp&0xf0;
        
        //if(tmpp!=0x7f)tmpp|=0x80; }
        if((tmpp&0xff)==0x7e)tmpp=0xe7;
    
    return tmpp&0xff;
    
}

void int1_service(void) interrupt 2{
    
    delay(1000);
    
    if(KEY==0){
        EX1=0;
        flag1=1;
        
    }
    
}
int main(){
    
    int flag=0;
    unsigned int tmp=0x18;
    P2=0; 
    init_int1();
    while(1){
        tmp=f(tmp,flag);
        if(flag1){ 	
            while(KEY==0)tmp=f(tmp,flag);
            flag=flag^1;
            flag1=0;
            EX1=1;			
        }
    }
    return 0;
    
}