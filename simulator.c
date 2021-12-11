/* Flash simulator code for Exercise 3.2 SPI Flash Test Code

Assignment:

Unfortunately, the SPI Flash we need to test the Key-Value storage system is on backorder. The
KVStore only uses the read, write, and erase functions from the SPI Flash subsystem. Create a
small simulator so you can test the KVStore. Write a test for your simulator that uses the read,
write and erase functions.

*/

#include <stdio.h>
#include "spi_flash.h"

#define PAGE_SIZE_BYTES 256
#define SECTOR_SIZE_BYTES 4096
#define BLOCK_SIZE_BYTES 65536
#define FLASH_SIZE_BYTES (BLOCK_SIZE_BYTES * 16)
uint8_t flash[FLASH_SIZE_BYTES];

//Set some Initial value in flash storage, I know ... probably misusing thi sfunction...
 void sFLASH_DeInit(void)
 {
    sFLASH_EraseBulk();
 }

//Set some Initial value in flash storage, I know ... probably misusing thi sfunction...
void sFLASH_Init(void)
{
    for (int i = 0; i < FLASH_SIZE_BYTES; i++ )
    {
      flash[i] = i;  // Allow overflow 0 ... 255, 0 ... 255 ...
    }
}
void sFLASH_EraseSector(uint32_t SectorAddr)
{
    uint16_t datalen = SECTOR_SIZE_BYTES;
    uint32_t address = (SectorAddr * SECTOR_SIZE_BYTES);

    for (int i = address; i < (address + datalen); i++ )
    {
        flash[i] = 0;
    }
}
void sFLASH_EraseBulk(void)
{
    for (int i = 0; i < FLASH_SIZE_BYTES; i++ )
    {
      flash[i] = 0; 
    }     
}
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
    uint16_t datalen = NumByteToWrite;
    uint32_t address = (WriteAddr * PAGE_SIZE_BYTES);
    uint16_t pBufferIndex = 0;

    for (int i = address; i < (address + datalen); i++ )
    {
        flash[i] = *(pBuffer + pBufferIndex);
        pBufferIndex++;
    }
}
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
    uint16_t datalen = NumByteToWrite;
    uint32_t address = WriteAddr;
    uint16_t pBufferIndex = 0;

    for (int i = address; i < (address + datalen); i++ )
    {
        flash[i] = *(pBuffer + pBufferIndex);
        pBufferIndex++;
    }
}
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{
    uint16_t datalen = NumByteToRead;
    uint32_t address = ReadAddr;
    uint16_t pBufferIndex = 0;

   for (int i = address; i < (address + datalen); i++ )
    {
         *(pBuffer + pBufferIndex) = flash[i];
        pBufferIndex++;
    }
}
uint32_t sFLASH_ReadID(void)
{
    return 0xBEEF;
}
void sFLASH_StartReadSequence(uint32_t ReadAddr)
{
    ;
}
void print_flash_content( uint32_t address, uint32_t datalen)
{
    for (int i = address; i < (address + datalen); i++ )
    {
       printf("0x%06x %d\n",i,flash[i]);
    }
}
