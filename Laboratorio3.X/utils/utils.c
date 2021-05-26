/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "../mcc_generated_files/usb/usb_device_cdc.h"
#include "../mcc_generated_files/tmr2.h"
#include "utils.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
/*  A brief description of a section can be given directly below the section
    banner.
 */


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */



/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
void receiveAndSendData(void) {
    uint8_t numBytes;
    uint8_t buffer[64];

    numBytes = getsUSBUSART(buffer, sizeof (buffer)); //until the buffer is free.
    if (numBytes  > 0) {
        //we received numBytes bytes of data and they are copied into
        //  the "buffer" variable.  We can do something with the data
        //  here.
        if(USBUSARTIsTxTrfReady()) {
            putUSBUSART(buffer, numBytes);
        }
    }
}

bool UT_delayms(ut_tmrDelay_t* p_timer, uint32_t p_ms) {
    switch (p_timer->state) {
        case UT_TMR_DELAY_INIT:
            p_timer->state = UT_TMR_DELAY_WAIT;
            p_timer->startValue = TMR2_SoftwareCounterGet();
            return false;
        case UT_TMR_DELAY_WAIT:
            if (p_timer->startValue + p_ms <= TMR2_SoftwareCounterGet()) {
                return false;
            } else {
                p_timer->state = UT_TMR_DELAY_INIT;
                return true;
            }
    }

    
    /*if (UT_TMR_DELAY_INIT == p_timer->state) {
        p_timer->state = UT_TMR_DELAY_WAIT;
        p_timer->startValue = TMR2_SoftwareCounterGet();
        return false;
    } else if (UT_TMR_DELAY_WAIT == p_timer->state &&
            p_timer->startValue + p_ms <= TMR2_SoftwareCounterGet()) {
        return false;
    } else {
        p_timer->state = UT_TMR_DELAY_INIT;
        return true;
    }*/
}