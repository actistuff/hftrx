#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include "hardware.h"

#if defined (COLORPIP_SHADED)

	// цвета
	// от 0..COLORPIP_BASE - 1 - волопад
	// от COLORPIP_BASE..127 - yflgbcb надписи и элементы дизайна
	// то же с колом больше на 128 - затененные цвета для имитации полупрозрачности
	#define COLORPIP_BASE 112	// should be match to PALETTESIZE
	// Заполнение палитры производится в display2_xltrgb24()

	#define COLORPIP_YELLOW      (COLORPIP_BASE + 0) // TFTRGB(0xFF, 0xFF, 0x00)
	#define COLORPIP_ORANGE      (COLORPIP_BASE + 1) // TFTRGB(0xFF, 0xA5, 0x00)
	#define COLORPIP_BLACK       (COLORPIP_BASE + 2) // TFTRGB(0x00, 0x00, 0x00)
	#define COLORPIP_WHITE       (COLORPIP_BASE + 3) // TFTRGB(0xFF, 0xFF, 0xFF)
	#define COLORPIP_GRAY        (COLORPIP_BASE + 4) // TFTRGB(0x80, 0x80, 0x80)
	#define COLORPIP_DARKGRAY    (COLORPIP_BASE + 5) // TFTRGB(0x70, 0x70, 0x70) FIXME: use right value
	#define COLORPIP_DARKGREEN   (COLORPIP_BASE + 5) // TFTRGB(0x00, 0x64, 0x00)
	#define COLORPIP_BLUE        (COLORPIP_BASE + 6) // TFTRGB(0x00, 0x00, 0xFF)
	#define COLORPIP_GREEN       (COLORPIP_BASE + 7) // TFTRGB(0x00, 0xFF, 0x00)
	#define COLORPIP_RED         (COLORPIP_BASE + 8) // TFTRGB(0xFF, 0x00, 0x00)
	#define COLORPIP_LOCKED  	 (COLORPIP_BASE + 9) // TFTRGB(0x3C, 0x3C, 0x00)

	#define COLORPIP_GRIDCOLOR		(COLORPIP_BASE + 10) // TFTRGB565(128, 0, 0)		//COLOR_GRAY - center marker
	#define COLORPIP_GRIDCOLOR2		(COLORPIP_BASE + 11) // TFTRGB565(96, 96, 96)		//COLOR_DARKRED - other markers
	#define COLORPIP_SPECTRUMBG		(COLORPIP_BASE + 12) // TFTRGB565(0, 64, 24)			//
	#define COLORPIP_SPECTRUMBG2	(COLORPIP_BASE + 13) // TFTRGB565(0, 24, 8)		//COLOR_xxx - полоса пропускания приемника
	#define COLORPIP_SPECTRUMFG		(COLORPIP_BASE + 14) // TFTRGB565(0, 255, 0)		//COLOR_GREEN
	#define COLORPIP_SPECTRUMFENCE	(COLORPIP_BASE + 15) // TFTRGB565(255, 255, 255)	//COLOR_WHITE

	#if COLORSTYLE_ATS52
		// new (for ats52).
		#define COLORPIP_SPECTRUMLINE	COLORPIP_YELLOW

	#else
		// old
		//#define COLORPIP_SPECTRUMLINE	COLORPIP_GREEN
		#define COLORPIP_SPECTRUMLINE	COLORPIP_YELLOW

	#endif

	#if LCDMODE_MAIN_L8
		// Цвета, используемые на основном экране
		#define COLORMAIN_BLACK COLORPIP_BLACK
		#define COLORMAIN_WHITE COLORPIP_WHITE
		#define COLORMAIN_BLUE COLORPIP_BLUE
		#define COLORMAIN_GREEN COLORPIP_GREEN
		#define COLORMAIN_RED COLORPIP_RED
		#define COLORMAIN_GRAY COLORPIP_GRAY
		#define COLORMAIN_DARKGREEN COLORPIP_DARKGREEN
		#define COLORMAIN_YELLOW COLORPIP_YELLOW
		#define COLORMAIN_DARKRED  COLORPIP_GRIDCOLOR2	// COLORPIP_DARKRED
	#endif /* LCDMODE_MAIN_L8 */

#else /* LCDMODE_PIP_L8 */

	// определение основных цветов
	///

	/* RGB 24-bits color table definition (RGB888). */
	#define COLOR_BLACK          TFTRGB(0x00, 0x00, 0x00)
	#define COLOR_WHITE          TFTRGB(0xFF, 0xFF, 0xFF)
	#define COLOR_BLUE           TFTRGB(0x00, 0x00, 0xFF)
	#define COLOR_GREEN          TFTRGB(0x00, 0xFF, 0x00)
	#define COLOR_RED            TFTRGB(0xFF, 0x00, 0x00)
	#define COLOR_NAVY           TFTRGB(0x00, 0x00, 0x80)
	#define COLOR_DARKBLUE       TFTRGB(0x00, 0x00, 0x8B)
	#define COLOR_DARKGREEN      TFTRGB(0x00, 0x64, 0x00)
	#define COLOR_DARKGREEN2     TFTRGB(0x00, 0x20, 0x00)
	#define COLOR_DARKCYAN       TFTRGB(0x00, 0x8B, 0x8B)
	#define COLOR_CYAN           TFTRGB(0x00, 0xFF, 0xFF)
	#define COLOR_TURQUOISE      TFTRGB(0x40, 0xE0, 0xD0)
	#define COLOR_INDIGO         TFTRGB(0x4B, 0x00, 0x82)
	#define COLOR_DARKRED        TFTRGB(0x80, 0x00, 0x00)
	#define COLOR_DARKRED2       TFTRGB(0x40, 0x00, 0x00)
	#define COLOR_OLIVE          TFTRGB(0x80, 0x80, 0x00)
	#define COLOR_GRAY           TFTRGB(0x80, 0x80, 0x80)
	#define COLOR_SKYBLUE        TFTRGB(0x87, 0xCE, 0xEB)
	#define COLOR_BLUEVIOLET     TFTRGB(0x8A, 0x2B, 0xE2)
	#define COLOR_LIGHTGREEN     TFTRGB(0x90, 0xEE, 0x90)
	#define COLOR_DARKVIOLET     TFTRGB(0x94, 0x00, 0xD3)
	#define COLOR_YELLOWGREEN    TFTRGB(0x9A, 0xCD, 0x32)
	#define COLOR_BROWN          TFTRGB(0xA5, 0x2A, 0x2A)
	#define COLOR_DARKGRAY       TFTRGB(0xA9, 0xA9, 0xA9)
	#define COLOR_SIENNA         TFTRGB(0xA0, 0x52, 0x2D)
	#define COLOR_LIGHTBLUE      TFTRGB(0xAD, 0xD8, 0xE6)
	#define COLOR_GREENYELLOW    TFTRGB(0xAD, 0xFF, 0x2F)
	#define COLOR_SILVER         TFTRGB(0xC0, 0xC0, 0xC0)
	#define COLOR_LIGHTGREY      TFTRGB(0xD3, 0xD3, 0xD3)
	#define COLOR_LIGHTCYAN      TFTRGB(0xE0, 0xFF, 0xFF)
	#define COLOR_VIOLET         TFTRGB(0xEE, 0x82, 0xEE)
	#define COLOR_AZUR           TFTRGB(0xF0, 0xFF, 0xFF)
	#define COLOR_BEIGE          TFTRGB(0xF5, 0xF5, 0xDC)
	#define COLOR_MAGENTA        TFTRGB(0xFF, 0x00, 0xFF)
	#define COLOR_TOMATO         TFTRGB(0xFF, 0x63, 0x47)
	#define COLOR_GOLD           TFTRGB(0xFF, 0xD7, 0x00)
	#define COLOR_ORANGE         TFTRGB(0xFF, 0xA5, 0x00)
	#define COLOR_SNOW           TFTRGB(0xFF, 0xFA, 0xFA)
	#define COLOR_YELLOW         TFTRGB(0xFF, 0xFF, 0x00)
	#define COLOR_BROWN   		 TFTRGB(0xA5, 0x2A, 0x2A)	// коричневый
	#define COLOR_PEAR    		 TFTRGB(0xD1, 0xE2, 0x31)	// грушевый

	// Заполнение палитры производится в display2_xltrgb24()

	#define COLORPIP_YELLOW      TFTRGB565(0xFF, 0xFF, 0x00)
	#define COLORPIP_ORANGE      TFTRGB565(0xFF, 0xA5, 0x00)
	#define COLORPIP_BLACK       TFTRGB565(0x00, 0x00, 0x00)
	#define COLORPIP_WHITE       TFTRGB565(0xFF, 0xFF, 0xFF)
	#define COLORPIP_GRAY        TFTRGB565(0x80, 0x80, 0x80)
	#define COLORPIP_DARKGRAY    TFTRGB565(0x70, 0x70, 0x70)
	#define COLORPIP_DARKGREEN   TFTRGB565(0x00, 0x40, 0x00)
	#define COLORPIP_BLUE        TFTRGB565(0x00, 0x00, 0xFF)
	#define COLORPIP_GREEN       TFTRGB565(0x00, 0xFF, 0x00)
	#define COLORPIP_RED         TFTRGB565(0xFF, 0x00, 0x00)
	#define COLORPIP_LOCKED  	 TFTRGB565(0x3C, 0x3C, 0x00)

	#if COLORSTYLE_ATS52
		// new (for ats52).
		#define COLORPIP_GRIDCOLOR		TFTRGB565(128, 0, 0)		//COLOR_GRAY - center marker
		#define COLORPIP_GRIDCOLOR2		TFTRGB565(96, 96, 96)		//COLOR_DARKRED - other markers
		#define COLORPIP_SPECTRUMBG		TFTRGB565(0, 64, 24)			//
		#define COLORPIP_SPECTRUMBG2	TFTRGB565(0, 24, 8)		//COLOR_xxx - полоса пропускания приемника
		#define COLORPIP_SPECTRUMFG		TFTRGB565(0, 255, 0)		//COLOR_GREEN
		#define COLORPIP_SPECTRUMFENCE	TFTRGB565(255, 255, 255)	//COLOR_WHITE
		#define COLORPIP_SPECTRUMLINE	COLORPIP_YELLOW

	#else
		// old
		#define COLORPIP_GRIDCOLOR      TFTRGB565(128, 128, 0)        //COLOR_GRAY - center marker
		#define COLORPIP_GRIDCOLOR2     TFTRGB565(128, 0, 0x00)        //COLOR_DARKRED - other markers
		#define COLORPIP_SPECTRUMBG     TFTRGB565(0, 0, 0)            //COLOR_BLACK
		#define COLORPIP_SPECTRUMBG2    TFTRGB565(0, 128, 128)        //COLOR_CYAN - полоса пропускания приемника
		#define COLORPIP_SPECTRUMFG		TFTRGB565(0, 255, 0)		//COLOR_GREEN
		#define COLORPIP_SPECTRUMFENCE	TFTRGB565(255, 255, 255)	//COLOR_WHITE
		//#define COLORPIP_SPECTRUMLINE	COLORPIP_GREEN
		#define COLORPIP_SPECTRUMLINE	COLORPIP_YELLOW

	#endif


	// Цвета, используемые на основном экране
	#define COLORMAIN_BLACK COLOR_BLACK
	#define COLORMAIN_WHITE COLOR_WHITE
	#define COLORMAIN_BLUE COLOR_BLUE
	#define COLORMAIN_GREEN COLOR_GREEN
	#define COLORMAIN_RED COLOR_RED
	#define COLORMAIN_GRAY COLOR_GRAY
	#define COLORMAIN_DARKGREEN COLOR_DARKGREEN
	#define COLORMAIN_YELLOW COLOR_YELLOW
	#define COLORMAIN_DARKRED  COLOR_DARKRED

#endif /* LCDMODE_PIP_L8 */

#if LCDMODE_PIP_L8
	#define COLOR_BUTTON_NON_LOCKED		COLORPIP_GREEN
	#define COLOR_BUTTON_PR_NON_LOCKED	COLORPIP_DARKGREEN	// was: COLORPIP_DARKGREEN2
	#define COLOR_BUTTON_LOCKED			COLORPIP_YELLOW
	#define COLOR_BUTTON_PR_LOCKED		COLORPIP_LOCKED // TFTRGB565(0x3C, 0x3C, 0x00)
	#define COLOR_BUTTON_DISABLED		COLORPIP_GRAY // TFTRGB565(0x50, 0x50, 0x50) FIXME: use right value

#else /* LCDMODE_PIP_L8 */
	#define COLOR_BUTTON_NON_LOCKED		COLORPIP_GREEN
	#define COLOR_BUTTON_PR_NON_LOCKED	COLORPIP_DARKGREEN
	#define COLOR_BUTTON_LOCKED			COLORPIP_YELLOW
	#define COLOR_BUTTON_PR_LOCKED		COLORPIP_LOCKED // TFTRGB565(0x3C, 0x3C, 0x00)
	#define COLOR_BUTTON_DISABLED		COLORPIP_GRAY

#endif /* LCDMODE_PIP_L8 */

// Цвета используемые для отображения
// различных элементов на основном экране.

#define LCOLOR	COLORMAIN_GREEN		// цвет левой половины S-метра
#define RCOLOR	COLORMAIN_RED			// цвет правой половины S-метра
#define PWRCOLOR	COLORMAIN_RED		// цвет измерителя мощности
#define SWRCOLOR	COLORMAIN_YELLOW		// цвет SWR-метра

#define OVFCOLOR COLORMAIN_RED
#define LOCKCOLOR COLORMAIN_RED
#define MODECOLOR COLORMAIN_WHITE
#define TXRXMODECOLOR COLORMAIN_BLACK
#define MODECOLORBG_TX COLORMAIN_RED
#define MODECOLORBG_RX	COLORMAIN_GREEN

#define MENUGROUPCOLOR COLORMAIN_YELLOW
#define MENUCOLOR COLORMAIN_WHITE
#define MNUVALCOLOR COLORMAIN_WHITE
#define MENUSELCOLOR	COLORMAIN_GREEN

#if COLORSTYLE_RED
	// "All-in-red": FT1000 inspired color scheme
	#define DESIGNBIGCOLOR COLORMAIN_RED 		// DARK RED
	//#define DESIGNBIGCOLORHALF COLORMAIN_RED 	// DARK RED
	#define DESIGNCOLORSTATE	COLORMAIN_RED
	#define DESIGNCOLORDARKSTATE	COLORMAIN_DARKRED

#else /* COLORSTYLE_RED */
	#define DESIGNBIGCOLOR COLORMAIN_YELLOW 		// GOLD
	//#define DESIGNBIGCOLORHALF COLORMAIN_YELLOW
	#define DESIGNCOLORSTATE	COLORMAIN_GREEN
	#define DESIGNCOLORDARKSTATE	COLORMAIN_DARKGREEN

#endif /* COLORSTYLE_RED */

void display_smeter2(uint_fast8_t x, uint_fast8_t y, void * pv);

#if WITHTOUCHGUI

	void button9_handler(void);
	void encoder2_menu (enc2_menu_t * enc2_menu);
	void display_pip_update(uint_fast8_t x, uint_fast8_t y, void * pv);

#endif /* #if WITHTOUCHGUI */
#endif /* GUI_H_INCLUDED */
