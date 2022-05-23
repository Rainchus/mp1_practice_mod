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


// .headersize 0x7FFFF400
// .org 0x80064234
//original code
// func_80064234:
// /* 64E34 80064234 27BDFFC8 */  addiu      $sp, $sp, -0x38
// /* 64E38 80064238 AFBF0034 */  sw         $ra, 0x34($sp)
// /* 64E3C 8006423C AFB20030 */  sw         $s2, 0x30($sp)
// /* 64E40 80064240 AFB1002C */  sw         $s1, 0x2c($sp)
// /* 64E44 80064244 AFB00028 */  sw         $s0, 0x28($sp)
// /* 64E48 80064248 27A40010 */  addiu      $a0, $sp, 0x10
// /* 64E4C 8006424C 3C05800F */  lui        $a1, hi(0x800F3370)
// /* 64E50 80064250 24A53370 */  addiu      $a1, $a1, lo(0x800F3370)
// /* 64E54 80064254 0C018E7E */  jal        0x800639F8
// /* 64E58 80064258 24060003 */   addiu     $a2, $zero, 3
// /* 64E5C 8006425C 24120001 */  addiu      $s2, $zero, 1
// /* 64E60 80064260 24110002 */  addiu      $s1, $zero, 2
// .L80064264:
// /* 64E64 80064264 3C04800F */  lui        $a0, hi(0x800F3370)
// /* 64E68 80064268 24843370 */  addiu      $a0, $a0, lo(0x800F3370)
// /* 64E6C 8006426C 27A50020 */  addiu      $a1, $sp, 0x20
// /* 64E70 80064270 0C022278 */  jal        0x800889E0
// /* 64E74 80064274 24060001 */   addiu     $a2, $zero, 1
// /* 64E78 80064278 8FA20020 */  lw         $v0, 0x20($sp)
// /* 64E7C 8006427C 10520005 */  beq        $v0, $s2, .L80064294
// /* 64E80 80064280 00000000 */   nop
// /* 64E84 80064284 10510007 */  beq        $v0, $s1, .L800642A4
// /* 64E88 80064288 00000000 */   nop
// /* 64E8C 8006428C 080190AD */  j          .L800642B4
// /* 64E90 80064290 00000000 */   nop
// .L80064294:
// /* 64E94 80064294 0C019070 */  jal        0x800641C0
// /* 64E98 80064298 00002021 */   addu      $a0, $zero, $zero
// /* 64E9C 8006429C 08019099 */  j          .L80064264
// /* 64EA0 800642A0 00000000 */   nop
// .L800642A4:
// /* 64EA4 800642A4 0C019070 */  jal        0x800641C0
// /* 64EA8 800642A8 24040001 */   addiu     $a0, $zero, 1
// /* 64EAC 800642AC 08019099 */  j          .L80064264
// /* 64EB0 800642B0 00000000 */   nop
// .L800642B4:
// /* 64EB4 800642B4 8FB00020 */  lw         $s0, 0x20($sp)
// /* 64EB8 800642B8 8E020000 */  lw         $v0, ($s0)
// /* 64EBC 800642BC 0040F809 */  jalr       $v0
// /* 64EC0 800642C0 8E040004 */   lw        $a0, 4($s0)
// /* 64EC4 800642C4 AE020008 */  sw         $v0, 8($s0)
// /* 64EC8 800642C8 8E04000C */  lw         $a0, 0xc($s0)
// /* 64ECC 800642CC 1080FFE5 */  beqz       $a0, .L80064264
// /* 64ED0 800642D0 00002821 */   addu      $a1, $zero, $zero
// /* 64ED4 800642D4 0C0222C4 */  jal        0x80088B10
// /* 64ED8 800642D8 24060001 */   addiu     $a2, $zero, 1
// /* 64EDC 800642DC 08019099 */  j          .L80064264
// /* 64EE0 800642E0 00000000 */   nop
// /* 64EE4 800642E4 8FBF0034 */  lw         $ra, 0x34($sp)
// /* 64EE8 800642E8 8FB20030 */  lw         $s2, 0x30($sp)
// /* 64EEC 800642EC 8FB1002C */  lw         $s1, 0x2c($sp)
// /* 64EF0 800642F0 8FB00028 */  lw         $s0, 0x28($sp)
// /* 64EF4 800642F4 03E00008 */  jr         $ra
// /* 64EF8 800642F8 27BD0038 */   addiu     $sp, $sp, 0x38
