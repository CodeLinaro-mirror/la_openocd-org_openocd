#include <stdio.h>
#include <unistd.h>

#include "EudAPI.h"
#include "armdap.h"

// Error bits in CTRL/STAT Register
#define WDATAERR    0x80 
#define STICKYERR   0x20
#define STICKYCMP   0x10
#define STICKYORUN  0x02
#define ORUNDETECT  0x01

// Error clear bits in Abort Register
#define ORUNERRCLR  0x10
#define WDERRCLR    0x8
#define STKERRCLR   0x4
#define STKCMPCLR   0x2

#define C_DEBUGEN   0x1
#define C_HALT      0x2
#define C_STEP      0x4
#define C_MASKINTS  0x10
#define C_SNAPSTALL 0x20
#define S_REGRDY    0x10000
#define S_HALT      0x20000
#define S_SLEEP     0x40000
#define S_LOCKUP    0X80000
#define S_RETIRE_ST 0x1000000
#define S_RESET_ST  0x2000000


void stickyErrClr(uint32_t val);
void readProcessorReg(uint8_t regSel);

swd_eud_device* pSWD = 0x0;

static int eud_swd_read (uint8_t cmd, uint32_t *value, uint32_t ap_delay_hint)
{
    //printf("\neud_swd_read");
    uint32_t APnDP = 0;
    uint32_t A2_3  = 0;
    EUD_ERR_t err;
    uint32_t  val;

    (void) ap_delay_hint;
    APnDP = (cmd >> 1) & 0x1;
    A2_3  = (cmd >> 3) & 0x3;
    err = SWDRead(pSWD, APnDP, A2_3, &val);
    //printf("err = %x\n",err);
    if (err != EUD_SUCCESS)
    {
        printf ("SWD Read FAILED!!");
        return 0;
    }
    else
    {
        if (value != NULL)
            *value = val;
                return 1;
    }

    // if (ap_delay_hint == 0) ap_delay_hint = 0;
}

static int eud_swd_write (uint8_t cmd, uint32_t value, uint32_t ap_delay_hint)
{
    //printf("\neud_swd_write");
    uint32_t APnDP = 0;
    uint32_t A2_3  = 0;
    EUD_ERR_t err;

    (void) ap_delay_hint;
    APnDP = (cmd >> 1) & 0x1;
    A2_3  = (cmd >> 3) & 0x3;

    err = SWDWrite (pSWD, APnDP, A2_3, value);
    //printf("err = %x\n",err);
    if (err != EUD_SUCCESS)
        {
        printf ("SWD Write FAILED!!");
                return 0;
        }

    return 1;
}

int read_dp_dpidr()
{
    uint32_t val;
    EUD_ERR_t   err;

    err = eud_swd_read( 0xa5, &val,0);
//    printf("read DPIDR = %x\n",val);
    return val;
}

void write_dp_abort(uint32_t val)
{
    EUD_ERR_t   err;

    err = eud_swd_write( 0x81, val,0);
//    printf("write ABORT = %x\n", val);
}

void write_dp_select(uint32_t val)
{
    EUD_ERR_t   err;

    err = eud_swd_write( 0xb1,val,0);
//    printf("write SELECT = %x\n", val);
}

int read_dp_ctrl_stat()
{
    uint32_t val;
    EUD_ERR_t   err;

    write_dp_select(0x0);
    err = eud_swd_read( 0x8d, &val ,0);
 //   printf("read CTRL/STAT = %x\n",val);
    return val;
}

int read_dp_target_id()
{
    uint32_t val;
    EUD_ERR_t   err;

    write_dp_select(0x2);
    err = eud_swd_read( 0x8d, &val ,0);
//    printf("read TARGETID = %x\n",val);
    return val;
}

int read_dp_dlpidr()
{
    uint32_t val;
    EUD_ERR_t   err;

    write_dp_select(0x3);
    err = eud_swd_read( 0x8d, &val ,0);
 //   printf("read DLPIDR = %x\n",val);
    return val;
}

int read_dp_event_stat()
{
    uint32_t val;
    EUD_ERR_t   err;

    write_dp_select(0x4);
    err = eud_swd_read( 0x8d, &val ,0);
//    printf("read EVENTSTAT = %x\n",val);
    return val;
}

void write_dp_ctrl_stat(uint32_t val)
{
    EUD_ERR_t   err;

    write_dp_select(0x0);
    err = eud_swd_write( 0xa9,val,0);
//    printf("write CTRL/STAT = %d\n", val);
}

int read_dp_rdbuff()
{
    uint32_t val;
    EUD_ERR_t   err;

    err = eud_swd_read( 0xbd, &val, 0);
//    printf("read RDBUFF = %x\n",val);
    return val;
}

void write_ap_tar_low(int ap_num,uint32_t val)
{
    EUD_ERR_t   err;
    uint32_t bankAddr;
    
    bankAddr = (ap_num<<24);
    write_dp_select(bankAddr);
    err = eud_swd_write( 0x8b,val,0);
    //printf("write TAR_LOW = %x\n");
}

int read_ap_tar_low()
{
    uint32_t val;
    EUD_ERR_t   err;

    err = eud_swd_read( 0xaf, &val,0);
//    printf("\nTAR_LOW = %x\n",val);
    return val;
}

int read_ap_tar_high()
{
    uint32_t val;
    EUD_ERR_t   err;

    err = eud_swd_read( 0xb7, &val,0);
//    printf("\nTAR_HIGH = %x\n",val);
    return val;
}

void write_ap_tar_high(uint32_t val)
{
    EUD_ERR_t   err;

    err = eud_swd_write( 0x93,val,0);
//    printf("\nWrite TAR_HIGH = %x\n", val);
}

int read_ap_data_rw(int ap_num)
{
    uint32_t val,bankAddr;
    EUD_ERR_t   err;

    bankAddr = (ap_num<<24);
    write_dp_select(bankAddr);
    err = eud_swd_read( 0x9f, &val ,0);
    err = eud_swd_read( 0xbd, &val, 0);
    return val;
}

int read_ap_IDR (int ap_num)
{
    uint32_t val;
    uint32_t bankAddr;
    EUD_ERR_t   err;

    bankAddr = (ap_num << 24) + 0xf0;
    write_dp_select (bankAddr);
    err = eud_swd_read (0x9f, &val, 0);
    err = eud_swd_read (0xbd, &val, 0);
    return val;
}

int read_ap_DBGBASE (int ap_num)
{
    uint32_t val;
    uint32_t bankAddr;
    EUD_ERR_t   err;

    bankAddr = (ap_num << 24) + 0xf0;
    write_dp_select (bankAddr);
    err = eud_swd_read (0x97, &val, 0);
    err = eud_swd_read (0xbd, &val, 0);
    return val;
}

int read_ap_DBGBASE_PAE (int ap_num)
{
    uint32_t val;
    uint32_t bankAddr;
    EUD_ERR_t   err;

    bankAddr = (ap_num << 24) + 0xf0;
    write_dp_select (bankAddr);
    err = eud_swd_read (0x87, &val, 0);
    err = eud_swd_read (0xbd, &val, 0);
    return val;
}

int read_ap_CFG (int ap_num)
{
    uint32_t val;
    uint32_t bankAddr;
    EUD_ERR_t   err;

    bankAddr = (ap_num << 24) + 0xf0;
    write_dp_select (bankAddr);
    err = eud_swd_read (0x8f, &val, 0);
    err = eud_swd_read (0xbd, &val, 0);
    return val;
}

void write_ap_csw(int ap_num,uint32_t val)
{
    EUD_ERR_t   err;
    uint32_t bankAddr;
    bankAddr = (ap_num<<24);
    write_dp_select(bankAddr);
    err = eud_swd_write (0xa3, val, 0);
}

int read_ap_csw()
{
    uint32_t val;
    EUD_ERR_t   err;

    write_dp_select(0x0);
    err = eud_swd_read( 0x87, &val ,0);
    err = eud_swd_read( 0xbd, &val, 0);
    return val;
}

void write_ap_data_rw(int ap_num,uint32_t val)
{
    uint32_t bankAddr;
    EUD_ERR_t   err;

    bankAddr = (ap_num<<24);   
    write_dp_select(bankAddr);//0x1000000
    
    err = eud_swd_write( 0xbb, val ,0);
}

void write_ap_bank_reg(uint32_t ad,uint32_t val)
{
    EUD_ERR_t   err;
    uint32_t a2_3= (ad & 0xc);
    uint32_t opcode;
    switch(a2_3)
    {
        case 0x0:
            opcode = 0xa3;
        case 0x4:
            opcode = 0x8b;
        case 0x8:
            opcode = 0x93;
        case 0xc:
            opcode = 0xbb;
    }
    err = eud_swd_write(opcode, val ,0);
}

void write_openocd(int ap_num,uint32_t csw,uint32_t ad,uint32_t val)
{
    write_ap_csw(ap_num,csw);
    uint32_t ad2 = ad & 0xfffffff0;
    write_ap_tar_low(ap_num,ad2);
    uint32_t bankAddr = (ap_num<<24) + (0x10);
    write_dp_select(bankAddr);
    write_ap_bank_reg(ad,val);
}

int read_ap_bank_reg(uint32_t ad)
{
    EUD_ERR_t   err;
    uint32_t a2_3= (ad & 0xc);
    uint32_t opcode,val;
    switch(a2_3)
    {
        case 0x0:
                    opcode = 0x87;
        case 0x4:
                    opcode = 0xaf;
        case 0x8:
                    opcode = 0xb7;
        case 0xc:
                    opcode = 0x9f;
                    
    }
    err = eud_swd_read(opcode, &val ,0);
    err = eud_swd_read (0xbd, &val, 0);
    return val;
}

int read_openocd(int ap_num,uint32_t csw,uint32_t ad)
{
    write_ap_csw(ap_num,csw);
    uint32_t ad2 = ad & 0xfffffff0;
    write_ap_tar_low(ap_num,ad2);
    // Sleep(200);
    usleep (200000);
    uint32_t bankAddr = (ap_num<<24) + (0x10);
    write_dp_select(bankAddr);
    // Sleep(200);
    usleep (200000);
    uint32_t val = read_ap_bank_reg(ad);
    return val;
}

EUD_ERR_t  read_SWI (uint32_t addr, uint32_t* pVal)
{
    EUD_ERR_t  err;

    write_ap_csw(0x0,0x93000002);
    write_ap_tar_low(0x0,addr);
    *pVal = read_ap_data_rw(0x0);
    // printf (" AP -> READ  -> DRW(SOCID)    = 0x%08x\n", val);
    // pVal = read_ap_csw();
    return err;
}

int main()
{
    uint32_t    deviceId, val;
    uint32_t    arr[100] = {0}, len; 
    EUD_ERR_t   err;
    err = GetDeviceIDArray (arr, &len);
    deviceId = arr[0];
    printf ("\nDEVICE = 0x%08x\n", deviceId);
    pSWD = EUDInitializeDeviceSWD (deviceId, 1, &err);
    if (err != EUD_SUCCESS)
       printf ("Initialise FAILED!!\n");
    
    JTAG_to_SWD(pSWD);

    eud_swd_read  (0xa5,       &val, 0);  // READ  = DPIDR      ; Read Data  = 0x5ba02477 
    printf (" DP -> READ  -> DPIDR              = 0x%08x\n", val);
    printf (" DP -> SELECT  -> WRITE        = 0x0\n");
    eud_swd_write (0xb1,       0x0 , 0);  // WRITE = SELECT     ; Write Data = 0x0 
    eud_swd_read  (0xa5,       &val, 0);  // READ  = DPIDR      ; Read Data  = 0x5ba02477 
    printf (" DP -> READ  -> DPIDR              = 0x%08x\n", val);
    eud_swd_read  (0xa5,       &val, 0);  // READ  = DPIDR      ; Read Data  = 0x5ba02477 
    printf (" DP -> READ  -> DPIDR              = 0x%08x\n", val);

    printf (" DP -> SELECT  -> WRITE        = 0x2\n");
    eud_swd_write (0xb1,       0x2 , 0);  // WRITE = SELECT     ; Write Data = 0x2 
    eud_swd_read  (0x8d,       &val, 0);  // READ  = TARGETID   ; Read Data  = 0x601200e1 
    printf (" DP -> READ  -> TARGETID           = 0x%08x\n", val);
    printf (" DP -> SELECT  -> WRITE        = 0x0\n");
    eud_swd_write (0xb1,       0x0 , 0);  // WRITE = SELECT     ; Write Data = 0x0 
    
    printf (" DP -> ABORT  -> WRITE         = 0x4\n");
    eud_swd_write (0x81,       0x4 , 0);  //  WRITE = ABORT      ; Write Data = 0x4 
    printf (" DP -> CTRL/STAT  -> WRITE     = 0x10000020\n");
    eud_swd_write (0xa9, 0x10000020, 0);  //  WRITE = CTRL/STAT  ; Write Data = 0x10000020  -> 0x50000020 
    eud_swd_read  (0x8d,       &val, 0);  //  READ  = CTRL/STAT  ; Read Data 
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);  //  READ  = CTRL/STAT  ; Read Data 
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);

    printf (" DP -> ABORT  -> WRITE         = 0x4\n");
    printf (" DP -> SELECT  -> WRITE        = 0x13000000\n");
    eud_swd_write (0xb1, 0x13000000,  0);   // WRITE: SELECT;       Write Data = 0x13000000    
    printf (" AP -> CSW  -> WRITE           = 0x22000052\n");
    eud_swd_write (0xa3, 0x22000052,  0);   // WRITE = CSW reg      Write Data = 0x22000052
    printf (" AP -> TAR LOW  -> WRITE       = 0xe000ed00\n");
    eud_swd_write (0x8b, 0xe000ed00, 0);    // WRITE = TAR LOW ; Write Data = 0xE000ED00
    eud_swd_read  (0x9f,       &val, 0);    // READ  = DATA RW ;
    printf (" AP -> READ  -> DATA RW        = 0x%08x\n", val);
    eud_swd_read  (0xbd,       &val, 0);    // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);    //  READ  = CTRL/STAT  ; Read Data 
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    printf (" AP -> TAR LOW  -> WRITE       = 0xe000ed00\n");
    eud_swd_write (0x8b, 0xe000ed00, 0);    // WRITE = TAR LOW ; Write Data = 0xe000ed00   
    eud_swd_read  (0x9f,       &val, 0);    // READ  = DATA RW ;
    printf (" AP -> READ  -> DATA RW        = 0x%08x\n", val);
    eud_swd_read  (0xbd,       &val, 0);    // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);  //  READ  = RDBUFF 
    // printf (" DP -> READ  -> CTRL/STAT           = 0x%08x\n", val);
    // printf (" AP -> TAR LOW  -> WRITE        = 0xe000edf0\n");
    // eud_swd_write (0x8b, 0xe000edf0, 0);  // WRITE = TAR LOW ; Write Data = 0xe000edf0   
    // eud_swd_read  (0x9f,       &val, 0);  // READ  = DATA RW ;
    // printf (" AP -> READ  -> DATA RW     = 0x%08x\n", val);
    // eud_swd_read  (0xbd,       &val, 0);  // READ  = RDBUFF  ; 
    // printf (" DP -> READ  -> RDBUFF          = 0x%08x\n", val);
    // eud_swd_read  (0x8d,       &val, 0);  //  READ  = CTRL/STAT
    // printf (" DP -> READ  -> CTRL/STAT           = 0x%08x\n", val);
    // eud_swd_write (0x8b, 0xe000edf0, 0);    // WRITE = TAR LOW ; Write Data = 0xe000edf0   
    // eud_swd_write (0xbb, 0xa05f0001, 0);  // WRITE = TAR LOW      ; Write Data = 0xA05F0001
    // eud_swd_read  (0xbd,       &val, 0);         // READ  = RDBUFF  ; 
    // printf (" DP -> READ  -> RDBUFF for the add=0xe000edf0   = 0x%08x\n", val);
    // eud_swd_read  (0x8d,       &val, 0);  //  READ  = CTRL/STAT
    // printf (" DP -> READ  -> CTRL/STAT           = 0x%08x\n", val);
    // eud_swd_write (0x8b, 0xe000edfc, 0);    // WRITE = TAR LOW ; Write Data = 0xe000edfc 
    // eud_swd_write (0xbb, 0x10000000, 0);  // WRITE = TAR LOW      ; Write Data = 0x10000000
    // eud_swd_read  (0xbd,       &val, 0);  // READ  = RDBUFF  ; 
    // printf (" DP -> READ  -> RDBUFF          = 0x%08x\n", val);
    // eud_swd_read  (0x8d,       &val, 0);  //  READ  = CTRL/STAT
    // printf (" DP -> READ  -> CTRL/STAT           = 0x%08x\n", val);
    // eud_swd_write (0xb1,       0x0 , 0);  // WRITE = SELECT     ; Write Data = 0x0 
    // eud_swd_read  (0xa5,       &val, 0);  // READ  = DPIDR      ; Read Data  = 0x5ba02477 
    // printf (" DP -> READ  -> DPIDR               = 0x%08x\n", val);

    printf (" DP -> ABORT  -> WRITE         = 0x04\n");
    eud_swd_write (0x81, 0x4 , 0);  // WRITE = ABORT ; Write Data = 0x4 
    printf (" DP -> SELECT  -> WRITE        = 0x11000000\n");
    eud_swd_write (0xb1, 0x11000000,  0);   // WRITE: SELECT;       Write Data = 0x11000000    
    printf (" AP -> CSW  -> WRITE           = 0xa0000012\n");
    eud_swd_write (0xa3, 0xa0000012 ,  0);  // WRITE = CSW reg      Write Data = 0xa0000012    
    printf (" AP -> TAR LOW  -> WRITE       = 0x6b0ffb0\n");
    eud_swd_write (0x8b, 0x6b0ffb0 , 0);    // WRITE = TAR LOW ; Write Data = 0x6b0ffb0  
    printf (" AP -> DATA RW  -> WRITE       = 0xc5acce55\n");
    eud_swd_write (0xbb, 0xc5acce55 , 0);   // WRITE = Data write      ; Write Data = 0xc5acce55
    eud_swd_read  (0xbd,       &val, 0);    // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);    // READ  = CTRL/STAT  ;
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    stickyErrClr(val);

    printf (" DP -> ABORT  -> WRITE         = 0x04\n");
    eud_swd_write (0x81, 0x4 , 0);  // WRITE = ABORT ; Write Data = 0x4 
    printf (" DP -> SELECT  -> WRITE        = 0x13000000\n");
    eud_swd_write (0xb1, 0x13000000,  0);   // WRITE: SELECT;       Write Data = 0x13000000    
    printf (" AP -> CSW  -> WRITE           = 0x22000052\n");
    eud_swd_write (0xa3, 0x22000052,  0);   // WRITE = CSW reg      Write Data = 0x22000052    
    printf (" AP -> TAR LOW  -> WRITE       = 0xe000ed00\n");
    eud_swd_write (0x8b, 0xe000ed00, 0);    // WRITE = TAR LOW ; Write Data = 0xe000ed00  
    eud_swd_read  (0x9f,       &val, 0);    // READ  = DATA RW ;
    printf (" AP -> READ  -> DATA RW            = 0x%08x\n", val);
    eud_swd_read  (0xbd,       &val, 0);    // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);   // READ  = CTRL/STAT  ;
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    stickyErrClr(val);

    printf (" DP -> ABORT  -> WRITE         = 0x04\n");
    eud_swd_write (0x81, 0x4 , 0);  // WRITE = ABORT ; Write Data = 0x4 
    printf (" DP -> SELECT  -> WRITE        = 0x11000000\n");
    eud_swd_write (0xb1, 0x11000000,  0);   // WRITE: SELECT;       Write Data = 0x11000000    
    printf (" AP -> CSW  -> WRITE           = 0x80000012\n");
    eud_swd_write (0xa3, 0x80000012,  0);   // WRITE = CSW reg      Write Data = 0x80000012    
    printf (" AP -> TAR LOW  -> WRITE       = 0x6b0f064\n");
    eud_swd_write (0x8b, 0x6b0f064 , 0);    // WRITE = TAR LOW ; Write Data = 0x6b0f064   
    printf (" AP -> DATA RW  -> WRITE       = 0x1\n");
    eud_swd_write  (0xbb,0x1, 0);           // Write  = DATA RW  ;
    eud_swd_read  (0xbd,       &val, 0);    // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);    // READ  = CTRL/STAT  ;
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    stickyErrClr(val);
    
    printf (" DP -> ABORT  -> WRITE         = 0x04\n");
    eud_swd_write (0x81, 0x4 , 0);  // WRITE = ABORT ; Write Data = 0x4 
    printf (" DP -> SELECT  -> WRITE        = 0x13000000\n");
    eud_swd_write (0xb1, 0x13000000,  0);   // WRITE: SELECT;       Write Data = 0x13000000    
    printf (" AP -> CSW  -> WRITE           = 0x22000052\n");
    eud_swd_write (0xa3, 0x22000052,  0);   // WRITE = CSW reg      Write Data = 0x22000052    
    printf (" AP -> TAR LOW  -> WRITE       = 0xe000edf0\n");
    eud_swd_write (0x8b, 0xe000edf0  , 0);  // WRITE = Tar Low      ; Write Data = 0xe000edf0  
    printf (" AP -> DATA RW  -> WRITE       = 0xa05f0003\n");
    eud_swd_write (0xbb, 0xa05f0003  , 0);  // WRITE = Data WRITE   ; Write Data = 0xA05F0003
    eud_swd_read  (0xbd,       &val, 0);  // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);  // READ  = CTRL/STAT  ;
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    stickyErrClr(val);
    
    printf (" AP -> TAR LOW  -> WRITE       = 0xe000edf0\n");
    eud_swd_write (0x8b, 0xe000edf0  , 0);  // WRITE = Tar Low      ; Write Data = 0xe000edf0  
    eud_swd_read  (0x9f,       &val, 0);    // READ  = DATA RW ;
    printf (" AP -> READ  -> DATA RW        = 0x%08x\n", val);
    eud_swd_read  (0xbd,       &val, 0);    // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);  // READ  = CTRL/STAT  ;
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    stickyErrClr(val);

    printf (" DP -> ABORT  -> WRITE         = 0x04\n");
    eud_swd_write (0x81, 0x4 , 0);  // WRITE = ABORT ; Write Data = 0x4 
    printf (" DP -> SELECT  -> WRITE        = 0x11000000\n");
    eud_swd_write (0xb1, 0x11000000,  0);   // WRITE: SELECT;       Write Data = 0x11000000    
    printf (" AP -> CSW  -> WRITE           = 0x80000012\n");
    eud_swd_write (0xa3, 0x80000012,  0);   // WRITE = CSW reg      Write Data = 0x80000012    
    printf (" AP -> TAR LOW  -> WRITE       = 0x6b0ffb0\n");
    eud_swd_write (0x8b, 0x6b0ffb0  , 0);    // WRITE = TAR LOW ; Write Data = 0x6b0ffb0    
    printf (" AP -> DATA RW  -> WRITE       = 0x0\n");
    eud_swd_write  (0xbb,0x0, 0);         // Write  = DATA RW  ;
    eud_swd_read  (0xbd,       &val, 0);  // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);  // READ  = CTRL/STAT  ;
    printf (" DP -> READ  -> CTRL/STAT      = 0x%08x\n", val);

    printf (" DP -> ABORT  -> WRITE         = 0x04\n");
    eud_swd_write (0x81, 0x4 , 0);  // WRITE = ABORT ; Write Data = 0x4 
    printf (" DP -> SELECT  -> WRITE        = 0x13000000\n");
    eud_swd_write (0xb1, 0x13000000,  0);   // WRITE: SELECT;       Write Data = 0x13000000    
    printf (" AP -> CSW  -> WRITE           = 0x22000052\n");
    eud_swd_write (0xa3, 0x22000052,  0);   // WRITE = CSW reg      Write Data = 0x22000052    
    printf (" AP -> TAR LOW  -> WRITE       = 0xe000edf0\n");
    eud_swd_write (0x8b, 0xe000edf0  , 0);  // WRITE = Tar Low      ; Write Data = 0xe000edf0  
    eud_swd_read  (0x9f,       &val, 0);    // READ  = DATA RW ;
    printf (" AP -> READ  -> DATA RW        = 0x%08x\n", val);
    eud_swd_read  (0xbd,       &val, 0);  // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);  // READ  = CTRL/STAT  ;
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    stickyErrClr(val);
    
    printf (" AP -> TAR LOW  -> WRITE       = 0xe000edf0\n");
    eud_swd_write (0x8b, 0xe000edf0  , 0);  // WRITE = Tar Low      ; Write Data = 0xe000edf0  
    eud_swd_read  (0x9f,       &val, 0);    // READ  = DATA RW ;
    printf (" AP -> READ  -> DATA RW        = 0x%08x\n", val);
    eud_swd_read  (0xbd,       &val, 0);    // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    
    // If the value of RDBUFF is 0x00020002 at 0xe000edf0 dhscr register. 
    // this means that the processor is in halt mode.
//  if((val & (S_HALT | C_HALT)) == 0x00020002)
//  {
//      printf(" Now processor is in HALT Mode\n");
//      printf(" So, write/read the data to the processor register\n");
//      printf(" For checking purpose, We are reading the processor reg's data\n");
//      for(uint8_t cntRegSel = 0; cntRegSel <= 19; cntRegSel++)
//          readProcessorReg(cntRegSel);
//  }
//    eud_swd_read  (0x8d,       &val, 0);  // READ  = CTRL/STAT  ;
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    stickyErrClr(val);

    return 0;
}

void stickyErrClr(uint32_t val)
{
    // Clear if any error present
    if((val & WDATAERR) != 0)
        eud_swd_write (0x81, WDERRCLR, 0);  // WRITE = ABORT ; 
    if((val & STICKYERR) != 0)
        eud_swd_write (0x81, STKERRCLR, 0);  // WRITE = ABORT ; 
    if((val & STICKYCMP) != 0)
        eud_swd_write (0x81, STKCMPCLR, 0);  // WRITE = ABORT ; 
    if((val & STICKYORUN) != 0)
        eud_swd_write (0x81, ORUNERRCLR, 0);  // WRITE = ABORT ; 
}

void readProcessorReg(uint8_t regSel)
{
    uint32_t val;
    printf (" AP -> TAR LOW  -> WRITE       = 0xe000edf4\n");
    eud_swd_write (0x8b, 0xe000edf4, 0);  // WRITE = Tar Low      ; Write Data = 0xe000edf4
    printf (" AP -> DATA RW  -> WRITE       = 0x%02x\n", regSel);
    eud_swd_write (0xbb,regSel, 0);       // Write  = DATA RW  ;
    eud_swd_read  (0xbd,       &val, 0);  // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
    eud_swd_read  (0x8d,       &val, 0);  // READ  = CTRL/STAT  ;
    printf (" DP -> READ  -> CTRL/STAT          = 0x%08x\n", val);
    printf (" AP -> TAR LOW  -> WRITE       = 0xe000edf8\n");
    eud_swd_write (0x8b, 0xe000edf8, 0);  // WRITE = Tar Low      ; Write Data = 0xe000edf8 
    eud_swd_read  (0x9f,       &val, 0);  // READ  = DATA RW ;
    printf (" AP -> READ  -> DATA RW        = 0x%08x\n", val);
    eud_swd_read  (0xbd,       &val, 0);  // READ  = RDBUFF  ; 
    printf (" DP -> READ  -> RDBUFF         = 0x%08x\n", val);
}

