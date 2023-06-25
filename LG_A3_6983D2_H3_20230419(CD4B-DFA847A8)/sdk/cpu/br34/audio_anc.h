#ifndef AUDIO_ANC_H
#define AUDIO_ANC_H

#include "generic/typedef.h"

#if 0
//#include "anc.h"


/*ANC初始化*/
void anc_init(void);

/*ANC训练模式*/
void anc_train_open(void);

/*
 *ANC状态获取
 *return 0: close(关闭)
 *return 1: open(ANC/通透/训练)
 */
u8 anc_status_get(void);

u8 anc_mode_get(void);

/*ANC模式切换*/
void anc_mode_switch(u8 mode);

/*ANC模式切换测试接口*/
void anc_mode_switch_test();

#endif

#endif
