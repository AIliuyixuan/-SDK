#ifndef CONFIG_BOARD_AD698X_DEMO_CFG_H
#define CONFIG_BOARD_AD698X_DEMO_CFG_H

#ifdef CONFIG_BOARD_AD698X_DEMO

#define CONFIG_SDFILE_ENABLE
#define CONFIG_FLASH_SIZE       (1024 * 1024)

//*********************************************************************************//
//                                 配置开始                                        //
//*********************************************************************************//
#define ENABLE_THIS_MOUDLE					1
#define DISABLE_THIS_MOUDLE					0

#define ENABLE								1
#define DISABLE								0

#define NO_CONFIG_PORT						(-1)

//*********************************************************************************//
//                                 UART配置                                        //
//*********************************************************************************//
#define TCFG_UART0_ENABLE					ENABLE_THIS_MOUDLE                     //串口打印模块使能
#define TCFG_UART0_RX_PORT					NO_CONFIG_PORT                         //串口接收脚配置（用于打印可以选择NO_CONFIG_PORT）
#define TCFG_UART0_TX_PORT  				IO_PORTA_05                             //串口发送脚配置
#define TCFG_UART0_BAUDRATE  				1000000                                //串口波特率配置


//*********************************************************************************//
//                                 硬件SPI 配置                                    //
//*********************************************************************************//
#define TCFG_HW_SPI1_ENABLE                 ENABLE_THIS_MOUDLE
#define TCFG_HW_SPI1_PORT_CLK               IO_PORTC_04// NO_CONFIG_PORT//IO_PORTA_00
#define TCFG_HW_SPI1_PORT_DO                IO_PORTC_05//NO_CONFIG_PORT//IO_PORTA_01
#define TCFG_HW_SPI1_PORT_DI                NO_CONFIG_PORT// IO_PORTC_03
#define TCFG_HW_SPI1_BAUD                   2000000L
#define TCFG_HW_SPI1_MODE                   SPI_MODE_BIDIR_1BIT
#define TCFG_HW_SPI1_ROLE                   SPI_ROLE_MASTER

#define TCFG_HW_SPI2_ENABLE                 ENABLE_THIS_MOUDLE
#define TCFG_HW_SPI2_PORT_CLK               NO_CONFIG_PORT
#define TCFG_HW_SPI2_PORT_DO                NO_CONFIG_PORT
#define TCFG_HW_SPI2_PORT_DI                NO_CONFIG_PORT
#define TCFG_HW_SPI2_BAUD                   2000000L
#define TCFG_HW_SPI2_MODE                   SPI_MODE_BIDIR_1BIT
#define TCFG_HW_SPI2_ROLE                   SPI_ROLE_MASTER


//*********************************************************************************//
//                                  UI 配置                                        //
//*********************************************************************************//

#define TCFG_UI_ENABLE 						0//ENABLE_THIS_MOUDLE 	//UI总开关
// #define CONFIG_UI_STYLE                     STYLE_JL_SOUNDBOX
#define CONFIG_UI_STYLE                  STYLE_UI_SIMPLE //这是309 sdk ui 风格 需要再开启TCFG_SIMPLE_LCD_ENABLE
#define TCFG_LRC_LYRICS_ENABLE             0// ENABLE_THIS_MOUDLE  //歌词显示
#define TCFG_LCD_OLED_ENABLE	            ENABLE_THIS_MOUDLE
// #define TCFG_SPI_LCD_ENABLE                 0//ENABLE_THIS_MOUDLE //spi lcd开关
#define TCFG_SIMPLE_LCD_ENABLE             1// DISABLE_THIS_MOUDLE//去ui 框架的驱动开关 开启请关闭了TCFG_SPI_LCD_ENABLE
#define TCFG_TFT_LCD_DEV_SPI_HW_NUM			 1// 1: SPI1    2: SPI2 配置lcd选择的spi口
#define LCD_SPI_INTERRUPT_ENABLE             0//默认开启 需要主动关闭
#define ALL_KEY_EVENT_CLICK_ONLY	         0 	//是否全部按键只响应单击事件
#define APP_CASE_EARPHONE                     1


//*********************************************************************************//
//                                 IIC配置                                        //
//*********************************************************************************//
/*软件IIC设置*/
#define TCFG_SW_I2C0_CLK_PORT               IO_PORTA_09                             //软件IIC  CLK脚选择
#define TCFG_SW_I2C0_DAT_PORT               IO_PORTA_10                             //软件IIC  DAT脚选择
#define TCFG_SW_I2C0_DELAY_CNT              50                                      //IIC延时参数，影响通讯时钟频率

/*硬件IIC端口选择
  SCL         SDA
  'A': IO_PORT_DP   IO_PORT_DM
  'B': IO_PORTA_09  IO_PORTA_10
  'C': IO_PORTA_07  IO_PORTA_08
  'D': IO_PORTA_05  IO_PORTA_06
 */
#define TCFG_HW_I2C0_PORTS                  'B'
#define TCFG_HW_I2C0_CLK                    100000                                  //硬件IIC波特率

//*********************************************************************************//
//                                  SD 配置                                        //
//*********************************************************************************//
#define TCFG_SD0_ENABLE						DISABLE_THIS_MOUDLE                    //SD0模块使能
#define TCFG_SD0_DAT_MODE					1               //线数设置，1：一线模式  4：四线模式
#define TCFG_SD0_DET_MODE					SD_IO_DECT     //SD卡检测方式
#define TCFG_SD0_DET_IO                     IO_PORTB_03      //当检测方式为IO检测可用
#define TCFG_SD0_DET_IO_LEVEL               0               //当检测方式为IO检测可用,0：低电平检测到卡。 1：高电平(外部电源)检测到卡。 2：高电平(SD卡电源)检测到卡。
#define TCFG_SD0_CLK						(3000000 * 4L)  //SD卡时钟频率设置
#define TCFG_SD0_PORT_CMD					IO_PORTB_00
#define TCFG_SD0_PORT_CLK					IO_PORTB_01
#define TCFG_SD0_PORT_DA0					IO_PORTB_02
#define TCFG_SD0_PORT_DA1					NO_CONFIG_PORT  //当选择4线模式时要用
#define TCFG_SD0_PORT_DA2					NO_CONFIG_PORT
#define TCFG_SD0_PORT_DA3					NO_CONFIG_PORT
//*********************************************************************************//
//                                 key 配置                                        //
//*********************************************************************************//
#define KEY_NUM_MAX                        	10
#define KEY_NUM                            	3

#define MULT_KEY_ENABLE						DISABLE 		//是否使能组合按键消息, 使能后需要配置组合按键映射表
//*********************************************************************************//
//                                 iokey 配置                                      //
//*********************************************************************************//
#define TCFG_IOKEY_ENABLE					DISABLE_THIS_MOUDLE //是否使能IO按键

#define TCFG_IOKEY_POWER_CONNECT_WAY		ONE_PORT_TO_LOW    //按键一端接低电平一端接IO
#define TCFG_IOKEY_POWER_ONE_PORT			IO_PORTB_01        //IO按键端口

//*********************************************************************************//
//                                 adkey 配置                                      //
//*********************************************************************************//
#define TCFG_ADKEY_ENABLE                   DISABLE_THIS_MOUDLE//是否使能AD按键
#define TCFG_ADKEY_PORT                     IO_PORT_DM         //AD按键端口(需要注意选择的IO口是否支持AD功能)
/*AD通道选择，需要和AD按键的端口相对应:
    AD_CH_PA1    AD_CH_PA3    AD_CH_PA4    AD_CH_PA5
    AD_CH_PA9    AD_CH_PA1    AD_CH_PB1    AD_CH_PB4
    AD_CH_PB6    AD_CH_PB7    AD_CH_DP     AD_CH_DM
    AD_CH_PB2
*/
#define TCFG_ADKEY_AD_CHANNEL               AD_CH_DM
#define TCFG_ADKEY_EXTERN_UP_ENABLE         ENABLE_THIS_MOUDLE //是否使用外部上拉

#if TCFG_ADKEY_EXTERN_UP_ENABLE
#define R_UP    220                 //22K，外部上拉阻值在此自行设置
#else
#define R_UP    100                 //10K，内部上拉默认10K
#endif

//必须从小到大填电阻，没有则同VDDIO,填0x3ffL
#define TCFG_ADKEY_AD0      (0)                                 //0R
#define TCFG_ADKEY_AD1      (0x3ffL * 30   / (30   + R_UP))     //3k
#define TCFG_ADKEY_AD2      (0x3ffL * 62   / (62   + R_UP))     //6.2k
#define TCFG_ADKEY_AD3      (0x3ffL * 91   / (91   + R_UP))     //9.1k
#define TCFG_ADKEY_AD4      (0x3ffL * 150  / (150  + R_UP))     //15k
#define TCFG_ADKEY_AD5      (0x3ffL * 240  / (240  + R_UP))     //24k
#define TCFG_ADKEY_AD6      (0x3ffL * 330  / (330  + R_UP))     //33k
#define TCFG_ADKEY_AD7      (0x3ffL * 510  / (510  + R_UP))     //51k
#define TCFG_ADKEY_AD8      (0x3ffL * 1000 / (1000 + R_UP))     //100k
#define TCFG_ADKEY_AD9      (0x3ffL * 2200 / (2200 + R_UP))     //220k
#define TCFG_ADKEY_VDDIO    (0x3ffL)

#define TCFG_ADKEY_VOLTAGE0 ((TCFG_ADKEY_AD0 + TCFG_ADKEY_AD1) / 2)
#define TCFG_ADKEY_VOLTAGE1 ((TCFG_ADKEY_AD1 + TCFG_ADKEY_AD2) / 2)
#define TCFG_ADKEY_VOLTAGE2 ((TCFG_ADKEY_AD2 + TCFG_ADKEY_AD3) / 2)
#define TCFG_ADKEY_VOLTAGE3 ((TCFG_ADKEY_AD3 + TCFG_ADKEY_AD4) / 2)
#define TCFG_ADKEY_VOLTAGE4 ((TCFG_ADKEY_AD4 + TCFG_ADKEY_AD5) / 2)
#define TCFG_ADKEY_VOLTAGE5 ((TCFG_ADKEY_AD5 + TCFG_ADKEY_AD6) / 2)
#define TCFG_ADKEY_VOLTAGE6 ((TCFG_ADKEY_AD6 + TCFG_ADKEY_AD7) / 2)
#define TCFG_ADKEY_VOLTAGE7 ((TCFG_ADKEY_AD7 + TCFG_ADKEY_AD8) / 2)
#define TCFG_ADKEY_VOLTAGE8 ((TCFG_ADKEY_AD8 + TCFG_ADKEY_AD9) / 2)
#define TCFG_ADKEY_VOLTAGE9 ((TCFG_ADKEY_AD9 + TCFG_ADKEY_VDDIO) / 2)

#define TCFG_ADKEY_VALUE0                   0
#define TCFG_ADKEY_VALUE1                   1
#define TCFG_ADKEY_VALUE2                   2
#define TCFG_ADKEY_VALUE3                   3
#define TCFG_ADKEY_VALUE4                   4
#define TCFG_ADKEY_VALUE5                   5
#define TCFG_ADKEY_VALUE6                   6
#define TCFG_ADKEY_VALUE7                   7
#define TCFG_ADKEY_VALUE8                   8
#define TCFG_ADKEY_VALUE9                   9

//*********************************************************************************//
//                                 irkey 配置                                      //
//*********************************************************************************//
#define TCFG_IRKEY_ENABLE                   DISABLE_THIS_MOUDLE//是否使能AD按键
#define TCFG_IRKEY_PORT                     IO_PORTA_08        //IR按键端口


//*********************************************************************************//
//                             lp tocuh key 配置                                   //
//*********************************************************************************//
#define TCFG_LP_TOUCH_KEY_ENABLE 			ENABLE_THIS_MOUDLE 	//是否使能触摸按键
#define TCFG_LP_EARTCH_KEY_ENABLE 			ENABLE_THIS_MOUDLE 	//是否使能CH1
//内置触摸灵敏度调试工具使能, 使能后可以通过连接PC端上位机通过SPP调试,
//打开该宏需要确保同时打开宏:
//1.USER_SUPPORT_PROFILE_SPP
//2.APP_ONLINE_DEBUG
//可以针对每款样机校准灵敏度参数表(在lp_touch_key.c ch_sensitivity_table), 详细使用方法请参考《低功耗内置触摸介绍》文档.
#define TCFG_LP_TOUCH_KEY_BT_TOOL_ENABLE 	DISABLE //是否使能内置触摸调试功能

//电容检测灵敏度级数配置(范围: 0 ~ 9)
//该参数配置与触摸时电容变化量有关, 触摸时电容变化量跟模具厚度, 触摸片材质, 面积等有关,
//触摸时电容变化量越小, 推荐选择灵敏度级数越大,
//触摸时电容变化量越大, 推荐选择灵敏度级数越小,
//用户可以从灵敏度级数为0开始调试, 级数逐渐增大, 直到选择一个合适的灵敏度配置值.
#define TCFG_LP_TOUCH_KEY_SENSITIVITY 			5 	//触摸按键电容检测灵敏度配置(级数0 ~ 9)
#define TCFG_EARIN_TOUCH_KEY_SENSITIVITY 		5 	//触摸按键电容检测灵敏度配置(级数0 ~ 9)

#if TCFG_LP_TOUCH_KEY_ENABLE
//取消外置触摸的一些宏定义
#ifdef TCFG_IOKEY_ENABLE
#undef TCFG_IOKEY_ENABLE
#define TCFG_IOKEY_ENABLE 					DISABLE_THIS_MOUDLE
#endif /* #ifdef TCFG_IOKEY_ENABLE */
#endif /* #if TCFG_LP_TOUCH_KEY_ENABLE */



//*********************************************************************************//
//                                 Audio配置                                       //
//*********************************************************************************//
#define TCFG_AUDIO_ADC_ENABLE				ENABLE_THIS_MOUDLE
//MIC只有一个声道
#define TCFG_AUDIO_ADC_MIC_CHA				LADC_CH_MIC_L
#define TCFG_AUDIO_ADC_LINE_CHA				LADC_LINE0_MASK
/*MIC LDO电流档位设置：
    0:5ua    1:10ua    2:15ua    3:20ua*/
#define TCFG_AUDIO_ADC_LD0_SEL				3

#define TCFG_AUDIO_DAC_ENABLE				ENABLE_THIS_MOUDLE

#define TCFG_AUDIO_DAC_LDO_VOLT				DACVDD_LDO_1_25V
/*
DAC硬件上的连接方式,可选的配置：
    DAC_OUTPUT_MONO_L               左声道
    DAC_OUTPUT_MONO_R               右声道
    DAC_OUTPUT_LR                   立体声
    DAC_OUTPUT_MONO_LR_DIFF         单声道差分输出
*/
#define TCFG_AUDIO_DAC_CONNECT_MODE         DAC_OUTPUT_MONO_LR_DIFF

#define TCFG_AUDIO_DUAL_MIC_ENABLE			DISABLE_THIS_MOUDLE
#define TCFG_AUDIO_NOISE_GATE				DISABLE_THIS_MOUDLE

/*通话下行降噪使能*/
#define TCFG_ESCO_DL_NS_ENABLE				DISABLE_THIS_MOUDLE
/*
 *系统音量类型选择
 *软件数字音量是指纯软件对声音进行运算后得到的
 *硬件数字音量是指dac内部数字模块对声音进行运算后输出
 */
#define VOL_TYPE_DIGITAL		0	//软件数字音量
#define VOL_TYPE_ANALOG			1	//硬件模拟音量
#define VOL_TYPE_AD				2	//联合音量(模拟数字混合调节)
#define VOL_TYPE_DIGITAL_HW		3  	//硬件数字音量
#define SYS_VOL_TYPE            VOL_TYPE_DIGITAL
/*
 *通话的时候使用数字音量
 *0：通话使用和SYS_VOL_TYPE一样的音量调节类型
 *1：通话使用数字音量调节，更加平滑
 */
#define TCFG_CALL_USE_DIGITAL_VOLUME		1
/*
 *支持省电容MIC模块
 *(1)要使能省电容mic,首先要支持该模块:TCFG_SUPPORT_MIC_CAPLESS
 *(2)只有支持该模块，才能使能该模块:TCFG_MIC_CAPLESS_ENABLE
 */
#define TCFG_SUPPORT_MIC_CAPLESS			ENABLE_THIS_MOUDLE
//省电容MIC使能
#define TCFG_MIC_CAPLESS_ENABLE				ENABLE_THIS_MOUDLE

// AUTOMUTE
#define AUDIO_OUTPUT_AUTOMUTE               DISABLE_THIS_MOUDLE

#define TCFG_WAV_TONE_MIX_ENABLE			DISABLE

//*********************************************************************************//
//                           编解码格式配置(CodecFormat)                           //
//*********************************************************************************//
#define TCFG_DEC_MP3_ENABLE                 DISABLE
#define TCFG_DEC_WTGV2_ENABLE				DISABLE



//*********************************************************************************//
//                                  充电仓配置                                     //
//*********************************************************************************//
#define TCFG_CHARGESTORE_ENABLE				DISABLE_THIS_MOUDLE       //是否支持智能充点仓
#define TCFG_TEST_BOX_ENABLE			    1
#define TCFG_CHARGESTORE_PORT				IO_PORTP_00               //耳机和充点仓通讯的IO口
#define TCFG_CHARGESTORE_UART_ID			IRQ_UART1_IDX             //通讯使用的串口号

//*********************************************************************************//
//                                  充电参数配置                                   //
//*********************************************************************************//
//是否支持芯片内置充电
#define TCFG_CHARGE_ENABLE					ENABLE_THIS_MOUDLE
//是否支持开机充电
#define TCFG_CHARGE_POWERON_ENABLE			DISABLE
//是否支持拔出充电自动开机功能
#define TCFG_CHARGE_OFF_POWERON_NE			ENABLE
/*
充电截止电压可选配置：
    CHARGE_FULL_V_3962  CHARGE_FULL_V_4002  CHARGE_FULL_V_4044  CHARGE_FULL_V_4086
    CHARGE_FULL_V_4130  CHARGE_FULL_V_4175  CHARGE_FULL_V_4222  CHARGE_FULL_V_4270
    CHARGE_FULL_V_4308  CHARGE_FULL_V_4349  CHARGE_FULL_V_4391  CHARGE_FULL_V_4434
    CHARGE_FULL_V_4472  CHARGE_FULL_V_4517  CHARGE_FULL_V_4564  CHARGE_FULL_V_4611
*/
#define TCFG_CHARGE_FULL_V					CHARGE_FULL_V_4175
/*
充电截止电流可选配置：
    CHARGE_FULL_mA_2	CHARGE_FULL_mA_5	CHARGE_FULL_mA_7	 CHARGE_FULL_mA_10
    CHARGE_FULL_mA_15	CHARGE_FULL_mA_20	CHARGE_FULL_mA_25	 CHARGE_FULL_mA_30
*/
#define TCFG_CHARGE_FULL_MA					CHARGE_FULL_mA_5
/*
充电电流可选配置：
    CHARGE_mA_20		CHARGE_mA_30		CHARGE_mA_40		CHARGE_mA_50
    CHARGE_mA_60		CHARGE_mA_70		CHARGE_mA_80		CHARGE_mA_90
    CHARGE_mA_100		CHARGE_mA_110		CHARGE_mA_120		CHARGE_mA_140
    CHARGE_mA_160		CHARGE_mA_180		CHARGE_mA_200		CHARGE_mA_220
 */
#define TCFG_CHARGE_MA						CHARGE_mA_20

//*********************************************************************************//
//                                  LED 配置                                       //
//*********************************************************************************//
#define TCFG_PWMLED_ENABLE					DISABLE_THIS_MOUDLE			//是否支持PMW LED推灯模块
#define TCFG_PWMLED_IOMODE					LED_ONE_IO_MODE				//LED模式，单IO还是两个IO推灯
#define TCFG_PWMLED_PIN						IO_PORTB_06					//LED使用的IO口
//*********************************************************************************//
//                                  时钟配置                                       //
//*********************************************************************************//
#define TCFG_CLOCK_SYS_SRC					SYS_CLOCK_INPUT_PLL_BT_OSC   //系统时钟源选择
//#define TCFG_CLOCK_SYS_HZ					12000000                     //系统时钟设置
//#define TCFG_CLOCK_SYS_HZ					16000000                     //系统时钟设置
#define TCFG_CLOCK_SYS_HZ					24000000                     //系统时钟设置
//#define TCFG_CLOCK_SYS_HZ					32000000                     //系统时钟设置
//#define TCFG_CLOCK_SYS_HZ					48000000                     //系统时钟设置
//#define TCFG_CLOCK_SYS_HZ					54000000                     //系统时钟设置
//#define TCFG_CLOCK_SYS_HZ					64000000                     //系统时钟设置
#define TCFG_CLOCK_OSC_HZ					24000000                     //外界晶振频率设置
#define TCFG_CLOCK_MODE                     CLOCK_MODE_ADAPTIVE

//*********************************************************************************//
//                                  低功耗配置                                     //
//*********************************************************************************//
#define TCFG_LOWPOWER_POWER_SEL				PWR_DCDC15//PWR_LDO15                    //电源模式设置，可选DCDC和LDO
#define TCFG_LOWPOWER_BTOSC_DISABLE			0                            //低功耗模式下BTOSC是否保持
#define TCFG_LOWPOWER_LOWPOWER_SEL			1   //芯片是否进入powerdown
/*强VDDIO等级配置,可选：
    VDDIOM_VOL_20V    VDDIOM_VOL_22V    VDDIOM_VOL_24V    VDDIOM_VOL_26V
    VDDIOM_VOL_30V    VDDIOM_VOL_30V    VDDIOM_VOL_32V    VDDIOM_VOL_36V*/
#define TCFG_LOWPOWER_VDDIOM_LEVEL			VDDIOM_VOL_28V
/*弱VDDIO等级配置，可选：
    VDDIOW_VOL_21V    VDDIOW_VOL_24V    VDDIOW_VOL_28V    VDDIOW_VOL_32V*/
#define TCFG_LOWPOWER_VDDIOW_LEVEL			VDDIOW_VOL_26V               //弱VDDIO等级配置
#define TCFG_LOWPOWER_OSC_TYPE              OSC_TYPE_LRC

//*********************************************************************************//
//                                  EQ配置                                         //
//*********************************************************************************//
//EQ配置，使用在线EQ时，EQ文件和EQ模式无效。有EQ文件时，默认不用EQ模式切换功能
#define TCFG_EQ_ENABLE                            1     //支持EQ功能
#if TCFG_EQ_ENABLE
#define TCFG_EQ_ONLINE_ENABLE                     0     //支持在线EQ调试,如果使用蓝牙串口调试，需要打开宏 APP_ONLINE_DEBUG，否则，默认使用uart调试(二选一)
#define TCFG_BT_MUSIC_EQ_ENABLE                   0     //支持蓝牙音乐EQ
#define TCFG_PHONE_EQ_ENABLE                      0     //支持通话近端EQ
#define TCFG_AUDIO_OUT_EQ_ENABLE                  0     //mix out级，增加eq高低音接口
#define TCFG_AEC_DCCS_EQ_ENABLE           		  1     // AEC DCCS
#define TCFG_AEC_UL_EQ_ENABLE           		  1     // AEC UL

#define TCFG_USE_EQ_FILE                          1    //是否使能默认系数表 1：不使能  0:使能
#define EQ_SECTION_MAX                            10     //eq 段数，最大20
#endif//TCFG_EQ_ENABLE

/*省电容mic通过eq模块实现去直流滤波*/
#if (TCFG_SUPPORT_MIC_CAPLESS && TCFG_MIC_CAPLESS_ENABLE)
#if ((TCFG_EQ_ENABLE == 0) || (TCFG_AEC_DCCS_EQ_ENABLE == 0))
#error "MicCapless enable,Please enable TCFG_EQ_ENABLE and TCFG_AEC_DCCS_EQ_ENABLE"
#endif
#endif/*TCFG_SUPPORT_MIC_CAPLESS*/

#define TCFG_DRC_ENABLE							  0	  //DRC
#define TCFG_BT_MUSIC_DRC_ENABLE            	  0     //支持蓝牙音乐DRC

// ONLINE CCONFIG
#define TCFG_ONLINE_ENABLE                        (TCFG_EQ_ONLINE_ENABLE)    //是否支持EQ在线调试功能
#define TCFG_ONLINE_TX_PORT						  IO_PORT_DP                 //EQ调试TX口选择
#define TCFG_ONLINE_RX_PORT						  IO_PORT_DM                 //EQ调试RX口选择


//*********************************************************************************//
//                                  g-sensor配置                                   //
//*********************************************************************************//
#define TCFG_GSENSOR_ENABLE                       0     //gSensor使能
#define TCFG_DA230_EN                             0
#define TCFG_SC7A20_EN                            0
#define TCFG_STK8321_EN                           0
#define TCFG_GSENOR_USER_IIC_TYPE                 0     //0:软件IIC  1:硬件IIC

//*********************************************************************************//
//                                  系统配置                                         //
//*********************************************************************************//
#define TCFG_AUTO_SHUT_DOWN_TIME		          120   //没有蓝牙连接自动关机时间
#define TCFG_SYS_LVD_EN						      1   //电量检测使能
#define TCFG_POWER_ON_NEED_KEY				      0	  //是否需要按按键开机配置

#define AUDIO_OUT_MIXER_ENABLE					  1	  // AUIDO输出使用mixer


//*********************************************************************************//
//                                  蓝牙配置                                       //
//*********************************************************************************//
#define TCFG_USER_TWS_ENABLE                      1   //tws功能使能
#define TCFG_USER_BLE_ENABLE                      0   //BLE功能使能
#define TCFG_BT_SUPPORT_AAC                       0   //AAC格式支持

#define USER_SUPPORT_PROFILE_SPP                  0
#define USER_SUPPORT_PROFILE_HFP                  1
#define USER_SUPPORT_PROFILE_A2DP                 1
#define USER_SUPPORT_PROFILE_AVCTP                1
#define USER_SUPPORT_PROFILE_HID                  0
#define USER_SUPPORT_PROFILE_PNP                  1
#define USER_SUPPORT_PROFILE_PBAP                 0

#if TCFG_USER_TWS_ENABLE
#define TCFG_BD_NUM						          1   //连接设备个数配置
#define TCFG_AUTO_STOP_PAGE_SCAN_TIME             0   //配置一拖二第一台连接后自动关闭PAGE SCAN的时间(单位分钟)
#else
#define TCFG_BD_NUM						          2   //连接设备个数配置
#define TCFG_AUTO_STOP_PAGE_SCAN_TIME             0 //配置一拖二第一台连接后自动关闭PAGE SCAN的时间(单位分钟)
#endif


#define APP_ONLINE_DEBUG            0//在线APP调试,发布默认不开
#if (APP_ONLINE_DEBUG && TCFG_ONLINE_ENABLE)//使能蓝牙串口在线调试时，关闭普通串口在线调试
#undef TCFG_ONLINE_ENABLE
#define TCFG_ONLINE_ENABLE 0
#endif



#define BT_INBAND_RINGTONE                        1   //是否播放手机自带来电铃声
#define BT_PHONE_NUMBER                           0   //是否播放来电报号
#define BT_SUPPORT_DISPLAY_BAT                    1   //是否使能电量检测
#define BT_SUPPORT_MUSIC_VOL_SYNC                 1   //是否使能音量同步

#define TCFG_DEC_G729_ENABLE                      1
#define TCFG_DEC_MTY_ENABLE					DISABLE

//*********************************************************************************//
//                                 电源切换配置                                    //
//*********************************************************************************//
#define CONFIG_PHONE_CALL_USE_LDO15	    0


//*********************************************************************************//
//                                 时钟切换配置                                    //
//*********************************************************************************//
#define CONFIG_BT_NORMAL_HZ	            (24 * 1000000L)
#define CONFIG_BT_CONNECT_HZ            (48 * 1000000L)

#if TCFG_BT_MUSIC_EQ_ENABLE
#define CONFIG_BT_A2DP_HZ	        	(96 * 1000000L)
#else
#define CONFIG_BT_A2DP_HZ	        	(48 * 1000000L)
#endif

#define CONFIG_MUSIC_DEC_CLOCK			(48 * 1000000L)
#define CONFIG_MUSIC_IDLE_CLOCK		    (48 * 1000000L)

#define CONFIG_BT_CALL_HZ		        (48 * 1000000L)
#define CONFIG_BT_CALL_ADVANCE_HZ       (60 * 1000000L)
#define CONFIG_BT_CALL_16k_HZ	        (60 * 1000000L)
#define CONFIG_BT_CALL_16k_ADVANCE_HZ   (80 * 1000000L)


//*********************************************************************************//
//                                 256KB Flash                                     //
//*********************************************************************************//
#ifdef CONFIG_256K_FLASH
#undef AUDIO_OUT_MIXER_ENABLE
#define AUDIO_OUT_MIXER_ENABLE				0
#undef TCFG_WAV_TONE_MIX_ENABLE
#define TCFG_WAV_TONE_MIX_ENABLE			0
#endif

//*********************************************************************************//
//                                 配置结束                                        //
//*********************************************************************************//


#endif //CONFIG_BOARD_AD698X_DEMO
#endif //CONFIG_BOARD_AD698X_DEMO_CFG_H
