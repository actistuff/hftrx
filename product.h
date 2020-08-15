/* $Id$ */
// В проекте используется файл product.h - данный файл (product.h.prototype) копируется и переименовывается в product.h. Для компиляции требуется выбрать одну из конфигураций.

#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#ifndef HARDWARE_H_INCLUDED
	#error PLEASE, DO NOT USE THIS FILE DIRECTLY. USE FILE "hardware.h" INSTEAD.
#endif

#define DEBUGSPEED 115200L
#define CTLSTYLE_STORCH_V7	1	// rmainunit_v5km0.pcb, rmainunit_v5km1.pcb STM32H743IIT6, TFT 4.3", 2xUSB, SD-CARD, NAU8822L и FPGA EP4CE22E22I7N
#include "boards/arm_stm32h7xx_tqfp208_ctlstyle_storch_v7z_no_radio.h"	// Плата evg_cimb@mail.ru TQFP208
#include "paramdepend.h"							/* проверка зависимостей параметров конфигурации */
#include "boards/arm_stm32h7xx_tqfp208_cpustyle_storch_v7z.h"	// Плата evg_cimb@mail.ru TQFP208
#include "radio.h"	/* Определения, специфические для устройств, относящихся к радиосвязи. */

#endif /* PRODUCT_H_INCLUDED */
