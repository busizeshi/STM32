/**
 * @file    led.h
 * @brief   LED驱动头文件
 * @author  jwd
 */
#ifndef __LED_H
#define __LED_H

#include "./SYSTEM/sys/sys.h"

// 定义LED编号
#define LED0_ID 0
#define LED1_ID 1

// 定义gpio端口和引脚
#define LED0_GPIO_PORT GPIOB
#define LED0_GPIO_PIN GPIO_PIN_5
#define LED0_GPIO_CLK_ENABLE() do{ __HAL_RCC_GPIOB_CLK_ENABLE(); } while(0)

#define LED1_GPIO_PORT GPIOE
#define LED1_GPIO_PIN GPIO_PIN_5
#define LED1_GPIO_CLK_ENABLE() do{ __HAL_RCC_GPIOE_CLK_ENABLE(); } while(0)

// led控制
#define LED0(x) do{ if(x) HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_RESET); \
                             else HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_SET); } while(0)

#define LED1(x) do{ if(x) HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_RESET); \
                             else HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_SET); } while(0)

// 函数声明
void LED_Init(void);
void LED_Toggle(uint8_t led);

#endif /* __LED_H */
