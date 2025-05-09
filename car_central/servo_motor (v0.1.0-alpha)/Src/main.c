#include "stm32f4xx.h"
#define ARM_MATH_CM4

// 특정 GPIO 핀에 Alternate Function (AFx)을 설정하는 매크로
#define SET_GPIO_AF(GPIOx, PIN, AF)                     \
    do {                                                \
        uint8_t index = (PIN) / 8;                      /* AFR 레지스터 선택 (0: AFR[0], 1: AFR[1]) */ \
        uint8_t pos = ((PIN) % 8) * 4;                  /* 해당 핀의 비트 위치 계산 (핀당 4비트) */ \
        GPIOx->AFR[index] &= ~(0xF << pos);             /* 기존 설정을 클리어 (해당 4비트를 0000으로) */ \
        GPIOx->AFR[index] |=  ((AF) << pos);            /* 새로운 AF 값을 해당 위치에 설정 */ \
    } while(0)

// GPIO 핀을 Alternate Function 모드로 설정하는 매크로
#define SET_GPIO_AF_MODE(GPIOx, PIN)                    \
    do {                                                \
        GPIOx->MODER &= ~(0x3 << ((PIN) * 2));          /* 해당 핀의 MODER 2비트를 클리어 */ \
        GPIOx->MODER |=  (0x2 << ((PIN) * 2));          /* 0b10 = Alternate Function 모드로 설정 */ \
    } while(0)

// 위 두 동작을 한 줄로 묶어 한번에 설정하는 통합 매크로
#define CONFIGURE_GPIO_AF(GPIOx, PIN, AF)               \
    do {                                                \
        SET_GPIO_AF_MODE(GPIOx, PIN);                   /* 해당 핀을 AF 모드로 설정 */ \
        SET_GPIO_AF(GPIOx, PIN, AF);                    /* 해당 핀에 원하는 AF 번호를 지정 */ \
    } while(0)

void GPIO_Init(void);
void TIM3_Init(void);
void TIM4_ms_Delay(uint32_t delay);

// PB0 → TIM3_CH3 (AF2)
void GPIO_Init(){
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; // Enable GPIOB clock
    CONFIGURE_GPIO_AF(GPIOB, 0, 2);      // PB0 → AF2 (TIM3_CH3) (PB0 핀을 PWM 출력으로 설정할 수 있게 만들어주는 매크로)
}

void TIM3_Init(){
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; // Enable TIM3 clock
    TIM3->PSC = 16 - 1;      // 1MHz timer clock
    TIM3->ARR = 20000;       // 20ms period
    TIM3->CNT = 0;
    TIM3->CCR3 = 1500;       // Initial pulse width
    TIM3->CCMR2 &= ~(0xFF);  // Clear channel 3 bits
    TIM3->CCMR2 |= 0x0060;   // PWM mode 1 on CH3
    TIM3->CCER |= TIM_CCER_CC3E; // Enable output on CH3
}

void TIM4_ms_Delay(uint32_t delay){
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    TIM4->PSC = 16000 - 1; // 1kHz clock (1ms tick)
    TIM4->ARR = delay;
    TIM4->CNT = 0;
    TIM4->CR1 |= TIM_CR1_CEN;
    while (!(TIM4->SR & TIM_SR_UIF)) {}
    TIM4->SR &= ~TIM_SR_UIF;
}

int main(){
    GPIO_Init();
    TIM3_Init();
    TIM3->CR1 |= TIM_CR1_CEN;

    while(1){
        TIM3->CCR3 = 1500; // 0도
        TIM4_ms_Delay(1000);

        TIM3->CCR3 = 2000; // -90도
        TIM4_ms_Delay(1000);

        TIM3->CCR3 = 1500; // 0도
        TIM4_ms_Delay(1000);

        TIM3->CCR3 = 800; // +90도
        TIM4_ms_Delay(1000);
    }
}
