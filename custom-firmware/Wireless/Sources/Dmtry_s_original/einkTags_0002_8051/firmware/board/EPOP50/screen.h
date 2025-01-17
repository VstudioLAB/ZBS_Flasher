#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <stdbool.h>
#include <stdint.h>



#define SCREEN_WIDTH				224
#define SCREEN_HEIGHT				90

#define SCREEN_NUM_GREYS			2
#define SCREEN_FIRST_GREY_IDX		0
#define SCREEN_EXTRA_COLOR_INDEX	-1		//set to negative if nonexistent
#define SCREEN_TX_BPP				1		//in transit


#define SCREEN_WIDTH_MM				51
#define SCREEN_HEIGHT_MM			21

#define SCREEN_BYTE_FILL			0xff

#define SCREEN_TYPE					TagScreenPersistentLcd_1bpp

#define SCREEN_DATA_PASSES			1
#define screenEndPass()

void screenShutdown(void);

void screenTest(void);

__bit screenTxStart(__bit forPartial);

#pragma callee_saves screenByteTx
void screenByteTx(uint8_t byte);
void screenTxEnd(void);



__xdata __at (0xfda2) uint8_t mScreenRow[320];	//350 bytes here, we use 320 of them

#endif
