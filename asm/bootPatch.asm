//ROM 0x15070
.headersize 0x7FFFF400
.org 0x8005B6E4
LI a0, 0x1CED490 //ROM addr to read from
LUI a1, 0x8040 //RAM addr to write to
ORI a2, r0, 0x7F00 //size of DMA
JAL dmaCopy2
NOP
J DisplacedBootCode
NOP
NOP //delete this line for clarity


.headersize 0x7E712B70
.org 0x80400000
DisplacedBootCode:
JAL cBootFunction
NOP
//restore displaced boot code
LUI at, 0x800E
SW s1, 0x8910 (at)
JAL mallocPerm
ADDIU a0, r0, 0x0010
ADDU s0, v0, r0
ADDU a0, s1, r0
ADDU a1, s0, r0
JAL 0x80061FE8
ADDIU a2, r0, 0x0010
J 0x8005B708
NOP

//0x8001758C RAM
//0x1818C ROM
.headersize 0x7FFFF400
.org 0x8001758C
J GetRandomByteHook
NOP

//bumper balls frame counter hook
//ROM 0x197C48
//RAM 0x800FCB28
.headersize 0x7FF64EE0
.org 0x800FCB28
bumperBallsFrameCounterJumpInstruction:
J bumperBallsFrameCounterUpdate
ADDIU sp, sp, 0x80

.org 0x800FB298
J bumperBallsFrameCounterDisplay
NOP


//0x1DFB34 ROM
//0x800FCA84 RAM
.headersize 0x7FF1CF50
.org 0x800FCA84
J shyGuySaysTurnDisplay
ADDIU sp, sp, 0x70

//0x1B05C ROM
//0x8001A45C RAM
.headersize 0x7FFFF400
.org 0x8001A454
J mainThreadHook
NOP

.org 0x8001A428
J debugDrawThreadHook
NOP

.org 0x80055D28
J minigameIslandLivesDisplayHook
NOP

.org 0x8001A3DC
J mainThreadHook2
NOP


//RAM 800F8F24
//ROM 116704
.headersize 0x7FFE2820
.org 0x800F8F24
J pipeMazeScrollHook
NOP

.headersize 0x7FFCA9C0
.org 0x800F696C
J faceLiftScoreDisplayHook
ADDIU sp, sp, 0x38