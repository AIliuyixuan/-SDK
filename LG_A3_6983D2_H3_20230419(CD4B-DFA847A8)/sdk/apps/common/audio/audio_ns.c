/*
 ******************************************************************
 *				Noise Suppress Module(降噪模块)
 *1. Usage:
 *(1)
 *(2)
 ******************************************************************
 */

#include "audio_ns.h"

int audio_ns_run(audio_ns_t *ns, short *in, short *out, u16 len)
{
    if (ns == NULL) {
        return len;
    }
#if 0
    int wlen = cbuf_write(&ns->cbuf, in, len);
    if (wlen != len) {
        printf("ns_cbuf full\n");
    }
    if (ns->cbuf.data_len >= NS_FRAME_SIZE) {
        cbuf_read(&ns->cbuf, out, NS_FRAME_SIZE);
        putchar('.');
        noise_suppress_run(out, out, NS_FRAME_POINTS);
        return NS_FRAME_SIZE;
    } else {
        return 0;
    }
#else
    //putchar('.');
    int nOut = noise_suppress_run(in, out, (len / 2));
    //printf(" [%d,%d] ",len/2,nOut);
    return (nOut << 1);
#endif
}

audio_ns_t *audio_ns_open(u16 sr, u8 mode, float NoiseLevel, float AggressFactor, float MinSuppress)
{
    audio_ns_t *ans = zalloc(sizeof(audio_ns_t));
    //cbuf_init(&ans->cbuf, ans->in, sizeof(ans->in));

    ans->ns_para.wideband = (sr == 16000) ? 1 : 0;
    ans->ns_para.mode = mode;
    ans->ns_para.NoiseLevel = NoiseLevel;
    ans->ns_para.AggressFactor = AggressFactor;
    ans->ns_para.MinSuppress = MinSuppress;
    printf("ns wideband:%d\n", ans->ns_para.wideband);
    noise_suppress_open(&ans->ns_para);
    float lowcut = -60.f;
    //noise_suppress_config(NS_CMD_LOWCUTTHR, 0, &lowcut);
    printf("audio_ns_open ok\n");
    return ans;
}

int audio_ns_close(audio_ns_t *ns)
{
    noise_suppress_close();
    if (ns) {
        free(ns);
        ns = NULL;
    }
    printf("esco_ans_close ok\n");
    return 0;
}
