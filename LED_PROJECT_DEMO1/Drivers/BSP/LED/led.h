/**
 * @brief       LED头文件
 * @details     封装LED的初始化、打开、关闭函数
 */
#ifndef __LED_H__
#define __LED_H__

#include "./SYSTEM/sys/sys.h"

#define LED0_GPIO_PORT GPIOA
#define LED0_GPIO_PIN GPIO_PIN_0
#define LED0_GPIO_CLK_ENABLE()          \
    do                                \
    {                                 \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
    } while (0)

#define LED1_GPIO_PORT GPIOA
#define LED1_GPIO_PIN GPIO_PIN_1
#define LED1_GPIO_CLK_ENABLE()          \
    do                                \
    {                                 \
        __HAL_RCC_GPIOA_CLK_ENABLE(); \
    } while (0)

#define LED0(x)                                                                                                                                \
    do                                                                                                                                         \
    {                                                                                                                                          \
        x ? HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_RESET) : HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_SET); \
    } while (0)
#define LED1(x)                                                                                                                                \
    do                                                                                                                                         \
    {                                                                                                                                          \
        x ? HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_RESET) : HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_SET); \
    } while (0)

#define LED0_TOGGLE()                                      \
    do                                                     \
    {                                                      \
        HAL_GPIO_TogglePin(LED0_GPIO_PORT, LED0_GPIO_PIN); \
    } while (0)
#define LED1_TOGGLE()                                      \
    do                                                     \
    {                                                      \
        HAL_GPIO_TogglePin(LED1_GPIO_PORT, LED1_GPIO_PIN); \
    } while (0)

void led_init(void);

#endif /* __LED_H__ */
