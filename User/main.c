#include "stm32f10x.h"

int main()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能时钟

    GPIO_InitTypeDef gpioTypefDef;
    gpioTypefDef.GPIO_Pin = GPIO_Pin_5; // LED0 PB5
    gpioTypefDef.GPIO_Speed = GPIO_Speed_50MHz;
    gpioTypefDef.GPIO_Mode = GPIO_Mode_Out_PP; // 通用推挽输出

    GPIO_Init(GPIOB, &gpioTypefDef);
    GPIO_ResetBits(GPIOB, GPIO_Pin_5); // PB5置低电平

    while (1) {

    }
}
