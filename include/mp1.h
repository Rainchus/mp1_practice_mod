#include "types.h"

#define A_BUTTON 0x8000
#define B_BUTTON 0x4000
#define Z_BUTTON 0x2000
#define START 0x1000
#define D_UP 0x0800
#define D_DOWN 0x0400
#define D_LEFT 0x0200
#define D_RIGHT 0x0100
#define L_BUTTON 0x0020
#define R_BUTTON 0x0010

typedef struct box {
    s16 activeBool;
    s16 unk_02;
    s32 xPosStart;
    s32 yPosStart;
    s32 width;
    s32 height;
    u32 rgba;
} box;

typedef struct unkOSStructController {
    /* 0x00 */ char unk_00[8];
} unkOSStructController;

extern u16 controller1PressedButtons;
extern u16 controller1CurrentHeldButtons;
extern u16 controller1PreviousHeldButtons;
extern box box0Struct;
extern s8 minigameIslandLives;

void func_800672B0(s16, s16, s16);
void func_800635B4(void);
void func_800672DC(s16, s32, u16, s32);
extern s16 D_800D84E4;
extern s8 D_800F37BB; //minigame island lives

typedef u64	OSTime;
extern u32	osGetCount(void);
#define	OS_CLOCK_RATE		62500000LL
#define	OS_CPU_COUNTER		(OS_CLOCK_RATE*3/4) // 46875000
#define OS_CYCLES_TO_USEC(c)	(((u64)(c)*(1000000LL/15625LL))/(OS_CPU_COUNTER/15625LL))

void sleepVProcess(void);
void func_80018B2C(void);
void func_8001E5A0(s32);
void func_800247FC(void*, s32);
void func_80013974(s32);
extern s16 D_800F3742;

extern s32 isLoading;

void osContStartReadData(void*);
void osContGetReadData(void*);
void osRecvMsg(void*, s32, s32);
extern unkOSStructController unkControllerArray[8];
extern s16 unkOSStructArrayIndex;

void func_8002B6C8(void);
void func_8001DFC0(void);
void func_80025658(s32, s32);
void func_800621D8(void);

void func_8005E3FC(void);

extern s16 D_800FCA02[4];
extern s16 boxDrawn;
extern s32 bumper_balls_frame_counter;
extern u32 rngSeed;
u8 GetRandomByte(void);
extern u32 lag_frames;
extern u32 another_frame_count;
extern u32 frame_count;
extern u32 __osVIIntrCount;
void drawDebugText(s32 xPos, s32 yPos, char* string);
void mp1_sprintf(char* dest, char* source, ...);
s32 createBox(s32 xPosStart, s32 yPosStart, s32 width, s32 height, s32 rgba);
extern s32 print_time_length_saved1;
extern s32 print_time_length_load1;
extern s32 print_time_length_saved2;
extern s32 print_time_length_load2;
extern s32 rng_seed;
extern s32 rng_seed_copy1;
extern s32 rng_seed_copy2;
extern s32 rng_calls;
extern s32 rng_calls_copy1;
extern s32 rng_calls_copy2;

//pipe maze
extern f32 pipe_maze_scroll_speed;
extern s8 D_800F64F2_pm;
extern f32 D_800F6528_pm[2]; //camera
extern s32 D_800F990C_pm;
extern s32 D_800F9A34_pm;

//face lift
void func_800FB9E8(void);


//800C3430 DL of village main
//800C33B0 DL of piep in village