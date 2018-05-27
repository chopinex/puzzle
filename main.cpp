#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define tam 4
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESCAPE 27

using namespace std;
int tablero[tam][tam]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int fil=3;
int col=3;
int *hueco;

void intercambio(int (*p)[tam]){
    int temp;
    int dir;
    for(int i=0;i<100;i++){
        dir=rand()%4;
        switch(dir){
        case 0:
            if(fil>0){
                temp=*(*(p+fil)+col);
                *(*(p+fil)+col)=*(*(p+(fil-1))+col);
                *(*(p+(fil-1))+col)=temp;
                fil--;
            }break;
        case 1:
            if(col<tam-1){
                temp=*(*(p+fil)+col);
                *(*(p+fil)+col)=*(*(p+fil)+(col+1));
                *(*(p+fil)+(col+1))=temp;
                col++;
            }break;
        case 2:
            if(fil<tam-1){
                temp=*(*(p+fil)+col);
                *(*(p+fil)+col)=*(*(p+(fil+1))+col);
                *(*(p+(fil+1))+col)=temp;
                fil++;
            }break;
        case 3:
            if(col>0){
                temp=*(*(p+fil)+col);
                *(*(p+fil)+col)=*(*(p+fil)+(col-1));
                *(*(p+fil)+(col-1))=temp;
                col--;
            }break;
        }
    }
    hueco=*(p+fil)+col;
}

void recorrer(int (*p)[tam]){
    int *ptr=*p;
    int i=0;
    while(ptr<*p+(tam*tam)){
        cout<<"|";
        while(ptr<*(p+i)+tam){
            if(*ptr==0)
                cout <<"  |";
            else{
                if(*ptr<10)
                    cout <<" "<<*ptr<<"|";
                else
                    cout <<*ptr<<"|";
            }
            ptr++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl;
}

bool gano(int (*p)[tam]){
    int val=0;
    while (val<15){
        if(*(*p+val)!=val+1)
            return false;
        val++;
    }
    cout<<"MAESTRO!!"<<endl;
    return true;
}

void juego(int (*p)[tam]){
    int temp;
    int KB_code=0;
    while(KB_code != KEY_ESCAPE ){
        KB_code = getch();
        //if (kbhit()){
            switch(KB_code) {
            case KEY_UP:
                if(hueco-tam>=*p){
                    temp=*hueco;
                    *hueco=*(hueco-tam);
                    *(hueco-tam)=temp;
                    hueco=hueco-tam;
                    recorrer(p);
                    if(gano(p))
                        KB_code=KEY_ESCAPE;
                }
                break;
            case KEY_DOWN:
                if(hueco+tam<*(p+tam)){
                    temp=*hueco;
                    *hueco=*(hueco+tam);
                    *(hueco+tam)=temp;
                    hueco=hueco+tam;
                    recorrer(p);
                    if(gano(p))
                        KB_code=KEY_ESCAPE;
                }
                break;
            case KEY_RIGHT:
                if(hueco+1<*(p+(hueco-*p)/tam+1)){
                    temp=*hueco;
                    *hueco=*(hueco+1);
                    *(hueco+1)=temp;
                    hueco=hueco+1;
                    recorrer(p);
                    if(gano(p))
                        KB_code=KEY_ESCAPE;
                }
                break;
            case KEY_LEFT:
                if(hueco-1>=*(p+(hueco-*p)/tam)){
                    temp=*hueco;
                    *hueco=*(hueco-1);
                    *(hueco-1)=temp;
                    hueco=hueco-1;
                    recorrer(p);
                    if(gano(p))
                        KB_code=KEY_ESCAPE;
                }
                break;
            }
        //}
    }
}

int main(){
    srand (time(NULL));
    int (*punt)[tam]=tablero;
    //recorrer(punt);
    //cout<<endl;
    intercambio(punt);
    recorrer(punt);
    punt=tablero;
    juego(punt);
    return 0;
}
