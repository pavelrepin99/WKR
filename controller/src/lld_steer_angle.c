#include <lld_steer_angle.h>

#define ADC1_NUM_CHANNELS 1
#define ADC1_BUF_DEPTH 1
#define F 1000000
#define factor 0.9
#define LINE_ADC123_IN PAL_LINE(GPIOC,0)
buff cur_adc=0;
filterAdc filtered_adc=0;
angle_adc angle=0;
int32_t steer_a_left = 0;
int32_t steer_c = 0;
int32_t steer_b_right = 0;

static bool InitSteer = false;
static adcsample_t samples1[ADC1_NUM_CHANNELS * ADC1_BUF_DEPTH];

static const GPTConfig gpt4cfg1 = {
  .frequency =  F,
  .callback  =  NULL,
  .cr2       =  TIM_CR2_MMS_1,
  .dier      =  0U
};

static void adccallback(ADCDriver *adcp, adcsample_t *buffer, size_t n)
{
  (void)adcp;
  (void)n;
  (void)buffer;
  cur_adc = samples1[0];
  filtered_adc = cur_adc * (1-factor)+filtered_adc * factor;
  angle = filtered_adc;
}

static const ADCConversionGroup adcgrpcfg1 = {
  .circular     = true,
  .num_channels = ADC1_NUM_CHANNELS,
  .end_cb       = adccallback,
  .error_cb     = 0,
  .cr1          = 0,
  .cr2          = ADC_CR2_EXTEN_RISING | ADC_CR2_EXTSEL_SRC(0b1100),
  .smpr1        = ADC_SMPR1_SMP_AN10(ADC_SAMPLE_480),
  .smpr2        = 0,
  .sqr1         = ADC_SQR1_NUM_CH(ADC1_NUM_CHANNELS),
  .sqr2         = 0,
  .sqr3         = ADC_SQR3_SQ1_N(ADC_CHANNEL_IN10)

};
/**
 * @brief Initialization ADC, GPT
 * @note variable InitSteer for protection
 */
void lldSteerAngleInit(void)
{
    if(InitSteer)
        return;
    adcStart(&ADCD1, NULL);
    palSetLineMode( LINE_ADC123_IN, PAL_MODE_INPUT_ANALOG );
    adcStartConversion(&ADCD1, &adcgrpcfg1, samples1, ADC1_BUF_DEPTH);
    gptStart(&GPTD4, &gpt4cfg1);
    gptStartContinuous(&GPTD4, gpt4cfg1.frequency/2000);
    steer_a_left = LEFT_STEER - CENTER_STEER;
    steer_c = CENTER_STEER;
    steer_b_right = CENTER_STEER - RIGHT_STEER;
    InitSteer = true;
}
/**
 * @brief Get angle of rotation of the servo
 * @args unit (TICKS,DEG,RAD)
 * @returns the angle in the units
 */
angle_adc lldGetSteerAngle(angle_units unit)
{
    if(unit!=TICKS)
    {
        if(unit == RAD)
        {
            unit=unit*0.001; //for terminal
        }
        if(angle <= CENTER_STEER && angle >= RIGHT_STEER)
        {
            angle = (steer_c - angle) / (steer_b_right);
        }
        else if(angle > CENTER_STEER && angle <= LEFT_STEER)
        {
            angle = (steer_c - angle) / (steer_a_left);
        }
    }
    return angle*unit;
}


