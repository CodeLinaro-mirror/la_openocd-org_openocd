#include <stdio.h>
#include "eud_error_defines.h"
#include "trc_api.h"
#include "device_manager.h"

int main (void)
{
    uint32_t trns_len = 42;
    uint32_t trns_tmout = 0x00EE12EA;
    uint32_t on_time = 30;
    uint32_t device_id=0U;
    uint32_t arr[100] = {0};
    uint32_t len = 0U; 
    EUD_ERR_t err = EUD_SUCCESS;

    //Getting device ID 
    err = get_device_id_array(arr, &len);
    device_id = arr[0];
    if(device_id == 0) {
        printf("\nGet Device ID failed\n");
        return err;
    }
    printf("\nDEVICE ID = 0x%08x\n", device_id);

    err = eud_trace_device_init(device_id, trns_len, trns_tmout, on_time);
    if(EUD_SUCCESS != err) {
        printf("\nInitialise EUD Trace failed with err : %x\n", err );
        goto error;
    }
    printf("\nDone. Initialising EUD trace.\n");

    err = eud_trace_device_read();
    if(EUD_SUCCESS != err) {
        printf("\nCould not read. Failed with err : %x\n", err );
        goto error;
    }
    printf("\nDone. Reading from trace device.\n");

error:
    err = eud_trace_device_close();
    if(EUD_SUCCESS != err) {
        printf("\nCould not Close device failed with err : %x\n", err );
        return err;
    }
    printf("\nDone. Closing the trace device.\n");

    return err; 
}

