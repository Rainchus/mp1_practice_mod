#include "types.h"

typedef struct box {
    s16 activeBool;
    s16 unk_02;
    s32 xPosStart;
    s32 yPosStart;
    s32 width;
    s32 height;
    u32 rgba;
} box;

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

void func_8005E3FC(void);

extern s16 boxDrawn;
extern s32 bumper_balls_frame_counter;
extern u32 rngSeed;
u8 GetRandomByte(void);
extern u32 lag_frames;
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