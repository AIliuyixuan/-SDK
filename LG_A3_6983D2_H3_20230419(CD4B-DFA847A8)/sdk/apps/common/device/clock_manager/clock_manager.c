
#include "clock_manager.h"
#include "asm/clock.h"
#include "list.h"


typedef struct clock_manager_st {
    struct list_head entry;
    const char  *name;
    u32         freq;
} clock_manager_item;

static struct list_head clk_mgr_head = LIST_HEAD_INIT(clk_mgr_head);


/* --------------------------------------------------------------------------*/
/**
 * @brief clock_alloc，此函数会触发时钟频率设置
 *
 * @param name
 * @param clk
 *
 * @return 0:succ
 */
/* ----------------------------------------------------------------------------*/
int clock_alloc(const char *name, u32 clk)
{
    clock_manager_item *p;
    u32 total;

    total = 0;
    list_for_each_entry(p, &clk_mgr_head, entry) {
        total += p->freq;
        if (0 == strcmp(p->name, name)) {
            return -1;
        }
    }

    clock_manager_item *it = malloc(sizeof(clock_manager_item));
    if (it == NULL) {
        return -1;
    }

    it->name = name;
    it->freq = clk;

    list_add_tail(&it->entry, &clk_mgr_head);

    clk_set("sys", total + clk);

    return 0;
}


/* --------------------------------------------------------------------------*/
/**
 * @brief clock_free，此函数会触发时钟频率设置
 *
 * @param name
 *
 * @return 0:succ
 */
/* ----------------------------------------------------------------------------*/
int clock_free(char *name)
{
    clock_manager_item *p, *n;
    u32 total;

    total = 0;
    list_for_each_entry_safe(p, n, &clk_mgr_head, entry) {
        if (0 == strcmp(p->name, name)) {
            __list_del_entry(&p->entry);
            free(p);
            continue;
        }
        total += p->freq;
    }

    clk_set("sys", total);

    return 0;
}


/* --------------------------------------------------------------------------*/
/**
 * @brief clock_manager_dump
 */
/* ----------------------------------------------------------------------------*/
void clock_manager_dump(void)
{
    clock_manager_item *p;
    u32 total;

    total = 0;
    list_for_each_entry(p, &clk_mgr_head, entry) {
        printf("%s : %dHz", p->name, p->freq);
        total += p->freq;
    }
    printf("%s : %dHz", "total", total);
}


/* --------------------------------------------------------------------------*/
/**
 * @brief clock_manager_test
 */
/* ----------------------------------------------------------------------------*/
void clock_manager_test(void)
{
    clock_alloc("clk_mgr_1", 2 * 1000000U);
    clock_manager_dump();

    clock_alloc("clk_mgr_2", 2 * 1000000U);
    clock_manager_dump();

    clock_free("clk_mgr_1");
    clock_manager_dump();

    clock_free("clk_mgr_2");
    clock_manager_dump();

    printf("test over");
    while (1);
}



/* --------------------------------------------------------------------------*/
/**
 * @brief clock_manager_reflash
 */
/* ----------------------------------------------------------------------------*/
static u16 clk_ref_timer;
static u8 ref_cnt;

#define BASE_CLK_FREQ       (12 * 1000000)

extern void os_system_info_reset(void);
extern void hw_clock_switching(u32 out_freq);

/* --------------------------------------------------------------------------*/
/**
 * @brief clk_ref_cal
 */
/* ----------------------------------------------------------------------------*/
static void clk_ref_cal(void)
{
    u32 clk_freq;
    u32 clk_decr;
    u8 pct;

    clk_freq = clk_get("sys");
    pct = os_idle_percentage();

    clk_decr = clk_freq - BASE_CLK_FREQ;

    if (pct > 80) {
        clk_decr = clk_decr / 2;
    } else if (pct > 60) {
        clk_decr = clk_decr / 3;
    } else if (pct > 40) {
        clk_decr = clk_decr / 4;
    } else {
        clk_decr = 0;
    }

    clk_freq -= clk_decr;

    /* clk_set("sys", clk_freq); */
    hw_clock_switching(clk_freq);
    core_voltage_dump();

    os_system_info_reset();
}

/* --------------------------------------------------------------------------*/
/**
 * @brief clk_ref_fun
 *
 * @param p
 */
/* ----------------------------------------------------------------------------*/
static void clk_ref_fun(void *p)
{
    if (ref_cnt++ < 7) {

        clk_ref_cal();

    } else {
        local_irq_disable();

        sys_timer_del(clk_ref_timer);
        clk_ref_timer = 0;

        printf("clock_reflash_stop");

        local_irq_enable();
    }
}

void clock_refurbish(void)
{
    printf("clock_reflash_start");

    local_irq_disable();

    ref_cnt = 0;

    if (clk_ref_timer) {
        sys_timer_modify(clk_ref_timer, 5 * 1000);
    } else {
        clk_ref_timer = sys_timer_add(NULL, clk_ref_fun, 5 * 1000);
    }

    ASSERT(clk_ref_timer);

    local_irq_enable();
}


/* --------------------------------------------------------------------------*/
/**
 * @brief clock_manager_test
 */
/* ----------------------------------------------------------------------------*/

static void clk_test_tmr_fun(void *p)
{
    /* clk_set("sys", 96 * 1000000); */
    hw_clock_switching(96 * 1000000);

    os_system_info_reset();

    clock_refurbish();
}

void clock_manager_test_2(void)
{
    sys_timer_add(NULL, clk_test_tmr_fun, 60 * 1000);
}

