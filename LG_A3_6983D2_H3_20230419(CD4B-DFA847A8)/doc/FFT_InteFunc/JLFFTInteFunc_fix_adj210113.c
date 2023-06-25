#ifndef JLFFTINTEFUNC_FIX_H
#define JLFFTINTEFUNC_FIX_H

//#include "includes.h"


typedef struct {
    unsigned int fft_config;
    const int *in;
    int *out;
} pi32v2_hw_fft_ctx;


unsigned int make_fft_config(int N, int log2N, int same_addr, int is_real, int is_forward)
{
    unsigned int ConfgPars;
    ConfgPars = 0;
    ConfgPars |= same_addr;
    ConfgPars |= is_real << 1;
    if (is_forward == 1)
    {
        if (is_real == 1)
        {
            ConfgPars |= (log2N - 3) << 4;
            ConfgPars |= (log2N - 2) << 8;
        }
        else
        {
            ConfgPars |= (log2N - 2) << 4;
            ConfgPars |= (log2N - 1) << 8;
        }
    }
    else
    {
        if (is_real == 1)
        {
            ConfgPars |= 1 << 2;
            ConfgPars |= (2) << 4;
            ConfgPars |= (log2N - 2) << 8;
        }
        else
        {
            ConfgPars |= 1 << 2;
            ConfgPars |= (3) << 4;
            ConfgPars |= (log2N - 1) << 8;
        }
    }
    
    ConfgPars |= (N) << 16;

    return ConfgPars;
}

void _fixfft_wrap(pi32v2_hw_fft_ctx *ctx, const int *in, int *out)
{
    ctx->in = in;
    ctx->out = out;
    hw_fft_wrap(ctx);
}

#endif