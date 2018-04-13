

#include "common.h"
#include "include.h"


void PIT0_IRQHandler(void);

/*!
 *  @brief      main函数
 *  @since      v5.0
 *  @note       FTM 正交解码 测试
 */
void Quad_Init(void)
{
    //printf("\n*****FTM 正交解码 测试*****\n");

    ftm_quad_init(FTM1);                                    //FTM1 正交解码初始化（所用的管脚可查 port_cfg.h ）
                                                            //切记要把引脚改成pta8，pta9
    pit_init_ms(PIT0, 1000);                                 //初始化PIT0，定时时间为： 1000ms
    set_vector_handler(PIT0_VECTORn ,PIT0_IRQHandler);      //设置PIT0的中断服务函数为 PIT0_IRQHandler
    enable_irq (PIT0_IRQn);                                 //使能PIT0中断

}

/*!
 *  @brief      PIT0中断服务函数
 *  @since      v5.0
 */
void PIT0_IRQHandler(void)
{
    int16 val=0;
    PIT_Flag_Clear(PIT0);       //清中断标志位
   
    val = ftm_quad_get(FTM1);          //获取FTM 正交解码 的脉冲数(负数表示反方向)
                                      //val值为脉冲数，正负为方向。脉冲数基本等于转过齿数
    //以下是显示用的
    //LCD_str(site_val[0], "            ", BLACK, WHITE);    
    //LCD_char(site_val[0], ((val<0)?'-':'+') , BLACK, WHITE);
    //LCD_num(site_val[1], abs(val), BLACK, WHITE);
    ftm_quad_clean(FTM1);

}

