#include "sys_common.h"
#include "system.h"

#include "can.h"

#include "esm.h"

#define  D_SIZE 9

uint8  tx_data[D_SIZE]  = {'H','E','R','C','U','L','E','S','\0'};
uint8  rx_data[D_SIZE] = {0};
uint32 error = 0;




void main(void)
{

    canInit(); /* can1 -> can2 */

    canTransmit(canREG1, canMESSAGE_BOX1, tx_data);

    while(1){

        if(canIsRxMessageArrived(canREG1, canMESSAGE_BOX2)){
                    canGetData(canREG1, canMESSAGE_BOX2, rx_data);
        }

    }

}
