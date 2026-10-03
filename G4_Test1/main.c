#include "RTE_Components.h"
#include CMSIS_device_header
#include "stm32g4xx.h"

int main(void){

    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;


    GPIOA->MODER &= ~(3U << (2 * 7));
    GPIOA->MODER |=  (1U << (2 * 7));

    GPIOA->MODER &= ~(3U << (2 * 4));
    GPIOA->MODER |=  (1U << (2 * 4));

    GPIOA->MODER &= ~(3U << (2 * 0));
    GPIOA->MODER |=  (1U << (2 * 0));

    GPIOA->MODER &= ~(3U << (2 * 2));
    GPIOA->MODER |=  (1U << (2 * 2));

    GPIOA->MODER &= ~(3U << (2 * 6));
    GPIOA->MODER |=  (1U << (2 * 6));
 

    GPIOB->MODER &= ~(3U << (2 * 0));
    GPIOB->PUPDR &= ~(3U << (2 * 0));
    GPIOB->PUPDR |=  (2U << (2 * 0));

    GPIOB->MODER &= ~(3U << (2 * 7));
    GPIOB->PUPDR &= ~(3U << (2 * 7));
    GPIOB->PUPDR |=  (2U << (2 * 7));

    GPIOB->MODER &= ~(3U << (2 * 6));
    GPIOB->PUPDR &= ~(3U << (2 * 6));
    GPIOB->PUPDR |=  (2U << (2 * 6));

    GPIOB->MODER &= ~(3U << (2 * 5));
    GPIOB->PUPDR &= ~(3U << (2 * 5));
    GPIOB->PUPDR |=  (2U << (2 * 5));

    GPIOB->MODER &= ~(3U << (2 * 4));
    GPIOB->PUPDR &= ~(3U << (2 * 4));
    GPIOB->PUPDR |=  (2U << (2 * 4));


    while (1){
        if (GPIOB->IDR & (1U << 0)){
            GPIOA->ODR |= (1U << 2);
        }
        else {
            GPIOA->ODR &= ~(1U << 2);
        }

        if (GPIOB->IDR & (1U << 7)) {
            GPIOA->ODR |= (1U << 7);
        }
        else{ 
            GPIOA->ODR &= ~(1U << 7);
        }

        if (GPIOB->IDR & (1U << 6)){
            GPIOA->ODR |= (1U << 4);
        }
        else{
            GPIOA->ODR &= ~(1U << 4);
        }
        if (GPIOB->IDR & (1U << 5)){
            GPIOA->ODR |= (1U << 0);
        }
        else {
            GPIOA->ODR &= ~(1U << 0);
        }

        if (GPIOB->IDR & (1U << 4)) {
            GPIOA->ODR |= (1U << 6);
        }
        else{
            GPIOA->ODR &= ~(1U << 6);
        }
    }
}