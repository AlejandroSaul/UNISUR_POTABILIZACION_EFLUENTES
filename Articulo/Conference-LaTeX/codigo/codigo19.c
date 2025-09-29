temperatura = ds1820_read();
           delay_ms(1000);
            while (temperatura >= 28)   //Si la temperatura no es adecuada aquí se mantendrá 
           {
           output_low (PIN_E0);                   //led
           lcd_gotoxy (1,1);
          printf (LCD_PUTC, “\f Temperatura no”);
           lcd_gotoxy (1,2);
          printf(LCD_PUTC, “\b adecuada T= %0.0f “,temperatura);
           temperatura = ds1820_read();
           delay_ms(1000);          
           }
            ///////////////////////////////////////////////////////////////////////////////////////////////
            //Si la temperatura fue la correcta, inicia esta parte del programa
            output_low(PIN_D1);                   //Activa servo 1
            pwm_set_duty_percent(340);           //Servo1 se abre
            delay_ms(1000);
            output_low(PIN_D3);                   //Bomba 1 se enciende           
           lcd_gotoxy (1,1);printf(LCD_PUTC, "\f Temperatura");   //indica que la temp, fue correcta.
           lcd_gotoxy (1,2);printf(LCD_PUTC, "\b adecuada"); 
           delay_ms(3000);           