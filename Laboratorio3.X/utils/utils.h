#ifndef _UTILS_H    /* Guard against multiple inclusion */
#define _UTILS_H

typedef enum {
    UT_TMR_DELAY_INIT,
    UT_TMR_DELAY_WAIT
} UT_TMR_DELAY_STATE;

typedef struct {
    uint32_t startValue;
    UT_TMR_DELAY_STATE state;
} ut_tmrDelay_t;

void receiveAndSendData(void);

bool UT_delayms(ut_tmrDelay_t* p_timer, uint32_t p_ms);

#endif /* _UTILS_H */
