#include "./BSP/LED/led.h"

/**
 * @brief 初始化LED
 */
void LED_Init(void)
{
    LED0_GPIO_CLK_ENABLE();
    LED1_GPIO_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = LED0_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // 推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL; // 不上拉不下拉
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; // 高速
    HAL_GPIO_Init(LED0_GPIO_PORT, &GPIO_InitStruct);
    GPIO_InitStruct.Pin = LED1_GPIO_PIN;
    HAL_GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);

    LED0(0); // 关闭LED0
    LED1(0); // 关闭LED1
}

/**
 * @brief 翻转LED
 */
void LED_Toggle(uint8_t led)
{
    if (led == LED0_ID)
    {
        HAL_GPIO_TogglePin(LED0_GPIO_PORT, LED0_GPIO_PIN);
    }
    else if (led == LED1_ID)
    {
        HAL_GPIO_TogglePin(LED1_GPIO_PORT, LED1_GPIO_PIN);
    }
}
