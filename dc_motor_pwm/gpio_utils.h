/*
 * gpio_utils.h
 *
 *  Created on: Apr 25, 2025
 *      Author: PC
 */

#ifndef __GPIO_UTILS_H
#define __GPIO_UTILS_H

#include "stm32f4xx.h"

// GPIO 클럭 활성화
#define ENABLE_GPIO_CLOCK(GPIOx) \
    (RCC->AHB1ENR |= (1 << (((uint32_t)(GPIOx) - AHB1PERIPH_BASE) >> 10)))

// GPIO 핀을 Alternate Function Mode로 설정
#define SET_GPIO_AF_MODE(GPIOx, PIN) \
    (GPIOx->MODER = (GPIOx->MODER & ~(0x3 << ((PIN) * 2))) | (0x2 << ((PIN) * 2)))

// GPIO 핀을 Pull-Down 설정
#define SET_GPIO_PULLDOWN(GPIOx, PIN) \
    (GPIOx->PUPDR = (GPIOx->PUPDR & ~(0x3 << ((PIN) * 2))) | (0x2 << ((PIN) * 2)))

// GPIO 핀의 Alternate Function 지정
#define SET_GPIO_AF(GPIOx, PIN, AF)                     \
    do {                                                \
        uint32_t index = (PIN) / 8;                     \
        uint32_t pos = ((PIN) % 8) * 4;                 \
        GPIOx->AFR[index] &= ~(0xF << pos);             \
        GPIOx->AFR[index] |= ((AF) << pos);             \
    } while(0)

#endif /* __GPIO_UTILS_H */

