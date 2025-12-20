#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"

void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    KEY_GPIO_CLK;

    GPIO_InitStruct.Pin = KEY0_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(KEY_PORT_PORT, &GPIO_InitStruct);
}

uint8_t KEY_Scan()
{
    static uint8_t key_release = 1;

    if (key_release && HAL_GPIO_ReadPin(KEY_PORT_PORT, KEY0_PIN) == KEY_PRESSED)
    {
        delay_ms(10);
        if (HAL_GPIO_ReadPin(KEY_PORT_PORT, KEY0_PIN) == KEY_PRESSED)
        {
            key_release = 0;
            return 1;
        }
    }
    else if (HAL_GPIO_ReadPin(KEY_PORT_PORT, KEY0_PIN) != KEY_PRESSED)
    {
        key_release = 1;
    }

    return 0;
}