#ifndef __KEY_EVENT_DEAL_H__
#define __KEY_EVENT_DEAL_H__

#include "typedef.h"
#include "bt_profile_cfg.h"
#include "system/event.h"

enum {
    KEY_POWER_ON = KEY_EVENT_MAX,
    KEY_POWEROFF,
    KEY_POWEROFF_HOLD,
    KEY_MUSIC_PP,
    KEY_MUSIC_PREV,
    KEY_MUSIC_NEXT,
    KEY_VOL_UP,
    KEY_VOL_DOWN,
    KEY_CALL_LAST_NO,
    KEY_CALL_HANG_UP,
    KEY_CALL_ANSWER,
    KEY_OPEN_SIRI,
    KEY_HID_CONTROL,
    KEY_LOW_LANTECY,
    KEY_MODE_SWITCH,
   
    KEY_EQ_MODE,
    KEY_lONG_CLICK,
    KEY_DOUBLE_CLICK,
    KEY_THREE_CLICK,
    KEY_THIRD_CLICK,

#if (BT_FOR_APP_EN)
    KEY_SEND_SPEECH_START,
    KEY_SEND_SPEECH_STOP,
    KEY_AI_DEC_SUSPEND,
    KEY_AI_DEC_RESUME,

#if(USE_DMA_TONE)
    KEY_SEND_SPEECH_START_AFTER_TONE,
    KEY_DMA_CONNECTED_ALL_FINISH,
    KEY_DMA_NEED_CON_BT,
    KEY_DMA_A2DP_CONN,
    KEY_DMA_A2DP_DISCONN,
#endif
#endif

    KEY_EARTCH_ENABLE,
    KEY_EARTCH_DISABLE,
    KEY_ANC_SWITCH,
    KEY_MUSIC_EFF,  //播歌音效切换
    KEY_PHONE_PITCH,//通话上行 变声切换

    MSG_HALF_SECOND,
    KEY_NULL = 0xFF,
};

enum {
    ONE_KEY_CTL_NEXT_PREV = 1,
    ONE_KEY_CTL_VOL_UP_DOWN,
};

enum {
    EARTCH_STATE_IN,
    EARTCH_STATE_OUT,
};

extern int app_earphone_key_event_handler(struct sys_event *);

#endif
