
#include "includes.h"
#include "MatrixInteFunc.h"

static u8 fft_init = 0;
static OS_MUTEX fft_mutex;

typedef struct {
    unsigned int fft_config;
    const int *in;
    int *out;
} pi32v2_hw_fft_ctx;

void hw_fft_wrap(pi32v2_hw_fft_ctx *ctx)
{
    if (fft_init == 0) {
        fft_init = 1;
        os_mutex_create(&fft_mutex);
    }
    os_mutex_pend(&fft_mutex, 0);

    JL_FFT->CON = 0;
    JL_FFT->CON |= 1 << 8;

    JL_FFT->CADR = (unsigned int)ctx;
    JL_FFT->CON |= 1;
    while ((JL_FFT->CON & (1 << 7)) == 0);
    JL_FFT->CON |= (1 << 6);

    os_mutex_post(&fft_mutex);
}



// Matrix Hardware model API define
void MatrixCFG_core(unsigned int con_cfg, matrix_config *mat_cof)
{
    if (fft_init == 0) {
        fft_init = 1;
        os_mutex_create(&fft_mutex);
    }
    os_mutex_pend(&fft_mutex, 0);

	JL_FFT->CADR = (unsigned long)(&mat_cof->matrix_con);
	JL_FFT->CON = con_cfg;

	while (!(JL_FFT->CON & (1 << 7)))
		;


    os_mutex_post(&fft_mutex);
}

// Matrix Hardware model API define
void MatrixCFG_core0(unsigned int con_cfg, matrix_config *mat_cof, int *rst, int rQ, int is_real)
{

	long long tmp_64_1, tmp_64_2;
	tmp_64_1 = 0;
	tmp_64_2 = 0;

    if (fft_init == 0) {
        fft_init = 1;
        os_mutex_create(&fft_mutex);
    }
    os_mutex_pend(&fft_mutex, 0);


	JL_FFT->CADR = (unsigned long)(&mat_cof->matrix_con);
	JL_FFT->CON = con_cfg;

	while (!(JL_FFT->CON & (1 << 7)))
		;

	if (is_real == 1)
	{
		tmp_64_1 = JL_FFT->ACC0H;
		tmp_64_1 = tmp_64_1 << 32;
		tmp_64_1 |= JL_FFT->ACC0L;

		if (rQ >= 0)
		{
			*rst = (int)(tmp_64_1 << rQ);
		}
		else
		{
			*rst = (int)(tmp_64_1 >> (-rQ));
		}
	}
	else
	{
		tmp_64_1 = JL_FFT->ACC0H;
		tmp_64_2 = JL_FFT->ACC1H;
		tmp_64_1 = tmp_64_1 << 32;
		tmp_64_2 = tmp_64_2 << 32;
		tmp_64_1 |= JL_FFT->ACC0L;
		tmp_64_2 |= JL_FFT->ACC1L;

		if (rQ >= 0)
		{
			*rst++ = (int)(tmp_64_1 << rQ);
			*rst = (int)(tmp_64_2 << rQ);
		}
		else
		{
			*rst++ = (int)(tmp_64_1 >> (-rQ));
			*rst = (int)(tmp_64_2 >> (-rQ));
		}
	}

    os_mutex_pend(&fft_mutex, 0);
	
}

