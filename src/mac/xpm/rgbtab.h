/*
 * Copyright (C) 1989-95 GROUPE BULL
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * GROUPE BULL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of GROUPE BULL shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization from GROUPE BULL.
 */

/*****************************************************************************\
* rgbtab.h                                                                    *
*                                                                             *
* A hard coded rgb.txt. To keep it short I removed all colornames with        *
* trailing numbers, Blue3 etc, except the GrayXX. Sorry Grey-lovers I prefer  *
* Gray ;-). But Grey is recognized on lookups, only on save Gray will be      *
* used, maybe you want to do some substitue there too.                        *
*                                                                             *
* To save memory the RGBs are coded in one long value, as done by the RGB     *
* macro.                                                                      *
*                                                                             *
* Developed by HeDu 3/94 (hedu@cul-ipn.uni-kiel.de)                           *
\*****************************************************************************/


typedef struct {
    char *name;
    RGBColor rgb;			/* it's unsigned long */
}      rgbRecord;

/*
#define myRGB(r,g,b) \
	((unsigned long)r<<16|(unsigned long)g<<8|(unsigned long)b)
*/
#ifdef FOR_MSW
#define myRGB(r,g,b)	RGB(r,g,b)	/* MSW has this macro */
#else
#define myRGB(r,g,b) { ((r) << 8) + (r) , ((g) << 8) + (g), ((b) << 8) + (b) }
#define GetRValue(c) ((c).red)
#define GetGValue(c) ((c).green)
#define GetBValue(c) ((c).blue)
#endif

static rgbRecord theRGBRecords[] =
{
    {"AliceBlue", myRGB(240, 248, 255)},
    {"AntiqueWhite", myRGB(250, 235, 215)},
    {"Aquamarine", myRGB(50, 191, 193)},
    {"Azure", myRGB(240, 255, 255)},
    {"Beige", myRGB(245, 245, 220)},
    {"Bisque", myRGB(255, 228, 196)},
    {"Black", myRGB(0, 0, 0)},
    {"BlanchedAlmond", myRGB(255, 235, 205)},
    {"Blue", myRGB(0, 0, 255)},
    {"BlueViolet", myRGB(138, 43, 226)},
    {"Brown", myRGB(165, 42, 42)},
    {"burlywood", myRGB(222, 184, 135)},
    {"CadetBlue", myRGB(95, 146, 158)},
    {"chartreuse", myRGB(127, 255, 0)},
    {"chocolate", myRGB(210, 105, 30)},
    {"Coral", myRGB(255, 114, 86)},
    {"CornflowerBlue", myRGB(34, 34, 152)},
    {"cornsilk", myRGB(255, 248, 220)},
    {"Cyan", myRGB(0, 255, 255)},
    {"DarkGoldenrod", myRGB(184, 134, 11)},
    {"DarkGreen", myRGB(0, 86, 45)},
    {"DarkKhaki", myRGB(189, 183, 107)},
    {"DarkOliveGreen", myRGB(85, 86, 47)},
    {"DarkOrange", myRGB(255, 140, 0)},
    {"DarkOrchid", myRGB(139, 32, 139)},
    {"DarkSalmon", myRGB(233, 150, 122)},
    {"DarkSeaGreen", myRGB(143, 188, 143)},
    {"DarkSlateBlue", myRGB(56, 75, 102)},
    {"DarkSlateGray", myRGB(47, 79, 79)},
    {"DarkTurquoise", myRGB(0, 166, 166)},
    {"DarkViolet", myRGB(148, 0, 211)},
    {"DeepPink", myRGB(255, 20, 147)},
    {"DeepSkyBlue", myRGB(0, 191, 255)},
    {"DimGray", myRGB(84, 84, 84)},
    {"DodgerBlue", myRGB(30, 144, 255)},
    {"Firebrick", myRGB(142, 35, 35)},
    {"FloralWhite", myRGB(255, 250, 240)},
    {"ForestGreen", myRGB(80, 159, 105)},
    {"gainsboro", myRGB(220, 220, 220)},
    {"GhostWhite", myRGB(248, 248, 255)},
    {"Gold", myRGB(218, 170, 0)},
    {"Goldenrod", myRGB(239, 223, 132)},
    {"Gray", myRGB(126, 126, 126)},
    {"Gray0", myRGB(0, 0, 0)},
    {"Gray1", myRGB(3, 3, 3)},
    {"Gray10", myRGB(26, 26, 26)},
    {"Gray100", myRGB(255, 255, 255)},
    {"Gray11", myRGB(28, 28, 28)},
    {"Gray12", myRGB(31, 31, 31)},
    {"Gray13", myRGB(33, 33, 33)},
    {"Gray14", myRGB(36, 36, 36)},
    {"Gray15", myRGB(38, 38, 38)},
    {"Gray16", myRGB(41, 41, 41)},
    {"Gray17", myRGB(43, 43, 43)},
    {"Gray18", myRGB(46, 46, 46)},
    {"Gray19", myRGB(48, 48, 48)},
    {"Gray2", myRGB(5, 5, 5)},
    {"Gray20", myRGB(51, 51, 51)},
    {"Gray21", myRGB(54, 54, 54)},
    {"Gray22", myRGB(56, 56, 56)},
    {"Gray23", myRGB(59, 59, 59)},
    {"Gray24", myRGB(61, 61, 61)},
    {"Gray25", myRGB(64, 64, 64)},
    {"Gray26", myRGB(66, 66, 66)},
    {"Gray27", myRGB(69, 69, 69)},
    {"Gray28", myRGB(71, 71, 71)},
    {"Gray29", myRGB(74, 74, 74)},
    {"Gray3", myRGB(8, 8, 8)},
    {"Gray30", myRGB(77, 77, 77)},
    {"Gray31", myRGB(79, 79, 79)},
    {"Gray32", myRGB(82, 82, 82)},
    {"Gray33", myRGB(84, 84, 84)},
    {"Gray34", myRGB(87, 87, 87)},
    {"Gray35", myRGB(89, 89, 89)},
    {"Gray36", myRGB(92, 92, 92)},
    {"Gray37", myRGB(94, 94, 94)},
    {"Gray38", myRGB(97, 97, 97)},
    {"Gray39", myRGB(99, 99, 99)},
    {"Gray4", myRGB(10, 10, 10)},
    {"Gray40", myRGB(102, 102, 102)},
    {"Gray41", myRGB(105, 105, 105)},
    {"Gray42", myRGB(107, 107, 107)},
    {"Gray43", myRGB(110, 110, 110)},
    {"Gray44", myRGB(112, 112, 112)},
    {"Gray45", myRGB(115, 115, 115)},
    {"Gray46", myRGB(117, 117, 117)},
    {"Gray47", myRGB(120, 120, 120)},
    {"Gray48", myRGB(122, 122, 122)},
    {"Gray49", myRGB(125, 125, 125)},
    {"Gray5", myRGB(13, 13, 13)},
    {"Gray50", myRGB(127, 127, 127)},
    {"Gray51", myRGB(130, 130, 130)},
    {"Gray52", myRGB(133, 133, 133)},
    {"Gray53", myRGB(135, 135, 135)},
    {"Gray54", myRGB(138, 138, 138)},
    {"Gray55", myRGB(140, 140, 140)},
    {"Gray56", myRGB(143, 143, 143)},
    {"Gray57", myRGB(145, 145, 145)},
    {"Gray58", myRGB(148, 148, 148)},
    {"Gray59", myRGB(150, 150, 150)},
    {"Gray6", myRGB(15, 15, 15)},
    {"Gray60", myRGB(153, 153, 153)},
    {"Gray61", myRGB(156, 156, 156)},
    {"Gray62", myRGB(158, 158, 158)},
    {"Gray63", myRGB(161, 161, 161)},
    {"Gray64", myRGB(163, 163, 163)},
    {"Gray65", myRGB(166, 166, 166)},
    {"Gray66", myRGB(168, 168, 168)},
    {"Gray67", myRGB(171, 171, 171)},
    {"Gray68", myRGB(173, 173, 173)},
    {"Gray69", myRGB(176, 176, 176)},
    {"Gray7", myRGB(18, 18, 18)},
    {"Gray70", myRGB(179, 179, 179)},
    {"Gray71", myRGB(181, 181, 181)},
    {"Gray72", myRGB(184, 184, 184)},
    {"Gray73", myRGB(186, 186, 186)},
    {"Gray74", myRGB(189, 189, 189)},
    {"Gray75", myRGB(191, 191, 191)},
    {"Gray76", myRGB(194, 194, 194)},
    {"Gray77", myRGB(196, 196, 196)},
    {"Gray78", myRGB(199, 199, 199)},
    {"Gray79", myRGB(201, 201, 201)},
    {"Gray8", myRGB(20, 20, 20)},
    {"Gray80", myRGB(204, 204, 204)},
    {"Gray81", myRGB(207, 207, 207)},
    {"Gray82", myRGB(209, 209, 209)},
    {"Gray83", myRGB(212, 212, 212)},
    {"Gray84", myRGB(214, 214, 214)},
    {"Gray85", myRGB(217, 217, 217)},
    {"Gray86", myRGB(219, 219, 219)},
    {"Gray87", myRGB(222, 222, 222)},
    {"Gray88", myRGB(224, 224, 224)},
    {"Gray89", myRGB(227, 227, 227)},
    {"Gray9", myRGB(23, 23, 23)},
    {"Gray90", myRGB(229, 229, 229)},
    {"Gray91", myRGB(232, 232, 232)},
    {"Gray92", myRGB(235, 235, 235)},
    {"Gray93", myRGB(237, 237, 237)},
    {"Gray94", myRGB(240, 240, 240)},
    {"Gray95", myRGB(242, 242, 242)},
    {"Gray96", myRGB(245, 245, 245)},
    {"Gray97", myRGB(247, 247, 247)},
    {"Gray98", myRGB(250, 250, 250)},
    {"Gray99", myRGB(252, 252, 252)},
    {"Green", myRGB(0, 255, 0)},
    {"GreenYellow", myRGB(173, 255, 47)},
    {"honeydew", myRGB(240, 255, 240)},
    {"HotPink", myRGB(255, 105, 180)},
    {"IndianRed", myRGB(107, 57, 57)},
    {"ivory", myRGB(255, 255, 240)},
    {"Khaki", myRGB(179, 179, 126)},
    {"lavender", myRGB(230, 230, 250)},
    {"LavenderBlush", myRGB(255, 240, 245)},
    {"LawnGreen", myRGB(124, 252, 0)},
    {"LemonChiffon", myRGB(255, 250, 205)},
    {"LightBlue", myRGB(176, 226, 255)},
    {"LightCoral", myRGB(240, 128, 128)},
    {"LightCyan", myRGB(224, 255, 255)},
    {"LightGoldenrod", myRGB(238, 221, 130)},
    {"LightGoldenrodYellow", myRGB(250, 250, 210)},
    {"LightGray", myRGB(168, 168, 168)},
    {"LightPink", myRGB(255, 182, 193)},
    {"LightSalmon", myRGB(255, 160, 122)},
    {"LightSeaGreen", myRGB(32, 178, 170)},
    {"LightSkyBlue", myRGB(135, 206, 250)},
    {"LightSlateBlue", myRGB(132, 112, 255)},
    {"LightSlateGray", myRGB(119, 136, 153)},
    {"LightSteelBlue", myRGB(124, 152, 211)},
    {"LightYellow", myRGB(255, 255, 224)},
    {"LimeGreen", myRGB(0, 175, 20)},
    {"linen", myRGB(250, 240, 230)},
    {"Magenta", myRGB(255, 0, 255)},
    {"Maroon", myRGB(143, 0, 82)},
    {"MediumAquamarine", myRGB(0, 147, 143)},
    {"MediumBlue", myRGB(50, 50, 204)},
    {"MediumForestGreen", myRGB(50, 129, 75)},
    {"MediumGoldenrod", myRGB(209, 193, 102)},
    {"MediumOrchid", myRGB(189, 82, 189)},
    {"MediumPurple", myRGB(147, 112, 219)},
    {"MediumSeaGreen", myRGB(52, 119, 102)},
    {"MediumSlateBlue", myRGB(106, 106, 141)},
    {"MediumSpringGreen", myRGB(35, 142, 35)},
    {"MediumTurquoise", myRGB(0, 210, 210)},
    {"MediumVioletRed", myRGB(213, 32, 121)},
    {"MidnightBlue", myRGB(47, 47, 100)},
    {"MintCream", myRGB(245, 255, 250)},
    {"MistyRose", myRGB(255, 228, 225)},
    {"moccasin", myRGB(255, 228, 181)},
    {"NavajoWhite", myRGB(255, 222, 173)},
    {"Navy", myRGB(35, 35, 117)},
    {"NavyBlue", myRGB(35, 35, 117)},
    {"OldLace", myRGB(253, 245, 230)},
    {"OliveDrab", myRGB(107, 142, 35)},
    {"Orange", myRGB(255, 135, 0)},
    {"OrangeRed", myRGB(255, 69, 0)},
    {"Orchid", myRGB(239, 132, 239)},
    {"PaleGoldenrod", myRGB(238, 232, 170)},
    {"PaleGreen", myRGB(115, 222, 120)},
    {"PaleTurquoise", myRGB(175, 238, 238)},
    {"PaleVioletRed", myRGB(219, 112, 147)},
    {"PapayaWhip", myRGB(255, 239, 213)},
    {"PeachPuff", myRGB(255, 218, 185)},
    {"peru", myRGB(205, 133, 63)},
    {"Pink", myRGB(255, 181, 197)},
    {"Plum", myRGB(197, 72, 155)},
    {"PowderBlue", myRGB(176, 224, 230)},
    {"purple", myRGB(160, 32, 240)},
    {"Red", myRGB(255, 0, 0)},
    {"RosyBrown", myRGB(188, 143, 143)},
    {"RoyalBlue", myRGB(65, 105, 225)},
    {"SaddleBrown", myRGB(139, 69, 19)},
    {"Salmon", myRGB(233, 150, 122)},
    {"SandyBrown", myRGB(244, 164, 96)},
    {"SeaGreen", myRGB(82, 149, 132)},
    {"seashell", myRGB(255, 245, 238)},
    {"Sienna", myRGB(150, 82, 45)},
    {"SkyBlue", myRGB(114, 159, 255)},
    {"SlateBlue", myRGB(126, 136, 171)},
    {"SlateGray", myRGB(112, 128, 144)},
    {"snow", myRGB(255, 250, 250)},
    {"SpringGreen", myRGB(65, 172, 65)},
    {"SteelBlue", myRGB(84, 112, 170)},
    {"Tan", myRGB(222, 184, 135)},
    {"Thistle", myRGB(216, 191, 216)},
    {"tomato", myRGB(255, 99, 71)},
    {"Transparent", myRGB(0, 0, 1)},
    {"Turquoise", myRGB(25, 204, 223)},
    {"Violet", myRGB(156, 62, 206)},
    {"VioletRed", myRGB(243, 62, 150)},
    {"Wheat", myRGB(245, 222, 179)},
    {"White", myRGB(255, 255, 255)},
    {"WhiteSmoke", myRGB(245, 245, 245)},
    {"Yellow", myRGB(255, 255, 0)},
    {"YellowGreen", myRGB(50, 216, 56)},
    NULL
};

static int numTheRGBRecords = 234;
