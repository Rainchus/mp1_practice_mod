#include "../include/mp1.h"

char seed[] = "Seed\x7A";
char calls[] = "Calls\x7A";

void customTextDraw(void);
void print_fps(s32 x, s32 y);

typedef struct OSContPad {
    unsigned short 	button;     /* Controller button data */
    char  			stick_x;    /* Control stick's X coordinate position*/
    char  			stick_y;    /* Control stick's Y coordinate position*/
    unsigned char  	errno;      /* Error values returned from the Controller */
} OSContPad;//800ED3F0 p1

enum colors {
    purple_color = 0x03,
	green_color = 0x0C,
	cyan_color = 0x0D,
	yellow_color = 0x0E
};

s32 boxBool = 1;
s32 pauseBool = 0;
s32 frameAdvance = 0;
OSContPad* p1Controller = (OSContPad*) 0x800ED3F4;
u16* pressedButtons = (u16*)0x800ECC24;



void advanceRNGBackwards(void) {
    if (rng_calls != 0) {
        rng_calls--;
        rngSeed = rngSeed - 0x3039;
        rngSeed = rngSeed * (0xEEB9EB65 % 0x100000000);
    }
}

void cBootFunction(void) { //ran once on boot, initializes variables and such
    print_time_length_saved1 = 0;
    print_time_length_load1 = 0;
    print_time_length_saved2 = 0;
    print_time_length_load2 = 0;
    frame_count = 0;
    another_frame_count = 0;
    lag_frames = 0;
    rng_seed_copy1 = 0xA70DCEFB;
    rng_calls_copy1 = 0x003A;
    rng_seed_copy2 = 0x2297B5D4;
    rng_calls_copy2 = 0x03EF;
    pipe_maze_scroll_speed = 150.0f;
    rng_calls = 0;
}

void setDebugFontColor(int color) {
	int* debugFontColorAddr = (int*)0x800ECB24;
	*debugFontColorAddr = color;
}

void printInputs(void) {
    
}

void customTextDraw(void) {
	char rngSeedString[15];
	char rngCallsString[15];
    char saved1String[15];
    char load1String[15];
    char saved2String[15];
    char load2String[15];
    char xInput[15];
    char yInput[15];

    char savedSeedAndCallsString1[] = "SAVED SEED AND CALLS 1";
    char loadSeedAndCallsString1[] = "LOAD SEED AND CALLS 1";
    char savedSeedAndCallsString2[] = "SAVED SEED AND CALLS 2";
    char loadSeedAndCallsString2[] = "LOAD SEED AND CALLS 2";
	char A_ButtonString[] = "A";
	char B_ButtonString[] = "B";
	char Z_ButtonString[] = "Z";
    char Start_ButtonString[] = "S";
    char DLeft[] = "DL";
    char DUp[] = "DUP";
    char DRight[] = "DR";
    char DDown[] = "DD";
    char LText[] = "L";
    char RText[] = "R";

    if (print_time_length_saved1 != 0) {
      	setDebugFontColor(purple_color);
	    mp1_sprintf(saved1String, "%s", savedSeedAndCallsString1);
	    drawDebugText(16, 210, saved1String);
        print_time_length_saved1--;
    }

    if (print_time_length_load1 != 0) {
      	setDebugFontColor(purple_color);
	    mp1_sprintf(load1String, "%s", loadSeedAndCallsString1);
	    drawDebugText(16, 220, load1String);
        print_time_length_load1--;
    }

    if (print_time_length_saved2 != 0) {
      	setDebugFontColor(purple_color);
	    mp1_sprintf(saved2String, "%s", savedSeedAndCallsString2);
	    drawDebugText(16, 210, saved2String);
        print_time_length_saved2--;
    }

    if (print_time_length_load2 != 0) {
      	setDebugFontColor(purple_color);
	    mp1_sprintf(load2String, "%s", loadSeedAndCallsString2);
	    drawDebugText(16, 220, load2String);
        print_time_length_load2--;
    }

	setDebugFontColor(cyan_color);
	mp1_sprintf(rngSeedString, "SEED\x7A%08X", rng_seed);
	drawDebugText(16, 20, rngSeedString);
	setDebugFontColor(green_color);
	mp1_sprintf(rngCallsString, "CALLS\x7A%08X", rng_calls);
	drawDebugText(16, 30, rngCallsString);

	if (p1Controller->button & A_BUTTON) { //if holding A, print "A"
        setDebugFontColor(green_color);
		drawDebugText(16, 40, A_ButtonString);
	}

	if (p1Controller->button & B_BUTTON) { //if holding B, print "B"
        setDebugFontColor(green_color);
		drawDebugText(26, 40, B_ButtonString);
	}

	if (p1Controller->button & Z_BUTTON) { //if holding Z, print "Z"
        setDebugFontColor(green_color);
		drawDebugText(36, 40, Z_ButtonString);
	}

	if (p1Controller->button & START) { //if holding start, print "S"
        setDebugFontColor(green_color);
		drawDebugText(46, 40, Start_ButtonString);
	}

	if (p1Controller->button & D_UP) { //dpad up
        setDebugFontColor(green_color);
		drawDebugText(55, 40, DUp);
	}

	if (p1Controller->button & D_DOWN) { //dpad down
	    setDebugFontColor(green_color);
		drawDebugText(64, 40, DDown);	
	}

	if (p1Controller->button & D_LEFT) { //dpad left
		setDebugFontColor(green_color);
		drawDebugText(73, 40, DLeft);
	}

	if (p1Controller->button & D_RIGHT) { //dpad right
		setDebugFontColor(green_color);
		drawDebugText(82, 40, DRight);
	}

	if (p1Controller->button & L_BUTTON) { //L button
		setDebugFontColor(green_color);
		drawDebugText(100, 40, LText);
	}

	if (p1Controller->button & R_BUTTON) { //R button
		setDebugFontColor(green_color);
		drawDebugText(109, 40, RText);
	}

    mp1_sprintf(xInput, "%d", p1Controller->stick_x);
	setDebugFontColor(green_color);
	drawDebugText(16, 50, xInput);

	mp1_sprintf(yInput, "%d", p1Controller->stick_y);
	setDebugFontColor(green_color);
    drawDebugText(46, 50, yInput);

    if (*pressedButtons == 0x0200) { //dpad left
        rng_seed_copy1 = rng_seed;
        rng_calls_copy1 = rng_calls;
        print_time_length_saved1 = 75;
    }

    if (*pressedButtons == 0x0400) { //dpad down
        rng_seed = rng_seed_copy1;
        rng_calls = rng_calls_copy1;
        print_time_length_load1 = 75;
    }

    if (*pressedButtons == D_RIGHT) { //dpad right
        frame_count = __osVIIntrCount / 2; //reset lag counter
    }
}

void printStats(void) {
    char VICountBuffer[15];
    char secondFrameCounter[15];
    s32 frameCountXPos;

    mp1_sprintf(VICountBuffer, "%d", lag_frames);
	setDebugFontColor(green_color);
	drawDebugText(263, 200, VICountBuffer);

    print_fps(263, 210);

    mp1_sprintf(secondFrameCounter, "%d", another_frame_count);
	setDebugFontColor(cyan_color);
    if (another_frame_count < 100000) {
        frameCountXPos = 263;
    } else if (another_frame_count < 1000000) {
        frameCountXPos = 255;
    } else if (another_frame_count < 10000000) {
        frameCountXPos = 247;
    } else if (another_frame_count < 100000000) {
        frameCountXPos = 239;
    } else if (another_frame_count < 1000000000) {
        frameCountXPos = 231;
    } else {
        frameCountXPos = 222;
    }
	drawDebugText(frameCountXPos, 220, secondFrameCounter);
}

void cCompareVICount(void) {
    lag_frames = (__osVIIntrCount / 2) - frame_count; //if 0, no lag occurred
    frame_count++;
}

// ------------- FPS COUNTER ---------------
// To use it, call print_fps(x,y); every frame.
#define FRAMETIME_COUNT 30

OSTime frameTimes[FRAMETIME_COUNT];
u8 curFrameTimeIndex = 0;

// Call once per frame
f32 calculate_and_update_fps(void) {
    u32 newTime = osGetCount();
    u32 oldTime = frameTimes[curFrameTimeIndex];
    frameTimes[curFrameTimeIndex] = newTime;

    curFrameTimeIndex++;
    if (curFrameTimeIndex >= FRAMETIME_COUNT) {
        curFrameTimeIndex = 0;
    }

    return (1000000.0f * FRAMETIME_COUNT * (OS_CPU_COUNTER/15625.0f) / (1000000.0f/15625.0f)) / (f32)(newTime - oldTime);
}

void print_fps(s32 x, s32 y) {
    f32 fps = calculate_and_update_fps();
    char text[10];

    mp1_sprintf(text, "%2.2f", fps);
	setDebugFontColor(green_color);
	drawDebugText(x, y, text);
}

// ------------ END OF FPS COUNER -----------------

void bumperBallsFrameCounterUpdate(void) {
    bumper_balls_frame_counter++;
}

void bumperBallsFrameCounterDisplay(void) {
    char frameCounterBufferBumperBalls[15];
    //bumper balls
    mp1_sprintf(frameCounterBufferBumperBalls, "%d", bumper_balls_frame_counter);
	setDebugFontColor(green_color);
	drawDebugText(16, 220, frameCounterBufferBumperBalls);
}

void shyGuySaysTurnDisplay(void) {
    char turnCountText[15];
    u16* turnCount = (u16*)0x800FD9A8;

    mp1_sprintf(turnCountText, "%d", *turnCount);
	setDebugFontColor(green_color);
	drawDebugText(16, 220, turnCountText);
}

void copyInputs(void) {
    s16 buttonsTemp;
    osContGetReadData((void*)0x800EE960); //copy controller data to osCont struct
    controller1PreviousHeldButtons = controller1CurrentHeldButtons;
    controller1CurrentHeldButtons = p1Controller->button;
    buttonsTemp = controller1CurrentHeldButtons & controller1PreviousHeldButtons;
    controller1PressedButtons = buttonsTemp ^ controller1CurrentHeldButtons;
}

void stepFrame(void) {
    if (controller1PressedButtons & L_BUTTON) {
        frameAdvance = 1;
        controller1PressedButtons = 0;
    }

    if (controller1PressedButtons & R_BUTTON) {
        pauseBool = 0;
        controller1PressedButtons = 0;
    }
}

void mainThreadHook(void) {
    while(1) {
        sleepVProcess();
        func_80018B2C();
        func_8001E5A0(2);
        func_800247FC((void*)0x800ED538, 2);
        cCompareVICount();
    }
}

void mainThreadHook2(void) {
    while(1) {
        if (pauseBool == 0) {
            sleepVProcess();
            func_8002B6C8();
            func_8001DFC0();
            func_80025658(0x02000000, 0x003D0800);
            func_800621D8();
            copyInputs();
            if (controller1PressedButtons & R_BUTTON) {
                pauseBool ^= 1;
                controller1PressedButtons = 0;
            }
            another_frame_count++;
        } else {
            if (frameAdvance == 1) {
                sleepVProcess();
                func_8002B6C8();
                func_8001DFC0();
                func_80025658(0x02000000, 0x003D0800);
                func_800621D8();
                frameAdvance = 0;
                controller1PressedButtons = 0;
                another_frame_count++;
            } else {
                copyInputs();
                stepFrame();
            }
        }
    }
}

void debugDrawThreadHook(void) {
    u8 red = 0;
    u8 green = 0;
    u8 blue = 0xFF;
    u8 alpha = 0x70;
    u32 combinedColor = (red << 24) | (green << 16) | (blue << 8) | alpha;
    u16* oneFrameInputs = (u16*)0x800ECC24;

    while (1) {
        if (boxDrawn == -1) {
            createBox(14, 16, 140, 64, combinedColor);
            boxDrawn = 1;
        }

        if (*oneFrameInputs == D_UP) { //dpad up
            boxBool ^= 1;
        }

        if (boxBool == 1) {
            box0Struct.activeBool = 1;
            customTextDraw();
        } else {
            box0Struct.activeBool = 0;
        }
        sleepVProcess();
        func_8005E3FC();
        printStats();
    }
}

u8 GetRandomByteHook(void) {
    rng_calls++;
    rngSeed = rngSeed * 0x41C64E6D + 0x3039;
    return (rngSeed + 1) >> 16;
}

void cStickRNGAdvance(void) {
    short* oneFrameInputs = (short*)0x800ECC24;
    if (*oneFrameInputs == 0x0008) { //c-up
        GetRandomByte(); //advance RNG once
    }

    if (*oneFrameInputs == 0x0004) { //c-down
        advanceRNGBackwards();
    }

    if (*oneFrameInputs == 0x0002) { //c-left
        for (int i = 0; i < 0x10; i++) {
            advanceRNGBackwards(); //advance RNG backwards 16 times
        }
    }

    if (*oneFrameInputs == 0x0001) { //c-right
        for (int i = 0; i < 0x10; i++) {
            GetRandomByte(); //advance RNG 16 times
        }
    }
}

void minigameIslandLivesDisplayHook(void) { //minigame lives display
    s32 lives;
    bumper_balls_frame_counter = 0;

    while (1) {
        lives = minigameIslandLives;
        if (lives < 0) {
            lives = 0;
        }
        
        if (lives >= 100) {
            lives = 99;
        }

        lives = 99; //lock lives to 99
        
        func_800672B0(D_800D84E4, 0, 1);
        func_800672DC(D_800D84E4, 0, (lives / 10), 0);
        func_800672B0(D_800D84E4, 1, 1);
        func_800672DC(D_800D84E4, 1, (lives % 10), 0);
        func_800635B4();
        cStickRNGAdvance();
    }
}

void pipeMazeScrollHook(void) {
    char scrollSpeedPercentageText[15];
    short* oneFrameInputs = (short*)0x800ECC24;

    if (*oneFrameInputs == 0x0008) { //c-up
        pipe_maze_scroll_speed += 15.0f;
    }

    if (*oneFrameInputs == 0x0004) { //c-down
        pipe_maze_scroll_speed -= 15.0f;
    }

    // mp1_sprintf(scrollSpeedText, "%d", (s32)pipe_maze_scroll_speed);
	// setDebugFontColor(green_color);
	// drawDebugText(16, 220, scrollSpeedText);

    mp1_sprintf(scrollSpeedPercentageText, "SPEED: %d", (s32)((pipe_maze_scroll_speed / 150.0f) * 100.0f)); //150.0f is base speed
	setDebugFontColor(green_color);
	drawDebugText(16, 220, scrollSpeedPercentageText); 

    if (D_800F9A34_pm == 1) {
        if ((D_800F6528_pm[0] < 6800.0f) && (D_800F990C_pm == 0)) {
            D_800F6528_pm[0] = D_800F6528_pm[0] + pipe_maze_scroll_speed;
            D_800F64F2_pm = 1;
        } else if ((D_800F6528_pm[0] >= 6800.0f) && (D_800F990C_pm == 0)) {
            D_800F990C_pm = 1;
            D_800F64F2_pm = 0;
        }
        if (D_800F990C_pm == 3) {
            D_800F9A34_pm = 2;
        }
    }
}

void faceLiftScoreDisplayHook(void) {
    //char scoresText[40];
    //func_800FB9E8(); //calculate scores (does more than just this actually)

    // mp1_sprintf(scoresText, "P1:%d P2:%d P3:%d P4:%d", D_800FCA02[0], D_800FCA02[1], D_800FCA02[2], D_800FCA02[3]);
	// setDebugFontColor(green_color);
	// drawDebugText(16, 220, scoresText); 
}