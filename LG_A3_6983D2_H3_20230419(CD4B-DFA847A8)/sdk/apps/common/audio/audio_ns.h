#ifndef _AUDIO_NOISE_SUPPRESS_H_
#define _AUDIO_NOISE_SUPPRESS_H_

#include "generic/typedef.h"
#include "generic/circular_buf.h"
#include "commproc_ns.h"

#define NS_FRAME_POINTS		160
#define NS_FRAME_SIZE		(NS_FRAME_POINTS << 1)
#define NS_OUT_POINTS_MAX	(NS_FRAME_POINTS << 1)

typedef struct {
    //s16 in[512];
    //cbuffer_t cbuf;
    noise_suppress_param ns_para;
} audio_ns_t;

audio_ns_t *audio_ns_open(u16 sr, u8 mode, float NoiseLevel, float AggressFactor, float MinSuppress);
int audio_ns_run(audio_ns_t *ns, short *in, short *out, u16 len);
int audio_ns_close(audio_ns_t *ns);

#endif/*_AUDIO_NOISE_SUPPRESS_H_*/
