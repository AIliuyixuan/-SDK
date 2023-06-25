#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

/*
 *  板级配置选择
 */

// #define CONFIG_BOARD_AD698X_DEMO
//#define CONFIG_BOARD_AD6983E_DEMO
//#define CONFIG_BOARD_AD6986A
//#define CONFIG_BOARD_AD6983A
#define CONFIG_BOARD_AD6983D

#include "board_ad698x_demo_cfg.h"
#include "board_ad6983e_demo_cfg.h"
#include "board_ad6986a_cfg.h"
#include "board_ad6983a_cfg.h"
#include "board_ad6983d_cfg.h"

#define  DUT_AUDIO_DAC_LDO_VOLT                 DACVDD_LDO_1_25V

#endif
