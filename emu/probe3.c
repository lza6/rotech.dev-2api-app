#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

static void* fn_4(void) { fprintf(stderr, "[jni] slot 4 (off 0x20)"); exit(3); }
static void* fn_5(void) { fprintf(stderr, "[jni] slot 5 (off 0x28)"); exit(3); }
static void* fn_6(void) { fprintf(stderr, "[jni] slot 6 (off 0x30)"); exit(3); }
static void* fn_7(void) { fprintf(stderr, "[jni] slot 7 (off 0x38)"); exit(3); }
static void* fn_8(void) { fprintf(stderr, "[jni] slot 8 (off 0x40)"); exit(3); }
static void* fn_9(void) { fprintf(stderr, "[jni] slot 9 (off 0x48)"); exit(3); }
static void* fn_10(void) { fprintf(stderr, "[jni] slot 10 (off 0x50)"); exit(3); }
static void* fn_11(void) { fprintf(stderr, "[jni] slot 11 (off 0x58)"); exit(3); }
static void* fn_12(void) { fprintf(stderr, "[jni] slot 12 (off 0x60)"); exit(3); }
static void* fn_13(void) { fprintf(stderr, "[jni] slot 13 (off 0x68)"); exit(3); }
static void* fn_14(void) { fprintf(stderr, "[jni] slot 14 (off 0x70)"); exit(3); }
static void* fn_15(void) { fprintf(stderr, "[jni] slot 15 (off 0x78)"); exit(3); }
static void* fn_16(void) { fprintf(stderr, "[jni] slot 16 (off 0x80)"); exit(3); }
static void* fn_17(void) { fprintf(stderr, "[jni] slot 17 (off 0x88)"); exit(3); }
static void* fn_18(void) { fprintf(stderr, "[jni] slot 18 (off 0x90)"); exit(3); }
static void* fn_19(void) { fprintf(stderr, "[jni] slot 19 (off 0x98)"); exit(3); }
static void* fn_20(void) { fprintf(stderr, "[jni] slot 20 (off 0xa0)"); exit(3); }
static void* fn_21(void) { fprintf(stderr, "[jni] slot 21 (off 0xa8)"); exit(3); }
static void* fn_22(void) { fprintf(stderr, "[jni] slot 22 (off 0xb0)"); exit(3); }
static void* fn_23(void) { fprintf(stderr, "[jni] slot 23 (off 0xb8)"); exit(3); }
static void* fn_24(void) { fprintf(stderr, "[jni] slot 24 (off 0xc0)"); exit(3); }
static void* fn_25(void) { fprintf(stderr, "[jni] slot 25 (off 0xc8)"); exit(3); }
static void* fn_26(void) { fprintf(stderr, "[jni] slot 26 (off 0xd0)"); exit(3); }
static void* fn_27(void) { fprintf(stderr, "[jni] slot 27 (off 0xd8)"); exit(3); }
static void* fn_28(void) { fprintf(stderr, "[jni] slot 28 (off 0xe0)"); exit(3); }
static void* fn_29(void) { fprintf(stderr, "[jni] slot 29 (off 0xe8)"); exit(3); }
static void* fn_30(void) { fprintf(stderr, "[jni] slot 30 (off 0xf0)"); exit(3); }
static void* fn_31(void) { fprintf(stderr, "[jni] slot 31 (off 0xf8)"); exit(3); }
static void* fn_32(void) { fprintf(stderr, "[jni] slot 32 (off 0x100)"); exit(3); }
static void* fn_33(void) { fprintf(stderr, "[jni] slot 33 (off 0x108)"); exit(3); }
static void* fn_34(void) { fprintf(stderr, "[jni] slot 34 (off 0x110)"); exit(3); }
static void* fn_35(void) { fprintf(stderr, "[jni] slot 35 (off 0x118)"); exit(3); }
static void* fn_36(void) { fprintf(stderr, "[jni] slot 36 (off 0x120)"); exit(3); }
static void* fn_37(void) { fprintf(stderr, "[jni] slot 37 (off 0x128)"); exit(3); }
static void* fn_38(void) { fprintf(stderr, "[jni] slot 38 (off 0x130)"); exit(3); }
static void* fn_39(void) { fprintf(stderr, "[jni] slot 39 (off 0x138)"); exit(3); }
static void* fn_40(void) { fprintf(stderr, "[jni] slot 40 (off 0x140)"); exit(3); }
static void* fn_41(void) { fprintf(stderr, "[jni] slot 41 (off 0x148)"); exit(3); }
static void* fn_42(void) { fprintf(stderr, "[jni] slot 42 (off 0x150)"); exit(3); }
static void* fn_43(void) { fprintf(stderr, "[jni] slot 43 (off 0x158)"); exit(3); }
static void* fn_44(void) { fprintf(stderr, "[jni] slot 44 (off 0x160)"); exit(3); }
static void* fn_45(void) { fprintf(stderr, "[jni] slot 45 (off 0x168)"); exit(3); }
static void* fn_46(void) { fprintf(stderr, "[jni] slot 46 (off 0x170)"); exit(3); }
static void* fn_47(void) { fprintf(stderr, "[jni] slot 47 (off 0x178)"); exit(3); }
static void* fn_48(void) { fprintf(stderr, "[jni] slot 48 (off 0x180)"); exit(3); }
static void* fn_49(void) { fprintf(stderr, "[jni] slot 49 (off 0x188)"); exit(3); }
static void* fn_50(void) { fprintf(stderr, "[jni] slot 50 (off 0x190)"); exit(3); }
static void* fn_51(void) { fprintf(stderr, "[jni] slot 51 (off 0x198)"); exit(3); }
static void* fn_52(void) { fprintf(stderr, "[jni] slot 52 (off 0x1a0)"); exit(3); }
static void* fn_53(void) { fprintf(stderr, "[jni] slot 53 (off 0x1a8)"); exit(3); }
static void* fn_54(void) { fprintf(stderr, "[jni] slot 54 (off 0x1b0)"); exit(3); }
static void* fn_55(void) { fprintf(stderr, "[jni] slot 55 (off 0x1b8)"); exit(3); }
static void* fn_56(void) { fprintf(stderr, "[jni] slot 56 (off 0x1c0)"); exit(3); }
static void* fn_57(void) { fprintf(stderr, "[jni] slot 57 (off 0x1c8)"); exit(3); }
static void* fn_58(void) { fprintf(stderr, "[jni] slot 58 (off 0x1d0)"); exit(3); }
static void* fn_59(void) { fprintf(stderr, "[jni] slot 59 (off 0x1d8)"); exit(3); }
static void* fn_60(void) { fprintf(stderr, "[jni] slot 60 (off 0x1e0)"); exit(3); }
static void* fn_61(void) { fprintf(stderr, "[jni] slot 61 (off 0x1e8)"); exit(3); }
static void* fn_62(void) { fprintf(stderr, "[jni] slot 62 (off 0x1f0)"); exit(3); }
static void* fn_63(void) { fprintf(stderr, "[jni] slot 63 (off 0x1f8)"); exit(3); }
static void* fn_64(void) { fprintf(stderr, "[jni] slot 64 (off 0x200)"); exit(3); }
static void* fn_65(void) { fprintf(stderr, "[jni] slot 65 (off 0x208)"); exit(3); }
static void* fn_66(void) { fprintf(stderr, "[jni] slot 66 (off 0x210)"); exit(3); }
static void* fn_67(void) { fprintf(stderr, "[jni] slot 67 (off 0x218)"); exit(3); }
static void* fn_68(void) { fprintf(stderr, "[jni] slot 68 (off 0x220)"); exit(3); }
static void* fn_69(void) { fprintf(stderr, "[jni] slot 69 (off 0x228)"); exit(3); }
static void* fn_70(void) { fprintf(stderr, "[jni] slot 70 (off 0x230)"); exit(3); }
static void* fn_71(void) { fprintf(stderr, "[jni] slot 71 (off 0x238)"); exit(3); }
static void* fn_72(void) { fprintf(stderr, "[jni] slot 72 (off 0x240)"); exit(3); }
static void* fn_73(void) { fprintf(stderr, "[jni] slot 73 (off 0x248)"); exit(3); }
static void* fn_74(void) { fprintf(stderr, "[jni] slot 74 (off 0x250)"); exit(3); }
static void* fn_75(void) { fprintf(stderr, "[jni] slot 75 (off 0x258)"); exit(3); }
static void* fn_76(void) { fprintf(stderr, "[jni] slot 76 (off 0x260)"); exit(3); }
static void* fn_77(void) { fprintf(stderr, "[jni] slot 77 (off 0x268)"); exit(3); }
static void* fn_78(void) { fprintf(stderr, "[jni] slot 78 (off 0x270)"); exit(3); }
static void* fn_79(void) { fprintf(stderr, "[jni] slot 79 (off 0x278)"); exit(3); }
static void* fn_80(void) { fprintf(stderr, "[jni] slot 80 (off 0x280)"); exit(3); }
static void* fn_81(void) { fprintf(stderr, "[jni] slot 81 (off 0x288)"); exit(3); }
static void* fn_82(void) { fprintf(stderr, "[jni] slot 82 (off 0x290)"); exit(3); }
static void* fn_83(void) { fprintf(stderr, "[jni] slot 83 (off 0x298)"); exit(3); }
static void* fn_84(void) { fprintf(stderr, "[jni] slot 84 (off 0x2a0)"); exit(3); }
static void* fn_85(void) { fprintf(stderr, "[jni] slot 85 (off 0x2a8)"); exit(3); }
static void* fn_86(void) { fprintf(stderr, "[jni] slot 86 (off 0x2b0)"); exit(3); }
static void* fn_87(void) { fprintf(stderr, "[jni] slot 87 (off 0x2b8)"); exit(3); }
static void* fn_88(void) { fprintf(stderr, "[jni] slot 88 (off 0x2c0)"); exit(3); }
static void* fn_89(void) { fprintf(stderr, "[jni] slot 89 (off 0x2c8)"); exit(3); }
static void* fn_90(void) { fprintf(stderr, "[jni] slot 90 (off 0x2d0)"); exit(3); }
static void* fn_91(void) { fprintf(stderr, "[jni] slot 91 (off 0x2d8)"); exit(3); }
static void* fn_92(void) { fprintf(stderr, "[jni] slot 92 (off 0x2e0)"); exit(3); }
static void* fn_93(void) { fprintf(stderr, "[jni] slot 93 (off 0x2e8)"); exit(3); }
static void* fn_94(void) { fprintf(stderr, "[jni] slot 94 (off 0x2f0)"); exit(3); }
static void* fn_95(void) { fprintf(stderr, "[jni] slot 95 (off 0x2f8)"); exit(3); }
static void* fn_96(void) { fprintf(stderr, "[jni] slot 96 (off 0x300)"); exit(3); }
static void* fn_97(void) { fprintf(stderr, "[jni] slot 97 (off 0x308)"); exit(3); }
static void* fn_98(void) { fprintf(stderr, "[jni] slot 98 (off 0x310)"); exit(3); }
static void* fn_99(void) { fprintf(stderr, "[jni] slot 99 (off 0x318)"); exit(3); }
static void* fn_100(void) { fprintf(stderr, "[jni] slot 100 (off 0x320)"); exit(3); }
static void* fn_101(void) { fprintf(stderr, "[jni] slot 101 (off 0x328)"); exit(3); }
static void* fn_102(void) { fprintf(stderr, "[jni] slot 102 (off 0x330)"); exit(3); }
static void* fn_103(void) { fprintf(stderr, "[jni] slot 103 (off 0x338)"); exit(3); }
static void* fn_104(void) { fprintf(stderr, "[jni] slot 104 (off 0x340)"); exit(3); }
static void* fn_105(void) { fprintf(stderr, "[jni] slot 105 (off 0x348)"); exit(3); }
static void* fn_106(void) { fprintf(stderr, "[jni] slot 106 (off 0x350)"); exit(3); }
static void* fn_107(void) { fprintf(stderr, "[jni] slot 107 (off 0x358)"); exit(3); }
static void* fn_108(void) { fprintf(stderr, "[jni] slot 108 (off 0x360)"); exit(3); }
static void* fn_109(void) { fprintf(stderr, "[jni] slot 109 (off 0x368)"); exit(3); }
static void* fn_110(void) { fprintf(stderr, "[jni] slot 110 (off 0x370)"); exit(3); }
static void* fn_111(void) { fprintf(stderr, "[jni] slot 111 (off 0x378)"); exit(3); }
static void* fn_112(void) { fprintf(stderr, "[jni] slot 112 (off 0x380)"); exit(3); }
static void* fn_113(void) { fprintf(stderr, "[jni] slot 113 (off 0x388)"); exit(3); }
static void* fn_114(void) { fprintf(stderr, "[jni] slot 114 (off 0x390)"); exit(3); }
static void* fn_115(void) { fprintf(stderr, "[jni] slot 115 (off 0x398)"); exit(3); }
static void* fn_116(void) { fprintf(stderr, "[jni] slot 116 (off 0x3a0)"); exit(3); }
static void* fn_117(void) { fprintf(stderr, "[jni] slot 117 (off 0x3a8)"); exit(3); }
static void* fn_118(void) { fprintf(stderr, "[jni] slot 118 (off 0x3b0)"); exit(3); }
static void* fn_119(void) { fprintf(stderr, "[jni] slot 119 (off 0x3b8)"); exit(3); }
static void* fn_120(void) { fprintf(stderr, "[jni] slot 120 (off 0x3c0)"); exit(3); }
static void* fn_121(void) { fprintf(stderr, "[jni] slot 121 (off 0x3c8)"); exit(3); }
static void* fn_122(void) { fprintf(stderr, "[jni] slot 122 (off 0x3d0)"); exit(3); }
static void* fn_123(void) { fprintf(stderr, "[jni] slot 123 (off 0x3d8)"); exit(3); }
static void* fn_124(void) { fprintf(stderr, "[jni] slot 124 (off 0x3e0)"); exit(3); }
static void* fn_125(void) { fprintf(stderr, "[jni] slot 125 (off 0x3e8)"); exit(3); }
static void* fn_126(void) { fprintf(stderr, "[jni] slot 126 (off 0x3f0)"); exit(3); }
static void* fn_127(void) { fprintf(stderr, "[jni] slot 127 (off 0x3f8)"); exit(3); }
static void* fn_128(void) { fprintf(stderr, "[jni] slot 128 (off 0x400)"); exit(3); }
static void* fn_129(void) { fprintf(stderr, "[jni] slot 129 (off 0x408)"); exit(3); }
static void* fn_130(void) { fprintf(stderr, "[jni] slot 130 (off 0x410)"); exit(3); }
static void* fn_131(void) { fprintf(stderr, "[jni] slot 131 (off 0x418)"); exit(3); }
static void* fn_132(void) { fprintf(stderr, "[jni] slot 132 (off 0x420)"); exit(3); }
static void* fn_133(void) { fprintf(stderr, "[jni] slot 133 (off 0x428)"); exit(3); }
static void* fn_134(void) { fprintf(stderr, "[jni] slot 134 (off 0x430)"); exit(3); }
static void* fn_135(void) { fprintf(stderr, "[jni] slot 135 (off 0x438)"); exit(3); }
static void* fn_136(void) { fprintf(stderr, "[jni] slot 136 (off 0x440)"); exit(3); }
static void* fn_137(void) { fprintf(stderr, "[jni] slot 137 (off 0x448)"); exit(3); }
static void* fn_138(void) { fprintf(stderr, "[jni] slot 138 (off 0x450)"); exit(3); }
static void* fn_139(void) { fprintf(stderr, "[jni] slot 139 (off 0x458)"); exit(3); }
static void* fn_140(void) { fprintf(stderr, "[jni] slot 140 (off 0x460)"); exit(3); }
static void* fn_141(void) { fprintf(stderr, "[jni] slot 141 (off 0x468)"); exit(3); }
static void* fn_142(void) { fprintf(stderr, "[jni] slot 142 (off 0x470)"); exit(3); }
static void* fn_143(void) { fprintf(stderr, "[jni] slot 143 (off 0x478)"); exit(3); }
static void* fn_144(void) { fprintf(stderr, "[jni] slot 144 (off 0x480)"); exit(3); }
static void* fn_145(void) { fprintf(stderr, "[jni] slot 145 (off 0x488)"); exit(3); }
static void* fn_146(void) { fprintf(stderr, "[jni] slot 146 (off 0x490)"); exit(3); }
static void* fn_147(void) { fprintf(stderr, "[jni] slot 147 (off 0x498)"); exit(3); }
static void* fn_148(void) { fprintf(stderr, "[jni] slot 148 (off 0x4a0)"); exit(3); }
static void* fn_149(void) { fprintf(stderr, "[jni] slot 149 (off 0x4a8)"); exit(3); }
static void* fn_150(void) { fprintf(stderr, "[jni] slot 150 (off 0x4b0)"); exit(3); }
static void* fn_151(void) { fprintf(stderr, "[jni] slot 151 (off 0x4b8)"); exit(3); }
static void* fn_152(void) { fprintf(stderr, "[jni] slot 152 (off 0x4c0)"); exit(3); }
static void* fn_153(void) { fprintf(stderr, "[jni] slot 153 (off 0x4c8)"); exit(3); }
static void* fn_154(void) { fprintf(stderr, "[jni] slot 154 (off 0x4d0)"); exit(3); }
static void* fn_155(void) { fprintf(stderr, "[jni] slot 155 (off 0x4d8)"); exit(3); }
static void* fn_156(void) { fprintf(stderr, "[jni] slot 156 (off 0x4e0)"); exit(3); }
static void* fn_157(void) { fprintf(stderr, "[jni] slot 157 (off 0x4e8)"); exit(3); }
static void* fn_158(void) { fprintf(stderr, "[jni] slot 158 (off 0x4f0)"); exit(3); }
static void* fn_159(void) { fprintf(stderr, "[jni] slot 159 (off 0x4f8)"); exit(3); }
static void* fn_160(void) { fprintf(stderr, "[jni] slot 160 (off 0x500)"); exit(3); }
static void* fn_161(void) { fprintf(stderr, "[jni] slot 161 (off 0x508)"); exit(3); }
static void* fn_162(void) { fprintf(stderr, "[jni] slot 162 (off 0x510)"); exit(3); }
static void* fn_163(void) { fprintf(stderr, "[jni] slot 163 (off 0x518)"); exit(3); }
static void* fn_164(void) { fprintf(stderr, "[jni] slot 164 (off 0x520)"); exit(3); }
static void* fn_165(void) { fprintf(stderr, "[jni] slot 165 (off 0x528)"); exit(3); }
static void* fn_166(void) { fprintf(stderr, "[jni] slot 166 (off 0x530)"); exit(3); }
static void* fn_167(void) { fprintf(stderr, "[jni] slot 167 (off 0x538)"); exit(3); }
static void* fn_168(void) { fprintf(stderr, "[jni] slot 168 (off 0x540)"); exit(3); }
static void* fn_169(void) { fprintf(stderr, "[jni] slot 169 (off 0x548)"); exit(3); }
static void* fn_170(void) { fprintf(stderr, "[jni] slot 170 (off 0x550)"); exit(3); }
static void* fn_171(void) { fprintf(stderr, "[jni] slot 171 (off 0x558)"); exit(3); }
static void* fn_172(void) { fprintf(stderr, "[jni] slot 172 (off 0x560)"); exit(3); }
static void* fn_173(void) { fprintf(stderr, "[jni] slot 173 (off 0x568)"); exit(3); }
static void* fn_174(void) { fprintf(stderr, "[jni] slot 174 (off 0x570)"); exit(3); }
static void* fn_175(void) { fprintf(stderr, "[jni] slot 175 (off 0x578)"); exit(3); }
static void* fn_176(void) { fprintf(stderr, "[jni] slot 176 (off 0x580)"); exit(3); }
static void* fn_177(void) { fprintf(stderr, "[jni] slot 177 (off 0x588)"); exit(3); }
static void* fn_178(void) { fprintf(stderr, "[jni] slot 178 (off 0x590)"); exit(3); }
static void* fn_179(void) { fprintf(stderr, "[jni] slot 179 (off 0x598)"); exit(3); }
static void* fn_180(void) { fprintf(stderr, "[jni] slot 180 (off 0x5a0)"); exit(3); }
static void* fn_181(void) { fprintf(stderr, "[jni] slot 181 (off 0x5a8)"); exit(3); }
static void* fn_182(void) { fprintf(stderr, "[jni] slot 182 (off 0x5b0)"); exit(3); }
static void* fn_183(void) { fprintf(stderr, "[jni] slot 183 (off 0x5b8)"); exit(3); }
static void* fn_184(void) { fprintf(stderr, "[jni] slot 184 (off 0x5c0)"); exit(3); }
static void* fn_185(void) { fprintf(stderr, "[jni] slot 185 (off 0x5c8)"); exit(3); }
static void* fn_186(void) { fprintf(stderr, "[jni] slot 186 (off 0x5d0)"); exit(3); }
static void* fn_187(void) { fprintf(stderr, "[jni] slot 187 (off 0x5d8)"); exit(3); }
static void* fn_188(void) { fprintf(stderr, "[jni] slot 188 (off 0x5e0)"); exit(3); }
static void* fn_189(void) { fprintf(stderr, "[jni] slot 189 (off 0x5e8)"); exit(3); }
static void* fn_190(void) { fprintf(stderr, "[jni] slot 190 (off 0x5f0)"); exit(3); }
static void* fn_191(void) { fprintf(stderr, "[jni] slot 191 (off 0x5f8)"); exit(3); }
static void* fn_192(void) { fprintf(stderr, "[jni] slot 192 (off 0x600)"); exit(3); }
static void* fn_193(void) { fprintf(stderr, "[jni] slot 193 (off 0x608)"); exit(3); }
static void* fn_194(void) { fprintf(stderr, "[jni] slot 194 (off 0x610)"); exit(3); }
static void* fn_195(void) { fprintf(stderr, "[jni] slot 195 (off 0x618)"); exit(3); }
static void* fn_196(void) { fprintf(stderr, "[jni] slot 196 (off 0x620)"); exit(3); }
static void* fn_197(void) { fprintf(stderr, "[jni] slot 197 (off 0x628)"); exit(3); }
static void* fn_198(void) { fprintf(stderr, "[jni] slot 198 (off 0x630)"); exit(3); }
static void* fn_199(void) { fprintf(stderr, "[jni] slot 199 (off 0x638)"); exit(3); }
static void* fn_200(void) { fprintf(stderr, "[jni] slot 200 (off 0x640)"); exit(3); }
static void* fn_201(void) { fprintf(stderr, "[jni] slot 201 (off 0x648)"); exit(3); }
static void* fn_202(void) { fprintf(stderr, "[jni] slot 202 (off 0x650)"); exit(3); }
static void* fn_203(void) { fprintf(stderr, "[jni] slot 203 (off 0x658)"); exit(3); }
static void* fn_204(void) { fprintf(stderr, "[jni] slot 204 (off 0x660)"); exit(3); }
static void* fn_205(void) { fprintf(stderr, "[jni] slot 205 (off 0x668)"); exit(3); }
static void* fn_206(void) { fprintf(stderr, "[jni] slot 206 (off 0x670)"); exit(3); }
static void* fn_207(void) { fprintf(stderr, "[jni] slot 207 (off 0x678)"); exit(3); }
static void* fn_208(void) { fprintf(stderr, "[jni] slot 208 (off 0x680)"); exit(3); }
static void* fn_209(void) { fprintf(stderr, "[jni] slot 209 (off 0x688)"); exit(3); }
static void* fn_210(void) { fprintf(stderr, "[jni] slot 210 (off 0x690)"); exit(3); }
static void* fn_211(void) { fprintf(stderr, "[jni] slot 211 (off 0x698)"); exit(3); }
static void* fn_212(void) { fprintf(stderr, "[jni] slot 212 (off 0x6a0)"); exit(3); }
static void* fn_213(void) { fprintf(stderr, "[jni] slot 213 (off 0x6a8)"); exit(3); }
static void* fn_214(void) { fprintf(stderr, "[jni] slot 214 (off 0x6b0)"); exit(3); }
static void* fn_215(void) { fprintf(stderr, "[jni] slot 215 (off 0x6b8)"); exit(3); }
static void* fn_216(void) { fprintf(stderr, "[jni] slot 216 (off 0x6c0)"); exit(3); }
static void* fn_217(void) { fprintf(stderr, "[jni] slot 217 (off 0x6c8)"); exit(3); }
static void* fn_218(void) { fprintf(stderr, "[jni] slot 218 (off 0x6d0)"); exit(3); }
static void* fn_219(void) { fprintf(stderr, "[jni] slot 219 (off 0x6d8)"); exit(3); }
static void* fn_220(void) { fprintf(stderr, "[jni] slot 220 (off 0x6e0)"); exit(3); }
static void* fn_221(void) { fprintf(stderr, "[jni] slot 221 (off 0x6e8)"); exit(3); }
static void* fn_222(void) { fprintf(stderr, "[jni] slot 222 (off 0x6f0)"); exit(3); }
static void* fn_223(void) { fprintf(stderr, "[jni] slot 223 (off 0x6f8)"); exit(3); }
static void* fn_224(void) { fprintf(stderr, "[jni] slot 224 (off 0x700)"); exit(3); }
static void* fn_225(void) { fprintf(stderr, "[jni] slot 225 (off 0x708)"); exit(3); }
static void* fn_226(void) { fprintf(stderr, "[jni] slot 226 (off 0x710)"); exit(3); }
static void* fn_227(void) { fprintf(stderr, "[jni] slot 227 (off 0x718)"); exit(3); }
static void* fn_228(void) { fprintf(stderr, "[jni] slot 228 (off 0x720)"); exit(3); }
static void* fn_229(void) { fprintf(stderr, "[jni] slot 229 (off 0x728)"); exit(3); }
static void* fn_230(void) { fprintf(stderr, "[jni] slot 230 (off 0x730)"); exit(3); }
static void* fn_231(void) { fprintf(stderr, "[jni] slot 231 (off 0x738)"); exit(3); }
static void* fn_232(void) { fprintf(stderr, "[jni] slot 232 (off 0x740)"); exit(3); }
static void* fn_233(void) { fprintf(stderr, "[jni] slot 233 (off 0x748)"); exit(3); }
static void* fn_234(void) { fprintf(stderr, "[jni] slot 234 (off 0x750)"); exit(3); }
static void* fn_235(void) { fprintf(stderr, "[jni] slot 235 (off 0x758)"); exit(3); }
static void* fn_236(void) { fprintf(stderr, "[jni] slot 236 (off 0x760)"); exit(3); }
static void* fn_237(void) { fprintf(stderr, "[jni] slot 237 (off 0x768)"); exit(3); }
static void* fn_238(void) { fprintf(stderr, "[jni] slot 238 (off 0x770)"); exit(3); }
static void* fn_239(void) { fprintf(stderr, "[jni] slot 239 (off 0x778)"); exit(3); }
static void* fn_240(void) { fprintf(stderr, "[jni] slot 240 (off 0x780)"); exit(3); }
static void* fn_241(void) { fprintf(stderr, "[jni] slot 241 (off 0x788)"); exit(3); }
static void* fn_242(void) { fprintf(stderr, "[jni] slot 242 (off 0x790)"); exit(3); }
static void* fn_243(void) { fprintf(stderr, "[jni] slot 243 (off 0x798)"); exit(3); }
static void* fn_244(void) { fprintf(stderr, "[jni] slot 244 (off 0x7a0)"); exit(3); }
static void* fn_245(void) { fprintf(stderr, "[jni] slot 245 (off 0x7a8)"); exit(3); }
static void* fn_246(void) { fprintf(stderr, "[jni] slot 246 (off 0x7b0)"); exit(3); }
static void* fn_247(void) { fprintf(stderr, "[jni] slot 247 (off 0x7b8)"); exit(3); }
static void* fn_248(void) { fprintf(stderr, "[jni] slot 248 (off 0x7c0)"); exit(3); }
static void* fn_249(void) { fprintf(stderr, "[jni] slot 249 (off 0x7c8)"); exit(3); }
static void* fn_250(void) { fprintf(stderr, "[jni] slot 250 (off 0x7d0)"); exit(3); }
static void* fn_251(void) { fprintf(stderr, "[jni] slot 251 (off 0x7d8)"); exit(3); }
static void* fn_252(void) { fprintf(stderr, "[jni] slot 252 (off 0x7e0)"); exit(3); }
static void* fn_253(void) { fprintf(stderr, "[jni] slot 253 (off 0x7e8)"); exit(3); }
static void* fn_254(void) { fprintf(stderr, "[jni] slot 254 (off 0x7f0)"); exit(3); }
static void* fn_255(void) { fprintf(stderr, "[jni] slot 255 (off 0x7f8)"); exit(3); }
static void* fn_256(void) { fprintf(stderr, "[jni] slot 256 (off 0x800)"); exit(3); }
static void* fn_257(void) { fprintf(stderr, "[jni] slot 257 (off 0x808)"); exit(3); }
static void* fn_258(void) { fprintf(stderr, "[jni] slot 258 (off 0x810)"); exit(3); }
static void* fn_259(void) { fprintf(stderr, "[jni] slot 259 (off 0x818)"); exit(3); }
static void* fn_260(void) { fprintf(stderr, "[jni] slot 260 (off 0x820)"); exit(3); }
static void* fn_261(void) { fprintf(stderr, "[jni] slot 261 (off 0x828)"); exit(3); }
static void* fn_262(void) { fprintf(stderr, "[jni] slot 262 (off 0x830)"); exit(3); }
static void* fn_263(void) { fprintf(stderr, "[jni] slot 263 (off 0x838)"); exit(3); }
static void* fn_264(void) { fprintf(stderr, "[jni] slot 264 (off 0x840)"); exit(3); }
static void* fn_265(void) { fprintf(stderr, "[jni] slot 265 (off 0x848)"); exit(3); }
static void* fn_266(void) { fprintf(stderr, "[jni] slot 266 (off 0x850)"); exit(3); }
static void* fn_267(void) { fprintf(stderr, "[jni] slot 267 (off 0x858)"); exit(3); }
static void* fn_268(void) { fprintf(stderr, "[jni] slot 268 (off 0x860)"); exit(3); }
static void* fn_269(void) { fprintf(stderr, "[jni] slot 269 (off 0x868)"); exit(3); }
static void* fn_270(void) { fprintf(stderr, "[jni] slot 270 (off 0x870)"); exit(3); }
static void* fn_271(void) { fprintf(stderr, "[jni] slot 271 (off 0x878)"); exit(3); }
static void* fn_272(void) { fprintf(stderr, "[jni] slot 272 (off 0x880)"); exit(3); }
static void* fn_273(void) { fprintf(stderr, "[jni] slot 273 (off 0x888)"); exit(3); }
static void* fn_274(void) { fprintf(stderr, "[jni] slot 274 (off 0x890)"); exit(3); }
static void* fn_275(void) { fprintf(stderr, "[jni] slot 275 (off 0x898)"); exit(3); }
static void* fn_276(void) { fprintf(stderr, "[jni] slot 276 (off 0x8a0)"); exit(3); }
static void* fn_277(void) { fprintf(stderr, "[jni] slot 277 (off 0x8a8)"); exit(3); }
static void* fn_278(void) { fprintf(stderr, "[jni] slot 278 (off 0x8b0)"); exit(3); }
static void* fn_279(void) { fprintf(stderr, "[jni] slot 279 (off 0x8b8)"); exit(3); }
static void* fn_280(void) { fprintf(stderr, "[jni] slot 280 (off 0x8c0)"); exit(3); }
static void* fn_281(void) { fprintf(stderr, "[jni] slot 281 (off 0x8c8)"); exit(3); }
static void* fn_282(void) { fprintf(stderr, "[jni] slot 282 (off 0x8d0)"); exit(3); }
static void* fn_283(void) { fprintf(stderr, "[jni] slot 283 (off 0x8d8)"); exit(3); }
static void* fn_284(void) { fprintf(stderr, "[jni] slot 284 (off 0x8e0)"); exit(3); }
static void* fn_285(void) { fprintf(stderr, "[jni] slot 285 (off 0x8e8)"); exit(3); }
static void* fn_286(void) { fprintf(stderr, "[jni] slot 286 (off 0x8f0)"); exit(3); }
static void* fn_287(void) { fprintf(stderr, "[jni] slot 287 (off 0x8f8)"); exit(3); }
static void* fn_288(void) { fprintf(stderr, "[jni] slot 288 (off 0x900)"); exit(3); }
static void* fn_289(void) { fprintf(stderr, "[jni] slot 289 (off 0x908)"); exit(3); }
static void* fn_290(void) { fprintf(stderr, "[jni] slot 290 (off 0x910)"); exit(3); }
static void* fn_291(void) { fprintf(stderr, "[jni] slot 291 (off 0x918)"); exit(3); }
static void* fn_292(void) { fprintf(stderr, "[jni] slot 292 (off 0x920)"); exit(3); }
static void* fn_293(void) { fprintf(stderr, "[jni] slot 293 (off 0x928)"); exit(3); }
static void* fn_294(void) { fprintf(stderr, "[jni] slot 294 (off 0x930)"); exit(3); }
static void* fn_295(void) { fprintf(stderr, "[jni] slot 295 (off 0x938)"); exit(3); }
static void* fn_296(void) { fprintf(stderr, "[jni] slot 296 (off 0x940)"); exit(3); }
static void* fn_297(void) { fprintf(stderr, "[jni] slot 297 (off 0x948)"); exit(3); }
static void* fn_298(void) { fprintf(stderr, "[jni] slot 298 (off 0x950)"); exit(3); }
static void* fn_299(void) { fprintf(stderr, "[jni] slot 299 (off 0x958)"); exit(3); }
static void* fn_300(void) { fprintf(stderr, "[jni] slot 300 (off 0x960)"); exit(3); }
static void* fn_301(void) { fprintf(stderr, "[jni] slot 301 (off 0x968)"); exit(3); }
static void* fn_302(void) { fprintf(stderr, "[jni] slot 302 (off 0x970)"); exit(3); }
static void* fn_303(void) { fprintf(stderr, "[jni] slot 303 (off 0x978)"); exit(3); }
static void* fn_304(void) { fprintf(stderr, "[jni] slot 304 (off 0x980)"); exit(3); }
static void* fn_305(void) { fprintf(stderr, "[jni] slot 305 (off 0x988)"); exit(3); }
static void* fn_306(void) { fprintf(stderr, "[jni] slot 306 (off 0x990)"); exit(3); }
static void* fn_307(void) { fprintf(stderr, "[jni] slot 307 (off 0x998)"); exit(3); }
static void* fn_308(void) { fprintf(stderr, "[jni] slot 308 (off 0x9a0)"); exit(3); }
static void* fn_309(void) { fprintf(stderr, "[jni] slot 309 (off 0x9a8)"); exit(3); }
static void* fn_310(void) { fprintf(stderr, "[jni] slot 310 (off 0x9b0)"); exit(3); }
static void* fn_311(void) { fprintf(stderr, "[jni] slot 311 (off 0x9b8)"); exit(3); }
static void* fn_312(void) { fprintf(stderr, "[jni] slot 312 (off 0x9c0)"); exit(3); }
static void* fn_313(void) { fprintf(stderr, "[jni] slot 313 (off 0x9c8)"); exit(3); }
static void* fn_314(void) { fprintf(stderr, "[jni] slot 314 (off 0x9d0)"); exit(3); }
static void* fn_315(void) { fprintf(stderr, "[jni] slot 315 (off 0x9d8)"); exit(3); }
static void* fn_316(void) { fprintf(stderr, "[jni] slot 316 (off 0x9e0)"); exit(3); }
static void* fn_317(void) { fprintf(stderr, "[jni] slot 317 (off 0x9e8)"); exit(3); }
static void* fn_318(void) { fprintf(stderr, "[jni] slot 318 (off 0x9f0)"); exit(3); }
static void* fn_319(void) { fprintf(stderr, "[jni] slot 319 (off 0x9f8)"); exit(3); }
static void* fn_320(void) { fprintf(stderr, "[jni] slot 320 (off 0xa00)"); exit(3); }
static void* fn_321(void) { fprintf(stderr, "[jni] slot 321 (off 0xa08)"); exit(3); }
static void* fn_322(void) { fprintf(stderr, "[jni] slot 322 (off 0xa10)"); exit(3); }
static void* fn_323(void) { fprintf(stderr, "[jni] slot 323 (off 0xa18)"); exit(3); }
static void* fn_324(void) { fprintf(stderr, "[jni] slot 324 (off 0xa20)"); exit(3); }
static void* fn_325(void) { fprintf(stderr, "[jni] slot 325 (off 0xa28)"); exit(3); }
static void* fn_326(void) { fprintf(stderr, "[jni] slot 326 (off 0xa30)"); exit(3); }
static void* fn_327(void) { fprintf(stderr, "[jni] slot 327 (off 0xa38)"); exit(3); }
static void* fn_328(void) { fprintf(stderr, "[jni] slot 328 (off 0xa40)"); exit(3); }
static void* fn_329(void) { fprintf(stderr, "[jni] slot 329 (off 0xa48)"); exit(3); }
static void* fn_330(void) { fprintf(stderr, "[jni] slot 330 (off 0xa50)"); exit(3); }
static void* fn_331(void) { fprintf(stderr, "[jni] slot 331 (off 0xa58)"); exit(3); }
static void* fn_332(void) { fprintf(stderr, "[jni] slot 332 (off 0xa60)"); exit(3); }
static void* fn_333(void) { fprintf(stderr, "[jni] slot 333 (off 0xa68)"); exit(3); }
static void* fn_334(void) { fprintf(stderr, "[jni] slot 334 (off 0xa70)"); exit(3); }
static void* fn_335(void) { fprintf(stderr, "[jni] slot 335 (off 0xa78)"); exit(3); }
static void* fn_336(void) { fprintf(stderr, "[jni] slot 336 (off 0xa80)"); exit(3); }
static void* fn_337(void) { fprintf(stderr, "[jni] slot 337 (off 0xa88)"); exit(3); }
static void* fn_338(void) { fprintf(stderr, "[jni] slot 338 (off 0xa90)"); exit(3); }
static void* fn_339(void) { fprintf(stderr, "[jni] slot 339 (off 0xa98)"); exit(3); }
static void* fn_340(void) { fprintf(stderr, "[jni] slot 340 (off 0xaa0)"); exit(3); }
static void* fn_341(void) { fprintf(stderr, "[jni] slot 341 (off 0xaa8)"); exit(3); }
static void* fn_342(void) { fprintf(stderr, "[jni] slot 342 (off 0xab0)"); exit(3); }
static void* fn_343(void) { fprintf(stderr, "[jni] slot 343 (off 0xab8)"); exit(3); }
static void* fn_344(void) { fprintf(stderr, "[jni] slot 344 (off 0xac0)"); exit(3); }
static void* fn_345(void) { fprintf(stderr, "[jni] slot 345 (off 0xac8)"); exit(3); }
static void* fn_346(void) { fprintf(stderr, "[jni] slot 346 (off 0xad0)"); exit(3); }
static void* fn_347(void) { fprintf(stderr, "[jni] slot 347 (off 0xad8)"); exit(3); }
static void* fn_348(void) { fprintf(stderr, "[jni] slot 348 (off 0xae0)"); exit(3); }
static void* fn_349(void) { fprintf(stderr, "[jni] slot 349 (off 0xae8)"); exit(3); }
static void* fn_350(void) { fprintf(stderr, "[jni] slot 350 (off 0xaf0)"); exit(3); }
static void* fn_351(void) { fprintf(stderr, "[jni] slot 351 (off 0xaf8)"); exit(3); }
static void* fn_352(void) { fprintf(stderr, "[jni] slot 352 (off 0xb00)"); exit(3); }
static void* fn_353(void) { fprintf(stderr, "[jni] slot 353 (off 0xb08)"); exit(3); }
static void* fn_354(void) { fprintf(stderr, "[jni] slot 354 (off 0xb10)"); exit(3); }
static void* fn_355(void) { fprintf(stderr, "[jni] slot 355 (off 0xb18)"); exit(3); }
static void* fn_356(void) { fprintf(stderr, "[jni] slot 356 (off 0xb20)"); exit(3); }
static void* fn_357(void) { fprintf(stderr, "[jni] slot 357 (off 0xb28)"); exit(3); }
static void* fn_358(void) { fprintf(stderr, "[jni] slot 358 (off 0xb30)"); exit(3); }
static void* fn_359(void) { fprintf(stderr, "[jni] slot 359 (off 0xb38)"); exit(3); }
static void* fn_360(void) { fprintf(stderr, "[jni] slot 360 (off 0xb40)"); exit(3); }
static void* fn_361(void) { fprintf(stderr, "[jni] slot 361 (off 0xb48)"); exit(3); }
static void* fn_362(void) { fprintf(stderr, "[jni] slot 362 (off 0xb50)"); exit(3); }
static void* fn_363(void) { fprintf(stderr, "[jni] slot 363 (off 0xb58)"); exit(3); }
static void* fn_364(void) { fprintf(stderr, "[jni] slot 364 (off 0xb60)"); exit(3); }
static void* fn_365(void) { fprintf(stderr, "[jni] slot 365 (off 0xb68)"); exit(3); }
static void* fn_366(void) { fprintf(stderr, "[jni] slot 366 (off 0xb70)"); exit(3); }
static void* fn_367(void) { fprintf(stderr, "[jni] slot 367 (off 0xb78)"); exit(3); }
static void* fn_368(void) { fprintf(stderr, "[jni] slot 368 (off 0xb80)"); exit(3); }
static void* fn_369(void) { fprintf(stderr, "[jni] slot 369 (off 0xb88)"); exit(3); }
static void* fn_370(void) { fprintf(stderr, "[jni] slot 370 (off 0xb90)"); exit(3); }
static void* fn_371(void) { fprintf(stderr, "[jni] slot 371 (off 0xb98)"); exit(3); }
static void* fn_372(void) { fprintf(stderr, "[jni] slot 372 (off 0xba0)"); exit(3); }
static void* fn_373(void) { fprintf(stderr, "[jni] slot 373 (off 0xba8)"); exit(3); }
static void* fn_374(void) { fprintf(stderr, "[jni] slot 374 (off 0xbb0)"); exit(3); }
static void* fn_375(void) { fprintf(stderr, "[jni] slot 375 (off 0xbb8)"); exit(3); }
static void* fn_376(void) { fprintf(stderr, "[jni] slot 376 (off 0xbc0)"); exit(3); }
static void* fn_377(void) { fprintf(stderr, "[jni] slot 377 (off 0xbc8)"); exit(3); }
static void* fn_378(void) { fprintf(stderr, "[jni] slot 378 (off 0xbd0)"); exit(3); }
static void* fn_379(void) { fprintf(stderr, "[jni] slot 379 (off 0xbd8)"); exit(3); }
static void* fn_380(void) { fprintf(stderr, "[jni] slot 380 (off 0xbe0)"); exit(3); }
static void* fn_381(void) { fprintf(stderr, "[jni] slot 381 (off 0xbe8)"); exit(3); }
static void* fn_382(void) { fprintf(stderr, "[jni] slot 382 (off 0xbf0)"); exit(3); }
static void* fn_383(void) { fprintf(stderr, "[jni] slot 383 (off 0xbf8)"); exit(3); }
static void* fn_384(void) { fprintf(stderr, "[jni] slot 384 (off 0xc00)"); exit(3); }
static void* fn_385(void) { fprintf(stderr, "[jni] slot 385 (off 0xc08)"); exit(3); }
static void* fn_386(void) { fprintf(stderr, "[jni] slot 386 (off 0xc10)"); exit(3); }
static void* fn_387(void) { fprintf(stderr, "[jni] slot 387 (off 0xc18)"); exit(3); }
static void* fn_388(void) { fprintf(stderr, "[jni] slot 388 (off 0xc20)"); exit(3); }
static void* fn_389(void) { fprintf(stderr, "[jni] slot 389 (off 0xc28)"); exit(3); }
static void* fn_390(void) { fprintf(stderr, "[jni] slot 390 (off 0xc30)"); exit(3); }
static void* fn_391(void) { fprintf(stderr, "[jni] slot 391 (off 0xc38)"); exit(3); }
static void* fn_392(void) { fprintf(stderr, "[jni] slot 392 (off 0xc40)"); exit(3); }
static void* fn_393(void) { fprintf(stderr, "[jni] slot 393 (off 0xc48)"); exit(3); }
static void* fn_394(void) { fprintf(stderr, "[jni] slot 394 (off 0xc50)"); exit(3); }
static void* fn_395(void) { fprintf(stderr, "[jni] slot 395 (off 0xc58)"); exit(3); }
static void* fn_396(void) { fprintf(stderr, "[jni] slot 396 (off 0xc60)"); exit(3); }
static void* fn_397(void) { fprintf(stderr, "[jni] slot 397 (off 0xc68)"); exit(3); }
static void* fn_398(void) { fprintf(stderr, "[jni] slot 398 (off 0xc70)"); exit(3); }
static void* fn_399(void) { fprintf(stderr, "[jni] slot 399 (off 0xc78)"); exit(3); }
static void* fn_400(void) { fprintf(stderr, "[jni] slot 400 (off 0xc80)"); exit(3); }
static void* fn_401(void) { fprintf(stderr, "[jni] slot 401 (off 0xc88)"); exit(3); }
static void* fn_402(void) { fprintf(stderr, "[jni] slot 402 (off 0xc90)"); exit(3); }
static void* fn_403(void) { fprintf(stderr, "[jni] slot 403 (off 0xc98)"); exit(3); }
static void* fn_404(void) { fprintf(stderr, "[jni] slot 404 (off 0xca0)"); exit(3); }
static void* fn_405(void) { fprintf(stderr, "[jni] slot 405 (off 0xca8)"); exit(3); }
static void* fn_406(void) { fprintf(stderr, "[jni] slot 406 (off 0xcb0)"); exit(3); }
static void* fn_407(void) { fprintf(stderr, "[jni] slot 407 (off 0xcb8)"); exit(3); }
static void* fn_408(void) { fprintf(stderr, "[jni] slot 408 (off 0xcc0)"); exit(3); }
static void* fn_409(void) { fprintf(stderr, "[jni] slot 409 (off 0xcc8)"); exit(3); }
static void* fn_410(void) { fprintf(stderr, "[jni] slot 410 (off 0xcd0)"); exit(3); }
static void* fn_411(void) { fprintf(stderr, "[jni] slot 411 (off 0xcd8)"); exit(3); }
static void* fn_412(void) { fprintf(stderr, "[jni] slot 412 (off 0xce0)"); exit(3); }
static void* fn_413(void) { fprintf(stderr, "[jni] slot 413 (off 0xce8)"); exit(3); }
static void* fn_414(void) { fprintf(stderr, "[jni] slot 414 (off 0xcf0)"); exit(3); }
static void* fn_415(void) { fprintf(stderr, "[jni] slot 415 (off 0xcf8)"); exit(3); }
static void* fn_416(void) { fprintf(stderr, "[jni] slot 416 (off 0xd00)"); exit(3); }
static void* fn_417(void) { fprintf(stderr, "[jni] slot 417 (off 0xd08)"); exit(3); }
static void* fn_418(void) { fprintf(stderr, "[jni] slot 418 (off 0xd10)"); exit(3); }
static void* fn_419(void) { fprintf(stderr, "[jni] slot 419 (off 0xd18)"); exit(3); }
static void* fn_420(void) { fprintf(stderr, "[jni] slot 420 (off 0xd20)"); exit(3); }
static void* fn_421(void) { fprintf(stderr, "[jni] slot 421 (off 0xd28)"); exit(3); }
static void* fn_422(void) { fprintf(stderr, "[jni] slot 422 (off 0xd30)"); exit(3); }
static void* fn_423(void) { fprintf(stderr, "[jni] slot 423 (off 0xd38)"); exit(3); }
static void* fn_424(void) { fprintf(stderr, "[jni] slot 424 (off 0xd40)"); exit(3); }
static void* fn_425(void) { fprintf(stderr, "[jni] slot 425 (off 0xd48)"); exit(3); }
static void* fn_426(void) { fprintf(stderr, "[jni] slot 426 (off 0xd50)"); exit(3); }
static void* fn_427(void) { fprintf(stderr, "[jni] slot 427 (off 0xd58)"); exit(3); }
static void* fn_428(void) { fprintf(stderr, "[jni] slot 428 (off 0xd60)"); exit(3); }
static void* fn_429(void) { fprintf(stderr, "[jni] slot 429 (off 0xd68)"); exit(3); }
static void* fn_430(void) { fprintf(stderr, "[jni] slot 430 (off 0xd70)"); exit(3); }
static void* fn_431(void) { fprintf(stderr, "[jni] slot 431 (off 0xd78)"); exit(3); }
static void* fn_432(void) { fprintf(stderr, "[jni] slot 432 (off 0xd80)"); exit(3); }
static void* fn_433(void) { fprintf(stderr, "[jni] slot 433 (off 0xd88)"); exit(3); }
static void* fn_434(void) { fprintf(stderr, "[jni] slot 434 (off 0xd90)"); exit(3); }
static void* fn_435(void) { fprintf(stderr, "[jni] slot 435 (off 0xd98)"); exit(3); }
static void* fn_436(void) { fprintf(stderr, "[jni] slot 436 (off 0xda0)"); exit(3); }
static void* fn_437(void) { fprintf(stderr, "[jni] slot 437 (off 0xda8)"); exit(3); }
static void* fn_438(void) { fprintf(stderr, "[jni] slot 438 (off 0xdb0)"); exit(3); }
static void* fn_439(void) { fprintf(stderr, "[jni] slot 439 (off 0xdb8)"); exit(3); }
static void* fn_440(void) { fprintf(stderr, "[jni] slot 440 (off 0xdc0)"); exit(3); }
static void* fn_441(void) { fprintf(stderr, "[jni] slot 441 (off 0xdc8)"); exit(3); }
static void* fn_442(void) { fprintf(stderr, "[jni] slot 442 (off 0xdd0)"); exit(3); }
static void* fn_443(void) { fprintf(stderr, "[jni] slot 443 (off 0xdd8)"); exit(3); }
static void* fn_444(void) { fprintf(stderr, "[jni] slot 444 (off 0xde0)"); exit(3); }
static void* fn_445(void) { fprintf(stderr, "[jni] slot 445 (off 0xde8)"); exit(3); }
static void* fn_446(void) { fprintf(stderr, "[jni] slot 446 (off 0xdf0)"); exit(3); }
static void* fn_447(void) { fprintf(stderr, "[jni] slot 447 (off 0xdf8)"); exit(3); }
static void* fn_448(void) { fprintf(stderr, "[jni] slot 448 (off 0xe00)"); exit(3); }
static void* fn_449(void) { fprintf(stderr, "[jni] slot 449 (off 0xe08)"); exit(3); }
static void* fn_450(void) { fprintf(stderr, "[jni] slot 450 (off 0xe10)"); exit(3); }
static void* fn_451(void) { fprintf(stderr, "[jni] slot 451 (off 0xe18)"); exit(3); }
static void* fn_452(void) { fprintf(stderr, "[jni] slot 452 (off 0xe20)"); exit(3); }
static void* fn_453(void) { fprintf(stderr, "[jni] slot 453 (off 0xe28)"); exit(3); }
static void* fn_454(void) { fprintf(stderr, "[jni] slot 454 (off 0xe30)"); exit(3); }
static void* fn_455(void) { fprintf(stderr, "[jni] slot 455 (off 0xe38)"); exit(3); }
static void* fn_456(void) { fprintf(stderr, "[jni] slot 456 (off 0xe40)"); exit(3); }
static void* fn_457(void) { fprintf(stderr, "[jni] slot 457 (off 0xe48)"); exit(3); }
static void* fn_458(void) { fprintf(stderr, "[jni] slot 458 (off 0xe50)"); exit(3); }
static void* fn_459(void) { fprintf(stderr, "[jni] slot 459 (off 0xe58)"); exit(3); }
static void* fn_460(void) { fprintf(stderr, "[jni] slot 460 (off 0xe60)"); exit(3); }
static void* fn_461(void) { fprintf(stderr, "[jni] slot 461 (off 0xe68)"); exit(3); }
static void* fn_462(void) { fprintf(stderr, "[jni] slot 462 (off 0xe70)"); exit(3); }
static void* fn_463(void) { fprintf(stderr, "[jni] slot 463 (off 0xe78)"); exit(3); }
static void* fn_464(void) { fprintf(stderr, "[jni] slot 464 (off 0xe80)"); exit(3); }
static void* fn_465(void) { fprintf(stderr, "[jni] slot 465 (off 0xe88)"); exit(3); }
static void* fn_466(void) { fprintf(stderr, "[jni] slot 466 (off 0xe90)"); exit(3); }
static void* fn_467(void) { fprintf(stderr, "[jni] slot 467 (off 0xe98)"); exit(3); }
static void* fn_468(void) { fprintf(stderr, "[jni] slot 468 (off 0xea0)"); exit(3); }
static void* fn_469(void) { fprintf(stderr, "[jni] slot 469 (off 0xea8)"); exit(3); }
static void* fn_470(void) { fprintf(stderr, "[jni] slot 470 (off 0xeb0)"); exit(3); }
static void* fn_471(void) { fprintf(stderr, "[jni] slot 471 (off 0xeb8)"); exit(3); }
static void* fn_472(void) { fprintf(stderr, "[jni] slot 472 (off 0xec0)"); exit(3); }
static void* fn_473(void) { fprintf(stderr, "[jni] slot 473 (off 0xec8)"); exit(3); }
static void* fn_474(void) { fprintf(stderr, "[jni] slot 474 (off 0xed0)"); exit(3); }
static void* fn_475(void) { fprintf(stderr, "[jni] slot 475 (off 0xed8)"); exit(3); }
static void* fn_476(void) { fprintf(stderr, "[jni] slot 476 (off 0xee0)"); exit(3); }
static void* fn_477(void) { fprintf(stderr, "[jni] slot 477 (off 0xee8)"); exit(3); }
static void* fn_478(void) { fprintf(stderr, "[jni] slot 478 (off 0xef0)"); exit(3); }
static void* fn_479(void) { fprintf(stderr, "[jni] slot 479 (off 0xef8)"); exit(3); }
static void* fn_480(void) { fprintf(stderr, "[jni] slot 480 (off 0xf00)"); exit(3); }
static void* fn_481(void) { fprintf(stderr, "[jni] slot 481 (off 0xf08)"); exit(3); }
static void* fn_482(void) { fprintf(stderr, "[jni] slot 482 (off 0xf10)"); exit(3); }
static void* fn_483(void) { fprintf(stderr, "[jni] slot 483 (off 0xf18)"); exit(3); }
static void* fn_484(void) { fprintf(stderr, "[jni] slot 484 (off 0xf20)"); exit(3); }
static void* fn_485(void) { fprintf(stderr, "[jni] slot 485 (off 0xf28)"); exit(3); }
static void* fn_486(void) { fprintf(stderr, "[jni] slot 486 (off 0xf30)"); exit(3); }
static void* fn_487(void) { fprintf(stderr, "[jni] slot 487 (off 0xf38)"); exit(3); }
static void* fn_488(void) { fprintf(stderr, "[jni] slot 488 (off 0xf40)"); exit(3); }
static void* fn_489(void) { fprintf(stderr, "[jni] slot 489 (off 0xf48)"); exit(3); }
static void* fn_490(void) { fprintf(stderr, "[jni] slot 490 (off 0xf50)"); exit(3); }
static void* fn_491(void) { fprintf(stderr, "[jni] slot 491 (off 0xf58)"); exit(3); }
static void* fn_492(void) { fprintf(stderr, "[jni] slot 492 (off 0xf60)"); exit(3); }
static void* fn_493(void) { fprintf(stderr, "[jni] slot 493 (off 0xf68)"); exit(3); }
static void* fn_494(void) { fprintf(stderr, "[jni] slot 494 (off 0xf70)"); exit(3); }
static void* fn_495(void) { fprintf(stderr, "[jni] slot 495 (off 0xf78)"); exit(3); }
static void* fn_496(void) { fprintf(stderr, "[jni] slot 496 (off 0xf80)"); exit(3); }
static void* fn_497(void) { fprintf(stderr, "[jni] slot 497 (off 0xf88)"); exit(3); }
static void* fn_498(void) { fprintf(stderr, "[jni] slot 498 (off 0xf90)"); exit(3); }
static void* fn_499(void) { fprintf(stderr, "[jni] slot 499 (off 0xf98)"); exit(3); }
static void* fn_500(void) { fprintf(stderr, "[jni] slot 500 (off 0xfa0)"); exit(3); }
static void* fn_501(void) { fprintf(stderr, "[jni] slot 501 (off 0xfa8)"); exit(3); }
static void* fn_502(void) { fprintf(stderr, "[jni] slot 502 (off 0xfb0)"); exit(3); }
static void* fn_503(void) { fprintf(stderr, "[jni] slot 503 (off 0xfb8)"); exit(3); }
static void* fn_504(void) { fprintf(stderr, "[jni] slot 504 (off 0xfc0)"); exit(3); }
static void* fn_505(void) { fprintf(stderr, "[jni] slot 505 (off 0xfc8)"); exit(3); }
static void* fn_506(void) { fprintf(stderr, "[jni] slot 506 (off 0xfd0)"); exit(3); }
static void* fn_507(void) { fprintf(stderr, "[jni] slot 507 (off 0xfd8)"); exit(3); }
static void* fn_508(void) { fprintf(stderr, "[jni] slot 508 (off 0xfe0)"); exit(3); }
static void* fn_509(void) { fprintf(stderr, "[jni] slot 509 (off 0xfe8)"); exit(3); }
static void* fn_510(void) { fprintf(stderr, "[jni] slot 510 (off 0xff0)"); exit(3); }
static void* fn_511(void) { fprintf(stderr, "[jni] slot 511 (off 0xff8)"); exit(3); }
static void* ENV[512] = {
  [4] = (void*)fn_4, [5] = (void*)fn_5, [6] = (void*)fn_6, [7] = (void*)fn_7, [8] = (void*)fn_8, [9] = (void*)fn_9, [10] = (void*)fn_10, [11] = (void*)fn_11,
  [12] = (void*)fn_12, [13] = (void*)fn_13, [14] = (void*)fn_14, [15] = (void*)fn_15, [16] = (void*)fn_16, [17] = (void*)fn_17, [18] = (void*)fn_18, [19] = (void*)fn_19,
  [20] = (void*)fn_20, [21] = (void*)fn_21, [22] = (void*)fn_22, [23] = (void*)fn_23, [24] = (void*)fn_24, [25] = (void*)fn_25, [26] = (void*)fn_26, [27] = (void*)fn_27,
  [28] = (void*)fn_28, [29] = (void*)fn_29, [30] = (void*)fn_30, [31] = (void*)fn_31, [32] = (void*)fn_32, [33] = (void*)fn_33, [34] = (void*)fn_34, [35] = (void*)fn_35,
  [36] = (void*)fn_36, [37] = (void*)fn_37, [38] = (void*)fn_38, [39] = (void*)fn_39, [40] = (void*)fn_40, [41] = (void*)fn_41, [42] = (void*)fn_42, [43] = (void*)fn_43,
  [44] = (void*)fn_44, [45] = (void*)fn_45, [46] = (void*)fn_46, [47] = (void*)fn_47, [48] = (void*)fn_48, [49] = (void*)fn_49, [50] = (void*)fn_50, [51] = (void*)fn_51,
  [52] = (void*)fn_52, [53] = (void*)fn_53, [54] = (void*)fn_54, [55] = (void*)fn_55, [56] = (void*)fn_56, [57] = (void*)fn_57, [58] = (void*)fn_58, [59] = (void*)fn_59,
  [60] = (void*)fn_60, [61] = (void*)fn_61, [62] = (void*)fn_62, [63] = (void*)fn_63, [64] = (void*)fn_64, [65] = (void*)fn_65, [66] = (void*)fn_66, [67] = (void*)fn_67,
  [68] = (void*)fn_68, [69] = (void*)fn_69, [70] = (void*)fn_70, [71] = (void*)fn_71, [72] = (void*)fn_72, [73] = (void*)fn_73, [74] = (void*)fn_74, [75] = (void*)fn_75,
  [76] = (void*)fn_76, [77] = (void*)fn_77, [78] = (void*)fn_78, [79] = (void*)fn_79, [80] = (void*)fn_80, [81] = (void*)fn_81, [82] = (void*)fn_82, [83] = (void*)fn_83,
  [84] = (void*)fn_84, [85] = (void*)fn_85, [86] = (void*)fn_86, [87] = (void*)fn_87, [88] = (void*)fn_88, [89] = (void*)fn_89, [90] = (void*)fn_90, [91] = (void*)fn_91,
  [92] = (void*)fn_92, [93] = (void*)fn_93, [94] = (void*)fn_94, [95] = (void*)fn_95, [96] = (void*)fn_96, [97] = (void*)fn_97, [98] = (void*)fn_98, [99] = (void*)fn_99,
  [100] = (void*)fn_100, [101] = (void*)fn_101, [102] = (void*)fn_102, [103] = (void*)fn_103, [104] = (void*)fn_104, [105] = (void*)fn_105, [106] = (void*)fn_106, [107] = (void*)fn_107,
  [108] = (void*)fn_108, [109] = (void*)fn_109, [110] = (void*)fn_110, [111] = (void*)fn_111, [112] = (void*)fn_112, [113] = (void*)fn_113, [114] = (void*)fn_114, [115] = (void*)fn_115,
  [116] = (void*)fn_116, [117] = (void*)fn_117, [118] = (void*)fn_118, [119] = (void*)fn_119, [120] = (void*)fn_120, [121] = (void*)fn_121, [122] = (void*)fn_122, [123] = (void*)fn_123,
  [124] = (void*)fn_124, [125] = (void*)fn_125, [126] = (void*)fn_126, [127] = (void*)fn_127, [128] = (void*)fn_128, [129] = (void*)fn_129, [130] = (void*)fn_130, [131] = (void*)fn_131,
  [132] = (void*)fn_132, [133] = (void*)fn_133, [134] = (void*)fn_134, [135] = (void*)fn_135, [136] = (void*)fn_136, [137] = (void*)fn_137, [138] = (void*)fn_138, [139] = (void*)fn_139,
  [140] = (void*)fn_140, [141] = (void*)fn_141, [142] = (void*)fn_142, [143] = (void*)fn_143, [144] = (void*)fn_144, [145] = (void*)fn_145, [146] = (void*)fn_146, [147] = (void*)fn_147,
  [148] = (void*)fn_148, [149] = (void*)fn_149, [150] = (void*)fn_150, [151] = (void*)fn_151, [152] = (void*)fn_152, [153] = (void*)fn_153, [154] = (void*)fn_154, [155] = (void*)fn_155,
  [156] = (void*)fn_156, [157] = (void*)fn_157, [158] = (void*)fn_158, [159] = (void*)fn_159, [160] = (void*)fn_160, [161] = (void*)fn_161, [162] = (void*)fn_162, [163] = (void*)fn_163,
  [164] = (void*)fn_164, [165] = (void*)fn_165, [166] = (void*)fn_166, [167] = (void*)fn_167, [168] = (void*)fn_168, [169] = (void*)fn_169, [170] = (void*)fn_170, [171] = (void*)fn_171,
  [172] = (void*)fn_172, [173] = (void*)fn_173, [174] = (void*)fn_174, [175] = (void*)fn_175, [176] = (void*)fn_176, [177] = (void*)fn_177, [178] = (void*)fn_178, [179] = (void*)fn_179,
  [180] = (void*)fn_180, [181] = (void*)fn_181, [182] = (void*)fn_182, [183] = (void*)fn_183, [184] = (void*)fn_184, [185] = (void*)fn_185, [186] = (void*)fn_186, [187] = (void*)fn_187,
  [188] = (void*)fn_188, [189] = (void*)fn_189, [190] = (void*)fn_190, [191] = (void*)fn_191, [192] = (void*)fn_192, [193] = (void*)fn_193, [194] = (void*)fn_194, [195] = (void*)fn_195,
  [196] = (void*)fn_196, [197] = (void*)fn_197, [198] = (void*)fn_198, [199] = (void*)fn_199, [200] = (void*)fn_200, [201] = (void*)fn_201, [202] = (void*)fn_202, [203] = (void*)fn_203,
  [204] = (void*)fn_204, [205] = (void*)fn_205, [206] = (void*)fn_206, [207] = (void*)fn_207, [208] = (void*)fn_208, [209] = (void*)fn_209, [210] = (void*)fn_210, [211] = (void*)fn_211,
  [212] = (void*)fn_212, [213] = (void*)fn_213, [214] = (void*)fn_214, [215] = (void*)fn_215, [216] = (void*)fn_216, [217] = (void*)fn_217, [218] = (void*)fn_218, [219] = (void*)fn_219,
  [220] = (void*)fn_220, [221] = (void*)fn_221, [222] = (void*)fn_222, [223] = (void*)fn_223, [224] = (void*)fn_224, [225] = (void*)fn_225, [226] = (void*)fn_226, [227] = (void*)fn_227,
  [228] = (void*)fn_228, [229] = (void*)fn_229, [230] = (void*)fn_230, [231] = (void*)fn_231, [232] = (void*)fn_232, [233] = (void*)fn_233, [234] = (void*)fn_234, [235] = (void*)fn_235,
  [236] = (void*)fn_236, [237] = (void*)fn_237, [238] = (void*)fn_238, [239] = (void*)fn_239, [240] = (void*)fn_240, [241] = (void*)fn_241, [242] = (void*)fn_242, [243] = (void*)fn_243,
  [244] = (void*)fn_244, [245] = (void*)fn_245, [246] = (void*)fn_246, [247] = (void*)fn_247, [248] = (void*)fn_248, [249] = (void*)fn_249, [250] = (void*)fn_250, [251] = (void*)fn_251,
  [252] = (void*)fn_252, [253] = (void*)fn_253, [254] = (void*)fn_254, [255] = (void*)fn_255, [256] = (void*)fn_256, [257] = (void*)fn_257, [258] = (void*)fn_258, [259] = (void*)fn_259,
  [260] = (void*)fn_260, [261] = (void*)fn_261, [262] = (void*)fn_262, [263] = (void*)fn_263, [264] = (void*)fn_264, [265] = (void*)fn_265, [266] = (void*)fn_266, [267] = (void*)fn_267,
  [268] = (void*)fn_268, [269] = (void*)fn_269, [270] = (void*)fn_270, [271] = (void*)fn_271, [272] = (void*)fn_272, [273] = (void*)fn_273, [274] = (void*)fn_274, [275] = (void*)fn_275,
  [276] = (void*)fn_276, [277] = (void*)fn_277, [278] = (void*)fn_278, [279] = (void*)fn_279, [280] = (void*)fn_280, [281] = (void*)fn_281, [282] = (void*)fn_282, [283] = (void*)fn_283,
  [284] = (void*)fn_284, [285] = (void*)fn_285, [286] = (void*)fn_286, [287] = (void*)fn_287, [288] = (void*)fn_288, [289] = (void*)fn_289, [290] = (void*)fn_290, [291] = (void*)fn_291,
  [292] = (void*)fn_292, [293] = (void*)fn_293, [294] = (void*)fn_294, [295] = (void*)fn_295, [296] = (void*)fn_296, [297] = (void*)fn_297, [298] = (void*)fn_298, [299] = (void*)fn_299,
  [300] = (void*)fn_300, [301] = (void*)fn_301, [302] = (void*)fn_302, [303] = (void*)fn_303, [304] = (void*)fn_304, [305] = (void*)fn_305, [306] = (void*)fn_306, [307] = (void*)fn_307,
  [308] = (void*)fn_308, [309] = (void*)fn_309, [310] = (void*)fn_310, [311] = (void*)fn_311, [312] = (void*)fn_312, [313] = (void*)fn_313, [314] = (void*)fn_314, [315] = (void*)fn_315,
  [316] = (void*)fn_316, [317] = (void*)fn_317, [318] = (void*)fn_318, [319] = (void*)fn_319, [320] = (void*)fn_320, [321] = (void*)fn_321, [322] = (void*)fn_322, [323] = (void*)fn_323,
  [324] = (void*)fn_324, [325] = (void*)fn_325, [326] = (void*)fn_326, [327] = (void*)fn_327, [328] = (void*)fn_328, [329] = (void*)fn_329, [330] = (void*)fn_330, [331] = (void*)fn_331,
  [332] = (void*)fn_332, [333] = (void*)fn_333, [334] = (void*)fn_334, [335] = (void*)fn_335, [336] = (void*)fn_336, [337] = (void*)fn_337, [338] = (void*)fn_338, [339] = (void*)fn_339,
  [340] = (void*)fn_340, [341] = (void*)fn_341, [342] = (void*)fn_342, [343] = (void*)fn_343, [344] = (void*)fn_344, [345] = (void*)fn_345, [346] = (void*)fn_346, [347] = (void*)fn_347,
  [348] = (void*)fn_348, [349] = (void*)fn_349, [350] = (void*)fn_350, [351] = (void*)fn_351, [352] = (void*)fn_352, [353] = (void*)fn_353, [354] = (void*)fn_354, [355] = (void*)fn_355,
  [356] = (void*)fn_356, [357] = (void*)fn_357, [358] = (void*)fn_358, [359] = (void*)fn_359, [360] = (void*)fn_360, [361] = (void*)fn_361, [362] = (void*)fn_362, [363] = (void*)fn_363,
  [364] = (void*)fn_364, [365] = (void*)fn_365, [366] = (void*)fn_366, [367] = (void*)fn_367, [368] = (void*)fn_368, [369] = (void*)fn_369, [370] = (void*)fn_370, [371] = (void*)fn_371,
  [372] = (void*)fn_372, [373] = (void*)fn_373, [374] = (void*)fn_374, [375] = (void*)fn_375, [376] = (void*)fn_376, [377] = (void*)fn_377, [378] = (void*)fn_378, [379] = (void*)fn_379,
  [380] = (void*)fn_380, [381] = (void*)fn_381, [382] = (void*)fn_382, [383] = (void*)fn_383, [384] = (void*)fn_384, [385] = (void*)fn_385, [386] = (void*)fn_386, [387] = (void*)fn_387,
  [388] = (void*)fn_388, [389] = (void*)fn_389, [390] = (void*)fn_390, [391] = (void*)fn_391, [392] = (void*)fn_392, [393] = (void*)fn_393, [394] = (void*)fn_394, [395] = (void*)fn_395,
  [396] = (void*)fn_396, [397] = (void*)fn_397, [398] = (void*)fn_398, [399] = (void*)fn_399, [400] = (void*)fn_400, [401] = (void*)fn_401, [402] = (void*)fn_402, [403] = (void*)fn_403,
  [404] = (void*)fn_404, [405] = (void*)fn_405, [406] = (void*)fn_406, [407] = (void*)fn_407, [408] = (void*)fn_408, [409] = (void*)fn_409, [410] = (void*)fn_410, [411] = (void*)fn_411,
  [412] = (void*)fn_412, [413] = (void*)fn_413, [414] = (void*)fn_414, [415] = (void*)fn_415, [416] = (void*)fn_416, [417] = (void*)fn_417, [418] = (void*)fn_418, [419] = (void*)fn_419,
  [420] = (void*)fn_420, [421] = (void*)fn_421, [422] = (void*)fn_422, [423] = (void*)fn_423, [424] = (void*)fn_424, [425] = (void*)fn_425, [426] = (void*)fn_426, [427] = (void*)fn_427,
  [428] = (void*)fn_428, [429] = (void*)fn_429, [430] = (void*)fn_430, [431] = (void*)fn_431, [432] = (void*)fn_432, [433] = (void*)fn_433, [434] = (void*)fn_434, [435] = (void*)fn_435,
  [436] = (void*)fn_436, [437] = (void*)fn_437, [438] = (void*)fn_438, [439] = (void*)fn_439, [440] = (void*)fn_440, [441] = (void*)fn_441, [442] = (void*)fn_442, [443] = (void*)fn_443,
  [444] = (void*)fn_444, [445] = (void*)fn_445, [446] = (void*)fn_446, [447] = (void*)fn_447, [448] = (void*)fn_448, [449] = (void*)fn_449, [450] = (void*)fn_450, [451] = (void*)fn_451,
  [452] = (void*)fn_452, [453] = (void*)fn_453, [454] = (void*)fn_454, [455] = (void*)fn_455, [456] = (void*)fn_456, [457] = (void*)fn_457, [458] = (void*)fn_458, [459] = (void*)fn_459,
  [460] = (void*)fn_460, [461] = (void*)fn_461, [462] = (void*)fn_462, [463] = (void*)fn_463, [464] = (void*)fn_464, [465] = (void*)fn_465, [466] = (void*)fn_466, [467] = (void*)fn_467,
  [468] = (void*)fn_468, [469] = (void*)fn_469, [470] = (void*)fn_470, [471] = (void*)fn_471, [472] = (void*)fn_472, [473] = (void*)fn_473, [474] = (void*)fn_474, [475] = (void*)fn_475,
  [476] = (void*)fn_476, [477] = (void*)fn_477, [478] = (void*)fn_478, [479] = (void*)fn_479, [480] = (void*)fn_480, [481] = (void*)fn_481, [482] = (void*)fn_482, [483] = (void*)fn_483,
  [484] = (void*)fn_484, [485] = (void*)fn_485, [486] = (void*)fn_486, [487] = (void*)fn_487, [488] = (void*)fn_488, [489] = (void*)fn_489, [490] = (void*)fn_490, [491] = (void*)fn_491,
  [492] = (void*)fn_492, [493] = (void*)fn_493, [494] = (void*)fn_494, [495] = (void*)fn_495, [496] = (void*)fn_496, [497] = (void*)fn_497, [498] = (void*)fn_498, [499] = (void*)fn_499,
  [500] = (void*)fn_500, [501] = (void*)fn_501, [502] = (void*)fn_502, [503] = (void*)fn_503, [504] = (void*)fn_504, [505] = (void*)fn_505, [506] = (void*)fn_506, [507] = (void*)fn_507,
  [508] = (void*)fn_508, [509] = (void*)fn_509, [510] = (void*)fn_510, [511] = (void*)fn_511,
};

static void* VM[16];   // JavaVM: GetEnv at idx 6
static void* vm_fn_GetEnv(void* vm, void** penv, int ver) { *penv = (void*)ENV; return 0; }
static void* vm_slot_stub(void) { fprintf(stderr, "[vm] slot called"); exit(3); }
int main(int argc, char** argv) { void* h = dlopen(argv[1], RTLD_NOW); if (!h) return 1;
  VM[6] = (void*)vm_fn_GetEnv;
  void** env = ENV; void** envptr[1] = { (void**)ENV };
  void* (*getAll)(void*, void*, void*, void*) = dlsym(h, "Java_dev_rotech_decode_Decoder_getAllJsonNative");
  void* r = getAll(envptr, NULL, NULL, (void*)0x1234);
  puts("returned");
  return 0;}
