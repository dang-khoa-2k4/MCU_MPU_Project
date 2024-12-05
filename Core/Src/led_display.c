#include "led_display.h"

static uint16_t LIGHT_PIN[2][2] = 
{
    {L1_0_Pin, L1_1_Pin},
    {L2_0_Pin, L2_1_Pin}
};

static GPIO_TypeDef * LIGHT_PORT[2][2] = 
{
    {L1_0_GPIO_Port , L1_1_GPIO_Port},
    {L2_0_GPIO_Port , L2_1_GPIO_Port}
};

static uint8_t toggle = 0;

static void amber(uint8_t light)
{
    HAL_GPIO_WritePin(LIGHT_PORT[light][0], LIGHT_PIN[light][0], LED_ON);
    HAL_GPIO_WritePin(LIGHT_PORT[light][1], LIGHT_PIN[light][1], LED_OFF);
}

static void green(uint8_t light)
{
    HAL_GPIO_WritePin(LIGHT_PORT[light][0], LIGHT_PIN[light][0], LED_OFF);
    HAL_GPIO_WritePin(LIGHT_PORT[light][1], LIGHT_PIN[light][1], LED_ON);
}

static void red(uint8_t light)
{
    HAL_GPIO_WritePin(LIGHT_PORT[light][0], LIGHT_PIN[light][0], LED_ON);
    HAL_GPIO_WritePin(LIGHT_PORT[light][1], LIGHT_PIN[light][1], LED_ON);
}

static void off_light(uint8_t light)
{
    HAL_GPIO_WritePin(LIGHT_PORT[light][0], LIGHT_PIN[light][0], LED_OFF);
    HAL_GPIO_WritePin(LIGHT_PORT[light][1], LIGHT_PIN[light][1], LED_OFF);
}

void light_off_all(void)
{
    off_light(LIGHT_1);
    off_light(LIGHT_2);
}

void light_toggle(uint8_t led)
{
    if (toggle)
    {
        switch (led)
        {
        case AMBER:
            amber(LIGHT_1);
            amber(LIGHT_2);
            break;
        case GREEN:
            green(LIGHT_1);
            green(LIGHT_2);
            break;
        case RED:
            red(LIGHT_1);
            red(LIGHT_2);
            break;
        default:
            light_off_all();
            break;
        }
    }
    else
    {
        light_off_all();
    }
    toggle = !toggle;
}

void light_1_handle(uint8_t led)
{
    switch (led)
    {
    case AMBER:
        amber(LIGHT_1);
        break;
    case GREEN:
        green(LIGHT_1);
        break;
    case RED:
        red(LIGHT_1);
        break;
    default:
        off_light(LIGHT_1);
        break;
    }
}

void light_2_handle(uint8_t led)
{
    switch (led)
    {
    case AMBER:
        amber(LIGHT_2);
        break;
    case GREEN:
        green(LIGHT_2);
        break;
    case RED:
        red(LIGHT_2);
        break;
    default:
        off_light(LIGHT_2);
        break;
    }
}