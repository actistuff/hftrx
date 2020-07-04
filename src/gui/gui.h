#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include "hardware.h"
#include "../display/display.h"
#include "display2.h"

#define GUIMINX					800							// минимальное разрешение для touch GUI
#define GUIMINY					480
#define WITHGUIMAXX				DIM_X
#define WITHGUIMAXY				DIM_Y

#if (DIM_X < GUIMINX || DIM_Y < GUIMINY) && WITHTOUCHGUI	// не соблюдены минимальные требования к разрешению экрана
	#undef WITHTOUCHGUI										// для функционирования touch GUI
#endif

#if WITHGUIMAXX != GUIMINX									// дизайн GUI в данный момент только для 800х480,
	#undef WITHGUIMAXX
	#define WITHGUIMAXX 		GUIMINX
#endif

#if WITHGUIMAXY != GUIMINY									// при большем разрешении интерфейс будет сжат до 800х480.
	#undef WITHGUIMAXY
	#define WITHGUIMAXY 		GUIMINY
#endif

#if WITHTOUCHGUI

#if ! defined WITHUSEMALLOC									// необходима поддержка динамического управления памятью
	#define WITHUSEMALLOC		1
#endif /* ! defined WITHUSEMALLOC */

#if ! defined WITHGUIHEAP || WITHGUIHEAP < (80 * 1024uL)	// требуемый размер кучи для touch GUI
	#undef WITHGUIHEAP
	#define WITHGUIHEAP 		(80 * 1024uL)
#endif /* ! defined WITHGUIHEAP || WITHGUIHEAP < (80 * 1024uL) */

typedef struct {
	char name[20];
	uint_fast8_t index;
} menu_names_t;

typedef struct {
	char param[20];
	char val[20];
	uint_fast8_t state;
	uint_fast8_t updated;
} enc2_menu_t;

enum {
	memory_cells_count = 20
};

typedef struct {
	int_fast32_t freq;
	int_fast8_t submode;
} memory_t;

uint_fast8_t hamradio_get_multilinemenu_block_groups(menu_names_t * vals);
uint_fast8_t hamradio_get_multilinemenu_block_params(menu_names_t * vals, uint_fast8_t index);
void hamradio_get_multilinemenu_block_vals(menu_names_t * vals, uint_fast8_t index, uint_fast8_t cnt);
const char * hamradio_gui_edit_menu_item(uint_fast8_t index, int_least16_t rotate);
void hamradio_save_memory_cells(uint_fast8_t i);
void hamradio_load_memory_cells(memory_t * mc, uint_fast8_t i, uint_fast8_t set);

void gui_encoder2_menu(enc2_menu_t * enc2_menu);
void gui_WM_walktrough(uint_fast8_t x, uint_fast8_t y, dctx_t * pctx);
void gui_initialize(void);
void gui_check_encoder2(int_least16_t rotate);
void gui_set_encoder2_state(uint_fast8_t code);
void gui_put_keyb_code(uint_fast8_t kbch);
void gui_uif_editmenu(const char * name, uint_fast16_t menupos, uint_fast8_t exitkey);
void gui_open_sys_menu(void);
void gui_timer_update (void * arg);

#endif /* WITHTOUCHGUI */
#endif /* GUI_H_INCLUDED */
