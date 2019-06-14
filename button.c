#include "button.h"


void scan_button()
{
    unsigned int counter;
    if(BTN_1 == 0){
       counter++; 
    }else{
        if(BTN_1 == 1){
            if(counter != 0){
                counter = 0;
            }
        }
    }
    
    else if(BTN_2 == 0){

    }else if(BTN_3 == 0){

    }
}

void handle_button()
{

}
