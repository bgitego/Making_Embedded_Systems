
#include "simulator.c"

/*
Simulator Funciton to test:

void sFLASH_Init(void) 
void sFLASH_EraseSector(uint32_t SectorAddr)  
void sFLASH_EraseBulk(void) 
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite) 
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
uint32_t sFLASH_ReadID(void) 
void print_flash_content( uint32_t address, uint32_t datalen)

*/

void main()
{
    uint8_t temp_hold_flash_data[FLASH_SIZE_BYTES]; 
    uint32_t temp_hold_flash_data_len = FLASH_SIZE_BYTES;
    uint8_t flash_data_write[10] = {42,43,44,45,46,47,48,49,50,51};
    uint16_t flash_data_write_len = 10;
    uint8_t flash_data_read[10] = {0,0,0,0,0,0,0,0,0,0};
    uint16_t flash_data_read_len = 10;
    int match_count,unique_data_count = 0;

    printf("Tesitng Flash Simulator\n");
    sFLASH_Init(); // Populate the flash with some known values.

    //Read orignal data from flash
     sFLASH_ReadBuffer(temp_hold_flash_data,0x000000,temp_hold_flash_data_len);
     sFLASH_WriteBuffer(flash_data_write,0x000000,flash_data_write_len);
     sFLASH_ReadBuffer(flash_data_read,0x000000,flash_data_read_len);
     
    //Check written data is unique from original flash data
     for(int i = 0; i < flash_data_write_len; i++)
     {
         if(temp_hold_flash_data[i] != flash_data_write[i])
         {
             unique_data_count +=1;
         }
     }

    //Check  Written data matches read data
     for(int i = 0; i < flash_data_write_len; i++)
     {
         if(flash_data_read[i] == flash_data_write[i])
         {
             match_count +=1;
         }
     }

    if(unique_data_count > 1 && match_count == 10)
    {
        printf("Flash read data matches\n");
    }

    unique_data_count = match_count = 0; //resets

    //Write the original data back to flash
    sFLASH_WriteBuffer(temp_hold_flash_data,0x000000,temp_hold_flash_data_len);
    //Read current data which sholld match restore temp data
    sFLASH_ReadBuffer(flash_data_read,0x000000,flash_data_read_len);

    //Check  Written data matches read data ( This need to be a function ... I know better)
     for(int i = 0; i < flash_data_read_len; i++)
     {
         if(flash_data_read[i] == temp_hold_flash_data[i])
         {
             match_count +=1;
         }
     }

    if( match_count == 10)
    {
        printf("Flash read data matches original data\n");
    }

    unique_data_count = match_count = 0; //resets
    // Read Flash ID
    if(sFLASH_ReadID() == 0xBEEF)
    {
        printf("sFLASH_ReadID Pass\n");
    }

    printf("Before Clearing Sector\n");
    print_flash_content(0x000FFF,1); // Print the last element in Secots 0 before clearing
    sFLASH_EraseSector(0);
    printf("After Clearing Sector\n");
    print_flash_content(0x000FFF,1); // Print the last element in Secots 0 after clearing

    sFLASH_EraseBulk(); // Erarse the whole flash, values should be 0 for entire flash/
    
    //Read a few data from a fully erase flash
    sFLASH_ReadBuffer(flash_data_read,0x000000,flash_data_read_len);
     
    //Check  Written data matches read data ( This need to be a function ... I know better)
     for(int i = 0; i < flash_data_read_len; i++)
     {
         if(flash_data_read[i] == 0)
         {
             match_count +=1;
         }
     }

    if( match_count == 10)
    {
        printf("Bulk erase passed\n");
    }


    //Reset Flash data
    sFLASH_Init();

}