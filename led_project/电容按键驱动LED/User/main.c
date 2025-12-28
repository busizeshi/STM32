/**
 * @file main.c
 * @brief STM32 gpio驱动LED灯控制
 */
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/TPAD/tpad.h"

int main(void)
{
    uint8_t t = 0;

    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    delay_init(72);                     /* 延时初始化 */
    usart_init(115200);                 /* 串口初始化为115200 */
    LED_Init();                         /* 初始化LED */
    tpad_init(6);                       /* 初始化触摸按键 */

    while (1)
    {
        if (tpad_scan(0)) /* 成功捕获到了一次上升沿(此函数执行时间至少15ms) */
        {
            LED_Toggle(LED1_ID); /* LED1翻转 */
        }

        t++;
        if (t == 15)
        {
            t = 0;
            LED_Toggle(LED0_ID); /* LED0翻转 */
        }

        delay_ms(10);
    }
}
