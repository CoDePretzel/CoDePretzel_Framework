/* 
 * File:   all_tests.h
 * Author: rafae
 *
 * Created on February 18, 2023, 8:25 PM
 */

#ifndef ALL_TESTS_H
#define	ALL_TESTS_H

#ifdef	__cplusplus
extern "C" {
#endif
#define UNITY_OUTPUT_CHAR(a) (void)USART1_Write(a) //Use UART instead of stdio.h putchar()
#define UNITY_FIXTURE_NO_EXTRAS //Not include unity_memory.h
    
void run_unity_tests(char * main_path);


#ifdef	__cplusplus
}
#endif

#endif	/* ALL_TESTS_H */

