// Tell armips' linker where the assets we declared in sm64.h are located
.definelabel dmaCopy, 0x80062088
.definelabel dmaCopy2, 0x80061FE8
.definelabel sleepVProcess, 0x800635B4
.definelabel drawDebugText, 0x800622BC
.definelabel mp1_sprintf, 0x8008C490
.definelabel mallocPerm, 0x8003B6A4
.definelabel createBox, 0x80062364
.definelabel osGetTime, 0x80088810
.definelabel osGetCount, 0x80093780
.definelabel __osVIIntrCount, 0x800ED608
.definelabel rng_seed, 0x800C2FF4
.definelabel GetRandomByte, 0x8001758C
.definelabel rngSeed, 0x800C2FF4
.definelabel func_80018B2C, 0x80018B2C
.definelabel func_8001E5A0, 0x8001E5A0
.definelabel func_800247FC, 0x800247FC
.definelabel func_8005E3FC, 0x8005E3FC
.definelabel boxDrawn, 0x800C59A6
.definelabel box0Struct, 0x800ED448
.definelabel minigameIslandLives, 0x800F37BB
.definelabel func_800672DC, 0x800672DC
.definelabel func_800635B4, 0x800635B4
.definelabel func_800672B0, 0x800672B0
.definelabel D_800D84E4, 0x800D84E4

//custom data
.definelabel pipe_maze_scroll_speed, 0x807FFFCC
.definelabel bumper_balls_frame_counter, 0x807FFFD0
.definelabel lag_frames, 0x807FFFD4
.definelabel frame_count, 0x807FFFD8
.definelabel rng_calls_copy2, 0x807FFFDC
.definelabel rng_seed_copy2, 0x807FFFE0
.definelabel print_time_length_load2, 0x807FFFE4
.definelabel print_time_length_saved2, 0x807FFFE8
.definelabel print_time_length_load1, 0x807FFFEC
.definelabel print_time_length_saved1, 0x807FFFF0
.definelabel rng_seed_copy1, 0x807FFFF4
.definelabel rng_calls, 0x807FFFF8
.definelabel rng_calls_copy1, 0x807FFFFC

//pipe maze
.definelabel D_800F64F2_pm, 0x800F64F2
.definelabel D_800F6528_pm, 0x800F6528
.definelabel D_800F990C_pm, 0x800F990C
.definelabel D_800F9A34_pm, 0x800F9A34